//
// Created by Legion on 6/7/2023.
//

#include "Myclass.h"

template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray() : head(nullptr), tail(nullptr), size(0) {}

template<typename K, typename V>
Node<K, V>::Node(K key, V value) : key(key), value(value), next(nullptr) {}

template<typename K, typename V>
AssociativeArray<K, V>::Iterator::Iterator(Node<K, V>* start) : current(start) {}

template<typename K, typename V>
int AssociativeArray<K, V>::getSize() {
    return size;
}

template<typename K, typename V>
V AssociativeArray<K, V>::getValue(K key) {
    Node<K, V>* temp = head;
    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    throw invalid_argument("Key not found");
}

template<typename K, typename V>
void AssociativeArray<K, V>::addPair(K key, V value) {
    Node<K, V>* temp = head;
    while (temp) {
        if (temp->key == key) {
            throw invalid_argument("Key already exists");
        }
        temp = temp->next;
    }
    Node<K, V>* newNode = new Node<K, V>(key, value);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename K, typename V>
typename AssociativeArray<K, V>::Iterator AssociativeArray<K, V>::getIterator() {
    return Iterator(head);
}

template<typename K, typename V>
bool AssociativeArray<K, V>::Iterator::isEnd() {
    return current == nullptr;
}

template<typename K, typename V>
void AssociativeArray<K, V>::Iterator::moveToNext() {
    if (current) {
        current = current->next;
    }
}

template<typename K, typename V>
V AssociativeArray<K, V>::Iterator::getValue() {
    if (current) {
        return current->value;
    }
    throw invalid_argument("End of array reached");
}

template<typename K, typename V>
void AssociativeArray<K, V>::main_method() {

    AssociativeArray<K, V>::Iterator it = getIterator();
    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Add a pair\n";
        cout << "2. Get size\n";
        cout << "3. Get value by key\n";
        cout << "4. Iterator operations\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                K key;
                V value;
                while (true) {
                    cout << "Enter key: ";
                    cin >> key;
                    cout << "Enter value: ";
                    cin >> value;
                    try {
                        this->addPair(key, value);
                        it = this->getIterator();  // Reset iterator to beginning after adding a pair
                        break;  // Exit the loop if addPair is successful
                    } catch (invalid_argument& e) {
                        cout << e.what() << ". Please enter a different key.\n";
                    }
                }
                break;
            }
            case 2:
                cout << "Size: " << this->getSize() << endl;
                break;
            case 3: {
                K key;
                cout << "Enter key: ";
                cin >> key;
                try {
                    cout << "Value: " << this->getValue(key) << endl;
                } catch (invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                while (true) {
                    cout << "\nChoose an iterator operation:\n";
                    cout << "1. Set to beginning\n";
                    cout << "2. Check end\n";
                    cout << "3. Get current value\n";
                    cout << "4. Move to next\n";
                    cout << "5. Return to main menu\n";
                    int iterChoice;
                    cin >> iterChoice;
                    switch (iterChoice) {
                        case 1:
                            it = this->getIterator();  // Reset iterator to beginning
                            break;
                        case 2:
                            if (it.isEnd()) {
                                cout << "End of array reached\n";
                            } else {
                                cout << "Not at end\n";
                            }
                            break;
                        case 3:
                            try {
                                cout << "Current value: " << it.getValue() << endl;
                            } catch (invalid_argument& e) {
                                cout << e.what() << endl;
                            }
                            break;
                        case 4:
                            if (!it.isEnd()) {
                                it.moveToNext();
                            } else {
                                cout << "Cannot move to next, end of array reached\n";
                            }
                            break;
                        case 5:
                            goto mainMenu;
                        default:
                            cout << "Invalid choice\n";
                    }
                }
                mainMenu:
                break;
            }
            case 5:
                return;
            default:
                cout << "Invalid choice\n";
        }
    }
}

template class AssociativeArray<int, int>;
template class AssociativeArray<int, double>;
template class AssociativeArray<int, char>;
template class AssociativeArray<int, string>;

template class AssociativeArray<double, int>;
template class AssociativeArray<double, double>;
template class AssociativeArray<double, char>;
template class AssociativeArray<double, string>;

template class AssociativeArray<char, int>;
template class AssociativeArray<char, double>;
template class AssociativeArray<char, char>;
template class AssociativeArray<char, string>;

template class AssociativeArray<string, int>;
template class AssociativeArray<string, double>;
template class AssociativeArray<string, char>;
template class AssociativeArray<string, string>;

