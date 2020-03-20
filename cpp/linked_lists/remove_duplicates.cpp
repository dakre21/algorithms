#include <iostream>
#include <list>
#include <unordered_map>


void remove_duplicates(std::list<int>& input) {
    std::unordered_map<int, int> history;
    std::list<int>::iterator it = input.begin();
    while (it != input.end()) {
        auto map_it = history.find(*it);
        bool erase = false;
        if (history.end() != map_it) {
            erase = true;
            auto tmp = it;
            it++;
            input.erase(tmp);
        } else {
            history[*it] = 1;
        }
        if (not erase) {
            it++;
        }
    }
}

void printList(const std::list<int>& input) {
    for (auto& it : input) {
        std::cout << it << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::list<int> my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_back(3);
    my_list.push_back(4);
    my_list.push_back(5);
    my_list.push_back(5);

    std::cout << "Original" << std::endl;
    printList(my_list);
    remove_duplicates(my_list);
    std::cout << "Modified" << std::endl;
    printList(my_list);

    return 0;
}
