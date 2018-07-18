#include "Menu.h"

using namespace sf;

	Menu::Menu()
	{
	
	}
	void Menu::Creator_(RenderWindow &a)
	{
		creat.update(a, button);
	}
	Menu::Menu(String image, String Font, String musicFile, String Creator_Image, String sprite_image)
	{
		startGameMenu.set(Font, image);
		creat.set(Creator_Image, Font);

		player.set(sprite_image, 48, 65, Font, 24, Color::Black, map::getStagePlayer(), 10, map::spawnPlayer().x, map::spawnPlayer().y);

		music.openFromFile(musicFile);
		music.play();
		music.setLoop(true);
		MenuImage.loadFromFile(image);
		MenuTexture.loadFromImage(MenuImage);
		MenuSprite.setTexture(MenuTexture);
		startGame.set(Font, "START GAME", 25, Color::Color(60, 5, 8));
		Option.set(Font, "Option", 25, Color::White);
		Exit.set(Font, "Exit", 25, Color::White);
		Creators.set(Font, "Creators", 25, Color::White);
		size = MenuImage.getSize();
		startGame.set_position(20, 30);
		Option.set_position(20, 65);
		Creators.set_position(20, 100);
		Exit.set_position(20, 135);
		Option__o.set(Font, image);
	}
	void Menu::set(String image, String Font, String musicFile, String Creator_Image, String sprite_image)
	{
		startGameMenu.set(Font, image);
		creat.set(Creator_Image, Font);

		player.set(sprite_image, 48, 65, Font, 24, Color::Black, map::getStagePlayer(), 0.1, map::spawnPlayer().x, map::spawnPlayer().y);

		music.openFromFile(musicFile);
		music.play();
		music.setLoop(true);

		MenuImage.loadFromFile(image);
		MenuTexture.loadFromImage(MenuImage);
		MenuSprite.setTexture(MenuTexture);
		startGame.set(Font, "STARTING GAME", 25, Color::Color(60, 5, 8));
		Option.set(Font, "Option", 25, Color::White);
		Exit.set(Font, "Exit", 25, Color::White);
		Creators.set(Font, "Creators", 25, Color::White);
		size = MenuImage.getSize();
		startGame.set_position(20, 30);
		Option.set_position(20, 65);
		Creators.set_position(20, 100);
		Exit.set_position(20, 135);
		Option__o.set(Font, image);
	}
	void Menu::update(RenderWindow &a, float time1)
	{
		if (button == No)
		{
			if (startGame.Mous_in_text(a))
			{
				startGame.setColor(Color::Black);
			}
			else
			{
				startGame.setColor(Color::Color(60, 5, 8));
			}
			if (startGame.Mous_in_text(a)&&Mouse::isButtonPressed(Mouse::Left))
			{
				button = Start_Game;
				Sleep(200);
			}


			if (Option.Mous_in_text(a))
			{
				Option.setColor(Color::Black);
			}
			else
			{
				Option.setColor(Color::White);
			}

			if (Creators.Mous_in_text(a))
			{
				Creators.setColor(Color::Black);
			}
			else
			{
				Creators.setColor(Color::White);
			}

			if (Exit.Mous_in_text(a))
			{
				Exit.setColor(Color::Black);
			}
			else
			{
				Exit.setColor(Color::White);
			}

			if (Option.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				Sleep(200);

				button = Options;
			}

			if (Creators.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				Sleep(200);
				button = Creator;
			}

			if (Exit.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				a.close();
			}
		}
		if (button == Start_Game)
		{
			startGameMenu.update(a, button, player, time1);

		}
		if (button == Creator)
		{
			Creator_(a);
		}
		if (button == Options)
		{
			Option__o.update(button, a, player, music);
		}


	}
	void Menu::draw(RenderWindow &a)
	{
		if (button == No)
		{
			a.draw(MenuSprite);
			startGame.dispayText(a);
			Option.dispayText(a);
			Creators.dispayText(a);
			Exit.dispayText(a);
		}
		if (button == Creator)
		{
			creat.draw(a);
		}
		if (button == Options)
		{

			Option__o.draw(a);
		}
		if (button == Start_Game)
		{
			startGameMenu.draw(a);
		}
	}