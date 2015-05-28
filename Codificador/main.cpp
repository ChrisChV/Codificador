#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <vector>


using namespace std;

char random(){
    int numero = rand() % 26 + 97;
    char result = numero;
    return result;
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

void codificador_suf(){
    cout<<"->CODIFICADOR SUFLEADO"<<endl;
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
    cout<<"->DECODIFICADOR SUFLEADO"<<endl;
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

void test(){
    char test[10];
    for (int i = 0; i< 5; i++){
        test[i]= '1';
    }
    test[5] = '6';

    cout<<test<<endl;
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
}
void dec(){
    string comando2;
    cin>>comando2;
    if(comando2 == "-suf"){
        decodificador_suf();
    }
}
void limpiar(){
    system("cls");
}
void init(){
    string comando2;
    cin>>comando2;
    if(comando2 == "-social"){
        system("start https://www.facebook.com");
        system("start https://twitter.com");
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
}

vector<string> listaComandos(){
    vector<string> listaComandos;
    listaComandos.push_back("no existe@@");
    listaComandos.push_back("/exit");
    listaComandos.push_back("/cod");
    listaComandos.push_back("/dec");
    listaComandos.push_back("/init");
    listaComandos.push_back("/search");
    listaComandos.push_back("/test");
    listaComandos.push_back("/clear");
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
    for(int i = 1; i < comandos.size() +1; i++){
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
    cout<<"->WELCOME"<<endl;
    cout<<"->USER:";
    cin>>usuario;
    cout<<"->PASS: ";
    pass = clave();
    cout<<endl;
    if(usuario == "WonderMel" and pass == "Cristo2014"){
        while(1){
            cout<<"WONDERMEL>>";
            cin>>comando1;
            int num = findComando(comandos,comando1);
            void (*temp)() =funciones[num];
            temp();
        }
    }
    else{
        cout<<"->INCORRECTO";
        exit(0);
    }
}
