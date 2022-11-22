using namespace std;

#ifndef HOMEWORK7_POKEMON_PLAYER_H
#define HOMEWORK7_POKEMON_PLAYER_H
#include "monsters.h"


class Player{

    friend ostream & operator<<(ostream& h, Player & a);

public:
Player();
~Player();

int coins;

int GetAtck(int pos);
int GetSAtk(int pos);   //getters
int GetHP(int pos);
char * GetType(int pos);
int GetAlive();


int Attack(int atk, int pos);   //attack

Player& operator=(Player& a);
void Grow();

private:

    int size;
Monsters *mptr[3];
    Fire* f;
    Water *w;
    Grass *g;
};
#endif