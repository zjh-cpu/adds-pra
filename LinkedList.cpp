#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    head = nullptr;
    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (pos <= 0) {
        pos = 1;
    }
    if (head == nullptr || pos == 1) {
        newNode->link = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < pos - 1 && current != nullptr; i++) {
            current = current->link;
        }
        if (current != nullptr) {
            newNode->link = current->link;
            current->link = newNode;
        } else {
            // Position exceeds the size of the list, add to the end
            current = head;
            while (current->link != nullptr) {
                current = current->link;
            }
            current->link = newNode;
        }
    }
}

bool LinkedList::deletePosition(int pos) {
    if (pos <= 0 || head == nullptr) {
        return false;
    }
    if (pos == 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
    } else {
        Node* current = head;
        for (int i = 1; i < pos - 1 && current != nullptr; i++) {
            current = current->link;
        }
        if (current != nullptr && current->link != nullptr) {
            Node* temp = current->link;
            current->link = temp->link;
            delete temp;
            return true;
        }
    }
    return false;
}

int LinkedList::get(int pos) {
    if (pos <= 0) {
        return std::numeric_limits<int>::max();
    }
    Node* current = head;
    for (int i = 1; i < pos && current != nullptr; i++) {
        current = current->link;
    }
    if (current != nullptr) {
        return current->data;
    } else {
        return std::numeric_limits<int>::max();
    }
}

int LinkedList::search(int target) {
    int pos = 1;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return pos;
        }
        current = current->link;
        pos++;
    }
    return -1;
}

void LinkedList::printList() {
    std::cout << "[";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        current = current->link;
        if (current != nullptr) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}
