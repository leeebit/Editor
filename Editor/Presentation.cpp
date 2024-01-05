#include "Presentation.h"
Presentation::Presentation() {
	slides = nullptr;
    slideCount = 0;
}

Presentation::~Presentation() {
    DeleteSlide();
}

Slide** Presentation::getSlides() {
	return slides;
}

int Presentation::CreateSlide() {
	if (!slides) {
		slides = new Slide * [1];
		slides[0] = new Slide();
        //std::cout << "Slide is created!" << std::endl;
	}
	else {
		//перевыделение памяти на +1;
        Slide** temp = new Slide * [slideCount + 1];
        for (int i = 0; i < slideCount; ++i) {
            temp[i] = slides[i];
        }
        temp[slideCount] = new Slide();
        delete[] slides;
        slides = temp;
    }
    slideCount++;
    
    return slideCount;

}

int Presentation::CreateSlideAtIndex(int index)
{
    if (!slides) {
        slides = new Slide * [1];
        slides[0] = new Slide();
        index--;
       // std::cout << "Slide is created!" << std::endl;
    }
    else {
        Slide** temp = new Slide * [slideCount + 1];
        int i;
        for (i = 0; i <= slideCount; ++i) {
            if (i == index + 1)
            {
                temp[i] = new Slide();
                break;
            }
            else
                temp[i] = slides[i];
        }
        for (; i < slideCount; ++i)
            temp[i + 1] = slides[i];
        delete[] slides;
        slides = temp;
    }
    slideCount++;

    return index+1;
}


void Presentation::DeleteSlide() {
    if (slides != nullptr) {
        for (int i = 0; i < slideCount; ++i) {
            if (slides[i] != nullptr) {
                delete slides[i];
                slides[i] = nullptr; // Устанавливаем указатель в nullptr после удаления
            }
        }
        delete[] slides;
        slides = nullptr;
        slideCount = 0;
    }

}

int Presentation::DeleteSlideAtIndex(int index) {
    if (slides != nullptr && index >= 0 && index < slideCount) {
        delete slides[index];

        for (int i = index; i < slideCount - 1; ++i) {
            if (i != 0)
                slides[i] = slides[i + 1];
        }

        if (slideCount == 1)
        {
            delete[] slides;
            slides = nullptr;
            slideCount = 0;
        }
        else
        {
            slides[slideCount - 1] = nullptr;
            slideCount--;
        }

    }

    if (slideCount > 0)
        return slideCount - 1;
    return slideCount;
}





