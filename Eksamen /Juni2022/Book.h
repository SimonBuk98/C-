#pragma once
#include "Work.h"
#include <string>


class Book: public Work
{
private:
    std::string author;
    std::string title;
public:

    Book(std::string author, std::string title);
    virtual std::string getInfo() override; 
};
