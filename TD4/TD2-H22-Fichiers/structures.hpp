/**
* Fichier contenant les strucutres pour une collection de films.
* \file   structures.hpp
* \author Grenier et Allam
* \date   6 mars 2022
* Créé le 28 janvier 2022
*/

#pragma once
// Structures mémoires pour une collection de films.

#include <string>
#include <cassert>
#include "gsl/span"
#include <memory>
#include <functional>

using gsl::span;
using namespace std;
using namespace gsl;

struct Film; struct Acteur; // Permet d'utiliser les types alors qu'ils seront défini après.


class ListeFilms
{
	public:
	ListeFilms() = default;
	ListeFilms(const std::string& nomFichier);
	ListeFilms(const ListeFilms& l) { assert(l.elements == nullptr);} 
	~ListeFilms();
	void ajouterFilm(Film* film);
	void enleverFilm(const Film* film);
	shared_ptr<Acteur> trouverActeur(const std::string& nomActeur) const;
	span<Film*> enSpan() const;
	int size() const {return nElements;}
	Film** getElements() const {return elements;}

	shared_ptr<Film> chercherFilm(const function<bool(Film*)>& critere)
	{
		shared_ptr<Film> elementPointer = nullptr;

		for(Film* film : this->enSpan())
		{
			if(critere(film))
			{
				elementPointer = make_shared<Film>(*film);
			}
		}
		return elementPointer;
	}

	Film& operator[](int i)
	{
		return *elements[i];
	}

	private:
	void changeDimension(int nouvelleCapacite);

	int capacite = 0, nElements = 0;
	Film** elements = nullptr; // Pointeur vers un tableau de Film*, chaque Film* pointant vers un Film.
	bool possedeLesFilms_ = false; // Les films seront détruits avec la liste si elle les possède.
};


template <typename T>
class Liste
{

	public:

	Liste()
	{
		capacite_ = 1;
		nElements_ = 0;
		elements_ = make_unique<shared_ptr<T>[]>(capacite_);
	}

	Liste(int nElements)
	{
		capacite_ = nElements;
		nElements_ = 0;
		elements_ = make_unique<shared_ptr<T>[]>(capacite_);
	}

	Liste& operator=(const Liste& listeElements) noexcept
	{
		if(this != &listeElements)
		{
			capacite_ = listeElements.capacite_;
			elements_ = make_unique<shared_ptr<T>[]>(capacite_);
			for(shared_ptr<T> element : listeElements.spanListeElements())
			{
				this->ajouterElement(element);
			}
		}
		return *this;
	}

	shared_ptr<T> operator[](int i)
	{
		return elements_[i];
	}

	Liste(const Liste& listeElements) noexcept
		: elements_(nullptr)
		, capacite_(1)
		, nElements_(0)
	{
		*this = listeElements;
	}

	constexpr span<shared_ptr<T>> spanListeElements() const
	{
		return span(elements_.get(), capacite_);
	}


	void ajouterElement(shared_ptr<T> element)
	{
		if(nElements_ == capacite_)
		{
			nElements_ = 0;
		}

		elements_[nElements_] = element;
		nElements_++;
	}
	
	int getNElements() const
	{
		return nElements_;
	}

	void setNElements(int nElements)
	{
		nElements_ = nElements;
	}

	void setElement(int index, shared_ptr<T> element)
	{
		elements_[index] = element;
	}
	
	private:

	int capacite_ = 1, nElements_ = 0;
	unique_ptr<shared_ptr<T>[]> elements_ = nullptr; // Pointeur vers un tableau de Acteur*, chaque Acteur* pointant vers un Acteur.
};


struct Film
{
	friend ostream& operator<<(ostream& os, const Film& film);

	std::string titre, realisateur; // Titre et nom du réalisateur (on suppose qu'il n'y a qu'un réalisateur).
	int anneeSortie, recette; // Année de sortie et recette globale du film en millions de dollars
	Liste<Acteur> acteurs;
};


struct Acteur
{
	std::string nom = " "; int anneeNaissance; char sexe;
	//ListeFilms joueDans;
};