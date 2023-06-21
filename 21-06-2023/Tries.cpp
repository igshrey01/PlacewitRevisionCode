class TrieNode{
    
    private:
        TrieNode* links[26];
        bool flg;
    
    public:
        
        TrieNode(){
            
            flg = false;
            memset(links,NULL,sizeof(links));
            
        }
    
        bool containKey(char ch){
            return links[ch-'a'] != NULL;
        }
    
        void setNode(char ch, TrieNode* newNode){
            links[ch-'a'] = newNode;
        }
        
        TrieNode* moveTo(char ch){
            return links[ch-'a'];
        }
    
        void setEnd(){
            flg = true;
        }
    
        bool isEnd(){
            return flg;
        }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        int n = word.size();
        TrieNode* tmp = root;
        
        for(int i=0;i<n;i++){
            
            if(!tmp->containKey(word[i]))
                tmp->setNode(word[i],new TrieNode());
            
            tmp = tmp->moveTo(word[i]);
        }
        
        tmp->setEnd();
        
    }
    
    bool search(string word) {
        
        int n = word.size();
        TrieNode* tmp = root;
        
        for(int i=0;i<n;i++){
            
            if(!tmp->containKey(word[i]))
                return false;
            
            tmp = tmp->moveTo(word[i]);
        }
        
        return tmp->isEnd();
        
    }
    
    bool startsWith(string prefix) {
        
        int n = prefix.size();
        TrieNode* tmp = root;
        
        for(int i=0;i<n;i++){
            
            if(!tmp->containKey(prefix[i]))
                return false;
            
            tmp = tmp->moveTo(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
