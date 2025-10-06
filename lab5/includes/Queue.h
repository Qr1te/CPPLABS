#ifndef LAB5_QUEUE_H
#define LAB5_QUEUE_H

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next = nullptr;
        explicit Node(const T& value): data(value) {}
    };
    Node* front = nullptr;
    Node* rear = nullptr;
    size_t size = 0;

public:
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    Queue(const Queue& other) {
        Node* current = other.front;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
    }

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            while (!isEmpty()) {
                pop();
            }

            Node* current = other.front;
            while (current != nullptr) {
                push(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push(const T& value) {
        auto newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
        }

        Node* temp = front;
        T value = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
        return value;
    }

    T peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
        }
        return front->data;
    }

    void printQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        Node* current = front;
        std::cout << "Queue contents: ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    [[nodiscard]] size_t getSize() const {
        return size;
    }

    [[nodiscard]] bool isEmpty() const {
        return front == nullptr;
    }
};

#endif//LAB5_QUEUE_H
