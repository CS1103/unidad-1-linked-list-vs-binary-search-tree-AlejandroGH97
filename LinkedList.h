//
// Created by alejandro on 4/3/19.
//

#ifndef NODESTRUCT_LINKEDLIST_H
#define NODESTRUCT_LINKEDLIST_H

#include "Location.h"
#include "Node.h"

namespace UTEC {

    class LinkedList {
        Node *head;
        Node *tail;

    public:
        LinkedList();

        bool empty();

        Node *getHead();

        Node *getTail();

        int getSize();

        void print(int pos);

        void add_head(Location location);

        void add_tail(Location location);

        void remove_head();

        void remove_tail();

        void addInPos(int pos, Location location);

        void deleteAll(Node* _head);

        Node* find_id(int position_id);

        ~LinkedList();
    };
}


#endif //NODESTRUCT_LINKEDLIST_H
