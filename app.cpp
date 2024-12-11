#include <ctime>
#include <iostream>
#include <unistd.h>

using namespace std;

static const int sizeArray = 100;

string random_array(const int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int main(int argc, char *argv[])
{
    char number(126);

    srand((unsigned)time(NULL) * getpid());
    cout << "Вывод исходного масива" << endl;
    cout << random_array(sizeArray) << "\n";
    cout << "Char ="<< number << endl;
    return 0;
}