
#include <iostream>

template <size_t...>
constexpr size_t Accumulate = 0;

template <size_t cur, size_t... In>
constexpr size_t Accumulate<cur, In...> = cur + Accumulate<In...>;

template <size_t... In>
size_t acc() {
    return (0 + ... + In);
}

// 对cur设置初始值，这样acc1<>() == acc1<0>()，可以处理输入0个参数的情况
// 添加init，这样可以设置初始值
template <size_t cur = 0, size_t... In>
size_t acc1(size_t init = 0) {
    if constexpr (sizeof...(In) == 0) {
        return cur + init;
    } else {
        return cur + acc1<In...>(init);
    }
}

int main() {
    std::cout << Accumulate<> << Accumulate<1, 2, 3, 4, 5> << std::endl;
    std::cout << acc<>() << acc<1, 2, 3, 4, 5>() << std::endl;
    std::cout << acc1<>(5) << acc1<1, 2, 3, 4, 5>(5) << std::endl;
    return 0;
}