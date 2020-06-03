#include <iostream>
#include<string>

using namespace std;

int main()
{
    long long n, i, count = 0, len, j = 0, x, y;
    
    string str;
    cin >> str;
    len = str.size();
    cin >> n;
    x = n / len;
    y = n % len;
    
    if(len == 1 && str[0] == 'a')
    {
        cout << n;
    }
    else
    {
        for(i = 0; i < len; ++i)
        {
            if(str[i] == 'a')
                ++count;
        }
        count = count * x;
        
        for(i = 0; i < y; ++i)
        {
            if(str[i] == 'a')
                ++count;
        }
        cout << count;
    }
}
