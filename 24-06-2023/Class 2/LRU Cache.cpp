//Link - https://leetcode.com/problems/lru-cache/

struct Node{
    
    int key,value;
    Node* prev,*next;
    
    Node(int key, int value){
        
        this->key = key;
        this->value = value;
        prev = next = NULL;
        
    }
    
};


class LRUCache {
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int availableCapacity;
    unordered_map<int,Node*> pos;
    
public:
    LRUCache(int capacity) {
        
        availableCapacity  = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    void deleteNode(Node* currNode){
        
        Node* prevNode = currNode->prev;
        Node* nextNode = currNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
    }
    
    void insertAfterHead(Node* currNode){
        
        Node* tmp = head->next;
        
        head->next = currNode;
        currNode->prev = head;
        
        currNode->next = tmp;
        tmp->prev = currNode;
        
    }
    
    int get(int key) {
        
        if(pos.find(key) == pos.end())
            return -1;
        
        Node* currNode = pos[key];
        deleteNode(currNode);
        pos.erase(key);
        
        insertAfterHead(currNode);
        pos[key] = head->next;
        
        return currNode->value;
        
    }
    
    void put(int key, int value) {
        
        if(pos.find(key)!=pos.end()){
            
            Node* currNode = pos[key];
            deleteNode(currNode);
            pos.erase(key);
                
        }
        
        if(pos.size() == availableCapacity){
            
            pos.erase(tail->prev->key);
            deleteNode(tail->prev);
            
        }
        
        insertAfterHead(new Node(key,value));
        pos[key] = head->next;
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
