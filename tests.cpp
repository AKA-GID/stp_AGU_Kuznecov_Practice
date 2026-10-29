#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Book.h"
#include "Book_utils.h"
#include "rarebook.h"

namespace {
int failures = 0;
void check(bool condition, const std::string& name) {
    std::cout << (condition ? "[PASS] " : "[FAIL] ") << name << '\n';
    if (!condition) ++failures;
}
template <typename Function>
bool throwsInvalidArgument(Function action) {
    try { action(); } catch (const std::invalid_argument&) { return true; }
    return false;
}
}

int main() {
    Book regular("1984", "George Orwell", 1949, 328);
    RareBook rare("First edition", "A. Author", 1900, 240, 15000.0);
    check(regular.description() == "1984 by George Orwell (1949)",
          "Book description includes title, author and year");
    check(rare.title() == "First edition" && rare.author() == "A. Author" &&
          rare.year() == 1900 && rare.pages() == 240, "RareBook inherits Book getters");

    rare.checkout();
    check(!rare.isAvailable(), "RareBook inherits checkout");
    rare.returnBook();
    check(rare.isAvailable(), "RareBook inherits returnBook");
    check(rare.description().find("First edition by A. Author (1900)") == 0 &&
          rare.description().find("Estimated value: $15000.000000") != std::string::npos,
          "RareBook description extends Book description");

    rare.applyDiscount(10.0);
    check(std::abs(rare.estimatedValue() - 13500.0) < 1e-9,
          "10 percent discount updates the value");
    check(rare.description().find("$13500.000000") != std::string::npos,
          "description reflects discounted value");
    check(throwsInvalidArgument([&] { rare.applyDiscount(150.0); }),
          "discount above 100 percent is rejected");
    check(throwsInvalidArgument([] {
        RareBook invalid("Invalid", "Author", 2000, 100, -1.0);
    }), "negative estimated value is rejected");

    if (failures == 0) std::cout << "All tests passed.\n";
    else std::cout << failures << " test(s) failed.\n";
    return failures == 0 ? 0 : 1;
}
