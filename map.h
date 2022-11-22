

using namespace std;

#ifndef HOMEWORK7_POKEMON_MAP_H
#define HOMEWORK7_POKEMON_MAP_H
#include "player.h"
#include "monsters.h"

class Map{

    friend ostream& operator<<(ostream & h, Map & a);
public:

    bool Attack(int pos);
Map();
~Map();
int Move(char cmd);
int GetCoins();

int GetCount();

private:
    //position
    int x_cord,y_cord;
    int Px_cord,Py_cord;    //Player Position

    //Sizes
    const int maxSize;
    const int maxMonsters;
    const int maxItems;


    int size;
    int currentMonsters, currentItems, totM;

    int **monsterPos;   //dynamic 2D arrays
    Monsters **mosState;
    char **map;

    //Inventory
    Player p;
    void monsters();
    void Items();

};
#endif
