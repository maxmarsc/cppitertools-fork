#include <cppitertools/zip.hpp>

#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<int> ivec{1, 4, 9, 16, 25, 36};
    std::vector<std::string> svec{"hello", "good day", "goodbye"};

    // zip terminates on the shortest sequence, and is variadic
    std::cout << "zipping a vector of ints and a vector of strings\n";
    for (auto&& [i, s] : iter::zip(ivec, svec)) {
        std::cout << '(' << i << ", " << s << ")\n";
    }
}

