#include <iostream>
#include <vector>
#include "Hashtable.h"

bool find_sub_string(std::string str, std::string sub) { //функция поиска подстроки в строке с помощью хэш-таблицы
    Hashtable table;
    for (int i = 0; i < str.size() - sub.size(); ++i) {
        table.insert(str.substr(i, sub.size()));
    }
    return table.find(sub);
}

int main() {
    std::string str[3];
    std::cout << "Enter 3 strings:\n";
    std::cin >> str[0] >> str[1] >> str[2];

    Hashtable hashtable;
    hashtable.insert(str[0]);
    hashtable.insert(str[1]);
    hashtable.insert(str[2]);

    hashtable.show();
}