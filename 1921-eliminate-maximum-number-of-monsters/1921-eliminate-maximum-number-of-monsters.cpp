class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> time;
        int n = dist.size();
        for(int i=0; i<n; i++) {
            float t = float(dist[i])/speed[i];
            time.push_back(t);
        }
        sort(time.begin(), time.end());
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            if(time[i] <= i)
                break;
            
            ans++;
        }
        
        return ans;
    }
};