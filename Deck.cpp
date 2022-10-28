#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;


Deck::Deck( ){
    char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suit[] = {'S',  'H', 'D', 'C'};
    int k= 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            storage[k] = Card(rank[j], suit[i]);
            k++;
        }
    }
    topCard = 0;
    totalCards = 52;

}

void  Deck::refreshDeck() {
    char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suit[] = {'S',  'H', 'D', 'C'};
    int k= 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            storage[k] = Card(rank[j], suit[i]);
            k++;
        }
    }
    topCard = 0;
    totalCards = 52;
}

Card Deck::deal(){
    Card c1;
    c1 = storage[topCard];
    ++ topCard;
    totalCards = totalCards - 1;
    return c1;
    //return storage[topCard++];

}

void Deck::shuffle() {
    srand(time(NULL));
    for(int i = 0; i < 10000; i++){
       int x = rand() % 52;
       int y = rand() % 52;
       Card temp = storage[x];
       storage[x] = storage[y];
       storage[y] = temp;

    }


}
bool Deck::isEmpty() {
    if(totalCards == 0){
        return true;
    }else {
        return false;
    }

}

void Deck::display() {

    for (int i = 0; i < 52; i++) {
        //cards more than 13 then go to the new line
        if (i % 13 == 0 && i != 0 ) {
            cout << endl;
            storage[i].display();
        }else{
            storage[i].display();
        }

    }
}