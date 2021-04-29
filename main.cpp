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
