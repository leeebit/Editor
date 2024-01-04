#include "GraphicEditor.h"
#include <vector>
using namespace sf;



GraphicEditor::GraphicEditor() {
	presentation = nullptr;
}

GraphicEditor::~GraphicEditor() {
	if (presentation != nullptr) {
		for (int i = 0; i < presentationCount; ++i) {
			delete presentation[i];
		}
		delete[] presentation;
	}
}

void GraphicEditor::CreatePresentation() {
	if (!presentation) {
		presentation = new Presentation * [1];
		presentation[0] = new Presentation();
		currentSlideIndex = 0;
	}
	else {
		Presentation** temp = new Presentation * [presentationCount + 1];
		for (int i = 0; i < presentationCount; ++i) {
			temp[i] = presentation[i];
		}
		temp[presentationCount] = new Presentation();

		delete[] presentation;
		presentation = temp;
	}
	presentationCount++;
}

int GraphicEditor::getCurrentSlideIndex() {
	return currentSlideIndex;
}

void GraphicEditor::setCurrentSlideIndex(int a) {
	currentSlideIndex = a;
}

void GraphicEditor::App(sf::RenderWindow& window) {

	RectangleShape Menu(Vector2f(1024, 100));
	Menu.setFillColor(Color(223, 226, 219));
	Menu.setPosition(0, 0);

	Font font;
	if (!font.loadFromFile("DMSerifDisplay-Regular.ttf")) {
		std::cerr << "Error font load!\n";
	}

	Text createPresentationText("Create presentation", font, 20);
	createPresentationText.setFillColor(Color::Black);
	createPresentationText.setPosition(20, 20);

	Text createSlideText("Create slide", font, 20);
	createSlideText.setFillColor(Color::Black);
	createSlideText.setPosition(200, 20);

	Text deleteSlideText("Delete slide", font, 20);
	deleteSlideText.setFillColor(Color::Black);
	deleteSlideText.setPosition(320, 20);

	/*Text copySlideText("Copy slide", font, 20);
	copySlideText.setFillColor(Color::Black);
	copySlideText.setPosition(500, 20);*/

	Text createElementText("Create element", font, 20);
	createElementText.setFillColor(Color::Black);
	createElementText.setPosition(700, 20);

	Text deleteElementText("Delete element", font, 20);
	deleteElementText.setFillColor(Color::Black);
	deleteElementText.setPosition(850, 20);
	window.draw(Menu);

	sf::RectangleShape colorPickerDialog(sf::Vector2f(400, 400));
	colorPickerDialog.setFillColor(sf::Color::White);
	colorPickerDialog.setOutlineColor(sf::Color::Black);
	colorPickerDialog.setOutlineThickness(1.f);
	colorPickerDialog.setPosition((window.getSize().x - colorPickerDialog.getSize().x) / 2, (window.getSize().y - colorPickerDialog.getSize().y) / 2);
	window.draw(colorPickerDialog);

	sf::RectangleShape createElementWindow(sf::Vector2f(300, 200));
	createElementWindow.setFillColor(sf::Color::White);
	createElementWindow.setOutlineColor(sf::Color::Black);
	createElementWindow.setOutlineThickness(1.f);
	createElementWindow.setPosition((window.getSize().x - createElementWindow.getSize().x) / 2, (window.getSize().y - createElementWindow.getSize().y) / 2);
	window.draw(createElementWindow);

	sf::Text circleButton("Circle", font, 20);
	circleButton.setFillColor(sf::Color::Black);
	circleButton.setPosition(createElementWindow.getPosition().x + 20, createElementWindow.getPosition().y + 20);
	window.draw(circleButton);

	sf::Text squareButton("Square", font, 20);
	squareButton.setFillColor(sf::Color::Black);
	squareButton.setPosition(createElementWindow.getPosition().x + 20, createElementWindow.getPosition().y + 60);
	window.draw(squareButton);

	sf::Text triangleButton("Triangle", font, 20);
	triangleButton.setFillColor(sf::Color::Black);
	triangleButton.setPosition(createElementWindow.getPosition().x + 20, createElementWindow.getPosition().y + 100);
	window.draw(triangleButton);

	sf::RectangleShape createElementPropertiesWindow(sf::Vector2f(300, 200));
	createElementPropertiesWindow.setFillColor(sf::Color::White);
	createElementPropertiesWindow.setOutlineColor(sf::Color::Black);
	createElementPropertiesWindow.setOutlineThickness(1.f);
	createElementPropertiesWindow.setPosition((window.getSize().x - createElementPropertiesWindow.getSize().x) / 2, (window.getSize().y - createElementPropertiesWindow.getSize().y) / 2);
	window.draw(createElementPropertiesWindow);

	sf::Text colorFillButton("Circle", font, 20);
	colorFillButton.setFillColor(sf::Color::Black);
	colorFillButton.setPosition(createElementPropertiesWindow.getPosition().x + 20, createElementPropertiesWindow.getPosition().y + 20);
	window.draw(colorFillButton);

	sf::Text outlineFillButton("Square", font, 20);
	outlineFillButton.setFillColor(sf::Color::Black);
	outlineFillButton.setPosition(createElementPropertiesWindow.getPosition().x + 20, createElementPropertiesWindow.getPosition().y + 60);
	window.draw(outlineFillButton);
	//палитра цветов
	for (int i = 0; i < 36; ++i) {
		colorRectangles[i] = sf::RectangleShape(sf::Vector2f(20, 20));
		colorRectangles[i].setPosition((window.getSize().x - colorPickerDialog.getSize().x) / 2 + 20 + (i % 6) * 30, (window.getSize().y - colorPickerDialog.getSize().y) / 2 + 20 + (i / 6) * 30);
		colorRectangles[i].setFillColor(colors[i]);
	}

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left) {
					Vector2i mousePos = Mouse::getPosition(window);
					if (createPresentationText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Presentation!" << std::endl;
						// Логика для создания презентации
						if (presentation == nullptr) {
							CreatePresentation();
							std::cout << "Presentation is created!" << std::endl;
						}
						else std::cout << "Presentation doesn't created!" << std::endl;
					}
					else if (createSlideText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Slide!" << std::endl;
						// Логика для создания слайда
						if (presentation != nullptr) {

							currentSlideIndex = presentation[0]->CreateSlideAtIndex(currentSlideIndex); // Создаем слайд
							std::cout << currentSlideIndex << std::endl;
						}
						else std::cout << "Slide doesn't created!" << std::endl;
					}
					else if (createElementText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Elements!" << std::endl;
						if (presentation != nullptr && currentSlideIndex >= 0 && currentSlideIndex < presentation[0]->getSlideCount()) {
							isCreateElementMenuActive = true;
						}

					}
					else if (isCreateElementMenuActive) {
						sf::Vector2i mousePos = sf::Mouse::getPosition(window);
						if (circleButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							std::cout << "Clicked Circle!" << std::endl;
							if (presentation != nullptr && currentSlideIndex >= 0 && currentSlideIndex < presentation[0]->getSlideCount()) {
								presentation[0]->getSlides()[currentSlideIndex]->createElements(Slide::getCircleType());
								isCreateElementMenuActive = false;
							}
						}
						else if (squareButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							std::cout << "Clicked Square!" << std::endl;
							if (presentation != nullptr && currentSlideIndex >= 0 && currentSlideIndex < presentation[0]->getSlideCount()) {
								presentation[0]->getSlides()[currentSlideIndex]->createElements(Slide::getSquareType());
								isCreateElementMenuActive = false;
							}
						}
						else if (triangleButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							std::cout << "Clicked Triangle!" << std::endl;
							if (presentation != nullptr && currentSlideIndex >= 0 && currentSlideIndex < presentation[0]->getSlideCount()) {
								presentation[0]->getSlides()[currentSlideIndex]->createElements(Slide::getTriangleType());
								isCreateElementMenuActive = false;
							}
						}
					}
					else if (deleteSlideText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						if (presentation != nullptr) {
							std::cout << "Clicked Delete Slide!" << std::endl;
							currentSlideIndex = presentation[0]->DeleteSlideAtIndex(currentSlideIndex - 1);
							std::cout << currentSlideIndex << std::endl;
						}
						else std::cout << "Slide doesn't deleted!" << std::endl;
					}

					else if (isColorPickerActive && event.mouseButton.button == Mouse::Left) {
						Vector2f mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

						// Обработка выбора цвета из диалогового окна
						for (int i = 0; i < 36; ++i) {
							if (colorRectangles[i].getGlobalBounds().contains(mousePos)) {
								chosenColorIndex = i;
								break;
							}
						}

						// Если был выбран цвет, применяем его к слайду
						if (chosenColorIndex != -1 && currentSlideIndex != -1) {
							sf::Color selectedColor = colorRectangles[chosenColorIndex].getFillColor();
							presentation[0]->getSlides()[currentSlideIndex]->SetBackgroundColor(selectedColor);
							isColorPickerActive = false; // Закрыть диалоговое окно после выбора цвета
							chosenColorIndex = -1;
							std::cout << currentSlideIndex << std::endl;
						}
						else
							std::cout << "Background doesn't changed!" << std::endl;
					}
				}
				else if (event.mouseButton.button == Mouse::Right) {
					// Обработка правой кнопки мыши
					std::cout << "Clicked Change slide background!" << std::endl;
					Vector2i mousePos = Mouse::getPosition(window);
					if (presentation != nullptr) {
						Slide** slides = presentation[0]->getSlides();
						if (slides != nullptr) {
							for (int i = 0; i < presentation[0]->getSlideCount(); ++i) {
								if (slides[i]->getBackground().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
									isColorPickerActive = true;
									break;
								}
							}
						}
					}
				}
				break;

			case Event::KeyPressed:
				if (event.key.code == Keyboard::A) {
					if (currentSlideIndex > 0) {
						currentSlideIndex--; // Переход на предыдущий слайд
						std::cout << "Switch to previous slide. Current slide: " << currentSlideIndex << std::endl;
					}
				}
				else if (event.key.code == Keyboard::D) {
					if (presentation != nullptr) {
						int totalSlides = presentation[0]->getSlideCount();
						if (currentSlideIndex < totalSlides - 1) {
							currentSlideIndex++; // Переход на следующий слайд
							std::cout << "Switch to next slide. Current slide: " << currentSlideIndex << std::endl;
						}
					}
				}
				break;

			}
		}

		window.clear({ 255, 255, 255 });
		window.draw(Menu);
		window.draw(createPresentationText);
		window.draw(createSlideText);
		window.draw(deleteSlideText);
		window.draw(createElementText);
		window.draw(deleteElementText);

		// Отрисовка всех слайдов, если они есть
		if (presentation != nullptr) {
			Slide** slides = presentation[0]->getSlides();
			if (slides != nullptr) {
				for (int i = 0; i < presentation[0]->getSlideCount(); ++i) {
					slides[i]->Draw(window);
				}
			}
		}

		if (presentation != nullptr) {
			Slide** slides = presentation[0]->getSlides();
			if (slides != nullptr && currentSlideIndex >= 0 && currentSlideIndex <= presentation[0]->getSlideCount()) {
				window.draw(slides[currentSlideIndex]->getBackground());

				Elements** elements = slides[currentSlideIndex]->getElements();
				if (elements != nullptr) {
					for (int i = 0; i < slides[currentSlideIndex]->getElementCount(); ++i) {
						elements[i]->drawElements(window);
					}
				}
			}
		}


		if (isColorPickerActive) {
			window.draw(colorPickerDialog);
			for (int i = 0; i < 36; ++i) {
				window.draw(colorRectangles[i]);
			}
		}

		if (isCreateElementMenuActive) {
			window.draw(createElementWindow);
			window.draw(circleButton);
			window.draw(squareButton);
			window.draw(triangleButton);
		}

		if (isChangeElementPropertiesMenuActive) {
			window.draw(createElementPropertiesWindow);
			window.draw(colorFillButton);
			window.draw(outlineFillButton);
		}
		window.display();
	}
}


