class LRUCache {
public:
    class Node {
    public:
        Node* next;
        Node* prev;
        int key, value;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    int limit;

    void addnode(Node* newnode) {
        Node* oldnext = head->next;
        head->next = newnode;
        oldnext->prev = newnode;
        newnode->next = oldnext;
        newnode->prev = head;
    }

    void deletenode(Node* oldnode) {
        Node* oldprev = oldnode->prev;
        Node* oldnext = oldnode->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansnode = m[key];
        int ans = ansnode->value;
        m.erase(key);
        deletenode(ansnode);
        addnode(ansnode);
        m[key] = ansnode;
        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldnode = m[key];
            deletenode(oldnode);
            m.erase(key);
        }
        if (m.size() == limit) {
            // delete lru
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        Node* newnode = new Node(key, value);
        addnode(newnode);
        m[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */