#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <AbcMorce.h>
#include <math.h>
#define varianza_numerica 48
#define varianza_tolower 32
#define varianza_letrica 97

///Versiones
#define suf_version "1.0"
#define loop_version "1.0"
#define bipolar_version "1.0"
#define dobleL_version "1.0"






using namespace std;

char random(){
    int numero = rand() % 26 + 97;
    char result = numero;
    return result;
}

string tolowerCase(string palabra){
    for(string::iterator iter = palabra.begin(); iter != palabra.end(); iter ++){
        if(*iter >= 65 and *iter <= 90){
            *iter += varianza_tolower;
        }
    }
    return palabra;
}

string eliminar(string palabra){

    string resultado;
    for(int i = 1; i < palabra.length(); i++){
        resultado.insert(resultado.end(),palabra[i]);
    }
    return resultado;

}

string par(string palabra, string resultado){
    for(int i = 0; i < palabra.length(); i += 2){
        resultado.insert(resultado.end(),palabra[i+1]);
        resultado.insert(resultado.end(),palabra[i]);
        resultado.insert(resultado.end(),random());
    }
    return resultado;
}

string impar(string palabra, string resultado){
    for(int i = 0; i < palabra.length(); i += 2){
        if (i == palabra.length() - 1){
            resultado.insert(resultado.end(),' ');
            resultado.insert(resultado.end(),palabra[i]);
            resultado.insert(resultado.end(),random());
        }
        else{
            resultado.insert(resultado.end(),palabra[i+1]);
            resultado.insert(resultado.end(),palabra[i]);
            resultado.insert(resultado.end(),random());
        }
    }
    return resultado;
}

string ingresarTexto(){
    string palabra;
    string frase;
    cin>>palabra;
    while(palabra != "-end"){
        palabra = tolowerCase(palabra);
        for(string::iterator iter = palabra.begin(); iter != palabra.end(); iter++){
            frase.insert(frase.end(), *iter);
        }
        cin>>palabra;
        if(palabra != "-end"){
            frase.insert(frase.end(), ' ');
        }
    }
    return frase;
}

string ingresarTexto_slower(){
    string palabra;
    string frase;
    cin>>palabra;
    while(palabra != "-end"){
        for(string::iterator iter = palabra.begin(); iter != palabra.end(); iter++){
            frase.insert(frase.end(), *iter);
        }
        cin>>palabra;
        if(palabra != "-end"){
            frase.insert(frase.end(), ' ');
        }
    }
    return frase;
}

void copiar(){
}

int numeroRandom(int a, int b){
    int temp = b - a +1;
    return rand() % temp + a;
}

void decodificador_loop(){
    cout<<"->DECODIFICADOR LOOP v"<<loop_version<<endl;
    cout<<"->INGRESAR TEXTO"<<endl;
    string frase = ingresarTexto();
    string resultado;
    for(int i = 97; i < 123; i++){
        for(int j = 1; j < frase.length(); j+=3){
            if(frase[j] == i){
                resultado.insert(resultado.end(),frase[j-1]);
                break;
            }
        }
    }
    cout<<resultado<<endl<<endl;

}

void codificador_loop(){
    cout<<"->CODIFICADOR LOOP v"<<loop_version<<endl;
    cout<<"====================================="<<endl;
    cout<<"=     FAVOR DE NO INGRESAR LETRAS   ="<<endl;
    cout<<"=        MAYUSCULAS NI NUMEROS      ="<<endl;
    cout<<"====================================="<<endl;
    cout<<"->INGRESAR TEXTO"<<endl;
    string resultado;
    string frase = ingresarTexto();

    for(int i = 97;  i < 124; i++){
        char looping = i;
        for(int j = 0; j < frase.length(); j++){
            if(frase[j] == i){
                resultado.insert(resultado.end(), frase[j]);
                resultado.insert(resultado.end(), j + 97);
                resultado.insert(resultado.end(), numeroRandom(48, 57));
            }
            else if(i == 123 and frase[j] == 32){
                resultado.insert(resultado.end(), 32);
                resultado.insert(resultado.end(), j + 97);
                resultado.insert(resultado.end(), numeroRandom(48, 57));
            }
        }
    }
    cout<<resultado<<endl<<endl;
}

