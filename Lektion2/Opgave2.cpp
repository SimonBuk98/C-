#include <iostream>

int main(int argc, char** argv){
	int x;
	std::cout << "Skriv din alder: ";
	std::cin >> x;
	
	for(int i = 1; i<=x; i++){
		std::cout << std::to_string(i) << std::endl;
	}
	
	int i=1;
	while(i<=x){
		std::cout << std::to_string(i) << std::endl;
		i++;
	}
	for(int i = 1; i<=x; i++){
		if(i%2==0){
		std::cout << std::to_string(i) << std::endl;
		}
	}
	
	int A[]={1,2,3,4,5,6,7,8,9,10};
	for(int i=0; i < sizeof(A) / sizeof(int); i++){
		std::cout << std::to_string(A[i]) << std::endl;
	}
	return 0; 
}
