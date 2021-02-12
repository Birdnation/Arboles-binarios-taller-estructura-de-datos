#include "stdafx.h"
#include "AVL.h"


AVL::AVL(){
	this->raiz = nullptr;
}

void AVL::AgregarDelincuente(NodoAVL*& raiz, Delincuente* delincuente, NodoAVL* dad, int rama){
	if (raiz == nullptr) { // se encuentra en la posicion Hoja
		NodoAVL* nodo = new NodoAVL(delincuente, dad); // crea el nodo
		raiz = nodo;
		Equilibrar(raiz->getDad(), rama, true); // equilibra el arbol desde el nodo creado hacia arriba (la rama indica si debe sumar o restar FE)
		return;
	}
	else {
		if (raiz->getDelincuente()->getRut() == delincuente->getRut()) { // si el delincuente ya esta en el arbol no hace nada
			cout << "Ya existe el delincuente." << endl;
			return;
		}
		else if (delincuente->getRut() < raiz->getDelincuente()->getRut()) { // mientras no llegue a una posicion hoja buscara de acuerdo al rut
			AgregarDelincuente(raiz->getLeft(), delincuente, raiz, this->izq);
		}
		else if (delincuente->getRut() > raiz->getDelincuente()->getRut()) {
			AgregarDelincuente(raiz->getRight(), delincuente, raiz, this->der);
			
		}
	}
}


void AVL::EliminarDelincuente(int rut, NodoAVL*& raiz){
	if (raiz == nullptr) { //arbol vacio
		return;
	}
	else if (rut < raiz->getDelincuente()->getRut()) { // si el valor es menor
		EliminarDelincuente(rut, raiz->getLeft()); // por la izq
	}
	else if (rut > raiz->getDelincuente()->getRut()) { // si es mayor
		EliminarDelincuente(rut, raiz->getRight()); // por la der
	}
	else if (rut == raiz->getDelincuente()->getRut()) {
		eliminarNodo(raiz);
		cout << "Eliminado!" << endl;
		return;
	}
}

void AVL::eliminarNodo(NodoAVL * eliminado){
	if (eliminado->getLeft() && eliminado->getRight()) {//tiene 2 crios
		NodoAVL* menor = minimo(eliminado->getRight()); // el menor de los mayores
		eliminado->setDelincuente(menor->getDelincuente()); // copia del menor con el actual
		eliminarNodo(menor); // recursivo para evitar clonacion de datos
	}
	else if (eliminado->getLeft()) { // tiene 1 crio izq
		reemplazar(eliminado, eliminado->getLeft());
		eliminado->setLeft(nullptr);
		eliminado->setRight(nullptr);
		delete eliminado; // borrado!
	}
	else if (eliminado->getRight()) { // tiene 1 crio der
		reemplazar(eliminado, eliminado->getRight());
		eliminado->setLeft(nullptr);
		eliminado->setRight(nullptr);
		delete eliminado; // borrado
	}
	else { // nodo hoja
		reemplazar(eliminado, nullptr);
		delete eliminado; // borrado!
	}
}

NodoAVL * AVL::minimo(NodoAVL * raiz){
	if (raiz == nullptr) { // si esta vacio
		return nullptr;
	}
	else if (raiz->getLeft()) { // si tiene crio izq
		return minimo(raiz->getLeft()); // siga buscando!!
	}
	else {
		return raiz; // si no tiene crios izq
	}
}

void AVL::reemplazar(NodoAVL * raiz, NodoAVL * nuevo){
	if (raiz->getDad()) { // tiene papa
		if (raiz == raiz->getDad()->getLeft()) { // si el hijo del papa es el izq
			raiz->getDad()->setLeft(nuevo); // bypass para el nuevo nodo
			if (raiz->getDad()->getFe() == 1){
				raiz->getDad()->setFe(0);
				Equilibrar(raiz->getDad()->getDad(), this->izq, false);
			}else{
				Equilibrar(raiz->getDad(), this->izq, false);
			}
		}
		else if (raiz == raiz->getDad()->getRight()) { // si es hijo der
			raiz->getDad()->setRight(nuevo); // bypass para el nuevo nodo
			if (raiz->getDad()->getFe() == -1){
				raiz->getDad()->setFe(0);
				Equilibrar(raiz->getDad()->getDad(), this->der, false);
			}else{
				Equilibrar(raiz->getDad(), this->der, false);
			}
		}
	}if (nuevo) { // si existe el nuevo
		nuevo->setDad(raiz->getDad()); // asignacion de papas fritas!
	}
}

NodoAVL *& AVL::getRaiz() // retorna la posicion raiz del arbolito
{
	return this->raiz;
}

