#include<iostream>
#include <math.h>



const int SIZE = 100;

void fillArray(char* arr, char choice) {
if (choice == '1') {
std::cout << "Enter " << SIZE << " characters (only letters and digits): ";
for (int i = 0; i < SIZE; ++i) {
std::cin >> arr[i];
}
} else if (choice == '2') {
char A, B;
std::cout << "Enter range A and B: ";
std::cin >> A >> B;
for (int i = 0; i < SIZE; ++i) {
arr[i] = rand() % (B - A + 1) + A;
}
}
}

void bubbleSort(char* arr, int size) {
for (int i = 0; i < size - 1; ++i) {
for (int j = 0; j < size - i - 1; ++j) {
if (arr[j] > arr[j + 1]) {
char temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}

void countCharacters(char* arr) {
int count[62] = {0}; // 26 letters + 10 digits = 36; 26 capital letters + 10 digits = 62
for (int i = 0; i < SIZE; ++i) {
if (arr[i] >= '0' && arr[i] <= '9') {
count[arr[i] - '0']++;
} else if (arr[i] >= 'A' && arr[i] <= 'Z') {
count[arr[i] - 'A' + 10]++;
} else if (arr[i] >= 'a' && arr[i] <= 'z') {
count[arr[i] - 'a' + 36]++;
}
}
}