class Solution {
    int binarySearch(vector<int>& arr,int x){
        int l=0;
        int r = arr.size()-1;
        int ans = arr.size();;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]>=x){
                r=mid-1;
                ans = mid;
            }
            else l=mid+1;
        }
        return ans;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int ind = binarySearch(arr,x);
        cout<<ind<<endl;
        vector<int> res;
        int l = ind-1;
        int r = ind;
        while(k>0){
            if(r>=n){
                cout<<arr[l]<<" ";
                res.push_back(arr[l]);
                l--;
            }
            else if(l<0){
                cout<<arr[r]<<" ";
                res.push_back(arr[r]);
                r++;
            }
            else if(abs(arr[l]-x)<=abs(x-arr[r])){
                cout<<arr[l]<<" ";
                res.push_back(arr[l]);
                l--;
            }
            else{
                cout<<arr[r]<<" ";
                res.push_back(arr[r]);
                r++;
            }
            k--;
        }
        sort(res.begin(),res.end());
        return res;
    }
};