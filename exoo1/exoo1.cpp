// exoo1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include <cmath>
using namespace std;



int main()
{
    int nombre;
    cout << "Entrez un nombre : "; cin >> nombre;
    for (int i = 2; i <= sqrt(nombre); ++i) {
        if (nombre % i == 0) {

            cout << "ce nombre n'est pas premier car il est divisible par " << i << ".";
            return 0;
        }
        
    }
    cout << " premier.";
    return 0;
}


