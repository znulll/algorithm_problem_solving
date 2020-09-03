class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int rain = 0;
        int size = height.size();
        vector<int> leftmax(size), rightmax(size);
        
        leftmax[0] = height[0];
        for(int i=1; i<size; i++){
            leftmax[i] = max(height[i], leftmax[i-1]);
        }
        
        rightmax[size-1] = height[size-1];
        for(int i=size-2; i>=0; i--){
            rightmax[i] = max(height[i], rightmax[i+1]);
        }
        
        for(int i=1; i<size-1; i++){
            rain += min(leftmax[i], rightmax[i]) - height[i];
        }
        
        return rain;
    }
};