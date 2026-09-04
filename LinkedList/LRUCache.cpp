#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertToFront(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        remove(node);
        insertToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insertToFront(node);
            return;
        }
        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insertToFront(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */