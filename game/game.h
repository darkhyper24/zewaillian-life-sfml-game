#pragma once
#include"menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
using namespace sf;
using namespace std;
class game
{
private:
    menu menu;
    string name;

    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event sfmlEvent;

    void initVariables();
    void initWindow();

public:
    //Constructors and Destructors
    game();
    ~game();



    //Modifiers

    const bool running() const;
    void pollEvents();

    void menuState();

    void update();

    void render();
};

