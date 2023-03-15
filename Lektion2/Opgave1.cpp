#include <iostream>

int main(int argc, char** argv){
	int x; 
	std::cout << "Indskriv din alder: ";
	std::cin >> x;
	if(x < 16){
		std::cout << "Du er for ung til at køre bil" << std::endl; 
	}else if(x>=16 && x<18){
		std::cout << "Du må køre bil, men er ungkøre!" << std::endl; 
	}else{
		std::cout << "Du må køre bil." << std::endl; 
	}
	return 0;
}


