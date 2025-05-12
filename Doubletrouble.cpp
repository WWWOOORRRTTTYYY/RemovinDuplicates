#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int arrayUnique(int array[], int size) {
    vector<int> uniqueElements;

    for (int i = 0; i < size; ++i) {
        if (find(uniqueElements.begin(), uniqueElements.end(), array[i]) == uniqueElements.end()) {
            uniqueElements.push_back(array[i]);
        }
    }

    for (int i = 0; i < uniqueElements.size(); ++i) {
        array[i] = uniqueElements[i];
    }

    return uniqueElements.size();
}

int main() {
    const int SIZE = 20;
    int array[SIZE];

    srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < SIZE; ++i) {
        array[i] = std::rand() % 10 + 1; 
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    int newSize = arrayUnique(array, SIZE);

    cout << "Массив без дубликатов: ";
    for (int i = 0; i < newSize; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Новая длина массива: " << newSize << endl;

    return 0;
}