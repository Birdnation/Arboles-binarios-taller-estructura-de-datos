#include "stdafx.h"
#include "NodoABB.h"


NodoABB::NodoABB(){}

NodoABB::NodoABB(Delincuente * delincuente, NodoABB* dad){
	this->delincuente = delincuente;
	this->left = nullptr;
	this->right = nullptr;
	this->dad = dad;
}

Delincuente NodoABB::getDelincuente(){
	return *this->delincuente;
}

NodoABB *& NodoABB::getLeft(){
	return this->left;
}

NodoABB *& NodoABB::getRight(){
	return this->right;
}

NodoABB *& NodoABB::getDad(){
	return this->dad;
}

void NodoABB::setDelincuente(Delincuente* delincuente){
	this->delincuente = delincuente;
}

void NodoABB::setLeft(NodoABB * left){
	this->left = left;
}

void NodoABB::setRight(NodoABB * right){
	this->right = right;
}

void NodoABB::setDad(NodoABB * dad){
	this->dad = dad;
}


NodoABB::~NodoABB()
{
}
