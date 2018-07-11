#include "Text.h"

myText::myText()
	{
	}
myText::myText(String file, String newtext, int textsize, Color color)
	{
		font.loadFromFile(file);
		text.setFont(font);
		//text.setPosition()
		text.setString(newtext);
		text.setCharacterSize(textsize);
		text.setFillColor(color);


	}
void myText::set(String file, String newtext, int textsize, Color color)
	{
		font.loadFromFile(file);
		text.setFont(font);
		//text.setPosition()
		text.setString(newtext);
		text.setCharacterSize(textsize);
		text.setFillColor(color);

	}
void myText::setText(String newtext)
	{
		text.setString(newtext);
	}
void myText::setFont(String file)
	{
		font.loadFromFile(file);
		text.setFont(font);
	}
void myText::setColor(Color color)
	{
		text.setFillColor(color);
	}
void myText::setSize(int size)
	{
		text.setCharacterSize(size);

	}
void myText::dispayText(RenderWindow &window)
	{
		window.draw(text);
	}
void myText::set_position(float x, float y)
	{
		text.setPosition(x, y);
	}
bool myText::Mous_in_text(RenderWindow &a)
	{
		size_sumbol = text.findCharacterPos(1).x - text.findCharacterPos(0).x;
		if (Mouse::getPosition(a).x > text.getPosition().x
			&&Mouse::getPosition(a).x < text.getPosition().x + text.getString().getSize()*size_sumbol
			&& Mouse::getPosition(a).y>text.getPosition().y
			&&Mouse::getPosition(a).y<text.getPosition().y + text.getCharacterSize())
		{
			return true;
		}
		return false;
	}