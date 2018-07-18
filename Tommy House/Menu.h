#pragma once

#include <SFML/Audio.hpp>
#include "Creator.h"
#include "Option.h"
#include "MainClassMenu.h"
#include "StartGame(menu).h"

using namespace sf;

enum Menu_Buttons
{
	No = 0,
	Start_Game,
	Options,
	Creator
};

class Menu : public MainClassMenu
{
	Player player;
	Player Granny;
	Option_class Option__o;
	Image MenuImage;
	Texture MenuTexture;
	int button = No;
	float time = 0;
	Music music;
	Creator_ creat;
	Sprite MenuSprite;
	myText startGame;
	myText Option;
	myText Exit;
	myText Creators;
	Vector2u size;
	StartGame startGameMenu;
	void Creator_(RenderWindow &a);
public:
	Menu(String image, String Font, String musicFile, String Creator_Image, String sprite_image);
	void set(String image, String Font, String musicFile, String Creator_Image, String sprite_image);
	void update(RenderWindow &a, float time1);
	void draw(RenderWindow &a);
};