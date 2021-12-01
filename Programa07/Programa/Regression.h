// Descripcion: Obtiene los datos de un archivo haciendo uso de la clase LeerArchivo y
//              genera una matriz que manda a la clase GaussJordan.
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 7 de noviembre de 2021

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <limits>
#include <iomanip>
#include "LeerArchivo.h"
#include "GaussJordan.h"

using namespace std;

class Regression
{
private:
    //.m=3
    string name;
    double n, wk, xk, yk, b0, b1, b2, b3, zk;
    vector<double> vtrW, vtrX, vtrY, vtrZ, vtrResul;
    double sumW = 0, sumX = 0, sumY = 0, sumZ = 0;
    double sumW2 = 0, sumX2 = 0, sumY2 = 0;
    double sumWX = 0, sumWY = 0, sumWZ = 0, sumXY = 0, sumXZ = 0, sumYZ = 0;

public:
    //.i
    // Asigna los valores correspondientes a los aatributos y llama a la función calculos
    Regression(string na)
    {
        name = na;
        LeerArchivo datos(name);
        n = datos.getN();
        wk = datos.getWk();
        xk = datos.getXk();
        yk = datos.getYk();
        vtrW = *datos.getPtrW();
        vtrX = *datos.getPtrX();
        vtrY = *datos.getPtrY();
        vtrZ = *datos.getPtrZ();
        calculos();
    }

    //.i
    // Calcula todas las sumatorias para que luego el proceso sea más sencillo
    void calcularSumatorias()
    {
        for (int i = 0; i < vtrX.size(); i++)
        {
            sumW += vtrW[i];
            sumX += vtrX[i];
            sumY += vtrY[i];
            sumZ += vtrZ[i];
            sumW2 += vtrW[i] * vtrW[i];
            sumX2 += vtrX[i] * vtrX[i];
            sumY2 += vtrY[i] * vtrY[i];
            sumWX += vtrW[i] * vtrX[i];
            sumWY += vtrW[i] * vtrY[i];
            sumWZ += vtrW[i] * vtrZ[i];
            sumXY += vtrX[i] * vtrY[i];
            sumXZ += vtrX[i] * vtrZ[i];
            sumYZ += vtrY[i] * vtrZ[i];
        }
    }

    //.i
    // Realiza los calculos pertinentes para el programa
    void calculos()
    {
        calcularSumatorias();
        
        GaussJordan resolverMat(n, sumW, sumX, sumY, sumZ, sumW2, sumX2, sumY2, sumWX, sumWY, sumWZ, sumXY, sumXZ, sumYZ);
    
        vtrResul = *resolverMat.getPtrVtrResul();

        b0 = vtrResul[0];
        b1 = vtrResul[1];
        b2 = vtrResul[2];
        b3 = vtrResul[3];

        zk = b0 + wk * b1 + xk * b2 + yk * b3;
    }

    //.i
    //.d=8
    // Imprime los resultados
    void imprimirResul()
    {
        cout << fixed;
        cout << setprecision(0);
        cout << endl;
        cout << "  N = " << n << endl;
        cout << setprecision(5);
        cout << " wk = " << wk << endl;
        cout << " xk = " << xk << endl;
        cout << " yk = " << yk << endl;
        cout << "------------" << endl;
        cout << " b0 = " << b0 << endl;
        cout << " b1 = " << b1 << endl;
        cout << " b2 = " << b2 << endl;
        cout << " b3 = " << b3 << endl;
        cout << "------------" << endl;
        cout << " zk = " << zk << endl;
        cout << endl;
    }
};