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

String String::reverse() const {
    return String(list::reverse(head));
}

int String::indexOf(char c) const {
    list::Node *found = list::find_char(head, c);
    if (found == nullptr) {
        return -1;
    }
    return list::index(head, found);
}

int String::indexOf(const String &s) const {
    if (s.head == nullptr) {
        return 0;
    }
    list::Node *found = list::find_list(head, s.head);
    if (found == nullptr) {
        return -1;
    }
    return list::index(head, found);
}

bool String::operator==(const String &s) const {
    return list::compare(head, s.head) == 0;
}

std::strong_ordering String::operator<=>(const String &s) const {
    int result = list::compare(head, s.head);
    if (result < 0) {
        return std::strong_ordering::less;
    }
    if (result > 0) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}


