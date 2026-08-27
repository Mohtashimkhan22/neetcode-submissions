class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int total = n + m;
        int mid1 = (total - 1) / 2;
        int mid2 = total / 2;

        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for (int count = 0; count <= mid2; count++) {
            prev = curr;

            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            }
            else {
                curr = nums2[j++];
            }
        }

        if (total % 2 == 0)
            return (prev + curr) / 2.0;

        return curr;
    }
};