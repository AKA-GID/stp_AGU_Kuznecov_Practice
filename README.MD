# Практические работы по C++

Коллекция практических работ по дисциплине «Языки программирования», 2 курс, ИБ.

Каждая практическая находится в отдельной ветке. Открой ветку, чтобы увидеть её исходный код, задание и пояснения.

| Ветка | Тема | Материалы |
|---|---|---|
| [`Practice_two`](https://github.com/AKA-GID/stp_AGU_Kuznecov_Practice/tree/Practice_two) | Проверка данных `Book`, свободные функции, принцип единственной ответственности | `Readme.md`, `Уточнение к работе.md` |
| [`Practice_three`](https://github.com/AKA-GID/stp_AGU_Kuznecov_Practice/tree/Practice_three) | Передача объектов по значению, ссылке и указателю | `Readme.md`, `Уточнение к работе.md` |
| [`Practice_four`](https://github.com/AKA-GID/stp_AGU_Kuznecov_Practice/tree/Practice_four) | Наследование `RareBook` от `Book` | `Readme.md`, `Уточнение к работе.md` |
| [`Practice_five`](https://github.com/AKA-GID/stp_AGU_Kuznecov_Practice/tree/Practice_five) | `Ebook`, полиморфизм и принцип подстановки Лисков | `Readme.md`, `Уточнение к работе.md` |
| [`Practice_six`](https://github.com/AKA-GID/stp_AGU_Kuznecov_Practice/tree/Practice_six) | `Vector2D`, перегрузка методов и операторов | `Readme.md`, `Уточнение к работе.md` |

## Проверки

В каждой ветке есть отдельный `tests.cpp` и workflow в `.github/workflows/`. GitHub Actions собирает демонстрационную программу и тесты, запускает их и показывает вывод в логах. Тесты печатают строки `[PASS]`; при ошибке завершаются ненулевым кодом, поэтому workflow отмечается как неуспешный.

Открой раздел **Actions** репозитория, чтобы посмотреть сборку и вывод для конкретной ветки.
