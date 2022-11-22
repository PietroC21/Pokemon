#include <iostream>
#include <cstring>
#include "map.h"
#include "monsters.h"
using namespace std;


Map::~Map() {

    for(int i=0;i<size;i++)
        delete[] map [i];

    delete [] map;

    for(int i=0;i<currentMonsters;i++)
        delete [] monsterPos[i];
    delete [] monsterPos;



    for(int i=0;i<currentMonsters;i++)
        delete [] mosState[i];

    delete[] mosState;

}
Map::Map()  : maxSize(10), maxItems(maxSize/3), maxMonsters(maxSize/2) {


    srand(time(0));
    size=maxSize;   //to make sure later on when we do size -2 it will never be 0 ddd
cout<<size<<endl;
    currentItems=rand()%maxItems+3; //initializing the number of items and muster sna d their arraysr
                                         //with their position
    currentMonsters=rand()%maxMonsters+3;
    totM=currentMonsters;

    monsterPos=new int*[currentMonsters];

    mosState= new  Monsters* [currentMonsters];




    map=new char *[size];

    for(int i=0;i<size;i++)
    map[i]=new char [size];


    for(int i=0;i<size;i++)     //constructing the map
    {for(int j=0;j<size;j++)
        {
        if(i==0||i==size-1)
    map[i][j]='-';

    if(j==0||j==size-1)
        map[i][j]='|';
    }
    }

    Px_cord=rand()%size;
    Py_cord=rand()%size;         //randomize the position of player, while making sure it is in bounds



    while (Px_cord==0 ||Px_cord==size-1|| Py_cord==0 ||Py_cord==size-1)
    {Px_cord=rand()%size;
        Py_cord=rand()%size;
    }
    map[Px_cord][Py_cord]='P';




monsters(); // create monsters and items in the map
    Items();

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
        {
            if(map[i][j]=='\0')     //for the rest that's  not the end of map make it a space
            map[i][j]=' ';
        }}




    if(map[Px_cord][Py_cord]=='I') {
        p.coins++;
        currentItems--;
    }


}

int Map::GetCount()
{
    return (totM+currentItems); //return amount of things still present in the map

}
void Map::monsters() {


    int choice;

    for(int i=0; i<currentMonsters;i++)
{

    x_cord=rand()%(size-2)+1;    //find x and y cord for the monster
    y_cord=rand()%(size-2)+1;

    //make sure its on the bounds permitted

    while (x_cord==0 ||x_cord==size-1|| y_cord==0 ||y_cord==size-1 || map[x_cord][y_cord]=='P'
    || map[x_cord][y_cord]=='M'  )
    {
        x_cord=rand()%(size-2)+1;
        y_cord=rand()%(size-2)+1;
    }

    map[x_cord][y_cord]='M';
    monsterPos[i]=new int [2];      //initialize an array for the pos of the monsters
    monsterPos[i][0]=x_cord;
    monsterPos[i][1]=y_cord;




}

    for(int i=0;i<currentMonsters;i++)
    {
        choice=rand()%3+1;    //randomize what type the Pokémon will be

        switch (choice) {       //use a switch statement to initialize it

            case 1:  mosState[i]=new Fire(i);
                break;
            case 2:  mosState[i]=new Water(i);
                break;
            case 3:  mosState[i]=new Grass(i);
                break;

        }

}
    for(int i=0;i<currentMonsters;i++)
    {
       cout<< mosState[i]->GetName()<<endl;
       cout<<"X: "<<monsterPos[i][0]<<" Y: "<<monsterPos[i][1]<<endl;
    }
}

void Map::Items() {

    for(int i=0; i<currentItems;i++)
    {
        x_cord=rand()%(size-2)+1;
        y_cord=rand()%(size-2)+1;

        while ( map[x_cord][y_cord]=='M' || x_cord==0 || x_cord==size-1 || y_cord==0 || y_cord==size-1
        || map[x_cord][y_cord]=='P' )
{  x_cord=rand()%(size-2)+1;
    y_cord=rand()%(size-2)+1;

}

        map[x_cord][y_cord]='I';


    }
}

ostream& operator<<(ostream & h, Map & a)
 {


     for(int i=0;i<a.size;i++)
     {for(int j=0;j<a.size;j++)
     { h<<a.map[i][j]<<" ";}
     h<<endl;
     }

     return h;
 }

