#include "GraphicEditor.h"
#include "Button.h"
#include <vector>
using namespace sf;

GraphicEditor::GraphicEditor(){}

GraphicEditor::~GraphicEditor() {

}

void GraphicEditor::CreatePresentation() {
	Presentation* newPresentation = new Presentation();
	presentations.push_back(newPresentation);
	presentationCount = presentations.size() - 1;
	currentSlideIndex = 0;
	std::cout << "Presentation created. Total presentations: " << presentations.size() << std::endl;
}

bool GraphicEditor::on_click_Button1() {

	if (presentations.empty())
	{
		CreatePresentation();
		std::cout << "Presentation is created!" << std::endl;
		return true;
	}
	std::cout << "Presentation doesn't created!" << std::endl;
	return false;
}

int GraphicEditor::getCurrentSlideIndex() {
	return currentSlideIndex;
}

void GraphicEditor::setCurrentSlideIndex(int a) {
	currentSlideIndex = a;
}

void check_for_buttons(std::vector<Button>& buttons, sf::Vector2i mouse)
{
	for (auto button : buttons)
	{
		if (button.isClicked(mouse)) button.click();
	}
}

void GraphicEditor::handleMouseClickOnElement(sf::Vector2f mousePosition) {
	if (!presentations.empty() && currentSlideIndex >= 0) {
		Presentation* currentPresentation = (presentations)[presentationCount];
		if (currentSlideIndex < currentPresentation->getSlideCount()) {
			Slide* currentSlide = currentPresentation->getSlides()[currentSlideIndex];
			Elements** elements = currentSlide->getElements();
			if (elements != nullptr) {
				for (int i = currentSlide->getElementCount() - 1; i >= 0; i--) {
					FloatRect elementBounds = elements[i]->getBounds();
					if (elementBounds.contains(mousePosition)) {
						selectedElement = elements[i];
						currentSlide->setCurrentElement(selectedElement);
						std::cout << "Current element is: " << i << std::endl;
						break;
					}
				}
			}
		}
	}
}

