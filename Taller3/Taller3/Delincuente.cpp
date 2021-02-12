#include "stdafx.h"
#include "Delincuente.h"


Delincuente::Delincuente(){}

Delincuente::Delincuente(int rut, string nombre, string alias, string delito, string peligrosidad)
{
	this->rut = rut;
	this->nombre = nombre;
	this->alias = alias;
	this->delito = delito;
	this->peligrosidad = peligrosidad;
}

string Delincuente::getNombre(){
	return this->nombre;
}

int Delincuente::getRut(){
	return this->rut;
}

string Delincuente::getAlias(){
	return this->alias;
}

string Delincuente::getDelito(){
	return this->delito;
}

string Delincuente::getPeligrosidad(){
	return this->peligrosidad;
}


Delincuente::~Delincuente(){}
