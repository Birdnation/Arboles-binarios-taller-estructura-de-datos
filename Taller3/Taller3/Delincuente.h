#pragma once
#include <iostream>
#include <string>

using namespace std;
class Delincuente
{
private:
	int rut;
	string nombre;
	string alias;
	string delito;
	string peligrosidad;
public:
	Delincuente();
	Delincuente(int rut, string nombre, string alias, string delito, string peligrosidad);
	string getNombre();
	int getRut();
	string getAlias();
	string getDelito();
	string getPeligrosidad();
	~Delincuente();
};

