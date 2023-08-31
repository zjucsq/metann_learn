#include <iostream>
#include <type_traits>

// 参考https://zhuanlan.zhihu.com/p/413531474
template <typename T>
class has_type {
   private:
    typedef char Yes;
    typedef struct {
        char arr[2];
    } No;

    template <typename C>
    static Yes test(typename C::type *);

    template <typename C>
    static No test(...);

   public:
    static const bool value = sizeof(test<T>(nullptr)) == sizeof(Yes);
};

// template <typename T, typename = void>
// struct has_type : std::false_type {};

// template <typename T>
// struct has_type<T, std::enable_if_t<std::is_same_v<typename T::type, typename T::type>>> : std::true_type {};

// template <typename T, typename = void>
// struct has_type : std::false_type {};

// template <typename T>
// struct has_type<T, std::void_t<typename T::type>> : std::true_type {};

template <typename T>
bool fun(T t) {
    return has_type<T>::value;
}

struct A {};
struct B {
    using type = int;
};
class C {
    using type = int;
};

int main() {
    A a;
    B b;
    C c;
    std::cout << has_type<int>::value << has_type<double>::value << has_type<A>::value << has_type<B>::value
              << has_type<B *>::value << has_type<C>::value << std::endl;
    std::cout << fun(1) << fun(1.1) << fun(a) << fun(b) << fun(&b) << fun(c) << std::endl;
}