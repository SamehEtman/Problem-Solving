class Solution {
public:
    bool isSmallerGood(vector<int>& nums, int k  , int mid){
        int count = 0 , left = 0;
        for (int right = 0 ;right < nums.size() ;right++){
            while (left < nums.size() && nums[right] - nums[left] > mid) left ++;
            count += right - left;
        }
        return  count >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort (nums.begin() , nums.end());
        int low = 0 , high = 1000000;
        while (low < high){
            int mid = (high + low) / 2;
            if (isSmallerGood(nums , k, mid)){
                 high = mid;
            }else {
                low = mid + 1;

            }
        }
        return low;
    }
};