// Descripcion: este programa pide dos variables (p y dof), con un objeto de tipo
//              Simpson, se aproxima x hasta que el resultado de calcular p con x
//              la aproximada sea cercano a la p dada; que la diferencia sea menor
//              al error máximo permitido.
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la última modificación: 7 de octubre de 2021

//.b=34
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include "Simpson.h"

using namespace std;

//.i
// Función: valida que una variable sea mayor o igual que cero y que sea un numero.
// Parámetros:          strVar  string con el nombre de la variable
//                      var     variable a validar
// Valor de retorno:    var     la variable validada.
double validarVar(string strVar)
{
    double var;
    bool aux = true;
    cin.exceptions(std::istream::failbit);
    do
    {
        try
        {
            cout << "Teclea " << strVar << ": "; //.m
            cin >> var;
            aux = true;
            if (var < 0)
            {
                cout << strVar << " debe ser un numero mayor o igual a 0" << endl;
            }
        }
        catch (std::ios_base::failure &fail)
        {
            aux = false;
            cout << strVar << " debe ser un numero mayor o igual a 0" << endl; //.m
            cin.clear();
            std::string tmp;
            getline(cin, tmp);
        }
    } while (aux == false || var < 0);
    return var;
};

//.i
// Función: calcula la x para p y dof dadas, por medio de un objeto Simpson y sumando o
//          restando a x según sea necesario, hasta que la p de la x que se esta
//          calculando tenga una diferencia de menos que el errMax con la p dada.
// Parámetros:          p       p dada por usuarix
//                      dof     dof dado por usuarix
//                      errMax  error máximo aceptable, establecido en el main
//                      x       x para calcular p0
//                      d       numero que se agregara o sumara a x
//                      p0      p de la x que se busca
// Valor de retorno:    x       x final
double obtenerXf(double p, double dof, double errMax)
{
    if (p == 0.0)
    {
        return 0;
    }
    else
    {
        double x = 1.0, d = x, p0;
        Simpson simpsonC(x, dof);
        p0 = simpsonC.getP();
        while (abs(p - p0) > errMax)
        {
            d /= 2;
            while (p0 < p)
            {
                x += d;
                simpsonC.setX(x);
                p0 = simpsonC.getP();
            }
            while (p0 > p)
            {
                x -= d;
                simpsonC.setX(x);
                p0 = simpsonC.getP();
            }
        }
        return x;
    }
};

//.i
// Función: imprime en pantalla los valores.
// Parámetros:          p       p dada por usuarix
//                      dof     dof dado por usuarix
//                      x       calculada para el valor de p dado
void imprimirResul(double p, double dof, double x)
{
    cout << fixed;
    cout << setprecision(5);
    cout << endl;
    cout << "  p = " << p << endl;
    cout << setprecision(0);
    cout << "dof = " << dof << endl;
    cout << setprecision(5);
    cout << "  x = " << x << endl;
    cout << endl;
};

int main()
{
    double p, dof, x, errMax = 0.0000001; //.m
    cout << endl;
    p = validarVar("p");
    dof = validarVar("dof");
    x = obtenerXf(p, dof, errMax);
    imprimirResul(p, dof, x);
    //.d=26
}