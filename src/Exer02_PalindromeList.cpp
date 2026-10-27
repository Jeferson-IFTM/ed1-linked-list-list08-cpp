#include <iostream>
#include <string>

#include "LinkedList.h"

template <typename T>
Node<T>* reverseList(Node<T>* head) {
    Node<T>* prev = nullptr;
    while (head != nullptr) {
        Node<T>* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

template <typename T>
bool isPalindrome(Node<T>* head) {
    if (head == nullptr || head->next == nullptr) return true;

    // 1) metade da lista
    Node<T>* slow = head;
    Node<T>* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2) inverte a segunda metade
    Node<T>* secondHalf = reverseList(slow);

    // 3) compara
    bool result = true;
    Node<T>* a = head;
    Node<T>* b = secondHalf;
    while (b != nullptr) {
        if (a->element != b->element) {
            result = false;
            break;
        }
        a = a->next;
        b = b->next;
    }

    // 4) restaura a lista original
    reverseList(secondHalf);
    return result;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    Node<int>* head = parseNodes<int>(line);
    std::cout << (isPalindrome(head) ? "true" : "false") << '\n';

    freeNodes(head);
    return 0;
}
