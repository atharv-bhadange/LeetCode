class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = *max_element(arr.begin(), arr.end());
        
        int curr = arr[0];
        int win = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            int opponent = arr[i];
            
            if (curr > opponent) {
                win++;
            } else {
                curr = opponent;
                win = 1;
            }
            
            if (win == k || curr == maxElement) {
                return curr;
            }
        }
        
        return -1;
    }
};