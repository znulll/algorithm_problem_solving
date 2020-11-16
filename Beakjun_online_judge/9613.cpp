#include <iostream>
#include <vector>
using namespace std;

int test_case = 0;
int each_case = 0;

bool check(int gcd, vector<int> &possible_gcd){
    for(int i=0; i<(int)possible_gcd.size(); i++){
        if(gcd == possible_gcd[i]) return false;
    }
    return true;
}

int get_gcd(int a, int b){
    if(b == 0) return a;
    else return get_gcd(b, a%b);
}

int get_all_gcd(vector<int> &v){
    int gcd = 0;
    int temp_gcd;
    vector<int> possible_gcd;
    for(int i=0; i<(int)v.size(); i++){
        for(int j=i+1; j<(int)v.size(); j++){
            temp_gcd = get_gcd(v[i], v[j]);
            if(check(temp_gcd, possible_gcd)) {
                possible_gcd.push_back(temp_gcd);
                gcd++;
            }
        }
    }
    
    return gcd;
}

int main(void){
    cin >> test_case;
    int sol;
    
    for(int i=0; i<test_case; i++){
        int temp;
        vector<int> v;
        cin >> each_case;
        for(int j=0; j<each_case; j++){
            cin >> temp;
            v.push_back(temp);
        }
        
        sol = get_all_gcd(v);
        cout << sol << endl;
    }
    
    return 0;
}