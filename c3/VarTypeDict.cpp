#include <memory>

template <typename... TParameters>
struct VarTypeDict {
    template <typename... TTypes>
    struct Values {
        Values() = default;

        Values(Values &&val) {
            for (size_t i = 0; i < sizeof...(TTypes); ++i) {
                m_tuple[i] = std::move(val.m_tuple[i]);
            }
        }

        template <typename TTag, typename TVal>
        auto Set(TVal &&val) && {
            
        }



        template <typename TTag, typename... TParams>
        void Update(TParams &&...p_params);



       private:
        std::shared_ptr<void> m_tuple[sizeof...(TTypes)];
    };
};