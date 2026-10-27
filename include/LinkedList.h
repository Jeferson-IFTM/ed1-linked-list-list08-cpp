#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <sstream>
#include <string>

#include "List.h"

template <typename T>
struct Node {
    T element;
    Node<T>* next;

    explicit Node(const T& element) : element(element), next(nullptr) {}
    Node(const T& element, Node<T>* next) : element(element), next(next) {}
};

// Utilitários para cadeias de nós (usados pelas questões)

// "1 2 3" -> 1 -> 2 -> 3
template <typename T>
Node<T>* parseNodes(const std::string& line) {
    std::istringstream in(line);
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    T value;
    while (in >> value) {
        Node<T>* node = new Node<T>(value);
        if (tail == nullptr) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

// 1 -> 2 -> 3 -> "1 2 3" (vazia -> "")
template <typename T>
std::string nodesToString(const Node<T>* first) {
    std::ostringstream out;
    for (const Node<T>* cur = first; cur != nullptr; cur = cur->next) {
        out << cur->element;
        if (cur->next != nullptr) out << ' ';
    }
    return out.str();
}

template <typename T>
void freeNodes(Node<T>* first) {
    while (first != nullptr) {
        Node<T>* next = first->next;
        delete first;
        first = next;
    }
}

template <typename T>
class LinkedList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    ~LinkedList() override { clear(); }

    void addFirst(const T& element) override {
        head = new Node<T>(element, head);
        if (tail == nullptr) tail = head;
        ++count;
    }

    void addLast(const T& element) override {
        Node<T>* node = new Node<T>(element);
        if (tail == nullptr) head = node;
        else tail->next = node;
        tail = node;
        ++count;
    }

    bool removeFirst() override {
        if (head == nullptr) return false;
        Node<T>* old = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete old;
        --count;
        return true;
    }

    bool removeLast() override {
        if (head == nullptr) return false;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* prev = head;
            while (prev->next != tail) prev = prev->next;
            delete tail;
            tail = prev;
            tail->next = nullptr;
        }
        --count;
        return true;
    }

    void clear() override { while (removeFirst()) {} }

    std::size_t size() const override { return count; }
    bool isEmpty() const override { return count == 0; }
    std::string toString() const override { return nodesToString<T>(head); }

    Node<T>* getHead() const { return head; }
    Node<T>* getTail() const { return tail; }
};

#endif // LINKEDLIST_H
