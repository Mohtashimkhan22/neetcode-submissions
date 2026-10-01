class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l=0,h=n-1;
        int pivot = -1;
        while(l<=h){
            int mid = (l+h)/2;
            int currele = mountainArr.get(mid);
            int prevele=INT_MAX,nextele=INT_MAX;
            if(mid>0) prevele = mountainArr.get(mid-1);
            if(mid<n-1) nextele = mountainArr.get(mid+1);
            if(mid>0 && currele>prevele && mid<n-1 && currele>nextele){
                pivot=mid;
                break;
            }
            else if(mid>0 && currele>prevele){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        cout<<pivot;
        l=0,h=pivot;
        while(l<=h){
            int m = (l+h)/2;
            int num = mountainArr.get(m);
            int left = mountainArr.get(l);
            int right = mountainArr.get(h);
            if(num==target){
                return m;    
            }
            else if(target<num){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        l=pivot+1;
        h=n-1; 
        while(l<=h){
            int m = (l+h)/2;
            int num = mountainArr.get(m);
            int left = mountainArr.get(l);
            int right = mountainArr.get(h);
            if(num==target){
                return m;    
            }
            else if(target<num){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
};