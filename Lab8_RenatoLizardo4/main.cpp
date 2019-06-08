#include <iostream>
#include <string>
#include <stdlib.h>

#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Torre.h"
#include "Pieza.h"
#include "Rey.h"

using namespace std;

int filasT(char);
void juego(char **);
void llenar();       //jugada de las negras
void RecrearJuego(); //jugada de las negras

void movimiento1(char **);
void movimiento2(char **);

void guardar();

char **crearMatriz(int);
void liberarMatriz(char **&, int);
void printMatrix(char **, int);

int tamano = 0;
char **tablero = NULL;
string nombre1, nombre2 , partida;

vector<string> movimientos;
vector<string> movimientos2;

int main()
{
    int opcion = 0;

    tamano = 8;
    int turno = 0;
    tablero = crearMatriz(tamano);

    bool salir = false;

    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            tablero[i][j] = '-';
        }
    }

    cout << "INgrese el nombre del primer jugador" << endl;
    cin >> nombre1;

    cout << "INgrese el nombre del segundo jugador" << endl;
    cin >> nombre2;

      cout << "INgrese el nombre de la partida" << endl;
    cin >> partida;

    while (salir == false)
    {

        cout << "Ingrese una de las siguientes opciones \n1)Para Iniciar Partida \n2)Para Recrear Partida" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            llenar();

            juego(tablero);
            break;

        case 2:
            RecrearJuego();

            break;

        default:

            salir = true;
            break;
        }
    }

    printMatrix(tablero, tamano);

    liberarMatriz(tablero, tamano);

    return 0;
}

void juego(char **m)
{
    
    int s = 0;
    int i = 0;
    bool salir = false;

    while (salir == false)
    {


        printMatrix(m, 8);
        i++;

        if (i % 2 == 0)
        {
            movimiento2(m);
            
        }
         if (i % 2 != 0)
        {
            movimiento1(m);
            
            
        }

        cout<<"INgrese s 1 para salir" <<endl;
        cin >> s;
          

        

       
    }
}

void movimiento1(char **matriz)
{
    //fstream archivo("registro.txt");

    int fila = 0, cols = 0;
    int fila2 = 0, cols2 = 0;
    string coordenada = "";
    string primeraC, segundaC;
    string coordenada2 = "";
    bool correcto = false;
    char caracter;

    // vector<string> coordenadas;

    Pieza* pieza;

    cout << "INgrese la columna en la que esta la pieza" << endl;
    cin >> coordenada;

    cols = filasT(coordenada[1]);
    fila = coordenada[2] - 48;

    cols2 = filasT(coordenada[4]);
    fila2 = coordenada[5] - 48;

    cout << "hola: " << cols << endl;
    cout << " hola2: " << fila << endl;

    while (correcto == false)
    {
        if (fila > 7 || cols > 7 || fila < 0 || cols < 0 || matriz[fila][cols] != 'T' && matriz[fila][cols] != 'R' )
        {
            cout << "eso no existe" << endl;

            cout << "INgrese la columna en la que esta la pieza" << endl;
            cin >> coordenada;

            cols = filasT( coordenada[1]);
            fila = coordenada[2] - 48;

            cols2 = filasT(coordenada[4]);
            fila2 = coordenada[5] - 48;


        }
        else
        {
            caracter = matriz[fila][cols];
            matriz[fila][cols] = '-';
            correcto = true;
        }
    }

    //coordenadas.clear();

    if (caracter == 'T')
    {
        cout<<"a-----------================="<<endl;
         movimientos.push_back(coordenada);
        pieza = new Torre();
    }

    if (caracter == 'R')
    {
        movimientos2.push_back(coordenada);
        pieza = new Rey();
    }


    cout << "hola:ss:: " << cols2 << endl;
    cout << " hola2:ss:: " << fila2 << endl;

    correcto = false;

    while (correcto == false)
    {

        if (pieza->validarMovimiento(fila, cols, fila2, cols2) == true)
            {
                cout<<"asdsa"<<endl;
                matriz[fila2][cols2] = 'T';

                correcto = true;
            }else{
                cout<<"no se puede mover asi" <<endl;
            }
        
    }

    //coordenadas.clear();
}

