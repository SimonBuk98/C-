#include <iostream>
#include <string>



void sort(int *numbers, int length){
    int min;
    int temp; 
     for(int i=0; i < length-1; i++ ){
        min = i;
        for(int j=i+1; j<length; j++){
          if(numbers[j] < numbers[min]){
            min=j;          
          }
        }
        if(min != i){
          temp = numbers[i];
          numbers[i] = numbers[min];
          numbers[min]=temp;
        }
    }
}




int main(){
  int x; 
  int *P = &x;
  *P =25;
  std::cout << x << std::endl;
  int numbers[] = {12,3,67,5,6,0,4,1};

  int size = sizeof(numbers)/sizeof(numbers[0]);
  std::cout << size << std::endl;
  for(int i=0; i < size; i++){
    std::cout << numbers[i] << std::endl;
  }

  sort(numbers, 8);

  for(int i=0; i < size; i++){
    std::cout << numbers[i] << " ";
  }
  return 0;
}
