// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        // code here
        // we have two cases when rectangle dont coincide 
        // in x - axis -> when r1 <-> r2 and r2 <-> r1
        if(r1[0]<l2[0] or r2[0]<l1[0]){
            return false;
        }
        // in y - axis -> when r1 and r2
        //                     |      |
        //                     r2 and r1
        else if(l1[1]<r2[1] or l2[1]<r1[1]){
            return false;
        }
        return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends