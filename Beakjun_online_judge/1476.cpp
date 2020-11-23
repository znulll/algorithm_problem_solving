#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int E, S, M;
    cin >> E;
    cin >> S;
    cin >> M;
    int e=0, s=0, m=0;
    int mod_e = 16, mod_s = 29, mod_m = 20;
    int year = 0;

    while(1){
        if(e == E && s == S && m == M) break;
        e += 1;
        s += 1;
        m += 1;
        if(e == mod_e) e = 1;
        if(s == mod_s) s = 1;
        if(m == mod_m) m = 1;
        year += 1;
    }
    
    cout << year;

    return 0;
}