#include <iostream>

using namespace std;

int summ(a,b);

int main(int argc, char const *argv[])
{
    int numberOne, numberTwo;
    int summ;
    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << "Enter number One" << endl;
    cin >> numberOne;
    cout << "Enter number Two" << endl;
    cin >> numberTwo;
    if (typeid(numberOne) == typeid(int) && typeid(numberTwo) == typeid(int))
    {
        summ = numberOne + numberTwo;
    }
    else
       //throw std::string{"-----------"};
       return 0;

    cout << "Summ numbers:=" << summ << endl;

    return 0;  
}

