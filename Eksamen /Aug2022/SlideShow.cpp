#include "SlideShow.h"

SlideShow::SlideShow() {}

void SlideShow::add(Slide &s)
{
    slides.push_back(&s);
}

void SlideShow::printSlideShow()
{
    for (Slide *s : slides)
    {
        std::cout << s->getTitle() << std::endl;
        for (std::string b : s->getBullets())
        {
            std::cout << b << std::endl;
        }
        std::cout << std::endl;
    }
}

