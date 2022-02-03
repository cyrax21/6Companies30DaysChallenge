class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxPeak = 0;
        
        for(int i = 1; i<arr.size()-1; i++){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                int x = 0, y = 0;
                int j = i;
                while(j!=0 && arr[j-1]<arr[j]){
                    j--;
                    x++;
                }
                j=i;
                while(i<arr.size()-1 && arr[i+1]<arr[i]){
                    i++;
                    y++;
                }
                maxPeak = max(maxPeak, x+y+1);
            }
        }
        
        return maxPeak;
    }
};