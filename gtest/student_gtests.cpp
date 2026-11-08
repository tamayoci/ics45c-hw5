#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, FromStringEmpty) {
    Node* head = list::from_string("");
    EXPECT_EQ(head, nullptr);
    list::free(head);
}

TEST(ListTests, FreeNullptr) {
    list::free(nullptr);
}

TEST(ListTests, Print) {
    Node* head = list::from_string("foo");
    std::ostringstream out;
    list::print(out, head);
    EXPECT_EQ(out.str(), "foo");
    list::free(head);
}

TEST(ListTests, Copy) {
    Node* head = list::from_string("foo");
    Node* copied = list::copy(head);
    EXPECT_NE(head, copied);
    EXPECT_EQ(list::length(copied), 3);
    EXPECT_EQ(head->data, copied->data);
    EXPECT_EQ(head->next->data, copied->next->data);
    copied->data = 'b';
    EXPECT_EQ(head->data, 'f');
    EXPECT_EQ(copied->data, 'b');
    list::free(head);
    list::free(copied);
}

TEST(ListTests, Compare) {
    Node* a = list::from_string("abc");
    Node* b = list::from_string("abc");
    Node* c = list::from_string("abd");
    Node* d = list::from_string("ab");

    EXPECT_EQ(list::compare(a, b), 0);
    EXPECT_LT(list::compare(a, c), 0);
    EXPECT_GT(list::compare(c, a), 0);
    EXPECT_GT(list::compare(a, d), 0);

    list::free(a);
    list::free(b);
    list::free(c);
    list::free(d);
}

TEST(ListTests, CompareN) {
    Node* a = list::from_string("abc");
    Node* b = list::from_string("abd");

    EXPECT_EQ(list::compare(a, b, 2), 0);
    EXPECT_LT(list::compare(a, b, 3), 0);

    list::free(a);
    list::free(b);
}

TEST(ListTests, Reverse) {
    Node* head = list::from_string("abc");
    Node* reversed = list::reverse(head);

    std::ostringstream out;
    list::print(out, reversed);

    EXPECT_EQ(out.str(), "cba");

    list::free(head);
    list::free(reversed);
}

TEST(ListTests, Append) {
    Node* a = list::from_string("abc");
    Node* b = list::from_string("def");

    Node* combined = list::append(a, b);

    std::ostringstream out;
    list::print(out, combined);

    EXPECT_EQ(out.str(), "abcdef");

    list::free(a);
    list::free(b);
    list::free(combined);
}

TEST(ListTests, FindChar) {
    Node* head = list::from_string("hello");

    Node* found = list::find_char(head, 'e');
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->data, 'e');

    EXPECT_EQ(list::find_char(head, 'z'), nullptr);

    list::free(head);
}

TEST(ListTests, FindList) {
    Node* haystack = list::from_string("hello");
    Node* needle = list::from_string("ell");

    Node* found = list::find_list(haystack, needle);

    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->data, 'e');

    Node* missing = list::from_string("xyz");

    EXPECT_EQ(list::find_list(haystack, missing), nullptr);

    list::free(haystack);
    list::free(needle);
    list::free(missing);
}

TEST(ListTests, Last) {
    Node* head = list::from_string("abc");
    Node* tail = list::last(head);

    ASSERT_NE(tail, nullptr);
    EXPECT_EQ(tail->data, 'c');

    list::free(head);
}

TEST(ListTests, Nth) {
    Node* head = list::from_string("abc");

    EXPECT_EQ(list::nth(head, 0)->data, 'a');
    EXPECT_EQ(list::nth(head, 1)->data, 'b');
    EXPECT_EQ(list::nth(head, 2)->data, 'c');
    EXPECT_EQ(list::nth(head, 3), nullptr);

    list::free(head);
}

TEST(ListTests, Index) {
    Node* head = list::from_string("abc");

    EXPECT_EQ(list::index(head, head), 0);
    EXPECT_EQ(list::index(head, head->next), 1);

    list::free(head);
}
