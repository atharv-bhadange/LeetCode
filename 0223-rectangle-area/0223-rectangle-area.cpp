class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int right=max(A,E);
        int left = max(min(C,G), right);
        int top = max(B,F);
        int bottom = max(min(D,H), top);
        return (A-C)*(B-D) + (E-G)*(F-H) - (right-left)*(top-bottom);
    }
};