class Solution {

int get_min(int a, int b){
    if(a>b) return b;
    else return a;
}
    

int get_max(int a, int b){
    if(a<b) return b;
    else return a;
}

public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            min_price = get_min(min_price, prices[i]);
            max_profit = get_max(max_profit, prices[i] - min_price);
        }
        
        return max_profit;
    }
};