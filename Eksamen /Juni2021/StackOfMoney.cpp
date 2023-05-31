#include "StackOfMoney.h"

StackOfMoney::StackOfMoney(std::string _name, int _value, ExchangeRate &_krus): Valuable(_name, _value), krus(_krus){}

double StackOfMoney::getValue(){
    return Valuable::getValue()*krus.getKurs()/100;
}