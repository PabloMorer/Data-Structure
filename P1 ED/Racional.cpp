#include "Racional.h"
#include <cmath>


//Metodos publicos

	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****
long* Racional:: numerador() const {
	return _numer;
}

long* Racional:: denominador() const {
	return _denom;
}

void Racional:: setNumerador(long numer) {
	*this->_numer = numer;
}

void Racional::setDenominador(long denom) {
	*this->_denom = denom;
}

Racional::Racional(long num, long dem) {
	if (dem == 0) {
		throw EDenominadorCero();
	}
	/*if (num == 0) {
		throw EDivisionPorCero();
	}*/
	_numer = new long;
	_denom = new long;
	*_numer = num;
	*_denom = dem;

	this->reduce();
}

Racional::~Racional() {
	delete _numer;
	delete _denom;
}

Racional& Racional:: divideYActualiza( Racional& R1) {
	R1.reduce();
	if (*R1.denominador() == 1 && *R1.numerador() == 0) {
		throw EDivisionPorCero();
	}
	long num1 = *this->numerador() * *(R1.denominador());
	long num2 = *this->denominador() * *(R1.numerador());

	this->setNumerador(num1);
	this->setDenominador(num2);
	this->reduce();

	return *this;
	
}


Racional& Racional:: operator*=(const Racional& R1) {
	long num1 = *this->numerador() * *(R1.numerador());
	long num2 = *this->denominador() * *(R1.denominador());
	Racional racional(num1, num2);
	racional.reduce();
	*this = racional;

	return *this;
}

Racional& Racional:: operator=(const Racional& R1) {
	this->setDenominador(*R1.denominador());
	this->setNumerador(*R1.numerador());
	return *this;
}

Racional& Racional:: suma(const Racional& R1) {
	long numerador = (*this->numerador() * (mcm(*this->denominador(), *R1.denominador()) / *this->denominador())
		+ *R1.numerador() * (mcm(*this->denominador(), *R1.denominador())) / *R1.denominador());
	long denominador = mcm(*this->denominador(), *R1.denominador());

	this->setNumerador(numerador);
	this->setDenominador(denominador);
	this->reduce();

	return *this;
}

Racional& Racional:: operator- (const Racional& R1) {
	long numerador = (*this->numerador() * (mcm(*this->denominador(), *R1.denominador()) / *this->denominador())
		- *R1.numerador() * (mcm(*this->denominador(), *R1.denominador())) / *R1.denominador());
	long denominador = mcm(*this->denominador(), *R1.denominador());

	this->setNumerador(numerador);
	this->setDenominador(denominador);
	this->reduce();

	return *this;

}

bool Racional:: operator == ( Racional& R1) {
	bool dev = false;
	R1.reduce();
	this->reduce();
	if ((*this->denominador() == *R1.denominador()) && *this->numerador() == *R1.numerador()) {
		dev = true;
	}
	return dev;
}


// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << *f._numer << "/" << *f._denom;
	return out;
}

// Metodos privados
void Racional::reduce() {
	// Se asegura que el denominador siempre sea positivo   
	if (*_denom < 0) {
		*_numer = -(*_numer);
		*_denom = -(*_denom);
	}
	// Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(*_numer, *_denom);
	*_numer /= fsimp;
	*_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	// El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1);
	v2 = abs(v2);
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1 % v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1 * v2 / mcd(v1, v2);
}

