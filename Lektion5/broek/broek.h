#ifndef BROEK_H
#define BROEK_H
#include <iostream>



class Broek{

public:
  
  Broek();
  Broek(int taeller, int naevner);
  
  void forkortBroek(int input_taeller,int input_naevner,int& output_taeller, int& output_naevner);
  int getTaeller();
  int getNaevner();
  Broek adder(Broek b);
  Broek subtraher(Broek b);
  Broek multiplicer(Broek b);
  Broek divider(Broek b);
  Broek operator+(Broek b);
  Broek operator-(Broek b);
  Broek operator*(Broek b);
  Broek operator/(Broek b);
private:
  int taeller;
  int naevner;

};
#endif // !BROEK_H
