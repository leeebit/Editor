#include "GraphicEditor.h"
#include "Button.h"
#include <vector>
using namespace sf;

GraphicEditor::GraphicEditor(){}

<<<<<<< HEAD
GraphicEditor::~GraphicEditor() {
	asdgit commi
}
=======
GraphicEditor::~GraphicEditor() {}
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6

void GraphicEditor::CreatePresentation() {
	Presentation* newPresentation = new Presentation();
	presentations.push_back(newPresentation);
	presentationCount = presentations.size() - 1;
	currentSlideIndex = 0;
	std::cout << "Presentation created. Total presentations: " << presentations.size() << std::endl;
}

<<<<<<< HEAD
bool GraphicEditor::on_click_Button1() {

=======
bool GraphicEditor::on_presentation_clicked()
{
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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

<<<<<<< HEAD
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
=======
#include "GraphicEditor.h"
#include <iostream>

void GraphicEditor::handleMouseClickOnElement(sf::Vector2f mousePosition) {
	if (!presentations.empty() && currentSlideIndex >= 0) {
		Presentation* currentPresentation = presentations[presentationCount];
		if (currentSlideIndex < currentPresentation->getSlides().size()) {
			Slide* currentSlide = currentPresentation->getSlides()[currentSlideIndex];
			std::vector<Elements*>& elements = currentSlide->getElements();
			if (!elements.empty()) {
				for (int i = elements.size() - 1; i >= 0; i--) {
					if (elements[i]->getBounds().contains(mousePosition)) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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

<<<<<<< HEAD
bool onCreatePresClicked()
{
	std::cout << "I got called!\n";
	return true;
}
=======
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6

void GraphicEditor::App(sf::RenderWindow& window) {

	RectangleShape Menu(Vector2f(1024, 50));
	Menu.setFillColor(Color(223, 226, 219));
	Menu.setPosition(0, 0);

	Font font;
	if (!font.loadFromFile("DMSerifDisplay-Regular.ttf")) {
		std::cerr << "Error font load!\n";
	}

	//std::vector<Button> buttons;

	Text createPresentationText("Create presentation", font, 15);
	createPresentationText.setFillColor(Color::Black);
	createPresentationText.setPosition(20, 20);
	//buttons.push_back(Button((IntRect)createPresentationText.getGlobalBounds(), sf::Color::Black, &on_presentation_clicked));

<<<<<<< HEAD
	std::vector<Button> buttons;
	Button createPresButton((IntRect)createPresentationText.getGlobalBounds(), sf::Color::Red, onCreatePresClicked);

	buttons.push_back(createPresButton);
	Text createSlideText("Create slide", font, 20);
=======
	Text createSlideText("Create slide", font, 15);
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
	createSlideText.setFillColor(Color::Black);
	createSlideText.setPosition(170, 20);

	Text deleteSlideText("Delete slide", font, 15);
	deleteSlideText.setFillColor(Color::Black);
	deleteSlideText.setPosition(270, 20);

	Text changeElementText("Change element", font, 15);
	changeElementText.setFillColor(Color::Black);
	changeElementText.setPosition(370, 20);

	Text createElementText("Create element", font, 15);
	createElementText.setFillColor(Color::Black);
	createElementText.setPosition(490, 20);

	Text deleteElementText("Delete element", font, 15);
	deleteElementText.setFillColor(Color::Black);
	deleteElementText.setPosition(610, 20);
	window.draw(Menu);

	sf::RectangleShape colorPickerDialog(sf::Vector2f(1024, 50));
	colorPickerDialog.setFillColor(sf::Color::White);
	colorPickerDialog.setOutlineColor(sf::Color::Black);
	colorPickerDialog.setOutlineThickness(1.f);
	colorPickerDialog.setPosition(0, 60);
	window.draw(colorPickerDialog);

	sf::RectangleShape createElementWindow(sf::Vector2f(1024, 50));
	createElementWindow.setFillColor(sf::Color::White);
	createElementWindow.setOutlineColor(sf::Color::Black);
	createElementWindow.setOutlineThickness(1.f);
	createElementWindow.setPosition(0, 60);
	window.draw(createElementWindow);

	sf::Text circleButton("Circle", font, 15);
	circleButton.setFillColor(sf::Color::Black);
	circleButton.setPosition(20, 70);
	window.draw(circleButton);

	sf::Text squareButton("Square", font, 15);
	squareButton.setFillColor(sf::Color::Black);
	squareButton.setPosition(80, 70);
	window.draw(squareButton);

	sf::Text triangleButton("Triangle", font, 15);
	triangleButton.setFillColor(sf::Color::Black);
	triangleButton.setPosition(150, 70);
	window.draw(triangleButton);

	sf::Text imageButton("Image", font, 15);
	imageButton.setFillColor(sf::Color::Black);
	imageButton.setPosition(220, 70);
	window.draw(imageButton);

	sf::RectangleShape createElementPropertiesWindow(sf::Vector2f(1024, 50));
	createElementPropertiesWindow.setFillColor(sf::Color::White);
	createElementPropertiesWindow.setOutlineColor(sf::Color::Black);
	createElementPropertiesWindow.setOutlineThickness(1.f);
	createElementPropertiesWindow.setPosition(0, 60);
	window.draw(createElementPropertiesWindow);

	sf::Text colorFillButton("Fill Color", font, 15);
	colorFillButton.setFillColor(sf::Color::Black);
	colorFillButton.setPosition(20, 70);
	window.draw(colorFillButton);

	sf::Text outlineFillButton("Fill Color Outline", font, 15);
	outlineFillButton.setFillColor(sf::Color::Black);
	outlineFillButton.setPosition(110, 70);
	window.draw(outlineFillButton);

	//������� ������
	int colorRectSize = 20;
	int padding = 7;
	int colorsPerRow = (1024 - padding) / (colorRectSize + padding);

	for (int i = 0; i < 36; ++i) {
		colorRectangles[i] = sf::RectangleShape(sf::Vector2f(colorRectSize, colorRectSize));
		int x = i % colorsPerRow;
		int y = i / colorsPerRow;
		colorRectangles[i].setPosition(colorPickerDialog.getPosition().x + padding + x * (colorRectSize + padding), colorPickerDialog.getPosition().y + padding + y * (colorRectSize + padding));
		colorRectangles[i].setFillColor(colors[i]);

	}
	bool isColorOutlinerClicked = false;
	bool isColorFillButtonClicked = false;
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
					std::cout << "Mouse coords: " << mousePos.x << " " << mousePos.y << "\n";
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

<<<<<<< HEAD
							currentSlideIndex = (presentations)[presentationCount]->CreateSlideAtIndex(currentSlideIndex); // ������� �����
							std::cout << currentSlideIndex << std::endl;
=======
							currentSlideIndex = presentations[presentationCount]->CreateSlide(); // ������� �����
							std::cout << "Slide is created" << std::endl;
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
						}
						else std::cout << "Slide doesn't created!" << std::endl;
					}
					else if (createElementText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Create Elements!" << std::endl;
<<<<<<< HEAD
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
							isCreateElementMenuActive = true;
						}

					}
					else if (changeElementText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						std::cout << "Clicked Change Elements!" << std::endl;
<<<<<<< HEAD
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount() && selectedElement != nullptr) {
=======
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size() && selectedElement != nullptr) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
						else if (imageButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
							isElementTypeChosen = true;
							chosenElementType = IMAGE;
							isCreateElementMenuActive = false;
						}
					}
					 
					else if (isElementTypeChosen) {
						sf::Vector2i mousePos = sf::Mouse::getPosition(window);
						sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePos);
						// ��������� ����� �� ������ ��� �������� �������� ���������� ����
<<<<<<< HEAD
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
							if (colorFillButton.getGlobalBounds().contains(mousePos))
								isColorFillButtonClicked = true;
							else if (outlineFillButton.getGlobalBounds().contains(mousePos))
								isColorOutlinerClicked = true;
							isColorPickerActive = true;
							isChangeElementPropertiesMenuActive = false;// ��������� ���� ������� ������
						}
					}

					else if (deleteSlideText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						if (!presentations.empty()) {
							std::cout << "Clicked Delete Slide!" << std::endl;
<<<<<<< HEAD
							currentSlideIndex = (presentations)[presentationCount]->DeleteSlideAtIndex(currentSlideIndex);
							std::cout << currentSlideIndex << std::endl;
=======
							currentSlideIndex = (presentations)[presentationCount]->DeleteSlide();
							if (currentSlideIndex > 0) {
								currentSlideIndex--; 
							}
							std::cout << "Slide is deleted" << std::endl;
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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

<<<<<<< HEAD
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
						if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
							if(currentSlideIndex != -1){
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (currentSlide->getChosenColorIndexElement() != -1 && selectedElement != nullptr) {
								sf::Color selectedColor = colorRectangles[currentSlide->getChosenColorIndexElement()].getFillColor();
								Elements* currentElement = currentSlide->getCurrentElement();
								std::cout << colorFillButton.getGlobalBounds().contains(mousePos) << " "
									<< outlineFillButton.getGlobalBounds().contains(mousePos) << "\n";
								if (isColorFillButtonClicked) {
									currentElement->setfillColorFigure(selectedColor);
								}
								else if (isColorOutlinerClicked) {
									currentElement->setfillColorOutlineFigure(selectedColor);
								}
								
								isColorPickerActive = false;
								isColorOutlinerClicked = false;
								isColorFillButtonClicked = false;
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
<<<<<<< HEAD
								for (int i = 0; i < (presentations)[presentationCount]->getSlideCount(); i++) {
=======
								for (int i = 0; i < (presentations)[presentationCount]->getSlides().size(); i++) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
<<<<<<< HEAD
						int totalSlides = (presentations)[presentationCount]->getSlideCount();
=======
						int totalSlides = (presentations)[presentationCount]->getSlides().size();
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
						if (currentSlideIndex < totalSlides - 1) {
							selectedElement = nullptr;
							currentSlideIndex++; // ������� �� ��������� �����
							std::cout << "Switch to next slide. Current slide: " << currentSlideIndex << std::endl;
						}
					}
				}
				else if (event.key.code == Keyboard::Up) {
<<<<<<< HEAD
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
<<<<<<< HEAD
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
<<<<<<< HEAD
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
<<<<<<< HEAD
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
<<<<<<< HEAD
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
						if (currentSlideIndex != -1) {
							Slide* currentSlide = (presentations)[presentationCount]->getSlides()[currentSlideIndex];
							if (selectedElement != nullptr) {
								selectedElement->resizeElements(10);
							}
						}
					}
				}
				else if (event.key.code == Keyboard::S) {
<<<<<<< HEAD
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlideCount()) {
=======
					if (!presentations.empty() && currentSlideIndex >= 0 && currentSlideIndex < (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
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
<<<<<<< HEAD
					for (int i = 0; i < (presentations)[presentationCount]->getSlideCount(); i++) {
=======
					for (int i = 0; i < (presentations)[presentationCount]->getSlides().size(); i++) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
						slides[i]->Draw(window);
					}
				}
			}

			if (!presentations.empty()) {
				std::vector<Slide*>slides = (presentations)[presentationCount]->getSlides();
<<<<<<< HEAD
				if (!slides.empty() && currentSlideIndex >= 0 && currentSlideIndex <= (presentations)[presentationCount]->getSlideCount()) {
=======
				if (!slides.empty() && currentSlideIndex >= 0 && currentSlideIndex <= (presentations)[presentationCount]->getSlides().size()) {
>>>>>>> a47f3146666a9864194108bdc35908460ab38ae6
					window.draw(slides[currentSlideIndex]->getBackground());

					std::vector<Elements*>& elements = slides[currentSlideIndex]->getElements();
					if (!elements.empty()) {
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
				window.draw(imageButton);
			}

			if (isChangeElementPropertiesMenuActive) {
				window.draw(createElementPropertiesWindow);
				window.draw(colorFillButton);
				window.draw(outlineFillButton);
			}
			window.display();
		}
	}