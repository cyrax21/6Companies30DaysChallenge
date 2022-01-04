// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n&1){
            return false;
        }
        unordered_map<int, int> mp;
        
        // store all the remainder of arr[i]%k in hashmap
        for(int i=0; i<n; i++) mp[nums[i]%k]++;
        
        for(auto x: mp){

            // all 0 remainder must be even in count
            if(x.first==0 and x.second&1){
                return false;
            }

            // and all remainder's freq and compliment freq must be equal
            if(x.first!=0 and x.second - mp[k-x.first]!=0){
                return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends