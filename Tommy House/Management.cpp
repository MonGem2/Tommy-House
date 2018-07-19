#include "Management.h"

Management::Management()
	{

	}
Management::Management(String file_font, String file_image)
	{
		menu.loadFromFile(file_image);
		Menu_t.loadFromImage(menu);
		menu_s.setTexture(Menu_t);
		Up.set(file_font, "Up:Up", 25, Color::White);
		Down.set(file_font, "Down:Down", 25, Color::White);
		Left.set(file_font, "Left:Left", 25, Color::White);
		Right.set(file_font, "Right:Right", 25, Color::White);
		back.set(file_font, "Back", 25, Color(Color(60, 5, 8)));
		Equip.set(file_font, "Equip/Unequip:E", 25, Color(Color(60, 5, 8)));
		Use.set(file_font, "Use:Space", 25, Color(Color(60, 5, 8)));
		Up.set_position(20, 20);
		Down.set_position(20, 50);
		Left.set_position(20, 80);
		Right.set_position(20, 110);
		Equip.set_position(20, 140);
		Use.set_position(20, 170);
		back.set_position(20, 200);

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
		Equip.set(file_font, "Equip/Unequip:E", 25, Color(Color(60, 5, 8)));
		Use.set(file_font, "Use:Space", 25, Color(Color(60, 5, 8)));
		Up.set_position(20, 20);
		Down.set_position(20, 50);
		Left.set_position(20, 80);
		Right.set_position(20, 110);
		Equip.set_position(20, 140);
		Use.set_position(20, 170);
		back.set_position(20, 200);
	}
void Management::update(RenderWindow &a, Player &b, int &button)
	{
		if (Up.Mous_in_text(a))
		{
			Up.setColor(Color(13,213,203));
		}
		else
		{
			Up.setColor(Color::White);
		}

		if (Down.Mous_in_text(a))
		{
			Down.setColor(Color(13,213,203));
		}
		else
		{
			Down.setColor(Color::White);
		}

		if (Left.Mous_in_text(a))
		{
			Left.setColor(Color(13,213,203));
		}
		else
		{
			Left.setColor(Color::White);
		}

		if (Right.Mous_in_text(a))
		{
			Right.setColor(Color(13,213,203));
		}
		else
		{
			Right.setColor(Color::White);
		}

		if (Equip.Mous_in_text(a))
		{
			Equip.setColor(Color(13,213,203));
		}
		else
		{
			Equip.setColor(Color::White);
		}

		if (Use.Mous_in_text(a))
		{
			Use.setColor(Color(13, 213, 203));
		}
		else
		{
			Use.setColor(Color::White);
		}

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
void Management::draw(RenderWindow &a)
	{
		a.draw(menu_s);
		Up.dispayText(a);
		Down.dispayText(a);
		Left.dispayText(a);
		Right.dispayText(a);
		Equip.dispayText(a);
		Use.dispayText(a);
		back.dispayText(a);
	}