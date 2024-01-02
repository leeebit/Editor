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
        std::cout << "Slide is created!" << std::endl;
	}
	else {
		//������������� ������ �� +1;
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

void Presentation::DeleteSlide() {
    if (slides != nullptr) {
        for (int i = 0; i < slideCount; ++i) {
            if (slides[i] != nullptr) {
                delete slides[i];
                slides[i] = nullptr; // ������������� ��������� � nullptr ����� ��������
            }
        }
        delete[] slides;
        slides = nullptr;
        slideCount = 0;
    }

}

int Presentation::DeleteSlideAtIndex(int index) {
    if (slides != nullptr && index >= 0 && index < slideCount) {
        delete slides[index]; // ������� ����� �� ���������� �������
        slides[index] = nullptr;

        // ������� ������ ����� ���������� �� ���� ������� �����
        for (int i = index; i < slideCount - 1; ++i) {
            slides[i] = slides[i + 1];
        }

        slides[slideCount - 1] = nullptr; // ������� ��������� �����
        slideCount--;
    }

    return slideCount;
}


