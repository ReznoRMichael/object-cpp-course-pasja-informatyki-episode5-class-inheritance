#include <iostream>
#undef __STRICT_ANSI__  // pozwala uzywac M_PI w gcc
#include <math.h>   // dla M_PI

using namespace std;

class Punkt
{
    float x,y;
    string nazwa;

public:
    void wyswietl()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
    Punkt(string n="S", float a=0, float b=0) // konstruktor
    {
        nazwa = n;
        x = a;
        y = b;
    }
};

class Kolo :public Punkt    // klasa pochodna Kolo dziedziczy publicznie z klasy Punkt
{
    string nazwa;

protected:
    float r;

public:
    void wyswietl()
    {
        cout << "Kolo o nazwie: " << nazwa << endl;
        cout << "Srodek kola: " << endl;
        Punkt::wyswietl();
        cout << "Promien: " << r << endl;
        cout << "Pole kola: " << M_PI*r*r << endl;
    }

    Kolo(string nk="Kolko", string np="S", float a=0, float b=0, float pr=1)
    :Punkt(np,a,b)  // przywolanie konstruktora z klasy Punkt do przypisania zmiennych
    {
        nazwa = nk;
        r = pr;
    }
};

class Kula :public Kolo
{
    string nazwa;

public:
    void wyswietl()
    {
        Kolo::wyswietl();
        cout << "Objetosc kuli: " << (4/3)*M_PI*r*r*r << endl;
    }

    Kula(string nku="Kula", string npk="S", float a=0, float b=0, float pr=1.5)
    :Kolo(nku,npk,a,b,pr)
    {
        nazwa = nku;
    }
};

int main()
{
    Kula ku1;
    ku1.wyswietl();

    return 0;
}
