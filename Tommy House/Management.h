#pragma once

#include "MainClassMenu.h"
#include "Player.h"

using namespace sf;

class Management : public MainClassMenu
{
	myText Up;
	myText Down;
	myText Left;
	myText Right;
	myText Equip;
	myText back;
	myText Use;
	Image menu; 
	Texture Menu_t;
	Sprite menu_s;
public:
	Management();
	Management(String file_font, String file_image);
	void set(String file_font, String file_image);
	void update(RenderWindow &a, Player &b, int &button);
	void draw(RenderWindow &a);
};