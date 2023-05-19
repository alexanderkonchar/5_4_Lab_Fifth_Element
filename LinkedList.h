//
// Created by Alex on 2/7/23.
//

#ifndef INC_5_4_LAB_FIFTH_ELEMENT_LINKEDLIST_H
#define INC_5_4_LAB_FIFTH_ELEMENT_LINKEDLIST_H

#include <ostream>
#include <memory>

template<class Type>
class LinkedList;

template<class Type>
std::ostream &operator<<(std::ostream &out, const LinkedList<Type> &list);

template<class Type>
struct Node {
    Type data;
    std::shared_ptr<Node<Type>> next;
};

template<class Type>
class LinkedList {
public:
    LinkedList() : front(nullptr), back(nullptr),
                   count(0) {}// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    //~LinkedList();           //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    void insert(Type data);  //Adds to the back of the list
    Type peek(int ndx) const;//Looks at an element at the given ndx value
    void remove(int ndx);    //Removes an element at the given ndx position
    friend std::ostream &operator
    <<<>(
    std::ostream &out,
    const LinkedList<Type> &list
    ); // Returns an output stream for displaying the LinkedList
protected:
    std::shared_ptr<Node<Type>> front;
    std::shared_ptr<Node<Type>> back;
    int count;
};

template<class Type>
void LinkedList<Type>::insert(Type data) {
    auto toAdd = std::make_shared<Node<Type>>();
    toAdd->data = data;
    toAdd->next = nullptr;
    if (!front) {
        front = toAdd;
        back = toAdd;
    } else {
        back->next = toAdd;
        back = toAdd;
    }
    ++count;
}

template<class Type>
Type LinkedList<Type>::peek(int ndx) const {
    if (ndx >= count || ndx < 0) {
        throw std::runtime_error("Out of range");
    }

    int currentNodeNum = 0;
    auto currentNode = front;

    while (currentNodeNum < ndx) {
        ++currentNodeNum;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<class Type>
void LinkedList<Type>::remove(int ndx) {
    if (ndx >= count || ndx < 0) {
        throw std::runtime_error("Out of range");
    }

    if (ndx == 0) {
        auto toDelete = front;
        front = toDelete->next;
        return;
    }

    int currentNodeNum = 0;
    auto currentNode = front;

    while (currentNodeNum < ndx - 1) {
        ++currentNodeNum;
        currentNode = currentNode->next;
    }
    auto toDelete = currentNode->next;
    if (toDelete->next) {
        currentNode->next = toDelete->next;
    } else {
        currentNode->next = nullptr;
        back = currentNode;
    }
    count--;
}

template<class Type>
std::ostream &operator<<(std::ostream &out, const LinkedList<Type> &list) {
    auto curr = list.front;

    while (curr) {
        out << curr->data;
        if (curr->next) out << " ";
        curr = curr->next;
    }
    return out;
}

#endif //INC_5_4_LAB_FIFTH_ELEMENT_LINKEDLIST_H
