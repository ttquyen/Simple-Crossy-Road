#pragma once
#ifndef CPEOPLE_H
#define CPEOPLE_H
#include "CGame.h"
#include "CAnimal.h"
#include "CVehicle.h"
using namespace std;
const int screenSizePlay_W = 32;
const int screenSizePlay_L = 80;

class CPEOPLE {
	int mX, mY;
	bool mState; 
	int level;
public:
	CPEOPLE();
	bool isImpact(const vector<CVEHICLE*>& vehicle);
	bool isImpact(const vector<CANIMAL*>& animal);
	bool isFinish();
	void increaseLevel();
	void drawPeople(int, int);
	bool isDead();
	void erasePeople(int, int);
	void changeState(bool);
	void move(int m);
	friend class CGAME;
	int getLevel();
};

void drawScreen();
#endif
