#include <iostream>
#include <assert.h>

#include "inc/bst.h"

int main(int argc, char* argv[]) {
    vector<int> arr{ 1, 2, 3, 4, 5, 6, 7 };

    createMinimalBST(arr, 0, arr.size() - 1);

    assert(findNode(3));
    assert(false == findNode(8));

    return 0;
}
