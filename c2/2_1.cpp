#include <iostream>
#include <type_traits>
#include <vector>

template <typename TInCont, template <typename> typename F, template <typename...> typename TOutCont>
struct Transform1_;

template <template <typename> typename TInCont, typename... TInputs, template <typename> typename F,
          template <typename...> typename TOutCont>
struct Transform1_<TInCont<TInputs...>, F, TOutCont> {
    using type = TOutCont<typename F<TInputs>::type...>;
};

template <typename TInCont, template <typename> typename F, template <typename...> typename TOutCont>
using Transform1 = typename Transform1_<TInCont, F, TOutCont>::type;

int main() { return 0; }