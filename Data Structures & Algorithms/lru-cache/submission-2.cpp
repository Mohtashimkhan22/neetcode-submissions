class Node{
public:
    int val;
    Node* prev,*next;

    Node(int val){
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class LRUCache {
    Node* head;
    Node* tail;
    int n;
    unordered_map<int,pair<int,Node*>> mp;
public:
    LRUCache(int capacity) {
        head = nullptr;
        tail = nullptr;
        n=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        Node* curr = mp[key].second;
        int val = mp[key].first;
        if(curr==tail) return val;
        if(curr==head){
            curr->next->prev = nullptr;
            head = curr->next;
        }
        else{
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
        }
        tail->next=curr;
        curr->prev=tail;
        tail=curr;
        return val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* curr = mp[key].second;
            if(curr==tail){
                mp[key].first = value;
                return;
            }
            if(curr==head){
                curr->next->prev = nullptr;
                head = curr->next;
            }
            else{
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
            }
            tail->next=curr;
            curr->prev=tail;
            tail=curr;
            mp[key].first = value;
            return;
        }
        else if(mp.size()==n){
            Node* first = head;
            mp.erase(head->val);
            if(tail==head) tail=nullptr;
            head=head->next;
            delete first;
        }
        Node* curr = new Node(key);
        mp[key]={value,curr};
        if(!head) head=curr;
        if(!tail) tail=curr;
        else{
            tail->next=curr;
            curr->prev = tail;
            tail=curr;
        }
    }
};
