#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b, int g){
    return a*b/g;
}

int main(){
    int test_case, a, b, g, l;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        cin >> a >> b;
        g = gcd(a, b);
        l = lcm(a, b, g);
        cout << l << endl;
    }
    
    return 0;
}