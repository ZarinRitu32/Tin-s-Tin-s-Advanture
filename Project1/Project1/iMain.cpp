#include<iostream>
using namespace std;
#include "iGraphics.h"
#include "bitmap_loader.h"

void drawInstruction1();
void drawInstruction2();
void drawUs();
void drawHomepage();
void drawMap();
void drawStartPage();
void drawStartPage2();
void drawLevel1();
void change1();
void drawLevel2();
void drawOver(); 
void drawScorePage();

int aus = 0;
int homePage = 1;
int startPage = 0;
int startPage2 = 0;
int level1 = 0;
int level2 = 0;
int over = 0;
int clear = 0;
int scorePage = 0;
int i1 = 0, i2 = 0,h=0;

int axixx = 0;
int axixy = 0;
int index = 0, rindex = 0;
int check1 = 0, check2 = 0, bh = 100, bw = 100, sx = 0, sy = 130, cx = 0, cy = 0;
int life = 3;
int c1x = 850;
int c1y = 50;
int c2x = 250;
int c2y = 250;
int c3x = 150;
int c3y = 450;
int c4x = 650;
int c4y = 450;
int c5x = 850;
int c5y = 450;
int tp1x = 1100;
int tp1y = 700;
int tp2x = 1100;
int tp2y = 700;
int tp3x = 1100;
int tp3y = 700;
int tp4x = 1100;
int tp4y = 700;
int tp5x = 1100;
int tp5y = 700;
int trapState = 0;
int trapTimer = 0;
int food = 0;
int ck1 = 0, ck2 = 0, ck3 = 0, ck4 = 0, ck5 = 0;
int rendx = 0;
int sindex = 0;
int p;

bool swimPosition = true;
bool standPosition = true;
bool musicOn = false;


