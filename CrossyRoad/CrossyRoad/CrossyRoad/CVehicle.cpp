#include "Library.h"


CVEHICLE::CVEHICLE()
{
	mX = 0;
	mY = 0;
}

CVEHICLE::CVEHICLE(int x, int y, bool dir)
{
	mX = x;
	mY = y;
	direction = dir;
}

bool CVEHICLE::getDirection()
{
	return direction;
}

void CCAR::Move(int x, int y)
{
	eraseVehicle();
	if (direction) {
		if (x >= screenSizePlay_L - 12)
		{
			eraseVehicle();
			mX = 2;
			mY = y;
			draw();

			return;
		}
	}
	else {
		if (x <= 2) {
			eraseVehicle();
			mX = screenSizePlay_L - 13;
			mY = y;
			draw();

			return;
		}
	}
	mX = x;
	mY = y;
	draw();
}
/*
	   ______
	  /|_||_\\__
	 |_ o___o ___\
	      ______
	   __//_||_|\
	 /____o___o__|
 */
void CCAR::draw()
{
	int x = mX;
	int y = mY;
	if (direction) {
		gotoXY(x, y);
		cout << "   ______";
		gotoXY(x, y + 1);
		cout << "  /|_||_\\\\___";
		gotoXY(x, y + 2);
		cout << " |_ o___o ___|";
	}
	else {
		gotoXY(x, y);
		cout << "     ______";
		gotoXY(x, y + 1);
		cout << "  __//_||_|\\";
		gotoXY(x, y + 2);
		cout << "/____o___o__|";
	}
}
CCAR::CCAR() : CVEHICLE()
{
	type = car;
}
CCAR::CCAR(int x, int y, bool dir) : CVEHICLE(x, y, dir)
{
	type = car;
}
void CTRUCK::Move(int x, int y)
{
	eraseVehicle();
	if (direction) {
		if (x >= screenSizePlay_L - 12)
		{
			eraseVehicle();
			mX = 2;
			mY = y;
			draw();

			return;
		}
	}
	else {
		if (x <= 2) {
			eraseVehicle();
			mX = screenSizePlay_L - 13;
			mY = y;
			draw();

			return;
		}
	}
	mX = x;
	mY = y;
	draw();

}

/*
	   _________ 
	  | |_| |_| |_
	  |_ o___o ___|
	     _________ 
	   _| |_| |_| |
	  |___ o___o _|
 */

void CTRUCK::draw()
{
	int x = mX;
	int y = mY;
	if (direction) {
		gotoXY(x, y);
		cout << " _________ ";
		gotoXY(x, y + 1);
		cout << "| |_| |_| |_";
		gotoXY(x, y + 2);
		cout << "|_ o___o ___|";
	}
	else {
		gotoXY(x, y);
		cout << "   _________";
		gotoXY(x, y + 1);
		cout << " _| |_| |_| |";
		gotoXY(x, y + 2);
		cout << "|___ o___o _|";
	}
}

CTRUCK::CTRUCK() : CVEHICLE()
{
	type = truck;
}

CTRUCK::CTRUCK(int x, int y, bool dir) : CVEHICLE(x, y, dir)
{
	type = truck;
}

void CVEHICLE::eraseVehicle()
{
	int x = mX;
	int y = mY;
	gotoXY(x, y);
	cout << "            ";
	gotoXY(x, y + 1);
	cout << "             ";
	gotoXY(x, y + 2);
	cout << "              ";

}

void CVEHICLE::setdata(int x, int y, bool d)
{
	mX = x;
	mY = y;
	direction = d;
}
