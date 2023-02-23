class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        else if(digits.size()==1)
        {
            if(digits=="2")
            {
                ans.push_back("a");
                ans.push_back("b");
                ans.push_back("c");
            }
            else if(digits=="3")
            {
                ans.push_back("d");
                ans.push_back("e");
                ans.push_back("f");
            }
            else if(digits=="4")
            {
                ans.push_back("g");
                ans.push_back("h");
                ans.push_back("i");
            }
            else if(digits=="5")
            {
                ans.push_back("j");
                ans.push_back("k");
                ans.push_back("l");
            }
            else if(digits=="6")
            {
                ans.push_back("m");
                ans.push_back("n");
                ans.push_back("o");
            }
            else if(digits=="7")
            {
                ans.push_back("p");
                ans.push_back("q");
                ans.push_back("r");
                ans.push_back("s");
            }
            else if(digits=="8")
            {
                ans.push_back("t");
                ans.push_back("u");
                ans.push_back("v");
            }
            else if(digits=="9")
            {
                ans.push_back("w");
                ans.push_back("x");
                ans.push_back("y");
                ans.push_back("z");
            }
        }
        else
        {
            vector<string> p1 = letterCombinations(digits.substr(0,1));
            vector<string> p2 = letterCombinations(digits.substr(1,digits.size()-1));
            for(int i=0; i<p1.size(); i++)
            {
                for(int j=0; j<p2.size(); j++)
                {
                    ans.push_back(p1[i]+p2[j]);
                }
            }
        }
        return ans;
    }
};