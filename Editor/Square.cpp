#include "Square.h"

Square::Square() {
    this->side = side; // Сохраняем длину стороны

    squareShape = new sf::RectangleShape();
    squareShape->setSize(sf::Vector2f(side, side)); // Задаем размер квадрата с использованием side
    squareShape->setFillColor(sf::Color::Blue); // Цвет заливки квадрата
    squareShape->setOutlineColor(sf::Color::Red); // Цвет обводки квадрата
    squareShape->setOutlineThickness(2); // Толщина обводки квадрата
    squareShape->setPosition(100, 125); // Позиция квадрата на экране (можно изменить)
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


