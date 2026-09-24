#include "book_utils.h"

#include <stdexcept>
#include <string>

std::string getInfo(const Book& book) {
    std::string status;
    if (book.isAvailable()) {
        status = "Available";
    } else {
        status = "Checked Out";
    }
    return "Title: " + book.title() +
           ", Author: " + book.author() +
           ", Year: " + std::to_string(book.year()) +
           ", Pages: " + std::to_string(book.pages()) +
           ", Status: " + status;
}

// true, если книга издана до 1975 года (более 50 лет назад)
bool isClassic(const Book& book) {
    return book.year() < 1975;
}

// Вычисляет примерное время чтения книги в днях при заданной скорости чтения 
double readingTime(const Book& book, int pages_per_day) {
    if (pages_per_day <= 0) {
        throw std::invalid_argument("Скорость чтения должна быть больше 0 страниц в день");
    }
    return static_cast<double>(book.pages()) / pages_per_day;
}

// true, если first издана раньше, чем second
bool isOlder(const Book& first, const Book& second) {
    return first.year() < second.year();
}