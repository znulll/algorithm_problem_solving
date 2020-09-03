bool isPalindrome(char * s){
    int bias_L = 0;
    int bias_R = 1;
    int str_len = strlen(s);
    
    for(int i=0; i<str_len; i++){
        while(!isalnum(s[i + bias_L])){
            bias_L++;
            if(i + bias_L == str_len) return true;
        }
        while(!isalnum(s[str_len - i -bias_R])){
            bias_R++;
        }
        
        if(i + bias_L >= str_len - i - bias_R) break;
        
        if(tolower(s[i+bias_L]) != tolower(s[str_len - i -bias_R])) return false;
    }
    
    return true;
}