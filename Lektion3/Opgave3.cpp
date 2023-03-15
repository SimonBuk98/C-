#include <iostream>



class Vehicle
{
public:
  Vehicle(int n, int p =1000, int e=100 ):wheels(n), price(p), exchangeRate(e) {}
  int getNumberOfWheels(){
    return  wheels; 
  }
  double getPrice(){
    return price*100/exchangeRate;
  }
  void setEcchangeRate(double e){
      exchangeRate = e;
  }

private:
  int wheels;
  double price;
  double exchangeRate;
  
};


int main (int argc, char *argv[])
{
  Vehicle car(4,50000);
  Vehicle bike(2);
  
  std::cout << car.getNumberOfWheels() << std::endl;
  std::cout << bike.getNumberOfWheels() << std::endl;   
  car.setEcchangeRate(693.66);
  bike.setEcchangeRate(693.66);
  std::cout << car.getPrice() << std::endl;
  std::cout << bike.getPrice() << std::endl;
  car.setEcchangeRate(744.40);
  bike.setEcchangeRate(744.40);

  std::cout << car.getPrice() << std::endl;
  std::cout << bike.getPrice() << std::endl;
  car.setEcchangeRate(68.42);
  bike.setEcchangeRate(68.42);
  std::cout << car.getPrice() << std::endl;
  std::cout << bike.getPrice() << std::endl;

  return 0;
}
