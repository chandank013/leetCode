class LFUCache {
private:
    struct Node {
        int value;
        int freq;
        long long time;
    };

    int capacity;
    long long timer = 0;

    unordered_map<int, Node> mp;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        mp[key].freq++;
        mp[key].time = ++timer;

        return mp[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // Update existing key
        if (mp.find(key) != mp.end()) {
            mp[key].value = value;
            mp[key].freq++;
            mp[key].time = ++timer;
            return;
        }

        // Evict LFU key if cache is full
        if (mp.size() == capacity) {
            int victim = -1;
            int minFreq = INT_MAX;
            long long oldestTime = LLONG_MAX;

            for (auto& p : mp) {
                int k = p.first;
                Node node = p.second;

                if (node.freq < minFreq ||
                    (node.freq == minFreq &&
                     node.time < oldestTime)) {

                    minFreq = node.freq;
                    oldestTime = node.time;
                    victim = k;
                }
            }

            mp.erase(victim);
        }

        mp[key] = {value, 1, ++timer};
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */