#pragma once
#include <iostream>
#include <functional>
using std::cout;
using std::function;

template<class A, class B>
class ArbolBusquedaBinaria {
	class Entidad {
	public:
		A key;
		B elem;
		Entidad(A key, B elem) :key(key), elem(elem) {}
	};
	class Nodo {
	public:
		Entidad elem;
		Nodo* izq;
		Nodo* der;
		Nodo(Entidad elem) :elem(elem), izq(nullptr), der(nullptr) {}
	};
	Nodo* raiz;
	int size;
	function<bool(A, A)>comparar;
	function<bool(A, A)>valor;
	function<void(B)>mostrar;
public:
	ArbolBusquedaBinaria(function<bool(A, A)>comparar, function<bool(A, A)>valor, function<void(B)>mostrar) :comparar(comparar), valor(valor), mostrar(mostrar) {
		raiz = nullptr;
		size = 0;
	}

	void insertar(A key, B elem) {
		Nodo* aux = raiz;
		if (raiz == nullptr) {
			raiz = new Nodo(Entidad(key, elem));
			++size;
			return;
		}
		while (1) {
			if (comparar(key, aux->elem.key)) {
				if (aux->izq == nullptr) {
					aux->izq = new Nodo(Entidad(key, elem));
					++size; return;
				}
				aux = aux->izq;
			} 
			else {
				if (aux->der == nullptr) {
					aux->der = new Nodo(Entidad(key, elem));
					++size; return;
				}
				aux = aux->der;
			}
		}
	}

	B busquedaKey(A key) {
		Nodo* aux = raiz;
		if (aux->elem.key == key) {
			return aux->elem.elem;
		}
		
		while (1) {
			if (aux == nullptr)return B();
			if (valor(key, aux->elem.key)) {
				return aux->elem.elem;
			}
			if (comparar(key, aux->elem.key)) {
				aux = aux ->izq;
			}
			else
				aux = aux->der;
		}
	}

	void imprimir() {
		this->_imprimir(this->raiz);
	}

private:
	void _imprimir(Nodo* n) {
		if (n == nullptr)return;
		mostrar(n->elem.elem);
		_imprimir(n->izq);
		_imprimir(n->der);
	}

};