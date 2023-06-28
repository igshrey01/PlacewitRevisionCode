//Link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Trie{
    
    Trie* links[2];
    
    public:
    Trie(){
        memset(links,NULL,sizeof(links));
    }
    
    bool containKey(int bit){
        return links[bit]!=NULL;
    }
    
    void addNewNode(int bit, Trie* newNode){
        links[bit] = newNode;
    }
    
    Trie* moveTo(int bit)
    {
        return links[bit];
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int n = nums.size();
        Trie* root = new Trie();
        int maxAns = 0;
        
        for(int i=0;i<n;i++){
            
            int tmp = nums[i];
            Trie* currNode = root;
            
            for(int j=31;j>=0;j--){
                
                int tp = tmp;
                int bit = (tp>>j)&1;
                //cout<<bit<<endl;
                if(!currNode->containKey(bit)){
                    currNode->addNewNode(bit,new Trie());
                }
                
                currNode = currNode->moveTo(bit);
                
            }
            
            currNode = root;
            int currAns = 0;
            
            for(int j=31;j>=0;j--){
                    
                int tp = tmp;
                int bit = (tp>>j)&1;
                
                if(currNode->containKey(!bit)){
                    currNode = currNode->moveTo(!bit);
                    currAns+=(1LL<<j);
                }
                else{
                    currNode = currNode->moveTo(bit);
                }
                
            }
            
            maxAns = max(maxAns,currAns);
            
        }
        
        return maxAns;
    }
};
