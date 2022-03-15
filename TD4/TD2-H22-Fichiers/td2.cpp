/**
* Programme qui affiche et créer des liste de films à partir d'un fichier binaire.
* \file   td2.cpp
* \author Grenier et Allam
* \date   6 mars 2022
* Créé le 28 janvier 2022
*/

#pragma region "Includes"//{
#define _CRT_SECURE_NO_WARNINGS // On permet d'utiliser les fonctions de copies de chaînes qui sont considérées non sécuritaires.

#include "structures.hpp"      // Structures de données pour la collection de films en mémoire.

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <memory>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include <functional>
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp" // Nos fonctions pour le rapport de fuites de mémoire.
#include "debogage_memoire.hpp"        // Ajout des numéros de ligne des "new" dans le rapport de fuites.  Doit être après les include 
//du système, qui peuvent utiliser des "placement new" (non supporté par notre ajout de numéros de lignes).

using namespace std;
using namespace iter;
using namespace gsl;

#pragma endregion//}

typedef uint8_t UInt8;
typedef uint16_t UInt16;


#pragma region "Fonctions de base pour lire le fichier binaire"//{

UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read((char*)&texte[0], streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

#pragma endregion//}


void ListeFilms::changeDimension(int nouvelleCapacite)
{
	Film** nouvelleListe = new Film * [nouvelleCapacite];

	if(elements != nullptr)
	{  
		nElements = min(nouvelleCapacite, nElements);
		for(int i : range(nElements))
			nouvelleListe[i] = elements[i];
		delete[] elements;
	}

	elements = nouvelleListe;
	capacite = nouvelleCapacite;
}

void ListeFilms::ajouterFilm(Film* film)
{
	if(nElements == capacite)
		changeDimension(max(1, capacite * 2));
	elements[nElements++] = film;
}


span<Film*> ListeFilms::enSpan() const
{
	return span(elements, nElements);
}

void ListeFilms::enleverFilm(const Film* film)
{
	for(Film*& element : enSpan())
	{  
		if(element == film)
		{
			if(nElements > 1)
				element = elements[nElements - 1];
			nElements--;
			return;
		}
	}
}
//]



shared_ptr<Acteur> ListeFilms::trouverActeur(const string& nomActeur) const
{
	for(const Film* film : enSpan())
	{
		for(const shared_ptr<Acteur> acteur : film->acteurs.spanListeElements())
		{
			if(acteur->nom == nomActeur)
				return acteur;
		}
	}
	return nullptr;
}

shared_ptr<Acteur> lireActeur(istream& fichier, ListeFilms& listeFilms)
{
	Acteur acteur = {};
	acteur.nom = lireString(fichier);
	acteur.anneeNaissance = lireUint16(fichier);
	acteur.sexe = lireUint8(fichier);
	
	shared_ptr<Acteur> acteurExistant = listeFilms.trouverActeur(acteur.nom);
	if(acteurExistant != nullptr)
		return acteurExistant;
	else
	{
		cout << "Création Acteur " << acteur.nom << endl;
		return make_shared<Acteur>(acteur);
	}
}

Film* lireFilm(istream& fichier, ListeFilms& listeFilms)
{
	Film* film = new Film {};
	film->titre = lireString(fichier);
	film->realisateur = lireString(fichier);
	film->anneeSortie = lireUint16(fichier);
	film->recette = lireUint16(fichier);
	film->acteurs = Liste<Acteur>(lireUint8(fichier));  
 
	cout << "Création Film " << film->titre << endl;
	
	for(shared_ptr<Acteur> acteur : film->acteurs.spanListeElements())
	{
		acteur = lireActeur(fichier, listeFilms);
		film->acteurs.ajouterElement(acteur);
	}

	return film;
}

ListeFilms::ListeFilms(const string& nomFichier) : possedeLesFilms_(true)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);

	int nElements = lireUint16(fichier);

	for([[maybe_unused]] int i : range(nElements))
	{ 
		ajouterFilm(lireFilm(fichier, *this)); 
	}
}


//bool joueEncore(const Acteur* acteur)
//{
//	return acteur->joueDans.size() != 0;
//}
void detruireFilm(Film* film)
{
	//for(const shared_ptr<Acteur> acteur : film->acteurs.spanListeActeurs())
	//{
	//	acteur->joueDans.enleverFilm(film);
	//}
	cout << "Destruction Film " << film->titre << endl;

	delete film;
}

ListeFilms::~ListeFilms()
{
	if(possedeLesFilms_)
		for(Film* film : enSpan())
			detruireFilm(film);
	delete[] elements;
}

//void afficherActeur(const Acteur& acteur)
//{
//	cout << "  " << acteur.nom << ", " << acteur.anneeNaissance << " " << acteur.sexe << endl;
//}

ostream& operator<<(ostream& os, const Film& film)
{
	os << "Titre: " << film.titre << '\n';
	os << "  Réalisateur: " << film.realisateur << "  Année :" << film.anneeSortie << '\n';
	os << "  Recette: " << film.recette << "M$" << '\n';

	os << "Acteurs:" << '\n';
	for(const shared_ptr<Acteur> acteur : film.acteurs.spanListeElements())
		os << "  " << acteur->nom << ", " << acteur->anneeNaissance << " " << acteur->sexe;
	return os;
}

