#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
class Uzytkownik{
public:
	Uzytkownik() {
		this->zalogowany = false;
	}
	int getZalogowany() {
		return zalogowany;
	}
	void setzalogowany(bool s) {
		zalogowany = s;
	}
private:

	bool zalogowany;
};



int main() {
	Uzytkownik pacjent;
	cout << "Wybierz recepte\n" << "Wcisnij enter aby wybrac";
	while (std::cin.get() != '\n');
	system("CLS");
	string login, haslo;
	while (pacjent.getZalogowany() == false) {
		cout << "Podaj login i wcisnij enter: ";
		cin >> login;
		cout << "\nPodaj haslo i wcisnij enter:";
		cin >> haslo;
		pacjent.setzalogowany(true);
	}
	return 0;
}