//Algoritmo recursivo para equilibrar el arbol AVL
void AVL::Equilibrar(NodoAVL* raiz, int rama, bool nuevo){
	if (raiz){
		if (nuevo){// añadiendo
			if (rama == this->izq){
				raiz->setFe(raiz->getFe() - 1);
			}else{
				raiz->setFe(raiz->getFe() + 1);
			}
		}else{ // eliminando
			if (rama == this->izq){
				raiz->setFe(raiz->getFe() + 1);
			}else{
				raiz->setFe(raiz->getFe() - 1);
			}
		}
		if (raiz->getFe() == 0){ // altura no a variado
			return;
		}else if (raiz->getFe() == -2){ //Rotaciones Derechas
			if (raiz->getLeft()->getFe() == 1){
				RotacionDD(raiz); //rotacion Izq Derecha (Doble Derecha)
			}else{
				RotacionSD(raiz); // rotacion Derecha derecha (Simple Derecha)
			}
			return; // salir
		}else if (raiz->getFe() == 2){ // rotaciones izquierdas
			if (raiz->getRight()->getFe() == -1){
				RotacionDI(raiz); // rotacion Derecha Izq (Doble Izq)
			}else{
				RotacionSI(raiz); // rotacion Izq Izq (Simple Izq)
			}
			return; // salir
		}
		if (raiz->getDad()){ // mientras tenga papa
			if (raiz == raiz->getDad()->getRight()){
				Equilibrar(raiz->getDad(), this->der, nuevo); // recursividad con el papa (indicando su orientacion en el arbol)
			}else{
				Equilibrar(raiz->getDad(), this->izq, nuevo); // recursividad con el papa (indicando su orientacion en el arbol)
			}
		}
	}
}

//rotacion Derecha Izquierda (Doble Izq)
void AVL::RotacionDD(NodoAVL * nodo){
	//Punteros Aux
	NodoAVL* padre = nodo->getDad();
	NodoAVL* P = nodo;
	NodoAVL* Q = P->getLeft();
	NodoAVL* R = Q->getRight();
	NodoAVL* B = R->getLeft();
	NodoAVL* C = R->getRight();
	// fin aux

	if (padre) { // Si el nodo involucrado tiene padre
		if (padre->getRight() == nodo) { // y es derecho
			padre->setRight(R);
		}
		else {
			padre->setLeft(R);
		}
	}
	else { // si no tiene padre entonces es raiz
		this->raiz = R;
	}
	//reconstruccion arbol
	P->setRight(B);
	Q->setLeft(C);
	R->setLeft(Q);
	R->setRight(P);

	//reasignar papas
	R->setDad(padre);
	P->setDad(R);
	Q->setDad(R);
	if (B) { B->setDad(Q); }
	if (C) { C->setDad(P); }

	//Ajustes FE
	switch (R->getFe()) {
	case -1:Q->setFe(0); P->setFe(1); break;
	case 0:Q->setFe(0); P->setFe(0); break;
	case 1:Q->setFe(-1); P->setFe(0); break;
	}
	R->setFe(0);
}


void AVL::RotacionDI(NodoAVL * nodo){
	NodoAVL* padre = nodo->getDad();
	NodoAVL* P = nodo;
	NodoAVL* Q = P->getRight();
	NodoAVL* R = Q->getLeft();
	NodoAVL* B = R->getLeft();
	NodoAVL* C = R->getRight();
	if (padre) {
		if (padre->getRight() == nodo) {
			padre->setRight(R);
		}
		else {
			padre->setLeft(R);
		}
	}
	else {
		this->raiz = R;
	}
	//reconstruccion arbol
	P->setRight(B);
	Q->setLeft(C);
	R->setLeft(P);
	R->setRight(Q);

	//reasignar papas
	R->setDad(padre);
	P->setDad(R);
	Q->setDad(R);
	if (B) { B->setDad(P); }
	if (C) { C->setDad(Q); }

	//Ajustes FE
	switch (R->getFe()) {
	case -1:P->setFe(0); Q->setFe(1); break;
	case 0:P->setFe(0); Q->setFe(0); break;
	case 1:P->setFe(-1); Q->setFe(0); break;
	}
	R->setFe(0);
}

void AVL::RotacionSD(NodoAVL * nodo){
	NodoAVL* padre = nodo->getDad();
	NodoAVL* P = nodo;
	NodoAVL* Q = P->getLeft();
	NodoAVL* B = Q->getRight();
	if (padre) {
		if (padre->getRight() == nodo) {
			padre->setRight(Q);
		}
		else {
			padre->setLeft(Q);
		}
	}
	else {
		this->raiz = Q;
	}
	//reconstruccion arbol
	P->setLeft(B);
	Q->setRight(P);

	//reasignar papas
	P->setDad(Q);
	if (B) { B->setDad(P); }
	Q->setDad(padre);

	//Ajustes FE
	P->setFe(0);
	Q->setFe(0);
}

