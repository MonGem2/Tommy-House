#include "Menu.h"
#include <Windows.h>

class Game
{
public:

	static Game& getInstance() {
		static Game app;
		return app;
	}

	void startGame(int length, int height)
	{
		Clock clock;
		RenderWindow window(sf::VideoMode(length, height), "Tommy House");
		Menu menu1("Image/Hous(Menu).jpg", "Font/Brushstroke Horror.otf", "Music/music1.ogg", "Image/Creators.jpg", "Image/tommy.png");
		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			menu1.update(window, time);
			window.clear();
			menu1.draw(window);
			window.display();
		}
	}

private:

	Game() {  }

	Game(Game const&) = delete;

	~Game() {  }

	Game& operator= (Game const&) = delete;
};

int main()
{
	//HWND hConsole = GetConsoleWindow();//Если компилятор старый заменить на GetForegroundWindow()
	//ShowWindow(hConsole, SW_HIDE);//собственно прячем оконо консоли
	Game::getInstance().startGame(1000, 700);
	return 0;
}