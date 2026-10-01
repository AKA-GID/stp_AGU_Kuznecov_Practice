#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(std::string title, std::string author, int year, int pages);

    // Геттеры
    const std::string& title() const;
    const std::string& author() const;
    int year() const;
    int pages() const;
    bool isAvailable() const;
    std::string description() const;

    // Управление доступностью
    void checkout();
    void returnBook();

    // Сеттеры с валидацией
    void updateTitle(std::string new_title);
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

// Меняет названия только у локальных копий книг.
void swap_titles_by_value(Book b1, Book b2);

// Меняет названия у исходных объектов книг.
void swap_titles_by_reference(Book& b1, Book& b2);

// Возвращает true, если первая книга издана раньше второй.
bool is_older(const Book& b1, const Book& b2);

// Меняет названия у книг, на которые указывают b1 и b2.
void swap_titles_by_pointer(Book* b1, Book* b2);

// Возвращает true, если указатель не пустой и книга доступна.
bool is_book_available(const Book* book);

#endif
