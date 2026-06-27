class Solution {
    int solver(vector<int>& numbers, int target){
        int r = numbers.size()-1;
        int ans = -1;
        int l = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(numbers[mid]==target){
                ans = mid;
                break;
            }
            else if(numbers[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0;i<n;i++){
            int diff = target - numbers[i];
            int j = solver(numbers,diff);
            if(j!=-1){
                return {i+1,j+1};
            }
        }
        return {};
    }
};
