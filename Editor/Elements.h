#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Elements
{
private:
	float x, y; //������� �� ������
public:
	virtual void drawElements(sf::RenderWindow& window);
	virtual void moveElements();
	virtual void resizeElements();
	virtual void rotateElements();
};

