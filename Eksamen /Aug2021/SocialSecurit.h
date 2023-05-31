#pragma once
#include <iostream>
#include <string>
#include "ID.h"
#include "Person.h"

class SocialSecurit : public ID
{
private:
    Person p;

public:
    SocialSecurit(Person _p);
    virtual bool compareTo(Person _p) override;
};

SocialSecurit::SocialSecurit(Person _p):p(_p){}

bool SocialSecurit::compareTo(Person _p){
        return p.getName() == _p.getName() && p.getAddress() == _p.getAddress();
}