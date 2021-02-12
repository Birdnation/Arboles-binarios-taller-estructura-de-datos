#pragma once
#include "NodoAVL.h"
#include <queue>
class AVL
{
private:
	NodoAVL * raiz;
	enum { izq, der };
public:
	AVL();
	void AgregarDelincuente(NodoAVL*& raiz, Delincuente* delincuente, NodoAVL* dad, int rama);
	void EliminarDelincuente(int rut, NodoAVL *& raiz);
	void eliminarNodo(NodoAVL* eliminado);
	NodoAVL* minimo(NodoAVL* raiz);
	void reemplazar(NodoAVL* raiz, NodoAVL* nuevo);

	

	NodoAVL*& getRaiz();
	void Equilibrar(NodoAVL* raiz, int rama, bool nuevo);
	void RotacionDD(NodoAVL* nodo);
	void RotacionDI(NodoAVL* nodo);
	void RotacionSD(NodoAVL* nodo);
	void RotacionSI(NodoAVL* nodo);

	void InOrden(NodoAVL* raiz);
	void PreOrden(NodoAVL* raiz);
	void PostOrden(NodoAVL* raiz);
	void PorNivel(NodoAVL* raiz);

	NodoAVL* BusquedaxRut(int rut, NodoAVL* raiz);
	void ImpresionxRut(int rut, NodoAVL* raiz);
	void BusquedaxDelito(string delito, NodoAVL* raiz);
	~AVL();
};

