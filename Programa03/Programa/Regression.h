// Descripcion: Obtiene los datos de un archivo haciendo uso de la clase LeerArchivo y 
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 29 de octubre de 2021

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <limits>
#include <iomanip>
#include "LeerArchivo.h"

using namespace std;

class Regression
{
private:
    string name;
    double n, xk, r, r2, b0, b1, yk;
    vector<double> vtrX, vtrY;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0, avgX = 0, avgY = 0;

public:
    //.i
    // Asigna los valores correspondientes a los aatributos y llama a la función calculos
    Regression(string na)
    {
        name = na;
        LeerArchivo datos(name);
        n = datos.getN();
        xk = datos.getXk();
        vtrX = *datos.getPtrX();
        vtrY = *datos.getPtrY();
        calculos();
    }

    //.i
    // Calcula todas las sumatorias para que luego el proceso sea más sencillo
    void calcularSumatorias()
    {
        for (int i = 0; i < vtrX.size(); i++)
        {
            sumX += vtrX[i];
            sumY += vtrY[i];
            sumXY += vtrX[i] * vtrY[i];
            sumX2 += vtrX[i] * vtrX[i];
            sumY2 += vtrY[i] * vtrY[i];
        }
        avgX = sumX / n;
        avgY = sumY / n;
    }

    //.i
    // Realiza los calculos pertinentes para el programa
    void calculos()
    {
        calcularSumatorias();
        b1 = (sumXY - n * avgX * avgY) / (sumX2 - n * avgX * avgX);
        b0 = avgY - b1 * avgX;
        r = (n * sumXY - sumX * sumY) / sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));
        r2 = r * r;
        yk = b0 + b1 * xk;
    }

    //.i
    // Imprime los resultados
    void imprimirResul()
    {
        cout << fixed;
        cout << setprecision(0);
        cout << endl;
        cout << "  N = " << n << endl;
        cout << setprecision(0);
        cout << " xk = " << xk << endl;
        cout << setprecision(5);
        cout << "  r = " << r << endl;
        cout << " r2 = " << r2 << endl;
        cout << " b0 = " << b0 << endl;
        cout << " b1 = " << b1 << endl;
        cout << " yk = " << yk << endl;
        cout << endl;
    }
};