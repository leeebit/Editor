#pragma once
#include "MyFigure.h"

class Square : public MyFigure{
private:
    sf::RectangleShape square;

public:
    Square(float size);
    void FillColor(const sf::Color& color);
    void FillColorOutline(const sf::Color& color, float outlineThickness);
    void ChangeTransperency(float transparency);
    void Draw(sf::RenderWindow& window);
};

