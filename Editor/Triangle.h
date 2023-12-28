#pragma once
#include "MyFigure.h"
class Triangle : public MyFigure{

private:
    sf::ConvexShape triangle;

public:
    Triangle(float sideLength);
    void FillColor(const sf::Color& color);
    void FillColorOutline(const sf::Color& color, float outlineThickness);
    void ChangeTransperency(float transparency);
    void Draw(sf::RenderWindow& window);
};