int Map::Move(char cmd) {

bool outcome= true,mos=false;
    if(cmd=='W' )
    {
        map[Px_cord][Py_cord]=' ';  //moving player one postion on whatever dirrection is given
        Px_cord-=1;

       if(map[Px_cord][Py_cord]=='M'){  //in case it stepped on a monster activate the attack function

               for (int i = 0; i < currentMonsters; i++) {
                   if (monsterPos[i][0] == Px_cord) {
                       if (monsterPos[i][1] == Py_cord)

                           outcome = Attack(i); //this will retrun true if player won and false if lost
                       mos = outcome;   //in case it won it will also at the end trigger another if statement
                                        // to decrement the amount of current monsters
                   }
               }


            if (!outcome)
            {
                Px_cord+=1; //if player lost it does not change the postion to where the monster was
            }

        }

        if(map[Px_cord][Py_cord]=='I') {
            p.coins++;  //if it steps on coin add to the counter
            currentItems--;// and decrease amount of coins
        }
        if(map[Px_cord][Py_cord]=='-' ||map[Px_cord][Py_cord]=='|')
        {//if player went to the boards of map do not let it move
            Px_cord+=1;

        }

        map[Px_cord][Py_cord]='P';


    }


    else if( cmd=='S')
    {
        map[Px_cord][Py_cord]=' ';
        Px_cord+=1;

        if(map[Px_cord][Py_cord]=='M'){
            {
                for (int i = 0; i < currentMonsters; i++) {
                    if (monsterPos[i][0] == Px_cord) {
                        if (monsterPos[i][1] == Py_cord) {
                            outcome = Attack(i);
                            mos = outcome;
                        }
                    }
                }
            }
        }

        if (!outcome)
        {
            Px_cord-=1;

        }
        if(map[Px_cord][Py_cord]=='-' ||map[Px_cord][Py_cord]=='|')
        {
            Px_cord-=1;
        }

        if(map[Px_cord][Py_cord]=='I') {
            p.coins++;
            currentItems--;
        }
        map[Px_cord][Py_cord]='P';
    }



    else if(cmd=='A')
    {
        map[Px_cord][Py_cord]=' ';

        Py_cord-=1;

        if(map[Px_cord][Py_cord]=='M'){

            for (int i = 0; i < currentMonsters; i++) {
                    if (monsterPos[i][0] == Px_cord) {
                        if (monsterPos[i][1] == Py_cord) {
                            outcome = Attack(i);
                            mos = outcome;
                        }
                    }
                }

            }


        if (!outcome)
        {
            Py_cord+=1;

        }

        if(map[Px_cord][Py_cord]=='-' ||map[Px_cord][Py_cord]=='|')
        {
            Py_cord+=1;
        }
        if(map[Px_cord][Py_cord]=='I') {
            p.coins++;
            currentItems--;
        }

        map[Px_cord][Py_cord]='P';
    }


    else if( cmd=='D')
    {
        map[Px_cord][Py_cord]=' ';

        Py_cord+=1;

        if(map[Px_cord][Py_cord]=='M'){
                for (int i = 0; i < currentMonsters; i++) {
                    if (monsterPos[i][0] == Px_cord) {
                        if (monsterPos[i][1] == Py_cord) {
                            outcome = Attack(i);
                            mos = outcome;
                        }
                    }
                }

        }
        if (!outcome)
        {
            Py_cord-=1;

        }

        if(map[Px_cord][Py_cord]=='-' ||map[Px_cord][Py_cord]=='|')
        {
            Py_cord-=1;
        }

        if(map[Px_cord][Py_cord]=='I') {
            p.coins++;
            currentItems--;

        }
        map[Px_cord][Py_cord]='P';
    }



if(mos)
{
    totM--;  //decrese ammouint of monster if it was defeated
}
    return p.GetAlive();    //retrun how many players are still alive to know when to stop the game



}

int Map::GetCoins() {
    return p.coins;
}

