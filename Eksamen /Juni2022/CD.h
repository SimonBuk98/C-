#pragma once
#include <iostream>
#include <string>
#include "Work.h"

class CD: public Work
{
private:
    std::string artist;
    std::string album;
    int year;
public:
    CD(std::string artist, std::string album, int year);
    virtual std::string getInfo() override;

};
