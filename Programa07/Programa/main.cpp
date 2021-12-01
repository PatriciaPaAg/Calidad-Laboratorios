// Descripcion: Valida el nombre del archivo y luego calcula los parametros de
//              regresion lineal y una zk mejorada.
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 8 de noviembre de 2021

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Regression.h"

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

//.d=71
int main()
{
    string name = validarName();
    Regression lineal(name);
    lineal.imprimirResul();
    return 0;
}
