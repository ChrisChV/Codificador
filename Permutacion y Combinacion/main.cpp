#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void imprimir(vector<double> s){
    for(vector<double>::iterator iter = s.begin() +1; iter != s.end(); iter++){
        cout<<*iter;
    }
    cout<<endl;
}

double factorial(double a){
    double result = 1;
    for(int i = a; i > 0; i --){
        result *= i;
    }
    return result;
}

double P(double a, double b){
    return factorial(a) / (factorial(a -b));
}

double C(double a, double b){
    /*
    double k = a -b;
    double temp = a;
    double r = 1;
    for(int i = k; i > 0; i--){
        r *= temp;
        temp--;
    }
    */
    return P(a,b) / factorial(b);
}

void permutacion(double n){
    vector<double> s(n +1);
    double count;
    for(int i = 1; i <= n; i++){
        s[i] = i;
    }
    imprimir(s);
    for(int i = 2; i <= factorial(n); i++){
        double m = n - 1;
        while(s[m] > s[m+1]){
            m = m-1;
        }
        double k = n;
        while(s[m] > s[k]){
            k = k-1;
        }
        double temp = s[m];
        s[m] = s[k];
        s[k] = temp;
        double p = m +1;
        double q = n;
        while(p < q){
            int temp = s[p];
            s[p] = s[q];
            s[q] = temp;
            p = p+1;
            q = q -1;
        }
        imprimir(s);
    }
}

void combinacion(double r, double n){
    vector<double> s(r +1);
    for(int i = 1; i <= r; i++){
        s[i] = i;
    }
    imprimir(s);

    for(int i = 2; i <= C(n,r); i++){
        double m = r ;
        double val_max = n;
        while(s[m] == val_max){
            m = m-1;
            val_max = val_max -1;
        }
        s[m] = s[m] +1;
        for(int j = m + 1; j <=r; j++){
            s[j] = s[j-1] +1;
        }
        imprimir(s);
    }

}

void distribucionbi(double n, double k, float p){
    float q = 1 - p;
    double result = C(n,k) * pow(p,k) * pow(q,n-k);
    cout<<result<<endl;
}

void distribucionben(float p, bool z){
    int x;
    if(z){
        x = 1;
    }
    else{
        x = 0;
    }
    cout<<pow(p,z) * pow(1-p,1-x)<<endl;
}

void siguienteComb(vector<double> s, double r, double n){
    double m = r ;
    double val_max = n;
    while(s[m] == val_max){
        m = m-1;
        val_max = val_max -1;
    }
    s[m] = s[m] +1;
    for(int j = m + 1; j <=r; j++){
        s[j] = s[j-1] +1;
    }
    imprimir(s);
}

int main()
{
    string comand;
    cin>>comand;
    vector<double> v(6);
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    v[4] = 6;
    v[5] = 7;
    bool t = true;
    while(comand != "exit"){
        if(comand == "comb"){
            double a,b;
            cin>>a>>b;
            combinacion(a,b);
            cout<<"=============================================="<<endl;
        }
        else if(comand == "per"){
            double a;
            cin>>a;
            permutacion(a);
            cout<<"=============================================="<<endl;
        }
        else if(comand == "sigComb"){
            siguienteComb(v,5,7);
        }
        else if(comand == "fac"){
            double a;
            cin>>a;
            cout<<factorial(a)<<endl;
            cout<<"=============================================="<<endl;
        }
        else if(comand == "com"){
            double a,b;
            cin>>a>>b;
            cout<<C(a,b)<<endl;
            cout<<"=============================================="<<endl;
        }
        else if(comand == "bin"){
            double a,b;
            float c;
            cin>>a>>b>>c;
            distribucionbi(a,b,c);
            cout<<"=============================================="<<endl;
        }
        else if(comand == "ben"){
            float a;
            int b;
            cin>>a>>b;
            distribucionben(a,b);
            cout<<"=============================================="<<endl;
        }
        cin>>comand;
    }
}
