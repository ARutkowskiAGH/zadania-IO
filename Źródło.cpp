#include <iostream>
using namespace std;

class Produkt
{
public:
	string nazwa;
	int cena;
};


int main() {
	Produkt produkty[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "podaj nazwe produktu nr " << i + 1<<": ";
		cin >> produkty[i].nazwa;
		cout << "podaj cene produktu nr: " << i + 1 << ": ";
		cin >> produkty[i].cena;
		cout << endl;
	}

	for (int i = 0; i < 10 - 1; i++) {

		for (int j = 0; j < 10 - i - 1; j++) {
			if (produkty[j].cena < produkty[j + 1].cena) {
				swap(produkty[j], produkty[j + 1]);
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << produkty[i].nazwa << " "<< produkty[i].cena << endl;
	}
	return 0;
}