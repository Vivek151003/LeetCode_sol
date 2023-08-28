// Intuition
// The goal is to implement a Last-In-First-Out (LIFO) stack using two queues, where the key challenge is to ensure that the elements are processed in reverse order to simulate the stack behavior. To achieve this, one queue can be used as the primary storage, while the second queue is used as a temporary container to reverse the order of elements.

// Approach
// Create two queues, queue1 and queue2.

// Push Operation:-

// When pushing an element:
// If queue1 is empty, enqueue the new element directly into it.
// If queue1 is not empty, enqueue the new element into queue2, and then enqueue all elements from queue1 into queue2. Finally, swap the names of queue1 and queue2.

// Pop Operation:-

// Dequeue an element from the front of the non-empty queue. Since the front element represents the top of the stack, this operation simulates popping from the stack.

// Top Operation:-

// Return the front element of the non-empty queue.

// Empty Operation:-

// Check if both queue1 and queue2 are empty. If both are empty, the stack is empty.

// Complexity
// Time complexity:
// The push operation takes O(n) time in the worst case, where n is the number of elements in the stack, due to the need to transfer elements between queues.
// The pop, top, and empty operations all take O(1) time.

// Space complexity:
// The space complexity is O(n) due to the space required to store elements in the two queues.

// Code : 

class MyStack {
public:
queue<int>queue1,queue2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(queue1.empty())
        {
            queue1.push(x);
            while(!queue2.empty())
            {
                queue1.push(queue2.front());
                queue2.pop();
            }
        }
        else
        {
            queue2.push(x);
            while(!queue1.empty())
            {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
    }
    
    int pop() {
        int topElement = top();
        if(!queue1.empty())
        queue1.pop();
        else
        queue2.pop();
        return topElement;
    }
    
    int top() {
        if(!queue1.empty())
        return queue1.front();
        else
        return queue2.front();
    }
    
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};


