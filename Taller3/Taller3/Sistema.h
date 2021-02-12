#pragma once
#include "ABB.h"
#include "AVL.h"
#include <fstream>
#include <sstream>
class Sistema
{
private:
	ABB abb;
	AVL avl;
public:
	Sistema();
	void Lectura();
	void Menu();
	void subMenu1();
	void subMenu2();
	void subMenu3();
	void EscribirFichero();
	~Sistema();
};

