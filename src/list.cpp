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

int compare(Node *left, Node *right, int n) {
    int count = 0;
    while (left != nullptr && right != nullptr && count < n) {
        if (left->data != right->data) {
            return left->data - right->data;
        }
        left = left->next;
        right = right->next;
        ++count;
    }
    if (count == n) {
        return 0;
    }
    if (left == nullptr && right == nullptr) {
        return 0;
    }
    if (left == nullptr) {
        return -1;
    }
    return 1;
}

Node *reverse(Node *head) {
    Node *result = nullptr;
    for (Node *p = head; p != nullptr; p = p->next) {
        result = new Node{p->data, result};
    }
    return result;
}

Node *append(Node *left, Node *right) {
    if (left == nullptr) {
        return copy(right);
    }
    Node *result = copy(left);
    Node *tail = result;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = copy(right);
    return result;
}

Node *find_char(Node *head, char c) {
    for (Node *p = head; p != nullptr; p = p->next) {
        if (p->data == c) {
            return p;
        }
    }
    return nullptr;
}

Node *find_list(Node *haystack, Node *needle) {
    if (needle == nullptr) {
        return haystack;
    }
    for (Node *p = haystack; p != nullptr; p = p->next) {
        Node *h = p;
        Node *n = needle;
        while (h != nullptr && n != nullptr && h->data == n->data) {
            h = h->next;
            n = n->next;
        }
        if (n == nullptr) {
            return p;
        }
    }
    return nullptr;
}