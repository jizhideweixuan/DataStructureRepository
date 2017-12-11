//
// Created by jizhideweixuan on 17-12-11.
//

#ifndef CHAINLIST_CHAINNODE_H
#define CHAINLIST_CHAINNODE_H

template<class T>
struct chainNode {
    T element;
    chainNode<T> *next;

    //method
    chainNode() {}

    chainNode(const T &element) { this->element = element; }

    chainNode(const T &element, chainNode<T> *next) {
        this->element = element;
        this->next = next;
    }
};

#endif //CHAINLIST_CHAINNODE_H
