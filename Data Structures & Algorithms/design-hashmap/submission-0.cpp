class MyHashMap {
private:
    struct Node {
        int key, val;
        Node* next;

        Node(
            int key = -1,
            int val = -1,
            Node* next = nullptr
        ): key(key), val(val), next(next) {}
    };

    vector<Node*> chains;
    int hash(int key) {
        return key % chains.size();
    }
public:
    MyHashMap() : chains(1000) {
        for (auto& chain : chains) {
            chain = new Node(0);
        }
    }
    
    void put(int key, int value) {
        Node* cur = chains[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }
            cur=cur->next;
        }
        cur->next = new Node(key, value);
    }
    
    int get(int key) {
        Node* cur = chains[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                return cur->next->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        Node* cur = chains[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */