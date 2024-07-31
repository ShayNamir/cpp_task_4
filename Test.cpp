// ID: 207192246
// Mail: ShayNamir@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <SFML/Graphics.hpp>
#include "Tree.hpp"
#include "Node.hpp"
#include "Complex.hpp"

using namespace std;

TEST_CASE("build a default_Tree with integers and check the traversals (pre-order, post-order, in-order, BFS, DFS)")
{
    // Create a default default_Tree with integers and maximum 2 children
    Tree<int> default_Tree;

    // Create a root node with value 20
    auto root = make_unique<Node<int>>(10);

    // Add the root node to the default_Tree
    default_Tree.add_root(move(root));

    // Create child nodes 
    auto child1 = make_unique<Node<int>>(20);
    auto child2 = make_unique<Node<int>>(30);
    auto child3 = make_unique<Node<int>>(40);
    auto child4 = make_unique<Node<int>>(50);
    auto child5 = make_unique<Node<int>>(60);
    auto child6 = make_unique<Node<int>>(70);

    // Add the child nodes to the default_Tree on specific ways
    default_Tree.add_sub_node(*default_Tree.get_root(), move(child1));
    default_Tree.add_sub_node(*default_Tree.get_root(), move(child2));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[0], move(child3));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[0], move(child4));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[1], move(child5));
    default_Tree.add_sub_node(*default_Tree.get_root()->get_children()[1], move(child6));

    //the tree should look like this:
    /*
            10
           /  \
          20   30
         /  \ /  \
        40 50 60 70   
    */

    
    SUBCASE("Pre-order Traversal") // Check the pre-order traversal
    {
        vector<int> expected = {1, 2, 4, 5, 3, 6, 7};
        vector<int> actual;

        // Iterate over the tree using pre-order traversal
        for (auto it = default_Tree.begin_pre_order(); it != default_Tree.end_pre_order(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("Post-order Traversal") // Check the post-order traversal
    {
        vector<int> expected = {4, 5, 2, 6, 7, 3, 1};
        vector<int> actual;

        // Iterate over the tree using post-order traversal
        for (auto it = default_Tree.begin_post_order(); it != default_Tree.end_post_order(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("In-order Traversal") // Check the in-order traversal
    {
        vector<int> expected = {4, 2, 5, 1, 6, 3, 7};
        vector<int> actual;

        // Iterate over the tree using in-order traversal
        for (auto it = default_Tree.begin_in_order(); it != default_Tree.end_in_order(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("BFS Traversal") // Check the BFS traversal
    {
        vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
        vector<int> actual;

        // Iterate over the tree using BFS traversal
        for (auto it = default_Tree.begin_bfs(); it != default_Tree.end_bfs(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("DFS Traversal") // Check the DFS traversal
    {
        vector<int> expected = {1, 2, 4, 5, 3, 6, 7};
        vector<int> actual;

        // Iterate over the tree using DFS traversal
        for (auto it = default_Tree.begin_dfs(); it != default_Tree.end_dfs(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }
}

TEST_CASE("build a default_Complex_Tree with Complex numbers and check the traversals (pre-order, post-order, in-order, BFS, DFS)")
{
    // Create a default_Complex_Tree with Complex numbers and maximum 2 children
    Tree<Complex> default_Complex_Tree;

    // Create a root node with value 1 + 2i
    auto root = make_unique<Node<Complex>>(Complex(1, 2));

    // Add the root node to the default_Complex_Tree
    default_Complex_Tree.add_root(move(root));

    // Create child nodes
    auto child1 = make_unique<Node<Complex>>(Complex(3, 4));
    auto child2 = make_unique<Node<Complex>>(Complex(5, 6));
    auto child3 = make_unique<Node<Complex>>(Complex(7, 8));
    auto child4 = make_unique<Node<Complex>>(Complex(9, 10));
    auto child5 = make_unique<Node<Complex>>(Complex(11, 12));
    auto child6 = make_unique<Node<Complex>>(Complex(13, 14));
    
    // Add the child nodes to the default_Complex_Tree on specific ways
    default_Complex_Tree.add_sub_node(*default_Complex_Tree.get_root(), move(child1));
    default_Complex_Tree.add_sub_node(*default_Complex_Tree.get_root(), move(child2));
    default_Complex_Tree.add_sub_node(*default_Complex_Tree.get_root()->get_children()[0], move(child3));
    default_Complex_Tree.add_sub_node(*default_Complex_Tree.get_root()->get_children()[0], move(child4));
    default_Complex_Tree.add_sub_node(*default_Complex_Tree.get_root()->get_children()[1], move(child5));
    default_Complex_Tree.add_sub_node(*default_Complex_Tree.get_root()->get_children()[1], move(child6));

    //the tree should look like this:
    /*
            1 + 2i
           /       \
       3 + 4i     5 + 6i
      /     \     /     \
    7 + 8i 9 + 10i 11 + 12i 13 + 14i
    */

    SUBCASE("In-order Traversal") // Check the in-order traversal
    {
        // The expected in-order traversal
        vector<Complex> expected = {Complex(7, 8), Complex(3, 4), Complex(9, 10), Complex(1, 2), Complex(11, 12), Complex(5, 6), Complex(13, 14)};
        vector<Complex> actual;

        // Iterate over the tree using in-order traversal
        for (auto it = default_Complex_Tree.begin_in_order(); it != default_Complex_Tree.end_in_order(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("Pre-order Traversal") // Check the pre-order traversal
    {
        // The expected pre-order traversal
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(7, 8), Complex(9, 10), Complex(5, 6), Complex(11, 12), Complex(13, 14)};
        vector<Complex> actual;

        // Iterate over the tree using pre-order traversal
        for (auto it = default_Complex_Tree.begin_pre_order(); it != default_Complex_Tree.end_pre_order(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("Post-order Traversal") // Check the post-order traversal
    {
        // The expected post-order traversal
        vector<Complex> expected = {Complex(7, 8), Complex(9, 10), Complex(3, 4), Complex(11, 12), Complex(13, 14), Complex(5, 6), Complex(1, 2)};
        vector<Complex> actual;

        // Iterate over the tree using post-order traversal
        for (auto it = default_Complex_Tree.begin_post_order(); it != default_Complex_Tree.end_post_order(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }
   
    SUBCASE("BFS Traversal") // Check the BFS traversal
    {
        // The expected BFS traversal
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(5, 6), Complex(7, 8), Complex(9, 10), Complex(11, 12), Complex(13, 14)};
        vector<Complex> actual;

        // Iterate over the tree using BFS traversal
        for (auto it = default_Complex_Tree.begin_bfs(); it != default_Complex_Tree.end_bfs(); ++it)
        {
            actual.push_back(it->get_value());
        }
        
        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("DFS Traversal") // Check the DFS traversal
    {
        // The expected DFS traversal  
        vector<Complex> expected = {Complex(1, 2), Complex(3, 4), Complex(7, 8), Complex(9, 10), Complex(5, 6), Complex(11, 12), Complex(13, 14)};
        vector<Complex> actual;

        // Iterate over the tree using DFS traversal
        for (auto it = default_Complex_Tree.begin_dfs(); it != default_Complex_Tree.end_dfs(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }
}

TEST_CASE("build a three_string_Tree with strings and check the traversals (pre-order, post-order, in-order, BFS, DFS)")
{
    // Create a three_string_Tree with strings and maximum 3 children
    Tree<string, 3> three_string_Tree;

    // Create a root node with value "Hello"
    auto root = make_unique<Node<string>>(string("Hello,"));

    // Add the root node to the three_string_Tree
    three_string_Tree.add_root(move(root));

    // Create child nodes
    auto child1 = make_unique<Node<string>>(string("my"));
    auto child2 = make_unique<Node<string>>(string("name"));
    auto child3 = make_unique<Node<string>>(string("is"));
    auto child4 = make_unique<Node<string>>(string("Eilon"));
    auto child5 = make_unique<Node<string>>(string("Ashwal"));
    auto child6 = make_unique<Node<string>>(string("and"));
    auto child7 = make_unique<Node<string>>(string("I"));
    auto child8 = make_unique<Node<string>>(string("am"));
    auto child9 = make_unique<Node<string>>(string("25"));
    auto child10 = make_unique<Node<string>>(string("years"));
    auto child11 = make_unique<Node<string>>(string("old"));
    auto child12 = make_unique<Node<string>>(string("!"));

    // Add the child nodes to the three_string_Tree on specific ways
    three_string_Tree.add_sub_node(*three_string_Tree.get_root(), move(child1));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root(), move(child2));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root(), move(child3));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[0], move(child4));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[0], move(child5));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[0], move(child6));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[1], move(child7));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[1], move(child8));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[1], move(child9));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[2], move(child10));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[2], move(child11));
    three_string_Tree.add_sub_node(*three_string_Tree.get_root()->get_children()[2], move(child12));

    //the tree should look like this:
    /*
                Hello,
           /       |       \
          my     name     is
         /|\     /|\     /|\
    Eilon Ashwal and I am 25 years old !
    */

    // For 3-ary tree, we have only DFS and BFS traversals

    SUBCASE("BFS Traversal") // Check the BFS traversal
    {
        // The expected BFS traversal
        vector<string> expected = {"Hello,", "my", "name", "is", "Eilon", "Ashwal", "and", "I", "am", "25", "years", "old", "!"};
        vector<string> actual;

        // Iterate over the tree using BFS traversal
        for (auto it = three_string_Tree.begin_bfs(); it != three_string_Tree.end_bfs(); ++it)
        {
            actual.push_back(it->get_value());
        }

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

    SUBCASE("DFS Traversal") // Check the DFS traversal
    {
        // The expected DFS traversal
        vector<string> expected = {"Hello,", "my", "Eilon", "Ashwal", "and", "name", "I", "am", "25", "is", "years", "old", "!"};
        vector<string> actual;

        // Iterate over the tree using DFS traversal
        for (auto it = three_string_Tree.begin_dfs(); it != three_string_Tree.end_dfs(); ++it)
        {
            actual.push_back(it->get_value());
        }   

        // Check if the actual traversal is equal to the expected one
        CHECK(actual == expected);
    }

}
