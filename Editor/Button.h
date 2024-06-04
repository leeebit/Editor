<<<<<<< HEAD
<<<<<<< HEAD
#pragma once
#include <SFML/Graphics.hpp>

typedef bool (*Action)();
=======
#pragma once
#include <SFML/Graphics.hpp>

class GraphEditor;

typedef bool (*GraphEditor::* Action)();
>>>>>>> parent of a47f314 (класс картинок)

class Button
{
public:
	sf::IntRect rect;
	sf::RectangleShape rect_shape;
	sf::Color color;
	Action click;

	Button(sf::IntRect r, sf::Color c, Action on_click_action);

	bool isClicked(sf::Vector2i mouse);
	void setOnClick(Action on_click_action);
	bool Click();

	void draw(sf::RenderWindow& window);

};

<<<<<<< HEAD
=======
//#pragma once
//#include <SFML/Graphics.hpp>
//
//class GraphEditor;
//
//typedef bool (*GraphEditor::* Action)();
//
//class Button
//{
//public:
//	sf::IntRect rect;
//	sf::RectangleShape rect_shape;
//	sf::Color color;
//	Action click;
//
//	Button(sf::IntRect r, sf::Color c, Action on_click_action);
//
//	bool isClicked(sf::Vector2i mouse);
//	void setOnClick(Action on_click_action);
//	bool Click();
//
//	void draw(sf::RenderWindow& window);
//
//};
//
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
=======
>>>>>>> parent of a47f314 (класс картинок)
