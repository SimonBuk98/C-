#pragma once
#include <iostream>
#include <vector>
#include "Slide.h"

class SlideShow
{
private:
    std::vector<Slide*> slides;
public:
    SlideShow();
    void add(Slide &s);
    void printSlideShow();

};