bool showing_page_of_scoring = false;
int cnt_take_name = 0;
bool play_ground = false;
char str1[40];
bool take_name = false;
int len = 0;
void showChar()
{
	iSetColor(255, 255, 0);
	iText(240, 400, "Enter your name", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(240, 350, 220, 30);
	iText(260, 360, str1, GLUT_BITMAP_HELVETICA_18);

}
typedef struct Player Player;

struct Player{
	char name[30];
	int score = 0;
	Player()
	{
		;
	}
	
};
typedef struct sorting
{
	char ch[30];
	int sc;
} sorts;

void sort_stru(sorting o1[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (o1[i].sc < o1[j].sc)
			{
				sorting temp = o1[i];
				o1[i] = o1[j];
				o1[j] = temp;
			}
		}
	}
}
Player o1;
void high_page_sorting(){
	FILE *fp = fopen("high_score.txt", "a");
	fprintf(fp, "%s %d\n", o1.name, o1.score);
	fclose(fp);
}
void showing_score_page(){
	int z;
	FILE *fp = fopen("high_score.txt", "r");
	char chs[30];
	int cnt = 0;
	while (fscanf(fp, "%s%d", &chs, &z) != EOF)
	{
		cnt++;
	}
	sorts o2[100];
	fclose(fp);
	fp = fopen("high_score.txt", "r");
	for (int i = 0; i < cnt; i++)
	{
  		fscanf(fp, "%s%d", &chs, &z);
		strcpy(o2[i].ch, chs);
		o2[i].sc = z;
	}
	fclose(fp);
	fp = fopen("high_score.txt", "r");
	sort_stru(o2, cnt);
	int x = cnt;
	if (cnt>7){
		x = 7;
	}
	for (int i = 0; i <x; i++)
	{
		char name[2][30];
		fprintf(fp, "%s %d\n", o2[i].ch, o2[i].sc);
		sprintf(name[0], "%s", o2[i].ch);
		sprintf(name[1], "%d", o2[i].sc);
		iSetColor(255, 255, 0);
		iText(700, 550 - 50 * i, name[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900, 550 - 50 * i, name[1], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	fclose(fp);
}
char point[1000];
void showing_score(){

	iShowBMP2(975, 720, "bci\\scoring.bmp", 0);
	iShowBMP2(1000, 745, "bci\\s1.bmp", 0);
	iSetColor(0, 0, 0);
	iText(1125, 755, ":", GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf_s(point, "%d", o1.score);
	iText(1142, 755, point, GLUT_BITMAP_TIMES_ROMAN_24);
}




void iDraw()
{
	iClear();
	if (homePage == 1)
	{
		drawHomepage();
	}
	

	if (startPage == 1)
	{
		drawStartPage();
		homePage = 0;
	}
	if (level1 == 1)
	{
		drawLevel1();
		startPage = 0;
	}
	if (startPage2 == 1)
	{
		drawStartPage2();
		level1 = 0;

	}
	if (level2 == 1)
	{
		drawLevel2();
		startPage2 = 0;
	}
	if (over == 1)
	{
		drawOver();
		level2 = 0;
		level1 = 0;
	}

	if (showing_page_of_scoring){
		cout << "--------" << endl;
		showChar();
		showing_score_page();
	}
	if (scorePage == 1)
	{
		drawScorePage();
		showing_score_page();
	}
	if (aus == 1)
	{
		homePage = 0;
		drawUs();
	}
	if (i1 == 1)
	{
		drawInstruction1();
		homePage == 0;
	}
	if (i2 == 1)
	{
		drawInstruction2();
		i1 = 0;
	}
	

}

void iMouseMove(int mx, int my)
{
}

void iPassiveMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d y=%d ", mx, my);
		if (homePage == 1 && (mx >= 581 && mx <= 797) && (my >= 401 && my <= 451))
		{
			homePage = 0;
			startPage = 1;
		}
		if (axixx >= 900 && axixy >= 500 && axixy <= 600)
		{
			startPage2 = 1;
			level1 = 0;
		}
		if (startPage == 1 && (mx >= 399 && mx <= 617) && (my >= 302 && my <= 349))
		{
			startPage = 0;
			level1 = 1;
		}
		if (startPage2 == 1 && (mx >= 399 && mx <= 617) && (my >= 302 && my <= 349))
		{
			startPage2 = 0;
			level2 = 1;
		}
		if (over == 1 && (mx >= 400 && mx <= 620) && (my >= 200 && my <= 250))
		{
			
			over = 0;
			homePage = 1;
			level2 = 0;
			level1 = 0;
		}
		
		if (homePage == 1 && (mx >= 580 && mx <= 800) && (my >= 200 && my <= 250))
		{
			scorePage = 1;
			homePage = 0;
		}
		if (homePage == 1 && (mx >= 580 && mx <= 800) && (my >= 100 && my <= 150))
		{
			aus = 1;
			homePage = 0;
		}
		if (homePage == 1 && (mx >= 580 && mx <= 800) && (my >= 300 && my <= 350))
		{
			i1 = 1;
			homePage = 0;
		}
		if (i1 == 1 && (mx >= 580 && mx <= 800) && (my >= 100 && my <= 150))
		{
			i2 = 1;
			i1 = 0;
		}
	

		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}
void takeinput(unsigned char key){
	if (key == 'p'){
		exit(0);
	}
	if (key == '\r'){
		strcpy(o1.name, str1);
		o1.score = food;
		high_page_sorting();
		showing_page_of_scoring = false;
		over = 0;
		homePage = 1;
	}
	else if (key == '\b'){
		if (len <= 0){
			len = 0;
		}
		else
			len--;
		str1[len] = '\0';
	}
	else{
		str1[len] = key;
		len++;
		if (len > 15){
			len = 15;
		}str1[len] = '\0';
	}
}
void iKeyboard(unsigned char key)

{
	if (showing_page_of_scoring && (over==1 || clear==1)){
		takeinput(key);
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT && level1 == 1)
	{
		standPosition = false;
		check1 = axixx;
		axixx += 10;
		index++;
		if (index >= 8)
			index = 0;
	}
	if (key == GLUT_KEY_LEFT && level1 == 1)
	{
		standPosition = false;
		check1 = axixx;
		axixx -= 10;
		index++;
		if (index >= 8)
			index = 0;
	}
	if (key == GLUT_KEY_UP && level1 == 1)
	{
		check2 = axixy;
		axixy += 10;
		index++;
		if (index >= 8)
			index = 0;
	}
	if (key == GLUT_KEY_DOWN && level1 == 1)
	{
		check2 = axixy;
		axixy -= 10;
		index++;
		if (index >= 8)
			index = 0;
	}
	if (key == GLUT_KEY_RIGHT && level2 == 1)
	{
		swimPosition = false;
		cx = sx;
		sx += 10;
		sindex++;
		if (sindex >= 5)
			sindex = 0;
	}
	if (key == GLUT_KEY_LEFT && level2 == 1)
	{
		swimPosition = false;
		cx = sx;
		sx -= 10;
		sindex++;
		if (sindex >= 5)
			sindex = 0;
	}
	if (key == GLUT_KEY_UP && level2 == 1)
	{
		cy = sy;
		sy += 10;
		sindex++;
		if (sindex >= 5)
			sindex = 0;
	}
	if (key == GLUT_KEY_DOWN && level2 == 1)
	{
		cy = sy;
		sy -= 10;
		sindex++;
		if (sindex >= 5)
			sindex = 0;
	}
	if (key == GLUT_KEY_F1)
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("hs.wav", NULL, SND_LOOP | SND_ASYNC);
		}



	}
}

void drawHomepage()
{
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "image\\hom.bmp", 0);

	iShowBMP2(580, 400, "image\\button.bmp", 0);
	iShowBMP2(580, 300, "image\\button.bmp", 0);
	iShowBMP2(580, 200, "image\\button.bmp", 0);
	iShowBMP2(580, 100, "image\\button.bmp", 0);

	iSetColor(0, 0, 0);
	iText(560, 520, "TinTin's   ADVENTURE", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640, 420, "START", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 320, "INSTRUCTIONS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640, 220, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(620, 120, "ABOUT US", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawUs()
{
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "image\\us.bmp", 0);
}

void drawStartPage()
{
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "image\\level1.bmp", 0);
	iShowBMP2(400, 300, "image\\button.bmp", 0);
	iText(460, 320, "Level 1", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawInstruction1()
{
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "image\\il1.bmp", 0);
	iShowBMP2(580, 100, "image\\button.bmp", 0);
	iText(600, 120, "Next", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawInstruction2()
{
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "image\\il2.bmp", 0);
}



void change1()
{
	if (over == 1){
		cnt_take_name ++;
	}
	if (cnt_take_name >= 3){
		cnt_take_name = 0;
		showing_page_of_scoring = true;
	}
	if (trapState == 1)
	{
		tp1x = 400;
		tp1y = 100;
		tp2x = 100;
		tp2y = 300;
		tp3x = 300;
		tp3y = 400;
		tp4x = 700;
		tp4y = 200;
		tp5x = 100;
		tp5y = 0;
	}
	if (trapState == 0)
	{
		tp1x = 1100;
		tp1y = 700;
		tp2x = 1100;
		tp2y = 700;
		tp3x = 1100;
		tp3y = 700;
		tp4x = 1100;
		tp4y = 700;
		tp5x = 1100;
		tp5y = 700;

	}
}

void drawLevel1()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "image\\lvl1b.bmp", 0);

	if (trapState == 1)
	{
		iShowBMP2(tp1x, tp1y, "image\\trap.bmp", 0);
		iShowBMP2(tp2x, tp2y, "image\\trap.bmp", 0);
		iShowBMP2(tp3x, tp3y, "image\\trap.bmp", 0);
		iShowBMP2(tp4x, tp4y, "image\\trap.bmp", 0);
		iShowBMP2(tp5x, tp5y, "image\\trap.bmp", 0);
		trapTimer++;

		if (trapTimer >= 40)
		{
			trapState = 0;
			trapTimer = 0;
		}

		change1();
	}
	if (trapState == 0)
	{
		iShowBMP2(tp1x, tp1y, "image\\trap.bmp", 0);
		iShowBMP2(tp2x, tp2y, "image\\trap.bmp", 0);
		iShowBMP2(tp3x, tp3y, "image\\trap.bmp", 0);
		iShowBMP2(tp4x, tp4y, "image\\trap.bmp", 0);
		iShowBMP2(tp5x, tp5y, "image\\trap.bmp", 0);

		trapTimer++;

		if (trapTimer >= 40)
		{
			trapState = 1;
			trapTimer = 0;
		}

		change1();
	}


	if (axixx == 850 && axixy == 50 && ck1 == 0)
	{
		food+50;
		c1x = 1100;
		c1y = 700;
		ck1 = 1;
	}
	if (axixx == 250 && axixy == 250 && ck2 == 0)
	{
		food+=50;
		c2x = 1100;
		c2y = 700;
		ck2 = 1;
	}
	if (axixx == 150 && axixy == 450 && ck3 == 0)
	{
		food+=50;
		c3x = 1100;
		c3y = 700;
		ck3 = 1;
	}
	if (axixx == 650 && axixy == 450 && ck4 == 0)
	{
		food+=50;
		c4x = 1100;
		c4y = 700;
		ck4 = 1;
	}
	if (axixx == 850 && axixy == 450 && ck5 == 0)
	{
		food+=50;
		c5x = 1100;
		c5y = 700;
		ck5 = 1;
	}

	if (trapState == 1 && (axixx >= 400 && axixx <= 500) && (axixy >= 100 && axixy <= 200))
	{
		life--;
		if (axixy <= 150)
			axixy = 0;
		if (axixy > 150)
			axixy = 220;
	}

	if (trapState == 1 && (axixx >= 100 && axixx <= 200) && (axixy >= 300 && axixy <= 400))
	{
		life--;
		if (axixy <= 350)
			axixy = 220;
		if (axixy > 350)
			axixy = 420;
	}

	if (trapState == 1 && (axixx >= 300 && axixx <= 400) && (axixy >= 400 && axixy <= 500))
	{
		life--;
		if (axixx <= 350)
			axixx = 250;
		if (axixx > 350)
			axixx = 420;

	}
	if (trapState == 1 && (axixx >= 700 && axixx <= 800) && (axixy >= 200 && axixy <= 300))
	{
		life--;
		if (axixx <= 750)
			axixx = 600;
		if (axixx > 750)
			axixx = 800;

	}
	if (trapState == 1 && (axixx >= 100 && axixx <= 200) && (axixy >= 0 && axixy <= 100))
	{
		life--;
		if (axixx <= 150)
			axixx = 0;
		if (axixx > 150)
			axixx = 250;
		
	}

	if (life == 0)
	{
		over = 1;
		level1 = 0;
		level2 = 0;

		
	}


	if ((axixx >= 900 && axixx <= 1000) && (axixy >= 500 && axixy <= 600))
		startPage2 = 1;


	if (axixy < 0) axixy = 0;
	if ((axixy >= 0 && axixy <= 100) && (axixx == 900))
		axixx = 880;
	if ((axixy >= 100 && axixy <= 200) && (axixx == 400))
		axixx = 420;
	if ((axixy >= 100 && axixy <= 200) && (axixx == 500))
		axixx = 460;
	if (axixy == 100 && (axixx <= 400 || axixx >= 500))
		axixy = 80;
	if ((axixy >= 200 && axixy <= 300) && axixx == 100)
		axixx = 120;
	if ((axixy >= 200 && axixy <= 300) && axixx == 500)
		axixx = 480;
	if ((axixy >= 200 && axixy <= 300) && axixx == 600)
		axixx = 620;
	if ((axixy >= 200 && axixy <= 300) && axixx == 900)
		axixx = 880;
	if (axixy == 200 && (axixx <= 400 || axixx >= 500))
		axixy = 220;
	if (axixy == 300 && (axixx >= 200 && axixx <= 500))
		axixy = 280;
	if (axixy == 300 && (axixx >= 700 && axixx <= 800))
		axixy = 280;
	if ((axixy >= 300 && axixy <= 400) && axixx == 100)
		axixx = 120;
	if ((axixy >= 300 && axixy <= 400) && axixx == 200)
		axixx = 180;
	if ((axixy >= 300 && axixy <= 400) && axixx == 600)
		axixx = 620;
	if ((axixy >= 300 && axixy <= 400) && axixx == 700)
		axixx = 680;
	if ((axixy >= 300 && axixy <= 400) && axixx == 800)
		axixx = 820;
	if ((axixy >= 300 && axixy <= 400) && axixx == 900)
		axixx = 880;
	if (axixy == 400 && (axixx >= 200 && axixx <= 600))
		axixy = 420;
	if (axixy == 500 && (axixx >= 100 && axixx <= 700))
		axixy = 480;
	if (axixy == 500 && (axixx >= 900 && axixx <= 1000))
		axixy = 520;
	if ((axixy >= 400 && axixy <= 500) && axixx == 100)
		axixx = 120;
	if ((axixy >= 400 && axixy <= 500) && axixx == 700)
		axixx = 680;
	if ((axixy >= 400 && axixy <= 500) && axixx == 800)
		axixx = 820;
	if ((axixy >= 400 && axixy <= 500) && axixx == 900)
		axixx = 880;
	if ((axixy >= 500 && axixy <= 600) && axixx == 800)
		axixx = 820;
	if (axixy > 600) axixy = 560;



	iShowBMP2(0, 500, "image\\block.bmp", 0);
	iShowBMP2(100, 500, "image\\block.bmp", 0);
	iShowBMP2(200, 500, "image\\block.bmp", 0);
	iShowBMP2(300, 500, "image\\block.bmp", 0);
	iShowBMP2(400, 500, "image\\block.bmp", 0);
	iShowBMP2(500, 500, "image\\block.bmp", 0);
	iShowBMP2(600, 500, "image\\block.bmp", 0);
	iShowBMP2(700, 500, "image\\block.bmp", 0);
	iShowBMP2(0, 400, "image\\block.bmp", 0);
	iShowBMP2(700, 400, "image\\block.bmp", 0);
	iShowBMP2(900, 400, "image\\block.bmp", 0);
	iShowBMP2(0, 300, "image\\block.bmp", 0);
	iShowBMP2(200, 300, "image\\block.bmp", 0);
	iShowBMP2(300, 300, "image\\block.bmp", 0);
	iShowBMP2(400, 300, "image\\block.bmp", 0);
	iShowBMP2(500, 300, "image\\block.bmp", 0);
	iShowBMP2(700, 300, "image\\block.bmp", 0);
	iShowBMP2(900, 300, "image\\block.bmp", 0);
	iShowBMP2(0, 200, "image\\block.bmp", 0);
	iShowBMP2(500, 200, "image\\block.bmp", 0);
	iShowBMP2(900, 200, "image\\block.bmp", 0);
	iShowBMP2(0, 100, "image\\block.bmp", 0);
	iShowBMP2(100, 100, "image\\block.bmp", 0);
	iShowBMP2(200, 100, "image\\block.bmp", 0);
	iShowBMP2(300, 100, "image\\block.bmp", 0);
	iShowBMP2(500, 100, "image\\block.bmp", 0);
	iShowBMP2(600, 100, "image\\block.bmp", 0);
	iShowBMP2(700, 100, "image\\block.bmp", 0);
	iShowBMP2(800, 100, "image\\block.bmp", 0);
	iShowBMP2(900, 100, "image\\block.bmp", 0);
	iShowBMP2(900, 0, "image\\block.bmp", 0);
	iShowBMP2(c1x, c1y, "image\\cken.bmp", 0);
	iShowBMP2(c2x, c2y, "image\\cken.bmp", 0);
	iShowBMP2(c3x, c3y, "image\\cken.bmp", 0);
	iShowBMP2(c4x, c4y, "image\\cken.bmp", 0);
	iShowBMP2(c5x, c5y, "image\\cken.bmp", 0);

	char run[8][16] = { "char\\t1.bmp", "char\\t2.bmp", "char\\t3.bmp", "char\\t4.bmp", "char\\t5.bmp", "char\\t6.bmp", "char\\t7.bmp", "char\\t8.bmp" };
	char rrun[8][16] = { "char\\rt1.bmp", "char\\rt2.bmp", "char\\rt3.bmp", "char\\rt4.bmp", "char\\rt5.bmp", "char\\rt6.bmp", "char\\rt7.bmp", "char\\rt8.bmp" };


	if (!standPosition)
	{
		if (check1 < axixx)
			iShowBMP2(axixx, axixy, run[index], 0);
		else if (check1 > axixx)
			iShowBMP2(axixx, axixy, rrun[index], 0);
		else if (check2 != axixy)
			iShowBMP2(axixx, axixy, run[index], 0);
	}
	else
	{
		iShowBMP2(axixx, axixy, run[0], 0);
	}


}

