// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long




// Binary search is also applicable but it will be very much complicated 


/*
Time Complexity :   0(3*nlogn)
Reason : we are n number in set and for each insertion it takes logn time. 3 because we are inserting no*2, no*3, no*5 


Space Complexity : 0(n)
Reason : we are using set 

*/







 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    set<ull> s;
	    s.insert(1);
	    for(int i=0; i<n-1; i++){
	        ull no = *s.begin();
	        s.erase(s.begin());
	        s.insert(no*2);
	        s.insert(no*3);
	        s.insert(no*5);
	    }
	    return *s.begin();
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends