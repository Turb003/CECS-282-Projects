#ifndef PROGRAM2_MYDATE_H
#define PROGRAM2_MYDATE_H
#include<string>
using namespace std;

class myDate{
private:
    int month, day, year;
    string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

public:

    myDate(); // default constructor. This will set the date to May 11, 1959
    myDate(int M, int D, int Y); // overloaded constructor. This will set the date to the values passed in through the parameter list represented by Month, Day and Year.
    void display(); //display the date in the following format - May 11, 1959 - Do NOT print a linefeed after the date.
    void increaseDate(int N); //increment the date by N days.
    void decreaseDate(int N); //decrement the date by N days.
    void addMonth( ); //this will add one month to the date. If the added month does not have the correct day, then the resulting month will use the last day of the month. Example: current date is Jan 31, 2022 – when you add a month the resulting dates will be Feb 28, 2022 because Feb does not have 31 days.
    int daysBetween(myDate D);//return the number of days between this date and the date D.  If date D is a future date, the return value will be a positive int.  If date D is in the past, the return value will be a negative int.
    int getMonth() ;//return the month in integer form
    int getDay(); //return the day of the month
    int getYear(); //return the year
    int dayOfYear();//the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32.
    string dayName();//returns Monday, Tuesday, etc according to the day of the week.
    string toString();
    int Greg2Julian(int month, int day, int year);
    void Julian2Greg(int JD, int & month, int & day, int & year);

    string toString1();
};

#endif
