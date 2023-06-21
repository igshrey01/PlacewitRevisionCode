//Question Link - https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?leftPanelTab=1
#include <bits/stdc++.h> 
class TrieNode{
    
    private:
        TrieNode* links[26];
        int countWord,countPrefix;
    
    public:
        
        TrieNode(){
            
            countWord = 0,countPrefix = 0;
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
        
        void increasePrefix(){
            countPrefix++;
        }

        void increaseWord(){
            countWord++;
        }

        void decreasePrefix(){
            countPrefix--;
        }

        void decreaseWord(){
            countWord--;
        }
        
        int countOfWord(){
            return countWord;
        }

        int countOfPrefix(){
            return countPrefix;
        }
};
class Trie{

    TrieNode* root;
    public:

    Trie(){

        root = new TrieNode();
        // Write your code here.
    }

    void insert(string &word){
        
        int n = word.size();
        TrieNode* tmp = root;
        
        for(int i=0;i<n;i++){
            
            if(!tmp->containKey(word[i]))
                tmp->setNode(word[i],new TrieNode());
            
            tmp = tmp->moveTo(word[i]);
            tmp->increasePrefix();
            
        }

        tmp->increaseWord();
        
    }

    int countWordsEqualTo(string &word){
        
        TrieNode* tmp = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            
            if(!tmp->containKey(word[i]))
                return 0;
            
            tmp = tmp->moveTo(word[i]);
            
        }

        return tmp->countOfWord();
        
    }

    int countWordsStartingWith(string &word){
        
        TrieNode* tmp = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            
            if(!tmp->containKey(word[i]))
                return 0;
            
            tmp = tmp->moveTo(word[i]);
            
        }

        return tmp->countOfPrefix();
        
    }

    void erase(string &word){
        
        int n = word.size();
        TrieNode* tmp = root;
        
        for(int i=0;i<n;i++){
            
            tmp = tmp->moveTo(word[i]);
            tmp->decreasePrefix();
            
        }

        tmp->decreaseWord();
        
    }
};
