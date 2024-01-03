#pragma once
#include "Slide.h"
#include <iostream>
class Presentation
{
	private:
	Slide** slides;
	int slideCount;
	public:
		Presentation();
		~Presentation();
		int CreateSlide();
		int CreateSlideAtIndex(int index);
		void DeleteSlide();
		int DeleteSlideAtIndex(int index);
		Slide** getSlides(); // Геттер для slides
		int getSlideCount() const {
			return slideCount;
		}
		
};

