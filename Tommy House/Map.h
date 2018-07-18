#pragma once

#include <SFML/Graphics.hpp>
#include"Room.h"
#include<ctime>
#include<vector>
//#include"Player.h"

using namespace sf;

const int HEIGHT_MAP = 33;
const int WIDTH_MAP = 26;

class map
{
	std::vector<room> rooms;
	int sizeblock = 32;
public:
	
	map()
	{
		///////////////////stage1////////////////////
		Vector2u point1(10 * sizeblock, 4 * sizeblock);
		std::vector<Vector2u> temp1;
		Vector2u neigh1(19 * sizeblock, 4 * sizeblock);
		temp1.push_back(neigh1);
		neigh1.x = 10 * sizeblock;
		neigh1.y = 18 * sizeblock;
		temp1.push_back(neigh1);
		room kitchen;
		kitchen.set(1 * sizeblock, 1 * sizeblock, 1, 13 * sizeblock, 12 * sizeblock, temp1, point1);


		Vector2u point2(19 * sizeblock, 4 * sizeblock);
		std::vector<Vector2u> temp2;
		Vector2u neigh2(10 * sizeblock, 4 * sizeblock);
		temp2.push_back(neigh2);
		room read;
		read.set(15 * sizeblock, 1 * sizeblock, 1, 10 * sizeblock, 8 * sizeblock, temp2, point2);


		Vector2u point3(16 * sizeblock, 14 * sizeblock);
		std::vector<Vector2u> temp3;
		Vector2u neigh3(16 * sizeblock, 18 * sizeblock);
		temp3.push_back(neigh3);
		room toilet;
		toilet.set(15 * sizeblock, 10 * sizeblock, 1, 10 * sizeblock, 6 * sizeblock, temp3, point3);


		Vector2u point4(16 * sizeblock, 18 * sizeblock);
		std::vector<Vector2u> temp4;
		Vector2u neigh4(16 * sizeblock, 14 * sizeblock);
		temp4.push_back(neigh4);
		neigh4.x = 16;
		neigh4.y = 24;
		temp4.push_back(neigh4);
		neigh4.x = 10;
		neigh4.y = 18;
		temp4.push_back(neigh4);
		room corridor1;
		corridor1.set(15 * sizeblock, 10 * sizeblock, 1, 10 * sizeblock, 5 * sizeblock, temp4, point4);


		Vector2u point5(10 * sizeblock, 18 * sizeblock);
		std::vector<Vector2u> temp5;
		Vector2u neigh5(16 * sizeblock, 18 * sizeblock);
		temp5.push_back(neigh5);
		neigh5.x = 10;
		neigh5.y = 4;
		temp5.push_back(neigh5);
		room main_room;
		main_room.set(1 * sizeblock, 14 * sizeblock, 1, 13 * sizeblock, 18 * sizeblock, temp5, point5);


		Vector2u point6(16 * sizeblock, 24 * sizeblock);
		std::vector<Vector2u> temp6;
		Vector2u neigh6(16 * sizeblock, 18 * sizeblock);
		temp6.push_back(neigh6);
		room bedroom1;
		bedroom1.set(15 * sizeblock, 23 * sizeblock, 1, 10 * sizeblock, 9 * sizeblock, temp6, point6);

		///////////////////stage2////////////////////

	}
	static Vector2u spawnGranny()
	{
		Vector2u a(50, 50);
		return a;
	}
	static Vector2u spawnPlayer()
	{
		Vector2u a(100, 100);
		return a;
	}
	static int getStageGranny()
	{
		return 0;
	}
	static int getStagePlayer()
	{
		return 2;
	}
	bool IsGrannyAndPlayerInRoom(int x, int y, int stage, int x2, int y2, int stage2)
	{
		for (int i = 0; i < rooms.size(); i++)
		{
			if (rooms[i].isInRoom(x, y, stage) && rooms[i].isInRoom(x2, y2, stage2));
			{
				return true;
			}
		}
		return false;
	}
	String Stage1[HEIGHT_MAP] = {
		"000000000001100000WWW00000",//0-wall
		"0TTTTnn    11 0          0",//1-stairs(up)
		"0TTTTnn       0          0",//2-stairs(down)
		"WTT                    TT0",//T-table
		"WTT      .        .    TT0",//t-toilet
		"Woo                    TT0",//n-nightstand
		"0oo                    TT0",//b-bath
		"0TT           0          0",//B-bed
		"0TT           0          0",//d-door
		"0nn           000000000000",//D-main door
		"0nn           0nnww t bbb0",//w-washbasin
		"0TTTTffTT     0nnww t bbb0",//W-window
		"0TTTTffTT     0       bbbW",//' '-floor
		"000000000     0       bbbW",//S-set(TV)
		"0             0       bbb0",//P-player's spawn
		"0             0 .     bbb0",//f-fridge
		"0             00dd00000000",//
		"0             0        nn0",//
		"0nn                    nn0",//
		"0nn      .      .        W",//
		"0SS                    nn0",//
		"0SS           0        nn0",//
		"0             00dd00000000",//
		"W             0 .        0",//
		"W             0          0",//
		"W             0    BBBBBB0",//
		"0             0    BBBBBB0",//
		"0             0    BBBBBB0",//
		"0             0    BBBBBB0",//
		"0             0          0",//
		"0nn           0 .    P   0",//
		"0nn           0          0",//
		"000000000DDD000000WW0WW000"
	};
	Vector2u GoUp(int stage)
	{
		if (stage == 1)
		{
			Vector2u a(12 * sizeblock, 1 * sizeblock);
			return a;
		}
		if (stage == 2)
		{
			Vector2u a(7 * sizeblock, 30 * sizeblock);
			return a;
		}
	}
	void getRandomPoint(int &x, int& y, int& stage)
	{
		//sf::Randomizer
		int v = rand() % rooms.size();
		x = rooms[v].getPoint().x;
		y = rooms[v].getPoint().y;
		stage = rooms[v].getStage();

	}
	Vector2u GoDown(int stage)
	{
		if (stage == 1)
		{
			Vector2u a(0, 0);
			return a;
		}
		if (stage == 2)
		{
			Vector2u a(11 * sizeblock, 1 * sizeblock);
			return a;
		}
	}
	room* getRoom(int x, int y, int stage)
	{
		for (int i = 0; i < rooms.size(); i++)
		{
			if (stage == rooms[i].getStage())
			{
				if (rooms[i].isInRoom(x, y, stage))
				{
					return &rooms[i];
				}
			}
		}
	}
	String Stage2[HEIGHT_MAP] = {
		"000000000002200000WWW00000",//0-wall                   
		"0          22            0",//1-stairs(up)
		"0 s                      0",//2-stairs(down)
		"0    .             .     0",//T-table
		"0                        0",//t-toilet
		"0rrrrddrrr               0",//n-nightstand
		"0oo      r               0",//b-bath
		"0TT      r               0",//B-bed
		"0TT      r               0",//d-door
		"0nn      d               0",//D-main door
		"0nn  .   d         .     0",//w-washbasin
		"0TTTTffTTr               0",//W-window
		"0TTTTffTTr               0",//' '-floor
		"000000000r               0",//S-set(TV)
		"0        r               0",//P-player's spawn
		"0        r               0",//f-fridge
		"0        r               0",//r-railing
		"0        r               0",//
		"0nn      r               0",//
		"0nn      r               0",//
		"0SS      r               0",//
		"0SS      r               0",//
		"0     .  r               0",//
		"0        r               0",//
		"0        r               0",//
		"0rrrrrddrr               0",//
		"0                        0",//
		"0     .            .     0",//
		"0                        0",//
		"0000000000               0",//
		"01111111 d         .     0",//
		"01111111 d               0",//
		"00000000000000000000000000"
	};
};