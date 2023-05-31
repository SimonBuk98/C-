#include "Slide.h"
#include <string>
#include <vector>

Slide::Slide(std::string _title, std::vector<std::string> _bullets): title(_title), bulltes(_bullets){}

std::string Slide::getTitle(){
    return title; 
}

std::vector<std::string> Slide::getBullets(){
    return bulltes;
}