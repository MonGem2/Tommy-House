#include "Management.h"

Management::Management()
	{

	}
Management::Management(String file_font, String file_image)
	{
		menu.loadFromFile(file_image);
		Menu_t.loadFromImage(menu);
		menu_s.setTexture(Menu_t);
		Up.set(file_font, "Up:up", 25, Color::White);
		Down.set(file_font, "Down:down", 25, Color::White);
		Left.set(file_font, "Left:left", 25, Color::White);
		Right.set(file_font, "Right:Right", 25, Color::White);
		back.set(file_font, "Back", 25, Color(Color(60, 5, 8)));
		Die.set(file_font, "Die:die", 25, Color(Color(60, 5, 8)));
		Up.set_position(20, 20);
		Down.set_position(20, 50);
		Left.set_position(20, 80);
		Right.set_position(20, 110);
		Die.set_position(20, 140);
		back.set_position(20, 170);

		//back.set_position(20, 170);
	}
void Management::set(String file_font, String file_image)
	{
		menu.loadFromFile(file_image);
		Menu_t.loadFromImage(menu);
		menu_s.setTexture(Menu_t);
		Up.set(file_font, "Up:up", 25, Color::White);
		Down.set(file_font, "Down:down", 25, Color::White);
		Left.set(file_font, "Left:left", 25, Color::White);
		Right.set(file_font, "Right:Right", 25, Color::White);
		back.set(file_font, "Back", 25, Color(Color(60, 5, 8)));
		Die.set(file_font, "Die:die", 25, Color(Color(60, 5, 8)));
		Up.set_position(20, 20);
		Down.set_position(20, 50);
		Left.set_position(20, 80);
		Right.set_position(20, 110);
		Die.set_position(20, 140);
		back.set_position(20, 170);
	}
void Management::update(RenderWindow &a, Player &b, int &button)
	{
		if (Up.Mous_in_text(a))
		{
			Up.setColor(Color::Black);
		}
		else
		{
			Up.setColor(Color::White);
		}

		if (Down.Mous_in_text(a))
		{
			Down.setColor(Color::Black);
		}
		else
		{
			Down.setColor(Color::White);
		}

		if (Left.Mous_in_text(a))
		{
			Left.setColor(Color::Black);
		}
		else
		{
			Left.setColor(Color::White);
		}

		if (Right.Mous_in_text(a))
		{
			Right.setColor(Color::Black);
		}
		else
		{
			Right.setColor(Color::White);
		}

		if (Die.Mous_in_text(a))
		{
			Die.setColor(Color::Black);
		}
		else
		{
			Die.setColor(Color::White);
		}

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
		}
	}
void Management::draw(RenderWindow &a)
	{
		a.draw(menu_s);
		Up.dispayText(a);
		Down.dispayText(a);
		Left.dispayText(a);
		Right.dispayText(a);
		Die.dispayText(a);
		back.dispayText(a);
	}