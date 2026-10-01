# Практическая №4
## Часть 1. Добавление метода описания в Book

Прежде чем создавать производный класс, добавим в `Book` метод, который будет полезен и для родителя, и для наследника.

Добавьте в `book.h` объявление:

```cpp
std::string description() const;
```

Реализуйте в `book.cpp`:

```cpp
std::string Book::description() const {
    return title_ + " by " + author_ + " (" + std::to_string(year_) + ")";
}
```

Проверьте в `main.cpp`:

```cpp
Book b(...);
std::cout << b.description() << std::endl;
```

---

## Часть 2. Создание RareBook

**Задача:** Создать класс `RareBook`, который наследуется от `Book` и добавляет поле `estimated_value_` (оценочная стоимость) и метод `applyDiscount()`.

Создайте файл `rarebook.h`:

```cpp
#ifndef RAREBOOK_H
#define RAREBOOK_H
#include <string>
#include "book.h"
class RareBook : public Book {
public:
    RareBook(std::string title, std::string author, int year, int pages,
             double estimated_value);
    double estimatedValue() const;
    void applyDiscount(double percent);
    std::string description() const;  // Переопределение
private:
    double estimated_value_;
};
#endif // RAREBOOK_H
```

Создайте файл `rarebook.cpp`:

Реализуйте конструктор. **Важно:** он должен вызвать конструктор базового класса `Book` в списке инициализации.

```cpp
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
    // Ваша реализация
}
void RareBook::applyDiscount(double percent) {
    // Ваша реализация
}
std::string RareBook::description() const {
    return Book::description() + " [Estimated value: $" 
           + std::to_string(estimated_value_) + "]";
}
```

**Ответьте на вопросы:**

1. Почему в конструкторе `RareBook` нужно вызывать `Book(title, author, year, pages)`?
2. Что произойдет, если этого не сделать?
3. В каком порядке вызываются конструкторы: сначала `Book` или сначала `RareBook`?
4. Может ли `RareBook::description()` обратиться к `title_` напрямую? Почему?

---

## Часть 3. Проверка наследования в main.cpp

**Задача:** Убедиться, что `RareBook` корректно наследует `Book`, и что все три типа работы с методами родителя (переиспользование, переопределение, расширение) работают как ожидается.

**Что нужно сделать в `main.cpp`:**

1. Подключите оба заголовочных файла — `book.h` и `rarebook.h`.
2. Создайте обычную книгу `Book` с произвольными корректными данными (название, автор, год, количество страниц).
3. Создайте редкую книгу `RareBook` с произвольными корректными данными, включая оценочную стоимость (например, `15000.0`).

**Проверьте переиспользование — унаследованные геттеры:**

- Выведите название, автора, год и количество страниц редкой книги, используя только унаследованные методы `title()`, `author()`, `year()`, `pages()`.
- Убедитесь, что они возвращают те значения, которые вы передали в конструктор.

**Унаследованные методы, изменяющие состояние:**

- Вызовите у редкой книги метод `checkout()` (унаследован от `Book`).
- Выведите статус доступности через `isAvailable()` — он должен стать `false`.
- Вызовите `returnBook()`.
- Снова выведите статус — он должен стать `true`.

**Проверьте переопределение — переопределённый `description()`:**

- Выведите `description()` для обычной книги.
- Выведите `description()` для редкой книги.
- Убедитесь, что описание редкой книги содержит всё, что содержит описание обычной книги, плюс информацию оценочной стоимости. Это доказывает, что `RareBook::description()` вызывает `Book::description()` и дополняет его.

**Проверьте расширение — собственный метод `RareBook`:**

- Выведите оценочную стоимость через `estimatedValue()`.
- Примените скидку 10% через `applyDiscount(10.0)`.
- Снова выведите оценочную стоимость — она должна уменьшиться на 10%.
- Выведите `description()` ещё раз, чтобы убедиться, что новая стоимость отражается в описании.

**Проверьте обработку ошибок:**

- Попробуйте применить скидку 150% (некорректное значение) внутри блока `try/catch`.
- Убедитесь, что