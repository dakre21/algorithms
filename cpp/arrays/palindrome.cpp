#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <assert.h>


bool hasPalindrome(std::string input) {
    std::unordered_map<char, int> table;
    std::vector<char> split(input.begin(), input.end());

    size_t size = input.size();
    for (auto c : input) {
        if (' ' == c) {
            size -= 1;
            continue;
        }
        auto it = table.find(c);
        if (table.end() != it) {
            table[c] += 1;
        } else {
            table[c] = 1;
        }
    }

    int odd_count = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second % 2 == 1) {
            odd_count += 1; 
        }
    }

    if (1 == (size % 2) && odd_count > 1) {
        return false; 
    }

    if (0 == (size % 2) && odd_count > 0) {
        return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    std::string one = "hannah";
    std::string two = "taco cat";
    std::string three = "not a palindrome";

    assert(true == hasPalindrome(one));
    assert(true == hasPalindrome(two));
    assert(false == hasPalindrome(three));

    return 0;
}
