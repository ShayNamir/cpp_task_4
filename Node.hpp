// ID: 315233486
// Mail: Eilonashwal30@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <utility> 

using namespace std;

template <typename T> class Node  // a class representing a node in a tree using a generic type T
{
    private:
        T value; // the value of the node 
        vector<Node<T> *> children; // vector of pointers to the children of the node
 
    public:
        // default constructor initializes the node with a default value and no children
        Node(const T &value, const vector<Node<T> *> &children = {}): value(value), children(children) {}

        // move constructor initializes the node with a value and a vector of children (using move semantics)
        Node(const T &value, vector<Node<T> *> &&children): value(value), children(move(children)) {} 

        Node(Node<T> &&) = default; // copy constructor using move semantics

        Node<T> &operator=(Node<T> &&) = default; // operator= using move semantics

        virtual ~Node() = default; // destructor

        void add_child(Node<T> *child) { children.push_back(child); } // add a child to the node

        vector<Node<T> *> get_children() const { return children; } // get the children of the node

        void set_value(const T &new_value) { value = new_value;} // set the value of the node

        const T &get_value() const { return value; } // get the value of the node (const)

        T &get_value() { return value; } // get the value of the node (non-const)

        size_t get_children_size() const { return children.size();} // get the number of children of the node
};

#endif
