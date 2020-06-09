#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    long long t,n,rem,i,x,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        count=0;
        x=n;
        for(i=0;n!=0;++i)
        {
            rem=n%10;
            if(rem==0)
            {
                n=n/10;
                continue;
            }
            if(x%rem==0)
                ++count;
            n=n/10;
        }
        cout<<count<<"\n";
    }
}

