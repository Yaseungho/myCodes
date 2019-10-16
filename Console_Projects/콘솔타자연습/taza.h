#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define NumberOfWords 20
using namespace std;

class Word {
public:
	string WordValue;
	int Length;
	int Speed;
	void Create();
	void Drop(int*, string*, int*, int*, bool*, int*);
};

class JudgmentLine {
public:
	void CreateLine();
};