#include<bits/stdc++.h>
using namespace std;


#define ll long long int
class Solution
{
    public:
    long long countWays(int m)
    {
        /*

        As order doesnt matter we only need to no
        nos of 1s and nos 2s required in set to get "m"

        Case 1: Doesnt Contain Any 2, 1 case only
        {1, 1, 1, 1} 
        Case 2: Contains 2, m/2 cases
        for example m = 11
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 2} ->1
        {1, 1, 1, 1, 1, 1, 1, 2, 2} ->2
        {1, 1, 1, 1, 1, 2, 2, 2} -> 3
        {1, 1, 1, 2, 2, 2, 2} -> 4
        {1, 2, 2, 2, 2, 2} -> 5
        maximum : m/2 twos -> m/2 set contains 2

        */
        return (m*1ll)/2+1;
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends