#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

bool revisionDominios();
int factorial(int);
void estadoInicial();
int combinaciones(int, int);
bool unicoIndice(int,int[]);

string X[]={"F", "T", "U", "W", "R", "O"};
string Y[] = {"C1", "C2", "C3"};
struct VariableAux{
    string nombre;
    int valor;
}variableAux[3];

//{"F", "T", "U", "W", "R", "O"};
//{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
struct Variable{
    string nombre;
    int valor;
}variable[6];

struct DominiosEstados{
    int valor;
    bool estado;
}dominio[10];

int main(){
    estadoInicial();
    //int random = rand() % 9;
    //variable[0].valor = dominio[random].valor;
    //dominio[random].estado = false;
    for (int i = 0; i < 6;i++){
        variable[i].valor = dominio[i].valor;
        dominio[i].estado = false;
    }
    if(variable[0].valor == 0){
        for (int i = 0; i < 10;i++){
            if(dominio[i].estado){
                variable[0].valor = dominio[i].valor;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 6;i++){
        cout << variable[i].nombre<<": ";
        cout << variable[i].valor << endl;
    }

        return 0;
}

//-------------------------------------Inicializacion de Estados-----------------------------------------------------------------
void estadoInicial(){
    srand(time(0));
    for (int i = 0; i < 6;i++){ // ingreso de nombres de variables
        variable[i].nombre = X[i];
    }
    for (int i = 0; i < 3;i++){ // ingreso de nombres de variables auxiliares
        variableAux[i].nombre = Y[i];
    }
    int n, num[10];
    for(int i=0; i<10; i++){  // ingresa datos del 0 - 9 desordenadamente en el arreglo
        do{
            n = rand() % 10;
        }while(unicoIndice(n, num));
        num[i] = n;
        dominio[i].valor = num[i];
        dominio[i].estado = true;
    }
    for (int i = 0; i < 10;i++){
        cout << dominio[i].valor << "  ";
    }
}
bool unicoIndice(int n, int num[]){
    for (int i = 0; i < 10;i++){
        if(n== num[i]){
            return true;
        }
    }
    return false;
}
//---------------------------------------------Asignacion de valores---------------------------------------------------------


































int factorial(int numero){
    return (numero >= 1) ?  numero* factorial(numero - 1) :  1;
}

int combinaciones(int numero, int duo){
    return (factorial(numero)/(factorial(duo)*factorial(numero-duo)));
}
