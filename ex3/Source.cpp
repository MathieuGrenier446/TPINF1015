#include <iostream>;
#include <cmath>;
using namespace std;

double validerEntree(double borneInf, double borneSup) {
    double entree;
    cin >> entree;
    while (entree < borneInf || entree > borneSup) {
        cout << "entree invalide, veuillez reessayer";
        cin >> entree;
    }
    return entree;
}
int main() {
        double hauteur_ini; int nb_rebonds; double coefficient; double vitesse_ini;  double vitesse_n; double hauteur_fin; double g = 9.81; int n = 2;  

    cout << "Quelle est la hauteur initial: ";
    hauteur_ini = validerEntree(0, INFINITY);

    cout << "Quelle est le nombre de rebonds : ";
    nb_rebonds = validerEntree(0, INFINITY);

    cout << "Quelle est le coefficient de rebonds :";
    coefficient = validerEntree(0, 1);






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