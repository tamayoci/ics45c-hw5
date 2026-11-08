#include "list.hpp"
#include <sstream>

namespace list {

int length(Node *head) {
    int count = 0;
    for (Node *p = head; p != nullptr; p = p->next) {
        ++count;
    }
    return count;
}

Node *from_string(const char *s) {
    if (s[0] == '\0') {
        return nullptr;
    }
    Node *head = new Node{s[0], nullptr};
    Node *tail = head;

    for (int i = 1; s[i] != '\0'; ++i) {
        tail->next = new Node{s[i], nullptr};
        tail = tail->next;
    }
    return head;
}

void free(Node *head) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *copy(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node *new_head = new Node{head->data, nullptr};
    Node *tail = new_head;
    for (Node *p = head->next; p != nullptr; p = p->next) {
        tail->next = new Node{p->data, nullptr};
        tail = tail->next;
    }
    return new_head;
}

int compare(Node *left, Node *right) {
    while (left != nullptr && right != nullptr) {
        if (left->data != right->data) {
            return left->data - right->data;
        }
        left = left->next;
        right = right->next;
    }
    if (left == nullptr && right == nullptr) {
        return 0;
    }
    if (left == nullptr) {
        return -1;
    }
    return 1;
}