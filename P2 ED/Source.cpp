#include <iostream>
#include <string>

#include "pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
    // A IMPLEMENTAR
    Pila<char> p1 = Pila<char>();
  
    int i = 0;
    bool equilibrado = true;
    int contPila = 0;
    while (i < cadena.length() && equilibrado) {
        if (cadena[i] == '('
            || cadena[i] == '['
            || cadena[i] == '{'
            ) {
            p1.apila(cadena[i]);
            contPila++;
            }
        else if (cadena[i] == ']') {
            if (p1.esVacia() || p1.cima() !=  '[' ){
                equilibrado = false;
            }
            else {
                p1.desapila();
                contPila--;
            }
        }
        else if (cadena[i] == ')') {
            if (p1.esVacia() || p1.cima() != '(') {
                equilibrado = false;
            }
            else {
                p1.desapila();
                contPila--;
            }
        }
    
        else if (cadena[i] == '}') {
            if (p1.esVacia() || p1.cima() != '{') {
                equilibrado = false;
            }
            else {
                p1.desapila();
                contPila--;
            }
        }
            i++;
    }

    if (contPila != 0) {
        equilibrado = false;
     }
    return equilibrado;
}


int main() {
    string cadena;
    while (getline(cin, cadena)) {
        if (esEquilibrada(cadena))
            cout << "EQUILIBRADA" << endl;
        else
            cout << "NO_EQUILIBRADA" << endl;
    }
    return 0;
}
