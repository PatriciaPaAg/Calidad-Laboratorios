// Descripcion: Este programa recibe un archivo con una xk y parejas de datos ordenados (x,y), estos datos son
//              enviados a la clase Regression en donde serán leidos con la clase LeerArchivo y posteriormente
//              procesados. Se imprimen en orden N, xk, r, r2, b0, b1 y yk. 
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 29 de octubre de 2021

//.b=103
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
    // Se crea un objeto de tipo Regression y se le pasa el nombre del archivo
    Regression lineal(name);
    lineal.imprimirResul();
    return 0;
}
