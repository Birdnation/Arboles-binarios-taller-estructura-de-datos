#pragma once
#include <iostream>
#include <ctime> 
#include "NodoABB.h"
#include <queue>
class ABB
{
private:
	NodoABB * raiz;
public:
	ABB();
	void agregarDelincuente(NodoABB*& raiz, Delincuente* delincuente, NodoABB* dad);
	void eliminarDelincuente(int rut, NodoABB * raiz);
	void eliminarNodo(NodoABB* eliminado);
	NodoABB* minimo(NodoABB* raiz);
	void reemplazar(NodoABB* raiz, NodoABB* nuevo);
	NodoABB*& getRaiz();

	void inOrden(NodoABB* raiz);
	void PreOrden(NodoABB* raiz);
	void PostOrden(NodoABB* raiz);
	void porNivel(NodoABB* raiz);
	NodoABB* BusquedaxRut(int rut, NodoABB* raiz);
	void ImpresionxRut(int rut, NodoABB* raiz);
	void BusquedaxDelito(string delito, NodoABB* raiz);
	~ABB();
};

