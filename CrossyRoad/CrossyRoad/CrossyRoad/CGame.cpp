#include "CGame.h"
bool theme = true;
CGAME::CGAME()
{
	cn = new CPEOPLE;
	CVEHICLE* temp = new CCAR(30, lane[4], true);
	veh.push_back(temp);
	temp = new CTRUCK(60, lane[0], true);
	veh.push_back(temp);
	temp = new CCAR(15, 21, false);
	veh.push_back(temp);
	temp = new CCAR(3, 9, true);
	veh.push_back(temp);
	temp = new CCAR(55, lane[4], true);
	veh.push_back(temp);
	temp = new CCAR(35, lane[2], true);
	veh.push_back(temp);
	temp = new CTRUCK(15, lane[1], false);
	veh.push_back(temp);
	temp = new CTRUCK(40, lane[1], false);
	veh.push_back(temp);

	temp = new CTRUCK(25, 1, true);
	veh.push_back(temp);
	CANIMAL* tempA = new CBIRD(41, 25);
	ani.push_back(tempA);
	tempA = new CDINOSAUR(19, lane[3]);
	ani.push_back(tempA);
	tempA = new CBIRD(59, lane[3]);
	ani.push_back(tempA);
	tempA = new CDINOSAUR(19, 25);
	ani.push_back(tempA);
}

void CGAME::drawGame()
{
	clrscr();
	cn->drawPeople(cn->mX, cn->mY);
	int x = 1;
	gotoXY(x, 0);
	cout << (char)218;
	for (int i = x; i < screenSizePlay_L; i++) {
		cout << (char)196;
	}
	cout << (char)191;
	for (int j = 1; j < screenSizePlay_W; j++) {
		gotoXY(x, j);
		cout << (char)179;
	}
	gotoXY(x, screenSizePlay_W);
	cout << (char)192;
	for (int i = x; i <= screenSizePlay_L - x; i++) {
		cout << (char)196;
	}
	cout << (char)217;
	for (int j = 1; j < screenSizePlay_W; j++) {
		gotoXY(screenSizePlay_L + 1, j);
		cout << (char)179;

	}
	for (int i = 4; i < screenSizePlay_W; i += 4) {
		gotoXY(x, i);
		cout << (char)195;
		for (int j = 1; j <= screenSizePlay_L - x; j++)
			cout << (char)196;
		cout << (char)180;
	}
	insBoard();
	instruction();
}

CGAME::~CGAME()
{
	//delete[] axt, axh, akl, ac;
	//axt = nullptr;
	//axh = nullptr;
	//akl = nullptr;
	//ac = nullptr;
}

CPEOPLE* CGAME::getPeople()
{
	return cn;
}

vector<CVEHICLE*>& CGAME::getVehicle()
{
	//int numberOfVehicle = sizeof(axt) + sizeof(axh);
	//CVEHICLE * ret = new CVEHICLE[numberOfVehicle];
	//int count = 0;
	//for (count; count < sizeof(axt); count++)
	//	ret[count] = axt[count];
	//int countTemp = 0;
	//for (count; count < numberOfVehicle; count++)
	//{
	//	ret[count] = axh[countTemp];
	//	countTemp++;
	//}
	//return ret;
	return veh;
}

vector <CANIMAL*>& CGAME::getAnimal()
{
	//int numberOfAni = sizeof(akl) + sizeof(ac);
	//CANIMAL * ret = new CANIMAL[numberOfAni];
	//int count = 0;
	//for (count; count < sizeof(akl); count++)
	//	ret[count] = akl[count];
	//int countTemp = 0;
	//for (count; count < numberOfAni; count++)
	//{
	//	ret[count] = ac[countTemp];
	//	countTemp++;
	//}
	//return ret;
	return ani;
}

