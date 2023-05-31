#include "Allvaluables.h"


Allvaluables::Allvaluables(){}


void Allvaluables::add(Valuable &name){
    all.push_back(&name);
}

int Allvaluables::getValue(){
    int sum=0;
    for(int i= 0; i<all.size(); i++){
        sum += all[i]->getValue();
    }
    return sum;
}

void Allvaluables::printAll(){
    for(int i =0; i<all.size(); i++){
        std::cout << all[i]->getName() <<", " <<all[i]->getValue() << std::endl;
    }
    std::cout << "Total: "<< getValue() << std::endl;

}