#include "about game.h"

about_game::about_game()
	{
	}
about_game::about_game(String file_f, String file_i)
	{
		menu.loadFromFile(file_i);
		menu_t.loadFromImage(menu);
		menu_s.setTexture(menu_t);
		back.set(file_f, "Back", 25, Color(60, 5, 8));
		back.set_position(40, 480);
	}
void about_game :: set(String file_f, String file_i)
	{
		menu.loadFromFile(file_i);
		menu_t.loadFromImage(menu);
		menu_s.setTexture(menu_t);
		back.set(file_f, "Back", 25, Color(60, 5, 8));
		back.set_position(40, 480);
	}
void about_game::update(RenderWindow &a, int &button)
	{
		if (back.Mous_in_text(a))
		{
			back.setColor(Color(13,213,203));
		}
		else
		{
			back.setColor(Color(60, 5, 8));
		}
		if (back.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
		{
			button = 0;
		}

	}
void about_game:: draw(RenderWindow &a)
	{
		a.draw(menu_s);
		back.dispayText(a);
	}
