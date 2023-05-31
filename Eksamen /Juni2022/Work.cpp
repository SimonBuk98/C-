#include "Work.h"

Work::Work(): isHome(true ){}

bool Work::Home(){
    return isHome;
}

std::string Work::getInfo(){
    return "";
}

void Work::borrow(){
    isHome = false; 
}