#include <iostream>
#include <cmath>
#include <string>  

int getYear(int x){
	int year= x/10000;
	return year;
}

int getMonth(int x){
	int month = (x/100)-((x/10000)*100);
	return month;
}

int getDay(int x){
	int day = x-(x/100)*100;
	return day;
}

int getQuater(int x){
	int quater = 0;
	if(getMonth(x)%3==0){
	quater = (((x/100)-((x/10000)*100))/3);
	} else{
	quater = (((x/100)-((x/10000)*100))/3)+1;
	}
	return quater;
}

int print(int x){
	return x;
}

bool isLeapYear(int x){
	bool LeapYear;
	if( (getYear(x)%4==0 && getYear(x)%100==0) || (getYear(x)%4==0 && getYear(x)%100==0 && getYear(x)%400==0)){
		LeapYear=true;
	}else{
		LeapYear=false;
	}
	return LeapYear;
}

bool isValid(int x){
	bool Valid;
	if( (x>=17000301 && x<=99999999) ){
		switch(getMonth(x)){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12: if(getDay(x)<32 && getDay(x)!=0) {Valid=true;}else{Valid=false;} break;
			case 2: if((getDay(x)<28 && getDay(x)!=0)|| (isLeapYear(x)&& getDay(x)<30 && getDay(x)!=0)) {Valid=true;}else{Valid=false;} break;
			case 4: case 6: case 9: case 11: if(getDay(x)<31 && getDay(x)!=0) {Valid=true;} else{Valid=false;} break;
		}
	}else{
		Valid = false;
	}
	return Valid;
}

int incrementDate(int x){
	bool increment = true;
	int date = x ;
	while(increment){
		date = date+1;
		if(isValid(date)==true){
			increment = false;
		}else {
		  increment = true;
		}
	}
	return date;
}

int diffenceInDays(int x1, int x2){
	int count=1;
	
	while(x1 != x2){
		count=count + 1;
		x1 = incrementDate(x1);
	}
	return count;
}

int dayOfTheYear(int x){
	int date;
	std::string str = std::to_string(getYear(x))+std::to_string(0)+std::to_string(getMonth(19980101))+std::to_string(0)+std::to_string(getDay(19980101));
	date = stoi(str);

	return diffenceInDays(date,x);
}

int weekday(int x ){
	int yearcode = ((getYear(x)%100)+((getYear(x)%100)/4))%7;
	int monthcode;
	int centrycode;
	int leapyearcode;
	int weekdays[]={0,1,2,3,4,5,6};
	
	switch(getMonth(x)){
		case 1: monthcode =0; break;
		case 2: monthcode =3; break;
		case 3: monthcode =3; break;
		case 4: monthcode =6; break;
		case 5: monthcode =1; break;
		case 6: monthcode =4; break;
		case 7: monthcode =6; break;
		case 8: monthcode =2; break;
		case 9: monthcode =5; break;
		case 10: monthcode =0; break;
		case 11: monthcode =3; break;
		case 12: monthcode =5; break;
	}
		switch(getYear(x)/100){
		case 17: centrycode =4; break;
		case 18: centrycode =2; break;
		case 19: centrycode =0; break;
		case 20: centrycode =6; break;
		case 21: centrycode =4; break;
		case 22: centrycode =2; break;
		case 23: centrycode =0; break;
	
	}
	if(getMonth(x)==1|| getMonth(x)==2){
		leapyearcode=0;
	
	}else if(isLeapYear(x)){
		leapyearcode=1;
	}else{
		leapyearcode = 0;
	}
	return (yearcode + monthcode + centrycode + getDay(x) - leapyearcode)%7;
}

std::string weekdayAsText(int x){
	int index;
	std::string week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	
	index = weekday(x);
	
	return week[index];
}



int main(){
	int x;
	int x1;
	std::string str;
	bool start = true;
	bool valid = true;
	std::cout << "Type a Dato YYYYMMDD: ";
	std::cin  >> x;
	
	while(valid){
		if(isValid(x)==true){
			break;
		}else {
			std::cout << "Not a valid dato, try a new dato YYYYMMDD: ";
			std::cin  >> x;
		}
	}
	
	while(start){
	std::cout << "Year: "+ std::to_string(getYear(x)) << std::endl;
	std::cout << "Month: " + std::to_string(getMonth(x)) << std::endl;
	std::cout << "Day: "+ std::to_string(getDay(x)) << std::endl;
	std::cout << "Quater: "+ std::to_string(getQuater(x)) << std::endl;
	std::cout << "Dato: "+ std::to_string(print(x)) << std::endl;
	std::cout << "Is it a LeapYear: "+ std::to_string(isLeapYear(x)) << std::endl;
	std::cout << "The date after: "+ std::to_string(incrementDate(x)) << std::endl;
	std::cout << "Do want do get the diffence in days between your date and another? (Y/N)";
	std::cin  >> str;
	
  if(str=="y"){
		std::cout << "Type another Dato YYYYMMDD: ";
    std::cin  >> x1;
	
    while(valid){
	    if(isValid(x1)==true){
	      break;
	    }else {
		    std::cout << "Not a valid dato, try a new dato YYYYMMDD: ";
		    std::cin  >> x1;
		  }
	  }
  std::cout << "Diffence in days: " + std::to_string(diffenceInDays(x,x1)) << std::endl;
	}

  std::cout << "Day of the Year: " + std::to_string(dayOfTheYear(x)) << std::endl;
	std::cout << "Weekday: " + weekdayAsText(x) << std::endl;
	std::cout << "Do you want to type another dato? (Y/N): ";
	std::cin >> str;
	if(str=="y"){
		std::cout << "Type a new Dato YYYYMMDD: ";
		std::cin  >> x;
		
		while(valid){
		if(isValid(x)==true){
			break;
		}else {
			std::cout << "Not a valid dato, try a new dato YYYYMMDD: ";
			std::cin  >> x;
		}
	}
	}else {
		start=false;
	}
	}
	return 0;
}
