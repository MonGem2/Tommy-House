#include "Option.h"

Option_class::Option_class(String file_f, String File_m)
	{
		Audio_op.set(file_f, File_m);
		management_o.set(file_f, File_m);
		Menu.loadFromFile(File_m);
		menu_t.loadFromImage(Menu);
		menu_s.setTexture(menu_t);
		about.set(file_f, "About", 25, Color::White);
		management.set(file_f, "Management", 25, Color::White);
		sound.set(file_f, "Sound", 25, Color::White);
		back.set(file_f, "Back", 25, Color::White);
		management.set_position(20, 30);
		sound.set_position(20, 30 + 25 + 5);
		about.set_position(20, 90);
		back.set_position(20, 120);

		aboutGame.set(file_f, "Image/about game.jpg");

	}
void Option_class::set(String file_f, String File_m)
	{
		Audio_op.set(file_f, File_m);


		management_o.set(file_f, File_m);
		about.set(file_f, "About", 25, Color::White);
		Menu.loadFromFile(File_m);
		menu_t.loadFromImage(Menu);
		menu_s.setTexture(menu_t);
		management.set(file_f, "Management", 25, Color(Color(60, 5, 8)));
		sound.set(file_f, "Sound", 25, Color(Color(60, 5, 8)));
		back.set(file_f, "Back", 25, Color(Color(60, 5, 8)));
		management.set_position(20, 30);
		sound.set_position(20, 30 + 25 + 5);
		about.set_position(20, 90);
		back.set_position(20, 120);
		aboutGame.set(file_f, "Image/about game.jpg");
	}
Option_class::Option_class()
	{

	}
void Option_class::update(int &button, RenderWindow &a, Player &player, Music &music)
	{
		if (button_ == No_)
		{
			//management.set(file_f, "Management", 25, Color::White);
			//sound.set(file_f, "Sound", 25, Color::White);
			//back.set(file_f, "Back", 25, Color::White);
			if (back.Mous_in_text(a))
			{
				back.setColor(Color(13,213,203));
			}
			else
			{
				back.setColor(Color(Color(60, 5, 8)));
			}
			if (back.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				button = 0;
				Sleep(200);
				//back.setColor(Color(13,213,203));
			}

			if (sound.Mous_in_text(a))
			{
				sound.setColor(Color(13,213,203));
			}
			else
			{
				sound.setColor(Color(Color::White));
			}
			if (sound.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				button_ = sound_;
			}

			if (management.Mous_in_text(a))
			{
				management.setColor(Color(13,213,203));
			}
			else
			{
				management.setColor(Color::White);
			}
			if (management.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				button_ = management_;
			}

			if (about.Mous_in_text(a))
			{
				about.setColor(Color(13,213,203));
			}
			else
			{
				about.setColor(Color::White);
			}
			if (about.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
			{
				button_ = about_;
			}
		}
		if (button_ == management_)
		{
			management_o.update(a, player, button_);
		}
		if (button_ == sound_)
		{
			Audio_op.update(music, button_, a);
		}
		if (button_ == about_)
		{
			aboutGame.update(a, button_);
		}
	}
void Option_class::draw(RenderWindow &a)
	{
		//std::cout << "sdf";

		if (button_ == No_)
		{
			a.draw(menu_s);
			management.dispayText(a);
			sound.dispayText(a);
			back.dispayText(a);
			about.dispayText(a);
		}
		if (button_ == management_)
		{
			management_o.draw(a);
		}
		if (button_ == sound_)
		{
			Audio_op.draw(a);
		}
		if (button_ == about_)
		{
			aboutGame.draw(a);
		}
	}
