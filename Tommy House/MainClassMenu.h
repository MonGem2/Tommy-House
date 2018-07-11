#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class MainClassMenu
{
public:
	virtual void set(...);

	virtual void update(...);

	virtual void draw(RenderWindow &a) = 0;

};