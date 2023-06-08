//
// Created by Legion on 6/7/2023.
//

#ifndef LAB_6_MYCLASS_H
#define LAB_6_MYCLASS_H


#include <iostream>
#include <string>

using namespace std;

template<typename K, typename V>
class Node {
public:
    K key;
    V value;
    Node* next;

    Node(K key, V value);
};

template<typename K, typename V>
class AssociativeArray {
private:
    Node<K, V>* head;
    Node<K, V>* tail;
    int size;

public:
    AssociativeArray();

    int getSize();
    V getValue(K key);
    void main_method();
    void addPair(K key, V value);

    class Iterator {
    private:
        Node<K, V>* current;

    public:
        Iterator(Node<K, V>* start);

        bool isEnd();
        void moveToNext();
        V getValue();
    };

    Iterator getIterator();
};



#endif //LAB_6_MYCLASS_H
