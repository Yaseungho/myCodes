#ifndef __GAME__
#define __GAME__
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

void gotoxy(int x, int y);

void CursorView(char show);

class Farmer {
public:
	Farmer(int _x, int _y, int _speed) : x(_x), y(_y), speed(_speed) {}
	int x, y;
	int speed;
};

class Yusin {
public:
	string icon;
	int x, y;
	Yusin() : x(2), y(2), icon("бу") {}
};

class Stage {
public:
	bool isGameover;
	bool isClear;
	int Nfarmer;
	int Nrice;
	bool map[80][25];
	vector<Farmer*> Farmers;
	Stage(int _Nfarmer, int _Nrice) : isGameover(false), isClear(false), Nfarmer(_Nfarmer), Nrice(_Nrice), map() {}
	~Stage() {
		for (auto& v : Farmers) delete v;
	}
};

class Stage_1 : public Stage {
public:
	Stage_1(int _Nfarmer, int _Nrice) : Stage(_Nfarmer, _Nrice) {
		map[50][10] = true;
		map[50][14] = true;
		map[58][10] = true;
		map[58][14] = true;
		map[58][18] = true;
		Farmers.push_back(new Farmer(42, 10, 500));
		Farmers.push_back(new Farmer(42, 14, 400));
		Farmers.push_back(new Farmer(42, 18, 300));
	}
};

class Stage_2 : public Stage {
public:
	Stage_2(int _Nfarmer, int _Nrice) : Stage(_Nfarmer, _Nrice) {
		map[50][10] = true;
		map[50][14] = true;
		map[58][10] = true;
		map[58][14] = true;
		map[58][18] = true;		
		map[66][10] = true;
		map[66][14] = true;
		map[66][18] = true;
		map[74][10] = true;
		map[74][14] = true;
		Farmers.push_back(new Farmer(42, 10, 400));
		Farmers.push_back(new Farmer(42, 14, 350));
		Farmers.push_back(new Farmer(42, 18, 300));
		Farmers.push_back(new Farmer(12, 14, 250));
		Farmers.push_back(new Farmer(12, 18, 200));
	}
};

class Stage_3 : public Stage {
public:
	Stage_3(int _Nfarmer, int _Nrice) : Stage(_Nfarmer, _Nrice) {
		map[34][6] = true;
		map[42][7] = true;
		map[50][8] = true;
		map[58][9] = true;
		map[66][10] = true;
		map[36][12] = true;
		map[44][13] = true;
		map[52][14] = true;
		map[60][15] = true;
		map[68][16] = true;
		map[38][18] = true;
		map[46][19] = true;
		map[54][20] = true;
		map[62][21] = true;
		map[70][22] = true;
		Farmers.push_back(new Farmer(78, 24, 100));
		Farmers.push_back(new Farmer(62, 24, 342));
		Farmers.push_back(new Farmer(46, 24, 204));
		Farmers.push_back(new Farmer(30, 24, 310));
		Farmers.push_back(new Farmer(14, 24, 209));
		Farmers.push_back(new Farmer(78, 19, 411));
		Farmers.push_back(new Farmer(78, 14, 533));
		Farmers.push_back(new Farmer(78, 9, 279));
		Farmers.push_back(new Farmer(78, 4, 622));
	}
};

class Screen {
public:
	bool Retry = true;
	int over = 0;
	virtual void show(vector<Stage*>& _Stages, int* NowStage) {}
	virtual void update() {}
};

class StartScreen : public Screen {
public:
	StartScreen() {}
	void show(vector<Stage*>& _Stages, int* NowStage);
};

class SelectScreen : public Screen {
public:
	SelectScreen() {}
	void show(vector<Stage*>& _Stages,  int * NowStage);
};

class InGameScreen : public Screen {
public:
	InGameScreen(Stage* _stage) : stage(_stage), yusin(new Yusin()) {}
	Stage * stage;
	Yusin * yusin;
	void show(vector<Stage*>& _Stages, int* NowStage);
	void update();
	~InGameScreen() {
		delete stage;
		delete yusin;
	}
};

class GameOverScreen : public Screen {
public:
	GameOverScreen() {}
	void show(vector<Stage*>& _Stages, int* NowStage);
};

class GameClearScreen : public Screen {
public:
	GameClearScreen() {}
	void show(vector<Stage*>& _Stages, int* NowStage);
};

class EndingScreen : public Screen {
public:
	EndingScreen() {}
	void show(vector<Stage*>& _Stages, int* NowStage);
};

class Game {
public:
	vector<Stage*> Stages;
	Screen* Nscreen = nullptr;
	int NowStage = 0;
};

#endif