#include<stdio.h>
#include <stdlib.h>
#include<string>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        int a_length = a.length();
        int b_length = b.length();
        int length;
        if (a_length >= b_length)
        {
            length = a_length;
            for (int i = 0; i < a_length - b_length; i++)
            {
                b = "0" + b;
            }
        }
        if (a_length < b_length)
        {
            length = b_length;
            for (int i = 0; i < b_length - a_length; i++)
            {
                a = "0" + a;
            }
        }
        printf("a: %s\n", a.c_str());
        printf("b: %s\n", b.c_str());
        char carrier = '0';
        for (int i = length - 1; i >= 0; i--)
        {
            // case 1
            if (a[i] == '0' && b[i] == '0' && carrier == '0')
            {
                a[i] = '0';
                carrier = '0';
            }
            // case 2
            else if (a[i] == '0' && b[i] == '0' && carrier == '1')
            {
                a[i] = '1';
                carrier = '0';
            }
            // case 3
            else if (a[i] == '0' && b[i] == '1' && carrier == '0')
            {
                a[i] = '1';
                carrier = '0';
            }
            // case 4
            else if (a[i] == '0' && b[i] == '1' && carrier == '1')
            {
                a[i] = '0';
                carrier = '1';
            }
            // case 5
            else if (a[i] == '1' && b[i] == '0' && carrier == '0')
            {
                a[i] = '1';
                carrier = '0';
            }
            // case 6
            else if (a[i] == '1' && b[i] == '0' && carrier == '1')
            {
                a[i] = '0';
                carrier = '1';
            }
            // case 7
            else if (a[i] == '1' && b[i] == '1' && carrier == '0')
            {
                a[i] = '0';
                carrier = '1';
            }
            // case 8
            else if (a[i] == '1' && b[i] == '1' && carrier == '1')
            {
                a[i] = '1';
                carrier = '1';
            }
        }
        if (carrier == '0')
        {
            return a;
        }
        if (carrier == '1')
        {
            return "1" + a;
        }
    }
};

int main()
{
    Solution obj;
    std::string a = "11";
    std::string b = "1000";
    std::string out;
    out = obj.addBinary(a, b);
    printf("out: %s\n", out.c_str());
    return 0;
}