#ifndef __MONSTERWORLD__
#define __MONSTERWORLD__

#define WIDTH 16
#define HEIGHT 8
#define MAXMOVE 200
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void gotoxy(int x, int y);
void CursorView(char show);
//콘솔창 관련 함수 선언

class MoveBehavior {
public:
	virtual void Move(int& x, int& y, int& NEnergy) {};
};
class Move_Normal : public MoveBehavior {
public:
	void Move(int& x, int& y, int& NEnergy);
};
class Move_Zombie : public MoveBehavior {
public:
	void Move(int& x, int& y, int& NEnergy);
};
class Move_Vampire : public MoveBehavior {
public:
	void Move(int& x, int& y, int& NEnergy);
};
class Move_Undead : public MoveBehavior {
public:
	void Move(int& x, int& y, int& NEnergy);
};
class Move_Ghost : public MoveBehavior {
public:
	void Move(int& x, int& y, int& NEnergy);
};
class Move_Knight : public MoveBehavior {
public:
	void Move(int& x, int& y, int& NEnergy);
};
//다양한 이동 알고리즘들을 캡슐화하여 교체 가능하게 구현 (Strategy 패턴)

class Monster {
public:
	string Name, Icon;
	MoveBehavior* Behavior;
	int NItem, NEnergy;
	int x, y;
	Monster(string _Name, string _Icon) :
		Name(_Name), x(rand() % WIDTH), y(rand() % HEIGHT), Icon(_Icon), NItem(0), NEnergy(100) {
		Behavior = new Move_Normal;
	}
	~Monster() {
		DeleteMove();
	}
	void Print();
	void DeleteMove();
	void Move();
	void SetMoveBehavior(MoveBehavior* temp);
};
//몬스터의 정보, 행동을 담은 클래스 선언

class Screen {
private:
	bool Map[WIDTH][HEIGHT] = { 1 };
public:
	int NMove = 0;
	int NItem = WIDTH * HEIGHT;
	int NDead = 0;
	void StartScreen(vector<Monster*>& _Monsters);
	void Update(vector<Monster*>& Monsters);
};
//게임 화면 출력에 필요한 정보를 담은 클래스 선언

#endif