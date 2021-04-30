#ifndef CODIFICAR_DECODIFICAR_H
#define CODIFICAR_DECODIFICAR_H
#include <iostream>
using namespace std;
/*
 Se crea la clase codiicar_decodificar, la cual cuenta con dos funciones publicas:

    1.) void codificar(int,int,string, string): Funcion que se encarga de la codificacion de
    un archivo .txt para su correcto uso se debe crear un objeto tipo codificar_decodificar e
    invocar la funcion codificar, la cual cuenta con 4 parametros de entrada:
        -Un entero que representa la semilla de codificadcion
        -Un entero que representa el metodo de codificacion
        -Un string que representa el nombre del archivo de entrada
        -Un string que representa el nombre del archivo de salida
    Se debe tener en cuenta la direccion  relativa de los archivos es:
    ../lab_3_pt_1/db/
    Lo anterios es bastante importante

    2.) void decodificar(int,int,string,string): Funcion que se enrga de la decodificacion de
    un archivo .bin, para su correcto uso se debe crear un objeto tipo codificar_decodificar e
    invocar la funcion decodificar, la cual cuenta con 4 parametros de entrada:
        -Un entero que representa la semilla de codificadcion
        -Un entero que representa el metodo de codificacion
        -Un string que representa el nombre del archivo de entrada
        -Un string que representa el nombre del archivo de salida
    Se debe tener en cuenta la direccion  relativa de los archivos es:
    ../lab_3_pt_1/db/
    Lo anterios es bastante importante

    NOTA IMPORTANTE:
    1.) NO SE GARANTIZA UN CORRECTO FUNCIONAMIENTO SI LOS ARCHIVO NO SE ENCUENTRAN UBICADOS
    EN DICHA RUTA

    2.) Para garantizar un correcto DECODIFICADO se debe tener en cuenta dos cosas, se debe ingresar
    la misma semilla de decodificacion y el mismo metodo de decodificacion
    De lo contrario no se asegura un resultado satisfactorio
*/
class codificar_decodificar{
public:
    void codificar(int,int,string, string);
    void decodificar(int,int,string,string);
};

#endif // CODIFICAR_DECODIFICAR_H
