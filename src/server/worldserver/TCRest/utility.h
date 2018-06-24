#ifndef SIMPLE_WEB_UTILITY_HPP
#define SIMPLE_WEB_UTILITY_HPP

#include "status_code.h"
#include <atomic>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

namespace SimpleWeb {
  inline bool case_insensitive_equal(const std::string &str1, const std::string &str2) noexcept {
    return str1.size() == str2.size() &&
           std::equal(str1.begin(), str1.end(), str2.begin(), [](char a, char b) {
             return tolower(a) == tolower(b);
           });
  }
  class CaseInsensitiveEqual {
  public:
    bool operator()(const std::string &str1, const std::string &str2) const noexcept {
      return case_insensitive_equal(str1, str2);
    }
  };
  // Based on https://stackoverflow.com/questions/2590677/how-do-i-combine-hash-values-in-c0x/2595226#2595226
  class CaseInsensitiveHash {
  public:
    std::size_t operator()(const std::string &str) const noexcept {
      std::size_t h = 0;
      std::hash<int> hash;
      for(auto c : str)
        h ^= hash(tolower(c)) + 0x9e3779b9 + (h << 6) + (h >> 2);
      return h;
    }
  };

  using CaseInsensitiveMultimap = std::unordered_multimap<std::string, std::string, CaseInsensitiveHash, CaseInsensitiveEqual>;

  /// Percent encoding and decoding
  class Percent {
  public:
    /// Returns percent-encoded string
    static std::string encode(const std::string &value) noexcept {
      static auto hex_chars = "0123456789ABCDEF";

      std::string result;
      result.reserve(value.size()); // Minimum size of result

      for(auto &chr : value) {
        if(!((chr >= '0' && chr <= '9') || (chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || chr == '-' || chr == '.' || chr == '_' || chr == '~'))
          result += std::string("%") + hex_chars[static_cast<unsigned char>(chr) >> 4] + hex_chars[static_cast<unsigned char>(chr) & 15];
        else
          result += chr;
      }

      return result;
    }

    /// Returns percent-decoded string
    static std::string decode(const std::string &value) noexcept {
      std::string result;
      result.reserve(value.size() / 3 + (value.size() % 3)); // Minimum size of result

      for(std::size_t i = 0; i < value.size(); ++i) {
        auto &chr = value[i];
        if(chr == '%' && i + 2 < value.size()) {
          auto hex = value.substr(i + 1, 2);
          auto decoded_chr = static_cast<char>(std::strtol(hex.c_str(), nullptr, 16));
          result += decoded_chr;
          i += 2;
        }
        else if(chr == '+')
          result += ' ';
        else
          result += chr;
      }

      return result;
    }
  };

  /// Query string creation and parsing
  class QueryString {
  public:
    /// Returns query string created from given field names and values
    static std::string create(const CaseInsensitiveMultimap &fields) noexcept {
      std::string result;

      bool first = true;
      for(auto &field : fields) {
        result += (!first ? "&" : "") + field.first + '=' + Percent::encode(field.second);
        first = false;
      }

      return result;
    }

    /// Returns query keys with percent-decoded values.
    static CaseInsensitiveMultimap parse(const std::string &query_string) noexcept {
      CaseInsensitiveMultimap result;

      if(query_string.empty())
        return result;

      std::size_t name_pos = 0;
      auto name_end_pos = std::string::npos;
      auto value_pos = std::string::npos;
      for(std::size_t c = 0; c < query_string.size(); ++c) {
        if(query_string[c] == '&') {
          auto name = query_string.substr(name_pos, (name_end_pos == std::string::npos ? c : name_end_pos) - name_pos);
          if(!name.empty()) {
            auto value = value_pos == std::string::npos ? std::string() : query_string.substr(value_pos, c - value_pos);
            result.emplace(std::move(name), Percent::decode(value));
          }
          name_pos = c + 1;
          name_end_pos = std::string::npos;
          value_pos = std::string::npos;
        }
        else if(query_string[c] == '=') {
          name_end_pos = c;
          value_pos = c + 1;
        }
      }
      if(name_pos < query_string.size()) {
        auto name = query_string.substr(name_pos, name_end_pos - name_pos);
        if(!name.empty()) {
          auto value = value_pos >= query_string.size() ? std::string() : query_string.substr(value_pos);
          result.emplace(std::move(name), Percent::decode(value));
        }
      }

      return result;
    }
  };

