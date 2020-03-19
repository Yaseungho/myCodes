#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//treap 자료구조 구현하기

int A[50000];
int shift[50000];

class Node {
public:
	int key;//노드의 값 (노드의 왼쪽 자식은 부모보다 값이 작고, 오른쪽 자식은 부모보다 값이 크다)
	int priority, size;//우선순위와 크기(우선순위는 노드의 형태를 무작위로 결정하는 값, 크기는 이 노드를 루트로 하는 트리의 노드 총 갯수)
	Node* left, * right;//왼쪽 자식과 오른쪽 자식을 연결하는 포인터
	Node(const int& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}//생성자(우선순위를 난수로 초기화)
	void setLeft(Node* _left) { left = _left; resize(); }//왼쪽 자식을 바꾸고 크기 다시 계산
	void setRight(Node* _right) { right = _right; resize(); }//오른쪽 자식을 바꾸고 크기 다시 계산
	void resize() {//크기를 계산하는 함수(왼쪽 크기 + 오른쪽 크기 + 1)
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};
pair<Node*, Node*> split(Node* root, int key) {//root를 루트로 하는 트리를 key보다 작은 서브트리, key보다 큰 서브트리로 쪼개고 그 두 트리를 반환하는 함수
	if (root == NULL) return { NULL,NULL };//기저사례 : 트리에 노드가 없다면 NULL 반환
	if (root->key < key) {//루트의 값보다 주어진 key가 더 크다면
		pair<Node*, Node*> r = split(root->right, key);//루트의 왼쪽은 서브트리는 key보다 이미 작기 때문에 루트의 오른쪽 서브트리를 재귀하여 쪼개기
		root->setRight(r.first);//루트의 오른쪽에 쪼갠 서브트리 중 key보다 작은 트리 붙이기
		return { root, r.second };//key보다 작은 트리, key보다 큰 트리 로 나누어졌다
	}
	else {//루트의 값보다 주어진 key가 더 작거나 같다면
		pair<Node*, Node*> l = split(root->left, key);//루트의 오른쪽은 서브트리는 key보다 이미 작기 때문에 루트의 왼쪽 서브트리를 재귀하여 쪼개기
		root->setLeft(l.second);//루트의 왼쪽에 쪼갠 서브트리 중 key보다 작은 트리 붙이기
		return { l.first, root };//key보다 작은 트리, key보다 큰 트리로 나누어졌다
	}
}
Node* insert(Node* root, Node* node) {//root를 루트로 하는 트리에 node를 삽입하고 새로운 트리의 루트를 반환하는 함수
	if (root == NULL) return node; //기저사례 : 트리에 노드가 없다면 삽입한 노드를 반환
	if (root->priority < node->priority) {//루트의 우선 순위보다 node의 우선 순위가 더 높다면 node가 루트가 됨
		pair<Node*, Node*> splitted = split(root, node->key);//노드의 key값을 기준으로 트리 나누기
		node->setLeft(splitted.first);//노드의 왼쪽에 노드의 값보다 작은 트리를 붙이기
		node->setRight(splitted.second);//노드에 오른쪽에 노드의 값보다 큰 트리를 붙이기
		return node;//루트가 된 node 반환하기
	}
	else {//루트의 우선 순위보다 node의 우선 순위가 더 낮다면 루트는 그대로 유지됨
		if (node->key < root->key) root->setLeft(insert(root->left, node));//루트와 node의 값을 비교해 루트가 더 크다면 재귀하여 루트의 왼쪽에 삽입
		else root->setRight(insert(root->right, node));//루트와 node의 값을 비교해 루트가 더 작거나 같다면 재귀하여 루트의 오른쪽에 삽입
		return root;//루트 반환하기
	}
}
Node* merge(Node* a, Node* b) {//a를 루트로 하는 트리의 최댓값보다 b를 루트로 하는 트리의 최솟값이 더 클때 두 트리를 합치고 합친 트리의 루트를 반환하는 함수
	if (a == NULL) return b;//기저 사례 1 : a에 노드가 없다면 b반환
	if (b == NULL) return a;//기저 사례 2 : b에 노드가 없다면 a반환
	if (a->priority < b->priority) {//a의 우선순위보다 b의 우선순위가 더 높다면 b가 루트가 됨
		b->setLeft(merge(a, b->left));//b의 왼쪽에 (a)와 (b의 왼쪽)을 합친 값 붙이기
		return b;//b반환
	}
	else {//a의 우선순위보다 b의 우선순위가 더 낮다면 a가 루트가 됨
		a->setRight(merge(a->right, b));//a의 오른쪽에 (a의 오른쪽)과 (b)를 합친 값 붙이기
		return a;//a반환
	}
}
Node* erase(Node* root, int key) {//root를 루트로 하는 트리에서 key를 값으로 하는 노드를 찾아 지우고 지워진 트리의 루트를 반환
	if (root == NULL) return root;//기저 사례 : 트리에 노드가 없다면 NULL반환
	if (root->key == key) {//지워야 하는 값이 루트라면
		Node* ret = merge(root->left, root->right);//루트의 왼쪽 서브트리와 오른쪽 서브트리 합치기
		delete root;//루트 지우기
		return ret;//새 트리의 루트 반환
	}
	if (key < root->key) root->setLeft(erase(root->left, key));//key가 루트의 값보다 왼쪽에 있다면 루트의 왼쪽 범위에서 재귀하여 찾기
	else root->setRight(erase(root->right, key));//key가 루트의 값보다 오른쪽에 있다면 루트의 오른쪽 범위에서 재귀하여 찾기
	return root;//루트 반환
}
Node* kth(Node* root, int k) {//root를 루트로 하는 트리에서 k번째 노드를 반환하는 함수
	int rootNum = 1;//루트의 왼쪽이 비어있을 수도 있으니 1로 초기화
	if (root->left != NULL) rootNum += root->left->size;//루트의 왼쪽이 비어있지 않았을 경우 루트의 왼쪽의 크기만큼 더해준다
	if (rootNum == k) return root;//루트가 k번째 값이라면 루트를 반환
	if (rootNum > k) return kth(root->left, k);//k번째 노드가 루트보다 왼쪽에 있다면 루트의 왼쪽 서브트리로 범위를 좁혀서 재귀호출
	return kth(root->right, k - rootNum);//k번째 노드가 루트보다 오른쪽에 있다면 루트의 오른쪽 서브트리로 범위를 좁혀서 재귀호출
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(NULL));
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			shift[i] = temp;
		}
		Node* root = NULL;
		for (int i = 0; i < n; i++) root = insert(root, new Node(i + 1));
		for (int i = n - 1; i >= 0; i--) {
			Node* temp = kth(root, i + 1 - shift[i]);
			A[i] = temp->key;
			root = erase(root, temp->key);
		}
		for (int i = 0; i < n; i++) cout << A[i] << " ";
		cout << "\n";
	}
}