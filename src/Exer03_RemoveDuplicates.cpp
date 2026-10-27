#include <iostream>
#include <string>

#include "LinkedList.h"

template <typename T>
Node<T>* removeDuplicates(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->element == current->next->element) {
            Node<T>* duplicate = current->next;
            current->next = duplicate->next;  // religa antes de liberar
            delete duplicate;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    Node<int>* head = parseNodes<int>(line);
    head = removeDuplicates(head);
    std::cout << nodesToString(head) << '\n';

    freeNodes(head);
    return 0;
}
