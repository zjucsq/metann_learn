#include <type_traits>
#include <iostream>
using namespace std;

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

template <int...> struct list {};



int main()
{
    Println(list<1,2,3>{});
}