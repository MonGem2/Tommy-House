#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Camera
{
	View view;
public:
	Camera()
	{

	}
	Camera(int w, int h)
	{
		view.setSize(w, h);
	}
	void set(int w, int h)
	{
		view.setSize(w, h);

	}
	void setPosition(float x, float y)
	{
		view.setCenter(x, y);
	}

};