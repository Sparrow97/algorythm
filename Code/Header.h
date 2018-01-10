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

bool CheckParam(char *f1, char*f2, char*f3)
{
    ifstream F1(f1);
    ifstream F2(f2);
    ifstream F3(f3);
    if ((!F1.is_open()) || (!F2.is_open()) || (!F3.is_open()))
    {
        cout << "\n Check Args! \n";
        return false;
    }
    F1.close();
    F2.close();
    F3.close();
    return true;
}

bool checkvector(const string & buff)
{
    for (auto &x : buff)
    {
        if (x != '0' && x != '1')
            return true;
    }
    return false;

};
class TEXT
{
private:
    string buff;
    vector <string> s;
    vector<char> anf;
    char* F1;
    char* F2;
    char* F3;
    bool OK;

    void read(char* F1)
    {
        ifstream fin(F1);
        fin >> buff;

            for(int i = 0; i < buff.size(); i++)
            {
                s.push_back( nib(i, log2(buff.size())) );
            }
        if( floor(log2(s.size())) == log2(s.size()))
        {
            if(checkvector(buff))
            OK = true;
            else
            {
                OK = false;
                cout << "Unknown symbol" << endl;
            }
                OK = false;
        }
            else
            {
                cout << "Check function" << endl;
                OK = false;
            }
            fin.close();
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


    bool nul()
    {
        if (buff[0] == '0')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool ed()
    {
        if (buff[buff.size() -1] == '1')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool smd()
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
            return true;
        }
        else if (buff != _buff)
        {
            return false;
        }
    }

    bool mono()
    {
        for(int i = 0; i < buff.size() - 1; i++)
        {
            for(int j = i + 1; j < buff.size(); j++)
            {
                if(nabor(s[i], s[j]))
                {
                    if(buff[i]== '1'&&buff[j] == '0')
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool lin()
    {
        foo2(buff);
        for(int i = 0; i < buff.size(); i++)
        {
            if(!nabored(s[i]))
            {
                if(anf[i]=='1')
                {

                    return false;
                }
            }
        }
        return true;
    }

public:

    TEXT(char* _F1, char* _F2, char* _F3)
    {
        F1 = _F1;
        F2 = _F2;
        F3 = _F3;
        if (CheckParam(F1, F2, F3))
        {
            read(F1);
            OK = true;
        }
    }

    bool ready()
    {
        return OK;
    }

    void write()
    {
        ofstream fw(F2);
        if(nul())
            fw << "+";
        else
            fw << "-";
        if(ed())
            fw << "+";
        else
            fw << "-";
        if(smd())
            fw << "+";
        else
            fw << "-";
        if(mono())
            fw << "+";
        else
            fw << "-";
        if(lin())
            fw << "+";
        else
            fw << "-";

        fw.close();
    }

    bool TEST()
    {
        string test_t;
        string test_d;
        ifstream din(F3);
        ifstream tut(F2);
        din >> test_t;
        tut >> test_d;
        if(test_t == test_d)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    ~TEXT()
    {

    }
};


