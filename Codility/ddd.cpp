int solution(int M, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int) A.size();
    int res = 0;
    vector<int> check(M, 0);
    
    if(size < 1) return 1;
    
    for(int P=0; P<size; P++){
        fill(check.begin(), check.end(), 0);
        int m_count = 0;
        for(int Q=P; Q<size; Q++){
            if(m_count >= M) break;
            int new_idx = A[Q];
            if(check[new_idx] == 1) break;
            else {
                res++;
                if(res > 1000000000) return 1000000000;
                check[new_idx] = 1;
                Q++;
            }
            m_count++;
        }
        
    }
    
    return res;
}