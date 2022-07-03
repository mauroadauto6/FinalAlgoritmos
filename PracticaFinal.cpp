#include "pch.h"
#include <iostream>

#include "ListaSimple.h"
#include "ListaDoble.h"
#include "HashTable.h"
#include "ArbolBusquedaBinaria.h"

using std::cin;

int main() {

	//LISTA SIMPLE
	ListaSimple<int>* ls = new ListaSimple<int>(
		[](int a)->void {cout << a << " -> "; }
	    );
	//////////////////////////////////////////////////
	cout << "\n";
	//LISTA DOBLE
	ListaDoble<int>* ld = new ListaDoble<int>(
		[](int a)->void {cout <<" <- " << a << " -> "; }
		);	
	/////////////////////////////////////////////////
	cout << "\n";
	//HASH TABLE
	HashTable<int>* ht = new HashTable<int>(10, [](int a)->void {cout << a; });
	/////////////////////////////////////////////////
	cout << "\n";
	//ARBOL DE BUSQUEDA BINARIA
	ArbolBusquedaBinaria<int, int>* abb = new ArbolBusquedaBinaria<int, int>(
		[](int a, int b)->bool {return a < b; },
		[](int a, int b)->bool {return a == b; },
		[](int c)->void {cout << c << " - "; }
	);
	/////////////////////////////////////////////////
	//MENU PRINCIPAL
	int op;
	do {
		cout << "1. Valores pre-definidos    2.Insertar valores\n";
		cout << "Seleccione una opción: "; cin >> op; cout << "\n";
		switch (op) {
		case 1:
			cout << "Lista Simple\n";
			ls->pushBack(12);
			ls->pushBack(13);
			ls->pushBack(14);
			ls->pushBack(15);
			ls->imprimir();
			cout << "Lista Doble\n";
			ld->pushBack(12);
			ld->pushBack(13);
			ld->pushBack(14);
			ld->pushBack(15);
			ld->imprimir();
			cout << "Hash Table\n";
			ht->insertar("Jairo", 12);
			ht->insertar("tioboda", 13);
			ht->insertar("davidwebon", 14);
			ht->insertar("cody", 15);
			ht->imprimir();
			cout << "Arbol de Busqueda Binaria\n";
			abb->insertar(1, 14);
			abb->insertar(4, 11);
			abb->insertar(3, 16);
			abb->insertar(2, 19);
			abb->imprimir();
			cout << "Valor indice: " << abb->busquedaKey(3) << "\n";
			system("pause");
			system("cls");
			break;
		case 2:
			int _op, elem, indice;
			string keyHT;
			do {
				cout << "INSERTAR EN ELEMENTO EN:\n";
				cout << "1. Lista Simple\t2. Lista Doble\n";
				cout << "3. Hash Table\t4. Arbol de busqueda\n";
				cout << "5. Mostrar Lista Simple\t6. Mostrar Lista Doble\n";
				cout << "7. Mostrar Hash Table\t8. Mostrar Arbol de busqueda\n";
				cout << "9. Buscar un elemento en el arbol\n";
				cout << "Seleccione una opcion: "; cin >> _op; cout << "\n";
				switch (_op) {
				case 1:
					cout << "Inserta un elemento: "; cin >> elem;
					ls->pushBack(elem);
					break;
				case 2:
					cout << "Inserta un elemento: "; cin >> elem;
					ld->pushBack(elem);
					break;
				case 3:
					cout << "Inserta un elemento: "; cin >> elem;
					cout << "Inserta un key: "; cin >> keyHT;
					ht->insertar(keyHT, elem);
					break;
				case 4:
					cout << "Inserta un elemento: "; cin >> elem;
					cout << "Inserta un indice: "; cin >> indice;
					abb->insertar(indice, elem);
					break;
				case 5:
					ls->imprimir();
					break;
				case 6:
					ld->imprimir();
					break;
				case 7:
					ht->imprimir();
					break;
				case 8:
					abb->imprimir();
					break;
				case 9:
					int i;
					cout << "Inserte un indice a buscar: "; cin >> i;
					cout << "Valor indice: " << abb->busquedaKey(i) << "\n";
				}
				system("pause");
				system("cls");
			} while (_op != 1 || _op != 2 || _op != 3 || _op != 4 || _op != 5 || _op != 6 || _op != 7 || _op != 8);
		}
	} while (op != 1 || op != 2);
	/////////////////////////////////////////////////
	system("pause");
	return 0;
}