void afficherListeFilms(const ListeFilms& listeFilms)
{
	static const string ligneDeSeparation =	"\033[32m────────────────────────────────────────\033[0m\n";
	cout << ligneDeSeparation;

	for(const Film* film : listeFilms.enSpan())
	{
		cout << *film;
		cout << ligneDeSeparation;
	}
}

//void afficherFilmographieActeur(const ListeFilms& listeFilms, const string& nomActeur)
//{
//	const shared_ptr<Acteur> acteur = listeFilms.trouverActeur(nomActeur);
//
//	if(acteur == nullptr)
//		cout << "Aucun acteur de ce nom" << endl;
//	else
//		afficherListeFilms(acteur->joueDans);
//}

int main()
{
#ifdef VERIFICATION_ALLOCATION_INCLUS
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
#endif
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	//int* fuite = new int; //TODO: Enlever cette ligne après avoir vérifié qu'il y a bien un "Detected memory leak" de "4 bytes" affiché dans la "Sortie", qui réfère à cette ligne du programme.

	static const string ligneDeSeparation = "\n\033[35m════════════════════════════════════════\033[0m\n";

	//TODO: Chaque TODO dans cette fonction devrait se faire en 1 ou 2 lignes, en appelant les fonctions écrites.

	//TODO: La ligne suivante devrait lire le fichier binaire en allouant la mémoire nécessaire.  Devrait afficher les noms de 20 acteurs sans doublons (par l'affichage pour fins de débogage dans votre fonction lireActeur).
	ListeFilms listeFilms("films.bin");

	cout << ligneDeSeparation << "Le premier film de la liste est:" << endl;
	//TODO: Afficher le premier film de la liste.  Devrait être Alien.
	//[
	cout<<listeFilms[0];
	//]

	cout << ligneDeSeparation << "Les films sont:" << endl;
	//TODO: Afficher la liste des films.  Il devrait y en avoir 7.
	//TODO: Afficher la liste des films.  Il devrait y en avoir 7.
	//[
	afficherListeFilms(listeFilms);
	//]

	//TODO: Modifier l'année de naissance de Benedict Cumberbatch pour être 1976 (elle était 0 dans les données lues du fichier).  Vous ne pouvez pas supposer l'ordre des films et des acteurs dans les listes, il faut y aller par son nom.
	//[
	listeFilms.trouverActeur("Benedict Cumberbatch")->anneeNaissance = 1976;
	//]

	//cout << ligneDeSeparation << "Liste des films où Benedict Cumberbatch joue sont:" << endl;
	//TODO: Afficher la liste des films où Benedict Cumberbatch joue.  Il devrait y avoir Le Hobbit et Le jeu de l'imitation.
	//[
	//afficherFilmographieActeur(listeFilms, "Benedict Cumberbatch");
	//]

	Film skylien = listeFilms[0];
	skylien.titre = "Skylien";
	skylien.acteurs[0] = listeFilms[1].acteurs[0];
	skylien.acteurs[0]->nom = "Daniel Wroughton Craig";
	cout << skylien << '\n' << listeFilms[0] << '\n' << listeFilms[1];

	auto lambda = [=](Film* film) {return film->recette == 955;};
	shared_ptr<Film> filmTrouver = listeFilms.chercherFilm(lambda);

	Liste<string> listeTextes(2);
	shared_ptr<string> string1 = make_shared<string>("allo");
	shared_ptr<string> string2 = make_shared<string>("bonjour");
	listeTextes.ajouterElement(string1);
	listeTextes.ajouterElement(string2);
	Liste<string> listeTextes2 = listeTextes;
	listeTextes[0] = make_shared<string>("hello");

	listeTextes[1].get()[0] = "B";

	std::cout << listeTextes[0] << '\n'
		<< listeTextes[1] << '\n' 
		<< listeTextes2[0] << '\n' << listeTextes2[1] << endl;

	//TODO: Détruire et enlever le premier film de la liste (Alien).  Ceci devrait "automatiquement" (par ce que font vos fonctions) détruire les acteurs Tom Skerritt et John Hurt, mais pas Sigourney Weaver puisqu'elle joue aussi dans Avatar.
	//[
	detruireFilm(listeFilms.enSpan()[0]);
	listeFilms.enleverFilm(listeFilms.enSpan()[0]);
	//]

	cout << ligneDeSeparation << "Les films sont maintenant:" << endl;
	//TODO: Afficher la liste des films.
	//[
	afficherListeFilms(listeFilms);
	//]

	//TODO: Faire les appels qui manquent pour avoir 0% de lignes non exécutées dans le programme (aucune ligne rouge dans la couverture de code; c'est normal que les lignes de "new" et "delete" soient jaunes).  Vous avez aussi le droit d'effacer les lignes du programmes qui ne sont pas exécutée, si finalement vous pensez qu'elle ne sont pas utiles.
	//[
	// Les lignes à mettre ici dépendent de comment ils ont fait leurs fonctions.  Dans mon cas:
	listeFilms.enleverFilm(nullptr); // Enlever un film qui n'est pas dans la liste (clairement que nullptr n'y est pas).
	/*afficherFilmographieActeur(listeFilms, "N'existe pas"); */// Afficher les films d'un acteur qui n'existe pas.
	//]

	//TODO: Détruire tout avant de terminer le programme.  L'objet verifierFuitesAllocations devrait afficher "Aucune fuite detectee." a la sortie du programme; il affichera "Fuite detectee:" avec la liste des blocs, s'il manque des delete.
//[
//]
}
