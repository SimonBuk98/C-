#pragma once
#include "Valuable.h"
#include <iostream>
#include <vector>

class Allvaluables
{
private:
    std::vector<Valuable*> all;    
public:
    Allvaluables();
    void add(Valuable &name);
    int getValue();
    void printAll();
};

