class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int sum = 0;
        int size = INT_MAX;
        int n = a.size();
        int start = 0, end = 0;
        while(end<n){
            
            sum+=a[end];
            
            while(start<n and sum>target){
                sum-=a[start];
                start++;
            }
            
            if(sum>=target){
                size = min(size, (end-start+1)); 
            }else if(start!=0 and sum+a[start-1]>=target){
                size = min(size, (end-start+2));
            }
            end++;
        }
        return size!=INT_MAX?size:0;
    }
};