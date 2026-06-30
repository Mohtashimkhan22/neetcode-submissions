class TimeMap {
    unordered_map<string,string> mp;
    unordered_map<string,vector<int>> mpt;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        string k = key+to_string(timestamp);
        mp[k]=value;
        mpt[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        string str = key + to_string(timestamp);
        if(mp.count(str))
            return mp[str];

        int t = timestamp;
        vector<int> arr=mpt[key];

        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]<=timestamp){
                t=arr[mid];
                l = mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        string st = key + to_string(t);
        return mp[st];
    }
};
