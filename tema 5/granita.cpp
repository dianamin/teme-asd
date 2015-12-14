/*
http://www.infoarena.ro/problema/granita
*/

#include <iostream>
#include <fstream>
//#include <cstdio>
#include <algorithm>

using namespace std;

ifstream f ("granita.in");
ofstream g ("granita.out");

int n;
struct interval {int x, y;} v[16001];

void citeste (){
    //freopen ("granita.in", "r", stdin);
    f>>n;
   // scanf ("%d", &n);
    for (int i=1; i<=n; i++) f>>v[i].x>>v[i].y;
    /*{
            scanf ("%d", &v[i].x);
            scanf ("%d", &v[i].y);
    }*/

}

int conditie (interval a, interval b){
    if (a.y>b.y) return 1;
    return 0;
}

void rezolva (){
    int a, b, nr=0;
    a=v[1].x; b=v[1].y;
    for (int i=2; i<=n; i++){
        if (v[i].x>a && v[i].y<b) nr++;
        else {
            a=v[i].x;
            b=v[i].y;
        }
    }
   // freopen ("granita.out", "w", stdout);
    g<<nr<<'\n';
   // printf ("%d\n", nr);
}

int main ()
{
    citeste ();
    sort (v+1, v+n+1, conditie);
    rezolva ();
    return 0;
}
