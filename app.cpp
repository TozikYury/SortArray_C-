#include <ctime>
#include <iostream>
#include <unistd.h>

using namespace std;

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
    static const int sizeArray = 100;
    srand((unsigned)time(NULL) * getpid());

    cout << random_array(sizeArray) << "\n";
    return 0;
}