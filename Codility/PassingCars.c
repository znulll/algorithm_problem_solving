// https://app.codility.com/demo/results/trainingRW4J74-ANS/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i,j;
    int pairs = 0;
    int num_west=0, num_east=0;
    int* west;
    int* east;
    west = (int*) malloc(sizeof(int)*N);
    east = (int*) malloc(sizeof(int)*N);
    
    for(i=0; i<N; i++){
        if(A[i] == 0) {
            west[num_west++] = i;
            // num_west++;
        }
        if(A[i] == 1) {
            east[num_east++] = i;
            // num_east++;
        }
    }
    
    for(i=0; i<num_east; i++){
        for(j=0; j<num_west; j++){
            if(i<j) continue;
            else pairs++;
        }
    }
    return pairs;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> east;
    vector<int> west;
    
    for(int i=0; i<A.size(); i++){
        if(A[i] == 0) east.push_back(i);
        else if(A[i] == 1) west.push_back(i);
    }
    int ans = east.size() * west.size();
    
    for(int i=0; i<east.size(); i++){
        for(int j=0; j<west.size(); j++){
            if(east[i] > west[j]) ans -= 1;
        }
    }
    
    if (ans > 1000000000) ans = -1;
    
    return ans;
}

