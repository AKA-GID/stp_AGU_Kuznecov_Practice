#ifndef LIBRARY_H
#define LIBRARY_H

#include <iosfwd>
#include <vector>

#include "Book.h"

class Library {
public:
    Library() = default;

    void add(const Book& book);
    void remove(int id);
    std::size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const Library& library);

private:
    // vector растёт по мере добавления и хранит только существующие книги;
    // массивы фиксированного размера тратят место или ограничивают вместимость.
    std::vector<Book> books_;
};

#endif // LIBRARY_H
