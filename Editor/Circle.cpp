#include "Circle.h"

Circle::Circle() {
    // �������� ��������
    squareShape = new sf::RectangleShape(sf::Vector2f(100, 100));
    squareShape->setFillColor(sf::Color::Transparent);
    squareShape->setOutlineColor(sf::Color::Green);
    squareShape->setOutlineThickness(2);
    squareShape->setPosition(100, 125); // ������� ��������

    // �������� �����
    circleShape = new sf::CircleShape(50); // ������ ����� �� ���������
    circleShape->setFillColor(sf::Color::Blue); // ���� ������� �����
    circleShape->setOutlineColor(sf::Color::Red); // ���� ������� �����
    circleShape->setOutlineThickness(2); // ������� ������� �����

    // ������������� ������� ����� ������ �������� (� ������ ��������)
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

