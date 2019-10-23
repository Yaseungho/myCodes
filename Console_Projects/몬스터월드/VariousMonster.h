#ifndef __VARIOUSMONSTER__
#define __VARIOUSMONSTER__

#include "MonsterWorld.h"

void Move_Normal::Move(int& x, int& y, int& NEnergy) {
	int MoveX = rand() % 17 - 8;
	int MoveY = rand() % 17 - 8;
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} // 평범한 몬스터의 이동 알고리즘 (8칸 내의 무작위 위치로 이동)

void Move_Zombie::Move(int& x, int& y, int& NEnergy) {
	const int DX[8] = { -1,-1,-1, 1, 1, 1, 0, 0 };
	const int DY[8] = { -1, 0, 1,-1, 0, 1,-1, 1 };
	int RandDirection = rand() % 8;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} //좀비의 이동 알고리즘 (동, 서, 남, 북, 남동, 남서, 북동, 북서 8방향 중 무작위 방향으로 1칸 이동)

void Move_Vampire::Move(int& x, int& y, int& NEnergy) {
	const int DX[4] = { 0, 0,-1, 1 };
	const int DY[4] = { -1, 1, 0, 0 };
	int RandDirection = rand() % 4;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} //뱀파이어의 이동 알고리즘 (동, 서, 남, 북 4방향 중 무작위 방향으로 1칸 이동)

void Move_Undead::Move(int& x, int& y, int& NEnergy) {
	const int DX[4] = { 0, 0,-2, 2 };
	const int DY[4] = { -2, 2, 0, 0 };
	int RandDirection = rand() % 4;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
	if (!RandDirection) NEnergy++;
} //언데드의 이동 알고리즘 (동, 서, 남, 북 4방향 중 무작위 방향으로 2칸 이동, 이동 시 25% 확률로 에너지 1 추가 회복)

void Move_Ghost::Move(int& x, int& y, int& NEnergy) {
	int RandNum = rand() % 4;
	if (RandNum) {
		x = rand() % 16;
		y = rand() % 8;
		NEnergy -= 3;
	}
} //유령의 이동 알고리즘 (75%확률로 맵의 랜덤 위치로 이동, 이동시마다 에너지 3 추가 감소)

void Move_Knight::Move(int& x, int& y, int& NEnergy) {
	const int DX[8] = {  2,-2, 2,-2, 1,-1, 1,-1 };
	const int DY[8] = {  1, 1,-1,-1, 2, 2,-2,-2 };
	int RandDirection = rand() % 8;
	int MoveX = DX[RandDirection];
	int MoveY = DY[RandDirection];
	x = (x + MoveX) >= 0 && (x + MoveX) <= 15 ? x + MoveX : x + MoveX < 0 ? 0 : 15;
	y = (y + MoveY) >= 0 && (y + MoveY) <= 7 ? y + MoveY : y + MoveY < 0 ? 0 : 7;
} //나이트의 이동 알고리즘 (무작위 방향으로 체스의 '나이트' 처럼 L자로 이동)

class NormalMonster : public Monster {
public:
	NormalMonster(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Normal); }
}; //생성자를 통해 NormalMonster에게 맞는 이동 알고리즘 할당

class Zombie : public Monster {
public:
	Zombie(string _Name, string _Icon) : 
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Zombie); }
}; //생성자를 통해 Zombie에게 맞는 이동 알고리즘 할당

class Vampire : public Monster {
public:
	Vampire(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Vampire); }
}; //생성자를 통해 Vampire에게 맞는 이동 알고리즘 할당

class Undead : public Monster {
public:
	Undead(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Undead); }
}; //생성자를 통해 Undead에게 맞는 이동 알고리즘 할당

class Ghost : public Monster {
public:
	Ghost(string _Name, string _Icon) :
		Monster(_Name, _Icon) { SetMoveBehavior(new Move_Ghost); }
}; //생성자를 통해 Ghost에게 맞는 이동 알고리즘 할당

class Knight : public Monster {
public:
	Knight(string _Name, string _Icon) :
		Monster(_Name, _Icon) {
		SetMoveBehavior(new Move_Knight);
	}
}; //생성자를 통해 에게 맞는 이동 알고리즘 할당

#endif