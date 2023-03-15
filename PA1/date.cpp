#include "date.h"


/* Class definitions */ 
Date::Date(int date){
  x=date; 
  
  if(isValid()==false){
      x=17000301;
  }   
}
int Date::getYear(){
    return x/10000;
}
  
int Date::getMonth(){
    return (x/100)-((x/10000)*100);
}
  
int Date::getDay(){
    return x-(x/100)*100;
}
  
int Date::getQuater(){
	  
  if(getMonth()%3==0){
	    return (((x/100)-((x/10000)*100))/3);
	  }else{
	    return (((x/100)-((x/10000)*100))/3)+1;
	  }
}
  
void Date::print(){
  std::cout << weekdayAsText(weekday()) + " " + std::to_string(getDay()) +"/"+ std::to_string(getMonth()) +"-"+ std::to_string(getYear()) << std::endl; 
}
  
bool Date::isLeapYear() {
    bool leapYear;
  	if( (getYear()%4==0 && getYear()%100!=0) || (getYear()%4==0 && getYear()%100==0 && getYear()%400==0)){
		  leapYear=true;
	  }else{
		  leapYear=false;
	  }
	  return leapYear;
}
  
bool Date::isValid(){
    bool Valid;
	  if( (x>=17000301 && x<=99999999) ){
		  switch(getMonth()){
			  case 1: case 3: case 5: case 7: case 8: case 10: case 12: if(getDay()<32 && getDay()!=0) {Valid=true;}else{Valid=false;} break;
			  case 2: if((getDay()<29 && getDay()!=0)|| (isLeapYear()&& getDay()<30 && getDay()!=0)) {Valid=true;}else{Valid=false;} break;
		  	case 4: case 6: case 9: case 11: if(getDay()<31 && getDay()!=0) {Valid=true;} else{Valid=false;} break;
		  }
	  }else{
		  Valid = false;
	  }
	  return Valid;
}
  
void Date::incrementDate(){
  	bool increment = true;

	  while(increment){
		    x = x+1;
		  if(isValid()==true){
			  increment = false;
		  }else {
		    increment = true;
		  }
	  }
}
  
int Date::differenceInDays(Date future){
  	int count=0;
    Date tempdate(x);

	  while(tempdate.x != future.x){
		  count = count +1;
      tempdate.incrementDate();
      
	  }
    return count;
}
int Date::dayOfTheYear(){
    Date current(x);
    Date reff(getYear()*10000+101);

    if(reff.differenceInDays(current)==0){
      return 1;
    }else {
	    return reff.differenceInDays(current)+1;
    }
}
int Date::weekday(){
    Date start(17000301);

  return (start.differenceInDays(x))%7+1;
}

std::string Date::weekdayAsText(int weekday){
    std::string weekdays[]={"mon","tue","wed","thu","fri","sat","sun"};

    return weekdays[weekday-1];
}
