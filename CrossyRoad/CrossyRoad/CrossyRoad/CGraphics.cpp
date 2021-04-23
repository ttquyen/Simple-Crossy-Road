#include "CGraphics.h"
#include "CGame.h"
#include <chrono>
#include <ctime>


bool isRun = true;
int KEY = NULL;
int light = 1;
CGAME game;

void subThread()
{
	while (isRun) {
		while (!game.getPause() && KEY == NULL)
		{
			if (light == 1)
			{
				theme ? TextColor(Theme1_Red) : TextColor(Theme2_Red); // red light 1 2 3 5 6
				gotoXY(83, 2);
				cout << (char)219 << (char)219;
				gotoXY(83, 6);
				cout << (char)219 << (char)219;
				gotoXY(83, 10);
				cout << (char)219 << (char)219;
				gotoXY(83, 18);
				cout << (char)219 << (char)219;
				gotoXY(83, 22);
				cout << (char)219 << (char)219;
				theme ? TextColor(Theme1_Black) : TextColor(Theme2_Black);
				srand(time(NULL));
				light = rand() % 4 + 1;
			}
			else
			{
				theme ? TextColor(Theme1_Green) : TextColor(Theme2_Green); // green light
				gotoXY(83, 2);
				cout << (char)219 << (char)219;
				gotoXY(83, 6);
				cout << (char)219 << (char)219;
				gotoXY(83, 10);
				cout << (char)219 << (char)219;
				gotoXY(83, 18);
				cout << (char)219 << (char)219;
				gotoXY(83, 22);
				cout << (char)219 << (char)219;
				theme ? TextColor(Theme1_Black) : TextColor(Theme2_Black);
				
				game.updatePosVehicle();
				
				srand(time(NULL));
				light = rand() % 4 + 1;
			}
			game.updatePosAnimal();
			if (game.getPeople()->getLevel() == 5)
				Sleep(30);
			else if (game.getPeople()->getLevel() == 4)
				Sleep(50);
			else if (game.getPeople()->getLevel() == 3)
				Sleep(100);
			else if (game.getPeople()->getLevel() == 2)
				Sleep(150);
			else if (game.getPeople()->getLevel() == 1)
				Sleep(200);
			else Sleep(20);
		}
	}
}

void threadCheckImpact()
{
	while (isRun)
	{
		if (game.getPeople()->isImpact(game.getVehicle()) || game.getPeople()->isImpact(game.getAnimal())) {
			isRun = false;
			game.setPause(true);
			if (game.getPeople()->isImpact(game.getVehicle())) {
				PlaySound("sound/crash.WAV", NULL, SND_ASYNC);
			}
			else if (game.getPeople()->isImpact(game.getAnimal())) {
				PlaySound("sound/chirp.WAV", NULL, SND_ASYNC);
			}
			gameOver();
			game.resetGame();
			_getch();	
		}
	}
}

string space(int k)
{
	string ret = "";
	for (int i = 0; i < k; i++)
		ret += "  ";
	return ret;
}
string block(int k) {
	string ret = "";
	for (int i = 0; i < k; i++) {
		ret += (char)219;
		ret += (char)219;
	}
	return ret;
}

