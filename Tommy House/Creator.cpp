#include "Creator.h"

Creator_::Creator_()
	{
	}
Creator_::Creator_(String file_image, String font)
	{
		menu.loadFromFile(file_image);
		menu_t.loadFromImage(menu);
		menu_s.setTexture(menu_t);
		back.set(font, "Back", 30, Color(Color(60, 5, 8)));
		back.set_position(40, 70);
	}
	void Creator_::set(String file_image, String font)
	{
		menu.loadFromFile(file_image);
		menu_t.loadFromImage(menu);
		menu_s.setTexture(menu_t);
		back.set(font, "Back", 30, Color(Color(60, 5, 8)));
		back.set_position(40, 70);
	}
	void Creator_::update(RenderWindow &a, int &isop)
	{
		//std::cout << isop << "\t";
		if (back.Mous_in_text(a))
		{
			back.setColor(Color::Black);
		}
		else
		{
			back.setColor(Color(Color(60, 5, 8)));
		}
		if (back.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
		{
			Sleep(200);
			isop = 0;
			//back.setColor(Color::Black);
		}
	}
	void Creator_::draw(RenderWindow &a)
	{
		a.draw(menu_s);
		back.dispayText(a);
	}