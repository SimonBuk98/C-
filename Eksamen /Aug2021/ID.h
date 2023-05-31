#pragma once
#include <iostream>
#include <string>
#include "Person.h"

class ID
{
private:
    
public:
    virtual bool compareTo(Person p)=0;
};