  class HttpHeader {
  public:
    /// Parse header fields
    static CaseInsensitiveMultimap parse(std::istream &stream) noexcept {
      CaseInsensitiveMultimap result;
      std::string line;
      getline(stream, line);
      std::size_t param_end;
      while((param_end = line.find(':')) != std::string::npos) {
        std::size_t value_start = param_end + 1;
        while(value_start + 1 < line.size() && line[value_start] == ' ')
          ++value_start;
        if(value_start < line.size())
          result.emplace(line.substr(0, param_end), line.substr(value_start, line.size() - value_start - 1));

        getline(stream, line);
      }
      return result;
    }

    class FieldValue {
    public:
      class SemicolonSeparatedAttributes {
      public:
        /// Parse Set-Cookie or Content-Disposition header field value. Attribute values are percent-decoded.
        static CaseInsensitiveMultimap parse(const std::string &str) {
          CaseInsensitiveMultimap result;

          std::size_t name_start_pos = std::string::npos;
          std::size_t name_end_pos = std::string::npos;
          std::size_t value_start_pos = std::string::npos;
          for(std::size_t c = 0; c < str.size(); ++c) {
            if(name_start_pos == std::string::npos) {
              if(str[c] != ' ' && str[c] != ';')
                name_start_pos = c;
            }
            else {
              if(name_end_pos == std::string::npos) {
                if(str[c] == ';') {
                  result.emplace(str.substr(name_start_pos, c - name_start_pos), std::string());
                  name_start_pos = std::string::npos;
                }
                else if(str[c] == '=')
                  name_end_pos = c;
              }
              else {
                if(value_start_pos == std::string::npos) {
                  if(str[c] == '"' && c + 1 < str.size())
                    value_start_pos = c + 1;
                  else
                    value_start_pos = c;
                }
                else if(str[c] == '"' || str[c] == ';') {
                  result.emplace(str.substr(name_start_pos, name_end_pos - name_start_pos), Percent::decode(str.substr(value_start_pos, c - value_start_pos)));
                  name_start_pos = std::string::npos;
                  name_end_pos = std::string::npos;
                  value_start_pos = std::string::npos;
                }
              }
            }
          }
          if(name_start_pos != std::string::npos) {
            if(name_end_pos == std::string::npos)
              result.emplace(str.substr(name_start_pos), std::string());
            else if(value_start_pos != std::string::npos) {
              if(str.back() == '"')
                result.emplace(str.substr(name_start_pos, name_end_pos - name_start_pos), Percent::decode(str.substr(value_start_pos, str.size() - 1)));
              else
                result.emplace(str.substr(name_start_pos, name_end_pos - name_start_pos), Percent::decode(str.substr(value_start_pos)));
            }
          }

          return result;
        }
      };
    };
  }; // namespace SimpleWeb

