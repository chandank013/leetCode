class DinnerPlates {
private:
    int capacity;

    vector<stack<int>> stacks;

    // Min heap stores indices of potentially non-full stacks
    priority_queue<int, vector<int>, greater<int>> available;

    // Rightmost nonempty stack
    int rightMost = -1;

public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (capacity == 0) {
            return;
        }

        // Remove stale indices of full stacks
        while (!available.empty() &&
               (available.top() >= stacks.size() ||
                stacks[available.top()].size() == capacity)) {
            available.pop();
        }

        int index;

        if (available.empty()) {
            // No available stack, create a new one
            index = stacks.size();
            stacks.push_back(stack<int>());
        } else {
            // Use the leftmost available stack
            index = available.top();
            available.pop();
        }

        stacks[index].push(val);

        rightMost = max(rightMost, index);

        // If this stack still has space, keep its index available
        if (stacks[index].size() < capacity) {
            available.push(index);
        }
    }

    int pop() {
        // Move left until a nonempty stack is found
        while (rightMost >= 0 && stacks[rightMost].empty()) {
            rightMost--;
        }

        if (rightMost < 0) {
            return -1;
        }

        int val = stacks[rightMost].top();
        stacks[rightMost].pop();

        // The stack now has space
        available.push(rightMost);

        // Update rightmost if this stack became empty
        while (rightMost >= 0 && stacks[rightMost].empty()) {
            rightMost--;
        }

        return val;
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() ||
            stacks[index].empty()) {
            return -1;
        }

        int val = stacks[index].top();
        stacks[index].pop();

        // This stack now has available space
        available.push(index);

        // Update rightmost if necessary
        while (rightMost >= 0 && stacks[rightMost].empty()) {
            rightMost--;
        }

        return val;
    }
};
/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */