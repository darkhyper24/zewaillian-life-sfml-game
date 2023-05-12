#include "game.h"
menu::menu()
{
	this->initVariables();
}

menu::~menu()
{

}
//keyboard moving down logic
void menu::movedown()
{
	if (selected + 1 <= 4) {
		mainmenu[selected].setFillColor(Color::White);
		selected++;
		if (selected == 4) {
			selected = 0;
		}
		mainmenu[selected].setFillColor(Color::Yellow);
	}
}
void menu::set_selected(int n)
{
	selected = n;
}

int menu::pressed()
{
	return selected;
}
void menu::initBackground(RenderWindow& window)
{
	menuBackground.loadFromFile("assets/background/backgrounddd.jpg");
	bg.setTexture(menuBackground);
	window.draw(bg);
	
}
//setting an array of the keybindings for the game and displaying it to the user
void menu::controls(RenderWindow& window)
{
	font.loadFromFile("assets/fonts/Barlock.otf");
	controlstext[0].setFont(font);
	controlstext[0].setFillColor(Color::Yellow);
	controlstext[0].setString("Move up:   up");
	controlstext[0].setCharacterSize(50);
	controlstext[0].setPosition(Vector2f(100, 640 / (15)));

	controlstext[1].setFont(font);
	controlstext[1].setFillColor(Color::Yellow);
	controlstext[1].setString("Move down:   down");
	controlstext[1].setCharacterSize(50);
	controlstext[1].setPosition(Vector2f(100, 640 / (15) + 75));

	controlstext[2].setFont(font);
	controlstext[2].setFillColor(Color::Yellow);
	controlstext[2].setString("Move right:   right");
	controlstext[2].setCharacterSize(50);
	controlstext[2].setPosition(Vector2f(100, 640 / (15) + 150));

	controlstext[3].setFont(font);
	controlstext[3].setFillColor(Color::Yellow);
	controlstext[3].setString("Move left:   left");
	controlstext[3].setCharacterSize(50);
	controlstext[3].setPosition(Vector2f(100, 640 / (15) + 225));

	controlstext[4].setFont(font);
	controlstext[4].setFillColor(Color::Yellow);
	controlstext[4].setString("Pick up item:   space");
	controlstext[4].setCharacterSize(50);
	controlstext[4].setPosition(Vector2f(100, 640 / (15) + 300));

	controlstext[5].setFont(font);
	controlstext[5].setFillColor(Color::Yellow);
	controlstext[5].setString("Interact:   I");
	controlstext[5].setCharacterSize(50);
	controlstext[5].setPosition(Vector2f(100, 640 / (15) + 375));

	controlstext[6].setFont(font);
	controlstext[6].setFillColor(Color::Yellow);
	controlstext[6].setString("Enter a room:   Enter");
	controlstext[6].setCharacterSize(50);
	controlstext[6].setPosition(Vector2f(100, 640 / (15) + 450));

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed()) {
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				page = 100;
				return;
			}

		}
		window.clear();
		initBackground(window);
		for (int i = 0; i < 7; i++) {
			window.draw(controlstext[i]);
		}
		window.display();

	}
}

int menu::getPage()
{
		return this->page;
}
//setting an array of the features that the mainmenu contains
void menu::initVariables()
{
	delay = sf::seconds(0.15f);
	inputEnabled = true;
	this->selected = 0;


	font.loadFromFile("assets/fonts/Barlock.otf");
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color::Yellow);
	mainmenu[0].setString("play");
	mainmenu[0].setCharacterSize(90);
	mainmenu[0].setPosition(Vector2f(250, 640 / (11)));

	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::White);
	mainmenu[1].setString("volume");
	mainmenu[1].setCharacterSize(90);
	mainmenu[1].setPosition(Vector2f(250, 640 / (11) + 150));

	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color::White);
	mainmenu[2].setString("controls");
	mainmenu[2].setCharacterSize(90);
	mainmenu[2].setPosition(Vector2f(250, 640 / (11) + 300));

	mainmenu[3].setFont(font);
	mainmenu[3].setFillColor(Color::White);
	mainmenu[3].setString("exit");
	mainmenu[3].setCharacterSize(90);
	mainmenu[3].setPosition(Vector2f(250, 640 / (11) + 450));

}

void menu::setDelay()
{
	if (!inputEnabled)
	{
		// Check if the delay time has passed
		if (clock.getElapsedTime() >= delay)
		{
			// Enable input and reset the timer
			inputEnabled = true;
			clock.restart();
		}
	}
}
//setting the page number
void menu::updateMenu()
{
	this->setDelay();

	if (page == 100)
	{

		if (inputEnabled && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			moveup();
			inputEnabled = false;
			clock.restart();
		}
		if (inputEnabled && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			movedown();
			inputEnabled = false;
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (pressed() == 0)
			{
				page = 0;
			}

			else if (pressed() == 1)
			{
				page = 1;
			}
			else if (pressed() == 2)
			{
				page = 2;
			}
			else if (pressed() == 3)
			{
				page = 3;
			}
		}

	}
}

//setting a text that says enter your name and a place for the user to enter it

void menu::playername(RenderWindow& window, string& name)
{
	if (!name.empty())
	{
		name.clear();
	}
	Font font;
	font.loadFromFile("assets/fonts/Barlock.otf");
	Text headText;
	Text nameText;
	headText.setFont(font);
	nameText.setFont(font);
	headText.setString("enter your name");
	headText.setCharacterSize(70);
	nameText.setCharacterSize(70);
	headText.setPosition(10, 10);
	nameText.setPosition(10, 100);
	headText.setFillColor(Color::Green);
	nameText.setFillColor(Color::White);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed()) {
				window.close();
			}
			if (event.type == Event::TextEntered) {
				name += static_cast<char>(event.text.unicode);
			}
			if (Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() > 0) {
				name.resize(name.size() - 1);
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter) && name.size() > 1) {
				page = 4;
				return;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				page = 100;
				return;
			}
		}
		nameText.setString(name);
		window.clear();
		initBackground(window);
		window.draw(headText);
		window.draw(nameText);
	
		window.display();

	}
}

void menu::draw(RenderWindow& window)
{
	initBackground(window);
	for (int i = 0; i < 4; i++) {
		window.draw(mainmenu[i]);
	}
}
//keyboard moving up logic
void menu::moveup()
{
	if (selected - 1 >= -1) {
		mainmenu[selected].setFillColor(Color::White);
		selected--;
		if (selected == -1) {
			selected = 3;
		}
		mainmenu[selected].setFillColor(Color::Yellow);
	}
}