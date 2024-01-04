#pragma once
#include "MyFigures.h"
class Triangle : public MyFigures{
private:
	sf::ConvexShape triangleShape;
	const int TRIANGLE = 2;
public:
	void drawElements();
	void moveElements();
	void resizeElements();
	void rotateElements();
	void fillColorFigure();
	void fillColorOutlineFigure();
	void changeTrancperencyFigure();
	
};

