#include <iostream>

// if constexpr可以实现短路逻辑
template <int cur = 0, int... In>
constexpr bool has_one() {
    if constexpr (sizeof...(In) == 0) {
        return false;
    } else if constexpr (cur == 1) {
        return true;
    } else {
        return has_one<In...>();
    }
}

template <bool cur, typename TNext>
constexpr bool AndValue = false;

template <typename TNext>
constexpr bool AndValue<true, TNext> = TNext::value;

template <bool cur, typename TNext>
constexpr bool OrValue = true;

template <typename TNext>
constexpr bool OrValue<false, TNext> = TNext::value;

// has_one1非短路，has_one2短路
// 不确定，无法验证，因为编译结果看不到实例化了哪些类
template <int... In>
constexpr bool has_one1 = false;

template <int cur, int... In>
constexpr bool has_one1<cur, In...> = cur == 1 || has_one1<In...>;

template <int... In>
struct has_one2 {
    constexpr static bool value = false;
};

template <int cur, int... In>
struct has_one2<cur, In...> {
    constexpr static bool value = OrValue<cur == 1, has_one2<In...>>;
};

int main() {
    std::cout << std::boolalpha << has_one<0, 1, 2, 3, 4, 5>() << '\n';        // true
    std::cout << std::boolalpha << has_one<0, 2, 3, 4, 5>() << '\n';           // false
    std::cout << std::boolalpha << has_one1<0, 1, 2, 3, 4, 5> << '\n';         // true
    std::cout << std::boolalpha << has_one1<0, 2, 3, 4, 5> << '\n';            // false
    std::cout << std::boolalpha << has_one2<0, 1, 2, 3, 4, 5>::value << '\n';  // true
    std::cout << std::boolalpha << has_one2<0, 2, 3, 4, 5>::value << '\n';     // false
    return 0;
}