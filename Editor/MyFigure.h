#pragma once
#include "Editor.h"
class MyFigure
{
public:
    virtual void FillColor(const sf::Color& color) = 0;
    virtual void FillColorOutline(const sf::Color& color, float outlineThickness) = 0;
    virtual void ChangeTransperency(float transparency) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
};

