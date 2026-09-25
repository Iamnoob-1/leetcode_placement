class Node{
    public:
    int key,val;
    Node *prev,*next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head,*tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void insert(Node* n){
        n->next=head->next;
        n->prev=head;
        head->next->prev=n;
        head->next=n;
    }
    void remove(Node* n){
        n->prev->next=n->next;
        n->next->prev=n->prev;
    }
    int get(int key) {
        if (mp.find(key)==mp.end())return -1;
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            temp->val=value;
            remove(temp);
            insert(temp);
            return ;
        }
        Node* t=new Node(key,value);
        mp[key]=t;
        insert(t);
        if(mp.size()>capacity){
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */