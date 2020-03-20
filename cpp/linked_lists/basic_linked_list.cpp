#include <iostream>
#include <unordered_map>

#include "inc/LinkedList.h"

int main(int argc, char* argv[]) {
    LinkedList<int> list;

    Node<int> one(1);
    Node<int> two(5);
    Node<int> three(10);
    Node<int> four(-5);
    Node<int> five(-5);

    list.addNode(one);
    list.addNode(two);
    list.addNode(three);
    list.addNode(four);
    list.addNode(five);

    list.printList();

    return 0;
}