void codificador_suf(){
    cout<<"->CODIFICADOR SUFLEADO v"<<suf_version<<endl;
    cout<<"->INGRESAR TEXTO"<<endl;
    string palabra;
    string resultado;
    bool polarity = false;
    bool init = false;
    char temp;
    cin>>palabra;
    resultado.insert(resultado.end(),random());
    while(palabra != "-end"){
        if(polarity){
            resultado.insert(resultado.end(),palabra[0]);
            resultado.insert(resultado.end(),' ');
            resultado.insert(resultado.end(),random());
            palabra = eliminar(palabra);
            polarity = false;
        }
        if(palabra.length() % 2 == 0){
            resultado = par(palabra, resultado);
            polarity = true;
        }
        else{
           resultado = impar(palabra, resultado);
        }
        cin>>palabra;
    }
    cout<<resultado<<endl<<endl;
}


void sucess(){
    cout<<"->SUCESS"<<endl<<endl;
}

void decodificador_suf(){
    cout<<"->DECODIFICADOR SUFLEADO v"<<suf_version<<endl;
    cout<<"->INGRESE EL TEXTO"<<endl;
    string palabra;
    string result;
    char temp = '*';
    bool ending = false;
    bool pol = true;
    cin>>palabra;
    while(!ending){
        if( temp != '*'){
            result.insert(result.end(),temp);
            temp = '*';
        }
        if(palabra.length() != 1){
        if(!pol){
            result.insert(result.end(), palabra[0]);
            result.insert(result.end(),' ');
            for( int i = 2; i < palabra.length(); i += 3){
                if(i == palabra.length() - 1){
                    result.insert(result.end(),' ');
                    temp = palabra[i];
                    pol = true;
                }
                else{
                    result.insert(result.end(),palabra[i +1]);
                    result.insert(result.end(),palabra[i]);
                    pol = false;
                }
            }
        }
        else{
            for(int i = 1; i < palabra.length(); i += 3){
                if(i == palabra.length() - 1){
                    result.insert(result.end(),' ');
                    temp = palabra[i];
                    pol = true;
                }
                else{
                    result.insert(result.end(),palabra[i+1]);
                    result.insert(result.end(),palabra[i]);
                    pol = false;
                }
            }
        }
        }
        else{
           pol = false;
        }
        cin>>palabra;
        if(palabra == "-end"){
            ending = true;
        }
    }
    cout<<result<<endl<<endl;
}

void gg(){
    system("C:\\Eclipses\\eclipselunaEE\\eclipse.exe");
}

void yugi(){
    WinExec("D:\\Yu-Gi-Oh!MarikTheDarkness\\marik_pc.exe",SW_SHOW);
}

void search(){
    string sentence;
    string resultado;
    cin>>sentence;
    bool ending = false;
    while(!ending){
        for(string::iterator iter = sentence.begin(); iter != sentence.end(); iter++){
            resultado.insert(resultado.end(),*iter);
        }
        cin>>sentence;
        if(sentence != "-end"){
            resultado.insert(resultado.end(),'+');
        }
        else{
            ending = true;
        }
    }
    string temp = "start https://www.google.com.pe/#q=";
    char google[36 + resultado.length()];
    for(int i = 0; i< 3; i++){
        google[i] = ' ';
    }
    for(int i= 1; i < 35 + 1; i++){
        google[i - 1] = temp[i - 1];
        if(i % 4 == 0){
            google[i] = ' ';
            google[i +1] = ' ';
            google[i +2] = ' ';
        }
    }
    string temp2 = "start https://www.bing.com/search?q=";
    char bing[37 +  resultado.length()];
    for(int i = 0; i< 3; i++){
        bing[i] = ' ';
    }
    for(int i = 1; i < 36 + 1; i++){
        bing[i - 1] = temp2[i - 1];
        if(i % 4 == 0){
            bing[i] = ' ';
            bing[i +1] = ' ';
            bing[i +2] = ' ';
        }
    }
    int n = 3;
    for(int i = 0; i < resultado.length(); i++){
        google[i + 35] = resultado[i];
        bing[i + 36] = resultado[i];
        if(i == 0){
            google[36] = ' ';
            google[37] = ' ';
            google[38] = ' ';
        }
        else if(i % 4 == 0){
            google[i + 36] = ' ';
            google[i + 37] = ' ';
            google[i + 38] = ' ';
        }
        else if(i == n){
            bing[i + 37] = ' ';
            bing[i + 38] = ' ';
            bing[i + 39] = ' ';
            n = n + 4;
        }
    }
    system(google);
    system(bing);
}

///letras reservadas n, m, c, l, h, e, s;

