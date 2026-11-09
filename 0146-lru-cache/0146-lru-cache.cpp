class LRUCache {
private:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Remove a node from the list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert a node immediately after head
    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        head->next = node;
        nextNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Mark as recently used
        removeNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        // Case 1: Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            insertAfterHead(node);

            return;
        }

        // Case 2: Cache is full
        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            mp.erase(lru->key);
            removeNode(lru);

            delete lru;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // Insert at most recently used position
        insertAfterHead(newNode);

        // Store in hash map
        mp[key] = newNode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */