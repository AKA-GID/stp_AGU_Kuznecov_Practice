#include <iostream>
#include <stdexcept>

#include "Book.h"
#include "ebook.h"

void print_description(const Book& book) {
    std::cout << book.description() << '\n';
}

int main() {
    const std::string ebook_url = "http://example.com/1984";
    Book book("1984", "George Orwell", 1949, 328);
    Ebook ebook("1984", "George Orwell", 1949, 328, ebook_url);

    std::cout << "Book: ";
    print_description(book);
    std::cout << "Ebook through Book reference: ";
    print_description(ebook);
    std::cout << "URL: " << ebook.url() << '\n';
    ebook.download();

    ebook.updateTitle("Nineteen Eighty-Four");
    std::cout << "Updated ebook: " << ebook.description() << '\n';

    try {
        ebook.updateTitle("");
    } catch (const std::invalid_argument& error) {
        std::cout << "Invalid title rejected: " << error.what() << '\n';
    }

    return 0;
}
