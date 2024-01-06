#pragma once
#include "MyFigures.h"

class Circle : public MyFigures {
private:
	sf::CircleShape* circleShape;
	sf::RectangleShape* squareShape;
public:
	Circle(const sf::Vector2f& position);
	~Circle();
	void drawElements(sf::RenderWindow& window);
	void moveElements();
	void resizeElements();
	void rotateElements();
	void setfillColorFigure(const sf::Color& color);
	void setfillColorOutlineFigure(const sf::Color& color);
	void getfillColorFigure(const sf::Color& color);
	void getfillColorOutlineFigure(const sf::Color& color);
	sf::CircleShape& getCircleShape();
	void setTransparency(const sf::Color& color, int transparency);
	void showMenu(); //меню характеристик, что можно сделать с элементом
	sf::FloatRect getBounds();

};

