class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first!=b.first){
            return a.first < b.first;
        }
        else return a.second > b.second;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i=0; i<position.size(); i++){
            arr.push_back({position[i], speed[i]});
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<float> times(position.size(), 0);
        for(int i=0; i<position.size(); i++){
            times[i] = (float)(target-arr[i].first)/arr[i].second;
        }
        float temp_t = times[times.size()-1];
        int cnt = 1;
        for(int i = position.size()-1; i>=0; i--){
            if(times[i]<=temp_t){}
            if(times[i]>temp_t){
                cnt++;
                temp_t = times[i];
            }
        }
        return cnt;
    }
};