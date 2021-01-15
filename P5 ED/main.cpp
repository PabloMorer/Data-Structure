#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS
#include "pila.h"
#include <stdio.h>
#include <ctype.h>

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	 // A IMPLEMENTAR
	//Lista<char>::Iterator itPr = mensaje.begin();
	Lista<char>::Iterator itFin = mensaje.begin();

	Pila<char> pila;
	while (itFin != mensaje.end()) {
		if (tolower(itFin.elem()) != 'a' && // si el caracter que se apunta es distinto a una vocal
			tolower(itFin.elem()) != 'e' &&
			tolower(itFin.elem()) != 'i' &&
			tolower(itFin.elem()) != 'o' &&
			tolower(itFin.elem()) != 'u') {

			pila.apila(itFin.elem());
			itFin = mensaje.eliminar(itFin);
			
		}
		else {
		
			while (!pila.esVacia()) {
				mensaje.insertar(pila.cima(), itFin);
				pila.desapila();
			}
			itFin.next();
		}
		
	
	}

		while (!pila.esVacia()) {
			mensaje.insertar(pila.cima(), itFin);
			pila.desapila();
		}
	


}

 
// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
