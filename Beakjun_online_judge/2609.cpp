#include <iostream>
using namespace std;

// Greatest Common Divider
int gcd(int m, int n){
    if(n == 0) return m;
    else return gcd(n, m%n);
}

// Least Common Multiple
int lcm(int m, int n, int gcd){
    return m*n/gcd;
}

int main(){
    int input[2] = {0, };
    for(int i=0; i<2; i++) cin >> input[i];
    
    int a = input[0];
    int b = input[1];

    int g_gcd = gcd(a, b);
    int g_lcm = lcm(a, b, g_gcd);

    cout << g_gcd << endl;
    cout << g_lcm << endl;
    
    return 0;
}