#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>
#include <chrono>
#include <map>

using namespace std;
using namespace std::chrono;

// Структура для хранения элемента и его количества (для чисел и символов)
struct ElementCount {
    char element; // Используем char, т.к. нам важен символ или его ASCII код для числа
    int count;
    bool isNumber; //флаг для проверки является ли данный элемент числом или нет
};


bool compareElementCounts(const ElementCount& a, const ElementCount& b) {
    return a.count < b.count;
}

// Функция сортировки пузырьком
void bubbleSort(vector<ElementCount>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].count > arr[j + 1].count) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция сортировки чет-нечет
void oddEvenSort(vector<ElementCount>& arr) {
    int n = arr.size();
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;

        // Четная фаза
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i].count > arr[i + 1].count) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        // Нечетная фаза
        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i].count > arr[i + 1].count) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}



int main() {
    const int arrSize = 100;
    char arr[arrSize];
    char choice, sortChoice;

    cout << "Заполнить массив: (k - клавиатура, r - случайные числа): ";
    cin >> choice;

    if (choice == 'k') {
        cout << "Введите " << arrSize << " элементов (буквы и целые числа) через пробел: ";
        for (int i = 0; i < arrSize; ++i) {
            cin >> arr[i];
              // Проверяем, является ли символ буквой или цифрой
            if (!isalnum(arr[i])) {
                cout << "Некорректный символ. Введите только буквы или целые числа" << endl;
                return 1;
              }
        }
    } else if (choice == 'r') {
        int a, b;
        cout << "Введите диапазон случайных чисел (A B): ";
        cin >> a >> b;
          if (a > b) {
            cout << "Некорректный диапазон. A должно быть меньше или равно B." << endl;
            return 1;
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(a, b);

        for (int i = 0; i < arrSize; ++i) {
              // Генерируем случайный выбор (буква или число)
            if (distrib(gen) % 2 == 0) {
                 arr[i] = (char) (distrib(gen) % 26 + 'a') ;// Случайная буква от a до z
            } else {
                 arr[i] = (char) (distrib(gen) % 10 + '0') ; // Случайная цифра от 0 до 9
            }
        }
    } else {
        cout << "Неверный выбор." << endl;
        return 1;
    }


    cout << "Исходный массив: ";
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


     vector<ElementCount> elementCounts;
     for (char el : arr) {
       bool found = false;
       for(auto& ec: elementCounts) {
         if(ec.element == el) {
           ec.count++;
           found = true;
           break;
         }
       }
       if(!found) {
         elementCounts.push_back({el, 1, isdigit(el)}); //записываем является ли это числом
       }
     }

    cout << "Выбрать алгоритм сортировки: (b - пузырьком, o - чет-нечет): ";
    cin >> sortChoice;

    auto start = high_resolution_clock::now(); // Замер времени

    if (sortChoice == 'b') {
        bubbleSort(elementCounts);
    } else if (sortChoice == 'o') {
        oddEvenSort(elementCounts);
    } else {
        cout << "Неверный выбор сортировки." << endl;
        return 1;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "Массив после обработки (отсортированные символы и целые числа): ";
    for (const auto& ec : elementCounts) {
      for(int i = 0; i < ec.count; i++) {
         if(ec.isNumber) {
           cout << (int)(ec.element - '0');
         } else {
           cout << ec.element;
         }
      }
    }
    cout << endl;


    cout << "Время работы сортировки: " << duration.count() << " микросекунд" << endl;

    return 0;
}