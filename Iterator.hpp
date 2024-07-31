// ID: 315233486
// Mail: Eilonashwal30@gmail.com

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <vector>
#include <stack>
#include <queue>
#include "Node.hpp"

using namespace std;

// Pre-Order Iterator (first visit the parent and then the children from left to right)
template <typename T> class preOrderIterator
{
    private:
        stack<Node<T> *> nodeStack; // stack of pointers to nodes 

    public:
        preOrderIterator(Node<T> *root) // constructor
        {
            if (root != nullptr) // if the root is not null, push it to the stack (the first node to be visited)
            {
                nodeStack.push(root);
            }
        }

        // get the value of the current node
        T operator*() const { return nodeStack.top()->get_value(); }

        // compare two iterators by their stack
        bool operator!=(const preOrderIterator<T> &other) const { return nodeStack != other.nodeStack; } 

        bool operator==(const preOrderIterator<T> &other) const { return nodeStack == other.nodeStack; }

        // get the pointer to the current node
        Node<T> *operator->() { return nodeStack.top(); }

        // move to the next node and push its children to the stack
        preOrderIterator<T> &operator++()
        {
            Node<T> *current = nodeStack.top(); // get the current node
            nodeStack.pop();

            // push the children of the current node to the stack in reverse order to visit them in the correct order
            for (int i = current->get_children_size() - 1; i >= 0; i--)
            {
                nodeStack.push(current->get_children()[i]);
            }

            return *this;
        }
};

// Post-Order Iterator (first visit the children from left to right and then the parent)
template <typename T> class postOrderIterator
{
    private:
        // stack1 is used to push the nodes in the correct order, stack2 is used to pop the nodes in the correct order
        stack<Node<T> *> nodeStack1, nodeStack2; 

    public:
        postOrderIterator(Node<T> *root) // constructor
        {
        if (root != nullptr) // if the root is not null, push it to stack1
            {
                nodeStack1.push(root);
                while (!nodeStack1.empty()) // Push the children of the nodes to stack1 in reverse order
                {
                    Node<T> *node = nodeStack1.top();
                    nodeStack1.pop();
                    nodeStack2.push(node);
                    for (size_t i = 0; i < node->get_children_size(); ++i)
                    {
                        nodeStack1.push(node->get_children()[i]);
                    }
                }
            }
        }

        // get the Node pointer of the current node
        Node<T> *operator->() { return nodeStack2.top(); }

        T operator*() const // get the value of the current node
        {
            if (nodeStack2.empty()) // if the stack is empty, throw an exception
            {
                throw out_of_range("Iterator out of range");
            }
            Node<T> *node = nodeStack2.top();
            return node->get_value();
        }

        // compare two iterators by their stack2
        bool operator!=(const postOrderIterator<T> &other) const { return nodeStack2 != other.nodeStack2; }

        bool operator==(const postOrderIterator<T> &other) const { return nodeStack2 == other.nodeStack2; }
        
        // move to the next node by popping the top node from stack2
        postOrderIterator<T> &operator++() 
        {
            if (!nodeStack2.empty())
            {
                nodeStack2.pop();
            }
            return *this;
        }
};

// In-Order Iterator (first visit the left child, then the parent, and then the right child)
template <typename T> class inOrderIterator
{
    private:
        stack<Node<T> *> nodeStack; // stack of pointers to nodes

        // Push all the left children of the node to the stack
        void pushLeft(Node<T> *node)
        {
            while (node != nullptr)
            {
                nodeStack.push(node);
                if (node->get_children_size() >= 1)
                {
                    node = node->get_children()[0];
                }
                else
                {
                    node = nullptr;
                }
            }
        }

    public:
        // Constructor that initializes the stack with the left children of the root
        inOrderIterator(Node<T> *root) { pushLeft(root); }

        T operator*() const // get the value of the current node
        {
            Node<T> *node = nodeStack.top();
            return node->get_value();
        }

        // compare two iterators by their stack
        bool operator!=(const inOrderIterator<T> &other) const { return nodeStack != other.nodeStack; }

        // compare two iterators by their stack and check if they are empty
        bool operator==(const inOrderIterator &other)
        {
            if (nodeStack.empty() && other.nodeStack.empty())
            {
                return true;
            }
            if (nodeStack.empty() != other.nodeStack.empty())
            {
                return false;
            }
            return nodeStack.top() == other.nodeStack.top();
        }

        // get the pointer to the current node
        Node<T> *operator->() { return nodeStack.top(); }

        // move to the next node by popping the top node from the stack and pushing all its left children
        inOrderIterator &operator++()
        {
            Node<T> *current = nodeStack.top();
            nodeStack.pop();

            if (current->get_children_size() >= 2)
            {
                pushLeft(current->get_children()[1]);
            }

            return *this;
        }
};

