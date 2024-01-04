#pragma once
#include "MyFigures.h"

class Circle : public MyFigures{
private:
	sf::CircleShape* circleShape;
	float radius = 50.0;

public:
	Circle();
	~Circle();
	void drawElements(sf::RenderWindow& window);
	void moveElements();
	void resizeElements();
	void rotateElements();
	void setfillColorFigure(const sf::Color& color);
	void setfillColorOutlineFigure(const sf::Color& color);
	sf::CircleShape& getCircleShape();
	void changeTrancperencyFigure();
	
};

