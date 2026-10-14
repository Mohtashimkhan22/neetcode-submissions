class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int,int>> pq;
        if(a>0) pq.push({a,0});
        if(b>0) pq.push({b,1});
        if(c>0) pq.push({c,2});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(pq.empty()){
                if(it.first>=2){
                    res+=(it.second+'a');
                    res+=(it.second+'a');
                }
                else res+=(it.second+'a');
                break;
            }
            auto itr = pq.top();
            pq.pop();
            if(it.first-itr.first>=2){
                res+=(it.second+'a');
                res+=(it.second+'a');
                res+=(itr.second+'a');
                it.first-=2;
                itr.first--;
            }
            else{
                res+=(it.second+'a');
                res+=(itr.second+'a');
                it.first--;
                itr.first--;
            }
            if(it.first) pq.push(it);
            if(itr.first) pq.push(itr);
        }
        return res;
    }
};