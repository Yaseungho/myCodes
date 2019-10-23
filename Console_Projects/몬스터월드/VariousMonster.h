#ifndef __VARIOUSMONSTER__
#define __VARIOUSMONSTER__

#include "MonsterWorld.h"

void Move_Normal::Move(int& x, int& y, int& NEnergy) {
	int MoveX = rand() % 17 - 8;
	int MoveY = rand() % 17 - 8;
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} // ����� ������ �̵� �˰��� (8ĭ ���� ������ ��ġ�� �̵�)

void Move_Zombie::Move(int& x, int& y, int& NEnergy) {
	const int DX[8] = { -1,-1,-1, 1, 1, 1, 0, 0 };
	const int DY[8] = { -1, 0, 1,-1, 0, 1,-1, 1 };
	int RandDirection = rand() % 8;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} //������ �̵� �˰��� (��, ��, ��, ��, ����, ����, �ϵ�, �ϼ� 8���� �� ������ �������� 1ĭ �̵�)

void Move_Vampire::Move(int& x, int& y, int& NEnergy) {
	const int DX[4] = { 0, 0,-1, 1 };
	const int DY[4] = { -1, 1, 0, 0 };
	int RandDirection = rand() % 4;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} //�����̾��� �̵� �˰��� (��, ��, ��, �� 4���� �� ������ �������� 1ĭ �̵�)

void Move_Undead::Move(int& x, int& y, int& NEnergy) {
	const int DX[4] = { 0, 0,-2, 2 };
	const int DY[4] = { -2, 2, 0, 0 };
	int RandDirection = rand() % 4;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
	if (!RandDirection) NEnergy++;
} //�𵥵��� �̵� �˰��� (��, ��, ��, �� 4���� �� ������ �������� 2ĭ �̵�, �̵� �� 25% Ȯ���� ������ 1 �߰� ȸ��)

void Move_Ghost::Move(int& x, int& y, int& NEnergy) {
	int RandNum = rand() % 4;
	if (RandNum) {
		x = rand() % 16;
		y = rand() % 8;
		NEnergy -= 3;
	}
} //������ �̵� �˰��� (75%Ȯ���� ���� ���� ��ġ�� �̵�, �̵��ø��� ������ 3 �߰� ����)

void Move_Knight::Move(int& x, int& y, int& NEnergy) {
	const int DX[8] = {  2,-2, 2,-2, 1,-1, 1,-1 };
	const int DY[8] = {  1, 1,-1,-1, 2, 2,-2,-2 };
	int RandDirection = rand() % 8;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} //����Ʈ�� �̵� �˰��� (������ �������� ü���� '����Ʈ' ó�� L�ڷ� �̵�)

class NormalMonster : public Monster {
public:
	NormalMonster(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Normal); }
}; //�����ڸ� ���� NormalMonster���� �´� �̵� �˰��� �Ҵ�

class Zombie : public Monster {
public:
	Zombie(string _Name, string _Icon) : 
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Zombie); }
}; //�����ڸ� ���� Zombie���� �´� �̵� �˰��� �Ҵ�

class Vampire : public Monster {
public:
	Vampire(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Vampire); }
}; //�����ڸ� ���� Vampire���� �´� �̵� �˰��� �Ҵ�

class Undead : public Monster {
public:
	Undead(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Undead); }
}; //�����ڸ� ���� Undead���� �´� �̵� �˰��� �Ҵ�

class Ghost : public Monster {
public:
	Ghost(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Ghost); }
}; //�����ڸ� ���� Ghost���� �´� �̵� �˰��� �Ҵ�

class Knight : public Monster {
public:
	Knight(string _Name, string _Icon) :
		Monster(_Name, _Icon) {
		SetMoveBehavior(new Move_Knight);
	}
}; //�����ڸ� ���� ���� �´� �̵� �˰��� �Ҵ�

#endif