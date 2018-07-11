#pragma once

#include "Text.h"
#include "mainClassMenu.h"

using namespace sf;

class about_game : public MainClassMenu
{
	Image menu;
	Texture menu_t;
	Sprite menu_s;
	myText back;
public:
	about_game();
	about_game(String file_f, String file_i);
	void set(String file_f, String file_i);
	void update(RenderWindow &a, int &button);
	void draw(RenderWindow &a);
};