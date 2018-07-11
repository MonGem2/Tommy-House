#include "StartGame(menu).h"

	void StartGame::set(String font, String images)
	{

		image.loadFromFile(images);

		T.loadFromImage(image);
		menu.setTexture(T);
		back.set(font, "Back", 25, Color(60, 5, 8));
		Continie.set(font, "Continie", 25, Color::White);
		NewGame.set(font, "New Game", 25, Color::White);
		PlayFromGranny.set(font, "Play From Granny", 25, Color::White);
		Clasical.set(font, "Clasical", 25, Color::White);
		easy.set(font, "Easy", 25, Color::White);
		hard.set(font, "Hard", 25, Color::White);
		extream.set(font, "Extream", 25, Color::White);
		medium.set(font, "Medium", 25, Color::White);
		Continie.set_position(20, 20);
		NewGame.set_position(100, 20);
		back.set_position(20, 50);
		PlayFromGranny.set_position(20, 20);
		Clasical.set_position(100, 20);
		easy.set_position(20, 20);
		medium.set_position(100, 20);
		hard.set_position(200, 20);
		extream.set_position(300, 20);
	}
	StartGame::StartGame(String font, String images)
	{

		image.loadFromFile(images);

		T.loadFromImage(image);
		menu.setTexture(T);
		back.set(font, "Back", 25, Color(60, 5, 8));
		Continie.set(font, "Continie", 25, Color::White);
		NewGame.set(font, "New Game", 25, Color::White);
		PlayFromGranny.set(font, "Play From Granny", 25, Color::White);
		Clasical.set(font, "Clasical", 25, Color::White);
		easy.set(font, "Easy", 25, Color::White);
		hard.set(font, "Hard", 25, Color::White);
		extream.set(font, "Extream", 25, Color::White);
		medium.set(font, "Medium", 25, Color::White);
		Continie.set_position(20, 20);
		NewGame.set_position(100, 20);
		back.set_position(20, 50);
		PlayFromGranny.set_position(20, 20);
		Clasical.set_position(100, 20);
		easy.set_position(20, 20);
		medium.set_position(100, 20);
		hard.set_position(200, 20);
		extream.set_position(300, 20);
	}
	StartGame::StartGame()
	{

	}
	void StartGame::update(RenderWindow &a, int &button)
	{
		if (buttons == No1)
		{
			if (back.Mous_in_text(a))
			{
				back.setColor(Color::Black);
			}
			else
			{
				back.setColor(Color(60, 5, 8));
			}
			if (back.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				button = No1;
			}
			if (Continie.Mous_in_text(a))
			{
				Continie.setColor(Color::Black);
			}
			else
			{
				Continie.setColor(Color::White);
			}

			if (Continie.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				buttons = resum;
			}
			if (NewGame.Mous_in_text(a))
			{
				NewGame.setColor(Color::Black);
			}
			else
			{
				NewGame.setColor(Color::White);
			}
		}
		if (buttons == resum)
		{
			if (back.Mous_in_text(a))
			{
				back.setColor(Color::Black);
			}
			else
			{
				back.setColor(Color(60, 5, 8));
			}
			if (back.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				button = No1;
			}
			if (PlayFromGranny.Mous_in_text(a))
			{
				PlayFromGranny.setColor(Color::Black);
			}
			else
			{
				PlayFromGranny.setColor(Color::White);
			}

			if (PlayFromGranny.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				buttons = els;
			}

			if (Clasical.Mous_in_text(a))
			{
				Clasical.setColor(Color::Black);
			}
			else
			{
				Clasical.setColor(Color::White);
			}
			if (Clasical.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				buttons = els;
			}
		}
	}
