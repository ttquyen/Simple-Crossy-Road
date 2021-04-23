// basic console functions, collected by Nguyen Trung Thanh
// abcxyz tcIT

#ifndef _console_header
#define _console_header



#define Theme1_Black			224
#define Theme1_Red				236
#define Theme1_Highlight		14
#define Theme1_Green			226

#define Theme2_Black			14
#define Theme2_Red				12
#define Theme2_Highlight		224
#define Theme2_Green			10


#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


#define key_Up		72
#define key_Down	80
#define key_Left	75
#define key_Right	77
#define key_none	-1
#define key_Enter   13
#define key_Esc     27
#define key_Space   32

//--------------------------------------------------------

#include "Library.h"
//--------------------------------------------------------

int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY(int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor(int color);
//end----------------------Screen----------------------end


void clearScn();

//void DrawFrame(Point positionToDraw, int length, int height, char text[]);
void FixConsoleWindow();
void resizeConsole(int width, int height);
void setFontSize(int FontSize);
#endif

