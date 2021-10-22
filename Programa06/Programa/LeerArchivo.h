#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class LeerArchivo
{
private:
    string nombreArchivo;
    double xK, arrX[100], arrY[100];
    double *ptrArrX, *ptrArrY;

public:
    // Constructores

    LeerArchivo(string nameFile)
    {
        nombreArchivo = nameFile;
    }

    // Metodos GET
    
    double getXk(){
        return xK;
    }

    double *getArrX(){
        return ptrArrX;
    }

    double *getArrY(){
        return ptrArrY;
    }

    // funcion: abre el archivo, verifica si existe y si esta vacio. Cuenta las lineas en blanco, comentarios las demás lineas, calcula el total y asigna los valores a las variables.
    void contarLineas()
    {
        ifstream archivo;
        archivo.open(nombreArchivo);
        if (archivo)
        {
            string line;
            getline(archivo, line);

            
        }
        archivo.close();
    }
};