void movimiento2(char **matriz)
{
    int fila = 0, cols = 0;
    int fila2 = 0, cols2 = 0;
    string coordenada = "";
    string coordenada2 = "";
    bool correcto = false;
    char caracter;

    //vector<string> coordenadas;

    Pieza *pieza;

    cout << "INgrese la columna en la que esta la pieza" << endl;
            cin >> coordenada;

            cols = filasT(coordenada[1]);
            fila = coordenada[2] - 48;

            cols2 = filasT(coordenada[4]);
            fila2 = coordenada[5] - 48;


    while (correcto == false)
    {
        if (fila > 7 || cols > 7 || fila < 0 || cols < 0 || matriz[fila][cols] == '-')
        {
            cout << "eso no existe" << endl;

             cout << "INgrese la columna en la que esta la pieza" << endl;
            cin >> coordenada;

            cols = filasT( coordenada[1]);
            fila = coordenada[2] - 48;

            cols2 = filasT(coordenada[4]);
            fila2 = coordenada[5] - 48;
        }
        else
        {
            caracter = matriz[fila][cols];
            matriz[fila][cols] = '-';
            correcto = true;
        }
    }

    if (caracter == 't')
    {

        movimientos.push_back(coordenada);
        pieza = new Torre();
    }

    if (matriz[fila][cols] == 'r')
    {
        movimientos2.push_back(coordenada);
        
        pieza = new Rey();
    }

        correcto = false;

while (correcto == false)
{

     if (pieza->validarMovimiento(fila, cols, fila2, cols2))
            {
                matriz[fila2][cols2] = pieza->getForma();
                correcto = true;
            }
            else{
                cout<<"ESo no existe"<<endl;
            }
}
  
    

  
}

void RecrearJuego()
{
}

/****-----LLenar matriz y mas*/

void llenar()
{

    int pieza1;

    tablero[0][4] = 'R';
    tablero[7][4] = 'R';

    cout << "INgrese el tipo de pieza \n1)Torre \n2)Alfil \n3)Caballo \n4)Peon \n5)Reina" << endl;
    cin >> pieza1;

    bool correcto = false;

    while (correcto == false)
    {
        switch (pieza1)
        {
        case 1:
            tablero[0][7] = 'T';
            tablero[7][0] = 't';

            correcto = true;

            break;

        case 2:
            tablero[0][5] = 'A';
            tablero[7][2] = 'a';

            correcto = true;

            break;

        case 3:

            tablero[0][6] = 'C';
            tablero[7][1] = 'c';

            correcto = true;

            break;

        case 4:
            tablero[1][4] = 'P';
            tablero[6][4] = 'p';

            correcto = true;

            break;

        case 5:

            tablero[0][3] = 'Q';
            tablero[7][3] = 'q';

            correcto = true;

            break;

        default:

            correcto = false;
            break;
        }
    }
}


void guardar(){
fstream archivo("registro.txt");


         if (!archivo.is_open())
    {
        archivo.open("registro.txt", ios::app);
    }


    archivo<<partida <<endl;
    archivo <<"Torre"<<endl;
    for (int i = 0; i < movimientos.size()-1; i++)
    {
         archivo<<movimientos[1];
    }


    archivo <<"------------------"<<endl;
    archivo <<"Rey"<<endl;
    for (int i = 0; i < movimientos2.size()-1; i++)
    {
         archivo<<movimientos2[1];
    }

    archivo.close();

}


//----------------------------------------------Aqui van los metodos de la matriz ---------------------------
char **crearMatriz(int size)
{

    char **matrix = NULL;
    matrix = new char *[size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new char[size];
    }

    return matrix;
}

void printMatrix(char **matrix, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "[";
            cout << matrix[i][j];
            cout << "]";
        }
        cout << endl;
    }
}

void liberarMatriz(char **&matrix, int size)
{

    for (int i = 0; i < size; i++)
    {

        delete[] matrix[i];
        matrix[i] = NULL;
    }

    if (matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}

int filasT(char coordenada)
{

    int fila = 0;

    if (coordenada == 'A' || coordenada == 'a')
    {
        fila = 0;
    }
    else if (coordenada == 'B' || coordenada == 'b')
    {
        fila = 1;
    }
    else if (coordenada == 'C' || coordenada == 'c')
    {
        fila = 2;
    }
    else if (coordenada == 'D' || coordenada == 'd')
    {

        fila = 3;
    }
    else if (coordenada == 'E' || coordenada == 'e')
    {
        fila = 4;
    }
    else if (coordenada == 'F' || coordenada == 'f')
    {
        fila = 5;
    }
    else if (coordenada == 'G' || coordenada == 'g')
    {

        fila = 6;
    }
    else if (coordenada == 'H' || coordenada == 'h')
    {

        fila = 7;
    }

    return fila;
}