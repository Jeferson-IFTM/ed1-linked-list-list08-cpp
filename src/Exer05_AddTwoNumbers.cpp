#include <iostream>
#include <string>

#include "LinkedList.h"

// Dígitos em ordem inversa; retorna uma nova lista com a soma.
Node<int>* addTwoNumbers(const Node<int>* l1, const Node<int>* l2) {
    Node<int> dummy(0);  // sentinela
    Node<int>* tail = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) { sum += l1->element; l1 = l1->next; }
        if (l2 != nullptr) { sum += l2->element; l2 = l2->next; }

        carry = sum / 10;
        tail->next = new Node<int>(sum % 10);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    std::string line1, line2;
    std::getline(std::cin, line1);
    std::getline(std::cin, line2);

    Node<int>* l1 = parseNodes<int>(line1);
    Node<int>* l2 = parseNodes<int>(line2);
    Node<int>* result = addTwoNumbers(l1, l2);

    std::cout << nodesToString(result) << '\n';

    freeNodes(l1);
    freeNodes(l2);
    freeNodes(result);
    return 0;
}
