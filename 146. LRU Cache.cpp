class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* pre;
        Node* next;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }

    };
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> cache;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }

    void addnode(Node* newnode)
    {
        newnode->next = head->next;
        head->next = newnode;
        newnode->next->pre = newnode;
        newnode->pre = head;
    }

    void deletenode(Node* node)
    {
        Node* prenode = node->pre;
        Node* nextnode = node->next;
        prenode->next = nextnode;
        nextnode->pre = prenode;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) return -1;
        Node* node = cache[key];
        cache.erase(key);
        deletenode(node);
        addnode(node);
        cache[key] = node;
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key) == 1)
        {
            Node* node = cache[key];
            node->value = value;
            cache.erase(key);
            deletenode(node);
            // return;
        }
        Node* node = new Node(key, value);
        if (cache.size() == cap)
        {
            Node* todelete = tail->pre;
            cache.erase(todelete->key);
            deletenode(todelete);
        }
        addnode(node);
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */