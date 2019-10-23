#include "MonsterWorld.h"
#include "VariousMonster.h"

int main() {
	CursorView(0);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	srand((unsigned int)time(NULL));
	//Ŀ�� �����, ����� �ӵ����, ���� �õ尪 �ʱ�ȭ

	vector<Monster*> Monsters;
	Monsters.push_back(new NormalMonster("������", "��"));
	Monsters.push_back(new Zombie("����  ", "��"));
	Monsters.push_back(new Vampire("������", "��"));
	Monsters.push_back(new Undead("�𵥵�", "��"));
	Monsters.push_back(new Ghost("����  ", "��"));
	Monsters.push_back(new Knight("���  ", "��"));
	//Monster* �� ���͸� ���� �� ���͵��� ������ �����Ҵ�

	Screen Game;
	Game.StartScreen(Monsters);
	while (Game.NItem != 0 && !(Monsters.empty())) Game.Update(Monsters);
	//���� ����

	gotoxy(0, 14 + Monsters.size());
	cout << (Game.NItem == 0 ? "���͵��� ��� �������� �Ծ����ϴ� !\n" : "���͵��� ��� �׾����ϴ� !\n");
	//��� ���

	for (auto& v : Monsters) delete v;
	//�Ҵ� ����
	return 0;
}