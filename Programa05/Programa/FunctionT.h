#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

class FunctionT
{
private:
    double x = 0;
    double dof;
    double funParcial;
    double functionResult;

public:
    //.i
    FunctionT(double grados)
    {
        dof = grados;
        calculoParcialFun();
    }

    //.i
    void setX(double equis)
    {
        x = equis;
        calcularFun();
    }

    //.i
    double getResul()
    {
        return functionResult;
    }

    //.i
    double gamma(double num)
    {
        if (fmod(num, 1) == 0)
        {
            return gammaInt(num);
        }
        else
        {
            return gammaNoInt(num);
        }
    };

    //.i
    double gammaInt(double num)
    {
        double result = 1;
        for (int i = 1; i <= num - 1; i++)
        {
            result *= i;
        }
        return result;
    };

    //.i
    double gammaNoInt(double num)
    {
        double result = 1;
        for (double i = num - 1; i >= 0.5; i--)
        {
            result *= i;
        }
        result *= sqrt(M_PI);
        return result;
    };

    //.i
    void calculoParcialFun()
    {
        funParcial = gamma((dof + 1.0) / 2.0) / (sqrt(dof * M_PI) * gamma(dof / 2));
    };

    //.i
    void calcularFun()
    {
        functionResult = funParcial * pow((1 + pow(x, 2) / dof), ((-dof - 1) / 2));
    };
};