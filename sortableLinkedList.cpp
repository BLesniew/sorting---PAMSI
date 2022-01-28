#include "sortableLinkedList.h"

template<typename T>
sortableLinkedList<T>::sortableLinkedList()
{
    head = NULL;
}

template<typename T>
sortableLinkedList<T>::~sortableLinkedList()
{
    while(!isEmpty())
        removeFront();
}

template<typename T>
bool sortableLinkedList<T>::isEmpty() const
{
    return head==NULL;
}

template<typename T>
void sortableLinkedList<T>::first(T* data, int* key) const
{
    *data = head->data;
    *key = head->key;
}

template<typename T>
void sortableLinkedList<T>::removeFront()
{
    head = head->nextNode;
}

template<typename T>
void sortableLinkedList<T>::removeFront(T* data, int* key)
{
    *data = head->data;
    *key = head->key;
    head = head->nextNode;
}

template<typename T>
void sortableLinkedList<T>::addOnFront(const T& elem,int keyD)
{
    nodeWithKey<T>* newNode = new nodeWithKey<T>;
    newNode->nextNode = head;
    newNode->data = elem;
    newNode->key = keyD;
    head = newNode;
}

template<typename T>
int sortableLinkedList<T>::length() const
{
    int len=0;
    nodeWithKey<T> *tmpPointer=head;
    while(tmpPointer!=NULL)
    {
        len++;
        tmpPointer=tmpPointer->nextNode;
    }

    return len;
}

template<typename T>
void sortableLinkedList<T>::quicksort()
{
    quicksort(this->head,this->length());

    return;
}

//w quicksorcie zaimplementowanym ponizej zdecydowano sie uzywac pierwszego elementu listy jako pivotu

template<typename T>
nodeWithKey<T>* sortableLinkedList<T>::quicksort(nodeWithKey<T>*pivot, int lengthOfTheList)
{
    if(lengthOfTheList<=1)
    {
        return pivot;
    }

    else
    {

        nodeWithKey<T>* index = pivot->nextNode;
        nodeWithKey<T>* placeToSwap=pivot;

        int pivotFinalPlace=1;
        for(int i=1;i<lengthOfTheList;i++)
        {

            if(index->key<pivot->key)
            {

                placeToSwap=placeToSwap->nextNode;
                if(index!=placeToSwap)
                {
                    //SWAP
                    nodeWithKey<T> tmpNode;
                    tmpNode.data = index->data;
                    tmpNode.key = index->key;
                    index->data = placeToSwap->data;
                    index->key = placeToSwap->key;
                    placeToSwap->data = tmpNode.data;
                    placeToSwap->key = tmpNode.key;
                }


                pivotFinalPlace++;

            }
            index=index->nextNode;
        }

        if(placeToSwap!=pivot)
        {
           //SWAP
            nodeWithKey<T> tmpNode;
            tmpNode.data = pivot->data;
            tmpNode.key = pivot->key;
            pivot->data = placeToSwap->data;
            pivot->key = placeToSwap->key;
            placeToSwap->data = tmpNode.data;
            placeToSwap->key = tmpNode.key;

        }
        if(pivotFinalPlace<lengthOfTheList-pivotFinalPlace)
        {
            quicksort(pivot,pivotFinalPlace-1);
            if(placeToSwap->nextNode!=NULL)
                quicksort(placeToSwap->nextNode,lengthOfTheList-pivotFinalPlace);
        }
        else
        {
            if(placeToSwap->nextNode!=NULL)
                quicksort(placeToSwap->nextNode,lengthOfTheList-pivotFinalPlace);
            quicksort(pivot,pivotFinalPlace-1);
        }

    }

}

template<typename T>
void sortableLinkedList<T>::mergesort()
{
    mergesort(&(this->head),this->length());
}

template<typename T>
void sortableLinkedList<T>::mergesort(nodeWithKey<T>** headMS, int lengthOfTheList)
{

    nodeWithKey<T>* headRef = *headMS;
    nodeWithKey<T>* firstHalf;
    nodeWithKey<T>* secondHalf;

    if(lengthOfTheList <2)
    {
        return;
    }

    splitIntoTwo(headRef,&firstHalf,&secondHalf,lengthOfTheList);

    mergesort(&firstHalf,lengthOfTheList/2);                                           //pierwsza polowa ma dlugosc rowna drugiej polowie lub dlugosc o 1 mniejsza
    mergesort(&secondHalf,lengthOfTheList-lengthOfTheList/2);                          //dlugosci sa wyliczane w ten sposob aby uniknac wywolywania metody length()

    *headMS = mergeSorted(firstHalf,secondHalf);;
}

template<typename T>
void splitIntoTwo(nodeWithKey<T>* headOfSource,nodeWithKey<T>** firstHalfHead,nodeWithKey<T>** secondHalfHead, int lengthOfSource)
{
    *firstHalfHead = headOfSource;
    for(int i=0;i<lengthOfSource/2-1;i++)
    {
        *firstHalfHead = (*firstHalfHead)->nextNode;
    }
    *secondHalfHead=(*firstHalfHead)->nextNode;
    (*firstHalfHead)->nextNode = NULL;
    *firstHalfHead = headOfSource;

}

template<typename T>
nodeWithKey<T>* mergeSorted(nodeWithKey<T>* first,nodeWithKey<T>* second)
{
    nodeWithKey<T>* mergedList = NULL;



    if(first == NULL)
    {
        return second;
    }
    else if(second == NULL)
    {
        return first;
    }

    if(first->key <= second->key)
    {
        mergedList = first;
        mergedList->nextNode = mergeSorted(first->nextNode,second);
    }
    else
    {
        mergedList = second;
        mergedList->nextNode = mergeSorted(first,second->nextNode);
    }
    return mergedList;
}

//UZYWANE W PROJEKCIE WERSJE UTWORZONEJ KLASY

template class sortableLinkedList<std::string>;
