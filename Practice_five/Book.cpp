#include "Book.h"

#include <stdexcept>
#include <string>

Book::Book(std::string title, std::string author, int year, int pages)
    : title_(title), author_(author), year_(year), pages_(pages), is_available_(true) {
    if (!isValidData(title_, author_, year_, pages_)) {
        throw std::invalid_argument(
            "Некорректные данные книги: название и автор не должны быть пустыми, "
            "год - от 1450 до 2025, число страниц - больше 0");
    }
}

const std::string& Book::title() const { return title_; }
const std::string& Book::author() const { return author_; }
int Book::year() const { return year_; }
int Book::pages() const { return pages_; }
bool Book::isAvailable() const { return is_available_; }

std::string Book::description() const {
    return title_ + " by " + author_ + " (" + std::to_string(year_) + ")";
}

void Book::checkout() { is_available_ = false; }
void Book::returnBook() { is_available_ = true; }

void Book::updateTitle(std::string new_title) {
    if (!isValidData(new_title, author_, year_, pages_)) {
        throw std::invalid_argument("Название книги не может быть пустым");
    }
    title_ = new_title;
}

void Book::updateAuthor(std::string new_author) {
    if (!isValidData(title_, new_author, year_, pages_)) {
        throw std::invalid_argument("Автор книги не может быть пустым");
    }
    author_ = new_author;
}

void Book::updateYear(int new_year) {
    if (!isValidData(title_, author_, new_year, pages_)) {
        throw std::invalid_argument("Год издания должен быть от 1450 до 2025");
    }
    year_ = new_year;
}

void Book::updatePages(int new_pages) {
    if (!isValidData(title_, author_, year_, new_pages)) {
        throw std::invalid_argument("Число страниц должно быть больше 0");
    }
    pages_ = new_pages;
}

bool Book::isValidData(std::string title, std::string author, int year, int pages) const {
    return !title.empty() && !author.empty() && year >= 1450 && year <= 2025 && pages > 0;
}
