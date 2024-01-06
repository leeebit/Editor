#include "ImageElement.h"
bool ImageElement::loadFromFile(const std::string& filename) {
    if (!texture.loadFromFile(filename)) {
        std::cerr << "Failed to load image from file: " << filename << std::endl;
        return false;
    }
    sprite.setTexture(texture);
    return true;
};

// Метод для перемещения изображения
void ImageElement::moveElements(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
};

void ImageElement::resizeElements(float amount) {
    sf::Vector2f size = sprite.getScale();
    sf::Vector2f currentPos = sprite.getPosition();

    if (amount > 0) {
        size.x += amount;
        size.y += amount;
    }
    else if (amount < 0) {
        float absoluteAmount = std::abs(amount);
        size.x -= absoluteAmount;
        size.y -= absoluteAmount;
    }

    if (size.x > 150 || size.x < 10) {
       
        size.x = std::max(10.0f, std::min(150.0f, size.x));
        size.y = std::max(10.0f, std::min(150.0f, size.y));
    }

    sprite.setScale(size);

    if (currentPos.x + size.x > 800) {
        currentPos.x = 800 - size.x;
    }
    if (currentPos.y + size.y > 450) {
        currentPos.y = 450 - size.y;
    }

    sprite.setPosition(currentPos);
};

// Метод для обрезки изображения
void ImageElement::crop(const sf::IntRect& rect) {
    sprite.setTextureRect(rect);
}

// Метод для отрисовки изображения
void ImageElement::drawElements(sf::RenderWindow& window) {
    window.draw(sprite);
}