bool onCreatePresClicked()
{
	std::cout << "I got called!\n";
	return true;
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

	std::vector<Button> buttons;
	Button createPresButton((IntRect)createPresentationText.getGlobalBounds(), sf::Color::Red, onCreatePresClicked);

	buttons.push_back(createPresButton);
	Text createSlideText("Create slide", font, 20);
	createSlideText.setFillColor(Color::Black);
	createSlideText.setPosition(200, 20);

	Text deleteSlideText("Delete slide", font, 20);
	deleteSlideText.setFillColor(Color::Black);
	deleteSlideText.setPosition(320, 20);

	Text changeElementText("ChangeElement", font, 20);
	changeElementText.setFillColor(Color::Black);
	changeElementText.setPosition(500, 20);

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

	sf::Text colorFillButton("Fill Color", font, 20);
	colorFillButton.setFillColor(sf::Color::Black);
	colorFillButton.setPosition(createElementPropertiesWindow.getPosition().x + 20, createElementPropertiesWindow.getPosition().y + 20);
	window.draw(colorFillButton);

	sf::Text outlineFillButton("fill Color Outline", font, 20);
	outlineFillButton.setFillColor(sf::Color::Black);
	outlineFillButton.setPosition(createElementPropertiesWindow.getPosition().x + 20, createElementPropertiesWindow.getPosition().y + 60);
	window.draw(outlineFillButton);
	//������� ������
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
					Vector2f mousePosition = window.mapPixelToCoords(mousePos);
					handleMouseClickOnElement(mousePosition);
					check_for_buttons(buttons, mousePos);
					if (createPresentationText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Presentation!" << std::endl;
						// ������ ��� �������� �����������
						if (presentations.empty()) {
							CreatePresentation();
							std::cout << "Presentation is created!" << std::endl;
						}
						else std::cout << "Presentation doesn't created!" << std::endl;
					}
					else if (createSlideText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Slide!" << std::endl;
						// ������ ��� �������� ������
						if (!presentations.empty()) {

							currentSlideIndex = (presentations)[presentationCount]->CreateSlideAtIndex(currentSlideIndex); // ������� �����
							std::cout << currentSlideIndex << std::endl;
						}
						else std::cout << "Slide doesn't created!" << std::endl;
					}
					else if (createElementText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Elements!" << std::endl;
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
							isCreateElementMenuActive = true;
						}

					}
					else if (changeElementText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Change Elements!" << std::endl;
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount() && selectedElement != nullptr) {
							isChangeElementPropertiesMenuActive = true;
						}
					}
					else if (isCreateElementMenuActive) {
						sf::Vector2i mousePos = sf::Mouse::getPosition(window);
						sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);

						if (circleButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							isElementTypeChosen = true;
							chosenElementType = CIRCLE;
							isCreateElementMenuActive = false;
						}
						else if (squareButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							isElementTypeChosen = true;
							chosenElementType = SQUARE;
							isCreateElementMenuActive = false;
						}
						else if (triangleButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							isElementTypeChosen = true;
							chosenElementType = TRIANGLE;
							isCreateElementMenuActive = false;
						}
					}
					 
					else if (isElementTypeChosen) {
						sf::Vector2i mousePos = sf::Mouse::getPosition(window);
						sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);
						// ��������� ����� �� ������ ��� �������� �������� ���������� ����
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							currentSlide->setElementType(chosenElementType);
							currentSlide->createElements(worldMousePos);
						}
						isElementTypeChosen = false;
					}
					else if (isChangeElementPropertiesMenuActive) {
						Vector2f mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
						if (colorFillButton.getGlobalBounds().contains(mousePos) || outlineFillButton.getGlobalBounds().contains(mousePos)) {
							std::cout << selectedElement << std::endl;
							isColorPickerActive = true;
							isChangeElementPropertiesMenuActive = false;// ��������� ���� ������� ������
						}
					}

					else if (deleteSlideText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						if (!presentations.empty()) {
							std::cout << "Clicked Delete Slide!" << std::endl;
							currentSlideIndex = (presentations)[presentationCount]->DeleteSlideAtIndex(currentSlideIndex);
							std::cout << currentSlideIndex << std::endl;
						}
						else std::cout << "Slide doesn't deleted!" << std::endl;
					}

					else if (isColorPickerActive && event.mouseButton.button == Mouse::Left) {
						Vector2f mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

						// ��������� ������ ����� �� ����������� ����
						for (int i = 0; i < 36; i++) {
							if (colorRectangles[i].getGlobalBounds().contains(mousePos)) {
								if (selectedElement == nullptr)
									chosenColorIndex = i;
								else
									(presentations)[presentationCount]->getSlides()[currentSlideIndex]->setChosenColorIndexElement(i);
								break;

							}
						}

						// ���� ��� ������ ����, ��������� ��� � ������
						if (chosenColorIndex != -1 && currentSlideIndex != -1) {
							sf::Color selectedColor = colorRectangles[chosenColorIndex].getFillColor();
							(presentations)[presentationCount]->getSlides()[currentSlideIndex]->SetBackgroundColor(selectedColor);
							isColorPickerActive = false; // ������� ���������� ���� ����� ������ �����
							chosenColorIndex = -1;
						}
						else
							std::cout << "Background doesn't changed!" << std::endl;

						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
							if(currentSlideIndex != -1){
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (currentSlide->getChosenColorIndexElement() != -1 && selectedElement != nullptr) {
								sf::Color selectedColor = colorRectangles[currentSlide->getChosenColorIndexElement()].getFillColor();
								Elements* currentElement = currentSlide->getCurrentElement();
								//if (colorFillButton.getGlobalBounds().contains(mousePos)) {
									currentElement->setfillColorFigure(selectedColor);
								//}
								//else if (outlineFillButton.getGlobalBounds().contains(mousePos)) {
									currentElement->setfillColorOutlineFigure(selectedColor);
								//}
								
								isColorPickerActive = false;
								currentSlide->setChosenColorIndexElement(-1);
								std::cout << currentElement << std::endl;
							}
							}
						}
						break;
					}
				}
					else if (event.mouseButton.button == Mouse::Right) {
						Vector2i mousePos = Mouse::getPosition(window);
						if (!presentations.empty()) {
							std::vector<Slide*>slides = (presentations)[presentationCount]->getSlides();
							if (!slides.empty()) {
								selectedElement = nullptr;
								for (int i = 0; i < (presentations)[presentationCount]->getSlideCount(); i++) {
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
						selectedElement = nullptr;
						currentSlideIndex--; // ������� �� ���������� �����
						std::cout << "Switch to previous slide. Current slide: " << currentSlideIndex << std::endl;
					}
				}
				else if (event.key.code == Keyboard::D) {
					if (!presentations.empty()) {
						int totalSlides = (presentations)[presentationCount]->getSlideCount();
						if (currentSlideIndex < totalSlides - 1) {
							selectedElement = nullptr;
							currentSlideIndex++; // ������� �� ��������� �����
							std::cout << "Switch to next slide. Current slide: " << currentSlideIndex << std::endl;
						}
					}
				}
				else if (event.key.code == Keyboard::Up) {
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
						if (currentSlideIndex != -1) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (selectedElement != nullptr) {

								Elements* currentElement = currentSlide->getCurrentElement();
								// ����������� �������� ����� (���������� ���������� Y)
								currentElement->moveElements(0, -10);

							}
						}
					}
				}
				else if (event.key.code == Keyboard::Down) {
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
						if (currentSlideIndex != -1) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (selectedElement != nullptr) {
								// ����������� �������� ���� (���������� ���������� Y)
								selectedElement->moveElements(0, 10);
							}
						}
					}
				}
				else if (event.key.code == Keyboard::Left) {
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
						if (currentSlideIndex != -1) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (selectedElement != nullptr) {
								// ����������� �������� ����� (���������� ���������� X)
								selectedElement->moveElements(-10, 0);
							}
						}
					}
				}
				else if (event.key.code == Keyboard::Right) {
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
						if (currentSlideIndex != -1) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (selectedElement != nullptr) {
								// ����������� �������� ������ (���������� ���������� X)
								selectedElement->moveElements(10, 0);
							}
						}
					}
				}
				else if (event.key.code == Keyboard::W) {
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
						if (currentSlideIndex != -1) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (selectedElement != nullptr) {
								selectedElement->resizeElements(10);
							}
						}
					}
				}
				else if (event.key.code == Keyboard::S) {
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
						if (currentSlideIndex != -1) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (selectedElement != nullptr) {
								selectedElement->resizeElements(-10);
							}
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
			window.draw(changeElementText);
			window.draw(deleteSlideText);
			window.draw(createElementText);
			window.draw(deleteElementText);

			// ��������� ���� �������, ���� ��� ����
			if (!presentations.empty()) {
				std::vector<Slide*>slides = (presentations)[presentationCount]->getSlides();
				if (!slides.empty()) {
					for (int i = 0; i < (presentations)[presentationCount]->getSlideCount(); i++) {
						slides[i]->Draw(window);
					}
				}
			}

			if (!presentations.empty()) {
				std::vector<Slide*>slides = (presentations)[presentationCount]->getSlides();
				if (!slides.empty() && currentSlideIndex >= 0 && currentSlideIndex <= (presentations)[presentationCount]->getSlideCount()) {
					window.draw(slides[currentSlideIndex]->getBackground());

					Elements** elements = slides[currentSlideIndex]->getElements();
					if (elements != nullptr) {
						for (int i = 0; i < slides[currentSlideIndex]->getElementCount(); i++) {
							elements[i]->drawElements(window);
						}
					}
				}
			}


			if (isColorPickerActive) {
				window.draw(colorPickerDialog);
				for (int i = 0; i < 36; i++) {
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