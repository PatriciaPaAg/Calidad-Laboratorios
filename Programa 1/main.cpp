// Descripcion: este programa lee el nombre de un archivo, valida que exista, cuenta cuantas lineas en blanco, comentadas y las restantes. Además imprime los resultados en pantalla.
// Autora: Patricia Palula Aguilar      Matricula: A01732537
// Fecha de la ultima modificacion: 26 de agosto de 2021

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class LeerArchivo
{
private:
    string nombreArchivo;
    int linBlancas = 0, linComent = 0, linCodigo = 0, linTotal = 0;

public:
    // Constructores
    LeerArchivo()
    {
        nombreArchivo = "";
    }

    LeerArchivo(string nameFile)
    {
        nombreArchivo = nameFile;
    }

    // Metodos GET
    string getNombreArchivo()
    {
        return nombreArchivo;
    }

    int getLinBlancas()
    {
        return linBlancas;
    }

    int getLinComent()
    {
        return linComent;
    }

    int getLinCodigo()
    {
        return linCodigo;
    }

    int getLinTotal()
    {
        return linTotal;
    }

    // Metodos SET
    void setNombreArchivo(string name)
    {
        nombreArchivo = name;
    }

    void setLinBlancas(int white)
    {
        linBlancas = white;
    }

    void setLinComent(int comm)
    {
        linComent = comm;
    }

    void setLinCodigo(int code)
    {
        linCodigo = code;
    }

    void setLinTotal(int tot)
    {
        linTotal = tot;
    }

    // Metodos

    // funcion: lee de la pantalla el nombre del archivo y lo asigna a la variable correspondiente.
    void leerNombre()
    {
        cout << "\nTeclea el nombre del archivo: ";
        cin >> nombreArchivo;
    }

    // funcion: abre el archivo, verifica si existe y si esta vacio. Cuenta las lineas en blanco, comentarios las demás lineas, calcula el total y asigna los valores a las variables.
    void contarLineas()
    {
        ifstream archivo;
        archivo.open(nombreArchivo);
        if (archivo)
        {
            string line;
            while (!archivo.eof())
            {
                getline(archivo, line);
                line.erase(0, line.find_first_not_of(" \t\r\n"));
                //cout << "line: " << line << endl;
                if (line.length() == 0)
                {
                    linBlancas++;
                    //cout << "linBlancas++" << endl;
                }
                else
                {
                    switch (line[0])
                    {
                    case '/':
                        if (line[1] == '/')
                        {
                            linComent++;
                            //cout << "linCommen++" << endl;
                            break;
                        }
                        else if (line[1] == '*')
                        {
                            while (line.find("*/") == -1)
                            {
                                linComent++;
                                //cout << "linComent++" << endl;
                                getline(archivo, line);
                            }
                            linComent++;
                            //cout << "linComent++" << endl;
                            break;
                        }
                        linCodigo++;
                        //cout << "linCodigo++" << endl;
                        break;

                    default:
                        linCodigo++;
                        //cout << "linCodigo++" << endl;
                        break;
                    }
                }
            }
        }
        linTotal = linBlancas + linComent + linCodigo;
    }
<<<<<<< HEAD

    void printData()
    {
        cout << endl;
        cout << "Nombre del archivo: " << nombreArchivo << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Cantidad de lineas en blanco: " << linBlancas << endl;
        cout << "Cantidad de lineas con comentarios: " << linComent << endl;
        cout << "Cantidad de lineas con codigo: " << linCodigo << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Cantidad total de lineas: " << linTotal << endl;
        cout << endl;
    }
};

int main()
{
    LeerArchivo file;
    file.leerNombre();
    file.contarLineas();
    file.printData();
    return 0;
}
=======
};
//Hola como estas
>>>>>>> fac0b90f9959628599327b039422762f4a83c752
