// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        while(n!=0){
            // A, ----, Z -> 26 col
            // AA, ---- , AZ, BA, ----, BZ, ---- , ZA ---- ZZ -> 26*26
            // similarly -> 26*26*26, 26*26*26*26 ..........
            /*
            
            At first, it will give remainder last column name's character
            
            so we are dividing it by 26 
            
            */
            char index = 'A'+(n-1)%26;
            ans = (index) + ans;
            n = (n-1)/26;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends