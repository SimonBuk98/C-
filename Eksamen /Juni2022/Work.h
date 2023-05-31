#pragma once 
#include <iostream>
#include <string>
#include <vector>


class Work
{
private:
    bool isHome;
public:
    Work();
    bool Home();
    virtual std::string getInfo();
    void borrow();    
};
