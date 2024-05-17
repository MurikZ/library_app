#include "library.h" // Подключаем пользовательский заголовочный файл для доступа к классу библиотеки
#include <iostream> 
#include <algorithm> 
#include <limits> // Подключаем стандартный заголовочный файл для доступа к числовым пределам


void Library::addBook() {// Функция для добавления книги в библиотеку
    Book newBook; 
    while (true) {
        cout << "Введите фамилию и инициалы автора: ";
        getline(cin >> ws, newBook.author);// Вводим фамилию и инициалы автора. ws используется для удаления лишних пробелов
        bool hasDigit = false;
        // Проверяем, содержит ли строка цифры
        for (char c : newBook.author) {
            if (isdigit(c)) {
                hasDigit = true;
                break;
            }
        }
        if (hasDigit) {
            // Если в строке есть цифры, выводим сообщение об ошибке и продолжаем цикл
            cout << "Ошибка ввода. Пожалуйста, введите корректные данные (без цифр).\n";
        }
        else {
            // Если введена корректная строка без цифр, выходим из цикла
            break;
        }
    }
    cout << "Введите название книги: ";
    getline(cin >> ws, newBook.title);// Вводим название книги
    while (true) {
        cout << "Введите год издания: ";
        if (cin >> newBook.year and newBook.year>0 and newBook.year<2025) {// Если вводится число, то прерываем цикл
            break;
        }
        else {// Если вводится не число, выводим сообщение об ошибке
            cout << "Ошибка ввода. Пожалуйста, введите корректный год.\n";
            cin.clear();// Очищаем флаги ошибок ввода
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Очищаем буфер ввода
        }
    }
    while (true) {
        cout << "Введите количество экземпляров: ";
        if (cin >> newBook.copies and newBook.copies>0) {
            break;
        }
        else {
            cout << "Ошибка ввода, пожалуйста введите корректное положительное число.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    library[newBook.author].push_back(newBook);// Добавляем книгу в библиотеку
    cout << "*Книга успешно добавлена в библиотеку*.\n";
}

void Library::removeBook() {// Функция для удаления книги из библиотеки
    string author, titleToRemove;
    cout << "Введите фамилию и инициалы автора книги, которую хотите удалить: ";
    getline(cin >> ws, author);// Вводим фамилию и инициалы автора книги для удаления
    cout << "Введите название книги, которую хотите удалить: ";
    getline(cin >> ws, titleToRemove);// Вводим название книги для удаления
    auto& books = library[author];// Получаем список книг указанного автора
    auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
        return book.title == titleToRemove;// Поиск книги по названию
        });
    if (it != books.end()) {// Если книга найдена
        books.erase(it);// Удаляем книгу из списка
        cout << "*Книга успешно удалена из библиотеки*.\n";
    }
    else {// Если книга не найдена
        cout << "Книга с таким названием и автором не найдена.\n";
    }
}

void Library::displayBooksByAuthor(const map<string, vector<Book>>& library) const {// Функция для вывода книг по фамилиям авторов
    cout << "Сведения о книгах, упорядоченных по фамилиям авторов:\n";
    for (const auto& pair : library) {// Перебираем элементы словаря (автор - список книг)
        for (const auto& book : pair.second) {// Перебираем книги автора
            cout << "Автор: " << book.author << ", Название: " << book.title << ", Год издания: " << book.year << ", Количество экземпляров: " << book.copies << endl;
        }
    }
}

void Library::displayBooksByYear(const map<string, vector<Book>>& library) const {// Функция для вывода книг по годам издания
    vector<Book> allBooks;// Создаем вектор для всех книг из библиотеки
    for (const auto& pair : library) {// Перебираем элементы словаря (автор - список книг)
        for (const auto& book : pair.second) {// Перебираем книги автора
            allBooks.push_back(book);// Добавляем книгу в вектор всех книг
        }
    }

    sort(allBooks.begin(), allBooks.end(), [](const Book& a, const Book& b) {
        return a.year < b.year;// Сортируем книги по годам издания
        });

    cout << "Сведения о книгах, упорядоченных по годам издания:\n";
    for (const auto& book : allBooks) {
        cout << "Автор: " << book.author << ", Название: " << book.title << ", Год издания: " << book.year << ", Количество экземпляров: " << book.copies << endl;
    }
}

void Library::runMenu() {// Функция для запуска основного меню программы
    setlocale(0, "ru");
    int choice;
    do {
        cout << "\n----------Меню----------\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Удалить книгу\n";
        cout << "3. Вывести сведения о книгах по фамилиям авторов\n";
        cout << "4. Вывести сведения о книгах по годам издания\n";
        cout << "0. Выйти\n";
        
        while (true) {
            cout << "Выберите действие: ";
            if (cin >> choice) {
                break;
            }
            else {
                cout << "Ошибка ввода. Введите число\n";
                cin.clear();// Очищаем флаги ошибок ввода
                cin.ignore(numeric_limits<streamsize>::max(), '\n');// Очищаем буфер ввода
            }
        }
               
        

        switch (choice) {// Обрабатываем выбор пользователя
        case 1:
            addBook();// Вызываем функцию добавления книги
            break;
        case 2:
            removeBook();// Вызываем функцию удаления книги
            break;
        case 3:
            displayBooksByAuthor(library);// Вызываем функцию вывода книг по фамилиям авторов
            break;
        case 4:
            displayBooksByYear(library);// Вызываем функцию вывода книг по годам издания
            break;
        case 0:
            cout << "Выход из программы.\n";// Выводим сообщение о выходе
            break;
        default:// Если выбран неверный вариант
            cout << "Неверный выбор. Попробуйте снова.\n";// Выводим сообщение об ошибке
        }
    } while (choice != 0);// Повторяем цикл до тех пор, пока пользователь не выберет выход из программы
}

int main() {
    setlocale(LC_ALL, "Russian"); // задаём русский текст
    system("chcp 1251"); // настраиваем кодировку консоли
    Library library;// Создаем объект класса library
    library.runMenu();// Запускаем основное меню программы
    return 0;
}
