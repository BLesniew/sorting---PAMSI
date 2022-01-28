#include "listaJednokierunkowa.h"

template<typename T>
linkedList<T>::linkedList()
{
    head = NULL;
}

template<typename T>
linkedList<T>::~linkedList()
{
    while(!isEmpty())
        removeFront();                           //usuwa elementy listy poki nie jest pusta
}

template<typename T>
bool linkedList<T>::isEmpty() const
{
    return head==NULL;
}

//funkcja wyswietlajaca dane w pierwszym elemencie nie usuwajac elementu
template<typename T>
const T& linkedList<T>::first() const
{
    return head->data;
}

//funkcja usuwajaca pierwszy element i zwracajaca zawarte w nim dane
template<typename T>
T linkedList<T>::removeFront()
{
    T tmp = head->data;
    head = head->nextNode;
    return tmp;
}

//funkcja dodajace element w jej argumencie na poczatek listy
template<typename T>
void linkedList<T>::addOnFront(const T& elem)
{
    nodeL<T>* newNode = new nodeL<T>;
    newNode->nextNode = head;
    newNode->data = elem;
    head = newNode;
}

template<typename T>
int linkedList<T>::length()
{
    int len=0;
    nodeL<T> *tmpPointer=head->nextNode;
    while(tmpPointer!=NULL)
    {
        len++;
        tmpPointer=tmpPointer->nextNode;
    }
    return len;
}

//UZYWANE W PROJEKCIE WERSJE LINKED LIST

template class linkedList<std::string>;
