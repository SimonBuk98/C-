#include "AdcencedSlide.h"



AdcencedSlide::AdcencedSlide(std::string title, std::vector<std::string> bullets, std::string _marker):Slide(title,bullets), marker(_marker){}

std::string AdcencedSlide::getMarker(){
    return marker;
}

std::string AdcencedSlide::getTitle(){
    return "---" + Slide::getTitle() + "---";
}

std::vector<std::string> AdcencedSlide::getBullets(){
    std::vector<std::string> orig = Slide::getBullets();
    std::vector<std::string> newBullets;
    for(std::string s: orig){
        newBullets.push_back(marker+ " "+ s);
    }
    return newBullets;
}

