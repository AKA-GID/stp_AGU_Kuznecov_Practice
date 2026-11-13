#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "Book.h"
#include "library.h"

namespace {
double average_pages(const Book books[], std::size_t size) {
    if (size == 0) {
        return 0.0;
    }

    int total_pages = 0;
    for (std::size_t i = 0; i < size; ++i) {
        total_pages += books[i].pages();
    }
    return static_cast<double>(total_pages) / size;
}

double average_pages(const std::array<Book, 5>& books) {
    int total_pages = 0;
    for (const Book& book : books) {
        total_pages += book.pages();
    }
    return static_cast<double>(total_pages) / books.size();
}

void print_books(const std::vector<Book>& books) {
    for (const Book& book : books) {
        std::cout << book.description() << '\n';
    }
}
} // namespace

int main() {
    std::cout << "=== C-style array ===\n";
    Book c_books[5] = {
        Book("War and Peace", "Leo Tolstoy", 1869, 1225),
        Book("1984", "George Orwell", 1949, 328),
        Book("The Hobbit", "J.R.R. Tolkien", 1937, 310),
        Book("Dune", "Frank Herbert", 1965, 412),
        Book("Foundation", "Isaac Asimov", 1951, 255)
    };
    for (int i = 0; i < 5; ++i) {
        std::cout << c_books[i].description() << '\n';
    }
    std::cout << "Average pages: " << average_pages(c_books, 5) << '\n';
    // Размер C-массива теряется при передаче в функцию: его приходится
    // передавать отдельно. Ошибочный size может привести к чтению за границами.
    // c_books[7] = Book("Fake", "Nobody", 2000, 100); // Не запускать: неопределённое поведение.
    // std::array::at() проверяет индекс и сообщает об ошибке исключением.

    std::cout << "\n=== std::array ===\n";
    const std::array<Book, 5> books = {{
        Book("War and Peace", "Leo Tolstoy", 1869, 1225),
        Book("1984", "George Orwell", 1949, 328),
        Book("The Hobbit", "J.R.R. Tolkien", 1937, 310),
        Book("Dune", "Frank Herbert", 1965, 412),
        Book("Foundation", "Isaac Asimov", 1951, 255)
    }};
    for (std::size_t i = 0; i < books.size(); ++i) {
        std::cout << books[i].description() << '\n';
    }
    std::cout << "Same books using range-based for:\n";
    for (const auto& book : books) {
        std::cout << book.description() << '\n';
    }
    std::cout << "Average pages: " << average_pages(books) << '\n';
    try {
        (void)books.at(7);
    } catch (const std::out_of_range& error) {
        std::cout << "at() caught an invalid index: " << error.what() << '\n';
    }
    // operator[] не проверяет индекс; at() проверяет и выбрасывает out_of_range.

    std::cout << "\n=== std::vector ===\n";
    std::vector<Book> collection = {
        Book("War and Peace", "Leo Tolstoy", 1869, 1225),
        Book("1984", "George Orwell", 1949, 328),
        Book("The Hobbit", "J.R.R. Tolkien", 1937, 310)
    };
    std::cout << "Initial size: " << collection.size() << '\n';
    collection.push_back(Book("Dune", "Frank Herbert", 1965, 412));
    collection.push_back(Book("Foundation", "Isaac Asimov", 1951, 255));
    std::cout << "After two additions: " << collection.size() << '\n';

    collection.pop_back();
    std::cout << "After pop_back(): " << collection.size() << '\n';
    collection.erase(collection.begin() + 1);
    std::cout << "After erasing index 1:\n";
    print_books(collection);

    collection.resize(5, Book("Unknown", "Unknown", 2000, 100));
    std::cout << "After resize(5): " << collection.size() << '\n';
    print_books(collection);
    // resize(n) требует конструктор Book() даже когда в этом вызове
    // вектор только уменьшается; удаляем хвост через erase, не ослабляя
    // инварианты Book ради искусственного значения по умолчанию.
    collection.erase(collection.begin() + 2, collection.end());
    std::cout << "After shrinking to 2 elements: " << collection.size() << '\n';
    print_books(collection);

    std::cout << "\n=== Library ===\n";
    Library library;
    library.add(Book("War and Peace", "Leo Tolstoy", 1869, 1225));
    library.add(Book("1984", "George Orwell", 1949, 328));
    library.add(Book("The Hobbit", "J.R.R. Tolkien", 1937, 310));
    library.add(Book("Dune", "Frank Herbert", 1965, 412));
    std::cout << "Library contents:\n" << library << '\n';

    library.remove(1);
    std::cout << "After removing index 1:\n" << library << '\n';
    std::cout << "Library size: " << library.size() << '\n';
    return 0;
}
