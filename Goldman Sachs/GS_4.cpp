// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    //Your code here
    string ans = "";
    int n = src.length();
    for(int i=0; i<n;){
        char ch = src[i], count = 0;
        while(src[i]==ch){
            count++;
            i++;
        }
        char no = count+'0';
        // cout<<ch<<" "<<no<<endl;
        ans.push_back(ch);
        ans.push_back(no);
    }
    return ans;
}     
 
