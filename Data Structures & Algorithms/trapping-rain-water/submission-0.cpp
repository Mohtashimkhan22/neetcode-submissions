class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftGreater(n), rightGreater(n);
        leftGreater[0]=height[0];
        for(int i=1;i<n;i++){
            leftGreater[i]=max(leftGreater[i-1],height[i]);
        }
        rightGreater[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightGreater[i]=max(rightGreater[i+1],height[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(leftGreater[i],rightGreater[i])-height[i];
        }
        return ans;
    }
};
