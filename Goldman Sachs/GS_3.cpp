// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int s = 0, e = 0, count = 0;
        long long int prod = 1;
        
        while(e<n){
            prod *= a[e];
            
            while(s<n and prod>=k){
                prod = prod/a[s];
                s++;
            }
            
            if(prod<k){
                int length = e-s+1;
                count+=length;
            }
            e++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends