class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, maxi = 0;
        int j = heights.size()-1;
        while(i<j){
            int diff = j - i;
            maxi = max(maxi, diff*min(heights[i],heights[j]));
            if(heights[i]>heights[j]) j--;
            else i++;
        }
        return maxi;
    }
};
