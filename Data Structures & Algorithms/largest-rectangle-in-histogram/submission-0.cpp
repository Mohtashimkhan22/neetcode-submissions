class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int mini = heights[i];
            for(int j=i;j<n;j++){
                mini=min(mini,heights[j]);
                int rect = mini * (j-i+1);
                maxi=max(maxi,rect);
            }
        }
        return maxi;
    }
};
