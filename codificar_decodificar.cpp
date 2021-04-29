#include "codificar_decodificar.h"
#include <fstream>
#include <cmath>

string convertir_str_to_in(string dato){
    string chars [126][2]={
    {" ","00100000"},
    {"!","00100001"},
    {"commilla","00100010"},
    {"#","00100011"},
    {"$","00100100"},
    {"%","00100101"},
    {"&","00100110"},
    {"'","00100111"},
    {"(","00101000"},
    {")","00101001"},
    {"*","00101010"},
    {"+","00101011"},
    {",","00101100"},
    {"-","00101101"},
    {".","00101110"},
    {"/","00101111"},
    {"0","00110000"},
    {"1","00110001"},
    {"2","00110010"},
    {"3","00110011"},
    {"4","00110100"},
    {"5","00110101"},
    {"6","00110110"},
    {"7","00110111"},
    {"8","00111000"},
    {"9","00111001"},
    {":","00111010"},
    {";","00111011"},
    {"<","00111100"},
    {"=","00111101"},
    {">","00111110"},
    {"?","00111111"},
    {"@","01000000"},
    {"A","01000001"},
    {"B","01000010"},
    {"C","01000011"},
    {"D","01000100"},
    {"E","01000101"},
    {"F","01000110"},
    {"G","01000111"},
    {"H","01001000"},
    {"I","01001001"},
    {"J","01001010"},
    {"K","01001011"},
    {"L","01001100"},
    {"M","01001101"},
    {"N","01001110"},
    {"O","01001111"},
    {"P","01010000"},
    {"Q","01010001"},
    {"R","01010010"},
    {"S","01010011"},
    {"T","01010100"},
    {"U","01010101"},
    {"V","01010110"},
    {"W","01010111"},
    {"X","01011000"},
    {"Y","01011001"},
    {"Z","01011010"},
    {"[","01011011"},
    {"back_slash","01011100"},
    {"]","01011101"},
    {"^","01011110"},
    {"_","01011111"},
    {"`","01100000"},
    {"a","01100001"},
    {"b","01100010"},
    {"c","01100011"},
    {"d","01100100"},
    {"e","01100101"},
    {"f","01100110"},
    {"g","01100111"},
    {"h","01101000"},
    {"i","01101001"},
    {"j","01101010"},
    {"k","01101011"},
    {"l","01101100"},
    {"m","01101101"},
    {"n","01101110"},
    {"o","01101111"},
    {"p","01110000"},
    {"q","01110001"},
    {"r","01110010"},
    {"s","01110011"},
    {"t","01110100"},
    {"u","01110101"},
    {"v","01110110"},
    {"w","01110111"},
    {"x","01111000"},
    {"y","01111001"},
    {"z","01111010"},
    {"{","01111011"},
    {"|","01111100"},
    {"}","01111101"},
    {"~","01111110"}
   };
    string bin = "";
    for(int i = 0; i < int(dato.length()); i++){
        if(dato[i] != '\n'){
            bin += chars[int(dato[i])-32][1];
        }else{
            bin += "00001010";
        }
    }
    return bin;
}
string convertir_bin_to_str(string binarios){
    string chars [126][2]={
    {" ","00100000"},
    {"!","00100001"},
    {"commilla","00100010"},
    {"#","00100011"},
    {"$","00100100"},
    {"%","00100101"},
    {"&","00100110"},
    {"'","00100111"},
    {"(","00101000"},
    {")","00101001"},
    {"*","00101010"},
    {"+","00101011"},
    {",","00101100"},
    {"-","00101101"},
    {".","00101110"},
    {"/","00101111"},
    {"0","00110000"},
    {"1","00110001"},
    {"2","00110010"},
    {"3","00110011"},
    {"4","00110100"},
    {"5","00110101"},
    {"6","00110110"},
    {"7","00110111"},
    {"8","00111000"},
    {"9","00111001"},
    {":","00111010"},
    {";","00111011"},
    {"<","00111100"},
    {"=","00111101"},
    {">","00111110"},
    {"?","00111111"},
    {"@","01000000"},
    {"A","01000001"},
    {"B","01000010"},
    {"C","01000011"},
    {"D","01000100"},
    {"E","01000101"},
    {"F","01000110"},
    {"G","01000111"},
    {"H","01001000"},
    {"I","01001001"},
    {"J","01001010"},
    {"K","01001011"},
    {"L","01001100"},
    {"M","01001101"},
    {"N","01001110"},
    {"O","01001111"},
    {"P","01010000"},
    {"Q","01010001"},
    {"R","01010010"},
    {"S","01010011"},
    {"T","01010100"},
    {"U","01010101"},
    {"V","01010110"},
    {"W","01010111"},
    {"X","01011000"},
    {"Y","01011001"},
    {"Z","01011010"},
    {"[","01011011"},
    {"back_slash","01011100"},
    {"]","01011101"},
    {"^","01011110"},
    {"_","01011111"},
    {"`","01100000"},
    {"a","01100001"},
    {"b","01100010"},
    {"c","01100011"},
    {"d","01100100"},
    {"e","01100101"},
    {"f","01100110"},
    {"g","01100111"},
    {"h","01101000"},
    {"i","01101001"},
    {"j","01101010"},
    {"k","01101011"},
    {"l","01101100"},
    {"m","01101101"},
    {"n","01101110"},
    {"o","01101111"},
    {"p","01110000"},
    {"q","01110001"},
    {"r","01110010"},
    {"s","01110011"},
    {"t","01110100"},
    {"u","01110101"},
    {"v","01110110"},
    {"w","01110111"},
    {"x","01111000"},
    {"y","01111001"},
    {"z","01111010"},
    {"{","01111011"},
    {"|","01111100"},
    {"}","01111101"},
    {"~","01111110"}
   };
   string cadena_decodificada = "";
   string subcadena = "";
   for(int i = 0; i < int(binarios.length()); i+=8){
       subcadena = "";
       for(int j = i; j < i+8; j++){
           subcadena += binarios[j];
       }
       int potencia = 7;
       int decimal;
       int suma = 0;
       for(int k = 0; k < 8; k++){
           //cout << subcadena[k] - 48;
           decimal = (int(subcadena[k] - 48))*(pow(2,potencia));
           //cout << decimal << endl;
           potencia--;
           suma += decimal;
       }
       if(suma != 10){
           cadena_decodificada += chars[suma-32][0];
       }else{
           cadena_decodificada += "\n";
       }
   }
   return cadena_decodificada;
}
void separar_cadena(string dato, int index,string *cadena_semilla){
    int contador = 0;
    if(int(dato.length()) < index){
        *(cadena_semilla) = dato;
        cout << cadena_semilla[0] << endl;
        //cadena_semilla[0] = cadena_separada[0];
    }else if(int(dato.length())%index == 0){
        for(int i = 0; i < int(dato.length()); i+=index){
            string tmp_cadena = "";
            for(int j = i; j < (i+index); j++){
                tmp_cadena += dato[j];
            }
            *(cadena_semilla + contador) = tmp_cadena;
            contador++;
        }
    }else{
        for(int i = 0; i < int(dato.length()); i+=index){
            string tmp_cadena = "";
            if(i+index < int(dato.length())){
                for(int j = i; j < (i+index); j++){
                    tmp_cadena += dato[j];
                }
            }else{
                for(int j = i; j < int(dato.length()); j++){
                    tmp_cadena += dato[j];
                }
            }
            *(cadena_semilla + contador) = tmp_cadena;
            contador++;
         }
    }
}
void metodo_1_codificar(string *cadena_semilla, string *cadena_codificada, int tamanio){
    int contador_ceros = 0;
    int contador_unos = 0;
    int contador_bits = 0;
    string cadena_codificada_por_pos = "";

    //HALLANDO LOS CEROS Y LOS UNOS DE CADA CADENA DEL ARREGLO DE STRINGS
    int ceros_unos [tamanio][2];
    for(int i = 0; i < tamanio; i++){
        int tamanio_subcadena = int(cadena_semilla[i].length());
        contador_ceros = 0;
        contador_unos = 0;
        for(int j = 0; j < tamanio_subcadena; j++){
            if(cadena_semilla[i][j] == '0'){
               contador_ceros++;
            }else{
               contador_unos++;
            }
        }
        ceros_unos[i][0] = contador_ceros;
        ceros_unos[i][1] = contador_unos;
    }
    //FIN HALLANDO CEROS Y UNOS

    //INICIO DE LA CODIFICACION
    for(int i = 0; i < tamanio; i++){
        cadena_codificada_por_pos = "";
        int tamanio_subcadena = int(cadena_semilla[i].length());
        if(i == 0){
            for(int j = 0; j < tamanio_subcadena; j++){
                if(cadena_semilla[i][j] == '0'){
                   cadena_codificada_por_pos += "1";
                }else{
                   cadena_codificada_por_pos += "0";
                }
            }
        }else{
            if(ceros_unos[i-1][0] == ceros_unos[i-1][1]){
                //cout << "IGUAL CANTIDAD" << endl;
                for(int j = 0; j < tamanio_subcadena; j++){
                    if(cadena_semilla[i][j] == '0'){
                       cadena_codificada_por_pos += "1";
                    }else{
                       cadena_codificada_por_pos += "0";
                    }
                }
            }else if(ceros_unos[i-1][0] > ceros_unos[i-1][1]){
                //cout << "MAS CANTIDAD DE CEROS" << endl;
                contador_bits = 2;
                for(int j = 0; j < tamanio_subcadena; j++){
                    if((j+1)%contador_bits == 0 and (j+1) != 1){
                        if(cadena_semilla[i][j] == '0'){
                           cadena_codificada_por_pos += "1";
                        }else{
                           cadena_codificada_por_pos += "0";
                        }
                    }else{
                        cadena_codificada_por_pos += cadena_semilla[i][j];
                    }
                }
            }else if(ceros_unos[i-1][0] < ceros_unos[i-1][1]){
                //cout << "MENOS CANTIDAD DE CEROS" << endl;
                contador_bits = 3;
                for(int j = 0; j < tamanio_subcadena; j++){
                    if((j+1)%contador_bits == 0 and (j+1) != 1){
                        if(cadena_semilla[i][j] == '0'){
                           cadena_codificada_por_pos += "1";
                        }else{
                           cadena_codificada_por_pos += "0";
                        }
                    }else{
                        cadena_codificada_por_pos += cadena_semilla[i][j];
                    }
                }
            }
        }
        //cout << cadena_codificada_por_pos << endl;
        //cout << "********************" << endl;
        cadena_codificada[i] = cadena_codificada_por_pos;
    }
    //FIN DE LA CODIFICACION
}
void metodo_2_codificar(string *cadena_semilla, string *cadena_codificada, int tamanio){
    string cadena_codificada_por_pos = "";
    for(int i = 0; i < tamanio; i++){
        int tamanio_subcadena = int(cadena_semilla[i].length());
        cadena_codificada_por_pos = "";
        for(int j = 0; j < tamanio_subcadena ; j++){
            if(j == 0){
                cadena_codificada_por_pos += cadena_semilla[i][tamanio_subcadena-1];
            }else if(j == 1){
                cadena_codificada_por_pos += cadena_semilla[i][0];
            }else{
                cadena_codificada_por_pos += cadena_semilla[i][j-1];
            }

        }
        //cout << cadena_codificada_por_pos << endl;
        cadena_codificada[i] = cadena_codificada_por_pos;
    }
}
void metodo_1_decodificar(string *cadena_semilla, string *cadena_decodificada, int tamanio){
    int contador_ceros = 0;
    int contador_unos = 0;
    int contador_bits = 0;
    string cadena_codificada_por_pos = "";
    cout << "DECODIFICANDO" << endl;

    //HALLANDO LOS CEROS Y LOS UNOS DE CADA CADENA DEL ARREGLO DE STRINGS
    int ceros_unos [tamanio][2];
    for(int i = 0; i < tamanio; i++){
        cadena_codificada_por_pos = "";
        int tamanio_subcadena = int(cadena_semilla[i].length());
        if(i == 0){
            for(int j = 0; j < tamanio_subcadena; j++){
                if(cadena_semilla[i][j] == '0'){
                   cadena_codificada_por_pos += "1";
                }else{
                   cadena_codificada_por_pos += "0";
                }
            }
        }else{
            if(ceros_unos[i-1][0] == ceros_unos[i-1][1]){
                //cout << "IGUAL CANTIDAD" << endl;
                for(int j = 0; j < tamanio_subcadena; j++){
                    if(cadena_semilla[i][j] == '0'){
                       cadena_codificada_por_pos += "1";
                    }else{
                       cadena_codificada_por_pos += "0";
                    }
                }
            }else if(ceros_unos[i-1][0] > ceros_unos[i-1][1]){
                //cout << "MAS CANTIDAD DE CEROS" << endl;
                contador_bits = 2;
                for(int j = 0; j < tamanio_subcadena; j++){
                    if((j+1)%contador_bits == 0 and (j+1) != 1){
                        if(cadena_semilla[i][j] == '0'){
                           cadena_codificada_por_pos += "1";
                        }else{
                           cadena_codificada_por_pos += "0";
                        }
                    }else{
                        cadena_codificada_por_pos += cadena_semilla[i][j];
                    }
                }
            }else if(ceros_unos[i-1][0] < ceros_unos[i-1][1]){
                //cout << "MENOS CANTIDAD DE CEROS" << endl;
                contador_bits = 3;
                for(int j = 0; j < tamanio_subcadena; j++){
                    if((j+1)%contador_bits == 0 and (j+1) != 1){
                        if(cadena_semilla[i][j] == '0'){
                           cadena_codificada_por_pos += "1";
                        }else{
                           cadena_codificada_por_pos += "0";
                        }
                    }else{
                        cadena_codificada_por_pos += cadena_semilla[i][j];
                    }
                }
            }
        }
        //cout << cadena_codificada_por_pos << endl;
        //cout << "********************" << endl;
        cadena_decodificada[i] = cadena_codificada_por_pos;
        contador_ceros = 0;
        contador_unos = 0;
        for(int j = 0; j < tamanio_subcadena; j++){
            if(cadena_decodificada[i][j] == '0'){
               contador_ceros++;
            }else{
               contador_unos++;
            }
        }
        ceros_unos[i][0] = contador_ceros;
        ceros_unos[i][1] = contador_unos;
    }
    //FIN DE LA CODIFICACION
}
void metodo_2_decodificar(string *cadena_semilla, string *cadena_decodificada, int tamanio){
    string cadena_decodificada_por_pos = "";
    for(int i = 0; i < tamanio; i++){
        int tamanio_subcadena = int(cadena_semilla[i].length());
        cadena_decodificada_por_pos = "";
        for(int j = 1; j < tamanio_subcadena ; j++){
            cadena_decodificada_por_pos += cadena_semilla[i][j];
        }
        cadena_decodificada_por_pos += cadena_semilla[i][0];
        //cout << cadena_decodificada_por_pos << endl;
        cadena_decodificada[i] = cadena_decodificada_por_pos;
    }
}

