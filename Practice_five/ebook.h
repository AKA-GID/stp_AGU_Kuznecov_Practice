#ifndef EBOOK_H
#define EBOOK_H

#include <string>

#include "Book.h"

class Ebook : public Book {
public:
    Ebook(std::string title, std::string author, int year, int pages,
          std::string url);

    std::string url() const;
    void download() const;
    std::string description() const override;
    void updateTitle(std::string new_title) override;

private:
    std::string url_;
};

#endif // EBOOK_H
