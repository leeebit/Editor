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

int Slide::getCircleType(){
    return CIRCLE;
}

int Slide::getSquareType(){
    return SQUARE;
}

int Slide::getTriangleType(){
    return TRIANGLE;
}

Elements** Slide::getElements() {
    return elements;
}

int Slide::getElementCount() {
    return elementCount;
}
  
void Slide::createElements(int selectedFigure) {
        if (!elements) {
            elements = new Elements * [1];
            // Создание нового элемента в пустом массиве
            if (selectedFigure == CIRCLE) {
                elements[0] = new Circle();
            }
            else if (selectedFigure == SQUARE) {
                elements[0] = new Square();
            }
            else if (selectedFigure == TRIANGLE) {
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

            if (selectedFigure == CIRCLE) {
                elements[elementCount] = new Circle();
            }
            else if (selectedFigure == SQUARE) {
                elements[elementCount] = new Square();
            }
            else if (selectedFigure == TRIANGLE) {
                elements[elementCount] = new Triangle();
            }
        }
        elementCount++;

        std::cout << "Element is created!" << std::endl;
    }



void Slide::SetBackgroundColor(const sf::Color& color) {
	background->setFillColor(color);
}

sf::RectangleShape& Slide::getBackground() {
	return* background;
}


void Slide::Draw(sf::RenderWindow& window) {
	window.draw(*background);

    /*if (elements != nullptr) {
        for (int i = 0; i < elementCount; ++i) {
            elements[i]->drawElements(window);
        }
    }*/
   
}

