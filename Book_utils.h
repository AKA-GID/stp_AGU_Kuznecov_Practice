#ifndef BOOK_UTILS_H
#define BOOK_UTILS_H

#include <string>

#include "book.h"



// Вид функции getInfo, которая возвращает строку с информацией о книге
std::string getInfo(const Book& book);

// true, если книга издана до 1975 года (более 50 лет назад)
bool isClassic(const Book& book);

// Вычисляет примерное время чтения книги в днях при заданной скорости чтения (pages_per_day)
double readingTime(const Book& book, int pages_per_day);

// true, если first издана раньше, чем second
bool isOlder(const Book& first, const Book& second);

#endif