#include <iostream>
#include <assert.h>
#include <list>

#include "inc/bst.h"

list<list<Node*> > createListsFromBST(Node* root) {
    list<list<Node*> > result;
    list<Node*> current;

    if (root != NULL) {
        current.push_back(root);
        while (not current.empty()) {
            result.push_back(current);
            list<Node*> parents = current;
            current.clear();
            auto node = parents.begin();
            for (; node != parents.end(); node++) {
                if ((*node)->left != NULL) {
                    current.push_back((*node)->left);
                }
                if ((*node)->right != NULL) {
                    current.push_back((*node)->right);
                }
            }
        }
    }

    return result;
}

void printListOfLists(const list<list<Node*> >& lists) {
    for (auto it = lists.begin(); it != lists.end(); it++) {
        for (auto next = it->begin(); next != it->end(); next++) {
            cout << (*next)->data << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    vector<int> arr{ 1, 2, 3, 4, 5, 6, 7 };

    createMinimalBST(arr, 0, arr.size() - 1);

    auto lists = createListsFromBST(root);
    printListOfLists(lists);
    assert(3 == lists.size());

    return 0;
}
