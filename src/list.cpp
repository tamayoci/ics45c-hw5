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