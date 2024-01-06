#pragma once
#include "Elements.h"
class Triangle : public Elements {
private:
	sf::ConvexShape triangleShape;
public:
	void drawElements();
	void moveElements(float offsetX, float offsetY) override;
	void resizeElements(float amount) override;
	void fillColorFigure();
	void fillColorOutlineFigure();
};

