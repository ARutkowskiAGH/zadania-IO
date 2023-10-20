#include <iostream>
using namespace std;




int main() {
	int tablica[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> tablica[i];
	}
	int counter = 0;
	for (int i = 0; i < 10; i++)
	{
		
		if (tablica[i] < 0) counter++;
	}
	int* tablicaNowa = new int[counter];
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		
		if (tablica[i] < 0) {
			tablicaNowa[j] = tablica[i];
			j++;
		}
	}
	for (int i = 0; i < counter; i++)
	{
		cout << tablicaNowa[i]<<" ";
	}
	cout << endl << "liczb tych bylo: " << counter << endl << "Pominieto liczb: " << 10 - counter;
	return 0;
}