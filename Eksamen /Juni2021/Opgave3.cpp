#include <iostream>
#include <string>
#include <vector>


bool isPalindrom(std::string s){
    for(int i = 0; i<s.size(); i++ ){
        if(s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true; 
}


std::vector<std::string> palindromList(std::string s){
    std::vector<std::string> vec;
    std::string word = "";
    for(int i = 0; i<=s.size(); i++){
        if(s[i]!=' '){
            word += s[i];
        }else if(isPalindrom(word)){
            vec.push_back(word);
            word = "";
        }else{
            word="";
        }
    }
    return vec;
}


int main(){
    std::string s = "radar handle machine racecar kayak jetplane";
    std::vector<std::string> result = palindromList(s);
    for(int i =0; i <result.size(); i++){
        std::cout << result[i] << std::endl;
    }
    return 0;
}