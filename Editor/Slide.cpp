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
  
void Slide::CreateElements() {
	if (!elements) {
		elements = new Elements * [1];
		elements[0] = new Elements();
	}
	else {
		Elements** temp = new Elements * [elementCount + 1];
		for (int i = 0; i < elementCount; ++i) {
			temp[i] = elements[i];
		}
		temp[elementCount] = new Elements();

		delete[] elements;
		elements = temp;
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
}