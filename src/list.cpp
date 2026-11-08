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

