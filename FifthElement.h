//
// Created by Alex on 2/9/23.
//

#ifndef INC_5_4_LAB_FIFTH_ELEMENT_FIFTHELEMENT_H
#define INC_5_4_LAB_FIFTH_ELEMENT_FIFTHELEMENT_H


#include "LinkedList.h"

template<class Type>
class FifthElement : public LinkedList<Type> {
public:
    Type getFifthElement();

    void insertNewFifthElement(const Type &value);

    void deleteFifthElement();

    void swapFourthAndFifthElement();
};

template<class Type>
Type FifthElement<Type>::getFifthElement() {
    auto curr = LinkedList<Type>::front;
    for (int i = 1; i < 5; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

template<class Type>
void FifthElement<Type>::insertNewFifthElement(const Type &value) {
    auto toAdd = std::make_shared<Node<Type>>();
    toAdd->data = value;

    auto curr = LinkedList<Type>::front;
    for (int i = 1; i < 5 - 1; ++i) {
        curr = curr->next;
    }

    if (!curr->next) {
        toAdd->next = nullptr;
        LinkedList<Type>::back = toAdd;
    } else toAdd->next = curr->next;
    curr->next = toAdd;
}

template<class Type>
void FifthElement<Type>::deleteFifthElement() {
    auto curr = LinkedList<Type>::front;
    for (int i = 1; i < 5 - 1; ++i) {
        curr = curr->next;
    }

    if (!curr->next->next) {
        curr->next = nullptr;
        LinkedList<Type>::back = curr;
    } else curr->next = curr->next->next;
}

template<class Type>
void FifthElement<Type>::swapFourthAndFifthElement() {
    auto curr = LinkedList<Type>::front;
    for (int i = 1; i < 5 - 2; ++i) {
        curr = curr->next; // Will be third node
    }

    auto toSwap = curr->next; // Store fourth node
    auto next = curr->next->next->next; // Points to whatever the fifth node was pointing to

    curr->next = curr->next->next; // Make third node point to fifth node
    curr->next = toSwap; // Make Fifth node point to fourth node
    toSwap->next = next;
    std::cout << "Test: " << toSwap->next->data << "\n";

    if (!toSwap->data) LinkedList<Type>::back = toSwap; // If the fifth node was the last element before swap, make fourth the last element
}

#endif //INC_5_4_LAB_FIFTH_ELEMENT_FIFTHELEMENT_H
