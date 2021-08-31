#define ll long long
class Solution {
public:
    double findMedian(vector<int>& nums1, vector<int>& nums2){
        int left = 0 , right = nums2.size()-1;
        int half = (int)( nums1.size() + nums2.size() )/ 2;
        while  (true){
            int mid1 = left + (right - left) /2;
            int mid2 = half - mid1;
            int firstLeft = mid1 >= 0 ? nums1[mid1] : INT_MIN;
            int firstRight = mid1 < nums2.size() ? nums1[mid1+1] : INT_MAX;
            int secondLeft = mid2 >= 0 ? nums2[mid2] : INT_MIN;
            int secondRight = mid2 < nums2.size() ? nums1[mid2+1] : INT_MAX;
            
            
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedian(nums1 , nums2);
        return findMedian(nums2 , nums1);
    }
};