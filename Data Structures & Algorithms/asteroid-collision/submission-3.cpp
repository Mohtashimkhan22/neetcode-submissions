class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int i=0;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            bool flag = true;
            while(!st.empty() && st.back()>0 && asteroids[i]<0){
                if(abs(asteroids[i])==st.back()){
                    flag = false;
                    st.pop_back();
                    break;
                }
                else if(abs(asteroids[i])<st.back()){
                    flag = false;
                    break;
                }
                else if(abs(asteroids[i])>st.back()){
                    st.pop_back();
                }
            }
            if(flag) st.push_back(asteroids[i]);
        }
        return st;
    }
};
// [8,-8]