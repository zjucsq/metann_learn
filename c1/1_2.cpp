#include <iostream>
#include <type_traits>
using namespace std;

template <typename T, int a>
constexpr bool same = sizeof(T) == a;

int main() {
    cout << same<int, 4> << endl;
    cout << same<double, 8> << endl;
}