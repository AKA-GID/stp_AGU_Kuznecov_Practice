#include "Book.h"

#include <stdexcept>
#include <utility>

Book::Book(std::string title, std::string author, int year, int pages)
    : title_(std::move(title)), author_(std::move(author)), year_(year), pages_(pages) {
    if (title_.empty() || author_.empty()) {
        throw std::invalid_argument("Book title and author cannot be empty");
    }
    if (year_ < 1450 || year_ > 2025) {
        throw std::invalid_argument("Book year must be between 1450 and 2025");
    }
    if (pages_ <= 0) {
        throw std::invalid_argument("Book must have at least one page");
    }
}

const std::string& Book::title() const {
    return title_;
}

const std::string& Book::author() const {
    return author_;
}

int Book::year() const {
    return year_;
}

int Book::pages() const {
    return pages_;
}

std::string Book::description() const {
    return title_ + " by " + author_ + " (" + std::to_string(year_) +
           ", " + std::to_string(pages_) + " pages)";
}
