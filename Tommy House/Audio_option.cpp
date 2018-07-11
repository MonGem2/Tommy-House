#include "Audio_option.h"

Audio_option::Audio_option()
	{
	}
Audio_option::Audio_option(String file_f, String file_i)
	{
		menu.loadFromFile(file_i);
		menu_t.loadFromImage(menu);
		menu_s.setTexture(menu_t);
		if (Muse.music_on)
		{
			on_music.set(file_f, "music on", 25, Color(60, 5, 8));
			of_music.set(file_f, "music off", 25, Color::White);
		}
		else
		{
			on_music.set(file_f, "music on", 25, Color::White);
			of_music.set(file_f, "music off", 25, Color(60, 5, 8));
		}
		if (Muse.sound_on)
		{
			on.set(file_f, "sound on", 25, Color(60, 5, 8));
			of.set(file_f, "sound off", 25, Color::White);
		}
		else
		{
			on.set(file_f, "sound on", 25, Color::White);
			of.set(file_f, "sound off", 25, Color(60, 5, 8));
		}
		back.set(file_f, "Back", 25, Color(60, 5, 8));
		on_music.set_position(20, 20);
		of_music.set_position(120, 20);
		on.set_position(20, 50);
		of.set_position(120, 50);
		back.set_position(20, 80);
	}
void Audio_option::set(String file_f, String file_i)
	{
		menu.loadFromFile(file_i);
		menu_t.loadFromImage(menu);
		menu_s.setTexture(menu_t);
		if (Muse.music_on)
		{
			on_music.set(file_f, "music on", 25, Color(60, 5, 8));
			of_music.set(file_f, "music off", 25, Color::White);
		}
		else
		{
			on_music.set(file_f, "music on", 25, Color::White);
			of_music.set(file_f, "music off", 25, Color(60, 5, 8));
		}
		if (Muse.sound_on)
		{
			on.set(file_f, "sound on", 25, Color(60, 5, 8));
			of.set(file_f, "sound off", 25, Color::White);
		}
		else
		{
			on.set(file_f, "sound on", 25, Color::White);
			of.set(file_f, "sound off", 25, Color(60, 5, 8));
		}
		back.set(file_f, "Back", 25, Color(60, 5, 8));
		on_music.set_position(20, 20);
		of_music.set_position(120, 20);
		on.set_position(20, 50);
		of.set_position(120, 50);
		back.set_position(20, 80);
	}
void Audio_option::update(Music &music, int &button, RenderWindow &a)
	{
		if (on_music.Mous_in_text(a))
		{
			on_music.setColor(Color::Black);
		}
		else
		{
			if (Muse.music_on)
			{
				on_music.setColor(Color(60, 5, 8));
			}
			else
			{
				on_music.setColor(Color::White);
			}
		}
		if (on_music.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
		{
			Muse.music_on = true;
			music.play();
			music.setLoop(true);
		}
		if (of_music.Mous_in_text(a))
		{
			of_music.setColor(Color::Black);
		}
		else
		{
			if (!Muse.music_on)
			{
				of_music.setColor(Color(60, 5, 8));
			}
			else
			{
				of_music.setColor(Color::White);
			}
		}
		if (of_music.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
		{
			music.stop();
			Muse.music_on = false;
		}



		if (on.Mous_in_text(a))
		{
			on.setColor(Color::Black);
		}
		else
		{
			if (Muse.sound_on)
			{
				on.setColor(Color(60, 5, 8));
			}
			else
			{
				on.setColor(Color::White);
			}
		}
		if (on.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
		{
			Muse.sound_on = true;
		}

		if (of.Mous_in_text(a))
		{
			of.setColor(Color::Black);
		}
		else
		{
			if (!Muse.sound_on)
			{
				of.setColor(Color(60, 5, 8));
			}
			else
			{
				of.setColor(Color::White);
			}
		}
		if (of.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
		{
			Muse.sound_on = false;
		}


		if (back.Mous_in_text(a))
		{
			back.setColor(Color::Black);
		}
		else
		{
			back.setColor(Color(60, 5, 8));
		}
		if (back.Mous_in_text(a) && Mouse::isButtonPressed(Mouse::Left))
		{
			button = 0;
			Sleep(200);
		}
	}
void Audio_option::draw(RenderWindow &a)
	{
		a.draw(menu_s);
		on_music.dispayText(a);
		of_music.dispayText(a);
		on.dispayText(a);
		of.dispayText(a);
		back.dispayText(a);
	}