void Text(int x, int y) {
	gotoXY(x, y);     cout << space(1) << block(5) << space(1) << block(5) << space(3) << block(5) << space(4) << block(5) << space(4) << block(5) << space(2) << block(4) << space(3) << block(3) << endl;
	gotoXY(x, y + 1); cout << block(6) << space(1) << block(5) << space(2) << block(7) << space(2) << block(6) << space(3) << block(6) << space(3) << block(3) << space(3) << block(3) << endl;
	gotoXY(x, y + 2); cout << block(3) << space(4) << block(4) << space(2) << block(3) << space(2) << block(3) << space(1) << block(3) << space(6) << block(3) << space(7) << block(3) << space(2) << block(3) << endl;
	gotoXY(x, y + 3); cout << block(2) << space(5) << block(2) << space(4) << block(3) << space(2) << block(3) << space(1) << block(5) << space(4) << block(5) << space(6) << block(3) << space(1) << block(3) << endl;
	gotoXY(x, y + 4); cout << block(2) << space(5) << block(2) << space(4) << block(3) << space(2) << block(3) << space(2) << block(6) << space(3) << block(6) << space(4) << block(3) << space(1) << block(3) << endl;
	gotoXY(x, y + 5); cout << block(2) << space(5) << block(2) << space(4) << block(3) << space(2) << block(3) << space(4) << block(5) << space(4) << block(5) << space(4) << block(5) << endl;
	gotoXY(x, y + 6); cout << block(3) << space(4) << block(2) << space(4) << block(3) << space(2) << block(3) << space(1) << block(1) << space(4) << block(3) << space(1) << block(1) << space(4) << block(3) << space(4) << block(5) << endl;
	gotoXY(x, y + 7); cout << block(6) << space(1) << block(2) << space(5) << block(7) << space(2) << block(7) << space(2) << block(7) << space(4) << block(5) << endl;
	gotoXY(x, y + 8); cout << space(1) << block(5) << space(1) << block(2) << space(6) << block(5) << space(3) << block(6) << space(3) << block(6) << space(6) << block(3) << endl;
	gotoXY(x, y + 9); cout << space(44) << block(3) << endl;
	gotoXY(x, y + 10); cout << space(41) << block(5) << endl;
	gotoXY(x, y + 11); cout << space(9) << block(5) << space(2) << block(5) << space(4) << block(5) << space(2) << block(6) << space(3) << block(5) << endl;
	gotoXY(x, y + 12); cout << space(9) << block(5) << space(1) << block(7) << space(2) << block(7) << space(1) << block(7) << space(2) << block(2) << endl;
	gotoXY(x, y + 13); cout << space(9) << block(4) << space(1) << block(3) << space(2) << block(3) << space(6) << block(3) << space(1) << block(3) << space(2) << block(3) << endl;
	gotoXY(x, y + 14); cout << space(9) << block(2) << space(3) << block(3) << space(2) << block(3) << space(6) << block(3) << space(1) << block(3) << space(3) << block(2) << endl;
	gotoXY(x, y + 15); cout << space(9) << block(2) << space(3) << block(3) << space(2) << block(3) << space(2) << block(7) << space(1) << block(3) << space(3) << block(2) << endl;
	gotoXY(x, y + 16); cout << space(9) << block(2) << space(3) << block(3) << space(2) << block(3) << space(2) << block(7) << space(1) << block(3) << space(3) << block(2) << endl;
	gotoXY(x, y + 17); cout << space(9) << block(2) << space(3) << block(3) << space(2) << block(3) << space(2) << block(2) << space(2) << block(3) << space(1) << block(3) << space(2) << block(3) << endl;
	gotoXY(x, y + 18); cout << space(9) << block(2) << space(4) << block(7) << space(2) << block(7) << space(1) << block(7) << endl;
	gotoXY(x, y + 19); cout << space(9) << block(2) << space(5) << block(5) << space(3) << block(4) << space(1) << block(2) << space(1) << block(6) << endl;
}