void CGAME::resetGame()
{
	//cn = new CPEOPLE;
	//CVEHICLE* temp = new CCAR(30, lane[4], true);
	//veh.push_back(temp);
	int i = 0;
	veh[i]->setdata(30, lane[4], true);
	i++;
	//temp = new CTRUCK(60, lane[0], true);
	//veh.push_back(temp);
	veh[i]->setdata(60, lane[0], true);
	i++;
	//temp = new CCAR(15, 21, false);
	//veh.push_back(temp);
	veh[i]->setdata(15, lane[5], false);
	i++;
	//temp = new CCAR(3, 9, true);
	//veh.push_back(temp);
	veh[i]->setdata(3, lane[2], true);
	i++;
	//temp = new CCAR(55, lane[4], true);
	//veh.push_back(temp);
	veh[i]->setdata(55, lane[4], true);
	i++;
	//temp = new CCAR(35, lane[2], true);
	//veh.push_back(temp);
	veh[i]->setdata(35, lane[2], true);
	i++;
	//temp = new CTRUCK(15, lane[1], false);
	//veh.push_back(temp);
	veh[i]->setdata(15, lane[1], false);
	i++;
	//temp = new CTRUCK(40, lane[1], false);
	//veh.push_back(temp);
	veh[i]->setdata(40, lane[1], false);
	i++;

	//temp = new CTRUCK(25, 1, true);
	//veh.push_back(temp);
	veh[i]->setdata(25, lane[0], true);
	i++;
	//CANIMAL* tempA = new CBIRD(41, 25);
	//ani.push_back(tempA);
	i = 0;
	ani[i]->setData(41, lane[6]);
	i++;
	//tempA = new CDINOSAUR(19, lane[3]);
	//ani.push_back(tempA);
	ani[i]->setData(19, lane[3]);
	i++;
	//tempA = new CBIRD(59, lane[3]);
	//ani.push_back(tempA);
	ani[i]->setData(59, lane[3]);
	i++;
	//tempA = new CDINOSAUR(19, 25);
	//ani.push_back(tempA);
	ani[i]->setData(19, lane[6]);
	cn->changeState(true);
	cn->mX = screenSizePlay_L / 2;
	cn->mY = screenSizePlay_W - 3;
	cn->level = 1;
}

void CGAME::exitGame(HANDLE t)
{
	TerminateThread(t, 0);
	//~CGAME();
	exit(1);
}

void CGAME::startGame()
{
	normalSize();
	//resetGame();
	//cn.changeState(true);
	//cn = new CPEOPLE;

	cn->mState = true;
	cn->changeState(true);
	pause = false;
	drawGame();
}

void CGAME::pauseGame(HANDLE t)
{
	pause = true;
}

void CGAME::resumeGame(HANDLE)
{
	pause = false;
}

void CGAME::updatePosPeople(char mov)
{
	int oldLevel = cn->getLevel();
	cn->move(mov);
	int j = 0;
	if (cn->getLevel() - oldLevel != 0)
	{
		CANIMAL* temp = new CDINOSAUR(2, lane[j]);
		j++;
	}
}

void CGAME::updatePosVehicle()
{
	
	for (int i = 0; i < veh.size(); i++)
	{
		if (veh[i]->getDirection())
			veh[i]->Move(veh[i]->mX + 1, veh[i]->mY);
		else veh[i]->Move(veh[i]->mX - 1, veh[i]->mY);
		if (veh[i]->mY == cn->mY && (veh[i]->mX % 10 == 0) && cn->level <=5)
		{
			srand(time(0));
			int rd = rand() + 1;
			if(rd % 4 == 0)
				PlaySound("sound/horn_1.WAV", NULL, SND_ASYNC);
			else if (rd % 2 == 0)
				PlaySound("sound/horn_3.WAV", NULL, SND_ASYNC);
			else
				PlaySound("sound/horn_4.WAV", NULL, SND_ASYNC);

		}
		
	}

}

void CGAME::updatePosAnimal()
{
	
	for (int i = 0; i < ani.size(); i++)
	{
		ani[i]->Move(ani[i]->mX + 1, ani[i]->mY);
		if ((ani[i]->mX % 15 == 0) && (ani[i]->mY == cn->mY) && cn->level <= 5)
		{
			srand(time(0));
			int rd = rand() % 2 + 1;
			if (rd % 2 == 0)
				PlaySound("sound/dino.WAV", NULL, SND_ASYNC);

		}
	}
}

bool CGAME::getPause()
{
	return pause;
}

void CGAME::setPause(bool x)
{
	pause = x;
}

void CGAME::addMore(CANIMAL * x)
{
	ani.push_back(x);
}

bool CGAME::saveGame(string sFile)
{
	ofstream sF;
	sF.open(sFile);
	if (!sF.is_open())
		return false;
	sF << cn->mX << endl;
	sF << cn->mY << endl;
	sF << cn->level << endl;
	for (int i = 0; i < veh.size(); i++)
	{
		sF << veh[i]->mX << endl; 
		sF << veh[i]->mY << endl;
	}
	for(int i  = 0 ; i< ani.size();i++)
	{
		sF << ani[i]->mX << endl;
		sF << ani[i]->mY << endl;
	}
	cout << endl;
	sF.close();
	return true;
}

