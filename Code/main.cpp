#include <iostream>
#include "Header.h"
using namespace std;

int main(int argc, char *argv[])
{
    TEXT a(argv[1], argv[2], argv[3]);
    if(a.ready())
    {
        a.write();
        if(a.TEST())
        {
            cout << "Algorithm is correct" << endl;
        }
        else
        {
            cout << "Incorrect algorithm" << endl;
        }
    }

    system("pause");
    return 0;
}