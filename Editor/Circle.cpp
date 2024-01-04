#include "Circle.h"

Circle::Circle() {
    circleShape = new sf::CircleShape();
    circleShape->setRadius(50); // Устанавливаем радиус круга по умолчанию
    circleShape->setFillColor(sf::Color::Blue); // Цвет заливки круга
    circleShape->setOutlineColor(sf::Color::Red); // Цвет обводки круга
    circleShape->setOutlineThickness(2); // Толщина обводки круга

    // Устанавливаем позицию круга в центр экрана (здесь используется window.getSize())
    circleShape->setPosition(100, 125);
}

Circle::~Circle() {
    delete circleShape;
}

void Circle::fillColorFigure(){};

void Circle::fillColorOutlineFigure(){};

void Circle::changeTrancperencyFigure(){};

void Circle::drawElements(sf::RenderWindow& window){
    window.draw(*circleShape);
};

void Circle::moveElements(){};

void Circle::resizeElements(){};

void Circle::rotateElements(){};