// BFS Iterator (Breadth-First Search)
template <typename T> class bfsIterator
{
    private:
        queue<Node<T> *> nodeQueue; // queue of pointers to nodes

    public:
        bfsIterator(Node<T> *root) // constructor that initializes the queue with the root
        {
            if (root != nullptr)
            {
                nodeQueue.push(root);
            }
        }

        // get the pointer to the front of the queue
        Node<T> *operator->() { return nodeQueue.front(); }

        // get the value of the front of the queue
        T operator*() const
        {
            Node<T> *node = nodeQueue.front();
            return node->get_value();
        }

        // compare two iterators by their queue
        bool operator!=(const bfsIterator<T> &other) const { return nodeQueue != other.nodeQueue; }

        bool operator==(const bfsIterator<T> &other) const { return nodeQueue == other.nodeQueue; }

        // move to the next node by popping the front of the queue and pushing all its children
        bfsIterator<T> &operator++()
        {
            if (nodeQueue.empty()) // if the queue is empty, throw an exception
            {
                throw out_of_range("Iterator out of range");
            }

            Node<T> *current = nodeQueue.front();
            nodeQueue.pop();

            for (auto &child : current->get_children()) // push the children of the current node to the queue
            {
                nodeQueue.push(child);
            }

            return *this;
        }
};

// DFS Iterator (Depth-First Search)
template <typename T> class dfsIterator
{
    private:
        stack<Node<T> *> nodeStack; // stack of pointers to nodes

    public:
        dfsIterator(Node<T> *root) // constructor that initializes the stack with the root
        {
            if (root != nullptr)
            {
                nodeStack.push(root);
            }
        }

        T operator*() const // get the value of the top of the stack
        {
            Node<T> *node = nodeStack.top();
            return node->get_value();
        }

        // compare two iterators by their stack
        bool operator!=(const dfsIterator<T> &other) const { return nodeStack != other.nodeStack; }

        bool operator==(const dfsIterator<T> &other) const { return nodeStack == other.nodeStack; }
        
        // get the pointer to the top of the stack
        Node<T> *operator->() { return nodeStack.top(); }

        // move to the next node by popping the top of the stack and pushing all its children left to right
        dfsIterator<T> &operator++()
        {
            if (nodeStack.empty()) // if the stack is empty, throw an exception
            {
                throw out_of_range("Iterator out of range");
            }

            Node<T> *current = nodeStack.top();
            nodeStack.pop();

            // push the children of the current node to the stack in reverse order to visit them left to right
            for (int i = current->get_children_size() - 1; i >= 0; i--)
            {
                nodeStack.push(current->get_children()[i]);
            }

            return *this;
        }
};

template <typename T> class heapIterator
{
    private:
        vector<Node<T> *> heap; // vector of pointers to nodes

    public:
        heapIterator(Node<T> *root) // constructor that initializes the heap with the root
        {
            if (root != nullptr)
            {
                queue<Node<T> *>nodeQueue;
                nodeQueue.push(root);

                // push all the children of the root to the nodeQueue
                while (!nodeQueue.empty())
                {
                    Node<T> *current = nodeQueue.front();
                    nodeQueue.pop();
                    heap.push_back(current);

                    for (size_t i = 0; i < current->get_children_size(); ++i)
                    {
                        nodeQueue.push(current->get_children()[i]);
                    }
                }

                // sort the heap in descending order by the value of the nodes
                make_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b)
                            { return a->get_value() > b->get_value(); });
            }
        }
        
        // compare two iterators by their heap and check if they are empty
        bool operator==(const heapIterator &other) const
        {
            if (heap.empty() && other.heap.empty())
            {
                return true;
            }
            if (heap.empty() != other.heap.empty())
            {
                return false;
            }
            return heap.front() == other.heap.front();
        }

        // compare two iterators by their heap
        bool operator!=(const heapIterator &other) const
        {
            return !(*this == other);
        }

        // get the pointer to the front of the heap
        Node<T> *operator->() { return heap.front(); }

        // get the value of the front of the heap
        T operator*() const { return heap.front()->get_value(); }

        // move to the next node by popping the top node from the heap and sorting the heap again
        heapIterator<T> &operator++()
        {
            if (!heap.empty())
            {
                pop_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b)
                            { return a->get_value() > b->get_value(); });
                heap.pop_back();
            }
            return *this;
        }
};

#endif // ITERATOR_HPP