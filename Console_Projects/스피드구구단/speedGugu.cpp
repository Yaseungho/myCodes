#include "speedGugu.h"

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Speedgame::Speedgame() : NumGame{ 5 }, NumWins{ 0 }, Score{ 0 } {}

void Speedgame::startWindow() {
	system("cls");
	gotoxy(0, 0);
	cout << "��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "��";
		gotoxy(79, i); cout << "��";
	}
	cout << "\n��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";
	gotoxy(28, 6);
	cout << "[���ǵ� ��Ģ���� ����]";
	gotoxy(22, 11);
	cout << "����� ��Ģ���� �Ƿ��� �׽�Ʈ�ϼ���..!!";
	gotoxy(18, 12);
	cout << "�׽�Ʈ�� Ƚ���� ���� �� �غ�Ǹ� ���͸� ��������. . .";
	gotoxy(30, 17);
	cout << "���� ���� : 5�� ��";
	int GetKey = 0;
	while (GetKey != 13) {
		if (_kbhit()) {
			GetKey = _getch();
			if (GetKey == 224) {
				GetKey = _getch();
				if (GetKey == 72) {
					if (NumGame != 10) NumGame++;
					gotoxy(42, 17);
					if (NumGame == 10) cout << NumGame << "�� ��";
					else cout << NumGame << "�� ��";
				}
				else if (GetKey == 80) {
					if (NumGame > 5) NumGame--;
					gotoxy(42, 17);
					if (NumGame == 5) cout << NumGame << "�� ��";
					else cout << NumGame << "�� ��";
				}
			}
		}
	}
}

void Speedgame::play() {
	int answer;
	float timer;
	system("cls");
	gotoxy(0, 0);
	cout << "��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";
	for (int i = 1; i < 25; i++) {
		gotoxy(0, i); cout << "��";
		gotoxy(79, i); cout << "��";
	}
	cout << "\n��"; for (int i = 0; i < 78; i++) cout << "��"; cout << "��";


	clock_t start = clock();
	for (int i = 1; i <= NumGame; i++) {
		Quiz q;
		gotoxy(3, (i * 2) + 1);
		cout << "[���� " << i << "]: " << q.mathProblem << " = ";
		cin >> answer;
		if (q.solution != answer) {
			gotoxy(25, (i * 2) + 1);
			cout << "Ʋ�Ƚ��ϴ�!\n";
		}
		else NumWins++;
	}
	clock_t end = clock();
	timer = (float)(end - start) / CLOCKS_PER_SEC;
	Score = (100 * (20 * NumGame - timer) / (20 * NumGame)) - (20.0 * NumGame) + (20.0 * NumWins);
	gotoxy(12, (2 * NumGame) + 4);
	Score = Score > 0.0 ? Score : 0;
	cout << "���� ���� : "<< NumWins <<"�� / ���� : " << Score << "�� / �ɸ��ð� : " << timer << "��";
	gotoxy(0, 25); 
}

Quiz::Quiz() {
	int length = rand() % 2 ? 3 : 5;
	int randNum1, randNum2, randNum3;
	int Operator1, Operator2;
	if (length == 3) {
		Operator1 = rand() % 3;
		randNum1 = rand() % 8 + 50;
		randNum2 = rand() % 8 + 50;
		mathProblem.push_back(randNum1);
		switch (Operator1) {
		case 0:
			mathProblem.push_back('+');
			solution = (randNum1 - 48) + (randNum2 - 48);
			break;
		case 1:
			mathProblem.push_back('-');
			solution = (randNum1 - 48) - (randNum2 - 48);
			break;
		case 2:
			mathProblem.push_back('*');
			solution = (randNum1 - 48) * (randNum2 - 48);
			break;
		default:
			break;
		}
		mathProblem.push_back(randNum2);
	}
	else if (length == 5) {
		Operator1 = rand() % 3;
		Operator2 = rand() % 3;
		randNum1 = rand() % 8 + 50;
		randNum2 = rand() % 8 + 50;
		randNum3 = rand() % 8 + 50;
		mathProblem.push_back(randNum1);
		switch (Operator1) {
		case 0:
			mathProblem.push_back('+');
			mathProblem.push_back(randNum2);
			switch (Operator2) {
			case 0:
				mathProblem.push_back('+');
				solution = (randNum1 - 48) + (randNum2 - 48) + (randNum3 - 48);
				break;
			case 1:
				mathProblem.push_back('-');
				solution = (randNum1 - 48) + (randNum2 - 48) - (randNum3 - 48);
				break;
			case 2:
				mathProblem.push_back('*');
				solution = (randNum1 - 48) + (randNum2 - 48) * (randNum3 - 48);
				break;
			default:
				break;
			}
			break;
		case 1:
			mathProblem.push_back('-');
			mathProblem.push_back(randNum2);
			switch (Operator2) {
			case 0:
				mathProblem.push_back('+');
				solution = (randNum1 - 48) - (randNum2 - 48) + (randNum3 - 48);
				break;
			case 1:
				mathProblem.push_back('-');
				solution = (randNum1 - 48) - (randNum2 - 48) - (randNum3 - 48);
				break;
			case 2:
				mathProblem.push_back('*');
				solution = (randNum1 - 48) - (randNum2 - 48) * (randNum3 - 48);
				break;
			default:
				break;
			}
			break;
		case 2:
			mathProblem.push_back('*');
			mathProblem.push_back(randNum2);
			switch (Operator2) {
			case 0:
				mathProblem.push_back('+');
				solution = (randNum1 - 48) * (randNum2 - 48) + (randNum3 - 48);
				break;
			case 1:
				mathProblem.push_back('-');
				solution = (randNum1 - 48) * (randNum2 - 48) - (randNum3 - 48);
				break;
			case 2:
				mathProblem.push_back('*');
				solution = (randNum1 - 48) * (randNum2 - 48) * (randNum3 - 48);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		mathProblem.push_back(randNum3);
	}
}