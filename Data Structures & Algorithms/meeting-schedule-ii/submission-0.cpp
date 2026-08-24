/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){
            // if(a.end==b.end) return a.start<b.start;
            // return a.end<b.end;
            return a.start<b.start;
        });
        for(auto it : intervals) cout<<it.start<<" "<<it.end<<endl;
        vector<int> rooms;
        int n = intervals.size();
        for(int i=0;i<n;i++){
            if(rooms.empty()){
                rooms.push_back(intervals[i].end);
            }
            else{
                bool flag = true;
                for(int j=0;j<rooms.size();j++){
                    if(rooms[j]<=intervals[i].start){
                        rooms[j]=intervals[i].end;
                        flag=false;
                        break;
                    }
                }
                if(flag) rooms.push_back(intervals[i].end);
            }
        }
        return rooms.size();
    }
};
