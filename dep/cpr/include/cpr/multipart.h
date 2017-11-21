#ifndef CPR_MULTIPART_H
#define CPR_MULTIPART_H

#include <cstdint>
#include <initializer_list>
#include <string>
#include <type_traits>
#include <vector>

#include "cpr/defines.h"

namespace cpr {

struct File {
    template <typename StringType>
    explicit File(StringType&& filepath)
            : filepath{CPR_FWD(filepath)} {}
    std::string filepath;
};

struct Buffer {
    typedef const unsigned char* data_t;

    template <typename Iterator, typename StringType>
    explicit Buffer(Iterator begin, Iterator end, StringType&& filename)
            : data{reinterpret_cast<data_t>(&(*begin))},
              datalen{static_cast<unsigned long>(std::distance(begin, end))},
              filename{CPR_FWD(filename)} {
        is_random_access_iterator(begin, end);
        static_assert(sizeof(*begin) == 1, "only byte buffers can be used");
    }

    template <typename Iterator>
    typename std::enable_if<std::is_same<typename std::iterator_traits<Iterator>::iterator_category,
                                         std::random_access_iterator_tag>::value>::type
    is_random_access_iterator(Iterator /* begin */, Iterator /* end */ ) {}

    data_t data;
    unsigned long datalen;
    std::string filename;
};

struct Part {
    Part(const std::string& name, const std::string& value, const std::string& content_type = {})
            : name{name}, value{value}, content_type{content_type}, is_file{false},
              is_buffer{false} {}
    Part(const std::string& name, const std::int32_t& value, const std::string& content_type = {})
            : name{name}, value{std::to_string(value)}, content_type{content_type}, is_file{false},
              is_buffer{false} {}
    Part(const std::string& name, const File& file, const std::string& content_type = {})
            : name{name}, value{file.filepath}, content_type{content_type}, is_file{true},
              is_buffer{false} {}
    Part(const std::string& name, const Buffer& buffer, const std::string& content_type = {})
            : name{name}, value{buffer.filename}, content_type{content_type}, data{buffer.data},
              datalen{buffer.datalen}, is_file{false}, is_buffer{true} {}

    std::string name;
    std::string value;
    std::string content_type;
    Buffer::data_t data;
    unsigned long datalen;
    bool is_file;
    bool is_buffer;
};

class Multipart {
  public:
    Multipart(const std::initializer_list<Part>& parts);

    std::vector<Part> parts;
};

} // namespace cpr

#endif
