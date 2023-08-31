#include <type_traits>
#include <iostream>
using namespace std;

// template <typename... T>
// void Println(T... t)
// {
//     size_t size = sizeof...(t);
//     ((--size ? (::std::cout << t << ", ") : (::std::cout << t << ::std::endl)), ...);
// }

template <typename T, typename... U>
void Println(T t, U... u)
{
    if constexpr (sizeof...(U) == 0)
    {
        cout << t << endl;
    }
    else // 必须要有 else 不然会报错
    {
        cout << t << ", ";
        Println(u...);
    }
}

template <typename T>
constexpr int Size = sizeof(T); 

template <typename... T>
struct Cont;

int main()
{
    Println(1, 3.14, "hello", '@');
}