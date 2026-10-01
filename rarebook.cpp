#include "rarebook.h"

#include <stdexcept>
#include <string>

RareBook::RareBook(std::string title, std::string author, int year, int pages,
                   double estimated_value)
    : Book(title, author, year, pages), estimated_value_(estimated_value) {
    if (estimated_value_ < 0) {
        throw std::invalid_argument("Estimated value cannot be negative");
    }
}

double RareBook::estimatedValue() const {
    return estimated_value_;
}

void RareBook::applyDiscount(double percent) {
    if (percent < 0 || percent > 100) {
        throw std::invalid_argument("Discount must be between 0 and 100 percent");
    }
    estimated_value_ *= (1.0 - percent / 100.0);
}

std::string RareBook::description() const {
    return Book::description() + " [Estimated value: $" +
           std::to_string(estimated_value_) + "]";
}
