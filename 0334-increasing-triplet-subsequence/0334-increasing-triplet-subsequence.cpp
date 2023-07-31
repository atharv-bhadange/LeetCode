class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int ele1=INT_MAX,ele2 = INT_MAX;
        for(auto &x : nums) {
            // cout<<ele1<<' '<<ele2<<endl;
            if(x <= ele1) { // ele1 set
                ele1 = x;
            }
            else if(x <= ele2) { // if x > ele1 then it might be ele2 or ele3
                ele2 = x;
            }
            else // if x> ele1 && x>ele2 then it is ele3
                return 1;
        }
        
        return 0;
    }
};