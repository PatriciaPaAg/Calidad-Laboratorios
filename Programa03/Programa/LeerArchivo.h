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
    // Constructor
    //.i
    LeerArchivo(string na)
    {
        name = na;
        fillVectors();
    }

    vector<double>* getPtrX(){
        return ptrX;
    }

    vector<double>* getPtrY(){
        return ptrY;
    }

    double getN(){
        return n;
    }

    double getXk(){
        return xk;
    }

    //.i
    void fillVectors()
    {
        ifstream archivo;
        archivo.open(name);
        if (archivo)
        {
            string line;
            getline(archivo, line);
            if (line.empty())
            {
                cout << "El archivo está vacío" << endl;
            }
            else
            {
                xk = stoi(line);
                string aux;
                while (!archivo.eof())
                {
                    getline(archivo, line);
                    n++;
                    aux = line;
                    aux.erase(aux.find(','));
                    vtrX.push_back(stoi(aux));
                    line.erase(0, line.find(',') + 1);
                    vtrY.push_back(stoi(line));
                }
            }
        }
        archivo.close();
    }
};