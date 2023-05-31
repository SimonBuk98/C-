#include "CD.h"
#include <string>

CD::CD(std::string _artist, std::string _album, int _year): artist(_artist), album(_album), year(_year){}

std::string CD::getInfo(){
    return artist + ": "+ album + "("+ std::to_string(year) + ")";
}