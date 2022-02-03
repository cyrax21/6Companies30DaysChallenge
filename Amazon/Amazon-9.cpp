// Which among them forms a perfect Sudoku Pattern ?
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int n = mat.size();

        for(int i=0; i<n; i++){
        	// row and col check
            int checkRow = (1<<10)-1, checkCol = (1<<10)-1;
            for(int j = 0; j<n; j++){
                if(mat[i][j]!=0){
                    if(checkCol&(1<<mat[i][j])) checkCol = checkCol^(1<<mat[i][j]);
                    else return 0;
                }
                if(mat[j][i]!=0){
                    if(checkRow&(1<<mat[j][i])) checkRow = checkRow^(1<<mat[j][i]);
                    else return 0;
                }
            }
        }
        // Time: row*col + row/3*col/3*row/3*col/3 = n^2 , 0(1) space
        for(int a=0; a<n; a+=3){
            for(int b=0; b<n; b+=3){
                int check = (1<<10)-1;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        if(mat[a+i][b+j]!=0){
                            if(check&(1<<mat[a+i][b+j])) check = check^(1<<mat[a+i][b+j]);
                            else return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends