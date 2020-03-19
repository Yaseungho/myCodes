#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//treap �ڷᱸ�� �����ϱ�

int A[50000];
int shift[50000];

class Node {
public:
	int key;//����� �� (����� ���� �ڽ��� �θ𺸴� ���� �۰�, ������ �ڽ��� �θ𺸴� ���� ũ��)
	int priority, size;//�켱������ ũ��(�켱������ ����� ���¸� �������� �����ϴ� ��, ũ��� �� ��带 ��Ʈ�� �ϴ� Ʈ���� ��� �� ����)
	Node* left, * right;//���� �ڽİ� ������ �ڽ��� �����ϴ� ������
	Node(const int& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}//������(�켱������ ������ �ʱ�ȭ)
	void setLeft(Node* _left) { left = _left; resize(); }//���� �ڽ��� �ٲٰ� ũ�� �ٽ� ���
	void setRight(Node* _right) { right = _right; resize(); }//������ �ڽ��� �ٲٰ� ũ�� �ٽ� ���
	void resize() {//ũ�⸦ ����ϴ� �Լ�(���� ũ�� + ������ ũ�� + 1)
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};
pair<Node*, Node*> split(Node* root, int key) {//root�� ��Ʈ�� �ϴ� Ʈ���� key���� ���� ����Ʈ��, key���� ū ����Ʈ���� �ɰ��� �� �� Ʈ���� ��ȯ�ϴ� �Լ�
	if (root == NULL) return { NULL,NULL };//������� : Ʈ���� ��尡 ���ٸ� NULL ��ȯ
	if (root->key < key) {//��Ʈ�� ������ �־��� key�� �� ũ�ٸ�
		pair<Node*, Node*> r = split(root->right, key);//��Ʈ�� ������ ����Ʈ���� key���� �̹� �۱� ������ ��Ʈ�� ������ ����Ʈ���� ����Ͽ� �ɰ���
		root->setRight(r.first);//��Ʈ�� �����ʿ� �ɰ� ����Ʈ�� �� key���� ���� Ʈ�� ���̱�
		return { root, r.second };//key���� ���� Ʈ��, key���� ū Ʈ�� �� ����������
	}
	else {//��Ʈ�� ������ �־��� key�� �� �۰ų� ���ٸ�
		pair<Node*, Node*> l = split(root->left, key);//��Ʈ�� �������� ����Ʈ���� key���� �̹� �۱� ������ ��Ʈ�� ���� ����Ʈ���� ����Ͽ� �ɰ���
		root->setLeft(l.second);//��Ʈ�� ���ʿ� �ɰ� ����Ʈ�� �� key���� ���� Ʈ�� ���̱�
		return { l.first, root };//key���� ���� Ʈ��, key���� ū Ʈ���� ����������
	}
}
Node* insert(Node* root, Node* node) {//root�� ��Ʈ�� �ϴ� Ʈ���� node�� �����ϰ� ���ο� Ʈ���� ��Ʈ�� ��ȯ�ϴ� �Լ�
	if (root == NULL) return node; //������� : Ʈ���� ��尡 ���ٸ� ������ ��带 ��ȯ
	if (root->priority < node->priority) {//��Ʈ�� �켱 �������� node�� �켱 ������ �� ���ٸ� node�� ��Ʈ�� ��
		pair<Node*, Node*> splitted = split(root, node->key);//����� key���� �������� Ʈ�� ������
		node->setLeft(splitted.first);//����� ���ʿ� ����� ������ ���� Ʈ���� ���̱�
		node->setRight(splitted.second);//��忡 �����ʿ� ����� ������ ū Ʈ���� ���̱�
		return node;//��Ʈ�� �� node ��ȯ�ϱ�
	}
	else {//��Ʈ�� �켱 �������� node�� �켱 ������ �� ���ٸ� ��Ʈ�� �״�� ������
		if (node->key < root->key) root->setLeft(insert(root->left, node));//��Ʈ�� node�� ���� ���� ��Ʈ�� �� ũ�ٸ� ����Ͽ� ��Ʈ�� ���ʿ� ����
		else root->setRight(insert(root->right, node));//��Ʈ�� node�� ���� ���� ��Ʈ�� �� �۰ų� ���ٸ� ����Ͽ� ��Ʈ�� �����ʿ� ����
		return root;//��Ʈ ��ȯ�ϱ�
	}
}
Node* merge(Node* a, Node* b) {//a�� ��Ʈ�� �ϴ� Ʈ���� �ִ񰪺��� b�� ��Ʈ�� �ϴ� Ʈ���� �ּڰ��� �� Ŭ�� �� Ʈ���� ��ġ�� ��ģ Ʈ���� ��Ʈ�� ��ȯ�ϴ� �Լ�
	if (a == NULL) return b;//���� ��� 1 : a�� ��尡 ���ٸ� b��ȯ
	if (b == NULL) return a;//���� ��� 2 : b�� ��尡 ���ٸ� a��ȯ
	if (a->priority < b->priority) {//a�� �켱�������� b�� �켱������ �� ���ٸ� b�� ��Ʈ�� ��
		b->setLeft(merge(a, b->left));//b�� ���ʿ� (a)�� (b�� ����)�� ��ģ �� ���̱�
		return b;//b��ȯ
	}
	else {//a�� �켱�������� b�� �켱������ �� ���ٸ� a�� ��Ʈ�� ��
		a->setRight(merge(a->right, b));//a�� �����ʿ� (a�� ������)�� (b)�� ��ģ �� ���̱�
		return a;//a��ȯ
	}
}
Node* erase(Node* root, int key) {//root�� ��Ʈ�� �ϴ� Ʈ������ key�� ������ �ϴ� ��带 ã�� ����� ������ Ʈ���� ��Ʈ�� ��ȯ
	if (root == NULL) return root;//���� ��� : Ʈ���� ��尡 ���ٸ� NULL��ȯ
	if (root->key == key) {//������ �ϴ� ���� ��Ʈ���
		Node* ret = merge(root->left, root->right);//��Ʈ�� ���� ����Ʈ���� ������ ����Ʈ�� ��ġ��
		delete root;//��Ʈ �����
		return ret;//�� Ʈ���� ��Ʈ ��ȯ
	}
	if (key < root->key) root->setLeft(erase(root->left, key));//key�� ��Ʈ�� ������ ���ʿ� �ִٸ� ��Ʈ�� ���� �������� ����Ͽ� ã��
	else root->setRight(erase(root->right, key));//key�� ��Ʈ�� ������ �����ʿ� �ִٸ� ��Ʈ�� ������ �������� ����Ͽ� ã��
	return root;//��Ʈ ��ȯ
}
Node* kth(Node* root, int k) {//root�� ��Ʈ�� �ϴ� Ʈ������ k��° ��带 ��ȯ�ϴ� �Լ�
	int rootNum = 1;//��Ʈ�� ������ ������� ���� ������ 1�� �ʱ�ȭ
	if (root->left != NULL) rootNum += root->left->size;//��Ʈ�� ������ ������� �ʾ��� ��� ��Ʈ�� ������ ũ�⸸ŭ �����ش�
	if (rootNum == k) return root;//��Ʈ�� k��° ���̶�� ��Ʈ�� ��ȯ
	if (rootNum > k) return kth(root->left, k);//k��° ��尡 ��Ʈ���� ���ʿ� �ִٸ� ��Ʈ�� ���� ����Ʈ���� ������ ������ ���ȣ��
	return kth(root->right, k - rootNum);//k��° ��尡 ��Ʈ���� �����ʿ� �ִٸ� ��Ʈ�� ������ ����Ʈ���� ������ ������ ���ȣ��
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