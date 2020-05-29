#include <cmath>
#include <cstdio>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    long long i,j,len1,L,len2=0,x,r,c;
    char a[1000],b[1000];
    gets(a);
    len1=strlen(a);
    for(i=0,j=0;i<len1;++i,++j)
    {
        if(a[i]==' ')
        {
            --j;
            continue;
        }
        else
        {
            b[j]=a[i];
        }
    }
    L=j;
    x=sqrt(L);
    c=ceil(x);
    r=floor(x);
    if(L>(c*r))
    {
        ++r;
        ++c;
    }

    for(j=0;j<c;++j){
    for(i=0;i<L;++i)
    {
        if(i%c==j)
            cout<<b[i];
    }
    cout<<" ";
    }
}

