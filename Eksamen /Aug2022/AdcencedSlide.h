#pragma once
#include "Slide.h"
#include <string>
#include <vector>
#include <iostream>
class AdcencedSlide: public Slide
{
private:
    std::string marker;
public:
    AdcencedSlide(std::string title, std::vector<std::string> bullets, std::string marker);
    std::string getMarker();
    virtual std::string getTitle() override;
    virtual std::vector <std::string> getBullets() override;
};
