#include <iostream>
#include <cstdlib>
#include <string>
#include "monsters.h"
using namespace std;



int Monsters::GetHP() {
    return HP;
}

char *Monsters::GetType() {
    return type;
}

int Monsters::GetSpecialAtk() {
    return SpecialAtk;
}

int Monsters::GetAtk() {
    return Atk;
}

char *Monsters::GetName() {
    return name;
}

bool Monsters::GetIsBig() {
    return isBig;
}
Fire::Fire() {

    int choice;     //randomize the user between big or small
    srand(time(0));
    choice=rand()%2+1;

for(int i=0;i<40;i++)
    name[i]=' ';


        if(choice==1)
        {
            isBig=true;
            isSmall= 0;
            HP=120;
            Atk=20;
            SpecialAtk=40;
            strcpy(name,"Big Fire Charizard ");


        }



        if(choice==2)
        {
            isSmall= true;
            isBig=0;
            HP=80;
            Atk=5;
            SpecialAtk=20;
            strcpy(name,"Small Fire Charizard");




    }
    strcpy(type,"Fire");

}



 Fire::Fire(int num)
{
char d[3];
    int choice;
    choice=rand()%2+1;

    string str= to_string(num);

    if(choice==1)
    {
        isBig=true;
        isSmall= 0;
        HP=120;
        Atk=20;
        SpecialAtk=40;

        strcpy(name,"Big Fire Charizard ");
        strcat(name, str.c_str());

    }

    if(choice==2)
    {
        isSmall= true;
        isBig=0;
        HP=80;
        Atk=5;
        SpecialAtk=20;
        strcpy(name,"Small Fire Charizard ");
        strcat(name, str.c_str());


    }

 strcpy(type,"Fire");
}

int Fire::Attack(int dmg) {

HP+=-dmg;   //all it does it decrease the health and return how much it has left
    return HP;


}


Grass::Grass() {
    int choice;
    choice=rand()%2+1;
    strcpy(type,"Grass");

    if(choice==1)
    {
        isBig=true;
        isSmall= 0;
        HP=120;
        Atk=20;
        SpecialAtk=40;
        strcpy(name,"Big Grass Bulbasaur ");


    }

    if(choice==2)
    {
        isSmall= true;
        isBig=0;
        HP=80;
        Atk=5;
        SpecialAtk=20;
        strcpy(name,"Small Grass Bulbasaur");



    }

}
Grass::Grass(int num) {

    string str= to_string(num);

    int choice;
    choice=rand()%2+1;
    strcpy(type,"Grass");


    if(choice==1)
    {
        isBig=true;
        isSmall= 0;
        HP=120;
        Atk=20;
        SpecialAtk=40;
        strcpy(name,"Big Grass Bulbasaur ");
        strcat(name, str.c_str());

    }

    if(choice==2)
    {
        isSmall= true;
        isBig=0;
        HP=80;
        Atk=5;
        SpecialAtk=20;
        strcpy(name,"Small Grass Bulbasaur ");
        strcat(name, str.c_str());


    }
}

int Grass::Attack(int dmg) {


        HP+=-dmg;
        return HP;


}



Water::Water() {
    int choice;
    choice=rand()%2+1;
    for(int i=0;i<40;i++)
        name[i]=' ';

    strcpy(type,"Water");

    if(choice==1)
    {
        isBig=true;
        isSmall= 0;
        HP=120;
        Atk=20;
        SpecialAtk=40;
        strcpy(name,"Big Water Golduck ");


    }

    if(choice==2)
    {
        isSmall= true;
        isBig=0;
        HP=80;
        Atk=5;
        SpecialAtk=20;
        strcpy(name,"Small Water Golduck ");



    }
}
Water::Water(int num) {
    string str= to_string(num);

    int choice;
    choice=rand()%2+1;
    strcpy(type,"Water");



    if(choice==1)
    {
        isBig=true;
        isSmall= 0;
        HP=120;
        Atk=20;
        SpecialAtk=40;
        strcpy(name,"Big Water Golduck ");
        strcat(name, str.c_str());



    }

    if(choice==2)
    {
        isSmall= true;
        isBig=0;
        HP=80;
        Atk=5;
        SpecialAtk=20;
        strcpy(name,"Small Water Golduck ");
        strcat(name, str.c_str());




    }
}

int Water::Attack(int dmg) {

        HP+=-dmg;
        return HP;

}

