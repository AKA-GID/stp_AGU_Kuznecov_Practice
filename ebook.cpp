#include "ebook.h"

#include <iostream>
#include <utility>

Ebook::Ebook(std::string title, std::string author, int year, int pages,
             std::string url)
    : Book(std::move(title), std::move(author), year, pages), url_(std::move(url)) {}

std::string Ebook::url() const { return url_; }

void Ebook::download() const {
    std::cout << "Starting download: " << url_ << '\n';
}

std::string Ebook::description() const {
    return Book::description() + " [URL: " + url_ + "]";
}

void Ebook::updateTitle(std::string new_title) {
    Book::updateTitle(std::move(new_title));
}
