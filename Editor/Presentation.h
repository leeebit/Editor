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
		void DeleteSlide();
		int DeleteSlideAtIndex(int index);
		Slide** getSlides(); // ������ ��� slides
		int getSlideCount() const {
			return slideCount;
		}
		
};
