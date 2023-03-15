#include <iostream>

int fib(int x){
	int fib=1;
	int sum=0;
	int fsum=0;
	std::cout << std::to_string(fib) << std::endl;
	 for(int i=0; i<x; i++){
	 	sum=fsum+fib;
	 	fsum = fib;
	 	fib=sum;
	 	std::cout << std::to_string(sum) << std::endl;
	 }
	 return 0;
}

int wfib(int x){
	int fib =1;
	int sum=0;
	int fsum=0;
	int i =0;
	std::cout << std::to_string(fib) << std::endl;
	 while(sum<x){
	 	sum=fsum+fib;
	 	fsum = fib;
	 	fib=sum;
	 	std::cout << std::to_string(sum) << std::endl;
	 }
	return 0;
}

int main(int argc, char** argv){
	
	fib(10);
	wfib(100);
	return 0;
}
