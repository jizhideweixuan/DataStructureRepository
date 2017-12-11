//
// Created by jizhideweixuan on 17-12-11.
//

#ifndef CHAINLIST_CHAIN_H
#define CHAINLIST_CHAIN_H

#include <sstream>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"

template<class T>
class chain : public linearList<T> {
    //构造，复制，析构
public:
    chain(int initialCapacity = 10);

    chain(const chain<T> &);

    ~chain();

    bool empty() const { listSize == 0 ? true : false; }

    int size() const { return listSize; };

    T &get(int theIndex) const;

    int indexOf(const T &theElement) const;

    void erase(int theIndex);

    void insert(int theIndex, const T &theElement);

    void output(ostream &out) const;

protected:
    //校验
    void checkIndex(int theIndex) const;
    //首节点
    chainNode<T> *firstNode;
    //长度
    int listSize;
};

template<class T>
chain<T>::chain(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capcity =" << initialCapacity << " Must be > 0 ";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T> &theList) {
    if (listSize == 0) {
        firstNode = NULL;
        return;
    }
    chainNode<T> *sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode<T> *targetNode = firstNode;
    while (sourceNode != NULL) {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template<class T>
chain<T>::~chain() {
    while (firstNode != NULL) {
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
void chain<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>
T &chain<T>::get(int theIndex) const {
    checkIndex(theIndex);

    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T &theElement) const {
    chainNode<T> *currentNode = firstNode;
    int index = 0;
    while (currentNode->next != NULL && currentNode->element != theElement) {
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template<class T>
void chain<T>::insert(int theIndex, const T &theElement) {

    if (theIndex < 0 || theIndex > listSize) {// invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    chainNode<T> *currentNode = firstNode;
    //在头插入
    if (theIndex == 0)
        firstNode = new chainNode<T>(theElement, firstNode);
        //循环到第theIndex-1个节点
    else {
        for (int i = 0; i < theIndex - 1; i++) {
            currentNode = currentNode->next;
        }
        currentNode->next = new chainNode<T>(theElement, currentNode->next);
    }
    listSize++;
}

template<class T>
void chain<T>::erase(int theIndex) {
    checkIndex(theIndex);
    chainNode<T> *deleteNode;
    if (theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}

template<class T>
void chain<T>::output(ostream &out) const {
    for (chainNode<T> *currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
        out << currentNode->element << "  ";
}

template<class T>
ostream &operator<<(ostream &out, const chain<T> &x) {
    x.output(out);
    return out;
}

#endif //CHAINLIST_CHAIN_H
