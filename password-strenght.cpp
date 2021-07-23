#include <iostream>
#include <string>
using namespace std;

bool ifdigit(string str, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (str[i] > 47 && str[i] < 58)
            return true;
    }
    return false;
}

bool ifuppercase(string str, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (str[i] > 64 && str[i] < 91)
            return true;
    }
    return false;
}

bool iflowercase(string str, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (str[i] > 96 && str[i] < 121)
            return true;
    }
    return false;
}

bool ifspecial(string str, int l)
{
    for (int i = 0; i < l; i++)
    {
        if ((str[i] > 32 && str[i] < 48) || (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] < 127))
            return true;
    }
    return false;
}

int main()
{
    string password;
    int summation = 0;
    cout << "Enter the password to check it's strength" << endl;
    cin >> password;

    summation += ifdigit(password, password.size());
    summation += ifuppercase(password, password.size());
    summation += iflowercase(password, password.size());
    summation += bool(password.size() > 9);
    summation += ifspecial(password, password.size());
    summation = (summation * 100) / 5;
    cout << password << " satisfies " << summation << " % of neccessary criteria of a strong password" << endl;
    if (summation > 66)
        cout << "Password Stremgth : Strong" << endl;
    else if (summation < 67 && summation > 33)
        cout << "Password Stremgth : Moderate" << endl;
    else
        cout << "Password Stremgth : Weak" << endl;
}