  class RequestMessage {
  public:
    /// Parse request line and header fields
    static bool parse(std::istream &stream, std::string &method, std::string &path, std::string &query_string, std::string &version, CaseInsensitiveMultimap &header) noexcept {
      header.clear();
      std::string line;
      getline(stream, line);
      std::size_t method_end;
      if((method_end = line.find(' ')) != std::string::npos) {
        method = line.substr(0, method_end);

        std::size_t query_start = std::string::npos;
        std::size_t path_and_query_string_end = std::string::npos;
        for(std::size_t i = method_end + 1; i < line.size(); ++i) {
          if(line[i] == '?' && (i + 1) < line.size())
            query_start = i + 1;
          else if(line[i] == ' ') {
            path_and_query_string_end = i;
            break;
          }
        }
        if(path_and_query_string_end != std::string::npos) {
          if(query_start != std::string::npos) {
            path = line.substr(method_end + 1, query_start - method_end - 2);
            query_string = line.substr(query_start, path_and_query_string_end - query_start);
          }
          else
            path = line.substr(method_end + 1, path_and_query_string_end - method_end - 1);

          std::size_t protocol_end;
          if((protocol_end = line.find('/', path_and_query_string_end + 1)) != std::string::npos) {
            if(line.compare(path_and_query_string_end + 1, protocol_end - path_and_query_string_end - 1, "HTTP") != 0)
              return false;
            version = line.substr(protocol_end + 1, line.size() - protocol_end - 2);
          }
          else
            return false;

          header = HttpHeader::parse(stream);
        }
        else
          return false;
      }
      else
        return false;
      return true;
    }
  };

  class ResponseMessage {
  public:
    /// Parse status line and header fields
    static bool parse(std::istream &stream, std::string &version, std::string &status_code, CaseInsensitiveMultimap &header) noexcept {
      header.clear();
      std::string line;
      getline(stream, line);
      std::size_t version_end = line.find(' ');
      if(version_end != std::string::npos) {
        if(5 < line.size())
          version = line.substr(5, version_end - 5);
        else
          return false;
        if((version_end + 1) < line.size())
          status_code = line.substr(version_end + 1, line.size() - (version_end + 1) - 1);
        else
          return false;

        header = HttpHeader::parse(stream);
      }
      else
        return false;
      return true;
    }
  };
} // namespace SimpleWeb

#ifdef __SSE2__
#include <emmintrin.h>
namespace SimpleWeb {
  inline void spin_loop_pause() noexcept { _mm_pause(); }
} // namespace SimpleWeb
// TODO: need verification that the following checks are correct:
#elif defined(_MSC_VER) && _MSC_VER >= 1800 && (defined(_M_X64) || defined(_M_IX86))
#include <intrin.h>
namespace SimpleWeb {
  inline void spin_loop_pause() noexcept { _mm_pause(); }
} // namespace SimpleWeb
#else
namespace SimpleWeb {
  inline void spin_loop_pause() noexcept {}
} // namespace SimpleWeb
#endif

namespace SimpleWeb {
  /// Makes it possible to for instance cancel Asio handlers without stopping asio::io_service
  class ScopeRunner {
    /// Scope count that is set to -1 if scopes are to be canceled
    std::atomic<long> count;

  public:
    class SharedLock {
      friend class ScopeRunner;
      std::atomic<long> &count;
      SharedLock(std::atomic<long> &count) noexcept : count(count) {}
      SharedLock &operator=(const SharedLock &) = delete;
      SharedLock(const SharedLock &) = delete;

    public:
      ~SharedLock() noexcept {
        count.fetch_sub(1);
      }
    };

    ScopeRunner() noexcept : count(0) {}

    /// Returns nullptr if scope should be exited, or a shared lock otherwise
    std::unique_ptr<SharedLock> continue_lock() noexcept {
      long expected = count;
      while(expected >= 0 && !count.compare_exchange_weak(expected, expected + 1))
        spin_loop_pause();

      if(expected < 0)
        return nullptr;
      else
        return std::unique_ptr<SharedLock>(new SharedLock(count));
    }

    /// Blocks until all shared locks are released, then prevents future shared locks
    void stop() noexcept {
      long expected = 0;
      while(!count.compare_exchange_weak(expected, -1)) {
        if(expected < 0)
          return;
        expected = 0;
        spin_loop_pause();
      }
    }
  };
} // namespace SimpleWeb

#endif // SIMPLE_WEB_UTILITY_HPP
