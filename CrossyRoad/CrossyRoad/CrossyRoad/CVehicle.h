#pragma once
#ifndef CVEHICLE_H
#define CVEHICLE_H
#include "Library.h"
const int car = 1;
const int truck = 0;
class CVEHICLE {
protected:
	int mX, mY;
	int type;
	bool direction;
public:
	virtual void Move(int, int) = 0;
	virtual void draw() = 0;
	friend class CPEOPLE;
	friend class CGAME;
	CVEHICLE();
	CVEHICLE(int x, int y, bool dir);
	bool getDirection();
	void eraseVehicle();
	void setdata(int x, int y, bool d);
};
class CTRUCK : public CVEHICLE {
public:
	void Move(int, int);
	void draw();
	CTRUCK();
	CTRUCK(int x, int y, bool dir);
};
class CCAR : public CVEHICLE {
public:
	void Move(int, int);
	void draw();
	CCAR();
	CCAR(int x, int y, bool dir);
};
#endif