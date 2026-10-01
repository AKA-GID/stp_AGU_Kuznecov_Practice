#include <iostream>
#include <stdexcept>

#include "Book.h"
#include "Book_utils.h"
#include "rarebook.h"

int main() {
    Book book("Война и мир", "Л. Толстой", 1869, 1225);
    std::cout << getInfo(book) << "\n\n";

    // Попытка обновить год издания на некорректное значение
    try {
        book.updateYear(3000); // Исключение: год издания должен быть от 1450 до 2025
        std::cout << "Год обновлён (сюда попасть не должны)\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }

    // Попытка обновить количество страниц на отрицательное значение
    try {
        book.updateTitle("Война и мир. Том 1");  // корректное обновление
        std::cout << "Название обновлено: " << book.title() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }

    // Попытка обновить количество страниц на некорректное значение
    try {
        book.updatePages(0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
    std::cout << "\n";

    // Создание двух книг для демонстрации функций из Book_utils
    Book orwell("1984", "Д. Оруэлл", 1949, 328);
    Book modern("Чистый код", "Р. Мартин", 2008, 464);

    std::cout << getInfo(orwell) << "\n";
    orwell.checkout();
    std::cout << getInfo(orwell) << "\n\n";

    std::cout << "'" << orwell.title() << "' - классика? "
              << (isClassic(orwell) ? "да" : "нет") << "\n";
    std::cout << "'" << modern.title() << "' - классика? "
              << (isClassic(modern) ? "да" : "нет") << "\n";

    std::cout << "Время чтения '" << orwell.title() << "' при 40 стр/день: "
              << readingTime(orwell, 40) << " дн.\n";

    // Попытка вычислить время чтения с некорректной скоростью          
    try {
        readingTime(orwell, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }

    // Сравнение двух книг по году издания
    std::cout << "'" << orwell.title() << "' старше '" << modern.title() << "'? "
              << (isOlder(orwell, modern) ? "да" : "нет") << "\n\n";

    Book first("Преступление и наказание", "Ф. Достоевский", 1866, 671);
    Book second("Мастер и Маргарита", "М. Булгаков", 1967, 480);

    std::cout << "Обмен по значению:\n";
    std::cout << "До: " << first.title() << " | " << second.title() << "\n";
    swap_titles_by_value(first, second);
    std::cout << "После: " << first.title() << " | " << second.title() << "\n\n";

    std::cout << "Обмен по ссылке:\n";
    std::cout << "До: " << first.title() << " | " << second.title() << "\n";
    swap_titles_by_reference(first, second);
    std::cout << "После: " << first.title() << " | " << second.title() << "\n\n";

    std::cout << "Сравнение через const-ссылки:\n";
    std::cout << "'" << first.title() << "' старше '" << second.title() << "'? "
              << (is_older(first, second) ? "да" : "нет") << "\n\n";

    std::cout << "Обмен через указатели:\n";
    std::cout << "До: " << first.title() << " | " << second.title() << "\n";
    swap_titles_by_pointer(&first, &second);
    std::cout << "После: " << first.title() << " | " << second.title() << "\n\n";

    Book* first_pointer = &first;
    std::cout << "Книга '" << first.title() << "' доступна? "
              << (is_book_available(first_pointer) ? "да" : "нет") << "\n";
    std::cout << "nullptr указывает на доступную книгу? "
              << (is_book_available(nullptr) ? "да" : "нет") << "\n\n";

    //  Неккорректные данные при создании книги          
    try {
        Book bad("", "Автор", 2000, 100);
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка создания: " << e.what() << "\n";
    }

    // Практическая 4: наследование RareBook от Book.
    Book regular_book("Анна Каренина", "Л. Толстой", 1878, 864);
    RareBook rare_book("Первое издание", "А. Пушкин", 1833, 240, 15000.0);

    std::cout << "\nОписание обычной книги: " << regular_book.description() << "\n";
    std::cout << "Описание редкой книги: " << rare_book.description() << "\n";
    std::cout << "Поля редкой книги: " << rare_book.title() << " | "
              << rare_book.author() << " | " << rare_book.year() << " | "
              << rare_book.pages() << "\n";

    rare_book.checkout();
    std::cout << "Редкая книга доступна после выдачи? "
              << (rare_book.isAvailable() ? "да" : "нет") << "\n";
    rare_book.returnBook();
    std::cout << "Редкая книга доступна после возврата? "
              << (rare_book.isAvailable() ? "да" : "нет") << "\n";

    std::cout << "Оценочная стоимость: $" << rare_book.estimatedValue() << "\n";
    rare_book.applyDiscount(10.0);
    std::cout << "После скидки 10%: $" << rare_book.estimatedValue() << "\n";
    std::cout << "Новое описание: " << rare_book.description() << "\n";

    try {
        rare_book.applyDiscount(150.0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка скидки: " << e.what() << "\n";
    }

    try {
        RareBook invalid_rare_book("Некорректная оценка", "Автор", 2000, 100, -1.0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка создания редкой книги: " << e.what() << "\n";
    }

    return 0;
}
