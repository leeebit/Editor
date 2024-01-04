#include "Circle.h"

Circle::Circle() {
    circleShape = new sf::CircleShape();
    circleShape->setRadius(50); // ������������� ������ ����� �� ���������
    circleShape->setFillColor(sf::Color::Blue); // ���� ������� �����
    circleShape->setOutlineColor(sf::Color::Red); // ���� ������� �����
    circleShape->setOutlineThickness(2); // ������� ������� �����

    // ������������� ������� ����� � ����� ������ (����� ������������ window.getSize())
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