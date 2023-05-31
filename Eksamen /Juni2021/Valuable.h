#pragma once
#include <iostream>
#include <string>

class Valuable
{
public:
    Valuable(std::string name, double value);
    virtual double getValue();
    std::string getName();

private:
    std::string name;
    double value;
};
