#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<int> binaryStringToIntVector(std::string input){
    std::vector<std::string> bi;
    std::vector<int>numbers;
    int num=0;
    std::string word=""; 
    for(int i =0; i <=input.size(); i++){
        if((input[i]==':')|| (input[i]=='.')||i==input.size()){
            bi.push_back(word);
            word="";
        }else{
            word+= input[i];

        }
    }
    int k =0;
    for(int i = 0; i <bi.size(); i++){
        num=0;
        for(int j = bi[i].size()-1; j>=0; j--){
            if(bi[i][j]=='1'){
            num+=pow(2,k);
            }
            k++;
        }
        if(num!=0){
        numbers.push_back(num);
        }
        k=0;
    }
    return numbers;
}

int main(){
    std::string input="000111010110::010110::10.111101::1111::00010101101";
    std::vector<int> numbers = binaryStringToIntVector(input);

    for(int i = 0; i<numbers.size(); i++){
        std::cout << numbers[i] << std::endl;
    }

}