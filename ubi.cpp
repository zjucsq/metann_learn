// template <int...>
// class IntArray;

// template <int a, int... b>
// class IntArray<a, b...> {
//     constexpr static int first = a;
//     constexpr static int last = IntArray<b...>::last;
//     constexpr static bool p = first == last;
//     using tail = IntArray<b...>;
// };

// template <int a>
// class IntArray<a> {
//     constexpr static int first = a;
//     constexpr static int last = a;
// };

// template <typename>
// class Palindrome;

// template <int... b>
// class Palindrome<IntArray<b...>> {
//     constexpr static bool check = IntArray<b...>::first == IntArray<b...>::last;
// };

template <int... n>
class IntArray {
   public:
    constexpr static int nums[] = {n...};
    constexpr static int len = sizeof...(n);
    template <int idx>
    constexpr static bool check() {
        if constexpr (idx == len) {
            return true;
        } else if constexpr (nums[idx] != nums[len - idx - 1]) {
            return false;
        } else {
            return check<idx + 1>();
        }
    }
    constexpr static bool res = check<0>();
};

template <typename>
class Palindrome;

template <int... b>
class Palindrome<IntArray<b...>> {
   public:
    constexpr static bool check = IntArray<b...>::res;
};

int main() {
    static_assert(Palindrome<IntArray<1, 2, 3>>::check == false);
    static_assert(Palindrome<IntArray<1, 2, 1>>::check == true);
    return 0;
}