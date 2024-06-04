#include "Presentation.h"
Presentation::Presentation() {
   
}

Presentation::~Presentation() {
 
}

int Presentation::CreateSlide() {
    Slide* newSlide = new Slide();
    slides.push_back(newSlide);
    return slides.size() - 1;
}

int Presentation::CreateSlideAtIndex(int index) {
    if (index >= 0 && index <= slides.size()) {
        Slide* newSlide = new Slide();
        slides.insert(slides.begin() + index, newSlide);
        return index;
    }
    return -1; // Invalid index
}

void Presentation::DeleteSlide() {
    if (!slides.empty()) {
        delete slides.back();
        slides.pop_back();
    }
}

int Presentation::DeleteSlideAtIndex(int index) {
    if (index >= 0 && index < slides.size()) {
        delete (slides)[index];
        slides.erase(slides.begin() + index);
        return index;
    }
    return -1; // Invalid index
}

std::vector<Slide*> Presentation::getSlides() {
    return slides;
}