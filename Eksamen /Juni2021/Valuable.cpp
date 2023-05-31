#include "Valuable.h"


Valuable::Valuable(std::string _name, double _value){
    name = _name;
    value = _value;
}

std::string Valuable::getName(){
    return name;
}

double Valuable::getValue(){
    return value; 
}
