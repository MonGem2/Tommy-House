#pragma once

#include<Windows.h>
#include "Text.h"
#include<SFML/Graphics.hpp>
#include <iostream>
#include"MainClassMenu.h"

using namespace sf;

class Creator_ :public MainClassMenu
{
	Image menu;
	Texture menu_t;
	Sprite menu_s;
	myText back;
public:
	Creator_();
	Creator_(String file_image, String font);
	void set(String file_image, String font);
	void update(RenderWindow &a, int &isop);
	void draw(RenderWindow &a);
};