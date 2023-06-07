#include "SimpleList.h"

template <class T>
SimpleList<T>::SimpleList() {
    numElements = 0;
    elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList() {
    delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const {
    if ((index < numElements) && (index >= 0)) {
        return elements[index];
    } else {
        throw InvalidIndexException();
    }
}

template <class T>
bool SimpleList<T>::empty() const {
    if(numElements == 0){
        return true;
    }else{
        return false;
    }
}

template <class T>
T SimpleList<T>::first() const {
    T firstItem = elements[0];
    if (empty() == true) {
        throw EmptyListException();
    }
    return firstItem;
}

template <class T>
T SimpleList<T>::last() const {
    T lastItem =  elements[numElements -1];
    if (empty() == true) {
        throw EmptyListException();
    }
    return lastItem;
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) {
    if (numElements >= CAPACITY) {
        throw FullListException();
    }else{
        elements[numElements] = item;
        numElements += 1;
    }
}

template <class T>
void SimpleList<T>::remove(int index) {
    if (empty() == true) {
        throw EmptyListException();
    }else{
    if ((index < numElements) && (index >= 0)) {
        for (int i = index; i < numElements - 1; i++) {
            elements[i] = elements[i + 1];
        }
        numElements -= 1;
    } else {
        throw InvalidIndexException();
        }
    }
 }
