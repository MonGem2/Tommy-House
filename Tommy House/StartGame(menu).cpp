#include "StartGame(menu).h"

	void StartGame::set(String font, String images)
	{
		this->font = font;
		image.loadFromFile(images);
		T.loadFromImage(image);
		menu.setTexture(T);
		back.set(font, "Back", 25, Color(60, 5, 8));
		Continie.set(font, "Continue", 25, Color::White);
		NewGame.set(font, "New Game", 25, Color::White);
		PlayFromGranny.set(font, "Play From Tommy", 25, Color::White);
		Clasical.set(font, "Clasical", 25, Color::White);
		easy.set(font, "Easy", 25, Color::White);
		hard.set(font, "Hard", 25, Color::White);
		extream.set(font, "Extream", 25, Color::White);
		medium.set(font, "Medium", 25, Color::White);
		Continie.set_position(20, 20);
		NewGame.set_position(150, 20);
		back.set_position(20, 50);
		PlayFromGranny.set_position(20, 20);
		Clasical.set_position(300, 20);
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
	void StartGame::update(RenderWindow &a, int &button, Player &player, float time)
	{
		if (buttons == PlayFromPlay)
		{
			GameFromPlayer.update(time, player, buttons, a);
		}

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
				button = 0;
				Sleep(200);
			}
			
			if (NewGame.Mous_in_text(a))
			{
				NewGame.setColor(Color::Black);
			}
			else
			{
				NewGame.setColor(Color::White);
			}

			if (NewGame.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				Sleep(200);
				buttons = resum;
			}
			if (Continie.Mous_in_text(a))
			{
				Continie.setColor(Color::Black);
			}
			else
			{
				Continie.setColor(Color::White);
			}
		}
		if (buttons == resum)
		{
			//std::cout << "hdghd" << std::endl;
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
				
				buttons = No1;
				Sleep(200);
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
				Sleep(200);
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
				Sleep(200);
				fromPlayer = true;
				buttons = els;
			}
		}
		if (buttons == els)
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
				buttons = resum;
				Sleep(200);
			}

			if (easy.Mous_in_text(a))
			{
				easy.setColor(Color::Black);
			}
			else
			{
				easy.setColor(Color::White);
			}
			if (easy.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				easy.setColor(Color::White);
				if (fromPlayer)
				{
					buttons = PlayFromPlay;
					GameFromPlayer.set(0, "Image/tommy.png", player, font);
				}
			}
			if (hard.Mous_in_text(a))
			{
				hard.setColor(Color::Black);

			}
			else
			{
				hard.setColor(Color::White);
			}
			if (hard.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				if (fromPlayer)
				{
					buttons = PlayFromPlay;
					GameFromPlayer.set(2, "Image/tommy.png", player, font);
				}
				hard.setColor(Color::Black);

			}

			if (extream.Mous_in_text(a))
			{
				extream.setColor(Color::Black);
			}
			else
			{
				extream.setColor(Color::White);
			}

			if (extream.Mous_in_text(a)&&Mouse::isButtonPressed(Mouse::Left))
			{
				if (fromPlayer)
				{
					buttons = PlayFromPlay;
					GameFromPlayer.set(3, "Image/tommy.png", player, font);
				}
				extream.setColor(Color::Black);
			}
			if (medium.Mous_in_text(a))
			{
				medium.setColor(Color::Black);
			}
			else
			{
				medium.setColor(Color::White);
			}
			if (medium.Mous_in_text(a)&&Mouse::isButtonPressed(Mouse::Left))
			{
				if (fromPlayer)
				{
					buttons = PlayFromPlay;
					GameFromPlayer.set(3, "Image/tommy.png", player, font);
				}
				
				medium.setColor(Color::Black);
			}
		}

		//std::cout << buttons << std::endl;
	}
	void StartGame::draw(RenderWindow &a)
	{

		if (buttons == No1)
		{
			a.draw(menu);
			back.dispayText(a);
			Continie.dispayText(a);
			NewGame.dispayText(a);
		}
		if (buttons == resum)
		{
			a.draw(menu);
			back.dispayText(a);
			PlayFromGranny.dispayText(a);
			Clasical.dispayText(a);
		}
		if (buttons == els)
		{
			a.draw(menu);
			back.dispayText(a);
			easy.dispayText(a);
			hard.dispayText(a);
			extream.dispayText(a);
			medium.dispayText(a);
		}
		if (buttons == PlayFromPlay)
		{
			GameFromPlayer.draw(a);
		}

	}
