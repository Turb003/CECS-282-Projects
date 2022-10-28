//Dening Zhang
//Class (CECS 282-01)
//Project Name (Prog 1 – Fibonacci Solitaire)
//Due Date(02/14/2022)
//I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include <math.h>
using namespace std;

bool isFibo(int n);
bool isPerfectSquare(int n);

bool isPerfectSquare(int x){
    int s = sqrt(x);
    return (s * s == x);
}
bool isFibo(int n){

    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}
void playGame(Deck deck) {
    Card card;
    int pile = 0;

    int sumOfCards = 0;

    //isEmpty return 0 if deck is not empty, return 1 if deck is empty

    while (!deck.isEmpty()) {
        card = deck.deal();
        card.display();
        sumOfCards += card.getValue();
        if (isFibo(sumOfCards)) {
            pile += 1;
            cout << " Fibo: " << sumOfCards << endl;
            sumOfCards = 0;
        }
        int gamesPlay = 0;
        if (deck.isEmpty()) {
            bool gamePlayed = false;
            while (!gamePlayed) {
                if (sumOfCards != 0) {
                    cout << "\nlast hand value: " << sumOfCards << endl;
                    cout << "Loser in " << pile + 1 << " piles!" << endl;
                    gamesPlay +=1;
                    cout << "games played: " << gamesPlay;
                    gamePlayed = true;


                } else {
                    gamesPlay+=1;
                    gamePlayed = true;
                    cout << "Winner in " << pile + 1 << " piles!" << endl << endl;
                    cout << "games played: " << gamesPlay << endl;
                }


            }

        }

    }
}

int main() {
    Deck deck;
    int menuChoice = 0;
    while(menuChoice != 5){
        cout << "\nWelcome to Fibonacci Solitaire!\n"
                "1)	New Deck\n"
                "2)	Display Deck\n"
                "3)	Shuffle Deck\n"
                "4)	Play Solitaire\n"
                "5)	Exit\n"<<endl;
        cin >> menuChoice;
        if(menuChoice == 1){
            deck.refreshDeck();
            cout << "New deck is made!!!"<<endl;
        }else if(menuChoice == 2){
            deck.display();
        }else if(menuChoice == 3){
            deck.shuffle();
            cout<<"The cards randomly shuffle in the deck" <<endl;
        }else if(menuChoice == 4){
            cout << "playing fibonacci Soiltaire !!!" <<endl<<endl;
            playGame(deck);

        }else if(menuChoice == 5){
            cout << "The game is Over!" <<endl;
        }else{
            cout << "Invalid Input" <<endl;
        }
    }


    return 0;
}
