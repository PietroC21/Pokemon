#include <iostream>
#include "commands.h"



using namespace std;

void ShowMenu();

int main() {

    Commands h;
    ShowMenu();


        h.DoSelection('m'); // pass it on to the machine.
         h.DoSelection('c');



    cout << "\n\t\tWell Played!" << endl;
    return 0;
}

void ShowMenu()
{
    cout << "Please select one of the following options\n";
    cout << "by pressing the indicated key:\n";
    cout << "\t\tm:  Move player\n";
    cout << "\t\tc:  List coins\n";




}

