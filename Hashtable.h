#pragma once

#include <iostream>
#include "stdio.h"
#include <string>
#include <list>

#define SIZE 19

class Hashtable {
private:
    std::list<std::string> *mas;
    int string_count = 0;
public:
    Hashtable();

    ~Hashtable();

    unsigned int hashfunc(const std::string &str); // хеш-функция, конкатенация битовых образов чисел
    void insert(const std::string &str); // функция вставки строки в таблицу
    bool find(const std::string &str); // функция поиска строки в таблице
    void delete_str(const std::string &str); // удаляет строку из таблицы, если она есть
    unsigned int count();

    unsigned int size(); // возвращает размер таблицы
    void show(); // отображение таблицы
    void clear(); // очистка таблицы
};