#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>

using namespace std;

// Функция для печати массива
void printArray(const vector<char>& arr, const string& msg) {
    cout << msg;
    for (char c : arr) {
        cout << c << " ";
    }
    cout << endl;
}

// Функция сортировки пузырьком с учетом частоты символов (по возрастанию)
void bubbleSortByCount(vector<char>& arr, const map<char, int>& counts) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (counts.at(arr[j]) > counts.at(arr[j+1])) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    const int SIZE = 100;
    vector<char> arr(SIZE);

    int choice;
    cout << "Выберите способ заполнения массива:\n";
    cout << "1. Ввод с клавиатуры\n";
    cout << "2. Случайные буквы и цифры\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Введите " << SIZE << " символов (буквы латинского алфавита и цифры):\n";
             for(int i = 0; i < SIZE; ++i)
             {
                 char input_char;
                  cin >> input_char;
                  if (!isalnum(input_char))
                  {
                      cout << "Некорректный символ. Введите латинскую букву или цифру." << endl;
                      i--;
                      continue;
                  }
                  arr[i] = input_char;

             }
            break;
        }
        case 2: {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(0, 61); // 26 букв + 26 букв в верхнем регистре + 10 цифр

            for (int i = 0; i < SIZE; ++i) {
                int random_int = distrib(gen);
                 if (random_int < 10)
                     arr[i] = '0' + random_int;
                else if(random_int < 36)
                    arr[i] = 'a' + random_int - 10;
                else
                    arr[i] = 'A' + random_int - 36;
            }
            break;
        }
        default:
            cerr << "Ошибка: Неверный выбор.\n";
            return 1;
    }

    printArray(arr, "Исходный массив: ");

    // Подсчет частоты символов
    map<char, int> charCounts;
    for (char c : arr) {
        charCounts[c]++;
    }

    // Копируем исходный массив для сортировки
    vector<char> sortedArr = arr;

    // Сортировка массива на основе подсчета частот пузырьком
    bubbleSortByCount(sortedArr, charCounts);

    printArray(sortedArr, "Отсортированный массив: ");

    return 0;
}
//g++ app.cpp -o array_sort скомпелировать файл 