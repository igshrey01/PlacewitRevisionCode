//Link - https://leetcode.com/problems/range-sum-query-mutable/

class segTree{
        
    public:
    
        vector<int> sumNodes;
    
        segTree(){
            
        }
        void resizeArr(int n){
            sumNodes.resize(4*n);
        }
        void print(){
            
            for(auto x:sumNodes)
                cout<<x<<" ";
            cout<<endl;
            
        }

        void build(int node, int l, int r, vector<int> &a){

            if(l == r){
                sumNodes[node] = a[l];
                return;
            }

            int mid = l+(r-l)/2;
            build(2*node,l,mid,a);
            build(2*node+1,mid+1,r,a);

            sumNodes[node] = sumNodes[2*node]+sumNodes[2*node+1];

        }

        void update(int in, int value, int node, int l, int r, vector<int> &a){

            if(l==r){

                a[in] = value;
                sumNodes[node] = value;
                return;

            }

            int mid = l+(r-l)/2;
            if(in<=mid){
                update(in,value,2*node,l,mid,a);
            }
            else{
                update(in,value,2*node+1,mid+1,r,a);
            }

            sumNodes[node] = sumNodes[2*node]+sumNodes[2*node+1];

        }

        int query(int node, int l, int r, int queryL, int queryR){

            
            //cout<<node<<" "<<l<<" "<<r<<" "<<queryL<<" "<<queryR<<endl;
            if(queryL>r or queryR<l)
                return 0;
            
            //cout<<1<<endl;
            if(queryL<=l and queryR>=r)
                return sumNodes[node];
            
            int mid = l+(r-l)/2;
            int leftSum = query(2*node,l,mid,queryL,queryR);
            int rightSum = query(2*node+1,mid+1,r,queryL,queryR);
            
            //cout<<leftSum<<" "<<rightSum<<endl;
            return leftSum+rightSum;

        }


};
class NumArray {
    segTree sumTree;
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        
        int n = nums.size();
        num = nums;
        sumTree.resizeArr(4*n+1);
        sumTree.build(1,0,n-1,nums);
        
    }
    
    void update(int index, int val) {
        
        sumTree.update(index,val,1,0,num.size()-1,num);
        //sumTree.print();
        
    }
    
    int sumRange(int left, int right) {
        
        return sumTree.query(1,0,num.size()-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
