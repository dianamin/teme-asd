/*
http://www.infoarena.ro/problema/editor
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("editor.in");
ofstream g ("editor.out");

char s[60001], st[60001];
int n, numar;

void citeste ()
{
    n=0;
    char x;
    f>>x;
    while (x!='E')
    {
        if (x=='*') {if (n>0) n--;}
        else {n++; s[n]=x;}
        f>>x;
    }
    //cout<<n;
}


int ok ()
{
    citeste ();
    if (n==0) return 1;
    if (n%2==1) return 0;
    int k=0, l=n/2;
    for (int i=1; i<=n; i++)
    {
       // cout<<s[i];
        if (s[i]=='(')
        {
            k++; st[k]='(';
        }
        else if (s[i]=='[')
        {
            k++; st[k]='[';
        }
        else if (s[i]==')')
        {
            if (st[k]=='(') k--;
            else return 0;
        }
        else
        {
            if (st[k]=='[') k--;
            else return 0;
        }
    }
    if (k==0) return 1;
    return 0;
}

int main ()
{
    int t;
    f>>t;
    for (int i=1; i<=t; i++)
    {
        if (ok()) g<<":)";
        else g<<":(";
        g<<'\n';
    }
    return 0;
}