void codificar_decodificar::codificar(int semilla, int metodo, string archivo_entrada, string archivo_salida){
    ofstream Guardar;
    ifstream Leer;
    string file_name = "../lab_3_pt_1/db/" + archivo_entrada + ".txt";
    string *cadena_semilla = NULL, *cadena_codificada = NULL;
    string binario = "";
    int tamanio = 0;

    Leer.open(file_name);
    if(!Leer.is_open()){
        cout << "No se pudo abrir el archivo " << archivo_entrada << endl;
    }else{
        string texto_leido = "", texto_archivo_tmp = "", texto_archivo;
        while(getline(Leer,texto_leido)){
            texto_archivo_tmp += texto_leido + "\n";
        }
        Leer.close();
        for(int i = 0; i < int(texto_archivo_tmp.length())-1;i++){
            texto_archivo += texto_archivo_tmp[i];
        }
        binario = convertir_str_to_in(texto_archivo);
        if(semilla > int(binario.length())){
            tamanio = 1;
        }else if(int(binario.length())%semilla == 0){
            tamanio = int(binario.length()/semilla);
        }else{
            tamanio = int(binario.length()/semilla)+1;
        }
        cadena_semilla = new string[tamanio];
        cadena_codificada = new string[tamanio];
        separar_cadena(binario,semilla,cadena_semilla);
        if(metodo == 1){
            metodo_1_codificar(cadena_semilla,cadena_codificada,tamanio);
        }else{
            metodo_2_codificar(cadena_semilla,cadena_codificada,tamanio);
        }
        cout << "Codificado correctamente :)" << endl;
        string cadena_a_guardar = "";
        for(int i = 0; i < tamanio; i++){
            //cout << cadena_codificada[i] << endl;
            cadena_a_guardar += cadena_codificada[i];
        }
        Guardar.open("../lab_3_pt_1/db/"+archivo_salida+".bin",ios::app);
        Guardar << cadena_a_guardar;
        Guardar.close();
        cout << "Se guardo con exito! :)" << endl;
    }
    delete []cadena_semilla;
    delete []cadena_codificada;
}

