#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;

class myText
{
	Text text;
	Font font;
	int size_sumbol;
public:
	myText();
	myText(String file, String newtext, int textsize, Color color = Color::Black);
	void set(String file, String newtext, int textsize, Color color = Color::Black);
	void setText(String newtext);
	void setFont(String file);
	void setColor(Color color);
	void setSize(int size);
	void dispayText(RenderWindow &window);
	void set_position(float x, float y);
	bool Mous_in_text(RenderWindow &a);
};