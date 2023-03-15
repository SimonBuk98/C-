#include <iostream>
#include <cmath>

bool isPrime(int x){
	
	if(x<=1){
		return false; 
	}
	
	for(int i=2; i <= sqrt(x); i++){
		if(x % i==0){
			return false;
		}else{
			return true; 
		}
	}
	return 0;
}


int main(int argc, char** argv){
	int x; 
	std::cout << "Skriv et tal";
	std::cin >> x;
	int i = x;
	while(x>=i){
		std::cout << "Skriv et ny tal! (Hvis tal er mindre en tidliger vil det stoppe): " << std::endl;
		std::cin >> x;
	}
}
