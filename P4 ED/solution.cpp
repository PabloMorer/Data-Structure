
#include "cola.h"
#include <iostream>
using namespace std;


// A IMPLEMENTAR
void supervivientes(int n, Cola<int>& cola) {
	int i = 1;

	while (i <= n) {
		cola.pon(i);
		i++;
	}


	int eliminar = 1;
	int aux = 1;
	int cont = 1;

	int m = cola.longitud();
	while (eliminar < cola.longitud()) {
		while (cont <= m) {
			if (aux == eliminar) {
				cola.quita();
				aux = 0;
			}
			else {
				cola.pon(cola.primero());
				cola.quita();
				aux++;
			}

			cont++;
		}
		
		eliminar++;
		m = cola.longitud();
		cont = 1;
		aux = eliminar;
	}




}

int main() {
	
	int n;
	Cola<int> cola;

	cin >> n;
	while (n != 0){

		supervivientes(n, cola);

		cout << n << ":";
		while (!cola.esVacia()) {
			cout << " " << cola.primero();
			cola.quita();
		}
		cout << endl;
		
		cin >> n;	
	}
		
	return 0;
}
