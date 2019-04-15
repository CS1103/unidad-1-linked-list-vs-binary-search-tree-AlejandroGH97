//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"
#include "Node.h"

namespace UTEC {

    class BinarySearchTree {
        Node* root;

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Node* current, Location data);
        void clear(Node* _root);
        bool is_empty();
        Node* get_root();
        Node* search(int position_id);
        void print(int position_id);
    };

}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
