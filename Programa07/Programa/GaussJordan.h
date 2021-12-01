// Descripcion: Se crea la matriz correspondiente y se utiliza el método de Gauss Jordan
//              para resolverla, regresa un apuntador a un vector con los datos.
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 8 de noviembre de 2021

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GaussJordan
{
private:
    double matrix[4][5];
    vector<double> vtrResul;
    vector<double> *ptrVtrResul =  &vtrResul;
    int ren = 4, col = 5;

public:
    //.i
    GaussJordan(double n, double sumW = 0, double sumX = 0, double sumY = 0, double sumZ = 0, double sumW2 = 0, double sumX2 = 0, double sumY2 = 0, double sumWX = 0, double sumWY = 0, double sumWZ = 0, double sumXY = 0, double sumXZ = 0, double sumYZ = 0)
    {
        matrix[0][0] = n;
        matrix[0][1] = matrix[1][0] = sumW;
        matrix[0][2] = matrix[2][0] = sumX;
        matrix[0][3] = matrix[3][0] = sumY;
        matrix[0][4] = sumZ;
        matrix[1][1] = sumW2;
        matrix[1][2] = matrix[2][1] = sumWX;
        matrix[1][3] = matrix[3][1] = sumWY;
        matrix[1][4] = sumWZ;
        matrix[2][2] = sumX2;
        matrix[2][3] = matrix[3][2] = sumXY;
        matrix[2][4] = sumXZ;
        matrix[3][3] = sumY2;
        matrix[3][4] = sumYZ;
        resolverGJ();
    }


    vector<double> *getPtrVtrResul()
    {
        return ptrVtrResul;
    }

    //.i
    void imprimir(){
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cout << matrix[i][j] << "\t\t";
            }
            cout << endl;
        }
        cout << "\n\n\n" << endl;
    }

    //.i
    void resolverGJ()
    {
        for (int contador = 0; contador < ren; contador++)
        {
            double divisor = matrix[contador][contador];
            for (int j = contador; j < col; j++)
            {
                matrix[contador][j] = matrix[contador][j] / divisor;
            }
            for (int i = 0; i < ren; i++)
            {
                if (i != contador)
                {
                    double num = -1 * matrix[i][contador];
                    for (int j = contador; j < col; j++)
                    {
                        matrix[i][j] = matrix[contador][j] * num + matrix[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < ren; i++)
        {
            vtrResul.push_back(matrix[i][col - 1]);
        }
    }
};