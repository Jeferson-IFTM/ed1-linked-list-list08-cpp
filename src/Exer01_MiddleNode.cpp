#include <iostream>
#include <string>

#include "LinkedList.h"

// Fast/Slow: quando fast chega ao fim, slow está no meio (2º central se par).
template <typename T>
Node<T>* middleNode(Node<T>* head) {
    Node<T>* slow = head;
    Node<T>* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    Node<int>* head = parseNodes<int>(line);
    std::cout << nodesToString(middleNode(head)) << '\n';

    freeNodes(head);
    return 0;
}
