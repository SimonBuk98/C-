#include "broek.h"



Broek::Broek(int x ,int y){
  taeller= x;
  naevner= y;
  forkortBroek(x,y,taeller,naevner);
}

void Broek::forkortBroek(int input_taeller, int input_naevner,int& output_taeller, int& output_naevner){
   
  for(int i =2; i<=9; i++){
      if(input_taeller%i==0 && input_naevner%i==0){
        output_taeller = input_taeller/i;
        output_naevner = input_naevner/i;
      }
    }
}

int Broek::getTaeller(){
  return taeller;
}

int Broek::getNaevner(){
  return naevner;
}

Broek Broek::adder(Broek broek){
  int a = (taeller*broek.getNaevner())+(naevner*broek.getTaeller());
  int b = naevner*broek.getNaevner();
  Broek newB(a,b);
  return newB;
}

Broek Broek::subtraher(Broek broek){
  int a = (taeller*broek.getNaevner());
  int b = (naevner*broek.getTaeller());
  int c = naevner*broek.getNaevner();
  int d;
  if(a > b ){
    d = a - b;  
  }else{
    d = b -a;
  }
  Broek newB(d,c);
  return newB;
}

Broek Broek::multiplicer(Broek broek){
  int a = taeller*broek.getTaeller();
  int b = naevner*broek.getNaevner();
  Broek newB(a,b);
  return newB;
}

Broek Broek::divider(Broek broek){
  int a = taeller*broek.getNaevner();
  int b = naevner*broek.getTaeller();
  Broek newB(a,b);
  return newB;
}

Broek Broek::operator+(Broek b){
    return adder(b);
  }
Broek Broek::operator-(Broek b){
    return subtraher(b);
  }
Broek Broek::operator*(Broek b){
    return multiplicer(b);
  }
Broek Broek::operator/(Broek b){
    return divider(b);
  }
