#include "Game.h"

int main() {
	srand(time(NULL));
	CursorView(false);
	Game game;
	game.Stages.push_back(new Stage_1(3, 5));
	game.Stages.push_back(new Stage_2(5, 10));
	game.Stages.push_back(new Stage_3(9, 15));

	game.Nscreen = new StartScreen();
	game.Nscreen->show(game.Stages, &game.NowStage);
	delete game.Nscreen;

	while (!(game.Stages[0]->isClear) || !(game.Stages[1]->isClear) || !(game.Stages[2]->isClear)) {
		game.Nscreen = new SelectScreen();
		game.Nscreen->show(game.Stages, &game.NowStage);
		delete game.Nscreen;

		game.Nscreen = new InGameScreen(game.Stages[game.NowStage]);
		game.Nscreen->show(game.Stages, &game.NowStage);
		while (!(game.Nscreen->over)) game.Nscreen->update();

		if (game.Nscreen->over == 1) {
			delete game.Nscreen;
			game.Nscreen = new GameClearScreen();
			game.Nscreen->show(game.Stages, &game.NowStage);
			delete game.Nscreen;
		}
		else if (game.Nscreen->over == 2) {

			delete game.Nscreen;

			bool save = game.Stages[0]->isClear;
			delete game.Stages[0];
			game.Stages[0] = new Stage_1(3, 5);
			game.Stages[0]->isClear = save;

			save = game.Stages[1]->isClear;
			delete game.Stages[1];
			game.Stages[1] = new Stage_2(5, 10);
			game.Stages[1]->isClear = save; 

			save = game.Stages[2]->isClear;
			delete game.Stages[2];
			game.Stages[2] = new Stage_3(9, 15);
			game.Stages[2]->isClear = save;
			game.Nscreen = new GameOverScreen();

			game.Nscreen->show(game.Stages, &game.NowStage);
			if (!(game.Nscreen->Retry)) {
				gotoxy(0, 26);
				return 0;
			}
			delete game.Nscreen;
		}
	}
	if (game.Stages[0]->isClear && game.Stages[1]->isClear && game.Stages[2]->isClear) {
		game.Nscreen = new EndingScreen();
		game.Nscreen->show(game.Stages, &game.NowStage);
		delete game.Nscreen;
	}
	gotoxy(0, 26);
	return 0;
}