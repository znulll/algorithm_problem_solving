// https://app.codility.com/demo/results/training5WYEF4-D26/

int solution(int K, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ropes = 0;
    int temp_len = 0;
    
    for(int i=0; i<(int)A.size(); i++){
        temp_len += A[i];
        if(temp_len >= K){
            ropes += 1;
            temp_len = 0;
        }
        // printf("%d", temp_len);
    }
    
    return ropes;
}
