#pragma once
#include <iostream>
#include <string>

class Person
{
private:
    std::string name;
    std::string address;

public:
    Person(std::string _name, std::string _address);
    std::string getName();
    std::string getAddress();
    void changeAddress(std::string newAddress);
};

Person::Person(std::string _name, std::string _address) : name(_name), address(_address) {}
std::string Person::getName()
{
    return name;
}
std::string Person::getAddress()
{
    return address;
}
void Person::changeAddress(std::string newAddress)
{
    address = newAddress;
}