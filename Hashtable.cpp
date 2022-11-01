#include "Hashtable.h"


Hashtable::Hashtable() {
    mas = new std::list<std::string>[SIZE];
}

Hashtable::~Hashtable() {
    delete[] mas;
}

unsigned int Hashtable::hashfunc(const std::string &str) {
    unsigned int hashcode = 0;

    for (char i: str) {
        hashcode <<= 5;
        hashcode |= (i - 'A');
        hashcode %= SIZE;
    }
    return hashcode;
}

void Hashtable::insert(const std::string &str) {
    unsigned int hashcode = hashfunc(str);
    mas[hashcode].push_back(str);
    string_count++;
}

bool Hashtable::find(const std::string &str) {
    unsigned int hash;
    hash = hashfunc(str);
    for (auto iter: mas[hash]) {
        if (iter == str) {
            return true;
        }
    }
    return false;
}

void Hashtable::delete_str(const std::string &str) {
    unsigned int hash;
    hash = hashfunc(str);
    for (auto it = mas[hash].begin(); it != mas[hash].end();) {
        if (*it == str) {
            it = mas[hash].erase(it);
            break;
        } else {
            ++it;
        }
    }
}

unsigned int Hashtable::count() {
    std::cout << string_count << std::endl;
    return string_count;
}

unsigned int Hashtable::size() {
    return SIZE;
}

void Hashtable::show() {
    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << " ";
        switch (mas[i].size()) {
            case 0:
                std::cout << "free";
                std::cout << std::endl;
                break;
            default:
                std::cout << "busy: \n";
                for (auto &it: mas[i]) {
                    std::cout << "\t" << it << std::endl;
                }
                break;
        }
    }
}

void Hashtable::clear() {
    delete[] mas;
    string_count = 0;
    mas = new std::list<std::string>[SIZE];
}