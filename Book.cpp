#include "Book.h"

#include <stdexcept>
#include <string>


// Конструктор с валидацией данных
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

// Управление доступностью книги
void Book::checkout() { is_available_ = false; }

// Возвращает книгу в библиотеку
void Book::returnBook() { is_available_ = true; }

// Обновляет название книги
void Book::updateTitle(std::string new_title) {
    if (!isValidData(new_title, author_, year_, pages_)) {
        throw std::invalid_argument("Название книги не может быть пустым");
    }
    title_ = new_title;
}

// Обновляет автора книги
void Book::updateAuthor(std::string new_author) {
    if (!isValidData(title_, new_author, year_, pages_)) {
        throw std::invalid_argument("Автор книги не может быть пустым");
    }
    author_ = new_author;
}

// Обновляет год издания книги
void Book::updateYear(int new_year) {
    if (!isValidData(title_, author_, new_year, pages_)) {
        throw std::invalid_argument("Год издания должен быть от 1450 до 2025");
    }
    year_ = new_year;
}

// Обновляет количество страниц книги
void Book::updatePages(int new_pages) {
    if (!isValidData(title_, author_, year_, new_pages)) {
        throw std::invalid_argument("Число страниц должно быть больше 0");
    }
    pages_ = new_pages;
}

// Проверяет корректность данных книги
bool Book::isValidData(std::string title, std::string author, int year, int pages) const {
    if (title.empty() || author.empty()) {
        return false;
    }
    if (year < 1450 || year > 2025) { // Год издания должен быть от 1450 до 2025
        return false;
    }
    if (pages <= 0) {
        return false;
    }
    return true;
}

void swap_titles_by_value(Book b1, Book b2) {
    std::string temporary_title = b1.title();
    b1.updateTitle(b2.title());
    b2.updateTitle(temporary_title);
}

void swap_titles_by_reference(Book& b1, Book& b2) {
    std::string temporary_title = b1.title();
    b1.updateTitle(b2.title());
    b2.updateTitle(temporary_title);
}

bool is_older(const Book& b1, const Book& b2) {
    return b1.year() < b2.year();
}

void swap_titles_by_pointer(Book* b1, Book* b2) {
    if (b1 == nullptr || b2 == nullptr) {
        return;
    }

    std::string temporary_title = b1->title();
    b1->updateTitle(b2->title());
    b2->updateTitle(temporary_title);
}

bool is_book_available(const Book* book) {
    return book != nullptr && book->isAvailable();
}