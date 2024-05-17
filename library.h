
#ifndef LIBRARY_H//�������� �� ��� �� ��������� ������
#define LIBRARY_H

#include <map>
#include <vector>
#include <string>//���������� ������ ����������
using namespace std;
struct Book {//�������� ��������� � ������� ���� �����������
    string author;
    string title;
    int year;
    int copies;
};

class Library {
public:

    void runMenu();//������� ���� ������

private:
    void addBook();//������� ���������� �����
    void removeBook();//������� �������� �����
    void displayBooksByAuthor(const std::map<string, vector<Book>>& library) const;//������� ���������� ���� �� �������
    void displayBooksByYear(const std::map<string, vector<Book>>& library) const;//������� ���������� ���� �� ����� �������
    
    map<string, vector<Book>> library;//������� ���������(���)� ������� �� �����(������� � ��������) � ���������� ��������� �� ����
};

#endif


