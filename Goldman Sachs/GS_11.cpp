// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{

// approach 1: Hashing
// approach 2: 
/*

x is missing and y is actual

 ActualSum - sumofarray = n(n+1)/2 - arr[i](from i = 0 to n) = x - y
 Then
 SquareSum - SquareSumofArray = n(n+1)(2n+1)/6 - (arr[i])^2 (from i = 0 to n) = x2 - y2
 
 now divide x2-y2/x-y = x+y
 
 now solve them get x and get y

*/

// Approach 3:
/*

use indexes as indication


// for repeating
mark all arr[i] = -arr[abs(arr[i])-1];
if at any point a index is already neg means that is repeatative element


now traverse again if at any index value is +ve then missing no is i+1


*/

public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int xor1 = 0;
        for(int i=0; i<n; i++) xor1 = xor1^arr[i];
        for(int i=1; i<=n; i++) xor1 = xor1^(i);
        
        // xor1 contains missing^repeating
        // now
        int x = 0, y = 0;
        
        // Get the lsb 
        int posDiff = xor1&(~(xor1-1));
        
        for(int i=0; i<n; i++){
            if(arr[i]&posDiff){
                x = x^arr[i];
            }else{
                y = y^arr[i];
            }
        }
        for(int i=1; i<=n; i++){
            if(i&posDiff){
                x = x^i;
            }else{
                y = y^i;
            }
        }
        
        int xMiss = true;
        for(int i=0; i<n; i++){
            if(arr[i]==x){
                xMiss = false;
                break;
            }
        }
        if(!xMiss) swap(x, y);
        int *a = new int[2];
        a[0] = y, a[1] = x;
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends