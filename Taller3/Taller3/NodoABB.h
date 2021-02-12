#pragma once
#include "Delincuente.h"
class NodoABB
{
private:
	Delincuente* delincuente;
	NodoABB* left;
	NodoABB* right;
	NodoABB* dad;

public:
	NodoABB();
	NodoABB(Delincuente* delincuente, NodoABB* dad);
	Delincuente getDelincuente();
	NodoABB*& getLeft();
	NodoABB*& getRight();
	NodoABB*& getDad();
	void setDelincuente(Delincuente* delincuente);
	void setLeft(NodoABB* left);
	void setRight(NodoABB* right);
	void setDad(NodoABB* dad);


	~NodoABB();
};

