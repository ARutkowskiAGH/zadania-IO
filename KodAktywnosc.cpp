#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;
bool sprawdzLoginHaslo(const string& login, const string& haslo, const string& sciezkaPliku) {
    ifstream plik(sciezkaPliku);

    if (!plik.is_open()) {
        cerr << "Nie mozna otworzc pliku: " << sciezkaPliku << endl;
        return false;
    }

    string linia;
    while (getline(plik, linia)) {
        size_t pozycjaSeparatora = linia.find(':');

        if (pozycjaSeparatora != string::npos) {
            string zapisanyLogin = linia.substr(0, pozycjaSeparatora);
            string zapisaneHaslo = linia.substr(pozycjaSeparatora + 1);

            if (zapisanyLogin == login && zapisaneHaslo == haslo) {
                plik.close();
                return true;
            }
        }
    }

    plik.close();
    return false;
}
// Produkt
class Uzytkownik {
public:
    Uzytkownik() {
        this->zalogowany = false;
    }

    void setZalogowany(bool s) {
        zalogowany = s;
    }
    bool getZalogowany() {
       return this->zalogowany;
    }

private:
    bool zalogowany;
};

// Budowniczy
class AutentykacjaBuilder {
public:
    virtual void zbierzDane() = 0;
    virtual void autoryzuj(Uzytkownik& uzytkownik) = 0;
};

// Konkretny Budowniczy
class AutentykacjaConsoleBuilder : public AutentykacjaBuilder {
public:
    AutentykacjaConsoleBuilder(const string& sciezkaPliku, int limitProb)
        : sciezkaPliku(sciezkaPliku), limitProb(limitProb) {}

    void zbierzDane() override {
        cout << "Podaj login: ";
        cin >> login;
        cout << "Podaj haslo: ";
        cin >> haslo;
        system("CLS");
    }

    void autoryzuj(Uzytkownik& uzytkownik) override {
        if (sprawdzLoginHaslo(login, haslo, sciezkaPliku)) {
            cout << "Logowanie udane!" << endl;
            uzytkownik.setZalogowany(true);
        }
        else {
            cout << "Bledny login lub haslo. Pozostalo prob: " << limitProb - 1 << endl;
        }
    }

private:
    string login;
    string haslo;
    string sciezkaPliku;
    int limitProb;
};

// Dyrektor
class AutentykacjaDirector {
public:
    AutentykacjaDirector(AutentykacjaBuilder* builder)
        : builder(builder) {}

    void autentykuj(Uzytkownik& uzytkownik) {
        builder->zbierzDane();
        builder->autoryzuj(uzytkownik);
    }

private:
    AutentykacjaBuilder* builder;
};



int main() {
    Uzytkownik pacjent;
    string sciezkaPliku = "plik_z_haslami.txt";
    cout << "Wybierz recepte\n" << "Wcisnij enter aby wybrac";
    while (cin.get() != '\n');
    system("CLS");

    int limitProbLogowania = 4;
    while (!pacjent.getZalogowany()) {
    AutentykacjaConsoleBuilder builder(sciezkaPliku, limitProbLogowania);
    AutentykacjaDirector director(&builder);


    director.autentykuj(pacjent);
}

    if (pacjent.getZalogowany()) {
        cout << "Twoje recepty:\n";
    }

    return 0;
}