void Menu()
{
	clrscr();
	int key = 999;
	setFontSize(40);
	resizeConsole(1080, 575);
	char menu_text[3][100] = { "NEW GAME","LOAD GAME","SETTINGS" };

	int x = 45, y = 17, Y = 17;
	gotoXY(x, 17); cout << menu_text[0];
	gotoXY(x - 1, 18); cout << menu_text[1];
	gotoXY(x, 19); cout << menu_text[2];
	isRun = true;
	do {
		gotoXY(x, y);
		switch (y)
		{
		case 17: gotoXY(x, Y); cout << menu_text[0]; break;
		case 18: gotoXY(x - 1, Y+1); cout << menu_text[1]; break;
		case 19: gotoXY(x, Y+2); cout << menu_text[2]; break;
		}
		if (key != key_Enter)
			key = _getch();
		if (key == key_Up)
		{
			gotoXY(x, y);
			switch (y)
			{
			case 17: gotoXY(x, Y); cout << menu_text[0]; break;
			case 18: gotoXY(x - 1, Y+1); cout << menu_text[1]; break;
			case 19: gotoXY(x, Y+2); cout << menu_text[2]; break;
			}
			y--;
			if (y < Y)
				y = Y+2;
		}
		else if (key == key_Down)
		{
			gotoXY(x, y);
			switch (y)
			{
			case 17: gotoXY(x, Y); cout << menu_text[0]; break;
			case 18: gotoXY(x - 1, Y+1); cout << menu_text[1]; break;
			case 19: gotoXY(x, Y+2); cout << menu_text[2]; break;
			}
			y++;
			if (y > Y+2)
				y = Y;
		}
		if (y == Y && key == key_Enter)	//NewGame
		{
			PlaySound("sound/click.WAV", NULL, SND_ASYNC);
			//Test();
			clrscr();

			game.startGame();
			game.drawGame();
			thread t(subThread);
			thread t1(threadCheckImpact);
			while (isRun)
			{

				int temp = toupper(_getch());
				KEY = temp;
				if (KEY == key_Space)
				{
					if (game.getPause() == false)
						game.setPause(true);
					else game.setPause(false);
				}
				if (KEY == 'l' || KEY == 'L')			//SaveInGame
				{
					game.setPause(true);
					string save_player;
					gotoXY(101, 14); cin >> save_player;
					game.saveGame(save_player);
					gotoXY(101, 14);
					cout << " successfully saved! ";
					game.resetGame();
					isRun = false;
					_getch();
					Menu();
				}
				if (KEY == 't' || KEY == 'T')			//LoadInGame
				{
					game.setPause(true);
					string load_player;
					gotoXY(101, 14); cin >> load_player;
					game.loadGame(load_player);
					light = 1;
					gotoXY(101, 14);
					cout << "    player loaded!   ";
					game.setPause(false);
				}
				if (KEY == 27)	//Phím esc
				{
					game.setPause(true);
					light = 1;
					isRun = false;
					game.resetGame();
					Sleep(50);
					Menu();
				}
				if (!game.getPause())
				{
					if (KEY != NULL)
					{
						game.updatePosPeople(KEY);
						KEY = NULL;
						Sleep(20);
					}
				}
			}
			t.join();
			t1.join();
			game.resetGame();
			Menu();
		}
		if (y == 18 && key == key_Enter)	//LoadGame
		{
			clrscr();
			PlaySound("sound/click.WAV", NULL, SND_ASYNC);
			CDINOSAUR a(13, 5);
			string load_player;
			gotoXY(20, 5);
			a.draw();
			cout << " Enter player: ";
			cin >> load_player;
			if (!game.loadGame(load_player)) {
				gotoXY(24, 5); cout << "Unable to find player! Press any key to type again.";
			}
			y = Y;
		}
		else if (y == 19 && key == key_Enter)	//Setting
		{
			clrscr();
			PlaySound("sound/click.WAV", NULL, SND_ASYNC);
			CDINOSAUR a(8, 5);
			a.draw();
			char opt = 'y';
			cout << " Change to dark theme? [y]/[n] ";
			cin >> opt;
			if (opt == 'y' || opt == 'Y') {
				theme = false;
				system("color 0E");
				cout << "Theme changed!";
			}
			else {
				theme = true;
				system("color E0");
				cout << "Default theme applied!";
			}
			Menu();
			y = Y;
		}
	} while (true);
}

void gameOver()
{
	clrscr();
	setFontSize(70);
	resizeConsole(1080, 575);
	gotoXY(4, 3); cout << "  oh no you lose :(";
	PlaySound("sound/game_over.WAV", NULL, SND_ASYNC);
}


//void Test() {
//	clrscr();
//	PlaySound("sound/bgm.WAV", NULL, SND_ASYNC);
//	drawScreen();
//	CPEOPLE a;
//	//a.drawPeople(screenSizePlay_L / 2-1, screenSizePlay_W-3);
//	//a.move();
//	CGAME m;
//	m.resetGame();
//}
void normalSize() {
	setFontSize(16);
	resizeConsole(1080, 575);
}