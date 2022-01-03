// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        int n = s.length();
        string ans = "";
        for(int i=1; i<=n+1; i++){
            ans+=(i+'0');
        }
        for(int i=0; i<n;){
            if(s[i]=='D'){
                int count = 0, itr = i; 
                while(i<n and s[itr]=='D'){
                    count++;
                    itr++;
                }
                reverse(ans.begin()+i, ans.begin()+itr+1);
                i = itr;
            }else{
                i++;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends