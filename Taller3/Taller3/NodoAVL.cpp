#include "stdafx.h"
#include "NodoAVL.h"


NodoAVL::NodoAVL(){}

NodoAVL::NodoAVL(Delincuente * delincuente, NodoAVL * dad){
	this->delincuente = delincuente;
	this->left = nullptr;
	this->right = nullptr;
	this->dad = dad;
	this->fe = 0;
}

Delincuente * NodoAVL::getDelincuente()
{
	return this->delincuente;
}

NodoAVL *& NodoAVL::getLeft()
{
	return this->left;
}

NodoAVL *& NodoAVL::getRight()
{
	return this->right;
}

NodoAVL *& NodoAVL::getDad()
{
	return this->dad;
}

int NodoAVL::getFe()
{
	return this->fe;
}

void NodoAVL::setDelincuente(Delincuente * delincuente){
	this->delincuente = delincuente;
}

void NodoAVL::setLeft(NodoAVL * left){
	this->left = left;
}

void NodoAVL::setRight(NodoAVL * right){
	this->right = right;
}

void NodoAVL::setDad(NodoAVL * dad){
	this->dad = dad;
}

void NodoAVL::setFe(int fe){
	this->fe = fe;
}


NodoAVL::~NodoAVL()
{
}
