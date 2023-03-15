#include <iostream>

class Dato
{
public: 
  
  Dato(int date){
    x= date;  
    
    if(isValid()==false){
      x=17000301;
    }  
  }
  
  int getYear(){
    return x/10000;
  }
  
  int getMonth(){
    return (x/100)-((x/10000)*100);
  }
  
  int getDay(){
    return x-(x/100)*100;
  }
  
  int getQuater(){
	  if(getMonth()%3==0){
	    return (((x/100)-((x/10000)*100))/3);
	  } else{
	    return (((x/100)-((x/10000)*100))/3)+1;
	  }
  }
  
  int print(){
    return x;
  }
  
  bool isLeapYear() {
    bool leapYear;
  	if( (getYear()%4==0 && getYear()%100!=0) || (getYear()%4==0 && getYear()%100==0 && getYear()%400==0)){
		  leapYear=true;
	  }else{
		  leapYear=false;
	  }
	  return leapYear;
  }
  
  bool isValid(){
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
  
  void incrementDate(){
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
  
  int diffenceInDays(Dato future){
  	int count=0;
    Dato tempdate(x);

	  while(tempdate.x != future.x){
		  count = count +1;
      tempdate.incrementDate();
      
	  }
    return count;
  }
  int dayOfTheYear(){
    int date;
    Dato current(x);
	  std::string str = std::to_string(current.getYear())+std::to_string(0)+std::to_string(1)+std::to_string(0)+std::to_string(1);
	  date = stoi(str);
    Dato reff(date);

    if(reff.diffenceInDays(current)==0){
      return 1;
    }else {
	    return reff.diffenceInDays(current)+1;
    }
  }
  int weekday(){
    Dato start(17000301);

    return (start.diffenceInDays(x))%7+1;
  }

  std::string weekdayAsText(){
    int index = weekday();
    std::string weekdays[]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

    return weekdays[index-1];
  }


private:
  int x; 
};

int main (int argc, char *argv[])
{
  Dato d1(17000301);
  Dato d2(19681020);
  Dato d3(99990123);

  std::cout << d2.isLeapYear() <<std::endl;
  std::cout << d1.diffenceInDays(d2) << std::endl;
  std::cout << d2.getDay() << std::endl; 
  std::cout << d2.dayOfTheYear() << std::endl;
  std::cout << d3.weekday() << std::endl;
  std::cout << d3.weekdayAsText() << std::endl; 
  return 0;
}


