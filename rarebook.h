#ifndef RAREBOOK_H
#define RAREBOOK_H

#include <string>

#include "Book.h"

class RareBook : public Book {
public:
    RareBook(std::string title, std::string author, int year, int pages,
             double estimated_value);

    double estimatedValue() const;
    void applyDiscount(double percent);
    std::string description() const;

private:
    double estimated_value_;
};

#endif // RAREBOOK_H
