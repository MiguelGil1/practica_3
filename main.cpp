/*
 El siguiente programa tiene como principal obejetivo codificar y decodificar
 informacion obtenida por archivos de entrada.

 En primera instancia se muestra por consola un menu principal el cual le permite al
 usuario ingresar una opcion entre las siguentes:
 1.) Codificar
 2.) Decodificar
 3.) Salir.

 Se modela y gestiona por medio de un switch - case la opcion ingresada
 1.) Codificar: Se procederia a pedir tambien por consola una semila de codificacion
                metodo de codificacion, nombre de archivo de entrada y de salida, que tendran
                como ubicacion predeterminada ../lab_3_pt_1/db
 2.) Decodificar:Se procederia a pedir tambien por consola una semila de decodificacion
                metodo de decodificacion, nombre de archivo de entrada y de salida, que tendran
                como ubicacion predeterminada ../lab_3_pt_1/db
 3.) Salir: Se acabara la ejecucion de programa

 4.) Si el usuario ingresa un numero diferente de 1,2 y 3: Se imprimira en pantalla
                "Opcion fuera de rango" Y se volvera a mostrar el mismo menu.
*/

#include <iostream>
#include "codificar_decodificar.h"

using namespace std;

int main(){
    //INICIALIZACION DE VARIABLES
    bool key = true;
    int opt = 0, semilla = 0, metodo_codi = 0, metodo_deco = 0;
    string archivo_entrada = "", archivo_salida = "";
    codificar_decodificar dato;
    //INICIALIZACION DE VARIABLES
    while (key){
        cout << "MENU PRINCIPAL." << endl;
        cout << "1.) Codificar datos." << endl;
        cout << "2.) Decodificar datos." << endl;
        cout << "3.) Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opt;
        switch (opt){
        case 1:
            cout << "Ingrese la semilla de codificacion: ";
            cin >> semilla;
            cout << "Ingrese metodo de codificacion [1-2]: ";
            cin >> metodo_codi;
            /*
                CICLO PARA EVALUAR SI LA OPCION DE CODIFICACION
                Se encuentra dentro de los rangos estipulados, 1 y 2
                Si el usuario ingresa un numero mayor a 2 y menor a 1
                Se le pedira nuevamente un metodo de codificado.
            */
            while(metodo_codi > 2 || metodo_codi < 1){
                cout << "Opcion fuera de rango." << endl;
                cout << "Ingrese metodo de codificacion [1-2]: ";
                cin >> metodo_codi;
            }
            cout << "Ingrese el nombre del archivo de entrada: ";
            cin.get();
            getline(cin,archivo_entrada);
            cout << "Ingrese el nombre del archivo de salida: ";
            cin.get();
            getline(cin,archivo_salida);
            dato.codificar(semilla,metodo_codi,archivo_entrada,archivo_salida);
            break;
        case 2:
            cout << "Ingrese la semilla de codificacion: ";
            cin >> semilla;
            cout << "Ingrese metodo de decodificacion [1-2]: ";
            cin >> metodo_deco;
            /*
                CICLO PARA EVALUAR SI LA OPCION DE DECODIFICACION
                Se encuentra dentro de los rangos estipulados, 1 y 2
                Si el usuario ingresa un numero mayor a 2 y menor a 1
                Se le pedira nuevamente un metodo de decodificado.
            */
            while(metodo_deco > 2 || metodo_deco < 1){
                cout << "Opcion fuera de rango." << endl;
                cout << "Ingrese metodo de codificacion [1-2]: ";
                cin >> metodo_deco;
            }
            cout << "Ingrese el nombre del archivo de entrada: ";
            cin.get();
            getline(cin,archivo_entrada);
            cout << "Ingrese el nombre del archivo de salida: ";
            cin.get();
            getline(cin,archivo_salida);
            dato.decodificar(semilla,metodo_deco,archivo_entrada,archivo_salida);
            break;
        case 3:
            //Se le lleva a la variabel booleana key el valor de false
            //Para que se rompa el ciclo while
            key = false;
            cout << "Gracias por utilizar nuestros servicios! :)" << endl;
            break;
        default:
            cout << "Opcion fuera de rango" << endl;
            break;
        }
        if(opt != 3){
            system("PAUSE");
            system("CLS");
        }

    }
    return 0;
}