void AVL::RotacionSI(NodoAVL * nodo){
	cout << nodo->getFe() << nodo->getDelincuente()->getAlias() << endl;
	system("pause");
	NodoAVL* padre = nodo->getDad();
	NodoAVL* P = nodo;
	NodoAVL* Q = P->getRight();
	NodoAVL* B = Q->getLeft();
	if (padre) {	
		if (padre->getRight() == nodo) {
			padre->setRight(Q);
		}
		else {
			padre->setLeft(Q);
		}
	}
	else {
		this->raiz = Q;
	}
	//reconstruccion arbol
	P->setRight(B);
	Q->setLeft(P);

	//reasignar papas
	P->setDad(Q);
	if (B) { B->setDad(P); }
	Q->setDad(padre);

	//Ajustes FE
	P->setFe(0);
	Q->setFe(0);
}

void AVL::InOrden(NodoAVL * raiz){
	if (!raiz){
		return;
	}
	InOrden(raiz->getLeft());
	cout << raiz->getDelincuente()->getRut() << "\t" << raiz->getDelincuente()->getNombre() << " - " << raiz->getDelincuente()->getAlias() << " - " << raiz->getDelincuente()->getPeligrosidad() << " - " << raiz->getDelincuente()->getDelito() << endl;
	InOrden(raiz->getRight());
}

void AVL::PreOrden(NodoAVL * raiz){
	if (!raiz) {
		return;
	}
	cout << raiz->getDelincuente()->getRut() << "\t" << raiz->getDelincuente()->getNombre() << " - " << raiz->getDelincuente()->getAlias() << " - " << raiz->getDelincuente()->getPeligrosidad() << " - " << raiz->getDelincuente()->getDelito() << endl;
	PreOrden(raiz->getLeft());
	PreOrden(raiz->getRight());
}

void AVL::PostOrden(NodoAVL * raiz){
	if (!raiz) {
		return;
	}
	PostOrden(raiz->getLeft());
	PostOrden(raiz->getRight());
	cout << raiz->getDelincuente()->getRut() << "\t" << raiz->getDelincuente()->getNombre() << " - " << raiz->getDelincuente()->getAlias() << " - " << raiz->getDelincuente()->getPeligrosidad() << " - " << raiz->getDelincuente()->getDelito() << endl;
}

void AVL::PorNivel(NodoAVL * raiz){
	NodoAVL* actual;
	queue <NodoAVL*> nueva;
	queue <NodoAVL*> aux;
	nueva.push(raiz);
	while (!nueva.empty()) {
		actual = nueva.front();
		aux.push(actual);
		nueva.pop();
		if (actual->getLeft()) {
			nueva.push(actual->getLeft());
		}
		if (actual->getRight()) {
			nueva.push(actual->getRight());
		}
	}
	while (!aux.empty()) {
		cout << raiz->getDelincuente()->getRut() << "\t" << raiz->getDelincuente()->getNombre() << " - " << raiz->getDelincuente()->getAlias() << " - " << raiz->getDelincuente()->getPeligrosidad() << " - " << raiz->getDelincuente()->getDelito() << endl;
		aux.pop();
	}
}

NodoAVL * AVL::BusquedaxRut(int rut, NodoAVL * raiz){
	if (!raiz) {
		return nullptr;
	}
	else if (rut < raiz->getDelincuente()->getRut()) {
		return BusquedaxRut(rut, raiz->getLeft());
	}
	else if (rut > raiz->getDelincuente()->getRut()) {
		return BusquedaxRut(rut, raiz->getRight());
	}
	else {
		return raiz;
	}
}

void AVL::ImpresionxRut(int rut, NodoAVL * raiz){
	NodoAVL* buscado = BusquedaxRut(rut, raiz);
	if (!buscado) {
		cout << "No se encuentra el rut" << endl;
		return;
	}
	cout << "> Nombre: " + buscado->getDelincuente()->getNombre() + " Alias: " + buscado->getDelincuente()->getAlias() + " Peligrosidad: " + buscado->getDelincuente()->getPeligrosidad() + " delito: " + buscado->getDelincuente()->getDelito() << endl;
}

void AVL::BusquedaxDelito(string delito, NodoAVL * raiz){
	if (!raiz) {
		return;
	}
	if (raiz->getDelincuente()->getDelito() == delito) {
		cout << "> Nombre: " + raiz->getDelincuente()->getNombre() + " Alias: " + raiz->getDelincuente()->getAlias() + " Peligrosidad: " + raiz->getDelincuente()->getPeligrosidad() + " delito: " + raiz->getDelincuente()->getDelito() << endl;
	}
	BusquedaxDelito(delito, raiz->getLeft());
	BusquedaxDelito(delito, raiz->getRight());
}


AVL::~AVL()
{
}
