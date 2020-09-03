#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> find;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(map.count(target - num)) {
                find.push_back(i);
                find.push_back(map[target - num]);
                return find;
            } 
            else {
                map.insert({ num, i });
            }
        }
        return find;
    }
};