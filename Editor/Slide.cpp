#include "Slide.h"

Slide::Slide() {
	elements = nullptr;
	background = new sf::RectangleShape();
	background->setSize(sf::Vector2f(800, 450));
	background->setFillColor(sf::Color::White);
	background->setOutlineColor(sf::Color::Red);
	background->setOutlineThickness(2);
	background->setPosition(100, 125);
}

Slide::~Slide() {
	delete background;
	if (elements != nullptr) {
		for (int i = 0; i < elementCount; ++i) {
			delete elements[i];
		}
		delete[] elements;
	}
}
void Slide::setElementType(int type) {
	elementType = type;
}

int Slide::getElementType() const {
	return elementType;
}
Elements** Slide::getElements() {
	return elements;
}

int Slide::getElementCount() {
	return elementCount;
}

void Slide::setCurrentElement(Elements* element) {
	currentElement = element;
}

Elements* Slide::getCurrentElement() {
	return currentElement;
}

void Slide::createElements(const sf::Vector2f& clickPosition) {

	if (!elements) {
		elements = new Elements * [1];
		// Создание нового элемента в пустом массиве
		if (elementType == CIRCLE) {
			elements[0] = new Circle(clickPosition);
		}
		else if (elementType == SQUARE) {
			elements[0] = new Square(clickPosition);
		}
		else if (elementType == TRIANGLE) {
			elements[0] = new Triangle();
		}
		std::cout << "Element added to the slide!" << std::endl;
	}
	else {
		// Расширение массива и добавление нового элемента в конец
		Elements** temp = new Elements * [elementCount + 1];
		for (int i = 0; i < elementCount; ++i) {
			temp[i] = elements[i];
		}
		delete[] elements;

		elements = temp;

		if (elementType == CIRCLE) {
			elements[elementCount] = new Circle(clickPosition);
		}
		else if (elementType == SQUARE) {
			elements[elementCount] = new Square(clickPosition);
		}
		else if (elementType == TRIANGLE) {
			elements[elementCount] = new Triangle();
		}
		std::cout << "Create Element index is " << elementCount << " added to the slide!" << std::endl;
	}
	elementCount++;
	setCurrentElement(elements[elementCount - 1]);

}

void Slide::SetBackgroundColor(const sf::Color& color) {
	background->setFillColor(color);
}

sf::RectangleShape& Slide::getBackground() {
	return*background;
}

void Slide::Draw(sf::RenderWindow& window) {
	window.draw(*background);
}

