#include <cppitertools/combinations.hpp>
#include <cppitertools/combinations_with_replacement.hpp>
#include <cppitertools/permutations.hpp>
#include <cppitertools/product.hpp>
#include <cppitertools/powerset.hpp>

#include <vector>
#include <string>
#include <iostream>

int main() {
    const std::vector<int> v1 = {1,2,3,4,5};

    std::cout << "combinations({1,2,3,4,5}, 3}:\n";
    for (auto&& ns : iter::combinations(v1,3)) {
        std::cout << "{ ";
        for (auto&& j : ns ) {
            std::cout << j << ' ';
        }
        std::cout << "}\n";
    }



    // allows elements to be used repeatedly
    std::cout << "combinations_with_replacement({1, 2}, 4):\n";
    std::vector<int> v2 = {1,2};
    for (auto&& ns : iter::combinations_with_replacement(v2, 4)) {
        std::cout << "{ ";
        for (auto&& j : ns ) {
            std::cout << j << ' ';
        }
        std::cout << "}\n";
    }

    std::cout << "permutations(\"abc\"):\n";
    std::string s{"abc"};
    for (auto&& cs : iter::permutations(s)) {
        std::cout << "{ ";
        for (auto&& c : cs ) {
            std::cout << c << ' ';
        }
        std::cout << "}\n";
    }

    std::vector<std::string> v3 = {"abc", "def"};
    std::cout << "product of three vectors (int, int, string):\n";
    for (auto&& [a, b, c] : iter::product(v1,v2,v3)) {
        std::cout << "{ " << a << ' ' << b << ' ' << c << " }\n";
    }

    std::cout << "powerset({1,2,3,4,5}):\n";
    for (auto&& ns : iter::powerset(v1)) {
        std::cout << "{ ";
        for (auto&& i : ns ) {
            std::cout << i << ' ';
        }
        std::cout << "}\n";
    }
}
