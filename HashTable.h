#pragma once
#include <iostream>
#include <list>
#include <functional>
#include <string>
using std::cout;
using std::function;
using std::string;
using std::list;

template<class T>
class Entidad {
    T elem;
    string key;
public:
    Entidad(T elem, string key) : elem(elem), key(key) {}
    T getElem() {
        return this->elem;
    }
    string getKey() {
        return this->key;
    }
};

template<class T>
class HashTable {
    list<Entidad<T>*>** ht;
    size_t capacidad;
    size_t size;
    function<void(T)> mostrar;
public:
    HashTable(size_t capacidad, function<void(T)> mostrar) : capacidad(capacidad), mostrar(mostrar) {
        ht = new list<Entidad<T>*>*[capacidad];
        for (size_t i = 0; i < capacidad; ++i) {
            ht[i] = nullptr;
        }
        size = 0;
    }
    ~HashTable();

    void imprimir() {
        for (size_t i = 0; i < capacidad; ++i) {
            cout << i << " - ";
            if (ht[i] != nullptr) {
                for (Entidad<T>* elem : *(ht[i])) {
                    mostrar(elem->getElem()); cout << " -> ";
                }
                cout << "nullptr";
            }
            cout << "\n";
        }
    }
private:
    /*size_t funcionHash(string key) {
        int k = 0;
        for (char c : key) {
            k += c * c;
        }

        return k % capacidad;
    }*/

    size_t funcionHash(string key) {
        int k = 0;
        for (int i = 0; i < key.length(); ++i) {
            int ascii = key[i];
            k += pow(ascii, i + 1);
        }
        return k % capacidad;
    }

public:
    void insertar(string key, T elem) {
        size_t i = funcionHash(key);
        if (ht[i] == nullptr) {
            ht[i] = new list<Entidad<T>*>;
            ht[i]->push_back(new Entidad<T>(elem, key));
            ++size; return;
        }
        ht[i]->push_back(new Entidad<T>(elem, key));
        ++size;
    }
};