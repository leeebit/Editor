#include "Editor.h"
#include "MyFigure.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Shapes");

    Circle circle(50.f);
    circle.FillColor(sf::Color::Red);
    circle.FillColorOutline(sf::Color::Green, 2.f);
    circle.ChangeTransperency(0.5f);

    Square square(100.f);
    square.FillColor(sf::Color::Blue);
    square.FillColorOutline(sf::Color::Yellow, 1.f);
    square.ChangeTransperency(0.7f);

    Triangle triangle(100.f);
    triangle.FillColor(sf::Color::Magenta);
    triangle.FillColorOutline(sf::Color::Cyan, 3.f);
    triangle.ChangeTransperency(0.3f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        circle.Draw(window);
        square.Draw(window);
        triangle.Draw(window);
        window.display();
    }

    return 0;
}