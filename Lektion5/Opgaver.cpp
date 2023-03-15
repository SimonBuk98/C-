#include <iostream>
#include <string>
#include <cmath>
#include <vector>



void tal(int x){
  int sum=0;
std::string number = std::to_string(x);
for(int i=0; i < number.length(); i++){
    sum+=pow(std::stoi(number.substr(i,1)),i+1);
  if(sum == x ){
    std::cout << sum << std::endl;
  }
}
}

bool neighbors(std::string s){
  bool neighbor=false;
  std::string x="abcdefghijklmnopqrstuvwxyz";
  
  for(int i=1; i < x.length(); i++){
    for(int j=1; j < s.length();j++){
      if(s.substr(j,2) == x.substr(i,2)){
        neighbor = true;
        break;
      }
    }
  }
    return neighbor;
}

bool sumOfTwoEqualsThird(std::vector<int> vec){
  bool equals=false ;
  for(int i=0; i <vec.size(); i++ ){
    for(int j=0; j<vec.size(); j++){
      for(int k=0; k<vec.size(); k++){
        int sum = 0;
        sum= vec[i]+vec[j];
        if(sum == vec[k]){
          equals=true;
          break;
        }
      }
    }
  }
  return equals;
}


void forkortbroek(int input_taeller, int input_naevner, int& output_taeller, int& output_naevner){
  
  for(int i =2; i<=9; i++){
    if(input_taeller%i==0 && input_naevner%i==0){
      output_taeller = input_taeller/i;
      output_naevner = input_naevner/i;
    }
  }

  std::cout << output_taeller<< "/" << output_naevner << std::endl;
}


int main(){
int x;
int y;

  std::cout << neighbors("acasdfdasfdasf") << std::endl;  

  std::cout << sumOfTwoEqualsThird({17,29,512,58,43})<< std::endl;
 
  forkortbroek(8,12,x,y);
}
