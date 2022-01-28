#ifndef SORTABLE_LINKED_LIST_H
#define SORTABLE_LINKED_LIST_H

#include <cstddef>                     //zawiera definicje NULL dla wskaznikow
#include<string>


template <typename T>
struct nodeWithKey
{
    nodeWithKey<T>* nextNode;
    T data;
    int key;
};

/*!
Ponizsza klasa zostala zaprojektowana na potrzeby projektu.
Przypomina ona kolejke priorytetowa, z ta roznica, ze sortowanie
nie wykonuje sie automatycznie, a musi zostac wywolane jedna
z funkcji quicksort() lub mergesort()
*/

template <typename T>
class sortableLinkedList{
private:
    nodeWithKey<T>* head;
    nodeWithKey<T>* quicksort(nodeWithKey<T>* headQS, int lengthOfTheList);      //aby zmniejszyc liczbe wywolan metody length() zdecydowano sie przekazywac dlugosc listy jako argument
    void mergesort(nodeWithKey<T>** headMS, int lengthOfTheList);                //analogicznie jak w quicksort
public:
    sortableLinkedList();
    ~sortableLinkedList();
    bool isEmpty() const;
    void first(T* data, int* key) const;
    void addOnFront(const T& elem,int key);
    void removeFront();
    void removeFront(T* data, int* key);                                        //wersja motedy removeFront zapisujaca w miejsce wskazywane przez wskaznik data dane w pierwszym elemencie
                                                                                //a w miejsce wskazywane przez wskaznik key klucz pierwszego elementu
    int length() const;
    void quicksort();                                                           //publicznie moze zostac wywolana tylko ta wersja metody quicksort
    void mergesort();                                                           //analogicznie jak w quicksort
};

template <typename T>                                                               //funkcja dzielaca liste na dwie rowne lub niemal rowne czesci
void splitIntoTwo(nodeWithKey<T>* headOfSource,nodeWithKey<T>** firstHalfHead,nodeWithKey<T>** secondHalfHead, int lengthOfSource);

template<typename T>                                                               //funkcja laczaca dwie posortowane listy w jedna posortowana liste
nodeWithKey<T>* mergeSorted(nodeWithKey<T>* first,nodeWithKey<T>* second);


#endif // SORTABLE_LINKED_LIST_H
