//
// Created by hugues on 08/09/2018.
//

#include "Chain.h"

template<typename T>
Chain<T>::Chain() {
    this->first = nullptr;
    this->last = nullptr;
}

template<typename T>
Chain<T>::~Chain() {
}

template<typename T>
ChainElement<T> *Chain<T>::getFirst() const {
    return first;
}

template<typename T>
ChainElement<T> *Chain<T>::getLast() const {
    return last;
}

template<typename T>
ChainElement<T> *Chain<T>::pushFront(T value) {
    ChainElement<T> *newEle = new ChainElement(value);
    if(first == nullptr){
        last = newEle;
    }else{
        newEle->setNext(first);
        first->setPrevious(newEle);
    }
    first = newEle;
}

template<typename T>
ChainElement<T> *Chain<T>::pushBack(T value) {

}

template<typename T>
T Chain<T>::removeFirst() {
    return remove(first);
}

template<typename T>
T Chain<T>::removeLast() {
    return remove(last);
}

template<typename T>
T Chain<T>::remove(ChainElement<T> *element) {

    if(element->getNext() != nullptr) element->getNext()->setPrevious(element->getPrevious());
    if(element->getPrevious() != nullptr) element->getPrevious()->setNext(element->getNext());
    if(element == last) last = element->getPrevious();
    if(element == first) first = element->getNext();
    T res = element->getValue();
    delete element;
    return NULL;
}

template<typename T>
uint16_t Chain<T>::length() const {
    int length = 0;
    ChainElement* element = this->first;
    for(;element != nullptr; element = element->getNext())length++;
    return length;
}
