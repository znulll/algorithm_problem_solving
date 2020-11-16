#include <iostream>
using namespace std;

int main(void){
    // variable init
    int input[3] = {0, };

    // input
    for(int i=0; i<3; i++){
        cin >> input[i];
    }

    int A = input[0];
    int B = input[1];
    int C = input[2];

    // line1: (A+B)%C
    cout << (A+B)%C << endl;

    // line2: ((A%C) + (B%C))%C
    cout << ((A%C) + (B%C))%C << endl;

    // line3: (A×B)%C
    cout << (A*B)%C << endl;

    // line4: ((A%C) × (B%C))%C
    cout << ((A%C) * (B%C))%C << endl;
    
    return 0;
}