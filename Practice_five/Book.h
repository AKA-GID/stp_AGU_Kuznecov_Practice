#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(std::string title, std::string author, int year, int pages);

    const std::string& title() const;
    const std::string& author() const;
    int year() const;
    int pages() const;
    bool isAvailable() const;
    virtual std::string description() const;

    void checkout();
    void returnBook();

    virtual void updateTitle(std::string new_title);
    void updateAuthor(std::string new_author);
    void updateYear(int new_year);
    void updatePages(int new_pages);

private:
    bool isValidData(std::string title, std::string author, int year, int pages) const;

    std::string title_;
    std::string author_;
    int year_;
    int pages_;
    bool is_available_ = true;
};

#endif // BOOK_H
