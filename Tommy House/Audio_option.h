#pragma once

#include "Text.h"
#include "Sound.h"
#include <Windows.h>
#include <SFML/Audio.hpp>
#include "MainClassMenu.h"

using namespace sf;

class Audio_option : public MainClassMenu
{
	myText on_music, of_music, back, on, of;
	Image menu;
	Texture menu_t;
	Sprite menu_s;
	Sounds Muse;
public:
	Audio_option();
	Audio_option(String file_f, String file_i);
	void set(String file_f, String file_i);
	void update(Music &music, int &button, RenderWindow &a);
	void draw(RenderWindow &a);
};