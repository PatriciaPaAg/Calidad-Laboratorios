// Descripcion: 
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 22 de agosto de 2021

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Regression.h"

using namespace std;

//.d=71
int main()
{
    string name;
    cout << "Ingresa el nombre del archivo: ";
    cin >> name;
    Regression lineal(name);
    lineal.imprimirResul();
    return 0;
}
