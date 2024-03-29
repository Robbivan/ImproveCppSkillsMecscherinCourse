#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

/// List_bad, map, unordered map
/// реализация set и unordered set схожа с map (нет value)

// у List_bad нельзя indexing, так как реализовано через Node
// insert O(1)
// Operations:
// merge - merged two sorted lists
// sort собственный - std::sort неприменим из-за итераторов
// splice - позволяет взять (часть) лист(а)(вырезать) и поставить в другой лист в определенное место
// Разновидности:
// splice() от целого листа в другой лист O(1)
// splice() от части листа в другой лист с итераторами за O(n)


template<typename T>
class List_bad{
private:
    struct Node{
        T value;
        Node* prev;
        Node* next;
    };
    Node* head;
};



// map
// map <key, value>
// Реализовано через КЧ деревья
// m[5] = "abc"
// m[6];
// m.insert({4,"abc"}); // ключ - значение
// m.erase(4); // убрать ноду с ключом 4
// m.find(7); // возвращает итератор
// m.count(7); // возвращает количество элементов по ключу 7, в map это 0 или 1
// в multi_map реальное кол-во
// m.at(5); // если нет, то будет исключение
// Проход по map занимает !!O(n)!!, а поиск за нормальные O(log(N)) для КЧ, так происходит поскольку при обходе
// дерева мы будем часто повторяться
//
//  O(2 раза)
//  |\
//  O O(по 1 разу для каждого)
// multimap - хранит несколько экземпляров с одним ключом, работает с итераторами
// equal_range, lower_bound, upper_bound


template<typename Key, typename Value, typename Comparator>
class Map{
private:
    struct Node{
        std::pair<const Key,Value> value;
        Node * parent; // для дерева
        Node* left;
        Node* right;
    };
};

// unordered_map
// используется хэш,
// ищет за O(1)
// массив указателей
// по хэшу формируется односвязный список (bucket) для одинаковых хэшей - решение против коллизий
// данный хэш вставляется в список
// ___
// итераторы forward
// каждый конец списка хранит указатель на следующий список, чтобы удобно ходить с помощью forward итераторов,
// не возвращаясь к общей хэш таблице
// также для удаления хранится указатель на последний хэш в предыдущем bucket
// ___
// сравнение ключей equal_to<Key>
// в Node помимо классической pair<const Key, Value> и указателя на next хранится
// uint32_t cashed - закэшированный хэш, чтобы не пересчитывать хэш при переходе от одного bucket к другому
// по "большому" составному списку
// ___
// Специфичные функции для хэш таблиц:
// load_factor(средняя загрузка в bucket), rehash(если больше max_load_factor)
// bucket_count(кол-во bucket), bucket_size(кол-во элементов в конкретном bucket)



int main(){
    List_bad<int> list;
}