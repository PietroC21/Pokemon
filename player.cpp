#include <iostream>
#include "player.h"
#include "monsters.h"


using namespace std;
Player::~Player()
{
    for(int i=0;i<3;i++)
    delete [] mptr[i];
}

Player& Player::operator=(Player &a) {

    if(this!=&a)
    {
        for(int i=0;i<3;i++)
        delete [] mptr[i];

        size=a.size;

        for(int i=0;i<size;i++)
            mptr[i]=a.mptr[i];





    }
}
Player::Player()
{
    coins=0;
size= 3;
    f = new Fire();

     w= new Water();

     g= new  Grass();
    mptr[0]=f;
    mptr[1]=w;
    mptr[2]=g;


}

ostream & operator<<(ostream& h, Player & a)
{
    for(int i=0;i<3;i++){
   if(a.mptr[i]->GetHP()>0) {
       h << "Name of Pokemon number " << i + 1 << " : " << a.mptr[i]->GetName() << endl;
       h << "HP: " << a.mptr[i]->GetHP() << endl;
       h << "Attack: " << a.mptr[i]->GetAtk() << " Damage." << endl;
   }
    }

    return h;
}

int Player::Attack(int dmg, int choice) {

    return mptr[choice]->Attack(dmg);  //damage my pokemon receives
}

int Player::GetSAtk(int pos) {
    return mptr[pos]->GetSpecialAtk();
}

int Player::GetAtck(int pos) {
    return mptr[pos]->GetAtk();
}
int Player:: GetHP(int pos)
{
    return mptr[pos]->GetHP();
}

char * Player::GetType(int pos) {
    return mptr[pos]->GetType();
}

int Player::GetAlive() {
int counter=0;
    for(int i=0;i<3;i++){
        if(mptr[i]->GetHP()>0) {
           counter++;
        }
        }

    return counter;
}