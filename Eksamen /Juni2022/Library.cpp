#include "Library.h"
#include <string>
#include <iostream>
#include <vector>

Library::Library() {}

void Library::add(Work *work)
{
    works.push_back(work);
}

void Library::searchLibrary(std::string s)
{
    bool noworks = true;
    std::cout << "Search results for " << s << std::endl;
    ;
    for (int i = 0; i < works.size(); i++)
    {
        if ((works[i]->getInfo().find(s) != std::string::npos) && works[i]->Home())
        {
            std::cout << works[i]->getInfo() << std::endl;
            ;
            noworks = false;
        }
    }
    if (noworks)
    {
        std::cout << "No available works" << std::endl;
    }
}