// Test of Simplex Class: Allows for compile time n-length dimensional storage of a given type
// Based on source: https://www.fluentcpp.com/2018/11/02/variable-number-compile-time/
// Goal is to store the hash of any given class in this type and to have static checks against it later
#include <tuple>
#include <vector>
#include <utility>


namespace Boots
{
    template<int k> struct Hash32 {uint32_t hash};

    template<size_t n>
    class Hash32Storage
    {
    public:
        template<int m>
        std::vector<Hash32<m>>& getHashes()
        {
            return std::get<m - 1>(_storage);
        }
    private:
        template<size_t... ms>
        using StorageImpl = std::tuple<std::vector<Hash32<ms>>...>;

        template <size_t... ms>
        static StorageImpl<(1 + ms...)> make_storage(std::index_sequence<ms...>)
        {
            return StorageImpl<(1 + ms)...>{};
        }

        using Storage = decltype(make_storage(std::make_index_sequence<n>{}));

        Storage _storage;
    };
}