#pragma once
#include "Presentation.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class GraphicEditor {
private:
    Presentation** presentation;
    int presentationCount;
    sf::RectangleShape colorRectangles[36];
    sf::Color colors[36];
    int currentSlideIndex;
    int chosenColorIndex = -1;
    bool isColorPickerActive = false;
   
public:
    GraphicEditor();
    ~GraphicEditor();
   // void DeletePresentation();
    void App(sf::RenderWindow& window);
    int getCurrentSlideIndex();
    void setCurrentSlideIndex(int a);
    void CreatePresentation();
    

};

