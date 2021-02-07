#include <iostream>
#include <iomanip>
#include<cstdio>
using namespace std;
int main()
{
    double va_coe = 0, sum = 0;
    char read = 0, va=0;
    int num[100] = { 0 }, len = 0, judge = 1, opp=0;
    while (read != '=')
    {
        read = getchar();
        if (read == '-')
        {
            len++;
            judge = -1;
        }
        if (read == '+')
        {
            len++;
            judge = 1;
        }
        if (read >= '0' && read <= '9')
        {
            if (!num[len])
                num[len] = judge * (read - '0');
            else
                num[len] = num[len] * 10 + judge * (read - '0');
        }
        if (read >= 'a' && read <= 'z')
        {
            va = read;
            if (num[len] == 0)
                va_coe += judge;
            else
                va_coe += num[len];
            num[len] = 0;
            len--;
        }
    }
    opp = len;
    len++;
    judge = 1;
    while (read != '\n')
    {
        read = getchar();
        if (read == '-')
        {
            len++;
            judge = -1;
        }
        if (read == '+')
        {
            len++;
            judge = 1;
        }
        if (read >= '0' && read <= '9')
        {
            if (!num[len])
                num[len] = judge * (read - '0');
            else
            {
                num[len] = num[len] * 10 + judge * (read - '0');
            }
        }
        if (read >= 'a' && read <= 'z')
        {
            va = read;
            if (num[len] == 0)
                va_coe -= judge;
            else
                va_coe -= num[len];
            num[len] = 0;
            len--;
        }
    }
    for (int i = 0; i <= len; i++)
        sum = (i <= opp) ? sum - num[i] : sum + num[i];
    if (!(sum / va_coe))
        cout << va << '=' << "0.000";
    else
    {
        cout << va << '=' << fixed << setprecision(3) << sum / va_coe;
    }
    system("pause");
    return 0;
}