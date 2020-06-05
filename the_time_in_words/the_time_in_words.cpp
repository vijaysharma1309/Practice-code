#include <cmath>
#include <cstdio>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    long long h,m,i,x;
    string a[250]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"};
    cin>>h>>m;
    if(m==0)
    {
        cout<<a[h-1]<<" o' clock";
    }
    else if(m==15)
    {
        cout<<"quarter past "<<a[h-1];
    }
    else if(m==45 )
    {
        cout<<"quarter to "<<a[h];
    }
    else if(m==30)
    {
        cout<<"half past "<<a[h-1];
    }
    else if(m>0 && m<30 && m!=15)
    {
        cout<<a[m-1]<<" minutes past "<<a[h-1];
    }
    else if(m>30 && m<60 && m!=45)
    {
        x=60-m;
        cout<<a[x-1]<<" minutes to "<<a[h];
    }

}

