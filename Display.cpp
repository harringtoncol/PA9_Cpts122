#pragma once
#include "Display.h"


void displayMenu(Menu menu, sf::RenderWindow& window, sf::Clock clock, sf::Time elapsed)
{
    bool isMenuOpen = true;
    menu.printMenu(window);
    window.display();
    while (isMenuOpen) {
        int opt = menu.checkInput();
        if (opt > 0 && opt < 4) {
            if (opt == 1) {
                //elapsed = clock.restart();
                break;
            }
            else if (opt == 2) {
                menu.printInstructions(window);
                window.display();
                bool isRulesOpen = true;
                while (isRulesOpen) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        isRulesOpen = false;
                    }
                }
                menu.printMenu(window);
                window.display();
            }
            else if (opt == 3) window.close();
        }
    }
}

void displayTimer(sf::RenderWindow& window, sf::Clock clock, sf::Time elapsed, int posX, int posY)
{
    sf::RectangleShape clockBackground(sf::Vector2f(100, 40));
    clockBackground.setFillColor(sf::Color::Red);
    clockBackground.setPosition(posX, posY);
    window.draw(clockBackground);
    
    //Changes from float to string
    std::ostringstream ss;
    elapsed = clock.getElapsedTime();
    ss << elapsed.asSeconds();
    std::string timer(ss.str());
    timer = timer.substr(0, 6);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"));

    sf::Text text;
    text.setFont(font);
    text.setString(timer + "s");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(posX, posY));
    window.draw(text);
}

void displayWinner(sf::RenderWindow& window, int gameTime, bool isWinner, int posX, int posY)
{
    sf::Texture winnerTexture;
    winnerTexture.loadFromFile("WinnerBackground.png");
    sf::Sprite winnerBackground;
    winnerBackground.setTexture(winnerTexture);
    winnerBackground.setPosition(posX, posY);
    winnerBackground.setScale(2.f, 2.f);
    window.draw(winnerBackground);

    posX += 25;
    posY += 200;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"));
    
    sf::Text pStatus;
    pStatus.setFont(font);
    if (isWinner) {
        pStatus.setString("WINNER!!!");
    }
    else {
        pStatus.setString("Loser...");
    }
    pStatus.setCharacterSize(100);
    pStatus.setFillColor(sf::Color::Red);
    pStatus.setStyle(sf::Text::Bold);
    pStatus.setPosition(sf::Vector2f(posX, posY));
    window.draw(pStatus);

    std::string gTime = std::to_string(gameTime);

    posX += 125;
    posY += 250;

    sf::Text text;
    text.setFont(font);
    text.setString(gTime + " seconds");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(posX, posY));
    window.draw(text);
}
