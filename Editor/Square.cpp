#include "Square.h"

Square::Square(float size) : square(sf::Vector2f(size, size)) {}

void Square::FillColor(const sf::Color& color) {
    square.setFillColor(color);
}

void Square::FillColorOutline(const sf::Color& color, float outlineThickness) {
    square.setOutlineColor(color);
    square.setOutlineThickness(outlineThickness);
}

void Square::ChangeTransperency(float transparency) {
    sf::Color currentColor = square.getFillColor();
    currentColor.a = static_cast<sf::Uint8>(255 * transparency);
    square.setFillColor(currentColor);
}

void Square::Draw(sf::RenderWindow& window) {
    window.draw(square);
}