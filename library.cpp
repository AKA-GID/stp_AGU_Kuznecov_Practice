#include "library.h"

#include <ostream>

void Library::add(const Book& book) {
    books_.push_back(book);
}

void Library::remove(int id) {
    if (id < 0 || static_cast<std::size_t>(id) >= books_.size()) {
        return;
    }
    books_.erase(books_.begin() + id);
}

std::size_t Library::size() const {
    return books_.size();
}

std::ostream& operator<<(std::ostream& os, const Library& library) {
    for (std::size_t i = 0; i < library.books_.size(); ++i) {
        if (i != 0) {
            os << '\n';
        }
        os << library.books_[i].description();
    }
    return os;
}
