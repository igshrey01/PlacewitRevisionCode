//Link - https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check(int A[], int N, int M, int mid){
        
        int value = 0, currStudent = 1;
        
        for(int i=0;i<N;i++){
            
            if(value+A[i]>mid){
                value = A[i];
                currStudent++;
            }
            else{
                value+=A[i];
            }
            
        }
        
        if(currStudent<=M)
            return 1;
        
        return 0;
        
    }
    int findPages(int A[], int N, int M) 
    {
        
        if(N<M)
            return -1;
        
        int maxEle = INT_MIN;
        int sum = 0;
        
        for(int i=0;i<N;i++)
        {
            maxEle = max(maxEle,A[i]);
            sum+=A[i];
        }
        int low = maxEle,high = sum;
        int res = -1;
        while(low<=high){
            
            int mid = low+(high-low)/2;
            if(check(A,N,M,mid)){
                high = mid-1;
                res = mid;
            }
            else
                low = mid+1;
        
        }
        
        return res;
        //code here
    }
};
