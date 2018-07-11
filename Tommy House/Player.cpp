#include "Player.h"

	void Player::setTextureRect(float &time, int dir1)
	{
		animation_time += 0.005*time;
		if (animation_time >= 3) animation_time -= 3;
		sprite.setTextureRect(IntRect((int)animation_time * w, h*dir1, w, h));
	}
	Player::Player()
	{
	}
	Player::Player(String F, int X, int Y, float W, float H, String font, int textsize, Color color)
	{
		file = F;
		x = X;
		y = Y;
		w = W;
		h = H;
		image.loadFromFile(file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
		sprite.setPosition(x, y);
	}
	void Player::set(String F, int X, int Y, float W, float H, String font, int textsize, Color color)
	{
		file = F;
		x = X;
		y = Y;
		w = W;
		h = H;
		image.loadFromFile(file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
		sprite.setPosition(x, y);
	}
	void Player::update(float time)
	{
		if (Keyboard::isKeyPressed(up) || Keyboard::isKeyPressed(down))
		{
			if (Keyboard::isKeyPressed(up))
			{
				speed = 0.1;
				dy = -speed;
				setTextureRect(time, 3);
			}
			if (Keyboard::isKeyPressed(down))
			{
				speed = 0.1;
				dy = speed; setTextureRect(time, 0);
			}
		}
		else
		{
			if (Keyboard::isKeyPressed(right))
			{
				speed = 0.1;
				dx = speed; setTextureRect(time, 2);
			}
			if (Keyboard::isKeyPressed(left))
			{
				speed = 0.1;
				dx = -speed; setTextureRect(time, 1);
			}
		}
		x += dx * time;
		y += dy * time;
		speed = 0;
		map();



	}
	void Player::set_management(Keyboard::Key up1, Keyboard::Key down1, Keyboard::Key left1, Keyboard::Key right1)
	{
		up = up1;
		down = down1;
		left = left1;
		right = right1;
	}
	void Player::mask_kolor(int r, int g, int b)
	{

		image.createMaskFromColor(Color(r, g, b));
	}
	void Player::drav_window(RenderWindow &window)
	{
		textxp.set_position(x, y - h - 5);
		textxp.dispayText(window);
		window.draw(sprite);
	}
	float Player::get_x()
	{
		return x;
	}
	float Player::get_y()
	{
		return y;
	}
	void Player::map()
	{
		for (int i = y / 32; i<(y + h) / 32; i++)
			for (int l = x / 32; l < (x + w) / 32; l++)
			{
				if (Map.TileMap[i][l] == '0')
				{
					if (dx > 0)
					{
						x = l * 32 - w;

					}
					if (dx < 0)
					{
						x = (l + 1) * 32;

					}
					if (dy < 0)
					{
						y = (i - 1) * 32 + h;

					}
					if (dy > 0)
					{
						y = i * 32 - h;

					}
				}
			}
		dx = dy = 0;
		sprite.setPosition(x, y);
	}
