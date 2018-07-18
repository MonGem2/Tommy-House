#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include <Windows.h>
#include "MainClassMenu.h"
#include "StartGame.h"
using namespace sf;

enum button_gameSrart
{
	No1 = 0, resum, els, PlayFromPlay

};

class StartGame : public MainClassMenu
{
	String font;
	bool fromPlayer=true;
	StartNewGame GameFromPlayer;
	Image image;
	Texture T;
	myText back;
	myText Continie;
	myText NewGame;
	myText PlayFromGranny;
	myText Clasical;
	myText easy;
	myText hard;
	myText extream;
	myText medium;
	int buttons = No1;
	Sprite menu;
public:
	void set(String font, String images);
	StartGame(String font, String images);
	StartGame();
	void update(RenderWindow &a, int &button, Player &player, float time);
	void draw(RenderWindow &a);
};