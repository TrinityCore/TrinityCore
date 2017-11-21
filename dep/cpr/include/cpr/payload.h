#ifndef CPR_PAYLOAD_H
#define CPR_PAYLOAD_H

#include <cstdint>
#include <initializer_list>
#include <memory>
#include <string>

#include "cpr/defines.h"

namespace cpr {

struct Pair {
    template <typename KeyType, typename ValueType,
              typename std::enable_if<!std::is_integral<ValueType>::value, bool>::type = true>
    Pair(KeyType&& p_key, ValueType&& p_value)
            : key{CPR_FWD(p_key)}, value{CPR_FWD(p_value)} {}
    template <typename KeyType>
    Pair(KeyType&& p_key, const std::int32_t& p_value)
            : key{CPR_FWD(p_key)}, value{std::to_string(p_value)} {}

    std::string key;
    std::string value;
};

class Payload {
  public:
    template <class It>
    Payload(const It begin, const It end) {
        for (It pair = begin; pair != end; ++pair) {
            AddPair(*pair);
        }
    }
    Payload(const std::initializer_list<Pair>& pairs);

    void AddPair(const Pair& pair);

    std::string content;
};

} // namespace cpr

#endif
