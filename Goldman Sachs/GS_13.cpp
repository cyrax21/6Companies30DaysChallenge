

// 2 Stack approach
/*
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isDigit(char ch){
        return (ch-'0'>=0 && ch-'0'<=9);
    }
    string decodedString(string s){
        // code here
        string ans = "";
        stack<string> st;
        stack<int> number;
        
        int n = s.length();
        string res = "";
        for(int i=0; i<n;){
            if(isDigit(s[i])){
                int nos = 0;
                while(i<n and isDigit(s[i])){
                    nos = nos*10 + (s[i]-'0');
                    i++;
                }
                number.push(nos);
            }else if(s[i]=='['){
                st.push(res);
                res="";
                i++;
            }
            else if(s[i]==']'){
                int times = number.top();
                number.pop();
                string temp = st.top();
                st.pop();
                for(int itr=1; itr<=times; itr++){
                    temp+=res;
                }
                res = temp;
                i++;
            }else{
                res+=s[i];
                i++;
            }
        }

        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
} */
 // } Driver Code Ends







// 1 stack Apporach (GFG)

// Recursive Apporach

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isDigit(char ch){
        return (ch-'0'>=0 && ch-'0'<=9);
    }
    string solve(string s, int &i){
        string ref = "";
        int n = s.length();
        while(i<n and s[i]!=']'){
            if(isDigit(s[i])){
                int no = 0;
                while(i<n and isDigit(s[i])){
                    no = no*10 + (s[i]-'0');
                    i++;
                }
                
                i++; // skip the '['
                
                string temp = solve(s, i);
                
                i++; // skip the ']'
                
                while(no--){
                    ref+=temp;
                }
                
            }else{
                ref += s[i];
                i++;
            }
        }
        return ref;
    }
    string decodedString(string s){
        // code here
        int i = 0;
        return solve(s, i);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends