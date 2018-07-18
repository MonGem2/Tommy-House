#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include "Camera.h"
#include <Windows.h>
using namespace sf;
class StartNewGame
{
	int day = 1;
	int difficultyes;
	Player Granny;
	Player player;
	map Map;
	Image mask;
	Texture maskT;
	Sprite maskS;
	myText pause;
	bool isPause=false;
	myText exitToMenu;
	myText back;
	float thisTime=0;
	Camera view;
public:
	StartNewGame(int difficultyes_, String file, Player &player, String font)
	{
		this->player = player;
		pause.set(font, "Pause", 25, Color::White);
		exitToMenu.set(font, "Exit to menu", 25, Color::White);
		pause.set_position(20, 50);
		back.set(font, "Back", 25, Color(60, 5, 8));
		exitToMenu.set_position(player.get_x()-20, player.get_y()-20);
		back.set_position(player.get_x() - 20, player.get_y() +20);
		difficultyes = difficultyes_;
		Granny.set(file, player.get_w(), player.get_h(), font, player.get_textSize(), Color(60, 5, 8),0.1, 
			map::getStageGranny(), map::spawnGranny().x, map::spawnGranny().y);
		this->player.setPosition(map::spawnPlayer().x, map::spawnPlayer().y);
		if (difficultyes_ == 0)
		{
			mask.loadFromFile("Image/mask_easy.png");
		}
		if (difficultyes_ == 1)
		{
			mask.loadFromFile("Image/mask_extreme.png");
		}
		if (difficultyes_ == 2)
		{
			mask.loadFromFile("Image/mask_hard.png");
		}
		if (difficultyes_ == 3)
		{
			mask.loadFromFile("Image/mask_medium.png");
		}
		maskT.loadFromImage(mask);
		maskS.setTexture(maskT);
	}
	StartNewGame()
	{

	}
	void set(int difficultyes_, String file, Player &player, String font)
	{
		this->player = player;
		this->player.setStage(map::getStagePlayer());
		pause.set(font, "Pause", 25, Color::White);
		exitToMenu.set(font, "Exit to menu", 25, Color::White);
		pause.set_position(20, 50);
		back.set(font, "Back", 25, Color(60, 5, 8));
		exitToMenu.set_position(player.get_x() - 20, player.get_y() - 20);
		back.set_position(player.get_x() - 20, player.get_y() + 20);
		difficultyes = difficultyes_;
		Granny.set(file, player.get_w(), player.get_h(), font, player.get_textSize(), Color(60, 5, 8),0.1, 
			map::getStageGranny(), map::spawnGranny().x, map::spawnGranny().y);
		this->player.setPosition(map::spawnPlayer().x, map::spawnPlayer().y);
		if (difficultyes_ == 0)
		{
			mask.loadFromFile("Image/mask_easy.png");
			mask.createMaskFromColor(Color(255, 255, 255));
		}
		if (difficultyes_ == 1)
		{
			mask.loadFromFile("Image/mask_extreme.png");
			mask.createMaskFromColor(Color(255, 255, 255));
		}
		if (difficultyes_ == 2)
		{
			mask.loadFromFile("Image/mask_hard.png");
			mask.createMaskFromColor(Color(255, 255, 255));
		}
		if (difficultyes_ == 3)
		{
			mask.loadFromFile("Image/mask_medium.png");
			mask.createMaskFromColor(Color(255, 255, 255));
		}
		maskT.loadFromImage(mask);
		maskS.setTexture(maskT);
	}
	void update(float time, Player &player, int &button, RenderWindow &window)
	{
		
		if (thisTime <= 0 && day != 6&&!isPause)
		{
			
			if (pause.Mous_in_text(window))
			{
				pause.setColor(Color::Black);
			}
			else
			{
				pause.setColor(Color::White);
			}
			if (pause.Mous_in_text(window)&&Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Escape))
			{
				isPause = true;
			}
			if (difficultyes == 0)
			{
				player.update(time, Map, 0.2);
				//Granny.update_autoGranny(time, Map, player, 0.5);
			}
			if (difficultyes == 1)
			{
				player.update(time, Map, 0.2);
				//Granny.update_autoGranny(time, Map, player, 0.1);
			}
			if (difficultyes == 2)
			{
				player.update(time, Map, 0.1);
				//Granny.update_autoGranny(time, Map, player, 0.1);
			}
			if (difficultyes == 3)
			{
				player.update(time, Map, 0.1);
				//Granny.update_autoGranny(time, Map, player, 0.15);
			}
			
			if (player.isGrannyWithPlayer(Granny.get_x(), Granny.get_y(), Granny.get_w(), Granny.get_h(), difficultyes*5)&&player.get_stage()==Granny.get_stage())
			{
				player.setPosition(map::spawnPlayer().x, map::spawnPlayer().y);
				Granny.setPosition(map::spawnGranny().x, map::spawnGranny().y);
				day += 1;
				thisTime = 100;
			}
			
			view.setPosition(player.get_x(), player.get_y());
			
		}
		if (isPause)
		{
			
			
			view.setPosition(player.get_x(), player.get_y());
			
		
			if (exitToMenu.Mous_in_text(window))
			{
				exitToMenu.setColor(Color::Black);

			}
			else
			{
				exitToMenu.setColor(Color::White);
			}
			if (exitToMenu.Mous_in_text(window)&&Mouse::isButtonPressed(Mouse::Left))
			{
				button = 0;
			}

			if (back.Mous_in_text(window))
			{
				back.setColor(Color::Black);
			}
			else 
			{
				back.setColor(Color(60, 5, 8));
			}
			if (back.Mous_in_text(window) && Mouse::isButtonPressed(Mouse::Left))
			{
				isPause = false;
			}

		}
		
