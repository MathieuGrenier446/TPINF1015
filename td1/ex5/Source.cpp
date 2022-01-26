#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
int main() {
	using namespace std;
	int i;
	std::list<int> myList = std::list<int>();
	int liste1[10] = {};
	for (i = 0; i < 10; i++) {
		cout << "entrez l'element " << i + 1 << " : "; cin >> liste1[i];

	}

	for (int valeur : liste1) {
		if (valeur % 2 == 0) {
			myList.push_front(valeur);
		}
		else {
			myList.push_back(valeur);
		}

	}
	for (int x : myList) {

		std::cout << x << ' ';


	}
}
     
    

    

    
	


