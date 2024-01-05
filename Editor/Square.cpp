#include "Square.h"

Square::Square() {
    this->side = side; // ��������� ����� �������

    squareShape = new sf::RectangleShape();
    squareShape->setSize(sf::Vector2f(side, side)); // ������ ������ �������� � �������������� side
    squareShape->setFillColor(sf::Color::Blue); // ���� ������� ��������
    squareShape->setOutlineColor(sf::Color::Red); // ���� ������� ��������
    squareShape->setOutlineThickness(2); // ������� ������� ��������
    squareShape->setPosition(100, 125); // ������� �������� �� ������ (����� ��������)
}

Square::~Square() {
	delete squareShape;
}

void Square::fillColorFigure(const sf::Color& color){
	squareShape->setFillColor(color);
};

void Square::fillColorOutlineFigure(const sf::Color& color){
	squareShape->setOutlineColor(color);
};

sf::RectangleShape& Square::getSquareShape() {
	return *squareShape;
}

sf::FloatRect Square::getBounds() {
    return squareShape->getGlobalBounds();
};

void Square::changeTrancperencyFigure(){};

void Square::drawElements(sf::RenderWindow& window){
	window.draw(*squareShape);
};

void Square::moveElements(){};

void Square::resizeElements(){};

void Square::rotateElements(){};


