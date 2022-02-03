// Nuts and bolts - Sorting
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int partition(char nuts[], int low, int high, int pivot){
        int i = low;
        for(int j=low; j<=high-1; j++){
            if(nuts[j]<pivot){
                swap(nuts[i], nuts[j]);
                i++;
            }else if(nuts[j]==pivot){
                swap(nuts[j], nuts[high]);
                j--;
            }
        }
        swap(nuts[i], nuts[high]);
        return i;
    }
    void qSort(char nuts[], char bolts[], int low, int high){
        if(low<high){
            int pi = partition(nuts, low, high, bolts[high]);
            
            qSort(nuts, bolts, low, pi-1);
            qSort(nuts, bolts, pi+1, high);
        }
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    qSort(nuts, bolts, 0, n-1);
	    for(int i=0; i<n; i++){
	        bolts[i] = nuts[i];
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends