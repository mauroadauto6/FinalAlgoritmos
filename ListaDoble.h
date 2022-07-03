#pragma once
#include <iostream>
#include <functional>
using std::cout;
using std::function;

template<class T>
class ListaDoble {
	class Nodo {
	public:
		Nodo* ant;
		T elem;
		Nodo* sig;
		Nodo(T elem, Nodo* sig = nullptr, Nodo* ant = nullptr) : elem(elem), sig(sig), ant(ant) {}
	};
	Nodo* inicio;
	Nodo* fin;
	int size;
	function<void(T)>mostrar;
public:
	ListaDoble(function<void(T)>mostrar) :mostrar(mostrar) {
		inicio = fin = nullptr;
		size = 0;
	}
	~ListaDoble();

	void pushFront(T elem) {
		Nodo* nuevo = new Nodo(elem);
		if (size == 0) {
			inicio = fin = nuevo;
			++size; return;
		}
		nuevo->sig = inicio;
		inicio->ant = nuevo;
		inicio = nuevo;
		++size;
	}

	void pushBack(T elem) {
		Nodo* nuevo = new Nodo(elem);
		if (size == 0) {
			inicio = fin = nuevo;
			++size; return;
		}
		fin->sig = nuevo;
		nuevo->ant = fin;
		fin = nuevo;
		++size;
	}

	void imprimir() {
		Nodo* aux = inicio;
		cout << "NULL";
		while (aux != nullptr) {
			this->mostrar(aux->elem);
			aux = aux->sig;
		}
		cout << "NULL\n";
	}
};