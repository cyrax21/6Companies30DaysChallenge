#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int mod = 1e9 + 7;
	int dp[10005];
	    int solve(int pos, string str){
	        if(pos==str.length()) return 1;
	        
	        if(dp[pos]!=-1) return dp[pos];
	        int op1 = 0, op2 = 0;
	        if(str[pos]!='0') op1 = solve(pos+1, str);
	        if(pos+2<=str.length()){
	            int s = (str[pos]-'0')*10+(str[pos+1]-'0');
	            if(s==0) return 0;
	            if(s<=26 and s>=10) op2 = solve(pos+2, str);
	        }
	        return dp[pos] = (op1+op2)%mod;
	    }
		int CountWays(string str){
		    // Code here
		    memset(dp, -1, sizeof dp);
		    if(str[0]=='0') return 0;
		    return solve(0, str);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends