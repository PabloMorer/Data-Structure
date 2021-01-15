
#include <iostream>
#include <string>

#include"diccionario.h"
#include "lista.h"

using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	  // A IMPLEMENTAR  

	Diccionario<string, int> diccio;
	Lista<string>::ConstIterator itB = bien.cbegin();
	Lista<string>::ConstIterator itM = mal.cbegin();

	Lista<string>::ConstIterator itBFinal = bien.cend();
	Lista<string>::ConstIterator itMFinal = mal.cend();

	//recorremos Buenos
	int valor;

	while (itB != bien.cend()) {
		if (diccio.contiene(itB.elem())) {
			
			valor = diccio.valorPara(itB.elem()); //guardamos el valor de la clave
			diccio.inserta(itB.elem(), valor + 1); //modificamos en 1 el valor

		}
		else {
			diccio.inserta(itB.elem(), 1); // creamos una nueva tabla en el diccionario
		}

		itB.next();
	}

	//recorremos Malos

	while (itM != mal.cend()) {
		if (diccio.contiene(itM.elem())) {

			valor = diccio.valorPara(itM.elem()); //guardamos el valor de la clave
			diccio.inserta(itM.elem(), valor - 1); //modificamos en 1 el valor

		}
		else {
			diccio.inserta(itM.elem(), -1); // creamos una nueva tabla en el diccionario
		}

		itM.next();
	}

	//recorremos el diccionario guardando los resultados en la lista Puntuaciones

	Diccionario<string, int>::ConstIterator itDir = diccio.cbegin();

	
	while (itDir != diccio.cend()) {
		Puntuacion p = Puntuacion(itDir.clave(), itDir.valor());
		if (p.nota != 0) {
			listado.pon_ppio(p); //insertamos por el principio para que el orden sea inverso alfabeticamente
			
		}
		
		itDir.next();
	}


}


void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}