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