#include <iostream>
#include <string>
#include "FunctionT.h"

using namespace std;

class Simpson
{
private:
    double x, dof, w;
    int n;
    double pI, pF;
    double errMax = 0.0000001; //.m

public:
    //.i
    Simpson(double equis, double grados)
    {
        x = equis;
        dof = grados;
        n = 10;
        obtenerPf();
    }

    double getP()
    {
        return pF;
    }

    //.i
    void setX(double equis)
    {
        x = equis;
        n = 10;
        obtenerPf();
    }

    //.i
    double calcularP(FunctionT fun)
    {
        double sum = 0;
        w = x / n;
        fun.setX(0);
        sum += fun.getResul();
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 1)
            {
                fun.setX(i * w);
                sum += 4 * fun.getResul();
            }
            else
            {
                fun.setX(i * w);
                sum += 2 * fun.getResul();
            }
        }
        fun.setX(x);
        sum += fun.getResul();
        return w / 3 * sum;
    };

    //.i
    void obtenerPf()
    {
        FunctionT fun(dof);
        pI = calcularP(fun);
        n *= 2;
        pF = calcularP(fun);
        while (pF - pI > errMax)
        {
            pI = pF;
            n *= 2;
            pF = calcularP(fun);
        }
    };

    //.i
    void imprimirResul()
    {
        cout << endl;
        cout << "  x = " << x << endl;
        cout << "dof = " << dof << endl;
        cout << "  p = " << pF << endl;
        cout << endl;
    };
};