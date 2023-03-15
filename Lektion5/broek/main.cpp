#include <iostream>
#include <string>
#include "broek.h"



int main(){
	Broek b(6,12);
  Broek b1(5,8);
  Broek b2(11,9);

  b2 = b + b1;
  std::cout << b2.getTaeller() << std::endl;
  std::cout << b.adder(b1).getTaeller()<<"/" << b.adder(b1).getNaevner() << std::endl;
  std::cout << b.subtraher(b1).getTaeller()<<"/" << b.subtraher(b1).getNaevner() << std::endl;
  std::cout << b.multiplicer(b1).getTaeller()<<"/" << b.multiplicer(b1).getNaevner() << std::endl;
  std::cout << b.divider(b1).getTaeller()<<"/" << b.divider(b1).getNaevner() << std::endl;


 }
