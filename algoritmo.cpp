#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
int combinaciones(int, int);
int factorial(int);
void estadoInicial();
bool RestriccionBinaria(int []);
void restriccionGlobal();

struct VariableAux{
    string nombre;  //{"C1", "C2", "C3"};
    int valor;      //C1=?  C2 =?  C3=F
}variableAux[3];


struct Variables{
    string nombre;  //{"F", "T", "U", "W", "R", "O"}
    int valor;     // valores del dominio
} variable[6];

struct Dominios{
    int valor;
    bool estado;
} dominio[10];

int main(){
    estadoInicial();
    restriccionGlobal();
     cout << "   T W O         " << variable[1].valor << " " << variable[3].valor << " " << variable[5].valor << endl;
     cout << "+  T W O      +  " << variable[1].valor << " " << variable[3].valor << " " << variable[5].valor << endl;
     cout << " _______       _______" << endl;
     cout << " F O U R       " << variable[0].valor << " " << variable[5].valor << " " << variable[2].valor << " " << variable[4].valor << endl;
     cout << endl;
    
    return 0;
}



//-------------------------------------Inicializacion de Estados---------------------------------------------
void estadoInicial(){
    string X[]={"F", "T", "U", "W", "R", "O"};
    string Y[] = {"C1", "C2", "C3"};
    for (int i = 0; i < 3;i++){ // ingreso de nombres y valores a las variables auxiliares
        variableAux[i].nombre = Y[i];
        variableAux[i].valor = (i == 2) ? 1 : 0;
    }
    for (int i = 0; i < 6;i++){  // ingreso de nombres y valores iniciales a las variables
        variable[i].nombre = X[i];
        variable[i].valor = (i == 0) ? 1 : 0;
    }
    for (int i = 0; i < 10;i++){ // ingreso de valores y estados en el dominio
        dominio[i].valor = i;
        dominio[i].estado = (i == 1) ? false : true;
    }
}

//-----------------------------Restricciones Unarias, Binarias, Globles-----------------------------------------
bool RestriccionBinaria(int estados[6]){
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 6; j++){
            if(estados[i] == estados[j]){
                return false;
            }
        }
    }
    return true;
}
void restriccionGlobal(){
    int estados[6];
     // las Cs tienen valores de 0 - 1 excepto C3=1 --> por la restriccion F = C3 --> F!=0
    // por la restriccion F = C3 = 1;
    for(int i =0;i<10;i++){
        variable[0].valor = variableAux[2].valor;  // valor de F y C3 --> F=C3
        dominio[1].estado = false;
        if(dominio[i].estado){
            variable[5].valor = dominio[i].valor;                        //valor de O --> 0,1,2,3,4,5,6,7,8,9
        }else{
            continue;
        }
        dominio[i].estado = false;
        variable[4].valor = (2 * variable[5].valor > 9)?2*variable[5].valor-10: 2*variable[5].valor;  //valor de  R --> 0,2,4,6,8,0,2,4,6,8
        variableAux[0].valor = (2 * variable[5].valor > 9) ? 1 : 0;  // valor de la C1
        variable[1].valor = 10 + variable[5].valor;
        variableAux[1].valor = ((variable[1].valor)%2==0) ? 0: 1; //valor de C2
        variable[1].valor = (variable[5].valor +10  - variableAux[1].valor) / 2; // valor de T -> T= (O+10-C2)/2

        for (int j = 0; j < 10;j++){
            if(dominio[j].estado){
                variable[3].valor = dominio[j].valor;  //valor de w
                dominio[j].estado = false;
                variable[2].valor = ((((2 * variable[3].valor)+variableAux[0].valor))%10); // valor de U=((2*W)+C1)- 10*C2
                break;
            }else{
                continue;
            }
        }
        for (int idx = 0; idx < 6;idx++){
            estados[idx] = variable[idx].valor;
        }
        int valor1 = (variable[1].valor);
        int valor2 =((variable[5].valor +10  - variableAux[1].valor)/2);
        dominio[i].estado = true;
        if(RestriccionBinaria(estados)){
            if(valor1 == valor2){
                break;
            }
        }       
    }

}
//struct Variables{
//    string nombre;
//    int valor;
//    bool estado;
//} variable[210][6];
//int contador=0;
//void combinacionSR(int*datos,int n,int r,int y=0,int i=0,int *indexs=NULL){ // esta funcion me da convinaciones de dominios sin repeticion
//    if(indexs == NULL){
//        indexs = new int[r];
//    }
//    if(i<r){
//        for(int x=y;x<n;x++){
//            indexs[i]=x;
//            combinacionSR(datos,n,r,x+1,i+1,indexs);
//        }
//    }else{
//        for(int w=0;w<r;w++){
//            variable[contador][w].valor = datos[indexs[w]];
//            variable[contador][w].estado = true;
//        }
//        contador++;
//    }
//}

//void estadoInicial(){
//    int dominio[] = {0,1,2,3,4,5,6,7,8,9}; 
//    combinacionSR(dominio, 10, 6);  // se obtienen 210 combinaciones sin repeticion de dominios 

//    for (int i = 0; i < 210;i++){ // se ingresan nombres a las 210 variables 
//        for (int j = 0; j < 6;j++){
//            variables[i][j].nombre = X[j];
//            variable[i][j].estado = true;
//        }
//    }
//    for (int i = 0; i < 3;i++){ // ingreso de nombres de variables auxiliares
//        variableAux[i].nombre = Y[i];
//    }

//    //cout <<endl<<"el contador es: "<<contador<<endl;
//    //for (int i = 0; i < 210;i++){
//    //    for (int j = 0; j < 6;j++){
//    //        cout << variable[i][j].valor << "  ";
//    //    }
//    //    cout << endl;
//    //}
//}

























int factorial(int numero){
    return (numero >= 1) ?  numero* factorial(numero - 1) :  1;
}

int combinaciones(int numero, int duo){
    return (factorial(numero)/(factorial(duo)*factorial(numero-duo)));
}
