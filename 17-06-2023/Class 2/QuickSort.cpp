class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)
            return;
        
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
        // code her
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       
       int pivot = arr[low];
       int i=low,j=high;
       
       while(i<j){
           
           while(arr[i]<=pivot and i<high){
               i++;
           }
           
           while(arr[j]>pivot and j>low){
               j--;
           }
           
            if(i<j)
                swap(arr[i],arr[j]);
       }
       
       swap(arr[low],arr[j]);
       return j;
       
    }
};
