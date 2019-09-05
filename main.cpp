#include <cstdlib>
#include <iostream>
#include "Stack.h"

using namespace std;

int opcion;

//Algoritmo de conversión
string conversionPostfixes(string expression){
    //incicializar la pila
    Stack *pila= new Stack();

    //obtener caracter por caracter para validar
    //la expresión
    char character;

}

void menu(){
    cout<<"1. Conversion\n2. Evaluacion\n3. Salir"<<endl;
    cout<<"Ingrese el numero de la opcion:";
    cin >>opcion;
}

int main()
{
    cout <<"Programa de expresiones Postfijas"<<endl;

    do{

        menu();
        switch(opcion){
            case 1:
                break;
            case 2:
                break;

            case 3:
                break;
            default:
                menu();

        }
    } while(opcion!=3);


    return 0;
}
