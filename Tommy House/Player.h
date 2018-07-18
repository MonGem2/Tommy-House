#pragma once

#include <string>
#include "Map.h"
#include "Text.h"

using namespace sf;

class Player
{
	float speed;
	float x;
	float y;
	int stage;
	float animation_time = 0;
	float tempTime = 0;
	int  w;
	int h;
	int tempStage = 0;
	bool plyerFaktor = false;
	bool playerPositionFakto = false;
	Texture texture;
	String file;
	Image image;
	Sprite sprite;
	myText textxp;
	Vector2u tempPositionFromAuto;
	Keyboard::Key up = Keyboard::Up;
	Keyboard::Key down = Keyboard::Down;
	Keyboard::Key left = Keyboard::Left;
	Keyboard::Key right = Keyboard::Right;
	Keyboard::Key Die = Keyboard::Space;
public:
	bool getFakor()
	{
		return plyerFaktor;
	}
	bool getPlayerPositionFaktor()
	{
		return playerPositionFakto;
	}
	void setFaktor(bool a)
	{
		plyerFaktor = a;
	}
	
	Vector2u goToPoint(int x, int y, int stage, map &Map);
	void setTextureRect(float &time, int dir1);
	Player();
	Player(String F, float W, float H, String font, int textsize, Color color, float stage_, float speed, int X = 999, int Y = 999);
	void set(String F, float W, float H, String font, int textsize, Color color, float stage_, float speed, int X = 999, int Y = 999);
	void update(float time, map &Map, float speed);
	void set_management(Keyboard::Key up1, Keyboard::Key down1, Keyboard::Key left1, Keyboard::Key right1);
	void mask_kolor(int r, int g, int b);
	void drav_window(RenderWindow &window);
	float get_x();
	float get_y();
	void map_update(map &Map, float dx, float dy, float x_, float y_);
	void setPosition(int x, int y);
	float get_w();
	float get_h();
	float get_textSize();
	bool isGrannyWithPlayer(int X, int Y, int W, int H, int zone);
	int get_stage();
	//void update_autoGranny(float time, map &Map, Player &player, float speed);
};