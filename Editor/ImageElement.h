#pragma once
#include "Elements.h"
class ImageElement : public Elements
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	bool loadFromFile(const std::string& filename);
	void drawElements(sf::RenderWindow& window) override;
	void moveElements(float offsetX, float offsetY)override;
	void resizeElements(float amount) override;
	void crop(const sf::IntRect& rect);
		
};

