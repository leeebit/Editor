#include "Circle.h"

Circle::Circle() {
    this->radius = radius;
    circleShape = new sf::CircleShape();
    circleShape->setRadius(radius); // ������������� ������ ����� �� ���������
    circleShape->setFillColor(sf::Color::Blue); // ���� ������� �����
    circleShape->setOutlineColor(sf::Color::Red); // ���� ������� �����
    circleShape->setOutlineThickness(2); // ������� ������� �����

    // ������������� ������� ����� � ����� ������ (����� ������������ window.getSize())
    circleShape->setPosition(100, 125);
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

void Circle::changeTrancperencyFigure(){};

void Circle::drawElements(sf::RenderWindow& window){
    window.draw(*circleShape);
};

void Circle::moveElements(){};

void Circle::resizeElements(){};

void Circle::rotateElements(){};