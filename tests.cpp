#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Book.h"
#include "Book_utils.h"

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
    Book book("1984", "George Orwell", 1949, 328);
    check(book.title() == "1984" && book.author() == "George Orwell" &&
          book.year() == 1949 && book.pages() == 328, "constructor and getters");
    check(book.isAvailable(), "new book is available");

    book.updateTitle("Nineteen Eighty-Four");
    book.updateAuthor("G. Orwell");
    book.updateYear(1950);
    book.updatePages(330);
    check(book.title() == "Nineteen Eighty-Four" && book.author() == "G. Orwell" &&
          book.year() == 1950 && book.pages() == 330, "valid setters update fields");
    check(throwsInvalidArgument([&] { book.updateTitle(""); }), "empty title is rejected");
    check(throwsInvalidArgument([&] { book.updateAuthor(""); }), "empty author is rejected");
    check(throwsInvalidArgument([&] { book.updateYear(3000); }), "invalid year is rejected");
    check(throwsInvalidArgument([&] { book.updatePages(0); }), "invalid page count is rejected");
    check(throwsInvalidArgument([] { Book bad("", "Author", 2000, 10); }),
          "invalid constructor data is rejected");

    const std::string info = getInfo(book);
    check(info.find("Title: Nineteen Eighty-Four") != std::string::npos &&
          info.find("Status: Available") != std::string::npos, "getInfo formats book details");
    const Book classic("Classic", "Author", 1974, 100);
    const Book modern("Modern", "Author", 1975, 100);
    check(isClassic(classic) && !isClassic(modern), "isClassic boundary");
    check(std::abs(readingTime(book, 10) - 33.0) < 1e-9, "readingTime computes days");
    check(throwsInvalidArgument([&] { readingTime(book, 0); }), "bad speed is rejected");
    check(isOlder(classic, modern), "isOlder compares publication years");

    book.checkout();
    check(!book.isAvailable() && getInfo(book).find("Checked Out") != std::string::npos,
          "checkout changes availability");
    book.returnBook();
    check(book.isAvailable(), "returnBook restores availability");

    if (failures == 0) std::cout << "All tests passed.\n";
    else std::cout << failures << " test(s) failed.\n";
    return failures == 0 ? 0 : 1;
}
