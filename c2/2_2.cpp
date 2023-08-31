#include <iostream>

template <typename TFirstSet, typename TSecondSet>
struct IsEqual_;

int main() {
    std::cout << std::boolalpha << has_one<0, 1, 2, 3, 4, 5>() << '\n';  // true
    std::cout << std::boolalpha << has_one<0, 2, 3, 4, 5>() << '\n';     // false
    return 0;
}