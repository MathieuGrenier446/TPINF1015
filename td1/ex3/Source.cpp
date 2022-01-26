#include <iostream>;
#include <cmath>;
using namespace std;

int main() {
    double hauteur_ini; int nb_rebonds; double coefficient; double vitesse_ini;  double vitesse_n ; double hauteur_fin; double g = 9.81; int n = 2;
    cout << "Quelle est la hauteur initial: "; cin >> hauteur_ini;
    while (hauteur_ini < 0) {
        cout << "la hauteur doit etre positif.Entrez la hateur:"; cin >> hauteur_ini;
    }
    cout << "Quelle est le nombre de rebonds : "; cin >> nb_rebonds;
    while (nb_rebonds <= 0) {
        cout << "le nombre de rebonds doit etre positif.Entrez le nombre de rebonds:"; cin >> nb_rebonds;
    }
    cout << "Quelle est le coefficient de rebonds :"; cin >> coefficient;
    while (coefficient < 0 or coefficient>1) {
        cout << "Le coefficient doit etre entre 0 et 1.Entrez le coefficient :"; cin >> coefficient;
    }


    vitesse_ini = sqrt(2 * g * hauteur_ini);
    vitesse_n = coefficient * vitesse_ini;
    n = 2;
    while (n <= nb_rebonds) {

        vitesse_n = vitesse_n * coefficient; ++n;
    }
    hauteur_fin = (pow(vitesse_n, 2) / (2 * g));
    //cout << "vitesse initiale:" << vitesse_ini << ".";
    //cout << "vitesse finale:" << vitesse_n << ".";
    cout << "Le dernier rebond a atteint la hauteur: " << hauteur_fin << ".";

}