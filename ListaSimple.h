#pragma once
#include <iostream>
#include <functional>
using std::cout;
using std::function;

template<class T>
class ListaSimple {
	class Nodo {
	public:
		T elem;
		Nodo* sig;
		Nodo(T elem, Nodo* sig = nullptr) :elem(elem), sig(sig) {}
	};
	Nodo* inicio;
	Nodo* fin;
	int size;
	function<void(T)>mostrar;
public:
	ListaSimple(function<void(T)>mostrar) : mostrar(mostrar) {
		inicio = fin = nullptr;
		size = 0;
	}
	~ListaSimple();

	void pushFront(T elem) {
		Nodo* nuevo = new Nodo(elem);
		if (size == 0) {
			inicio = fin = nuevo;
			++size; return;
		}
		nuevo->sig = inicio;
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
		fin = nuevo;
		++size;
	}

	void imprimir() {
		Nodo* aux = inicio;
		while (aux != nullptr) {
			this->mostrar(aux->elem);
			aux = aux->sig;
		}
		cout << "NULL\n";
	}
};