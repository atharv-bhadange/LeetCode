class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        if(st.empty())
            return intervals;
        int left = -1, right = -1;
        for(auto& val : st) {
            if(left<0)
                left = right = val;
            else if(val == right + 1)
                right = val;
            else {
                intervals.push_back({left, right});
                left = right = val;
            } 
        }
        
        intervals.push_back({left, right});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */