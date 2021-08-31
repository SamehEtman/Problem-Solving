class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        for (int i = 0 ; i< n ;i++){
            if (visited[nums[i]])
                return nums[i];
        }
        return -1;
    }
};