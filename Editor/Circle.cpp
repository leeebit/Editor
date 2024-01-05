#include "Circle.h"

Circle::Circle() {
    // Создание квадрата
    squareShape = new sf::RectangleShape(sf::Vector2f(100, 100));
    squareShape->setFillColor(sf::Color::Transparent);
    squareShape->setOutlineColor(sf::Color::Green);
    squareShape->setOutlineThickness(2);
    squareShape->setPosition(100, 125); // Позиция квадрата

    // Создание круга
    circleShape = new sf::CircleShape(50); // Радиус круга по умолчанию
    circleShape->setFillColor(sf::Color::Blue); // Цвет заливки круга
    circleShape->setOutlineColor(sf::Color::Red); // Цвет обводки круга
    circleShape->setOutlineThickness(2); // Толщина обводки круга

    // Устанавливаем позицию круга внутри квадрата (в центре квадрата)
    sf::FloatRect circleBounds = circleShape->getGlobalBounds();
    sf::FloatRect squareBounds = squareShape->getGlobalBounds();

    float circleX = squareBounds.left + (squareBounds.width - circleBounds.width) / 2;
    float circleY = squareBounds.top + (squareBounds.height - circleBounds.height) / 2;

    circleShape->setPosition(circleX, circleY);
}

Circle::~Circle() {
    delete circleShape;
}

void Circle::setfillColorFigure(const sf::Color& color) {
    circleShape->setFillColor(color);
};

void Circle::setfillColorOutlineFigure(const sf::Color& color) {
    circleShape->setOutlineColor(color);
};

sf::CircleShape& Circle::getCircleShape() {
    return *circleShape;
}

void Circle::setTransparency(const sf::Color& color, int transparency) {
    
};

void Circle::drawElements(sf::RenderWindow& window){
    window.draw(*squareShape);
    window.draw(*circleShape);
};

sf::FloatRect Circle::getBounds() {
    return squareShape->getGlobalBounds();
};

void Circle::showMenu(){};

void Circle::moveElements(){};

void Circle::resizeElements(){};

void Circle::rotateElements(){};

