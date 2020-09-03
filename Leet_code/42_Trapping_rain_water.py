class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0
        
        rain = 0
        size = len(height)
        left = 0
        right = size -1
        leftmax, rightmax = height[left], height[right]
        
        while left < right:
            leftmax, rightmax = max(height[left], leftmax), max(height[right], rightmax)
            
            if leftmax <= rightmax:
                rain += leftmax - height[left]
                left += 1
            else:
                rain += rightmax - height[right]
                right -= 1
        
        return rain
            