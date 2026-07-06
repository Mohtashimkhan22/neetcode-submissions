class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count = 0;
        unordered_map<char,int> mp;
        for(char it : tasks){
            mp[it]++;
        }
        priority_queue<int> pq;
        for(auto& [ch,cn] : mp){
            pq.push(cn);
        }
        int total = 0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int> temp;
            while(cycle>0 && !pq.empty()){
                int num = pq.top();
                pq.pop();
                num--;
                if(num>0) temp.push_back(num);
                total++;
                cycle--;
            }
            if(!temp.empty()) total+=cycle;
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
                cout<<temp[i]<<" ";
            } 
        }
        return total;
    }
};