void drawStartPage2()
{
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "image\\lvl2.bmp", 0);
	iShowBMP2(400, 300, "image\\button.bmp", 0);
	iText(460, 320, "Level 2", GLUT_BITMAP_TIMES_ROMAN_24);
}
float p1 = 0, cpx = 900, cpy = 380;
int dis=0;



void drawLevel2()
{

	iFilledRectangle(0, 0, 1000, 600);
	iShowImage(p1, 0, 1000, 600, p);
	iShowImage(p1 + 1000, 0, 1000, 600, p);
	p1 -= 0.4;
	if (p1 <-1000)
		p1 = 0;
	iShowBMP2(cpx, cpy, "image\\crock.bmp", 0);
	char swim[8][16] = { "char\\s1.bmp", "char\\s2.bmp", "char\\s3.bmp", "char\\s4.bmp", "char\\s5.bmp" };
	
	if (!swimPosition)
	{
		if (cx < sx)
			iShowBMP2(sx, sy, swim[sindex], 0);
		else if (cy != sy)
			iShowBMP2(sx, sy, swim[sindex], 0);
	}
	else
	{
		iShowBMP2(sx, sy, swim[0], 0);
	}
	if (sy <= 120) sy = 130;
	if (sy >= 440) sy = 420;

	cpx -= 1;
	if (cpx == 0)
	{
		
		food+=25;
		cpx = 1000;
		int ty = 0 + rand() % 250;
		if (ty >= 120 && ty <= 440)
			cpy = ty;
		else
			cpy = 380;
	}
	if (sy + 30 >= cpy + 20 && sy + 30 <= cpy + 80 && sx >= cpx && sx <= cpx + 20)
	{
		sx = 0;
		sy = cpy + 50;
		life--;
	}
	if (life == 0)
	{
		over = 1;
		level2 = 0;
		
	}


}

void drawScorePage()
{
	iSetColor(255,255 , 255);
	iFilledRectangle(0, 0, 1000, 600);
}

void drawOver()
{
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 1000, 600);
	iText(320, 220, "HOME", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 0);
	iText(450, 500, "Game Over", GLUT_BITMAP_TIMES_ROMAN_24);
}


int main()
{
	iSetTimer(1000, change1);
	
	if (musicOn)
	{
		PlaySound("music\\hs.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iInitialize(1000, 600, "Project Title");
	p = iLoadImage("./image/rend1.bmp");
	iStart();
	return 0;
}

