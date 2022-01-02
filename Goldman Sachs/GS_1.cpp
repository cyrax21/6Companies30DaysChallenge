// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& sl) {
        //code here
        vector<vector<string>> ans;
        
        int n = sl.size();
        vector<pair<string, int>> mp;
        for(int i=0; i<n; i++){
            string temp = sl[i];
            sort(temp.begin(), temp.end());
            mp.push_back({temp, i});
        }
        sort(mp.begin(), mp.end());
        
        for(int i = 0; i<n;){
            string temp = mp[i].first;
            vector<string> cat;
            while(i<n and temp==mp[i].first){
                cat.push_back(sl[mp[i].second]);
                i++;
            }
            ans.push_back(cat);
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends