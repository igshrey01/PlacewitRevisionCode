class Solution
{
    public:
    int select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
    }
     
    void selectionSort(int arr[], int n)
    {
       
       for(int i=0;i<n-1;i++){
           
           int minInd = i;
           
           for(int j=i;j<n;j++){
               
               if(arr[j]<arr[minInd]){
                   minInd = j;
               }
               
           }
           
           swap(arr[i],arr[minInd]);
           
       }
       
    }
};