bool CGAME::loadGame(string sFile)
{
	cn->erasePeople(cn->mX,cn->mY);
	for (int i = 0; i < veh.size(); i++)
	{
		veh[i]->eraseVehicle();
	}
	for (int i = 0; i < ani.size(); i++)
	{
		ani[i]->eraseAnimal();
	}
	ifstream sF;
	sF.open(sFile);
	if (!sF.is_open())
		return false;
	sF >> cn->mX;
	sF >> cn->mY;
	sF >> cn->level;
	for (int i = 0; i < veh.size(); i++)
	{
		sF >> veh[i]->mX;
		sF >> veh[i]->mY;
	}
	for (int i = 0; i < ani.size(); i++)
	{
		sF >> ani[i]->mX;
		sF >> ani[i]->mY;
	}
	sF.close();
	return true;
}

void CGAME::instruction()
{
	int x = screenSizePlay_L + 10, y = 1;
	gotoXY(x, y);
	cout << " CROSSY ROAD - CS202 Final Project ";
	y += 3;
	gotoXY(x, y);
	cout << "[w] [^]  UP";
	gotoXY(x, y + 2);
	cout << "[s] [v]  DOWN";
	gotoXY(x, y + 4);
	cout << "[a] [<]  LEFT";
	gotoXY(x, y + 6);
	cout << "[d] [>]  RIGHT";
	gotoXY(x + 17, y);
	cout << "[L] [l]  SAVE GAME";
	gotoXY(x + 17, y + 2);
	cout << "[T] [t]  LOAD GAME";
	gotoXY(x + 17, y + 4);
	cout << "[SPACE]  PAUSE";
	gotoXY(x + 17, y + 6);
	cout << "[ ESC ]  BACK";

	gotoXY(x, y + 10);
	cout << " PLAYER  [ ____________________ ]";

	gotoXY(112, 18); cout << "       ";
	
	theme ? TextColor(Theme1_Highlight) : TextColor(Theme2_Highlight);
	if (cn->getLevel() <= 5) {
		gotoXY(x + 10, y + 14);
		cout << " L E V E L ";
		gotoXY(112, 18);
		cout << " " << cn->getLevel() << " ";
	}
	else {
		gotoXY(100, 18); cout << " INFINITE MODE ";
	}
	theme ? TextColor(Theme1_Black) : TextColor(Theme2_Black);
	gotoXY(x + 3, y + 18);
	cout << "Nguyen Trung Hau  - 18125129";
	gotoXY(x + 3, y + 20);
	cout << "Truong Thuy Quyen - 18125110";
	gotoXY(x + 3, y + 22);
	cout << "Nguyen Thao Ninh  - 18125106";
}

void CGAME::insBoard()
{
	int x = screenSizePlay_L + 6;
	int W = 41, H = 32;
	gotoXY(x, 0);
	cout << (char)218;
	for (int i = x; i < W + x; i++) {
		cout << (char)196;
	}
	cout << (char)191;
	for (int j = 1; j < H; j++) {
		gotoXY(x, j);
		cout << (char)179;
	}
	gotoXY(x, H);
	cout << (char)192;
	for (int i = x; i < W + x; i++) {
		cout << (char)196;
	}
	cout << (char)217;
	for (int j = 1; j < H; j++) {
		gotoXY(x + W + 1, j);
		cout << (char)179;

	}
	gotoXY(x, 2);
	cout << (char)195;
	for (int j = 1; j < W + 1; j++)
		cout << (char)196;
	cout << (char)180;

	gotoXY(x, 12);
	cout << (char)195;
	for (int j = 1; j < W + 1; j++)
		cout << (char)196;
	cout << (char)180;

	gotoXY(x, 16);
	cout << (char)195;
	for (int j = 1; j < W + 1; j++)
		cout << (char)196;
	cout << (char)180;

	gotoXY(x, 20);
	cout << (char)195;
	for (int j = 1; j < W + 1; j++)
		cout << (char)196;
	cout << (char)180;
	
	gotoXY(x, 28);
	cout << (char)195;
	for (int j = 1; j < W + 1; j++)
		cout << (char)196;
	cout << (char)180;
}
