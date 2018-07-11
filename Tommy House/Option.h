#pragma once

#include "Audio_option.h"
#include"about game.h"
#include <SFML/Audio.hpp>
#include "Management.h"

using namespace sf;

enum menu_op
{
	No_ = 0, management_, sound_, about_

};

class Option_class
{
	Audio_option Audio_op;
	myText management;
	myText sound;
	myText back, about;
	Image Menu;
	Texture menu_t;
	Sprite menu_s;
	Management management_o;
	about_game aboutGame;
	int button_ = No_;

public:
	Option_class(String file_f, String File_m);
	void set(String file_f, String File_m);
	Option_class();
	void update(int &button, RenderWindow &a, Player &player, Music &music);
	void draw(RenderWindow &a);
};