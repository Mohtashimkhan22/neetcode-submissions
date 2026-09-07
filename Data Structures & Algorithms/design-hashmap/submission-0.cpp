class LinkedList{
public:
    LinkedList* next;
    int key,val;
    LinkedList(int key,int val){
        this->val = val;
        this->key = key;
        next=nullptr;
    }
};
class MyHashMap {
LinkedList* head = nullptr;
LinkedList* tail = nullptr;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        LinkedList* curr = head;
        while(curr){
            if(curr->key==key){
                curr->val=value;
                return;
            }
            curr = curr->next;
        }
        LinkedList* node = new LinkedList(key,value);
        if(!head){
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail=node;
        return;
    }
    
    int get(int key) {
        LinkedList* curr = head;
        while(curr){
            if(curr->key==key){
                return curr->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        LinkedList* curr = head;
        if(!curr) return;
        if(curr->key==key){
            head=curr->next;
            delete curr;
            return;
        }
        while(curr->next){
            if(curr->next->key==key){
                if(curr->next==tail){
                    tail=curr;
                }
                LinkedList* temp = curr->next;
                curr->next=curr->next->next;
                delete temp;
                return;
            }
            curr=curr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */