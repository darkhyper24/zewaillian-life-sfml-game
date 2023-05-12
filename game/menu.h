#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
using namespace sf;
using namespace std;
class menu
{
private:
	int selected;
	Font font;
	int page = 100;
	sf::Clock clock;
	sf::Time delay;
	bool inputEnabled;
	Sprite bg;
	Texture menuBackground;
	Event event;
	Event eevent;

public:

	Text mainmenu[4];
	Text controlstext[7];

	menu();
	~menu();


	void initBackground(RenderWindow& window);
	void controls(RenderWindow& window);
	int getPage();
	void initVariables();
	void setDelay();
	void updateMenu();
	void playername(RenderWindow& window, string& name);
	void draw(RenderWindow& window);
	void moveup();
	void movedown();
	void set_selected(int n);
	int pressed();
};