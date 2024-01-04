#pragma once
#include "MyFigures.h"
class Square : public MyFigures{
private:
	sf::RectangleShape* rectangleShape;
public:
	void drawElements();
	void moveElements();
	void resizeElements();
	void rotateElements();
	void fillColorFigure();
	void fillColorOutlineFigure();
	void changeTrancperencyFigure();
};

