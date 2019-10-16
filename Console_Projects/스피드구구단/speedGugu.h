#ifndef _SPEEDGUGU_H_
#define _SPEEDGUGU_H_
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

void gotoxy(int x, int y);

class Speedgame {
private:
	double NumGame;
	double NumWins;
	double Score;
public:
	Speedgame();
	void startWindow();
	void play();
};

class Quiz {
public:
	string mathProblem;
	int solution = 0;
	Quiz();
};

#endif