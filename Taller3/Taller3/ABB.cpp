#include "stdafx.h"
#include "ABB.h"


ABB::ABB(){
	this->raiz = nullptr;
}

void ABB::agregarDelincuente(NodoABB *& raiz, Delincuente * delincuente, NodoABB* dad) {
	if (raiz == nullptr){
		NodoABB* nodo = new NodoABB(delincuente, dad);
		raiz = nodo;
	}else{
		if (raiz->getDelincuente().getRut() == delincuente->getRut()){
			cout << "Ya existe el delincuente." << endl;
			return;
		}
		else if (delincuente->getRut() < raiz->getDelincuente().getRut()){
			agregarDelincuente(raiz->getLeft(), delincuente, raiz);

		}else if (delincuente->getRut() > raiz->getDelincuente().getRut()){
			agregarDelincuente(raiz->getRight(), delincuente, raiz);
		}
	}
}

void ABB::eliminarDelincuente(int rut, NodoABB * raiz){
	if (raiz == nullptr){ //arbol vacio
		return;
	}else if (rut < raiz->getDelincuente().getRut()){ // si el valor es menor
		eliminarDelincuente(rut, raiz->getLeft()); // por la izq
	}else if (rut > raiz->getDelincuente().getRut()){ // si es mayor
		eliminarDelincuente(rut, raiz->getRight()); // por la der
	}else if (rut == raiz->getDelincuente().getRut()){
		eliminarNodo(raiz);
		cout << "Eliminado!" << endl;
		return;
	}
}

void ABB::eliminarNodo(NodoABB * eliminado){
	if (eliminado->getLeft() && eliminado->getRight()) {//tiene 2 crios
		NodoABB* menor = minimo(eliminado->getRight()); // el menor de los mayores
		eliminado->setDelincuente(&menor->getDelincuente()); // copia del menor con el actual
		eliminarNodo(menor); // recursivo para evitar clonacion de datos
	}else if (eliminado->getLeft()){ // tiene 1 crio izq
		reemplazar(eliminado, eliminado->getLeft());
		eliminado->setLeft(nullptr);
		eliminado->setRight(nullptr);
		delete eliminado; // borrado!
	}else if (eliminado->getRight()){ // tiene 1 crio der
		reemplazar(eliminado, eliminado->getRight());
		eliminado->setLeft(nullptr);
		eliminado->setRight(nullptr);
		delete eliminado; // borrado
	}else{ // nodo hoja
		reemplazar(eliminado, nullptr);
		delete eliminado; // borrado!
	}

}

NodoABB * ABB::minimo(NodoABB * raiz){
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

void ABB::reemplazar(NodoABB * raiz, NodoABB * nuevo){
	if (raiz->getDad()){ // tiene papa
		if (raiz == raiz->getDad()->getLeft()){ // si el hijo del papa es el izq
			raiz->getDad()->setLeft(nuevo); // bypass para el nuevo nodo
		}else if (raiz == raiz->getDad()->getRight()){ // si es hijo der
			raiz->getDad()->setRight(nuevo); // bypass para el nuevo nodo
		}
	}if (nuevo){ // si existe el nuevo
		nuevo->setDad(raiz->getDad()); // asignacion de papas fritas!
	}
}

NodoABB *& ABB::getRaiz()
{
	return this->raiz;
}

void ABB::inOrden(NodoABB * raiz){
	if (!raiz){
		return;
	}
	inOrden(raiz->getLeft());
	cout << raiz->getDelincuente().getRut()<< "\t" << raiz->getDelincuente().getNombre() << " - " << raiz->getDelincuente().getAlias() << " - " << raiz->getDelincuente().getPeligrosidad() << " - " << raiz->getDelincuente().getDelito() << endl;
	inOrden(raiz->getRight());
}

void ABB::PreOrden(NodoABB * raiz){
	if (!raiz) {
		return;
	}
	cout << raiz->getDelincuente().getRut() << "\t" << raiz->getDelincuente().getNombre() << " - " << raiz->getDelincuente().getAlias() << " - " << raiz->getDelincuente().getPeligrosidad() << " - " << raiz->getDelincuente().getDelito() << endl;
	PreOrden(raiz->getLeft());
	PreOrden(raiz->getRight());
}

void ABB::PostOrden(NodoABB * raiz){
	if (!raiz) {
		return;
	}
	PostOrden(raiz->getLeft());
	PostOrden(raiz->getRight());
	cout << raiz->getDelincuente().getRut() << "\t" << raiz->getDelincuente().getNombre() << " - " << raiz->getDelincuente().getAlias() << " - " << raiz->getDelincuente().getPeligrosidad() << " - " << raiz->getDelincuente().getDelito() << endl;
}

void ABB::porNivel(NodoABB * raiz){
	NodoABB* actual;
	queue <NodoABB*> nueva;
	queue <NodoABB*> aux;
	nueva.push(raiz);
	while (!nueva.empty()){
		actual = nueva.front();
		aux.push(actual);
		nueva.pop();
		if (actual->getLeft()){
			nueva.push(actual->getLeft());
		}
		if (actual->getRight()){
			nueva.push(actual->getRight());
		}
	}
	while (!aux.empty()){
		cout << raiz->getDelincuente().getRut() << "\t" << raiz->getDelincuente().getNombre() << " - " << raiz->getDelincuente().getAlias() << " - " << raiz->getDelincuente().getPeligrosidad() << " - " << raiz->getDelincuente().getDelito() << endl;
		aux.pop();
	}
}

NodoABB* ABB::BusquedaxRut(int rut, NodoABB * raiz) {
	if (!raiz) {
		return nullptr;
	}
	else if (rut < raiz->getDelincuente().getRut()) {
		return BusquedaxRut(rut, raiz->getLeft());
	}
	else if (rut > raiz->getDelincuente().getRut()) {
		return BusquedaxRut(rut, raiz->getRight());
	}
	else {
		return raiz;
	}
}

void ABB::ImpresionxRut(int rut, NodoABB * raiz) {
	NodoABB* buscado = BusquedaxRut(rut, raiz);
	if (!buscado) {
		cout << "No se encuentra el rut" << endl;
		return;
	}
	cout << "> Nombre: " + buscado->getDelincuente().getNombre() + " Alias: " + buscado->getDelincuente().getAlias() + " Peligrosidad: " + buscado->getDelincuente().getPeligrosidad() + " delito: " + buscado->getDelincuente().getDelito() << endl;
}


void ABB::BusquedaxDelito(string delito, NodoABB * raiz) {
	if (!raiz) {
		return;
	}
	if (raiz->getDelincuente().getDelito() == delito) {
		cout << "> Nombre: " + raiz->getDelincuente().getNombre() + " Alias: " + raiz->getDelincuente().getAlias() + " Peligrosidad: " + raiz->getDelincuente().getPeligrosidad() + " delito: " + raiz->getDelincuente().getDelito() << endl;
	}
	BusquedaxDelito(delito, raiz->getLeft());
	BusquedaxDelito(delito, raiz->getRight());
}


ABB::~ABB()
{
}
