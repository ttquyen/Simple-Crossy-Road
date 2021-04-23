#pragma once
#ifndef CGAME_H
#define CGAME_H
//#include "Library.h"
#include <time.h>
#include <vector>
#include <Windows.h>
#include <thread>
#include "CPeople.h"
#include "CAnimal.h"
#include "CVehicle.h"
#include "CGraphics.h"
using namespace std;
#define MAX_CAR 10
#define MAX_SPEED 5
#define MAX_CAR_LENGTH 60
#define WIDTH_CONSOLE 100
#define HEIGH_CONSOLE 20

// true : yellow - default
// false: green
extern bool theme;
const int lane[7] = { 1,5,9,13,17,21,25 };

class CGAME {

	bool pause;	//state of game: do stop?
	int speed;
	CPEOPLE* cn;
	vector<CVEHICLE*> veh;
	vector<CANIMAL*> ani;
public:
	CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	//void drawBoard(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	~CGAME(); // Hủy tài nguyên đã cấp phát
	CPEOPLE* getPeople();//Lấy thông tin người
	vector<CVEHICLE*>& getVehicle();//Lấy danh sách các xe
	vector <CANIMAL*>& getAnimal(); //Lấy danh sách các thú
	void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE); // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void pauseGame(HANDLE); // Tạm dừng Thread
	void resumeGame(HANDLE); //Quay lai Thread
	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();//Thực hiện cho CDINOSAUR & CBIRD di chuyển
	bool getPause();
	void setPause(bool x);
	void addMore(CANIMAL* x);
	bool saveGame(string);
	bool loadGame(string);
	void instruction();
	void insBoard();
};

#endif