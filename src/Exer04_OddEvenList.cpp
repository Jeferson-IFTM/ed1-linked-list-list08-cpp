#include <iostream>
#include <string>

#include "LinkedList.h"

template <typename T>
Node<T>* oddEvenList(Node<T>* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node<T>* odd = head;
    Node<T>* even = head->next;
    Node<T>* evenHead = even;

    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    Node<int>* head = parseNodes<int>(line);
    head = oddEvenList(head);
    std::cout << nodesToString(head) << '\n';

    freeNodes(head);
    return 0;
}
