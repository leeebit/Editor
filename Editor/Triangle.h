#pragma once
#include "MyFigures.h"
class Triangle : public MyFigures{
private:
	sf::ConvexShape triangleShape;
public:
	void drawElements();
	void moveElements();
	void resizeElements();
	void rotateElements();
	void fillColorFigure();
	void fillColorOutlineFigure();
	void changeTrancperencyFigure();
};