void codificar_decodificar::decodificar(int semilla, int metodo, string archivo_entrada, string archivo_salida){
    ofstream Guardar;
    ifstream Leer;
    string file_name = "../lab_3_pt_1/db/" + archivo_entrada + ".bin";
    string *cadena_semilla = NULL, *cadena_decodificada = NULL;
    int tamanio = 0;

    Leer.open(file_name);
    if(!Leer.is_open()){
        cout << "No se pudo abrir el archivo " << archivo_entrada << endl;
    }else{
        string texto_leido = "", texto_archivo_tmp = "", texto_archivo;
        while(getline(Leer,texto_leido)){
            texto_archivo_tmp += texto_leido + "\n";
        }
        Leer.close();
        for(int i = 0; i < int(texto_archivo_tmp.length())-1;i++){
            texto_archivo += texto_archivo_tmp[i];
        }
        //cout << texto_archivo << endl;
        if(semilla > int(texto_archivo.length())){
            tamanio = 1;
        }else if(int(texto_archivo.length())%semilla == 0){
            tamanio = int(texto_archivo.length()/semilla);
        }else{
            tamanio = int(texto_archivo.length()/semilla)+1;
        }
        cadena_semilla = new string[tamanio];
        cadena_decodificada = new string[tamanio];
        separar_cadena(texto_archivo,semilla,cadena_semilla);
        if(metodo == 1){
            metodo_1_decodificar(cadena_semilla,cadena_decodificada,tamanio);
        }else{
            metodo_2_decodificar(cadena_semilla,cadena_decodificada,tamanio);
        }
        string binario = "";
        for(int i = 0; i < tamanio; i++){
            binario += cadena_decodificada[i];
        }
        string cadena_a_guardar = convertir_bin_to_str(binario);
        cout << "Decodificado correctamente :)" << endl;
        Guardar.open("../lab_3_pt_1/db/"+archivo_salida+".txt",ios::app);
        Guardar << cadena_a_guardar;
        Guardar.close();
        cout << "Se guardo con exito! :)" << endl;
    }
    delete []cadena_semilla;
    delete []cadena_decodificada;
}