		if (thisTime > 0)
		{
			thisTime -= time;
		}

		if (day == 6)
		{
			button = 0;
		}
		
		
	}
	
	void draw(RenderWindow &window)
	{
		if (isPause)
		{
			Image map_image;//объект изображения для карты
			map_image.loadFromFile("Image/map.jpg");//загружаем файл для карты
			Texture map;//текстура карты
			map.loadFromImage(map_image);//заряжаем текстуру картинкой
			Sprite s_map;//создаём спрайт для карты
			s_map.setTexture(map);//заливаем текстуру спрайтом
			if (player.get_stage() == 1)
			{
				for (int i = 0; i < HEIGHT_MAP; i++)
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						if (Map.Stage1[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 34, 34)); //если встретили символ пробел, то рисуем 1й квадратик
						if (Map.Stage1[i][j] == 's')  s_map.setTextureRect(IntRect(34, 0, 34, 34));//если встретили символ s, то рисуем 2й квадратик
						if ((Map.Stage1[i][j] == '0')) s_map.setTextureRect(IntRect(68, 0, 34, 34));//если встретили символ 0, то рисуем 3й квадратик

						

						s_map.setPosition(j * 34, i * 34);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

						window.draw(s_map);//рисуем квадратики на экран
					}
			}
			if (player.get_stage() == 2)
			{
				for (int i = 0; i < HEIGHT_MAP; i++)
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						
						if (Map.Stage2[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 34, 34)); //если встретили символ пробел, то рисуем 1й квадратик
						if (Map.Stage2[i][j] == 's')  s_map.setTextureRect(IntRect(34, 0, 34, 34));//если встретили символ s, то рисуем 2й квадратик
						if ((Map.Stage2[i][j] == '0')) s_map.setTextureRect(IntRect(68, 0, 34, 34));//если встретили символ 0, то рисуем 3й квадратик

						

						s_map.setPosition(j * 34, i * 34);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

						window.draw(s_map);//рисуем квадратики на экран
					}
			}
			window.draw(maskS);
			back.dispayText(window);
			exitToMenu.dispayText(window);
		}
		if (day != 6 && !isPause)
		{
			Image map_image;//объект изображения для карты
			map_image.loadFromFile("Image/map.jpg");//загружаем файл для карты
			Texture map;//текстура карты
			map.loadFromImage(map_image);//заряжаем текстуру картинкой
			Sprite s_map;//создаём спрайт для карты
			s_map.setTexture(map);//заливаем текстуру спрайтом

			if (player.get_stage() == 0)
			{

				for (int i = 0; i < HEIGHT_MAP; i++)
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						if (Map.Stage1[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 34, 34)); //если встретили символ пробел, то рисуем 1й квадратик
						if (Map.Stage1[i][j] == 's')  s_map.setTextureRect(IntRect(34, 0, 34, 34));//если встретили символ s, то рисуем 2й квадратик
						if ((Map.Stage1[i][j] == '0')) s_map.setTextureRect(IntRect(68, 0, 34, 34));//если встретили символ 0, то рисуем 3й квадратик


						s_map.setPosition(j * 34, i * 34);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

						window.draw(s_map);//рисуем квадратики на экран
					}
			}
			if (player.get_stage() == 1)
			{

				for (int i = 0; i < HEIGHT_MAP; i++)
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						if (Map.Stage1[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 34, 34)); //если встретили символ пробел, то рисуем 1й квадратик
						if (Map.Stage1[i][j] == 's')  s_map.setTextureRect(IntRect(34, 0, 34, 34));//если встретили символ s, то рисуем 2й квадратик
						if ((Map.Stage1[i][j] == '0')) s_map.setTextureRect(IntRect(68, 0, 34, 34));//если встретили символ 0, то рисуем 3й квадратик


						s_map.setPosition(j * 34, i * 34);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

						window.draw(s_map);//рисуем квадратики на экран
					}
			}
			if (player.get_stage() == 2)
			{
				
				for (int i = 0; i < HEIGHT_MAP; i++)
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						if (Map.Stage2[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 34, 34)); //если встретили символ пробел, то рисуем 1й квадратик
						if (Map.Stage2[i][j] == 's')  s_map.setTextureRect(IntRect(34, 0, 34, 34));//если встретили символ s, то рисуем 2й квадратик
						if (Map.Stage2[i][j] == '0') s_map.setTextureRect(IntRect(68, 0, 34, 34));//если встретили символ 0, то рисуем 3й квадратик

						

						s_map.setPosition(j * 34, i * 34);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

						window.draw(s_map);//рисуем квадратики на экран
					}
			}
			
			if (player.get_stage() == Granny.get_stage())
			{
				Granny.drav_window(window);
			}
			
			player.drav_window(window);
			window.draw(maskS);
			pause.dispayText(window);

		}

	}
};