char letraReservada_bipolar(){
    auto random = numeroRandom(1,14);
    switch(random){
        case 1: return 'n';
        case 2: return 'm';
        case 3: return 'c';
        case 4: return 'l';
        case 5: return 'h';
        case 6: return 'e';
        case 7: return 's';
        case 8: return 'N';
        case 9: return 'M';
        case 10: return 'C';
        case 11: return 'L';
        case 12: return 'H';
        case 13: return 'E';
        case 14: return 'S';
    }
}


void codificador_bipolar(){
    cout<<"->CODIFICADOR BIPOLAR v"<<bipolar_version<<endl;
    cout<<"->INGRESAR TEXTO"<<endl;
    string frase = ingresarTexto();
    Morce *morce;
    string result;
    string letra;
    for(string::iterator iter = frase.begin(); iter != frase.end(); iter ++){
        morce = generarArbol();
        letra = morce->getMorce(*iter);
        int contador = 0;
        bool polarity;
        if(*iter == ' '){
            char res = letraReservada_bipolar();
            result.insert(result.end(), res);
            result.insert(result.end(), res);
        }
        else {
        for(string::iterator iter2 = letra.begin(); iter2 != letra.end(); iter2 ++){
            if(contador == 0){
                if(*iter2 == '0'){
                    polarity = false;
                    contador++;
                }
                else{
                    polarity = true;
                    contador++;
                }
            }
            else if((!polarity and *iter2 == '0') or (polarity and *iter2 == '1')){
                contador++;
            }
            else if(!polarity and *iter2 == '1'){
                polarity = true;
                result.insert(result.end(),contador + varianza_numerica);
                auto random = numeroRandom(97,122);
                    ///letras reservadas n, m, c, l, h, e, s;
                while(random ==110 or random ==109 or random ==99 or random ==108 or random ==104 or random ==101 or random ==115){
                    random = numeroRandom(97,122);
                }
                result.insert(result.end(),random);
                contador = 1;
            }
            else if (polarity and *iter2 == '0'){
                polarity = false;
                auto random2 = numeroRandom(65, 90);
                result.insert(result.end(),contador + varianza_numerica);
                while(random2 == 78 or random2 == 77 or random2 == 67 or random2 == 76 or random2 == 72 or random2 == 69 or random2 == 83){
                    random2 = numeroRandom(65,90);
                }
                result.insert(result.end(),random2);
                contador = 1;
            }
        }
        result.insert(result.end(),contador + varianza_numerica);
        if(polarity){
            auto random2 = numeroRandom(65,90);
            while(random2 == 78 or random2 == 77 or random2 == 67 or random2 == 76 or random2 == 72 or random2 == 69 or random2 == 83){
                random2 = numeroRandom(65,90);
            }
            result.insert(result.end(),random2);
        }
        else{
            auto random1 = numeroRandom(97,122);
            while(random1 ==110 or random1 ==109 or random1 ==99 or random1 ==108 or random1 ==104 or random1 ==101 or random1 ==115){
                random1 = numeroRandom(97,122);
            }
            result.insert(result.end(),random1);
        }
        result.insert(result.end(),letraReservada_bipolar());
        }
    }
    cout<<result<<endl<<endl;
}

void decodificador_bipolar(){
    cout<<"->DECODIFICADOR BIPOLAR v"<<bipolar_version<<endl;
    cout<<"->INGRESAR TEXTO"<<endl;
    auto mor = generarArbol();
    string frase = ingresarTexto_slower();
    string morce;
    string resultado;
    int number = 0;
    for(string::iterator iter = frase.begin(); iter != frase.end(); iter++){
        if(*iter >= 48 and *iter <= 57){
            number = *iter - varianza_numerica;
        }
               ///random ==110 or random ==77 or random ==67 or random ==76 or random ==72 or random ==69 or random ==83){
        else if(*iter ==78 or *iter ==109 or *iter ==99 or *iter ==108 or *iter ==104 or *iter ==101 or *iter ==115
                or *iter ==110 or *iter ==77 or *iter ==67 or *iter ==76 or *iter == 72 or *iter ==69 or *iter ==83){
            if(number != 0){
                number = 0;
                resultado.insert(resultado.end(),mor->getWord(morce));
                morce.clear();
            }
            else{
                resultado.insert(resultado.end(),' ');
            }
        }
        else if(*iter >= 65 and *iter <= 90){
            if(number == 0){
                break;
                resultado = "Ingrese una frase valida para este decodificador";
            }
            for(int i = 0; i<number;i++){
                morce.insert(morce.end(),'1');
            }
        }
        else if(*iter >= 97 and *iter <= 122){
            if(number == 0){
                break;
                resultado = "Ingrese una frase valida para este decodificador";
            }
            for(int i = 0; i<number;i++){
                morce.insert(morce.end(),'0');
            }
        }

    }
    cout<<resultado<<endl<<endl;
}

