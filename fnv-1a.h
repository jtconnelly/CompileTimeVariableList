#include <string>

// TEMPLATED FNV1 and FNV1a Hash
// Source from https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function

namespace {
    template <typename T>
    constexpr T fnv1(const std::string& s, T prime, T offset)
    {
        T result = offset;
        for (char c : s)
        {
            result *= prime;
            result = result ^ c;
        }
        return result;
    }

    template <typename T>
    constexpr T fnv1a(const std::string& s, T prime, T offset)
    {
        T result = offset;
        for (char c : s)
        {
            result = result ^ c;
            result *= prime;
        }
        return result;
    }
}

constexpr uint32_t fnv1a_32(const std::string& str)
{
    return fnv1a<uint32_t>(str, 0x01000193, 0x811c9dc5);
}

constexpr uint32_t fnv1_32(const std::string& str)
{
    return fnv1<uint32_t>(str, 0x01000193, 0x811c9dc5);
}

constexpr uint64_t fnv1a_64(const std::string& str)
{
    return fnv1a<uint64_t>(str, 0x00000100000001B3, 0xcbf29ce484222325);
}

constexpr uint64_t fnv1_64(const std::string& str)
{
    return fnv1<uint64_t>(str, 0x00000100000001B3, 0xcbf29ce484222325);
}