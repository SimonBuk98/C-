#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

/* Class declaration */
class Date
{
public: 
  Date(int x);
  int getYear();
  int getMonth();
  int getDay();
  int getQuater();
  void print();
  bool isLeapYear();
  bool isValid();
  void incrementDate();
  int differenceInDays(Date future);
  int dayOfTheYear();
  int weekday();
  std::string weekdayAsText(int weekday);

private:
  int x; 
};
#endif
