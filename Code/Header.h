#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

string moddva(const char&kek, const char&cec)
{
    if((kek == '0'&&cec == '0')||(kek == '1'&&cec == '1'))
    {
        return "0";
    }
    return "1";
}

bool nabor(const string&a, const string&b) // функция сравнимых наборов
{
    bool nullone = true;
    bool onenull = true;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '1'&&b[i] == '0')
        {
            onenull = false;
        }
        if(a[i] == '0'&&b[i] == '1')
        {
            nullone = false;
        }
        if(!onenull&&!nullone)
        {
            return false;
        }
    }
    return true;
}

string nib(int x, int len)
{
    string result;
    while (x > 0)
    {
        int buf = x & 1;
        x = x >> 1;
        result.append(to_string(buf));
    }
    reverse(result.begin(), result.end());
    if (result.length() < len)
    {
        int delta = len - result.length();
       string zeros;
        for (int i = 0; i < delta; ++i)
            zeros.append("0");
        result = zeros + result;
    }
    return result;
}

bool nabored(const string&a) //считает количество единиц в наборе
{
    int k = 0;
    for(int i =0; i<a.size();i++)
    {
        if (a[i] == '1')
        {
            k++;
        }
        if(k > 1)
        {
            return false;
        }
    }
    return true;
}


class TEXT
{
public:
    string buff;
    vector <string> s;
    vector<char> anf;

    void read()
    {
            ifstream fin("C:\\Users\\Ivan\\CLionProjects\\sparrow\\kek.txt");
            if (!fin.is_open())
            {
                cout << "Cannot find the file\n";
            }
            fin >> buff;
            cout << buff << endl;
            for(int i = 0; i < buff.size(); i++)
            {
                s.push_back( nib(i, log2(buff.size())) );

            }
        for(auto&x:s)
            cout << x << endl;
    }

    void foo2(string a) // задаем анф
    {
        anf.push_back((a[0]));
        if(a.size() == 1)
        {
            return;
        }
        string b;
        for(int i = 0;i < a.size()-1; i++)
        {
            b.append(moddva(a[i], a[i+1]));
        }
        foo2(b);
    }

    void nul()
    {
        if (buff[0] == '0')
        {
            cout << "T0 +" << endl;
        }
        else
        {
                cout << "T0 -" << endl;
        }
    }

    void ed()
    {
        if (buff[buff.size() -1] == '1')
        {
            cout << "T1 +" << endl;
        }
        else
        {
            cout << "T1 -" << endl;
        }
    }

    void smd()
    {
        string _buff = buff;
        reverse(_buff.begin(), _buff.end());
        for (int i = 0; i< _buff.size(); i++)
        {
            if(_buff[i] == '0')
            {
                _buff[i] = '1';
            }
            else if (_buff[i] == '1')
            {
                _buff[i] = '0';
            }
        }
        if(buff == _buff)
        {
            cout << "SM +" << endl;
        }
        else if (buff != _buff)
        {
            cout << "SM -" << endl;
        }
    }

    void mono()
    {
     for(int i = 0; i < buff.size() - 1; i++)
     {
         for(int j = i + 1; j < buff.size(); j++)
         {
             if(nabor(s[i], s[j]))
             {
                 if(buff[i]== '1'&&buff[j] == '0')
                 {
                     cout << "M -"<<endl;
                     return;
                 }
             }
         }
     }
        cout << "M +" << endl;
    }

    void lin()
    {
        foo2(buff);
        for(int i = 0; i < buff.size(); i++)
        {
            if(!nabored(s[i]))
            {
                if(anf[i]=='1')
                {
                    cout << "L -"<< endl;
                    return;
                }
            }
        }
        cout << "L +" << endl;
    }
};


