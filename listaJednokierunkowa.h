#ifndef LISTA_JEDNOKIERUNKOWA_H
#define LISTA_JEDNOKIERUNKOWA_H

#include <cstddef>                     //zawiera definicje NULL dla wskaznikow

//DELETE
#include<iostream>
#include<string>

template <typename T>
struct nodeL{
    nodeL<T>* nextNode;
    T data;
};

template <typename T>                //LISTA JEDNOKIERUNKOWA, implementacja nie jest pelna, nie zawiera np. usuwania elementu na konkretnej pozycji
class linkedList{

private:
    nodeL<T> *head;

public:
    linkedList();
    ~linkedList();
    bool isEmpty() const;
    const T& first() const;
    void addOnFront(const T& elem);
    T removeFront();
    int length();
};


#endif // LISTA_JEDNOKIERUNKOWA_H
