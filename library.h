
#ifndef LIBRARY_H//проверят не был ли определен макрос
#define LIBRARY_H

#include <map>
#include <vector>
#include <string>//подключаем нужные библиотеки
using namespace std;
struct Book {//основная структура с нужными нами переменными
    string author;
    string title;
    int year;
    int copies;
};

class Library {
public:

    void runMenu();//функция меню выбора

private:
    void addBook();//функция добавления книги
    void removeBook();//функция удаления книги
    void displayBooksByAuthor(const std::map<string, vector<Book>>& library) const;//функция сортировки книг по авторам
    void displayBooksByYear(const std::map<string, vector<Book>>& library) const;//функция сортировки книг по годам издания
    
    map<string, vector<Book>> library;//создаем контейнер(мап)с ключами из строк(фамилия и инициалы) и значениями состоящих из книг
};

#endif


