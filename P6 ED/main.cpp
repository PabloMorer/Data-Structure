#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int tiempoAyuda(const Arbin<char>& falda, int numVueltas) {
	if (falda.esVacio()) {
		return 0;
	}
	int bajadaI;
	int bajadaD;

	if (falda.raiz() == 'X') {
		bajadaI = tiempoAyuda(falda.hijoIz(), numVueltas + 1);
		bajadaD = tiempoAyuda(falda.hijoDer(), numVueltas + 1);
		return numVueltas * 2  + bajadaI + bajadaD;
	}
		
	bajadaI = tiempoAyuda(falda.hijoIz(), numVueltas + 1);
	bajadaD = tiempoAyuda(falda.hijoDer(), numVueltas + 1);
	return bajadaI + bajadaD;
}

int tiempoAyuda(const Arbin<char>& falda) {

	int numVueltas = 0;
	return tiempoAyuda(falda, numVueltas);
	

}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF)  {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}