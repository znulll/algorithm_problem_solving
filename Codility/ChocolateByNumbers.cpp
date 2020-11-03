// https://app.codility.com/demo/results/training2JJBA7-WDM/

int solution(int N, int M) { 
    int nRet = 0; 
    
    if( N > 0 && M > 0 ) { 
        int nTarget = N; 
        
        while( N % M != 0 ) {
            N %= M; 
            swap(N, M); 
        } 
        
        nRet = nTarget / M; 
    } 
    
    return nRet; 
    
}