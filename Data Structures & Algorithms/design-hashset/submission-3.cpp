class LinkedList{
public:
    LinkedList* next;
    int val;
    LinkedList(int key){
        val = key;
        next=nullptr;
    }
};
class MyHashSet {
LinkedList* head = nullptr;
LinkedList* tail = nullptr;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        LinkedList* node = new LinkedList(key);
        if(!head){
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail=node;
        return;
    }
    
    void remove(int key) {
        LinkedList* curr = head;
        if(!curr) return;
        if(curr->val==key){
            head=curr->next;
            delete curr;
            return;
        }
        while(curr->next){
            if(curr->next->val==key){
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
    
    bool contains(int key) {
        LinkedList* curr = head;
        while(curr){
            if(curr->val==key){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */