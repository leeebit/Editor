#pragma once
#include "MyFigures.h"
class Square : public MyFigures{
private:
	sf::RectangleShape* squareShape;
	float side = 50.0;
	const int SQUARE = 1;
public:
	Square();
	~Square();
	void drawElements(sf::RenderWindow& window);
	void moveElements();
	void resizeElements();
	void rotateElements();
	void fillColorFigure(const sf::Color& color);
	void fillColorOutlineFigure(const sf::Color& color);
	sf::RectangleShape& getSquareShape();
	void changeTrancperencyFigure();
	
};