bool Map:: Attack(int pos)
{
    int choice;
    int random;
    cout<<"Whoops seems like we stumbled upon a Pokemon!\nThese are the attributes of the Pokemon!"<<endl;
    cout<<"Name: "<<mosState[pos]->GetName()<<"\nHP: "<<mosState[pos]->GetHP()
    <<"\nAttack: "<<mosState[pos]->GetAtk()<<" Damage"<<endl;
    //here it displays the monster we are facing
    cout<<"\nNow select which one of your Pokemon's you wish to use:"<<endl;
    cout<<p<<endl;  //prints out list of monsters player posses that are still alive
    cout<<"\n> ";
    cin>>choice;

    while (choice!=1 && choice!=2 && choice!=3)
    {
        cout<<"Invalid Choice!\nPlease type it Again"<<endl;
        cout<<"> ";
        cin>>choice;
    }

    choice--;       //indexes always start at 0 so choice minus one gives us the actual Pokémon they wanted to choose
char option='a';
    int myHP=p.GetHP(choice),otherHP=mosState[pos]->GetHP();  //gets player and monster HP
    //players turn to give damage if chosen
    int dmg,speAtk,mosAtk,mosSatk;

    dmg=p.GetAtck(choice);
    speAtk=p.GetSAtk(choice);       //default values for the damaage in case they dont meet the requirements
    mosAtk=mosState[pos]->GetAtk();
    mosSatk=mosState[pos]->GetSpecialAtk();



    if(strcmp(mosState[pos]->GetType(),"Fire")==0) {
        //if statements to see the damage it'll have if double or not
    if(strcmp(p.GetType(choice),"Water")==0) {
        speAtk=2*speAtk;   //damage  player inflicts to monster
    }

    if(strcmp(p.GetType(choice),"Grass")==0)
    {
        mosSatk=2*mosSatk;
    }
}

    else if(strcmp(mosState[pos]->GetType(),"Grass")==0)
    {


         if(strcmp(p.GetType(choice),"Fire")==0)
        {

            speAtk=2*speAtk;

        }
        if(strcmp(p.GetType(choice),"Water")==0)
        {
            mosSatk=2*mosSatk;

        }

    }

    else if(strcmp(mosState[pos]->GetType(),"Water")==0)
{


         if(strcmp(p.GetType(choice),"Grass")==0)
        {
            speAtk=2*speAtk;

        }

    if(strcmp(p.GetType(choice),"Fire")==0)
    {
        mosSatk=2*mosSatk;

    }


}

    while (option!='R' && myHP>0 && otherHP>0)  //starts attack until player run away or someone's HP ends
    {
        cout<<"Choose from the following options what you wish to do in your turn: "<<endl;
        cout<<"\t\tW:   Wait"<<endl;
        cout<<"\t\tP:   Physical Attack"<<endl;
        cout<<"\t\tS:   Special Attack"<<endl;
        cout<<"\t\tR:   Run"<<endl;
        cout<<"> ";
        cin>>option;
        option= toupper(option);    //for data checking in case it was not put in upper case

        while (option!='W' && option!='P' && option!='S' && option!='R')    //bad data checking
        {
            cout<<"Invalid Choice!\nPlease type it Again\n";
            cout<<"Choose from the following options what you wish to do in your turn: "<<endl;
            cout<<"\t\tW:   Wait"<<endl;
            cout<<"\t\tP:   Physical Attack"<<endl;
            cout<<"\t\tS:   Special Attack"<<endl;
            cout<<"\t\tR:   Run"<<endl;
            cout<<"> ";
            cin>>option;
            option= toupper(option);

        }



        switch (option) {
            case 'P':otherHP=mosState[pos]->Attack(dmg); //damage to monster
                break;
            case 'S':otherHP=mosState[pos]->Attack(speAtk);
                break;


        }

        random=rand()%3+1;  //randomize what will the monster do

        if(option!='R' && otherHP>0) //if user did not run then the monster will take his turn to attack
        {                           // or if monsters HP is less than or equal 0
            switch (random) {
                case 1:myHP=p.Attack(mosAtk,choice);  //monster attack on player
                    break;
                case 2:myHP=p.Attack(speAtk,choice);    //special attack
                    break;
                case 3:break;
            }

        }



        cout<<"My HP: "<<myHP<<"\nOther HP: "<<otherHP<<endl;   //pring out their HP's

    }




    if(option=='R' ||myHP<=0)   //player lost
    return false;


if(otherHP<=0)  //player won
    return true;


}