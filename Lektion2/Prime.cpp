#include <iostream>
#include <cmath>

bool isPrime(int x){
	bool is_prime = true;
	if(x==0 || x==1){
		return false; 
	}
	
	for(int i=2; i <= (x/2); i++){
		if(x%i==0){
			is_prime =false;
			break;
		}
	}
	return is_prime;
}

void printPrimes(int n){
	for(int i = 0; i<=n; i++){
		if(isPrime(i)){
			std::cout << std::to_string(i) << std::endl; 
		}
	
	}
}

int main(int argc, char** argv){

	printPrimes(23);
	
	return 0;

}
