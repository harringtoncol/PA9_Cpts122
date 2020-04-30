#include "Menu.h"
#include <iostream>

Menu::Menu() {
    if (!font.loadFromFile("arial.ttf")) return;
}

void Menu::printMenu(sf::RenderWindow &window)
{
    window.clear(sf::Color::Blue);

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

void Menu::printOptions(sf::RenderWindow& window)
{
    sf::Text text;
    text.setFont(font);
    text.setString("1) Play Game\n2) How To Play\n3) Exit\n");
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(100, 300));
    window.draw(text);
}

void Menu::printInstructions(sf::RenderWindow& window) {
        window.clear(sf::Color::Cyan);

        text.setFont(font);
        text.setString("Objective: Find and hit \n\tthe target in the maze.\n\nRules:\n1) Locate the target\n2) Get to the target, \n\tbut beware of the ghosts\n3) Hit the target\n\n\nTo go back, press Space");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(sf::Vector2f(100, 50));
        window.draw(text);
}

int Menu::checkInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) return 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) return 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) return 3;
    else return -1;
}