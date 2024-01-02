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

	for (int i = 0; i < 36; ++i) {
		colorRectangles[i] = sf::RectangleShape(sf::Vector2f(20, 20)); // Задаем размеры прямоугольника
		colorRectangles[i].setPosition((window.getSize().x - colorPickerDialog.getSize().x) / 2 + 20 + (i % 6) * 30, (window.getSize().y - colorPickerDialog.getSize().y) / 2 + 20 + (i / 6) * 30); // Позиции прямоугольников с цветами

		// Устанавливаем цвет прямоугольника
		if (i == 0) {
			colorRectangles[i].setFillColor(sf::Color::Black);
		}
		else if (i == 1) {
			colorRectangles[i].setFillColor(sf::Color(128, 128, 128));
		}
		else if (i == 2) {
			colorRectangles[i].setFillColor(sf::Color(192, 192, 192));
		}
		else if (i == 3) {
			colorRectangles[i].setFillColor(sf::Color::White);
		}
		else if (i == 4) {
			colorRectangles[i].setFillColor(sf::Color(255, 0, 255));
		}
		else if (i == 5) {
			colorRectangles[i].setFillColor(sf::Color(128, 0, 128));
		}
		else if (i == 6) {
			colorRectangles[i].setFillColor(sf::Color::Red);
		}
		else if (i == 7) {
			colorRectangles[i].setFillColor(sf::Color(128, 0, 0));
		}
		else if (i == 8) {
			colorRectangles[i].setFillColor(sf::Color::Yellow);
		}
		else if (i == 9) {
			colorRectangles[i].setFillColor(sf::Color(128, 128, 0));
		}
		else if (i == 10) {
			colorRectangles[i].setFillColor(sf::Color::Green);
		}
		else if (i == 11) {
			colorRectangles[i].setFillColor(sf::Color(0, 128, 0));
		}
		else if (i == 12) {
			colorRectangles[i].setFillColor(sf::Color(0, 255, 255));
		}
		else if (i == 13) {
			colorRectangles[i].setFillColor(sf::Color(0, 128, 128));
		}
		else if (i == 14) {
			colorRectangles[i].setFillColor(sf::Color::Blue);
		}
		else if (i == 15) {
			colorRectangles[i].setFillColor(sf::Color(128, 128, 128));
		}
		else if (i == 16) {
			colorRectangles[i].setFillColor(sf::Color(0, 0, 128));
		}
		else if (i == 17) {
			colorRectangles[i].setFillColor(sf::Color(255, 192, 203));
		}
		else if (i == 18) {
			colorRectangles[i].setFillColor(sf::Color(255, 69, 0));
		}
		else if (i == 19) {
			colorRectangles[i].setFillColor(sf::Color(255, 160, 122));
		}
		else if (i == 20) {
			colorRectangles[i].setFillColor(sf::Color(230, 230, 250));
		}
		else if (i == 21) {
			colorRectangles[i].setFillColor(sf::Color(255, 248, 220));
		}
		else if (i == 22) {
			colorRectangles[i].setFillColor(sf::Color(245, 255, 250));
		}
		else if (i == 23) {
			colorRectangles[i].setFillColor(sf::Color(245, 245, 245));
		}
		else if (i == 24) {
			colorRectangles[i].setFillColor(sf::Color(211, 211, 211));
		}
		else if (i == 25) {
			colorRectangles[i].setFillColor(sf::Color(105, 105, 105));
		}
		else if (i == 26) {
			colorRectangles[i].setFillColor(sf::Color(255, 228, 225));
		}
		else if (i == 27) {
			colorRectangles[i].setFillColor(sf::Color(188, 148, 143));
		}
		else if (i == 28) {
			colorRectangles[i].setFillColor(sf::Color(245, 222, 179));
		}
		else if (i == 29) {
			colorRectangles[i].setFillColor(sf::Color(245, 245, 220));
		}
		else if (i == 30) {
			colorRectangles[i].setFillColor(sf::Color(222, 184, 135));
		}
		else if (i == 31) {
			colorRectangles[i].setFillColor(sf::Color(70, 130, 180));
		}
		else if (i == 32) {
			colorRectangles[i].setFillColor(sf::Color(255, 250, 205));
		}
		else if (i == 33) {
			colorRectangles[i].setFillColor(sf::Color(34, 139, 34));
		}
		else if (i == 34) {
			colorRectangles[i].setFillColor(sf::Color(102, 205, 170));
		}
		else if (i == 35) {
			colorRectangles[i].setFillColor(sf::Color(255, 215, 0));
		}
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

							currentSlideIndex = presentation[0]->CreateSlide(); // Создаем слайд
							std::cout << "Slide is created!" << std::endl;
						}
						else std::cout << "Slide doesn't created!" << std::endl;
					}
					else if (createElementText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Elements!" << std::endl;
						if (presentation != nullptr) {
							Slide** slides = presentation[0]->getSlides();
							if (slides != nullptr) {
								slides[0]->CreateElements();
								std::cout << "Elements is created!" << std::endl;
							}
							else std::cout << "Elements doesn't created!" << std::endl;

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
							presentation[0]->getSlides()[currentSlideIndex - 1]->SetBackgroundColor(selectedColor);
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
					if (currentSlideIndex > 1) {
						currentSlideIndex--; // Переход на предыдущий слайд
						std::cout << "Switch to previous slide. Current slide: " << currentSlideIndex << std::endl;
					}
				}
				else if (event.key.code == Keyboard::D) {
					if (presentation != nullptr) {
						int totalSlides = presentation[0]->getSlideCount();
						if (currentSlideIndex < totalSlides) {
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
			if (slides != nullptr && currentSlideIndex > 0 && currentSlideIndex <= presentation[0]->getSlideCount()) {
				window.draw(slides[currentSlideIndex - 1]->getBackground());
			}
		}


		if (isColorPickerActive) {
			window.draw(colorPickerDialog);
			for (int i = 0; i < 36; ++i) {
				window.draw(colorRectangles[i]);
			}
		}

		window.display();
	}
}

