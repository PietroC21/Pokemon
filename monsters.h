
#ifndef HOMEWORK7_POKEMON_MONSTERS_H
#define HOMEWORK7_POKEMON_MONSTERS_H

class Monsters{

public:

     virtual int Attack(int dmg)=0;
     char * GetName();
     char * GetType();

     int GetHP();
     int GetAtk();
     int GetSpecialAtk();

     bool GetIsBig();

protected:
    char name[40];
    int HP;
    int Atk;
    int SpecialAtk;
    char type[10];
    bool isBig, isSmall;
};


class Fire: public Monsters{

public:


    Fire();
    Fire(int  num) ;

    int Attack(int dmg);

private:

};

class Grass:  public Monsters{

public:


    int Attack(int dmg);

    Grass(int  num ) ;
    Grass();

};

class Water:  public Monsters{

public:

    int Attack(int dmg);

    Water(int  num) ;
    Water();


};
#endif

