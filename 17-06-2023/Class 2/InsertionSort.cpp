class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        
        for(int i=1;i<n;i++){
            
            int j=i;
            
            while(j>0 and arr[j-1]>arr[j]){
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                //swap(arr[j-1],arr[j]);
                j--;
            }
            
        }
        //code here
    }
};
