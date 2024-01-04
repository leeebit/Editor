#pragma once
#include "MyFigures.h"

class Circle : public MyFigures{
private:
	sf::CircleShape* circleShape;
	int radius;
public:
	Circle();
	~Circle();
	void drawElements(sf::RenderWindow& window);
	void moveElements();
	void resizeElements();
	void rotateElements();
	void fillColorFigure();
	void fillColorOutlineFigure();
	void changeTrancperencyFigure();
};

