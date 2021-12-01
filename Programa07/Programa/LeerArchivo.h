// Descripcion: Al crear un objeto de esta clase, se valida que el nombre del archivo exista y se procede a leer
//              los datos, con los anteriores se llenan cuatro vectores y se les asignan apuntadores, así mismo se
//              cuenta el número de cuartetos de datos y se registra como n. 
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 7 de noviembre de 2021

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class LeerArchivo
{
private:
    //.m=3
    //.d=1
    string name;
    double n = 0;
    double wk, xk, yk;
    vector<double> vtrW, vtrX, vtrY, vtrZ;
    vector<double> *ptrW = &vtrW, *ptrX = &vtrX, *ptrY = &vtrY, *ptrZ = &vtrZ;

public:
    //.i
    LeerArchivo(string na)
    {
        name = na;
        fillVectors();
    }

    vector <double> *getPtrW()
    {
        return ptrW;
    }

    vector<double> *getPtrX()
    {
        return ptrX;
    }

    vector<double> *getPtrY()
    {
        return ptrY;
    }

    vector<double> *getPtrZ()
    {
        return ptrZ;
    }

    double getN()
    {
        return n;
    }

    double getWk()
    {
        return wk;
    }

    double getXk()
    {
        return xk;
    }

    double getYk()
    {
        return yk;
    }

    //.i
    // Lee el archivo, valida que no este vacio y llena los vectores x y y con los datos correspondientes.
    void fillVectors()
    {
        ifstream archivo;
        archivo.open(name);
        // Revisa que el archivo exista
        if (archivo)
        {
            string line;
            getline(archivo, line);
            // Revisa que el archivo no este vacío
            if (line.empty())
            {
                cout << "El archivo esta vacio." << endl;
            }
            else
            {
                // Convierte el string a double
                //.m
                string auxW, auxX, auxY, auxZ;
                auxW = line;
                auxW.erase(auxW.find(','));
                wk = stoi(auxW);

                auxX = line;
                auxX.erase(0, auxX.find(',') + 1);
                auxX.erase(auxX.find(','));
                xk = stoi(auxX);

                auxY = line;
                auxY.erase(0, auxY.find(',') + 1);
                auxY.erase(0, auxY.find(',') + 1);
                yk = stoi(auxY);

                while (!archivo.eof())
                {
                    getline(archivo, line);
                    n++;
                    // Usa un aux para poder obtener ambos datos
                    auxW = line;
                    auxW.erase(auxW.find(','));
                    vtrW.push_back(stoi(auxW));

                    auxX = line;
                    auxX.erase(0, auxX.find(',') + 1);
                    auxX.erase(auxX.find(','));
                    vtrX.push_back(stoi(auxX));
                    
                    auxY = line;
                    auxY.erase(0, auxY.find(',') + 1);
                    auxY.erase(0, auxY.find(',') + 1);
                    auxY.erase(auxY.find(','));
                    vtrY.push_back(stoi(auxY));
                    
                    auxZ = line;
                    auxZ.erase(0, auxZ.find(',') + 1);
                    auxZ.erase(0, auxZ.find(',') + 1);
                    auxZ.erase(0, auxZ.find(',') + 1);
                    vtrZ.push_back(stoi(auxZ));
                }
            }
        }
        else
        {
            cout << "El archivo no existe." << endl;
        }
        archivo.close();
    }
};