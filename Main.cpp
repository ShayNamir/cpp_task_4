// ID: 207192246
// Mail: ShayNamir@gmail.com

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tree.hpp"
#include "Node.hpp"
#include "Complex.hpp"

using namespace std;

int main()
{
    // Create a 3-ary tree that contains integers.
    Tree<int, 3> three_Tree;
    
    // Create the root node with the value 1 and add it to the tree.
    auto root_three_Tree = make_unique<Node<int>>(1);
    three_Tree.add_root(move(root_three_Tree));

    // Create additional nodes with integer values
    auto child1 = make_unique<Node<int>>(2);
    auto child2 = make_unique<Node<int>>(3);
    auto child3 = make_unique<Node<int>>(4);
    auto child4 = make_unique<Node<int>>(5);
    auto child5 = make_unique<Node<int>>(6);
    auto child6 = make_unique<Node<int>>(7);
    auto child7 = make_unique<Node<int>>(8);
    auto child8 = make_unique<Node<int>>(9);
    auto child9 = make_unique<Node<int>>(10);

    // Add sub-nodes to the tree in a specific order
    three_Tree.add_sub_node(*three_Tree.get_root(), move(child1));
    three_Tree.add_sub_node(*three_Tree.get_root(), move(child2));
    three_Tree.add_sub_node(*three_Tree.get_root(), move(child3));
    three_Tree.add_sub_node(*three_Tree.get_root()->get_children()[0], move(child4));
    three_Tree.add_sub_node(*three_Tree.get_root()->get_children()[0], move(child5));
    three_Tree.add_sub_node(*three_Tree.get_root()->get_children()[1], move(child6));
    three_Tree.add_sub_node(*three_Tree.get_root()->get_children()[1], move(child7));
    three_Tree.add_sub_node(*three_Tree.get_root()->get_children()[2], move(child8));
    three_Tree.add_sub_node(*three_Tree.get_root()->get_children()[2], move(child9));

    // Draw the tree
    three_Tree.drawTree();

    // the tree should look like:
    /*
     *       root = 1
     *     /       |       \
     *     2       3       4
     *   /  \    /  \    /  \
     *  5    6  7    8  9   10
     */

    // *****************************************************************************************************************

    // Create a 5-ary tree that contains Complex numbers.
    Tree<Complex, 5> five_Tree_Complex; 

    // Create the root node with the value (1.1, 2.2) and add it to the tree.
    auto root__Five_Complex = make_unique<Node<Complex>>(Complex(1.5, 1.75));

    // Add the root node to the tree
    five_Tree_Complex.add_root(move(root__Five_Complex));
     
    // Create additional nodes with complex numbers
    auto n1 = make_unique<Node<Complex>>(Complex(3.5, 4.75));
    auto n2 = make_unique<Node<Complex>>(Complex(1.3, 2.5));
    auto n3 = make_unique<Node<Complex>>(Complex(7.5, 8.75));
    auto n4 = make_unique<Node<Complex>>(Complex(1.1, 2.2));
    auto n5 = make_unique<Node<Complex>>(Complex(9.5, 10.75));
    auto n6 = make_unique<Node<Complex>>(Complex(1.1, 2.2));
    auto n7 = make_unique<Node<Complex>>(Complex(22.5, 23.75));
    auto n8 = make_unique<Node<Complex>>(Complex(13.1, 12.2));

    // Add sub-nodes to the tree in a specific order
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root(), move(n1));
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root(), move(n2));
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root(), move(n3));
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root(), move(n4));
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root(), move(n5));
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root()->get_children()[0], move(n6));
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root()->get_children()[0], move(n7));
    five_Tree_Complex.add_sub_node(*five_Tree_Complex.get_root()->get_children()[1], move(n8));

    // Draw the tree
    five_Tree_Complex.drawTree();

    // the tree should look like:
    /*
     *       root = (1.5, 1.75)
     *     /       |       \       |       \
     *  (3.5, 4.75) (1.3, 2.5) (7.5, 8.75) (1.1, 2.2) (9.5, 10.75)
     *   /  \    /  \    /  \    /  \    /  \
     * (1.1, 2.2) (22.5, 23.75) (13.1, 12.2)
     */
    // *****************************************************************************************************************

    // Create a tree that contains integers. The default number of children is 2.
    Tree<int> default_Tree;

    // Create the root node with the value 1 and add it to the tree.
    auto root_default_Tree = make_unique<Node<int>>(1);

    // Add the root node to the tree
    default_Tree.add_root(move(root_default_Tree));

    // Create additional nodes with integer values
    auto child10 = make_unique<Node<int>>(2);
    auto child11 = make_unique<Node<int>>(3);
    auto child12 = make_unique<Node<int>>(4);
    auto child13 = make_unique<Node<int>>(5);
    auto child14 = make_unique<Node<int>>(6);
    auto child15 = make_unique<Node<int>>(7);
    auto child16 = make_unique<Node<int>>(8);
    
    // Add sub-nodes to the tree in a specific order
    default_Tree.add_sub_node(*default_Tree.get_root(), move(child10));
    default_Tree.add_sub_node(*default_Tree.get_root(), move(child11));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[0], move(child12));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[0], move(child13));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[1], move(child14));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[1], move(child15));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[1]->get_children()[0], move(child16));

    // Draw the tree
    default_Tree.drawTree(); 

    // the tree should look like:
    /*
     *       root = 1
     *     /       |       
     *     2       3       
     *   /  \    /  \    
     *  4    5  6    7
     *           /
     *          8
     */

    // Print the tree using different iterators

    cout<<endl; 
    cout << " default_Tree: " << endl;

    //PreOrder: 1, 2, 4, 5, 3, 6, 8, 7
    cout << "PreOrder: ";
    for (auto node = default_Tree.begin_pre_order(); node != default_Tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;
    
    //PostOrder: 4, 5, 2, 8, 6, 7, 3, 1
    cout << "PostOrder: ";
    for (auto node = default_Tree.begin_post_order(); node != default_Tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    //InOrder: 4, 2, 5, 1, 6, 3, 7, 8
    cout << "InOrder: ";
    for (auto node = default_Tree.begin_in_order(); node != default_Tree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;

    //BFS: 1, 2, 3, 4, 5, 6, 7, 8
    cout << "BFS: ";
    for (auto node = default_Tree.begin_bfs(); node != default_Tree.end_bfs(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    //DFS: 1, 2, 4, 5, 3, 6, 8, 7
    cout << "DFS: ";
    for (auto node = default_Tree.begin_dfs(); node != default_Tree.end_dfs(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;

    //Heap Iterator: 1, 2, 3, 4, 5, 6, 7, 8
    cout << "Heap Iterator: ";
    for (auto node = default_Tree.begin_heap(); node != default_Tree.end_heap(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    // *****************************************************************************************************************

   // Create a tree that contains doubles with 3 children.
    Tree<double, 3> three_Tree_Double;

    // Create the root node with the value 1.1 and add it to the tree.
    auto root_three_Tree_Double = make_unique<Node<double>>(1.1);

    // Add the root node to the tree
    three_Tree_Double.add_root(move(root_three_Tree_Double));

    // Create additional nodes with double values
    auto n1_d = make_unique<Node<double>>(1.2);
    auto n2_d = make_unique<Node<double>>(1.3);
    auto n3_d = make_unique<Node<double>>(1.4);
    auto n4_d = make_unique<Node<double>>(1.5);
    auto n5_d = make_unique<Node<double>>(1.6);

    // Add sub-nodes to the tree in a specific order
    three_Tree_Double.add_sub_node(*three_Tree_Double.get_root(), move(n1_d));
    three_Tree_Double.add_sub_node(*three_Tree_Double.get_root(), move(n2_d));
    three_Tree_Double.add_sub_node(*three_Tree_Double.get_root(), move(n3_d));
    three_Tree_Double.add_sub_node(*three_Tree_Double.get_root()->get_children()[0], move(n4_d));
    three_Tree_Double.add_sub_node(*three_Tree_Double.get_root()->get_children()[1], move(n5_d));

    // Draw the tree
    three_Tree_Double.drawTree(); 

    // the tree should look like:
    /*
     *       root = 1.1
     *     /       |       \
     *   1.2      1.3      1.4
     *   /  \       \
     *  1.5  1.6
     */

    // Print the tree using different iterators

    cout<<endl;
    cout << " three_Tree_Double: " << endl;

    //PreOrder: 1.1, 1.2, 1.5, 1.6, 1.3, 1.4,
    cout << "PreOrder: ";
    for (auto node = three_Tree_Double.begin_pre_order(); node != three_Tree_Double.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;
    
    //PostOrder: 1.5, 1.6, 1.2, 1.3, 1.4, 1.1
    cout << "PostOrder: ";

    for (auto node = three_Tree_Double.begin_post_order(); node != three_Tree_Double.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;

    //InOrder: 1.5, 1.2, 1.6, 1.1, 1.3, 1.4,
    cout << "InOrder: ";
    for (auto node = three_Tree_Double.begin_in_order(); node != three_Tree_Double.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";

    } 
    cout << endl;

    //BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6,
    cout << "BFS: ";
    for (auto node = three_Tree_Double.begin_bfs(); node != three_Tree_Double.end_bfs(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;

    //DFS: 1.1, 1.2, 1.5, 1.6, 1.3, 1.4,
    cout << "DFS: ";
    for (auto node = three_Tree_Double.begin_dfs(); node != three_Tree_Double.end_dfs(); ++node)
    {
        cout << *node << ", ";
    } 
    cout << endl;                                                                                                                                                                                                                                            

    //Heap Iterator: 1.1, 1.2, 1.5, 1.6, 1.3, 1.4,
    cout << "Heap Iterator: ";
    for (auto node = three_Tree_Double.begin_heap(); node != three_Tree_Double.end_heap(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    // *****************************************************************************************************************

    // Create a tree that contains strings with 3 children.
    Tree<string, 3> three_Tree_str;

    // Create the root node with the value "root" and add it to the tree.
    auto root_three_Tree_str = make_unique<Node<string>>("root");

    // Add the root node to the tree
    three_Tree_str.add_root(move(root_three_Tree_str));

    // Create additional nodes with string values
    auto child1_str = make_unique<Node<string>>("child1");
    auto child2_str = make_unique<Node<string>>("child2");
    auto child3_str = make_unique<Node<string>>("child3");
    auto child4_str = make_unique<Node<string>>("child4");
    auto child5_str = make_unique<Node<string>>("child5");
    
    // Add sub-nodes to the tree in a specific order
    three_Tree_str.add_sub_node(*three_Tree_str.get_root(), move(child1_str));
    three_Tree_str.add_sub_node(*three_Tree_str.get_root(), move(child2_str));
    three_Tree_str.add_sub_node(*three_Tree_str.get_root(), move(child3_str));
    three_Tree_str.add_sub_node(*three_Tree_str.get_root()->get_children()[0], move(child4_str));
    three_Tree_str.add_sub_node(*three_Tree_str.get_root()->get_children()[1], move(child5_str));

    // Draw the tree
    three_Tree_str.drawTree();

    // the tree should look like:
    /*
     *       root = "root"
        *     /       |       \
        *  "child1" "child2" "child3"
        *  /  \
        * "child4" "child5"
        * 
        */
    
    // Print the tree using different iterators

    cout<<endl;
    cout << " three_Tree_str: " << endl;

    //PreOrder: root, child1, child4, child5, child2, child3,
    cout << "PreOrder: ";
    for (auto node = three_Tree_str.begin_pre_order(); node != three_Tree_str.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;

    //PostOrder: child4, child5, child1, child2, child3, root
    cout << "PostOrder: ";
    for (auto node = three_Tree_str.begin_post_order(); node != three_Tree_str.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;

    //InOrder: child4, child1, child5, root, child2, child3,
    cout << "InOrder: ";
    for (auto node = three_Tree_str.begin_in_order(); node != three_Tree_str.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";

    } 
    cout << endl;

    //BFS: root, child1, child2, child3, child4, child5,
    cout << "BFS: ";
    for (auto node = three_Tree_str.begin_bfs(); node != three_Tree_str.end_bfs(); ++node)
    {
        cout << *node << ", ";
    } 
    cout << endl;

    //DFS: root, child1, child4, child5, child2, child3,
    cout << "DFS: ";
    for (auto node = three_Tree_str.begin_dfs(); node != three_Tree_str.end_dfs(); ++node)
    {
        cout << node->get_value() << ", ";
    } 
    cout << endl;

    //Heap Iterator: root, child1, child4, child5, child2, child3,
    cout << "Heap Iterator: ";
    for (auto node = three_Tree_str.begin_heap(); node != three_Tree_str.end_heap(); ++node)
    {
        cout << node->get_value() << ", ";
    }
    cout << endl;

    return 0;
}
