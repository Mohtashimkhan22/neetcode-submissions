class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(auto it : s){
            freq[it-'a']++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<26;i++){
            if(freq[i])pq.push({freq[i],i});
        }
        string res = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            res+=(it.second+'a');
            if(pq.empty()) break;
            auto itr = pq.top();
            pq.pop();
            res+=(itr.second+'a');
            itr.first--;
            it.first--;
            if(it.first){
                pq.push(it);
            }
            if(itr.first){
                pq.push(itr);
            }
        }
        if(res.size()!=s.size()) return "";
        return res;
    }
};