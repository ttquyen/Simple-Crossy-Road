#include "CPeople.h"

CPEOPLE::CPEOPLE()
{
	mX = screenSizePlay_L / 2;
	mY = screenSizePlay_W - 3;
	level = 1;
}

bool CPEOPLE::isImpact(const vector<CVEHICLE *>& vehicle)
{
	for (int i =0; i < vehicle.size(); i++)
	{
		if ((vehicle[i]->mX-4 <= mX && (mX <= (vehicle[i]->mX + 12))) && vehicle[i]->mY == mY) {
			mState = false;
			return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(const vector<CANIMAL *>&animal)
{
	for (int i = 0; i < animal.size(); i++)				
	{
		if ((animal[i]->mX-4 <= mX) && (mX <= animal[i]->mX + 7) && animal[i]->mY == mY) {
			mState = false;
			return true;
		}
	}
	return false;
}

bool CPEOPLE::isFinish()
{
	if (level == 5 && mY==3)
		return true;
	return false;
}

void CPEOPLE::increaseLevel()
{
	if (level <= 5) {
		PlaySound("sound/levelup.WAV", NULL, SND_ASYNC);
		++level;
	}
	if (level == 6)
	{
		PlaySound("sound/bgm.WAV", NULL, SND_ASYNC);
		gotoXY(100,30); cout <<  "CONGRATULATIONS!";
		gotoXY(94, 31); cout << "You've reached infinite mode!";
		++level;
	}
	if (level > 6) {
		++level;
	}
	gotoXY(112, 18);
	theme ? TextColor(Theme1_Highlight) : TextColor(Theme2_Highlight);
	cout << " " << level << " ";
	theme ? TextColor(Theme1_Black) : TextColor(Theme2_Black);
}

/*
  ___
 (o-o)
 /___\
*/
void CPEOPLE::drawPeople(int x, int y)
{
	if (!isDead()) {
		gotoXY(x, y);
		cout << "  ___";
		gotoXY(x, y + 1);
		cout << " (o-o)";
		gotoXY(x, y + 2);
		cout << " /___\\";
	}
	else {
		theme ? TextColor(Theme1_Red) : TextColor(Theme2_Red);
		gotoXY(x, y);
		cout << "  ___";
		gotoXY(x, y + 1);
		cout << " (x-x)";
		gotoXY(x, y + 2);
		cout << " /___\\";
		theme ? TextColor(Theme1_Black) : TextColor(Theme2_Black);
	}
}

void CPEOPLE::erasePeople(int x, int y)
{
	gotoXY(x, y);
	cout << "      ";
	gotoXY(x, y + 1);
	cout << "       ";
	gotoXY(x, y + 2);
	cout << "       ";
}
void CPEOPLE::changeState(bool x)
{
	mState = x;
}
void CPEOPLE::move(int m)
{
	int key = m;
	if (key == key_Up || key == 'w')	//di len
	{
		if (mY < 3)
		{
			erasePeople(mX, mY);
			increaseLevel();
		
			mX = screenSizePlay_L / 2;
			mY = screenSizePlay_W - 3;
			drawPeople(mX, mY);
		}
		else {
			erasePeople(mX, mY);
			mY -= 4;
			gotoXY(mX, mY);
			drawPeople(mX, mY);
			return;
		}

	}
	if (key == key_Down || key == 's')	//di xuong
	{
		if (mY >= screenSizePlay_W - 3)
			return;
		else {
			erasePeople(mX, mY);
			mY += 4;
			gotoXY(mX, mY);
			drawPeople(mX, mY);
			return;
		}

	}
	if (key == key_Left || key == 'a')	//qua trai
	{
		if (mX <= 2)
			return;
		else {
			erasePeople(mX, mY);
			mX -= 2;
			gotoXY(mX, mY);
			drawPeople(mX, mY);
			return;
		}

	}
	if (key == key_Right || key == 'd')	//qua phai
	{
		if (mX >= screenSizePlay_L - 6)
			return;
		else {
			erasePeople(mX, mY);
			mX += 2;
			gotoXY(mX, mY);
			drawPeople(mX, mY);
			return;
		}
	}
	else return;
}
int CPEOPLE::getLevel()
{
	return level;
}

bool CPEOPLE::isDead()
{
	if (mState == 0)
		return true;
	else
		return false;
}

void drawScreen()
{
	gotoXY(0, 0);
	cout << (char)201;
	for (int i = 0; i < screenSizePlay_L; i++) {
		cout << (char)205;
	}
	cout << (char)187;
	for (int j = 1; j < screenSizePlay_W; j++) {
		gotoXY(0, j);
		cout << (char)186;
	}
	gotoXY(0, screenSizePlay_W);
	cout << (char)200;
	for (int i = 0; i <= screenSizePlay_L - 1; i++) {
		cout << (char)205;
	}
	cout << (char)188;
	for (int j = 1; j < screenSizePlay_W; j++) {
		gotoXY(screenSizePlay_L + 1, j);
		cout << (char)186;

	}
	for (int i = 4; i < screenSizePlay_W; i += 4) {
		gotoXY(0, i);
		cout << (char)199;
		for (int j = 1; j <= screenSizePlay_L; j++)
			cout << (char)196;
		cout << (char)182;
	}

}