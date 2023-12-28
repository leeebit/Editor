#include "Circle.h"

Circle::Circle(float radius) : circle(radius) {}

void Circle::FillColor(const sf::Color& color) {
    circle.setFillColor(color);
}

void Circle::FillColorOutline(const sf::Color& color, float outlineThickness) {
    circle.setOutlineColor(color);
    circle.setOutlineThickness(outlineThickness);
}

void Circle::ChangeTransperency(float transparency) {
    sf::Color currentColor = circle.getFillColor();
    currentColor.a = static_cast<sf::Uint8>(255 * transparency);
    circle.setFillColor(currentColor);
}

void Circle::Draw(sf::RenderWindow& window) {
    window.draw(circle);
}