#ifndef LAB5_QUEUE_H
#define LAB5_QUEUE_H

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& value): data(value), next(nullptr) {}
    };
    Node* front;
    Node* rear;
    size_t size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
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
            throw std::runtime_error("Queue is empty");
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
            throw std::runtime_error("Queue is empty");
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
