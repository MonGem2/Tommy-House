#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Player.h"
#include<Windows.h>
#include"MainClassMenu.h"

using namespace sf;

enum button_gameSrart
{
	No1 = 0, resum, els

};

class StartGame :public MainClassMenu
{
	Image image;
	Texture T;
	myText back;
	myText Continie, NewGame, PlayFromGranny, Clasical, easy, hard, extream, medium;
	int buttons = No1;
	Sprite menu;
public:
	void set(String font, String images);
	StartGame(String font, String images);
	StartGame();
	void update(RenderWindow &a, int &button);
};