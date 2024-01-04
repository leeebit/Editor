#pragma once
#include "Elements.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Slide
{
private: 
	Elements** elements;
    sf::RectangleShape* background;
	int elementCount;
	static const int CIRCLE = 0;
	static const int SQUARE = 1;
	static const int TRIANGLE = 2;
	
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

