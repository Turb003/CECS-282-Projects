#ifndef PROG1_DECK_H
#define PROG1_DECK_H
#include"Card.h"
#include <string>
using namespace std;
class Deck{
private:
    Card storage[52];
    int topCard ;
    int totalCards;


public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    bool isEmpty();
    void display();

};
#endif //PROG1_DECK_H
