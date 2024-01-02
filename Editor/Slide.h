#pragma once
#include "Elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class Slide
{
private: 
	Elements** elements;
    sf::RectangleShape* background;
	int elementCount;
public: 
	Slide();
	~Slide(); 
	void CreateElements();
	void SetBackgroundColor(const sf::Color& color);
	sf::RectangleShape& getBackground();
	void Draw(sf::RenderWindow& window);
};

