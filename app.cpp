#include <iostream>
#include <limits>
using namespace std;

int main()
{

    int n, a;

    while (!(cin >> n))
    {

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Некоректный ввод даных! Введите их ещё раз: ";
    }
    a = n;
    
    cout << a << endl;
}