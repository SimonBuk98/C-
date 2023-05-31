#pragma once
#include <iostream>
#include <vector>
#include "Work.h"

class Library
{
private:
    std::vector<Work*> works;
public:
    Library();
    void add(Work* work);
    void searchLibrary(std::string searchString);

};


