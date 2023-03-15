#include <iostream>
using namespace std;

void printResult(string text, float result ){
	cout << text + ": " + to_string(result)<< endl; 
}

int main(){
	int a = 3; 
	float b=3;
	int c = 10;
	int d = 123;
	
	printResult("hej",27.5);
	printResult("Opgave 1",a+b);
	printResult("Opgave 2", c/a);
	printResult("Opgave 3", c/b);
	printResult("Opgave 4", b*c/a);
	printResult("Opgave 5", c/a*b);
	printResult("Opgave 6", c%a);
	printResult("Opgave 7", d/100);
	printResult("Opgave 8", d%100);
	return 0;
}

