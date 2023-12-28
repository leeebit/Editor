#pragma once
#include "MyFigure.h"
#include "Circle.h"

class Circle : public MyFigure{
private:
    sf::CircleShape circle;

public:
    Circle(float radius);
    void FillColor(const sf::Color& color);
    void FillColorOutline(const sf::Color& color, float outlineThickness);
    void ChangeTransperency(float transparency);
    void Draw(sf::RenderWindow& window);
};


