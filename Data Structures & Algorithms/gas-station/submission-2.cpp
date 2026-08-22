class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int j=0;
        int n = gas.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=gas[i];
            sum-=cost[i];
        } 
        if(sum<0) return -1;
        sum=0;
        for(int i=0;i<n;i++){
            sum=sum-cost[i]+gas[i];
            if(sum<0){
                sum=0;
                j=i+1;
            }
        } 
        
        return j%(n);
    }
};