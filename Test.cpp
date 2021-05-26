#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "doctest.h"
#include "BinaryTree.hpp"

using namespace std;
using namespace ariel;

void simpleTree(BinaryTree<int>& t){
    t.add_root(1);
    t.add_left(2,1);
    t.add_right(3,1);
    t.add_root(10);
    t.add_left(20,10);
    t.add_right(30,10);
    t.add_root(100);
    t.add_left(1,100);
    t.add_right(10,100);

}  

TEST_CASE("Simple init"){
    BinaryTree<int> t;
    t.add_root(1);
    auto head = t.begin();
    CHECK_EQ(*head,1);
}

TEST_CASE("Inorder"){
    BinaryTree<int> tree;
    simpleTree(tree);
    for (const auto& val: tree){
        CHECK(val==1);
    }
    auto it = tree.begin_inorder();
    it++;
    CHECK(*it == 2 );
    it++;
    CHECK(*it == 1 );
    it++;
    CHECK(*it == 3 );
    it++;
    CHECK(*it == 100);
    it++;
    CHECK(*it == 30);
    it++;
    CHECK(*it == 10);
    it++;
    CHECK(*it == 20);
    
}

TEST_CASE("Preorder"){
    BinaryTree<int> tree;
    simpleTree(tree);
    auto it = tree.begin_preorder();
    it++;
    CHECK(*it == 100);
    it++;
    CHECK(*it == 1);
    it++;
    CHECK(*it == 2);
    it++;
    CHECK(*it == 3);
    it++;
    CHECK(*it == 10);
    it++;
    CHECK(*it == 20);
    it++;
    CHECK(*it == 30);
}

TEST_CASE("Postorder"){

    BinaryTree<int> tree;
    simpleTree(tree);
    auto it = tree.begin_postorder();
    it++;
    CHECK(*it == 2);
    it++;
    CHECK(*it == 3);
    it++;
    CHECK(*it == 1);
    it++;
    CHECK(*it == 20);
    it++;
    CHECK(*it == 30);
    it++;
    CHECK(*it == 10);
    it++;
    CHECK(*it == 100);
}





