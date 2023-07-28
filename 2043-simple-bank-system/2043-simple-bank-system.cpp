class Bank {
public:
    vector<long long> bal;
    int n;
    Bank(vector<long long>& balance) {
        this->bal = balance;
        this->n = bal.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if(account1 >= n || account2 >= n) {
            return false;
        }
        
        if(bal[account1] < money) 
            return false;
        
        bal[account1] -= money;
        bal[account2] += money;
        
        return true;
    }
    
    bool deposit(int account, long long money) {
        account--;

        if(account >= n) {
            return false;
        }
        
        bal[account] += money;
        
        return true;
    }
    
    bool withdraw(int account, long long money) {
        account--;

        if(account >= n) {
            return false;
        }
        
        if(bal[account] < money) 
            return false;
        
        bal[account] -= money;
        
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */