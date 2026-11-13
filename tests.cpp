#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Book.h"
#include "library.h"

namespace {
int failures = 0;

void check(bool condition, const std::string& name) {
    std::cout << (condition ? "[PASS] " : "[FAIL] ") << name << '\n';
    if (!condition) {
        ++failures;
    }
}

template <typename Function>
bool throwsInvalidArgument(Function action) {
    try {
        action();
    } catch (const std::invalid_argument&) {
        return true;
    }
    return false;
}
} // namespace

int main() {
    const Book first("1984", "George Orwell", 1949, 328);
    const Book second("Dune", "Frank Herbert", 1965, 412);

    check(first.description() == "1984 by George Orwell (1949, 328 pages)",
          "Book description includes its fields");
    check(throwsInvalidArgument([] { Book("", "Author", 2000, 100); }),
          "Book rejects an empty title");
    check(throwsInvalidArgument([] { Book("Title", "Author", 2000, 0); }),
          "Book rejects a non-positive page count");

    Book c_array[] = {first, second};
    check(sizeof(c_array) / sizeof(c_array[0]) == 2,
          "C-style array has the expected number of elements");

    const std::array<Book, 2> fixed_array = {first, second};
    check(fixed_array.size() == 2 && fixed_array.at(1).title() == "Dune",
          "std::array exposes its size and checked access");
    bool out_of_range_thrown = false;
    try {
        (void)fixed_array.at(2);
    } catch (const std::out_of_range&) {
        out_of_range_thrown = true;
    }
    check(out_of_range_thrown, "std::array::at rejects an invalid index");

    std::vector<Book> dynamic_array = {first, second};
    dynamic_array.push_back(Book("The Hobbit", "J.R.R. Tolkien", 1937, 310));
    check(dynamic_array.size() == 3, "std::vector grows when a book is added");
    dynamic_array.erase(dynamic_array.begin() + 1);
    check(dynamic_array.size() == 2 && dynamic_array[1].title() == "The Hobbit",
          "std::vector erases the requested element");

    Library library;
    library.add(first);
    library.add(second);
    check(library.size() == 2, "Library adds books and reports its size");

    std::ostringstream output;
    output << library;
    check(output.str() == first.description() + "\n" + second.description(),
          "Library output places each book on a separate line");

    library.remove(1);
    check(library.size() == 1, "Library removes a book by index");
    library.remove(-1);
    library.remove(10);
    check(library.size() == 1 && library.size() > 0,
          "Library ignores negative and out-of-range indexes");

    library.remove(0);
    check(library.size() == 0, "Library can remove its last book");

    if (failures == 0) {
        std::cout << "All tests passed.\n";
    } else {
        std::cout << failures << " test(s) failed.\n";
    }
    return failures == 0 ? 0 : 1;
}
