#ifndef PROG1_CARD_H
#define PROG1_CARD_H

class Card{
private:
    char suit;
    char rank;
public:
    Card();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    void display();

};
#endif //PROG1_CARD_H
