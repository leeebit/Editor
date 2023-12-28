#include "Triangle.h"

Triangle::Triangle(float sideLength) {
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f, 0.f));
    triangle.setPoint(1, sf::Vector2f(sideLength, 0.f));
    triangle.setPoint(2, sf::Vector2f(sideLength / 2.f, sideLength));
}

void Triangle::FillColor(const sf::Color& color) {
    triangle.setFillColor(color);
}

void Triangle::FillColorOutline(const sf::Color& color, float outlineThickness) {
    triangle.setOutlineColor(color);
    triangle.setOutlineThickness(outlineThickness);
}

void Triangle::ChangeTransperency(float transparency) {
    sf::Color currentColor = triangle.getFillColor();
    currentColor.a = static_cast<sf::Uint8>(255 * transparency);
    triangle.setFillColor(currentColor);
}

void Triangle::Draw(sf::RenderWindow& window) {
    window.draw(triangle);
}