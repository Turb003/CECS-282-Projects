//Dening Zhang
//Class (CECS 282-01)
//Project Name (Prog 3 – Structs and Pointers)
//I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <string>
#include "myDate.h"
using namespace std;
#include <cstring>
#include "string.h"
#include <iomanip>
#include <sstream>



struct Movie{
    char name[100];
    int running;
    double rating;
    myDate released;
    string actor;

};

void sortName(Movie *mov[]);
void sortTime(Movie *mov[]);
void sortRating(Movie *mov[]);
void sortReleaseDate(Movie *mov[]);
void sortMainActor(Movie *mov[]);
void populate(Movie *mov[]);
void display(Movie *mov[]);
string runningTime(Movie *movie[]);

void sortName(Movie *mov[]){
    for(int i = 0; i <10; i++){
        for(int j = 0; j <9; j++){
            if(strcmp(mov[j] ->name, mov[j + 1] ->name) >0){
                swap(mov[j], mov[j+1]);
            }
        }
    }
}
void sortTime(Movie *mov[]){
    for(int i = 0; i <10; i++){
        for(int j = 0; j <9; j++){
            if(mov[j]->running > mov[j+1]->running){
                swap(mov[j], mov[j+1]);
            }
        }
    }
}
void sortRating(Movie *mov[]){
    for(int i = 0; i <10; i++){
        for(int j = 0; j <9; j++){
            if(mov[j]->rating > mov[j+1]->rating){
                swap(mov[j], mov[j+1]);
            }
        }
    }
}

void sortReleaseDate(Movie *mov[]){

    for(int i = 0; i <10; i++){
        for(int j = 0; j <9; j++){
            int jReleased1 = mov[j] ->released.Greg2Julian(mov[j] ->released.getMonth(), mov[j] ->released.getDay(), mov[j] ->released.getYear());
            int jRealesed2 = mov[j+1] ->released.Greg2Julian(mov[j+1] ->released.getMonth(), mov[j+1] ->released.getDay(), mov[j+1] ->released.getYear());
            if(jReleased1 > jRealesed2 ){
                swap(mov[j], mov[j+1]);
            }
        }
    }
}

void sortMainActor(Movie *mov[]){
    for(int i = 0; i <10; i++){
        for(int j = 0; j <9; j++){
            if(mov[j]->actor > mov[j+1]->actor){
                swap(mov[j], mov[j+1]);
            }
        }
    }
}
int main() {

    Movie *mov[10];
    populate(mov);
    display(mov);

    int menuChoice = 0;
    while(menuChoice != 6){
        cout<< "1)	Display list sorted by Name\n"
               "2)	Display list sorted by Running Time\n"
               "3)	Display list sorted by IMDB Rating\n"
               "4)	Display list sorted by Release Date\n"
               "5)	Display list sorted by Main Actor\n"
               "6)	Exit\n "<<endl;
        cin >>menuChoice;
        switch(menuChoice){
            case 1:
                sortName(mov);
                display(mov);
                break;
            case 2 :
                sortTime(mov);
                display(mov);
                break;
            case 3:
                sortRating(mov);
                display(mov);
                break;
            case 4:
                sortReleaseDate(mov);
                display(mov);
                break;
            case 5:
                sortMainActor(mov);
                display(mov);
                break;
            case 6:
                cout << "bye bye!"<<endl;
                break;

        }
    }
    return 0;
}
//void toStringTime(Movie *mov[]){
//
//    string timeFormatting = to_string(mov[i]->running/60 +" h "+ mov[i] ->running%60 + "m");
//}


void display(Movie *movie[]){

    cout<<setw(30)<<left<<"Name"
        <<setw(20)<<left<<"Running Time"
        <<setw(20)<<left<<"IMDB Rating"
        <<setw(30)<<left<<"Relaease Date"
        <<setw(30)<<left<<"Main Actor"<<endl;

    std::ostringstream ss;

    for(int i = 0; i <10 ; i++){
        string s1 = to_string(movie[i]->running/60);
        string s2 = "h ";
        string s3 = to_string(movie[i]->running%60);
        string s4 = "m";
        string s;
        s.append(s1 );
        s.append(s2);
        s.append(s3);
        s.append(s4);
        cout<<setw(30)<<left<<movie[i]->name;
        cout<<setw(20)<<left<<s;
        cout<<setw(20)<<left<<movie[i]->rating;
        cout<<setw(30)<<left<<movie[i]->released.toString();
        cout<<setw(30)<<left<<movie[i]->actor<<endl;
    }
}

void populate(Movie *movie[]){
    int time[10] = {142, 175, 152, 202, 96, 195, 201, 154, 178, 178};
    double movieRating[10] = {9.4, 6.2, 7.3, 8.2, 8.5, 8.9, 8.9, 8.9, 8.7, 8.6};

    myDate date1(9,22,1994);
    myDate date2(7, 28, 1995);
    myDate date3(6, 26, 1969);
    myDate date4(12, 20, 1974);
    myDate date5(4,18, 2016);
    myDate date6(2,14, 1994);
    myDate date7(12,15, 2012);
    myDate date8(5,21, 1994);
    myDate date9(12,19, 2010);
    myDate date10(3,29, 1977);
    myDate dateRelease[] = {date1, date2, date3, date4, date5, date6, date7, date8, date9, date10};

    string mainActor[10] = {"Tim Robbins", "Kevin Cosner", "Peter Fonda", "Al Pacino", "Ryunosuke Kamiki", "Liam Neeson",
                            "Jamie Foxx", "John Travolta", "Leonardo Dicaprio", "Mark Hamill"};

    for(int i = 0;i < 10; i++){
        movie[i] = new Movie;
        movie[i] ->running = time[i];
        movie[i] ->rating = movieRating[i];
        movie[i] ->released = dateRelease[i];
        movie[i] ->actor = mainActor[i];

    }
    strcpy(movie[0] -> name, "The Shawshank Redemption");
    strcpy(movie[1] -> name, "Water World");
    strcpy(movie[2] -> name, "Easy Rider");
    strcpy(movie[3] -> name, "Heat");
    strcpy(movie[4] -> name, "Your Name");
    strcpy(movie[5] -> name, "Schindler\'s List");
    strcpy(movie[6] -> name, "Django Unchained");
    strcpy(movie[7] -> name, "Pulp Fiction");
    strcpy(movie[8] -> name, "Inception");
    strcpy(movie[9] -> name, "Star Wars");


}

