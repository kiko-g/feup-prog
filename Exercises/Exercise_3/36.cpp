#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//HELPFUL EDITOR FUNCTIONS
void start();
void end();
void tabs(int n);
//ACTUAL FUNCTIONS
bool isBsx(int y);
int ndays(int month, int year);
int determineCode(int month, int year);
void wd_conversion(int wd);
void month_conversion(int m);
int weekday(int day, int month, int year); //0 is Saturday, 6 is Friday
void calendar(int month, int year);
void year_calendar(int year);


int main()
{
    int year, month, day, wd;
    start();
    cout << "\nYear: "; cin >> year; cout << "\n";
    year_calendar(year);
    end();
}
















//HELPFUL EDITOR FUNCTIONS
void start()
{
   cout << "=========================================\n";
}
void end()
{
   cout << "\n\n=========================================";
}

void tabs(int n)
{
    int i=0;
    while(i < n)
    {
        cout << "\t";
        i++;
    }
}


//ACTUAL FUNCTIONS
bool isBsx(int y)
{
    bool ok; 
    if(y % 4 == 0)
    {
        ok = true; 
        if(y % 100 == 0) ok = false;
        if(y % 400 == 0) ok = true;
    }
    else ok = false;
    return ok; 
}

int ndays(int month, int year)
{
   int days;
   if(month==4 || month==6 || month==9 || month==11)
       days = 30;

   if(month == 2)
   {
       if(isBsx(year)==1) days = 29;
       else days = 28;
   }
   else days = 31;     
   
   return days;
}

int determineCode(int month, int year)
{
    int code, ok = isBsx(year);
    switch (month)
    {
      case 1:
      if(ok == 1) code = 6;
      else code = 0;
      break;

      case 2:
      if(ok == 1) code = 2;
      else code = 3;
      break;

      case 3: code = 3;
      break;
      
      case 4: code = 6;
      break;

      case 5: code = 1;
      break;

      case 6: code = 4;
      break;

      case 7: code = 6;
      break;

      case 8: code = 2;
      break;

      case 9: code = 5;
      break;

      case 10: code = 0;
      break;

      case 11: code = 3;
      break;

      case 12: code = 5;
      break;
    }

    return code;
}

void wd_conversion(int wd)
{
    if(wd == 0) cout << "[Saturday | Sabado]";
    if(wd == 1) cout << "[Sunday | Domingo]";
    if(wd == 2) cout << "[Monday | Segunda-feira]";
    if(wd == 3) cout << "[Tuesday | Terca-feira]";
    if(wd == 4) cout << "[Wednesday | Quarta-feira]";
    if(wd == 5) cout << "[Thursday | Quinta-feira]";
    if(wd == 6) cout << "[Friday | Sexta-feira]";
}

void month_conversion(int m)
{
    if(m == 1)     cout << "Janeiro";
    if(m == 2)     cout << "Fevereiro";
    if(m == 3)     cout << "Marco";
    if(m == 4)     cout << "Abril";
    if(m == 5)     cout << "Maio";
    if(m == 6)     cout << "Junho";
    if(m == 7)     cout << "Julho";
    if(m == 8)     cout << "Agosto";
    if(m == 9)     cout << "Setembro";
    if(m == 10)    cout << "Outubro";
    if(m == 11)    cout << "Novembro";
    if(m == 12)    cout << "Dezembro";
}

int weekday(int day, int month, int year) //0 is Saturday, 6 is Friday
{
    int ds;
    int s, a, code = determineCode(month, year);
    s = (int)floor(year / 100);
    a = year % 100;

    ds = ((int)floor(5*a/4) + code + day - 2*(s % 4) + 7) % 7;
    return ds;
}

void calendar(int month, int year)
{
     int wd, nday = 1;
     month_conversion(month); cout << "/" << year;
     cout << "\nDom\tSeg\tTer\tQua\tQui\tSex\tSab\n";
     wd = weekday(1, month, year);
     
     if(wd == 0) tabs(6);
     if(wd == 1) tabs(0);
        if(wd == 2) tabs(1);
        if(wd == 3) tabs(2);
     if(wd == 4) tabs(3);
     if(wd == 5) tabs(4);
     if(wd == 6) tabs(5);   
     

     while(nday <= ndays(month, year))
     {
         if(wd == 6)
         {
             if(nday < 10) cout << " ";
             cout << " " << nday;
             cout << "\t";
             wd = 0;
         }

         if(wd == 0)
         {
             nday++;
             if(nday < 10) cout << " ";
             cout << " " << nday;
             cout << "\n";
             wd ++;
         }

         else
         {
            if(nday < 10) cout << " ";
            cout << " " << nday;
            cout << "\t";
            wd++;
         } 
         nday++;
     }
     cout << "\n\n";
}

void year_calendar(int year)
{
    int i=1;
    while(i <= 12)
    {
        calendar(i, year);
        i++;
    }
}