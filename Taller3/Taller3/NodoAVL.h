#pragma once
#include "Delincuente.h"
class NodoAVL
{
private:
	int fe;
	Delincuente* delincuente;
	NodoAVL* left;
	NodoAVL* right;
	NodoAVL* dad;

public:
	NodoAVL();
	NodoAVL(Delincuente* delincuente, NodoAVL* dad);
	Delincuente* getDelincuente();
	NodoAVL*& getLeft();
	NodoAVL*& getRight();
	NodoAVL*& getDad();
	int getFe();
	void setDelincuente(Delincuente* delincuente);
	void setLeft(NodoAVL* left);
	void setRight(NodoAVL* right);
	void setDad(NodoAVL* dad);
	void setFe(int fe);

	~NodoAVL();
};

