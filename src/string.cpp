#include "string.hpp"
#include <algorithm>
#include <compare>
#include <iostream>

using namespace std;

String::String(const char *s) {
    head = list::from_string(s);
}
