#include "Menu.h"

class Game
{
public:

	static Game& getInstance() {
		static Game app;
		return app;
	}

	void startGame()
	{
		Clock clock;
		RenderWindow window(sf::VideoMode(1000, 700), "Tommy Hous");
		Menu menu1("Image/Hous(Menu).jpg", "Font/Brushstroke Horror.otf", "Music/music1.ogg", "Image/Creators.jpg", "Image/granny.png");
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
			//window.draw(shape);
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
	Game::getInstance().startGame();
	return 0;
}