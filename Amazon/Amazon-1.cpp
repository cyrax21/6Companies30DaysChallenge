// Maximum Profit / Best time to sell and buy -IV (K- transactions)
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        if(k==0 or n==0){
            return 0;
        }
        int profit[k+1][n];
        memset(profit, 0, sizeof profit);
        
        // 1st row => zero transaction => profit = 0
        // 1st col => buy and sell at same day => profit = 0
        
        // transaction :
        for(int t=1; t<=k; t++){
            // filling the maximum profit we can get if we do transaction 
            // for "t" times till 'i'th day. 
            for(int i=1; i<n; i++){
                
                // maxm profit (t transac) 
                // = t-1 transaction at "j"th + price[j] - price[i];
                profit[t][i] = max(profit[t][i], profit[t][i-1]);
                for(int j=0; j<i; j++){
                    profit[t][i] = max(profit[t][i], profit[t-1][j]+(prices[i]-prices[j]));
                }
            }
        }
        
        return profit[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends