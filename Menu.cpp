#include "Menu.h"
#include <iostream>

Menu::Menu() {
    if (!font.loadFromFile("arial.ttf")) return;
}
//Prints the menu
void Menu::printMenu(sf::RenderWindow &window)
{
    //Prints the background for the menu
    sf::Texture menuTexture;
    menuTexture.loadFromFile("MenuBackground.png");
    sf::Sprite menuBackground;
    menuBackground.setTexture(menuTexture);
    menuBackground.setScale(2.f, 2.f);
    window.draw(menuBackground);

    //Prints the title
    sf::Text text;
    text.setFont(font);
    text.setString("Welcome to ???\n");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setStyle(sf::Text::Underlined);
    text.setPosition(sf::Vector2f(100, 50));
    window.draw(text);

    printOptions(window);
}
//Prints the options on the menu
void Menu::printOptions(sf::RenderWindow& window)
{
    //Prints options
    sf::Text text;
    text.setFont(font);
    text.setString("1) Play Game\n2) How To Play\n3) Exit\n");
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(100, 300));
    window.draw(text);
}
//Prints the rules
void Menu::printInstructions(sf::RenderWindow& window) {
        window.clear(sf::Color::Blue);
        //Prints the game rules
        text.setFont(font);
        text.setString("Objective: Survive the longest\n\nRules:\n1) Run from the ghosts\n2) Stay alive\n\n\n\n\n\n\n\n\n\nTo go back, press Space");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(sf::Vector2f(100, 50));
        window.draw(text);
}
//Checks the input of a user while menu is open
int Menu::checkInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) return 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) return 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) return 3;
    else return -1;
}