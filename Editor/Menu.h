#pragma once
#include "Editor.h"
class Menu
{
public:
    Menu();
    void run();
    void drawFigures();

private:
    sf::RenderWindow window;
    bool CreatePresentation = false;
    void handleEvents();
    void render();
    void centerText(sf::Text& text, float windowWidth, float windowHeight, int positionIndex);
};

