#pragma once
#include "Valuable.h"
#include "ExchangeRate.h"
#include <iostream>
#include <string>

class StackOfMoney: public Valuable
{
private:
    ExchangeRate &krus;
public:
    StackOfMoney (std::string name, int value, ExchangeRate &krus);
    virtual double getValue() override;
};

