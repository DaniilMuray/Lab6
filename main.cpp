
#include "Myclass.h"


int main() {

    int type_of_key;
    int type_of_value;

    do {
        cout << "1. int\n2. double\n3. char\n4. string\n" << endl;
        cout << "Choose the type of key: ";
        cin >> type_of_key;
    } while (type_of_key != 1 && type_of_key != 2 && type_of_key != 3 && type_of_key != 4);

    do {
        cout << "Choose the type of value: ";
        cin >> type_of_value;
    } while (type_of_value != 1 && type_of_value != 2 && type_of_value != 3 && type_of_value != 4);

    switch (type_of_key) {
        case 1:
            switch (type_of_value) {
                case 1: {
                    AssociativeArray<int, int> arr;
                    arr.main_method();
                    break;
                }
                case 2: {
                    AssociativeArray<int, double> arr;
                    arr.main_method();
                    break;
                }
                case 3: {
                    AssociativeArray<int, char> arr;
                    arr.main_method();
                    break;
                }
                case 4: {
                    AssociativeArray<int, string> arr;
                    arr.main_method();
                    break;
                }
            }
            break;
        case 2:
            switch (type_of_value) {
                case 1: {
                    AssociativeArray<double, int> arr;
                    arr.main_method();
                    break;
                }
                case 2: {
                    AssociativeArray<double, double> arr;
                    arr.main_method();
                    break;
                }
                case 3: {
                    AssociativeArray<double, char> arr;
                    arr.main_method();
                    break;
                }
                case 4: {
                    AssociativeArray<double, string> arr;
                    arr.main_method();
                    break;
                }
            }
            break;
        case 3:
            switch (type_of_value) {
                case 1: {
                    AssociativeArray<char, int> arr;
                    arr.main_method();
                    break;
                }
                case 2: {
                    AssociativeArray<char, double> arr;
                    arr.main_method();
                    break;
                }
                case 3: {
                    AssociativeArray<char, char> arr;
                    arr.main_method();
                    break;
                }
                case 4: {
                    AssociativeArray<char, string> arr;
                    arr.main_method();
                    break;
                }
            }
            break;
        case 4:
            switch (type_of_value) {
                case 1: {
                    AssociativeArray<string, int> arr;
                    arr.main_method();
                    break;
                }
                case 2: {
                    AssociativeArray<string, double> arr;
                    arr.main_method();
                    break;
                }
                case 3: {
                    AssociativeArray<string, char> arr;
                    arr.main_method();
                    break;
                }
                case 4: {
                    AssociativeArray<string, string> arr;
                    arr.main_method();
                    break;
                }
            }
            break;
    }


    return 0;
}
