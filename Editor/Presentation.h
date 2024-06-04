#pragma once
#include "Slide.h"
#include <vector>
class Presentation
{
private:
	std::vector<Slide*> slides;
	int slideCount;
public:
	Presentation();
	~Presentation();
	int CreateSlide();
	int CreateSlideAtIndex(int index);
	void DeleteSlide();
	int DeleteSlideAtIndex(int index);
	std::vector<Slide*> getSlides(); // Геттер для slides
	int getSlideCount() const {
		return slideCount;
	}
	Slide* getOneSlide(int index) {
		return slides[index];
	}

};

