#include <iostream>
#include <cstring>
using namespace std;

char s[25];

void reversion(int i, int j) {
    for(int k=0;k<(j+1-i)/2;++k)
        swap(s[i+k],s[j-k]);
    for(;s[i]=='0'&&i<j;++i);
    for(;s[j]=='0'&&i<j;--j);
    for(;i<=j;++i)
        cout<<s[i];
}

int main() {
    cin>>s;
    int lens,i,idx;
    lens=strlen(s);
    idx=lens-1;
    if(s[idx]=='%')
    {
        reversion(0,lens-2);
        cout<<'%';
    }
    else {
        for(i=0;i<lens;++i)
            if(s[i]=='.'||s[i]=='/')
            {
                idx=i;
                break;
            }
        if(idx==lens-1)
            reversion(0,lens-1);
        else {
            reversion(0,idx-1);
            cout<<s[idx];
            reversion(idx+1,lens-1);
        }
    }
    cout<<endl;
    return 0;
}