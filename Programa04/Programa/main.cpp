// Descripcion: este programa crea un objeto de tipo Simpson y con ayuda de la clase del mismo nombre
//              y de la clase FunctionT calcula p = t(x, dof) integrando de 0 a x la "distribucion t"
//              con dof grados de libertad por el método de Simpson.
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 30 de septiembre de 2021

#include <iostream>
#include <string>
#include "Simpson.h"

using namespace std;

int main() {
    double x, dof;
    bool aux = true;
    cin.exceptions(std::istream::failbit);
    do {
        try {
            cout << "Teclea x: ";
            cin >> x;
            aux = true;
        }
        catch (std::ios_base::failure &fail) {
            aux = false;
            cout << "x debe ser un numero mayor o igual a 0" << endl;
            cin.clear();
            std::string tmp;
            getline(cin, tmp);
        }
    } while (aux == false || x < 0);
    do {
        try {
            cout << "Teclea dof: ";
            cin >> dof;
            aux = true;
        }
        catch (std::ios_base::failure &fail) {
            aux = false;
            cout << "dof debe ser un numero mayor o igual a 0" << endl;
            cin.clear();
            std::string tmp;
            getline(cin, tmp);
        }
    } while (aux == false || dof < 0);
    Simpson area(x, dof);
    area.imprimirResul();
}