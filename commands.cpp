#include <iostream>
#include "commands.h"
#include "map.h"

using namespace std;

void Commands:: DoSelection(char cmd)
{
    switch(cmd) // Show all possible comndads and what function they should call
    {
        case 'm' :  Move();
        case 'c' : cout<<"You currently have : "<<m.GetCoins()<<" coin(s)"<<endl;



    }
}

void Commands::Move() {
int Player=1, tot=1;

    cout << m << endl;
    while (tot!=0 && Player!=0) {


        char cmd;
        int num;
        cout << "What direction do you wish to move the player to? \n";
        cout << "\t\tW:  To go up\n";
        cout << "\t\tA:  To go to the left\n";
        cout << "\t\tD:  To go to the right\n";
        cout << "\t\tS:  To go down \n";
        cout << "> ";
        cin >> cmd;
        cmd = toupper(cmd);
        while (cmd != 'W' && cmd != 'S' && cmd != 'A' && cmd != 'D') {
            cout << "Sorry Invalid Answer!\nInput it again\n";
            cout << "What direction do you wish to move the player to? \n";
            cout << "\t\tW:  To go up\n";
            cout << "\t\tA:  To go to the left\n";
            cout << "\t\tD:  To go to the right\n";
            cout << "\t\tS:  To go down \n";
            cout << "> ";
            cin >> cmd;
            cmd = toupper(cmd);
        }



        Player=m.Move(cmd);
        tot=m.GetCount();


        cout << m << endl;
        cout<<tot<<" "<<Player<<endl;
    }

    if(Player==0)
    {
        cout<<"You're Pokemon's have no HP! "<<endl;
    }

    if(tot==0)
    {cout<<"Congrats you defeated all Pokemon's"<<endl;}
}