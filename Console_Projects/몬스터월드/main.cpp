#include "MonsterWorld.h"
#include "VariousMonster.h"

int main() {
	CursorView(0);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	srand((unsigned int)time(NULL));
	//커서 숨기기, 입출력 속도향상, 난수 시드값 초기화

	vector<Monster*> Monsters;
	Monsters.push_back(new NormalMonster("슬라임", "★"));
	Monsters.push_back(new Zombie("좀비  ", "⊙"));
	Monsters.push_back(new Vampire("흡혈귀", "◈"));
	Monsters.push_back(new Undead("언데드", "♨"));
	Monsters.push_back(new Ghost("유령  ", "∩"));
	Monsters.push_back(new Knight("기사  ", "§"));
	//Monster* 형 벡터를 선언 후 몬스터들의 정보를 동적할당

	Screen Game;
	Game.StartScreen(Monsters);
	while (Game.NItem != 0 && !(Monsters.empty())) Game.Update(Monsters);
	//게임 진행

	gotoxy(0, 14 + Monsters.size());
	cout << (Game.NItem == 0 ? "몬스터들이 모든 아이템을 먹었습니다 !\n" : "몬스터들이 모두 죽었습니다 !\n");
	//결과 출력

	for (auto& v : Monsters) delete v;
	//할당 해제
	return 0;
}