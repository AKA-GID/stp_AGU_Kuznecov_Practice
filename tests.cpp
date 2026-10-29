#include <iostream>
#include <string>

#include "Book.h"
#include "Book_utils.h"

namespace {
int failures = 0;
void check(bool condition, const std::string& name) {
    std::cout << (condition ? "[PASS] " : "[FAIL] ") << name << '\n';
    if (!condition) ++failures;
}
}

int main() {
    Book first("First", "Author A", 1900, 100);
    Book second("Second", "Author B", 2000, 200);

    swap_titles_by_value(first, second);
    check(first.title() == "First" && second.title() == "Second",
          "pass by value changes only local copies");
    swap_titles_by_reference(first, second);
    check(first.title() == "Second" && second.title() == "First",
          "pass by reference changes the original books");
    swap_titles_by_pointer(&first, &second);
    check(first.title() == "First" && second.title() == "Second",
          "pointer function swaps the original books");

    swap_titles_by_pointer(nullptr, &first);
    swap_titles_by_pointer(&second, nullptr);
    check(first.title() == "First" && second.title() == "Second",
          "pointer function safely ignores nullptr");
    check(is_older(first, second), "const-reference comparison uses year");
    check(is_book_available(&first), "availability accepts a valid pointer");
    first.checkout();
    check(!is_book_available(&first), "availability reflects checkout");
    check(!is_book_available(nullptr), "availability rejects nullptr");
    check(getInfo(first).find("Checked Out") != std::string::npos,
          "getInfo reports current status");

    if (failures == 0) std::cout << "All tests passed.\n";
    else std::cout << failures << " test(s) failed.\n";
    return failures == 0 ? 0 : 1;
}
