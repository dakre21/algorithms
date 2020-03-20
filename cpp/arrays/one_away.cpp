#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <assert.h>

using namespace std;

bool isOneAway(string one, string two) {
    int diff = abs(int(one.length()) - int(two.length()));
    if (diff > 1) {
        return false;
    }

    vector<char> one_chars(one.begin(), one.end());
    vector<char> two_chars(two.begin(), two.end());
    if (int(one.length()) > int(two.length())) {
        one.push_back(0);
    } else if (int(two.length()) > int(one.length())) {
        two.push_back(0);
    }

    bool replacement = true;
    for (size_t i = 0; i < one.size(); i++) {
        if (one_chars[i] == two_chars[i]) {
            continue;
        } else if (replacement) {
            replacement = false;
        } else {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    assert(true == isOneAway("abba", "abb"));
    assert(true == isOneAway("test", "tess"));
    assert(false == isOneAway("blah", "blahhhh"));
    assert(true == isOneAway("boob", "boobs"));
    return 0;
}
