// Descripcion: este programa
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la última modificación: 21 de octubre de 2021

//.b=34
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Simpson.h"

using namespace std;

//.i
string validarName()
{
    string name;
    cout << "Ingrese el nombre del archivo: ";
    cin >> name;
    ifstream archivo;
    do
    {
        archivo.open(name);
        if (!archivo)
        {
            cout << "El archivo no existe" << endl;
        }
        archivo.close();
        cin >> name;
    } while (!archivo);
    return name;
};

//.d=10

int main()
{
    cout << endl;
    string name = validarName();
}