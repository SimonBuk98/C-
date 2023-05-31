#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ID.h"
#include "Person.h"


class GuestList
{
private:
    std::vector<Person*> vip;
    std::vector<Person*> geust;
public:
    GuestList();
    void addVIP(Person& p);
    void addGuest(Person& p);
    bool isAllowedEntry(Person& p);
    bool isAllowedEntry(ID& id);

};

GuestList::GuestList(){}

void GuestList::addVIP(Person &p){
    vip.push_back(&p);
}
void GuestList::addGuest(Person &p){
    geust.push_back(&p);
}
bool GuestList::isAllowedEntry(Person& p){
    for(Person* v: vip){
        if(v->getName()==p.getName()){
            return true;
        }
    }
    return false; 
}

bool GuestList::isAllowedEntry(ID& id){
    for(Person* v: vip){
        if(id.compareTo(*v)){
            return true;
        }
    }
    for(Person* g : geust){
        if(id.compareTo(*g)){
            return true; 
        }
    }
    return false; 
}