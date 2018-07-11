#pragma once

#include <string>
#include "Map.h"
#include "Text.h"

using namespace sf;

class Player
{
	float dx = 0;
	float dy = 0;
	float x;
	float y;
	float animation_time = 0;
	int  w;
	int h;
	map Map;
	Texture texture;
	String file;
	Image image;
	Sprite sprite;
	myText textxp;
	Keyboard::Key up = Keyboard::Up;
	Keyboard::Key down = Keyboard::Down;
	Keyboard::Key left = Keyboard::Left;
	Keyboard::Key right = Keyboard::Right;
	Keyboard::Key Die = Keyboard::Space;
public:
	float speed = 0;
	void setTextureRect(float &time, int dir1);
	Player();
	Player(String F, int X, int Y, float W, float H, String font, int textsize, Color color);
	void set(String F, int X, int Y, float W, float H, String font, int textsize, Color color);
	void update(float time);
	void set_management(Keyboard::Key up1, Keyboard::Key down1, Keyboard::Key left1, Keyboard::Key right1);
	void mask_kolor(int r, int g, int b);
	void drav_window(RenderWindow &window); 
	float get_x();
	float get_y();
	void map();
};