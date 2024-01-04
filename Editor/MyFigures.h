#pragma once
#include "Elements.h"

class MyFigures : public Elements
{
public:
	virtual void setfillColorFigure(const sf::Color& color);
	virtual void setfillColorOutlineFigure(const sf::Color& color);
	virtual void setTransparency(const sf::Color& color, int transparency);
};

