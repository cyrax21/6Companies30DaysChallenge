// Brackets in MCM
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int kUsed[26][26];
public:
    void formString(int i, int j, string &ans, char &alpha){
        if(i==j){
            ans.push_back(alpha);
            alpha++;
            return;
        }
        
        ans.push_back('(');
        
        int k = kUsed[i][j];
        formString(i, k, ans, alpha);
        formString(k+1, j, ans, alpha);
        
        ans.push_back(')');
    }
    string matrixChainOrder(int arr[], int n){
        // code here
        int len = n-1;  
        int dp[len][len];
        memset(kUsed, 0, sizeof kUsed);
        
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                dp[i][j] = INT_MAX;
                if(i==j)
                    dp[i][j] = 0;
            }
        }
        
        for(int l=2; l<=len; l++){
            for(int i=0; i<len-l+1; i++){
                int j = i+l-1;
                for(int k=i; k<j; k++){
                    int val = dp[i][k]+dp[k+1][j]+(arr[i]*arr[k+1]*arr[j+1]);
                    if(val<dp[i][j]){
                        dp[i][j] = val;
                        kUsed[i][j] = k;
                    }
                }
            }
        }
        
        string ans = "";
        char ch = 'A';
        formString(0, n-2, ans, ch);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends