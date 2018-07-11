#pragma once

#include "MainClassMenu.h"
#include "Player.h"

using namespace sf;

class Management : public MainClassMenu
{
	myText Up, Down, Left, Right, Die, back;
	Image menu; Texture Menu_t; Sprite menu_s;
public:
	Management();
	Management(String file_font, String file_image);
	void set(String file_font, String file_image);
	void update(RenderWindow &a, Player &b, int &button);
	void draw(RenderWindow &a);
};