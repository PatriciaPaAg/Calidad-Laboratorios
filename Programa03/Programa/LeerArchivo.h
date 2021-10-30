// Descripcion: Al crear un objeto de esta clase, se valida que el nombre del archivo exista y se procede a leer
//              los datos, con los anteriores se llenan dos vectores y se les asignan apuntadores, así mismo se
//              cuenta el número de parejas de datos y se registra como n. 
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 29 de octubre de 2021

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class LeerArchivo
{
private:
    string name;
    double n = 0;
    double xk;
    vector<double> vtrX;
    vector<double> vtrY;
    vector<double> *ptrX = &vtrX, *ptrY = &vtrY;

public:
    //.i
    LeerArchivo(string na)
    {
        name = na;
        fillVectors();
    }

    vector<double> *getPtrX()
    {
        return ptrX;
    }

    vector<double> *getPtrY()
    {
        return ptrY;
    }

    double getN()
    {
        return n;
    }

    double getXk()
    {
        return xk;
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
                xk = stoi(line);
                string aux;
                while (!archivo.eof())
                {
                    getline(archivo, line);
                    n++;
                    // Usa un aux para poder obtener ambos datos
                    aux = line;
                    aux.erase(aux.find(','));
                    vtrX.push_back(stoi(aux));
                    line.erase(0, line.find(',') + 1);
                    vtrY.push_back(stoi(line));
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