#pragma once
#include <iostream>
#include <string>
#include "ID.h"
#include "Person.h"


class DigitalSS: public ID
{
private:
    Person& p;
public:
    DigitalSS(Person& _p);
    virtual bool compareTo(Person _p) override;
};

DigitalSS::DigitalSS(Person &_p):p(_p)
{
}
bool DigitalSS::compareTo(Person _p){
    return (p.getName() == _p.getName() && p.getAddress() == _p.getAddress());
}