#include "Menu.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

Menu::Menu() : window(sf::VideoMode(1152, 864), "Программа для работы с презентациями"), CreatePresentation(false) {}

void Menu::run() {
    while (window.isOpen()) {
        handleEvents();
        if (CreatePresentation) {
            drawFigures();
        }
        else {
            render();
        }
    }
}

void Menu::handleEvents() {
    sf::Event event;
    sf::Color defaultColor = sf::Color::Black;
    sf::Color hoverColor = sf::Color(48, 152, 252);
    sf::Color clickColor = sf::Color(21, 64, 255);
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (!CreatePresentation && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                float windowWidth = static_cast<float>(window.getSize().x);
                float windowHeight = static_cast<float>(window.getSize().y);

                // Проверка нажатия по координатам каждой кнопки
                if (x >= windowWidth / 2 - 100 && x <= windowWidth / 2 + 100 && y >= windowHeight / 2 - 30 && y <= windowHeight / 2 + 20) {
                    
                    std::cout << "Selected: Create presentation\n";
                    CreatePresentation = true;
                }
                else if (x >= windowWidth / 2 - 125 && x <= windowWidth / 2 + 125 && y >= windowHeight / 2 + 30 && y <= windowHeight / 2 + 80) {
                    std::cout << "Selected: Load presentation\n";
                    // Действие для загрузки презентации (заглушка)
                }
                else if (x >= windowWidth / 2 - 100 && x <= windowWidth / 2 + 100 && y >= windowHeight / 2 + 90 && y <= windowHeight / 2 + 140) {
                    std::cout << "Selected: Exit\n";
                    window.close(); // Выход из программы
                }
            }
            break;
        default:
            break;
        }
    }
}


void Menu::drawFigures() {
    window.clear(sf::Color(223, 226, 219));

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

    circle.Draw(window);
    square.Draw(window);
    triangle.Draw(window);

    window.display();
}

void Menu::render() {
    window.clear(sf::Color(223, 226, 219));

    sf::Font font;
    if (!font.loadFromFile("C:/Users/Home/Editor/Editor/DMSerifDisplay-Regular.ttf")) {
        std::cerr << "Ошибка загрузки шрифта!\n";
    }

    // Размеры окна
    float windowWidth = static_cast<float>(window.getSize().x);
    float windowHeight = static_cast<float>(window.getSize().y);

    // Текст для кнопок
    sf::Text createText("Create presentation", font, 20);
    createText.setFillColor(sf::Color::Black);
    centerText(createText, windowWidth, windowHeight, 0);

    sf::Text loadText("Load presentation", font, 20);
    loadText.setFillColor(sf::Color::Black);
    centerText(loadText, windowWidth, windowHeight, 1);

    sf::Text exitText("Exit", font, 20);
    exitText.setFillColor(sf::Color::Black);
    centerText(exitText, windowWidth, windowHeight, 2);

    // Заголовок программы
    sf::Text titleText("Graphic Editor", font, 40);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold);
    centerText(titleText, windowWidth, windowHeight, -2);

    window.draw(titleText);
    window.draw(createText);
    window.draw(loadText);
    window.draw(exitText);
    window.display();
}

void Menu::centerText(sf::Text& text, float windowWidth, float windowHeight, int positionIndex) {
    // Вычисление позиции для центрирования текста
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    float xPos = windowWidth / 2.0f;
    float yPos = windowHeight / 2.0f;

    // Расположение кнопок в зависимости от индекса
    const float offset = 50.0f;
    yPos += offset * positionIndex;

    text.setPosition(xPos, yPos);
}
