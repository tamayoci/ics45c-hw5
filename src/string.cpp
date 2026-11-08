#include "string.hpp"
#include <algorithm>
#include <compare>
#include <iostream>

using namespace std;

String::String(const char *s) {
    head = list::from_string(s);
}

String::String(const String &s) {
    head = list::copy(s.head);
}

String::String(String &&s) {
    head = s.head;
    s.head = nullptr;
}

void String::swap(String &s) {
    std::swap(head, s.head);
}

String &String::operator=(const String &s) {
    if (this != &s) {
        String temp(s);
        swap(temp);
    }
    return *this;
}

String &String::operator=(String &&s) {
    if (this != &s) {
        list::free(head);
        head = s.head;
        s.head = nullptr;
    }
    return *this;
}

bool String::in_bounds(int index) const {
    return index >= 0 && index < size();
}

char String::operator[](int index) const {
    if (!in_bounds(index)) {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return '\0';
    }
    return list::nth(head, index)->data;
}

int String::size() const {
    return list::length(head);
}