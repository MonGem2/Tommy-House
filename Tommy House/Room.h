#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
using namespace sf;
class room
{
	int x, y, stage, w, h;
	std::vector<Vector2u> neighbor;
	Vector2u point;
public:
	room()
	{
	}
	void set(int x, int y, int stage, int w, int h, std::vector<Vector2u> neighbor, Vector2u point)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->stage = stage;
		this->h = h;
		this->neighbor = neighbor;
		this->point = point;
	}
	room(int x, int y, int stage, int w, int h, std::vector<Vector2u> neighbor, Vector2u point)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->stage = stage;
		this->h = h;
		this->neighbor = neighbor;
		this->point = point;
	}
	int getStage()
	{
		return stage;
	}
	bool isInRoom(int X, int Y, int Stage)
	{
		return ((Stage == stage) && (X >= x) && (X <= x + w) && (Y > y) && (Y<y + h));
	}
	std::vector<Vector2u> getNeighbor()
	{
		return neighbor;
	}
	Vector2u getPoint()
	{
		return point;
	}
};