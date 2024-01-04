#pragma once
#include "Elements.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

enum ElementType {
	CIRCLE = 0,
	SQUARE = 1,
	TRIANGLE = 2
};

class Slide
{
private: 
	Elements** elements;
    sf::RectangleShape* background;
	int elementCount;
	
public: 
	Slide();
	~Slide(); 
	void createElements(int selectedFigure);
	void SetBackgroundColor(const sf::Color& color);
	static int getCircleType();
	static int getSquareType();
	static int getTriangleType();
	Elements** getElements();
	int getElementCount();
	sf::RectangleShape& getBackground();
	void Draw(sf::RenderWindow& window);
};

