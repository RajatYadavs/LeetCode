class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int key){
        data=key;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
    Node* head=new Node(-1);
    Node* tail=new Node(-1);
    int cap;
    unordered_map<int,pair<Node*,int>>hm;
    public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(hm.find(key)==hm.end())
            return -1;
        else{
            Node* t=hm[key].first;
            t->prev->next=t->next;
            t->next->prev=t->prev;
            tail->prev->next=t;
            t->next=tail;
            t->prev=tail->prev;
            tail->prev=t;
            return hm[key].second;
        }
    }
    
    void put(int key, int value) {
        if(hm.find(key)!=hm.end()){
            hm[key].second=value;
            Node* t=hm[key].first;
            t->prev->next=t->next;
            t->next->prev=t->prev;
            
            tail->prev->next=t;
            t->next=tail;
            t->prev=tail->prev;
            tail->prev=t;
            return;
        }
        else if(hm.size()==cap){
            int n=head->next->data;
            hm.erase(n);
            
            head->next=head->next->next;
            head->next->prev=head;
        }
        Node* t=new Node(key);
        hm.insert(make_pair(key,make_pair(t,value)));
        if(head->next==NULL){
            head->next=t;
            t->prev=head;
            t->next=tail;
            tail->prev=t;
        }
        else{ 
            tail->prev->next=t;
            t->next=tail;
            t->prev=tail->prev;
            tail->prev=t;
        } 
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */