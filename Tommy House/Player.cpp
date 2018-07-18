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
Player::Player(String F, float W, float H, String font, int textsize, Color color, float stage_, float speed, int X, int Y)
{
	this->speed = speed;
	stage = stage_;
	file = F;
	x = X;
	y = Y;
	w = W;
	h = H;
	image.loadFromFile(file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, w, h));
	tempPositionFromAuto.x = 999;
	tempPositionFromAuto.y = 999;
	if (X != 999)
	{
		sprite.setPosition(x, y);
	}

}
void Player::set(String F, float W, float H, String font, int textsize, Color color, float stage_, float speed, int X, int Y)
{
	this->speed = speed;
	stage = stage_;
	file = F;
	x = X;
	y = Y;
	w = W;
	h = H;
	image.loadFromFile(file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, w, h));
	tempPositionFromAuto.x = 999;
	tempPositionFromAuto.y = 999;
	if (X != 999)
	{
		sprite.setPosition(x, y);
	}

}
void Player::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	sprite.setPosition(x, y);
}
void Player::update(float time, map &Map, float speed)
{
	float dx = 0, dy = 0, x_=x, y_=y;
	time = time / 700;
		if (Keyboard::isKeyPressed(up))
		{
			dy = -speed;
			setTextureRect(time, 3);
			sprite.move(0, dy);
		}
		if (Keyboard::isKeyPressed(down))
		{
			dy = speed; 
			setTextureRect(time, 0);
			sprite.move(0, dy);
		}
		if (Keyboard::isKeyPressed(right))
		{
			dx = speed; 
			setTextureRect(time, 2);
			sprite.move(dx, 0);
		}
		if (Keyboard::isKeyPressed(left))
		{
			dx = -speed; 
			setTextureRect(time, 1);
			sprite.move(dx, 0);
		}
	float z=x + dx * time , v= y + dy * time;;
	if (dx > 0)
	{
		for (int i = 0; i < z - x; i++)
		{
			x_ = x;
			y_ = y;
			x++;
			map_update(Map, dx, 0, x_, y_);
		}

	}
	if (dx < 0)
	{
		for (int i = 0; i > z - x; i--)
		{
			x_ = x;
			y_ = y;
			x--;
			map_update(Map, dx, 0, x_, y_);
		}

	}
	if (dy > 0)
	{
		for (int i = 0; i < v - y; i++)
		{
			x_ = x;
			y_ = y;
			y++;
			map_update(Map, dy, 0, x_, y_);
		}

	}
	if (dy < 0)
	{
		for (int i = 0; i > v - y; i--)
		{
			x_ = x;
			y_ = y;
			y--;
			map_update(Map, dy, 0, x_, y_);
		}

	}
	



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
void Player::map_update(map &Map, float dx, float dy, float x_, float y_)
{
	
	for (int i = y / Map.sizeblock; i<(y + h) / Map.sizeblock; i++)
		for (int l = x / Map.sizeblock; l < (x + w) / Map.sizeblock; l++)
		{
			
			if (Map.Stage1[i][l] == '0')
			{
				
				if (dx > 0)
				{
					x = x_;

				}
				if (dx < 0)
				{
					x=x_;

				}
				if (dy < 0)
				{
					y = y_;

				}
				if (dy > 0)
				{
					y=y_;

				}
			}
		}
	dx = dy = 0;
	std::cout << x << "       " << y << std::endl << w << "       " << h << std::endl;
	sprite.setPosition(x, y);
}
float Player::get_w()
{
	return w;
}
float Player::get_h()
{
	return h;
}
float Player::get_textSize()
{
	return textxp.size();
}
bool Player::isGrannyWithPlayer(int X, int Y, int W, int H, int zone)
{
	if (x >= X - zone && x + w <= X + W + zone && y > Y - zone && y + h <= Y + H + zone)
	{
		return true;
	}
	return false;
}
int Player::get_stage()
{
	return stage;
}
Vector2u Player::goToPoint(int x, int y, int stage, map &Map)
{
	std::vector<Vector2u> temp = Map.getRoom(this->x, this->y, this->stage)->getNeighbor();
	if (this->stage > stage)
	{
		x = Map.GoDown(this->stage).x;
		y = Map.GoDown(this->stage).y;
	}
	if (this->stage < stage)
	{
		x = Map.GoUp(this->stage).x;
		y = Map.GoUp(this->stage).y;
	}
	//std::vector<Vector2u> temp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (x - temp[i].x < x - this->x&&Map.getRoom(temp[i].x, temp[i].y, this->stage)->getNeighbor().size() != 1)
		{
			return temp[i];
		}
		if (y - temp[i].y < y - this->y&&Map.getRoom(temp[i].x, temp[i].y, this->stage)->getNeighbor().size() != 1)
		{
			return temp[i];
		}
	}
	return temp[0];
}
/*void Player::update_autoGranny(float time, map &Map, Player &player, float speed)
{
	if (player.getPlayerPositionFaktor())
	{
		Vector2u temp = goToPoint(player.get_x(), player.get_y(), player.get_stage(), Map);
	}
	if (tempTime > 5000)
	{
		tempTime = 0;
		int g, k;
		Map.getRandomPoint(g, k, tempStage);
		tempPositionFromAuto.x = g;
		tempPositionFromAuto.y = k;
	}
	if (this->x == tempPositionFromAuto.x&&this->x == tempPositionFromAuto.y&&this->stage == tempStage && tempTime<5000 &&
		(!Map.IsGrannyAndPlayerInRoom(this->x, this->y, this->stage, player.get_x(), player.get_y(), player.get_stage()) || player.getFakor()))
	{
		tempTime += time;
	}
	if (Map.IsGrannyAndPlayerInRoom(this->x, this->y, this->stage, player.get_x(), player.get_y(), player.get_stage()) && !player.getFakor())
	{
		tempPositionFromAuto.x = player.get_x();
		tempPositionFromAuto.y = player.get_y();
	}
	time = time / 700;
	if (tempPositionFromAuto.x < x)
	{
		dx = -speed; setTextureRect(time, 1);
	}
	if (tempPositionFromAuto.x > x)
	{
		dx = speed; setTextureRect(time, 1);
	}
	if (tempPositionFromAuto.y < y)
	{
		dy = -speed;
		setTextureRect(time, 3);
	}
	if (tempPositionFromAuto.y > y)
	{
		dy = speed;
		setTextureRect(time, 3);
	}
	x += dx * time;
	y += dy * time;
	speed = 0;
	map_update(Map);
}*/
void Player::setStage(int stage)
{
	this->stage = stage;


}