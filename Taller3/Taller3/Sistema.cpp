#include "stdafx.h"
#include "Sistema.h"


Sistema::Sistema(){}

void Sistema::Lectura(){
	ifstream archivo;
	string linea = "";
	archivo.open("datos.txt");
	while (getline(archivo, linea)) {
		stringstream ss(linea);
		while (!ss.eof()) {
			string nombre, alias, peligrosidad, delito, rutString;
			getline(ss, rutString, ',');
			getline(ss, nombre, ',');
			getline(ss, alias, ',');
			getline(ss, peligrosidad, ',');
			getline(ss, delito, ',');
			try{
				Delincuente* d = new Delincuente(stoi(rutString), nombre, alias, delito, peligrosidad);
				abb.agregarDelincuente(abb.getRaiz(), d, nullptr);
				avl.AgregarDelincuente(avl.getRaiz(), d, nullptr, 0);
			}
			catch (const std::exception&)
			{
				cout << "error" << endl;
			}
		}
	}
}


void Sistema::Menu(){
	system("cls");
	bool menu = true;
	string opcion;
	cout << "Sistema de monitoreo delincuentes" << endl;
	while (menu) {
		cout << "===== Menu Principal =====" << endl;
		cout << "1.- Desplegar Delincuentes." << endl;
		cout << "2.- Modificar Delincuentes." << endl;
		cout << "3.- Buscar Delincuentes." << endl;
		cout << "4.- Salir." << endl;
		cout << "- Ingrese su opcion (numero): ";
		getline(cin, opcion);
		try {
			stoi(opcion);
		}
		catch (const std::exception&) {
			cout << "Error no selecciono ninguna opcion" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int opcionElegida = stoi(opcion);
		switch (opcionElegida) {
		case 1:
			system("cls");
			subMenu1();
		case 2:
			subMenu2();
		case 3:
			subMenu3();
		case 4:
			EscribirFichero();
			exit(0);
		default:
			cout << "Ingrese una opcion valida." << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

void Sistema::subMenu1(){
	bool menu = true;
	string opcion;
	cout << "SubMenu Desplegar" << endl;
	while (menu) {
		cout << "1.- Desplegar Pre-Orden." << endl;
		cout << "2.- Desplegar In-Orden." << endl;
		cout << "3.- Desplegar Post-Orden." << endl;
		cout << "4.- Desplegar Por Nivel." << endl;
		cout << "5.- Volver al Menu Principal." << endl;
		cout << "- Ingrese su opcion (numero): ";
		getline(cin, opcion);
		try {
			stoi(opcion);
		}
		catch (const std::exception&) {
			cout << "Error no selecciono ninguna opcion" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int opcionElegida = stoi(opcion);
		switch (opcionElegida) {
		case 1:
			cout << "   > PRE ORDEN ABB." << endl;
			this->abb.PreOrden(this->abb.getRaiz());
			cout << "   > PRE ORDEN AVL." << endl;
			this->avl.PreOrden(this->avl.getRaiz());
			system("pause");
			system("cls");
			continue;
		case 2:
			cout << "   > IN ORDEN ABB." << endl;
			this->abb.inOrden(this->abb.getRaiz());
			cout << "   > IN ORDEN AVL." << endl;
			this->avl.InOrden(this->avl.getRaiz());
			system("pause");
			system("cls");
			continue;
		case 3:
			cout << "   > POST ORDEN ABB." << endl;
			this->abb.PostOrden(this->abb.getRaiz());
			cout << endl;
			cout << "   > POST ORDEN AVL." << endl;
			this->avl.PostOrden(this->avl.getRaiz());
			cout << endl;
			system("pause");
			system("cls");
			continue;
		case 4:
			cout << "   > POR NIVEL ABB." << endl;
			this->abb.porNivel(this->abb.getRaiz());
			cout << "   > POR NIVEL AVL." << endl;
			this->avl.PorNivel(this->avl.getRaiz());
			system("pause");
			system("cls");
			continue;
		case 5:
			Menu();
		default:
			cout << "Ingrese una opcion valida." << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

void Sistema::subMenu2(){
	bool menu = true;
	string opcion, rut_str, nombre, alias, peligrosidad, delito;

	cout << "SubMenu Modificar" << endl;
	while (menu) {
		cout << "1.- Agregar Delincuente." << endl;
		cout << "2.- Capturar Delincuente." << endl;
		cout << "3.- Volver al Menu Principal." << endl;
		cout << "- Ingrese su opcion (numero): ";
		getline(cin, opcion);
		try {
			stoi(opcion);
		}
		catch (const std::exception&) {
			cout << "Error no selecciono ninguna opcion" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int opcionElegida = stoi(opcion);
		switch (opcionElegida) {
		case 1:
			cout << "   > Agregar un delincuente." << endl;
			cout << "Ingrese rut del delincuente: ";
			getline(cin, rut_str);
			cout << "Ingrese nombre del delincuente: ";
			getline(cin, nombre);
			cout << "Ingrese alias del delincuente: ";
			getline(cin, alias);
			cout << "Ingrese peligrosidad: ";
			getline(cin, peligrosidad);
			cout << "Ingrese el delito: ";
			getline(cin, delito);
			try{
				Delincuente* nuevoD = new Delincuente(stoi(rut_str), nombre, alias, delito, peligrosidad);
				this->abb.agregarDelincuente(this->abb.getRaiz(), nuevoD, nullptr);
				this->avl.AgregarDelincuente(this->avl.getRaiz(), nuevoD, nullptr, 0);
				system("pause");
				system("cls");
				continue;
			}
			catch (const std::exception&)
			{
				cout << "Error datos erroneos." << endl;
				system("pause");
				system("cls");
				continue;
			}
		case 2:
			cout << "   > Eliminar un delincuente." << endl;
			cout << "Ingrese rut del delincuente: ";
			getline(cin, rut_str);
			try{
				this->abb.eliminarDelincuente(stoi(rut_str), this->abb.getRaiz());
				this->avl.EliminarDelincuente(stoi(rut_str), this->avl.getRaiz());
				system("pause");
				system("cls");
				continue;
			}
			catch (const std::exception&){
				cout << "Error datos erroneos." << endl;
				system("pause");
				system("cls");
				continue;
			}
			
		case 3:
			Menu();
		default:
			cout << "Ingrese una opcion valida." << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

void Sistema::subMenu3(){
	unsigned t0, t1;
	double time;
	bool menu = true;
	string opcion, rut_str, delito;

	cout << "SubMenu Buscar" << endl;
	while (menu) {
		cout << "1.- Buscar por Rut." << endl;
		cout << "2.- Buscar por categoria." << endl;
		cout << "3.- Volver al Menu Principal." << endl;
		cout << "- Ingrese su opcion (numero): ";
		getline(cin, opcion);
		try {
			stoi(opcion);
		}
		catch (const std::exception&) {
			cout << "Error no selecciono ninguna opcion" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int opcionElegida = stoi(opcion);
		switch (opcionElegida) {
		case 1:
			cout << "   > Buscar por rut." << endl;
			cout << "Ingrese rut del delincuente: ";
			getline(cin, rut_str);
			try {
				t0 = clock();
				this->abb.ImpresionxRut(stoi(rut_str), this->abb.getRaiz());
				t1 = clock();
				time = (double(t1 - t0));
				cout << "tiempo de busqueda ABB: " << time << " ms." << endl;
				t0 = clock();
				this->avl.ImpresionxRut(stoi(rut_str), this->avl.getRaiz());
				t1 = clock();
				time = (double(t1 - t0));
				cout << "tiempo de busqueda AVL: " << time << " ms." << endl;
				system("pause");
				system("cls");
				continue;
			}
			catch (const std::exception&)
			{
				cout << "Error datos erroneos." << endl;
				system("pause");
				system("cls");
				continue;
			}
		case 2:
			cout << "   > Buscar por categoria." << endl;
			cout << "Ingrese el delito a buscar: ";
			getline(cin, delito);
			try {
				t0 = clock();
				this->abb.BusquedaxDelito(delito,this->abb.getRaiz());
				t1 = clock();
				time = (double(t1 - t0));
				cout << "tiempo de busqueda ABB: " << time << " ms." << endl;
				t0 = clock();
				this->avl.BusquedaxDelito(delito, this->avl.getRaiz());
				t1 = clock();
				time = (double(t1 - t0));
				cout << "tiempo de busqueda AVL: " << time << " ms." << endl;
				system("pause");
				system("cls");
				continue;
			}
			catch (const std::exception&) {
				cout << "Error datos erroneos." << endl;
				system("pause");
				system("cls");
				continue;
			}

		case 3:
			Menu();
		default:
			cout << "Ingrese una opcion valida." << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

void Sistema::EscribirFichero(){
	ofstream file("datos.txt");
	string rut, nombre, alias, peligrosidad, delito;
	NodoABB* actual;
	queue <NodoABB*> nueva;
	queue <NodoABB*> aux;
	nueva.push(this->abb.getRaiz());
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
		rut = to_string(aux.front()->getDelincuente().getRut());
		nombre = aux.front()->getDelincuente().getNombre();
		alias = aux.front()->getDelincuente().getAlias();
		peligrosidad = aux.front()->getDelincuente().getPeligrosidad();
		delito = aux.front()->getDelincuente().getDelito();
		file << rut + "," + nombre + "," + alias + "," + peligrosidad + "," + delito << endl;
		aux.pop();
	}
	file.close();
}


Sistema::~Sistema(){}
