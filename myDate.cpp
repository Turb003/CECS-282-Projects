//Dening Zhang
//Class (CECS 282-01)
//Project Name (Prog 2 – myDate Object)
//I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.
#include "myDate.h"
#include<iostream>
#include <sstream>

using namespace std;

//
//int Greg2Julian(int month, int day, int year);
//void Julian2Greg(int JD, int & month, int & day, int & year);

int myDate::Greg2Julian(int month, int day, int year){

    int I = year;
    int J = month;
    int K = day;
    int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
    return JD;
}
void myDate::Julian2Greg(int JD, int &month, int &day, int &year){
    int l = JD + 68569;
    int n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    int i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    int j = 80 * l / 2447;
    int k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;

    year = i;
    month = j;
    day = k;

}

// default constructor. This will set the date to May 11, 1959
myDate::myDate(){
    month = 5;
    day = 11;
    year = 1959;
}

// overloaded constructor.
// This will set the date to the values passed in through the parameter list represented by Month, Day and Year.
myDate::myDate(int M, int D, int Y){
    month = M;
    day = D;
    year = Y;
    int JD = Greg2Julian(month, day, year);
    Julian2Greg(JD, M, D, Y);
    //if any invalid data is passed to this constructor, ignore all data and set the values to the default date.
    if(month != M || day != D && year != Y){
        month = 5;
        day = 11;
        year = 1959;
    }
}
//display the date in the following format - May 11, 1959 - Do NOT print a linefeed after the date.
void myDate::display(){
    string months = monthName[month - 1];
    cout << months << " " <<day <<", "<<year;
}

//increment the date by N days.
void myDate:: increaseDate(int N){
    int incrementDays = Greg2Julian(month, day, year) + N;
    Julian2Greg(incrementDays, month, day, year);
}

//decrement the date by N days.
void myDate::decreaseDate(int N){
    int decrementDays = Greg2Julian(month, day, year) - N;
    Julian2Greg(decrementDays, month, day, year);
}

//this will add one month to the date. If the added month does not have the correct day,
//then the resulting month will use the last day of the month. Example: current date is Jan 31, 2022 –
//when you add a month the resulting dates will be Feb 28, 2022 because Feb does not have 31 days.
void myDate::addMonth( ){

    int JD = Greg2Julian(month, day, year);
    Julian2Greg(JD, month, day, year);
    //if year is leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        if(month == 1){
            day += 29;
            int JD = Greg2Julian(month, day, year);
            Julian2Greg(JD, month, day, year);
        }
    }
    else{
        if(month == 1){
            day += 28;
        }else if(month ==2||month == 4 ||month == 6 || month == 7 || month == 9 || month == 11){
            day += 31;
        }else{
            day += 30;
        }
        int JD = Greg2Julian(month, day, year);
        Julian2Greg(JD, month, day, year);
    }



}


//return the number of days between this date and the date D.  If date D is a future date,
//the return value will be a positive int.
//If date D is in the past, the return value will be a negative int.
int myDate::daysBetween(myDate D){
    int JD1 = Greg2Julian(D.month, D.day,D.year);
    int JD2 = Greg2Julian(month, day, year);
    return JD1 - JD2;
}

//return the month in integer form
int myDate::getMonth() {
    return month;
}

//return the day of the month
int myDate::getDay(){
    return day;
}

//return the year
int myDate::getYear(){
    return year;
}

//return the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32.
int myDate::dayOfYear(){
    int JD = Greg2Julian(month, day, year);
    int firstDayOfYear = Greg2Julian(1, 1, year);
    return JD - firstDayOfYear + 1;

}

//returns Monday, Tuesday, etc according to the day of the week.
string myDate::dayName(){
    string nameOfWeekdays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int JD = Greg2Julian(month, day, year);
    int weekdays = JD % 7;
    return nameOfWeekdays[weekdays];
}
//return a string for the date format
string myDate::toString() {
    std :: ostringstream releasedMonth;
    releasedMonth <<monthName[month - 1] << " " << day <<", "<<year;

    return releasedMonth.str();
}






