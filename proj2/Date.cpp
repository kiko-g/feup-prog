#include "Date.h"

Date::Date(){}


Date::Date(unsigned short day, unsigned short month, unsigned year)
{
  this->setDay(day);
  this->setMonth(month);
  this->setYear(year);
}

/*********************************
 *          GET Methods
 ********************************/

unsigned short Date::getDay() const
{
  return this->day;
}

  
unsigned short Date::getMonth() const
{
  return this->month;
}
    
unsigned Date::getYear() const
{
  return this->year;
}

/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day)
{
  if(day>31){
    cout << "Invalid Day" << endl;
  }
  else this->day = day;
}

void Date::setMonth(unsigned short month)
{
    if(month>12){
    cout << "Invalid Month" << endl;
  }
  else this->month = month;
}

void Date::setYear(unsigned year)
{
  if(year > 2100 || year < 2000){
    cout << "Invalid Year (from 2000 to 2100)" << endl;
  }
  else this->year = year;

}


/*********************************
 *          Show Date
 ********************************/  


// disply a Date in a nice format
ostream& operator<<(ostream& out, const Date & date)
{

  // REQUIRES IMPLEMENTATION

}
