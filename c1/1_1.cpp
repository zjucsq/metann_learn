#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
constexpr int Size = sizeof(T);

int main() { cout << Size<int> << endl; }