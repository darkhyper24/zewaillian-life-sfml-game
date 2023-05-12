#include "game.h"
void game::initWindow()
{
    this->videoMode = sf::VideoMode(960, 640);
    this->window = new sf::RenderWindow(this->videoMode, "Zwailian Life ", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);

}

//Constructors and Destructors
game::game()
{


    this->initWindow();

}

game::~game()
{
    delete this->window;
}



//Functions
const bool game::running() const
{
    return this->window->isOpen();
}

void game::pollEvents()


{
    while (this->window->pollEvent(this->sfmlEvent))
    {
        switch (this->sfmlEvent.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}


void game::update()
{

    this->pollEvents();

    menu.updateMenu();

    menuState();

}

void game::render()
{
    this->window->clear();

    //Render stuff
    menu.draw(*this->window);

    this->window->display();
}
//page 100 = mainmenu window
//page 0 = enter your name window
//page 1 = volume window
//page 2 = controls window
//page 3 = exit program
//page 4 = select character window
//page 5 = cutscene window
//page 6 = outside the academic window
//page 7 = dr doaa office window
//page 8 = dr walid office window
void game::menuState()
{

    if (menu.getPage() == 3)
    {
        this->window->close();
    }
    if (menu.getPage() == 0)
    {
        menu.playername(*this->window,name);
    }
    if (menu.getPage() == 2) {
        menu.controls(*this->window);
    }
}

