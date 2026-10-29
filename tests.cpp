#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Book.h"
#include "ebook.h"

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
    const std::string url = "http://example.com/1984";
    Book book("1984", "George Orwell", 1949, 328);
    Ebook ebook("1984", "George Orwell", 1949, 328, url);

    check(book.description() == "1984 by George Orwell (1949)",
          "Book description keeps base information");
    check(ebook.url() == url, "Ebook stores and returns its URL");
    check(ebook.description() == "1984 by George Orwell (1949) [URL: " + url + "]",
          "Ebook description extends the Book description");

    const Book& base_view = ebook;
    check(base_view.description() == ebook.description(),
          "virtual description dispatch works through Book reference");
    Book& mutable_base_view = ebook;
    mutable_base_view.updateTitle("Nineteen Eighty-Four");
    check(ebook.title() == "Nineteen Eighty-Four" &&
          mutable_base_view.description().find("Nineteen Eighty-Four") == 0,
          "polymorphic title update preserves the Book contract");
    check(throwsInvalidArgument([&] { mutable_base_view.updateTitle(""); }),
          "empty title is rejected through Book reference");
    check(ebook.title() == "Nineteen Eighty-Four", "failed update leaves title unchanged");

    std::ostringstream download_output;
    std::streambuf* original_output = std::cout.rdbuf(download_output.rdbuf());
    ebook.download();
    std::cout.rdbuf(original_output);
    check(download_output.str().find(url) != std::string::npos,
          "download reports the ebook URL");

    if (failures == 0) std::cout << "All tests passed.\n";
    else std::cout << failures << " test(s) failed.\n";
    return failures == 0 ? 0 : 1;
}
