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

## Как скачать и запустить проект

### 1. Установите инструменты

- **Windows:** установите [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) с компонентом **Разработка классических приложений на C++**. Он включает компилятор MSVC.
- **Windows, macOS или Linux с VS Code:** установите [Visual Studio Code](https://code.visualstudio.com/), расширение [C/C++ от Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) и компилятор C++. На macOS его можно установить командой `xcode-select --install`; на Windows подойдут MSVC из Visual Studio или MinGW-w64; на Linux — `g++` из менеджера пакетов.
- **macOS с Xcode:** установите [Xcode из App Store](https://developer.apple.com/xcode/). Если нужен только компилятор для терминала, достаточно Command Line Tools: `xcode-select --install`.

### 2. Склонируйте репозиторий

Откройте терминал (в VS Code: **Терминал → Создать терминал**) и выполните:

```bash
git clone https://github.com/AKA-GID/stp_AGU_Kuznecov_Practice.git
cd stp_AGU_Kuznecov_Practice
git switch Practice_six
```

Вместо `Practice_six` укажите нужную ветку: `Practice_two`, `Practice_three`, `Practice_four`, `Practice_five` или `Practice_six`. Ветка `main` содержит этот обзор; исходники практических находятся в соответствующих ветках. Команда `git switch` переключает уже склонированную папку на выбранную работу.

### 3. Запуск в VS Code

1. В VS Code выберите **Файл → Открыть папку** и откройте папку репозитория.
2. Убедитесь, что выбрана нужная ветка (её имя видно в левом нижнем углу окна).
3. Откройте встроенный терминал и соберите программу. Например, для шестой практической:

   ```bash
   g++ -std=c++17 -Wall -Wextra -pedantic vector2d.cpp main.cpp -o practice
   ```

4. Запустите её:

   ```bash
   ./practice
   ```

На Windows в PowerShell запустите `.\practice.exe`. Если команда `g++` не найдена, сначала установите компилятор и перезапустите VS Code. Установка расширения C/C++ сама по себе компилятор не устанавливает.

### 4. Запуск в Visual Studio (Windows)

1. Откройте Visual Studio и выберите **Создать проект → Консольное приложение** на C++.
2. Создайте проект, затем в **Обозревателе решений** нажмите правой кнопкой на **Исходные файлы → Добавить → Существующий элемент** и добавьте `.cpp`-файлы выбранной практической. Заголовки `.h` можно добавить в **Файлы заголовков**.
3. Для обычного запуска добавьте `main.cpp` и файлы реализации этой практической. Для проверки добавьте `tests.cpp` вместо `main.cpp` и те же файлы реализации.
4. Выберите **Отладка → Запуск без отладки** или нажмите `Ctrl+F5`. Результат появится в консольном окне.

В одном запускаемом проекте должен быть только один `main()`: демонстрационный `main.cpp` и `tests.cpp` запускаются по отдельности.

### 5. Запуск в Xcode (macOS)

1. В Xcode выберите **File → New → Project → macOS → Command Line Tool** и задайте язык **C++**.
2. Создайте проект. Добавьте в него через **File → Add Files to…** нужные `.cpp` и `.h` файлы из папки склонированного репозитория и включите исходники в target приложения.
3. В настройках target выберите стандарт C++17 (**Build Settings → C++ Language Dialect**). Если шаблон Xcode создал собственный `main.cpp`, замените его содержимое демонстрационным `main.cpp` из практической.
4. Нажмите кнопку запуска или `⌘R`; вывод программы будет в консоли отладчика внизу окна.

Для запуска тестов используйте `tests.cpp` вместо демонстрационного `main.cpp` (или создайте для тестов отдельный Command Line Tool target). В одном target оставляйте только один файл с `main()`.

### Какие файлы собирать

Для каждой практической берите `main.cpp` и перечисленные файлы реализации из корня выбранной ветки:

| Ветка | Файлы реализации |
|---|---|
| `Practice_two` | `Book.cpp`, `Book_utils.cpp` |
| `Practice_three` | `Book.cpp`, `Book_utils.cpp` |
| `Practice_four` | `book.cpp`, `rarebook.cpp` |
| `Practice_five` | `Book.cpp`, `ebook.cpp` |
| `Practice_six` | `vector2d.cpp` |

Имена файлов учитывают регистр букв. В ветках, где файлы названы с заглавной буквы, используйте именно `Book.cpp` и `Book_utils.cpp`.

### Запуск тестов из терминала

Тесты находятся в `tests.cpp` и собираются отдельно от демонстрационной программы. Например, в шестой практике:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic vector2d.cpp tests.cpp -o practice_tests
./practice_tests
```

В командах для веток `Practice_two` и `Practice_three` используйте `Book.cpp Book_utils.cpp tests.cpp`; для `Practice_four` — `book.cpp rarebook.cpp tests.cpp`; для `Practice_five` — `Book.cpp ebook.cpp tests.cpp`. На Windows в PowerShell запускайте собранные программы как `.\practice_tests.exe`. В macOS вместо `g++` можно написать `clang++`.