void codificador_dobleL(){
    cout<<"->DECODIFICADOR dobleL v"<<dobleL_version<<endl;
    cout<<"->INGRESAR TEXTO"<<endl;
    vector<int> clave;
    clave.push_back(110);
    clave.push_back(105);
    clave.push_back(99);
    clave.push_back(111);
    clave.push_back(108);
    clave.push_back(108);
    string frase = ingresarTexto();
    string result;
    int numeroR;
    for(auto iter = frase.begin(); iter!= frase.end(); iter++ ){
        numeroR = numeroRandom(0,5);
        result.insert(result.end(), abs(clave[numeroR] - *iter) + varianza_letrica);
        result.insert(result.end(), numeroR + varianza_letrica);
    }
    cout<<result<<endl<<endl;
}

void keyloger(){

}

void test(){
    int temp;
    cin>>temp;
    cout<<abs(temp)<<endl;

}

string clave(){
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    string s;
    cin>>s;

    SetConsoleMode(hStdin, mode);

    return s;
}

void salir(){
    exit(0);
}
void cod(){
    string comando2;
    cin>>comando2;
    if(comando2 == "-suf"){
        codificador_suf();
    }
    else if(comando2 == "-loop"){
        codificador_loop();
    }
    else if(comando2 == "-bipolar"){
        codificador_bipolar();
    }
    else if(comando2 == "-dobleL"){
        codificador_dobleL();
    }
}
void dec(){
    string comando2;
    cin>>comando2;
    if(comando2 == "-suf"){
        decodificador_suf();
    }
    else if(comando2 == "-loop"){
        decodificador_loop();
    }
    else if(comando2 == "-bipolar"){
        decodificador_bipolar();
    }
}
void limpiar(){
    system("cls");
    cout<<"=================WONDEMEL================="<<endl;
}
void init(){
    string comando2;
    cin>>comando2;
    if(comando2 == "-social"){
        system("start https://www.facebook.com");
        system("start https://twitter.com");
        system("start https://web.whatsapp.com");
        sucess();
    }
    if(comando2 == "-candy"){
        system("start https://apps.facebook.com/candycrush/");
        sucess();
    }
    if(comando2 == "-alka"){
        system("start http://www.twitch.tv/mym_alkapone");
        system("start https://www.youtube.com/channel/UCLq35g_MyAFUqd1xdkxN5kg");
        sucess();
    }
}
void busqueda(){
    search();
    sucess();
}
void testeo(){
    test();
    sucess();
}
void noexiste(){
    cout<<"No se encuentra el comando"<<endl;
}

vector<string> listaComandos(){
    vector<string> listaComandos;
    listaComandos.push_back("no existe@@");
    listaComandos.push_back("exit");
    listaComandos.push_back("cod");
    listaComandos.push_back("dec");
    listaComandos.push_back("init");
    listaComandos.push_back("search");
    listaComandos.push_back("test");
    listaComandos.push_back("clear");
    return listaComandos;
}

vector<void (*)()> listaFunciones(){
    vector<void (*)()> funciones;
    void (*temp)() = noexiste;
    funciones.push_back(temp);
    temp = salir;
    funciones.push_back(temp);
    temp = cod;
    funciones.push_back(temp);
    temp = dec;
    funciones.push_back(temp);
    temp = init;
    funciones.push_back(temp);
    temp = busqueda;
    funciones.push_back(temp);
    temp = testeo;
    funciones.push_back(temp);
    temp = limpiar;
    funciones.push_back(temp);
    return funciones;
}

int findComando(vector<string> &comandos, string comando){
    for(int i = 1; i < comandos.size(); i++){
        if(comandos[i] == comando){
            return i;
        }
    }
    return 0;

}

int main()
{
    vector<string> comandos = listaComandos();
    vector<void (*)()> funciones = listaFunciones();
    srand (time(NULL));
    string comando1, comando2,usuario,pass;
    cout<<"=================WONDERMEL================="<<endl;
    cout<<"->WELCOME"<<endl;
    cout<<"->USER:";
    cin>>usuario;
    cout<<"->PASS: ";
    pass = clave();
    cout<<endl;
    if(usuario == "ChrisChV" and pass == "Cristo2014"){
        while(1){
            cout<<"CHRISCHV>>";
            cin>>comando1;
            int num = findComando(comandos,comando1);
            auto temp = funciones[num];
            temp();
        }
    }
    else{
        cout<<"->INCORRECTO";
        exit(0);
    }
}
