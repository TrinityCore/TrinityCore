/*
 Formatting library for C++

 Copyright (c) 2012 - 2015, Victor Zverovich
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FMT_FORMAT_H_
#define FMT_FORMAT_H_

#include <stdint.h>

#include <cassert>
#include <cmath>
#include <cstddef>  // for std::ptrdiff_t
#include <cstdio>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <string>
#include <sstream>

#if _SECURE_SCL
# include <iterator>
#endif

#ifdef _MSC_VER
# include <intrin.h>  // _BitScanReverse, _BitScanReverse64

namespace fmt {
namespace internal {
# pragma intrinsic(_BitScanReverse)
inline uint32_t clz(uint32_t x) {
  unsigned long r = 0;
  _BitScanReverse(&r, x);
  return 31 - r;
}
# define FMT_BUILTIN_CLZ(n) fmt::internal::clz(n)

# ifdef _WIN64
#  pragma intrinsic(_BitScanReverse64)
# endif

inline uint32_t clzll(uint64_t x) {
  unsigned long r = 0;
# ifdef _WIN64
  _BitScanReverse64(&r, x);
# else
  // Scan the high 32 bits.
  if (_BitScanReverse(&r, static_cast<uint32_t>(x >> 32)))
    return 63 - (r + 32);

  // Scan the low 32 bits.
  _BitScanReverse(&r, static_cast<uint32_t>(x));
# endif
  return 63 - r;
}
# define FMT_BUILTIN_CLZLL(n) fmt::internal::clzll(n)
}
}
#endif

#ifdef __GNUC__
# define FMT_GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
# define FMT_GCC_EXTENSION __extension__
# if FMT_GCC_VERSION >= 406
#  pragma GCC diagnostic push
// Disable the warning about "long long" which is sometimes reported even
// when using __extension__.
#  pragma GCC diagnostic ignored "-Wlong-long"
// Disable the warning about declaration shadowing because it affects too
// many valid cases.
#  pragma GCC diagnostic ignored "-Wshadow"
# endif
# if __cplusplus >= 201103L || defined __GXX_EXPERIMENTAL_CXX0X__
#  define FMT_HAS_GXX_CXX11 1
# endif
#else
# define FMT_GCC_EXTENSION
#endif

#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wdocumentation"
#endif

#ifdef __GNUC_LIBSTD__
# define FMT_GNUC_LIBSTD_VERSION (__GNUC_LIBSTD__ * 100 + __GNUC_LIBSTD_MINOR__)
#endif

#ifdef __has_feature
# define FMT_HAS_FEATURE(x) __has_feature(x)
#else
# define FMT_HAS_FEATURE(x) 0
#endif

#ifdef __has_builtin
# define FMT_HAS_BUILTIN(x) __has_builtin(x)
#else
# define FMT_HAS_BUILTIN(x) 0
#endif

#ifdef __has_cpp_attribute
# define FMT_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
# define FMT_HAS_CPP_ATTRIBUTE(x) 0
#endif

#ifndef FMT_USE_VARIADIC_TEMPLATES
// Variadic templates are available in GCC since version 4.4
// (http://gcc.gnu.org/projects/cxx0x.html) and in Visual C++
// since version 2013.
# define FMT_USE_VARIADIC_TEMPLATES \
   (FMT_HAS_FEATURE(cxx_variadic_templates) || \
       (FMT_GCC_VERSION >= 404 && FMT_HAS_GXX_CXX11) || _MSC_VER >= 1800)
#endif

#ifndef FMT_USE_RVALUE_REFERENCES
// Don't use rvalue references when compiling with clang and an old libstdc++
// as the latter doesn't provide std::move.
# if defined(FMT_GNUC_LIBSTD_VERSION) && FMT_GNUC_LIBSTD_VERSION <= 402
#  define FMT_USE_RVALUE_REFERENCES 0
# else
#  define FMT_USE_RVALUE_REFERENCES \
    (FMT_HAS_FEATURE(cxx_rvalue_references) || \
        (FMT_GCC_VERSION >= 403 && FMT_HAS_GXX_CXX11) || _MSC_VER >= 1600)
# endif
#endif

#if FMT_USE_RVALUE_REFERENCES
# include <utility>  // for std::move
#endif

// Define FMT_USE_NOEXCEPT to make C++ Format use noexcept (C++11 feature).
#if FMT_USE_NOEXCEPT || FMT_HAS_FEATURE(cxx_noexcept) || \
  (FMT_GCC_VERSION >= 408 && FMT_HAS_GXX_CXX11)
# define FMT_NOEXCEPT noexcept
#else
# define FMT_NOEXCEPT throw()
#endif

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#if FMT_USE_DELETED_FUNCTIONS || FMT_HAS_FEATURE(cxx_deleted_functions) || \
  (FMT_GCC_VERSION >= 404 && FMT_HAS_GXX_CXX11) || _MSC_VER >= 1800
# define FMT_DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&) = delete; \
    TypeName& operator=(const TypeName&) = delete
#else
# define FMT_DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&); \
    TypeName& operator=(const TypeName&)
#endif

namespace fmt {

// Fix the warning about long long on older versions of GCC
// that don't support the diagnostic pragma.
FMT_GCC_EXTENSION typedef long long LongLong;
FMT_GCC_EXTENSION typedef unsigned long long ULongLong;

#if FMT_USE_RVALUE_REFERENCES
using std::move;
#endif

template <typename Char>
class BasicWriter;

typedef BasicWriter<char> Writer;
typedef BasicWriter<wchar_t> WWriter;

template <typename Char>
class BasicFormatter;

template <typename Char, typename T>
void format(BasicFormatter<Char> &f, const Char *&format_str, const T &value);

/**
  \rst
  A string reference. It can be constructed from a C string or
  ``std::string``.
  
  You can use one of the following typedefs for common character types:

  +------------+-------------------------+
  | Type       | Definition              |
  +============+=========================+
  | StringRef  | BasicStringRef<char>    |
  +------------+-------------------------+
  | WStringRef | BasicStringRef<wchar_t> |
  +------------+-------------------------+

  This class is most useful as a parameter type to allow passing
  different types of strings to a function, for example::

    template <typename... Args>
    std::string format(StringRef format_str, const Args & ... args);

    format("{}", 42);
    format(std::string("{}"), 42);
  \endrst
 */
template <typename Char>
class BasicStringRef {
 private:
  const Char *data_;
  std::size_t size_;

 public:
  /**
    Constructs a string reference object from a C string and a size.
   */
  BasicStringRef(const Char *s, std::size_t size) : data_(s), size_(size) {}

  /**
    Constructs a string reference object from a C string computing
    the size with ``std::char_traits<Char>::length``.
   */
  BasicStringRef(const Char *s)
    : data_(s), size_(std::char_traits<Char>::length(s)) {}

  /**
    Constructs a string reference from an `std::string` object.
   */
  BasicStringRef(const std::basic_string<Char> &s)
  : data_(s.c_str()), size_(s.size()) {}

  /**
    Converts a string reference to an `std::string` object.
   */
  operator std::basic_string<Char>() const {
    return std::basic_string<Char>(data_, size());
  }

  /**
    Returns the pointer to a C string.
   */
  const Char *c_str() const { return data_; }

  /**
    Returns the string size.
   */
  std::size_t size() const { return size_; }

  friend bool operator==(BasicStringRef lhs, BasicStringRef rhs) {
    return lhs.data_ == rhs.data_;
  }
  friend bool operator!=(BasicStringRef lhs, BasicStringRef rhs) {
    return lhs.data_ != rhs.data_;
  }
};

typedef BasicStringRef<char> StringRef;
typedef BasicStringRef<wchar_t> WStringRef;

/**
  A formatting error such as invalid format string.
*/
class FormatError : public std::runtime_error {
 public:
  explicit FormatError(StringRef message)
  : std::runtime_error(message.c_str()) {}
};

namespace internal {
// The number of characters to store in the MemoryBuffer object itself
// to avoid dynamic memory allocation.
enum { INLINE_BUFFER_SIZE = 500 };

#if _SECURE_SCL
// Use checked iterator to avoid warnings on MSVC.
template <typename T>
inline stdext::checked_array_iterator<T*> make_ptr(T *ptr, std::size_t size) {
  return stdext::checked_array_iterator<T*>(ptr, size);
}
#else
template <typename T>
inline T *make_ptr(T *ptr, std::size_t) { return ptr; }
#endif
}  // namespace internal

/** A buffer supporting a subset of ``std::vector``'s operations. */
template <typename T>
class Buffer {
 private:
  FMT_DISALLOW_COPY_AND_ASSIGN(Buffer);

 protected:
  T *ptr_;
  std::size_t size_;
  std::size_t capacity_;

  Buffer(T *ptr = 0, std::size_t capacity = 0)
    : ptr_(ptr), size_(0), capacity_(capacity) {}

  /**
    Increases the buffer capacity to hold at least *size* elements updating
    ``ptr_`` and ``capacity_``.
   */
  virtual void grow(std::size_t size) = 0;

 public:
  virtual ~Buffer() {}

  /** Returns the size of this buffer. */
  std::size_t size() const { return size_; }

  /** Returns the capacity of this buffer. */
  std::size_t capacity() const { return capacity_; }

  /**
    Resizes the buffer. If T is a POD type new elements may not be initialized.
   */
  void resize(std::size_t new_size) {
    if (new_size > capacity_)
      grow(new_size);
    size_ = new_size;
  }

  /** Reserves space to store at least *capacity* elements. */
  void reserve(std::size_t capacity) {
    if (capacity > capacity_)
      grow(capacity);
  }

  void clear() FMT_NOEXCEPT { size_ = 0; }

  void push_back(const T &value) {
    if (size_ == capacity_)
      grow(size_ + 1);
    ptr_[size_++] = value;
  }

  /** Appends data to the end of the buffer. */
  void append(const T *begin, const T *end);

  T &operator[](std::size_t index) { return ptr_[index]; }
  const T &operator[](std::size_t index) const { return ptr_[index]; }
};

template <typename T>
void Buffer<T>::append(const T *begin, const T *end) {
  std::ptrdiff_t num_elements = end - begin;
  if (size_ + num_elements > capacity_)
    grow(size_ + num_elements);
  std::copy(begin, end, internal::make_ptr(ptr_, capacity_) + size_);
  size_ += num_elements;
}

namespace internal {

// A memory buffer for POD types with the first SIZE elements stored in
// the object itself.
template <typename T, std::size_t SIZE, typename Allocator = std::allocator<T> >
class MemoryBuffer : private Allocator, public Buffer<T> {
 private:
  T data_[SIZE];

  // Free memory allocated by the buffer.
  void free() {
    if (this->ptr_ != data_) this->deallocate(this->ptr_, this->capacity_);
  }

 protected:
  void grow(std::size_t size);

 public:
  explicit MemoryBuffer(const Allocator &alloc = Allocator())
      : Allocator(alloc), Buffer<T>(data_, SIZE) {}
  ~MemoryBuffer() { free(); }

#if FMT_USE_RVALUE_REFERENCES
 private:
  // Move data from other to this buffer.
  void move(MemoryBuffer &other) {
    Allocator &this_alloc = *this, &other_alloc = other;
    this_alloc = std::move(other_alloc);
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    if (other.ptr_ == other.data_) {
      this->ptr_ = data_;
      std::copy(other.data_,
                other.data_ + this->size_, make_ptr(data_, this->capacity_));
    } else {
      this->ptr_ = other.ptr_;
      // Set pointer to the inline array so that delete is not called
      // when freeing.
      other.ptr_ = other.data_;
    }
  }

 public:
  MemoryBuffer(MemoryBuffer &&other) {
    move(other);
  }

  MemoryBuffer &operator=(MemoryBuffer &&other) {
    assert(this != &other);
    free();
    move(other);
    return *this;
  }
#endif

  // Returns a copy of the allocator associated with this buffer.
  Allocator get_allocator() const { return *this; }
};

template <typename T, std::size_t SIZE, typename Allocator>
void MemoryBuffer<T, SIZE, Allocator>::grow(std::size_t size) {
  std::size_t new_capacity =
      (std::max)(size, this->capacity_ + this->capacity_ / 2);
  T *new_ptr = this->allocate(new_capacity);
  // The following code doesn't throw, so the raw pointer above doesn't leak.
  std::copy(this->ptr_,
            this->ptr_ + this->size_, make_ptr(new_ptr, new_capacity));
  std::size_t old_capacity = this->capacity_;
  T *old_ptr = this->ptr_;
  this->capacity_ = new_capacity;
  this->ptr_ = new_ptr;
  // deallocate may throw (at least in principle), but it doesn't matter since
  // the buffer already uses the new storage and will deallocate it in case
  // of exception.
  if (old_ptr != data_)
    this->deallocate(old_ptr, old_capacity);
}

// A fixed-size buffer.
template <typename Char>
class FixedBuffer : public fmt::Buffer<Char> {
 public:
  FixedBuffer(Char *array, std::size_t size) : fmt::Buffer<Char>(array, size) {}

 protected:
  void grow(std::size_t size);
};

#ifndef _MSC_VER
// Portable version of signbit.
inline int getsign(double x) {
  // When compiled in C++11 mode signbit is no longer a macro but a function
  // defined in namespace std and the macro is undefined.
# ifdef signbit
  return signbit(x);
# else
  return std::signbit(x);
# endif
}

// Portable version of isinf.
# ifdef isinf
inline int isinfinity(double x) { return isinf(x); }
inline int isinfinity(long double x) { return isinf(x); }
# else
inline int isinfinity(double x) { return std::isinf(x); }
inline int isinfinity(long double x) { return std::isinf(x); }
# endif
#else
inline int getsign(double value) {
  if (value < 0) return 1;
  if (value == value) return 0;
  int dec = 0, sign = 0;
  char buffer[2];  // The buffer size must be >= 2 or _ecvt_s will fail.
  _ecvt_s(buffer, sizeof(buffer), value, 0, &dec, &sign);
  return sign;
}
inline int isinfinity(double x) { return !_finite(x); }
inline int isinfinity(long double x) { return !_finite(static_cast<double>(x)); }
#endif

template <typename Char>
class BasicCharTraits {
 public:
#if _SECURE_SCL
  typedef stdext::checked_array_iterator<Char*> CharPtr;
#else
  typedef Char *CharPtr;
#endif
};

template <typename Char>
class CharTraits;

template <>
class CharTraits<char> : public BasicCharTraits<char> {
 private:
  // Conversion from wchar_t to char is not allowed.
  static char convert(wchar_t);

public:
  static char convert(char value) { return value; }

  // Formats a floating-point number.
  template <typename T>
  static int format_float(char *buffer, std::size_t size,
      const char *format, unsigned width, int precision, T value);
};

template <>
class CharTraits<wchar_t> : public BasicCharTraits<wchar_t> {
 public:
  static wchar_t convert(char value) { return value; }
  static wchar_t convert(wchar_t value) { return value; }

  template <typename T>
  static int format_float(wchar_t *buffer, std::size_t size,
      const wchar_t *format, unsigned width, int precision, T value);
};

// Checks if a number is negative - used to avoid warnings.
template <bool IsSigned>
struct SignChecker {
  template <typename T>
  static bool is_negative(T value) { return value < 0; }
};

template <>
struct SignChecker<false> {
  template <typename T>
  static bool is_negative(T) { return false; }
};

// Returns true if value is negative, false otherwise.
// Same as (value < 0) but doesn't produce warnings if T is an unsigned type.
template <typename T>
inline bool is_negative(T value) {
  return SignChecker<std::numeric_limits<T>::is_signed>::is_negative(value);
}

// Selects uint32_t if FitsIn32Bits is true, uint64_t otherwise.
template <bool FitsIn32Bits>
struct TypeSelector { typedef uint32_t Type; };

template <>
struct TypeSelector<false> { typedef uint64_t Type; };

template <typename T>
struct IntTraits {
  // Smallest of uint32_t and uint64_t that is large enough to represent
  // all values of T.
  typedef typename
    TypeSelector<std::numeric_limits<T>::digits <= 32>::Type MainType;
};

// MakeUnsigned<T>::Type gives an unsigned type corresponding to integer type T.
template <typename T>
struct MakeUnsigned { typedef T Type; };

#define FMT_SPECIALIZE_MAKE_UNSIGNED(T, U) \
  template <> \
  struct MakeUnsigned<T> { typedef U Type; }

FMT_SPECIALIZE_MAKE_UNSIGNED(char, unsigned char);
FMT_SPECIALIZE_MAKE_UNSIGNED(signed char, unsigned char);
FMT_SPECIALIZE_MAKE_UNSIGNED(short, unsigned short);
FMT_SPECIALIZE_MAKE_UNSIGNED(int, unsigned);
FMT_SPECIALIZE_MAKE_UNSIGNED(long, unsigned long);
FMT_SPECIALIZE_MAKE_UNSIGNED(LongLong, ULongLong);

void report_unknown_type(char code, const char *type);

// Static data is placed in this class template to allow header-only
// configuration.
template <typename T = void>
struct BasicData {
  static const uint32_t POWERS_OF_10_32[];
  static const uint64_t POWERS_OF_10_64[];
  static const char DIGITS[];
};

typedef BasicData<> Data;

#if FMT_GCC_VERSION >= 400 || FMT_HAS_BUILTIN(__builtin_clz)
# define FMT_BUILTIN_CLZ(n) __builtin_clz(n)
#endif

#if FMT_GCC_VERSION >= 400 || FMT_HAS_BUILTIN(__builtin_clzll)
# define FMT_BUILTIN_CLZLL(n) __builtin_clzll(n)
#endif

#ifdef FMT_BUILTIN_CLZLL
// Returns the number of decimal digits in n. Leading zeros are not counted
// except for n == 0 in which case count_digits returns 1.
inline unsigned count_digits(uint64_t n) {
  // Based on http://graphics.stanford.edu/~seander/bithacks.html#IntegerLog10
  // and the benchmark https://github.com/localvoid/cxx-benchmark-count-digits.
  unsigned t = (64 - FMT_BUILTIN_CLZLL(n | 1)) * 1233 >> 12;
  return t - (n < Data::POWERS_OF_10_64[t]) + 1;
}
#else
// Fallback version of count_digits used when __builtin_clz is not available.
inline unsigned count_digits(uint64_t n) {
  unsigned count = 1;
  for (;;) {
    // Integer division is slow so do it for a group of four digits instead
    // of for every digit. The idea comes from the talk by Alexandrescu
    // "Three Optimization Tips for C++". See speed-test for a comparison.
    if (n < 10) return count;
    if (n < 100) return count + 1;
    if (n < 1000) return count + 2;
    if (n < 10000) return count + 3;
    n /= 10000u;
    count += 4;
  }
}
#endif

#ifdef FMT_BUILTIN_CLZ
// Optional version of count_digits for better performance on 32-bit platforms.
inline unsigned count_digits(uint32_t n) {
  uint32_t t = (32 - FMT_BUILTIN_CLZ(n | 1)) * 1233 >> 12;
  return t - (n < Data::POWERS_OF_10_32[t]) + 1;
}
#endif

// Formats a decimal unsigned integer value writing into buffer.
template <typename UInt, typename Char>
inline void format_decimal(Char *buffer, UInt value, unsigned num_digits) {
  --num_digits;
  while (value >= 100) {
    // Integer division is slow so do it for a group of two digits instead
    // of for every digit. The idea comes from the talk by Alexandrescu
    // "Three Optimization Tips for C++". See speed-test for a comparison.
    unsigned index = (value % 100) * 2;
    value /= 100;
    buffer[num_digits] = Data::DIGITS[index + 1];
    buffer[num_digits - 1] = Data::DIGITS[index];
    num_digits -= 2;
  }
  if (value < 10) {
    *buffer = static_cast<char>('0' + value);
    return;
  }
  unsigned index = static_cast<unsigned>(value * 2);
  buffer[1] = Data::DIGITS[index + 1];
  buffer[0] = Data::DIGITS[index];
}

#ifdef _WIN32
// A converter from UTF-8 to UTF-16.
// It is only provided for Windows since other systems support UTF-8 natively.
class UTF8ToUTF16 {
 private:
  MemoryBuffer<wchar_t, INLINE_BUFFER_SIZE> buffer_;

 public:
  explicit UTF8ToUTF16(StringRef s);
  operator WStringRef() const { return WStringRef(&buffer_[0], size()); }
  size_t size() const { return buffer_.size() - 1; }
  const wchar_t *c_str() const { return &buffer_[0]; }
  std::wstring str() const { return std::wstring(&buffer_[0], size()); }
};

// A converter from UTF-16 to UTF-8.
// It is only provided for Windows since other systems support UTF-8 natively.
class UTF16ToUTF8 {
 private:
  MemoryBuffer<char, INLINE_BUFFER_SIZE> buffer_;

 public:
  UTF16ToUTF8() {}
  explicit UTF16ToUTF8(WStringRef s);
  operator StringRef() const { return StringRef(&buffer_[0], size()); }
  size_t size() const { return buffer_.size() - 1; }
  const char *c_str() const { return &buffer_[0]; }
  std::string str() const { return std::string(&buffer_[0], size()); }

  // Performs conversion returning a system error code instead of
  // throwing exception on conversion error. This method may still throw
  // in case of memory allocation error.
  int convert(WStringRef s);
};
#endif

void format_system_error(fmt::Writer &out, int error_code,
                         fmt::StringRef message) FMT_NOEXCEPT;

#ifdef _WIN32
void format_windows_error(fmt::Writer &out, int error_code,
                          fmt::StringRef message) FMT_NOEXCEPT;
#endif

// Computes max(N, 1) at compile time. It is used to avoid errors about
// allocating an array of 0 size.
template <unsigned N>
struct NonZero {
  enum { VALUE = N > 0 ? N : 1 };
};

// A formatting argument. It is a POD type to allow storage in
// internal::MemoryBuffer.
struct Arg {
  template <typename Char>
  struct StringValue {
    const Char *value;
    std::size_t size;
  };

  typedef void (*FormatFunc)(
      void *formatter, const void *arg, void *format_str_ptr);

  struct CustomValue {
    const void *value;
    FormatFunc format;
  };

  union {
    int int_value;
    unsigned uint_value;
    LongLong long_long_value;
    ULongLong ulong_long_value;
    double double_value;
    long double long_double_value;
    const void *pointer;
    StringValue<char> string;
    StringValue<signed char> sstring;
    StringValue<unsigned char> ustring;
    StringValue<wchar_t> wstring;
    CustomValue custom;
  };

  enum Type {
    NONE,
    // Integer types should go first,
    INT, UINT, LONG_LONG, ULONG_LONG, CHAR, LAST_INTEGER_TYPE = CHAR,
    // followed by floating-point types.
    DOUBLE, LONG_DOUBLE, LAST_NUMERIC_TYPE = LONG_DOUBLE,
    CSTRING, STRING, WSTRING, POINTER, CUSTOM
  };
  Type type;
};

template <typename T = void>
struct None {};

// A helper class template to enable or disable overloads taking wide
// characters and strings in MakeValue.
template <typename T, typename Char>
struct WCharHelper {
  typedef None<T> Supported;
  typedef T Unsupported;
};

template <typename T>
struct WCharHelper<T, wchar_t> {
  typedef T Supported;
  typedef None<T> Unsupported;
};

template <typename T>
class IsConvertibleToInt {
 private:
  typedef char yes[1];
  typedef char no[2];

  static const T &get();

  static yes &check(fmt::ULongLong);
  static no &check(...);
  
 public:
  enum { value = (sizeof(check(get())) == sizeof(yes)) };
};

#define FMT_CONVERTIBLE_TO_INT(Type) \
  template <> \
  class IsConvertibleToInt<Type> { \
   public: \
    enum { value = 1 }; \
  }

// Silence warnings about convering float to int.
FMT_CONVERTIBLE_TO_INT(float);
FMT_CONVERTIBLE_TO_INT(double);
FMT_CONVERTIBLE_TO_INT(long double);

template<bool B, class T = void>
struct EnableIf {};

template<class T>
struct EnableIf<true, T> { typedef T type; };

// A helper function to suppress bogus "conditional expression is constant"
// warnings.
inline bool check(bool value) { return value; }

// Makes an Arg object from any type.
template <typename Char>
class MakeValue : public Arg {
 private:
  // The following two methods are private to disallow formatting of
  // arbitrary pointers. If you want to output a pointer cast it to
  // "void *" or "const void *". In particular, this forbids formatting
  // of "[const] volatile char *" which is printed as bool by iostreams.
  // Do not implement!
  template <typename T>
  MakeValue(const T *value);
  template <typename T>
  MakeValue(T *value);

  // The following methods are private to disallow formatting of wide
  // characters and strings into narrow strings as in
  //   fmt::format("{}", L"test");
  // To fix this, use a wide format string: fmt::format(L"{}", L"test").
  MakeValue(typename WCharHelper<wchar_t, Char>::Unsupported);
  MakeValue(typename WCharHelper<wchar_t *, Char>::Unsupported);
  MakeValue(typename WCharHelper<const wchar_t *, Char>::Unsupported);
  MakeValue(typename WCharHelper<const std::wstring &, Char>::Unsupported);
  MakeValue(typename WCharHelper<WStringRef, Char>::Unsupported);

  void set_string(StringRef str) {
    string.value = str.c_str();
    string.size = str.size();
  }

  void set_string(WStringRef str) {
    wstring.value = str.c_str();
    wstring.size = str.size();
  }

  // Formats an argument of a custom type, such as a user-defined class.
  template <typename T>
  static void format_custom_arg(
      void *formatter, const void *arg, void *format_str_ptr) {
    format(*static_cast<BasicFormatter<Char>*>(formatter),
           *static_cast<const Char**>(format_str_ptr),
           *static_cast<const T*>(arg));
  }

 public:
  MakeValue() {}

#define FMT_MAKE_VALUE(Type, field, TYPE) \
  MakeValue(Type value) { field = value; } \
  static uint64_t type(Type) { return Arg::TYPE; }

  FMT_MAKE_VALUE(bool, int_value, INT)
  FMT_MAKE_VALUE(short, int_value, INT)
  FMT_MAKE_VALUE(unsigned short, uint_value, UINT)
  FMT_MAKE_VALUE(int, int_value, INT)
  FMT_MAKE_VALUE(unsigned, uint_value, UINT)

  MakeValue(long value) {
    // To minimize the number of types we need to deal with, long is
    // translated either to int or to long long depending on its size.
    if (check(sizeof(long) == sizeof(int)))
      int_value = static_cast<int>(value);
    else
      long_long_value = value;
  }
  static uint64_t type(long) {
    return sizeof(long) == sizeof(int) ? Arg::INT : Arg::LONG_LONG;
  }

  MakeValue(unsigned long value) {
    if (check(sizeof(unsigned long) == sizeof(unsigned)))
      uint_value = static_cast<unsigned>(value);
    else
      ulong_long_value = value;
  }
  static uint64_t type(unsigned long) {
    return sizeof(unsigned long) == sizeof(unsigned) ?
          Arg::UINT : Arg::ULONG_LONG;
  }

  FMT_MAKE_VALUE(LongLong, long_long_value, LONG_LONG)
  FMT_MAKE_VALUE(ULongLong, ulong_long_value, ULONG_LONG)
  FMT_MAKE_VALUE(float, double_value, DOUBLE)
  FMT_MAKE_VALUE(double, double_value, DOUBLE)
  FMT_MAKE_VALUE(long double, long_double_value, LONG_DOUBLE)
  FMT_MAKE_VALUE(signed char, int_value, CHAR)
  FMT_MAKE_VALUE(unsigned char, int_value, CHAR)
  FMT_MAKE_VALUE(char, int_value, CHAR)

  MakeValue(typename WCharHelper<wchar_t, Char>::Supported value) {
    int_value = value;
  }
  static uint64_t type(wchar_t) { return Arg::CHAR; }

#define FMT_MAKE_STR_VALUE(Type, TYPE) \
  MakeValue(Type value) { set_string(value); } \
  static uint64_t type(Type) { return Arg::TYPE; }

  FMT_MAKE_VALUE(char *, string.value, CSTRING)
  FMT_MAKE_VALUE(const char *, string.value, CSTRING)
  FMT_MAKE_VALUE(const signed char *, sstring.value, CSTRING)
  FMT_MAKE_VALUE(const unsigned char *, ustring.value, CSTRING)
  FMT_MAKE_STR_VALUE(const std::string &, STRING)
  FMT_MAKE_STR_VALUE(StringRef, STRING)

#define FMT_MAKE_WSTR_VALUE(Type, TYPE) \
  MakeValue(typename WCharHelper<Type, Char>::Supported value) { \
    set_string(value); \
  } \
  static uint64_t type(Type) { return Arg::TYPE; }

  FMT_MAKE_WSTR_VALUE(wchar_t *, WSTRING)
  FMT_MAKE_WSTR_VALUE(const wchar_t *, WSTRING)
  FMT_MAKE_WSTR_VALUE(const std::wstring &, WSTRING)
  FMT_MAKE_WSTR_VALUE(WStringRef, WSTRING)

  FMT_MAKE_VALUE(void *, pointer, POINTER)
  FMT_MAKE_VALUE(const void *, pointer, POINTER)

  template <typename T>
  MakeValue(const T &value,
            typename EnableIf<!IsConvertibleToInt<T>::value, int>::type = 0) {
    custom.value = &value;
    custom.format = &format_custom_arg<T>;
  }

  template <typename T>
  MakeValue(const T &value,
            typename EnableIf<IsConvertibleToInt<T>::value, int>::type = 0) {
    int_value = value;
  }

  template <typename T>
  static uint64_t type(const T &) {
    return IsConvertibleToInt<T>::value ? Arg::INT : Arg::CUSTOM;
  }
};

#define FMT_DISPATCH(call) static_cast<Impl*>(this)->call

// An argument visitor.
// To use ArgVisitor define a subclass that implements some or all of the
// visit methods with the same signatures as the methods in ArgVisitor,
// for example, visit_int(int).
// Specify the subclass name as the Impl template parameter. Then calling
// ArgVisitor::visit for some argument will dispatch to a visit method
// specific to the argument type. For example, if the argument type is
// double then visit_double(double) method of a subclass will be called.
// If the subclass doesn't contain a method with this signature, then
// a corresponding method of ArgVisitor will be called.
//
// Example:
//  class MyArgVisitor : public ArgVisitor<MyArgVisitor, void> {
//   public:
//    void visit_int(int value) { print("{}", value); }
//    void visit_double(double value) { print("{}", value ); }
//  };
//
// ArgVisitor uses the curiously recurring template pattern:
// http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
template <typename Impl, typename Result>
class ArgVisitor {
 public:
  void report_unhandled_arg() {}

  Result visit_unhandled_arg() {
    FMT_DISPATCH(report_unhandled_arg());
    return Result();
  }

  Result visit_int(int value) {
    return FMT_DISPATCH(visit_any_int(value));
  }
  Result visit_long_long(LongLong value) {
    return FMT_DISPATCH(visit_any_int(value));
  }
  Result visit_uint(unsigned value) {
    return FMT_DISPATCH(visit_any_int(value));
  }
  Result visit_ulong_long(ULongLong value) {
    return FMT_DISPATCH(visit_any_int(value));
  }
  Result visit_char(int value) {
    return FMT_DISPATCH(visit_any_int(value));
  }
  template <typename T>
  Result visit_any_int(T) {
    return FMT_DISPATCH(visit_unhandled_arg());
  }

  Result visit_double(double value) {
    return FMT_DISPATCH(visit_any_double(value));
  }
  Result visit_long_double(long double value) {
    return FMT_DISPATCH(visit_any_double(value));
  }
  template <typename T>
  Result visit_any_double(T) {
    return FMT_DISPATCH(visit_unhandled_arg());
  }

  Result visit_string(Arg::StringValue<char>) {
    return FMT_DISPATCH(visit_unhandled_arg());
  }
  Result visit_wstring(Arg::StringValue<wchar_t>) {
    return FMT_DISPATCH(visit_unhandled_arg());
  }
  Result visit_pointer(const void *) {
    return FMT_DISPATCH(visit_unhandled_arg());
  }
  Result visit_custom(Arg::CustomValue) {
    return FMT_DISPATCH(visit_unhandled_arg());
  }

  Result visit(const Arg &arg) {
    switch (arg.type) {
    default:
      assert(false);
      return Result();
    case Arg::INT:
      return FMT_DISPATCH(visit_int(arg.int_value));
    case Arg::UINT:
      return FMT_DISPATCH(visit_uint(arg.uint_value));
    case Arg::LONG_LONG:
      return FMT_DISPATCH(visit_long_long(arg.long_long_value));
    case Arg::ULONG_LONG:
      return FMT_DISPATCH(visit_ulong_long(arg.ulong_long_value));
    case Arg::DOUBLE:
      return FMT_DISPATCH(visit_double(arg.double_value));
    case Arg::LONG_DOUBLE:
      return FMT_DISPATCH(visit_long_double(arg.long_double_value));
    case Arg::CHAR:
      return FMT_DISPATCH(visit_char(arg.int_value));
    case Arg::CSTRING: {
      Arg::StringValue<char> str = arg.string;
      str.size = 0;
      return FMT_DISPATCH(visit_string(str));
    }
    case Arg::STRING:
      return FMT_DISPATCH(visit_string(arg.string));
    case Arg::WSTRING:
      return FMT_DISPATCH(visit_wstring(arg.wstring));
    case Arg::POINTER:
      return FMT_DISPATCH(visit_pointer(arg.pointer));
    case Arg::CUSTOM:
      return FMT_DISPATCH(visit_custom(arg.custom));
    }
  }
};

class RuntimeError : public std::runtime_error {
 protected:
  RuntimeError() : std::runtime_error("") {}
};

template <typename Char>
class ArgFormatter;
}  // namespace internal

/** An argument list. */
class ArgList {
 private:
  // To reduce compiled code size per formatting function call, types of first
  // MAX_PACKED_ARGS arguments are passed in the types_ field.
  uint64_t types_;
  const internal::Arg *args_;

  internal::Arg::Type type(unsigned index) const {
    unsigned shift = index * 4;
    uint64_t mask = 0xf;
    return static_cast<internal::Arg::Type>(
          (types_ & (mask << shift)) >> shift);
  }

 public:
  // Maximum number of arguments with packed types.
  enum { MAX_PACKED_ARGS = 16 };

  ArgList() : types_(0) {}
  ArgList(ULongLong types, const internal::Arg *args)
  : types_(types), args_(args) {}

  /** Returns the argument at specified index. */
  internal::Arg operator[](unsigned index) const {
    using internal::Arg;
    Arg arg;
    if (index < MAX_PACKED_ARGS) {
      Arg::Type arg_type = type(index);
      if (arg_type != Arg::NONE)
        arg = args_[index];
      arg.type = arg_type;
      return arg;
    }
    if (type(MAX_PACKED_ARGS - 1) == Arg::NONE) {
      arg.type = Arg::NONE;
      return arg;
    }
    for (unsigned i = MAX_PACKED_ARGS; i <= index; ++i) {
      if (args_[i].type == Arg::NONE)
        return args_[i];
    }
    return args_[index];
  }
};

struct FormatSpec;

namespace internal {

class FormatterBase {
 private:
  ArgList args_;
  int next_arg_index_;

  // Returns the argument with specified index.
  Arg do_get_arg(unsigned arg_index, const char *&error);

 protected:
  void set_args(const ArgList &args) {
    args_ = args;
    next_arg_index_ = 0;
  }

  // Returns the next argument.
  Arg next_arg(const char *&error);

  // Checks if manual indexing is used and returns the argument with
  // specified index.
  Arg get_arg(unsigned arg_index, const char *&error);

  template <typename Char>
  void write(BasicWriter<Char> &w, const Char *start, const Char *end) {
    if (start != end)
      w << BasicStringRef<Char>(start, end - start);
  }
};

// A printf formatter.
template <typename Char>
class PrintfFormatter : private FormatterBase {
 private:
  void parse_flags(FormatSpec &spec, const Char *&s);

  // Returns the argument with specified index or, if arg_index is equal
  // to the maximum unsigned value, the next argument.
  Arg get_arg(const Char *s,
      unsigned arg_index = (std::numeric_limits<unsigned>::max)());

  // Parses argument index, flags and width and returns the argument index.
  unsigned parse_header(const Char *&s, FormatSpec &spec);

 public:
  void format(BasicWriter<Char> &writer,
    BasicStringRef<Char> format_str, const ArgList &args);
};
}  // namespace internal

// A formatter.
template <typename Char>
class BasicFormatter : private internal::FormatterBase {
 private:
  BasicWriter<Char> &writer_;
  const Char *start_;
  
  FMT_DISALLOW_COPY_AND_ASSIGN(BasicFormatter);

  // Parses argument index and returns corresponding argument.
  internal::Arg parse_arg_index(const Char *&s);

 public:
  explicit BasicFormatter(BasicWriter<Char> &w) : writer_(w) {}

  BasicWriter<Char> &writer() { return writer_; }

  void format(BasicStringRef<Char> format_str, const ArgList &args);

  const Char *format(const Char *&format_str, const internal::Arg &arg);
};

enum Alignment {
  ALIGN_DEFAULT, ALIGN_LEFT, ALIGN_RIGHT, ALIGN_CENTER, ALIGN_NUMERIC
};

// Flags.
enum {
  SIGN_FLAG = 1, PLUS_FLAG = 2, MINUS_FLAG = 4, HASH_FLAG = 8,
  CHAR_FLAG = 0x10  // Argument has char type - used in error reporting.
};

// An empty format specifier.
struct EmptySpec {};

// A type specifier.
template <char TYPE>
struct TypeSpec : EmptySpec {
  Alignment align() const { return ALIGN_DEFAULT; }
  unsigned width() const { return 0; }
  int precision() const { return -1; }
  bool flag(unsigned) const { return false; }
  char type() const { return TYPE; }
  char fill() const { return ' '; }
};

// A width specifier.
struct WidthSpec {
  unsigned width_;
  // Fill is always wchar_t and cast to char if necessary to avoid having
  // two specialization of WidthSpec and its subclasses.
  wchar_t fill_;

  WidthSpec(unsigned width, wchar_t fill) : width_(width), fill_(fill) {}

  unsigned width() const { return width_; }
  wchar_t fill() const { return fill_; }
};

// An alignment specifier.
struct AlignSpec : WidthSpec {
  Alignment align_;

  AlignSpec(unsigned width, wchar_t fill, Alignment align = ALIGN_DEFAULT)
  : WidthSpec(width, fill), align_(align) {}

  Alignment align() const { return align_; }

  int precision() const { return -1; }
};

// An alignment and type specifier.
template <char TYPE>
struct AlignTypeSpec : AlignSpec {
  AlignTypeSpec(unsigned width, wchar_t fill) : AlignSpec(width, fill) {}

  bool flag(unsigned) const { return false; }
  char type() const { return TYPE; }
};

// A full format specifier.
struct FormatSpec : AlignSpec {
  unsigned flags_;
  int precision_;
  char type_;

  FormatSpec(
    unsigned width = 0, char type = 0, wchar_t fill = ' ')
  : AlignSpec(width, fill), flags_(0), precision_(-1), type_(type) {}

  bool flag(unsigned f) const { return (flags_ & f) != 0; }
  int precision() const { return precision_; }
  char type() const { return type_; }
};

// An integer format specifier.
template <typename T, typename SpecT = TypeSpec<0>, typename Char = char>
class IntFormatSpec : public SpecT {
 private:
  T value_;

 public:
  IntFormatSpec(T val, const SpecT &spec = SpecT())
  : SpecT(spec), value_(val) {}

  T value() const { return value_; }
};

// A string format specifier.
template <typename T>
class StrFormatSpec : public AlignSpec {
 private:
  const T *str_;

 public:
  StrFormatSpec(const T *str, unsigned width, wchar_t fill)
  : AlignSpec(width, fill), str_(str) {}

  const T *str() const { return str_; }
};

/**
  Returns an integer format specifier to format the value in base 2.
 */
IntFormatSpec<int, TypeSpec<'b'> > bin(int value);

/**
  Returns an integer format specifier to format the value in base 8.
 */
IntFormatSpec<int, TypeSpec<'o'> > oct(int value);

/**
  Returns an integer format specifier to format the value in base 16 using
  lower-case letters for the digits above 9.
 */
IntFormatSpec<int, TypeSpec<'x'> > hex(int value);

/**
  Returns an integer formatter format specifier to format in base 16 using
  upper-case letters for the digits above 9.
 */
IntFormatSpec<int, TypeSpec<'X'> > hexu(int value);

/**
  \rst
  Returns an integer format specifier to pad the formatted argument with the
  fill character to the specified width using the default (right) numeric
  alignment.

  **Example**::

    MemoryWriter out;
    out << pad(hex(0xcafe), 8, '0');
    // out.str() == "0000cafe"

  \endrst
 */
template <char TYPE_CODE, typename Char>
IntFormatSpec<int, AlignTypeSpec<TYPE_CODE>, Char> pad(
    int value, unsigned width, Char fill = ' ');

#define FMT_DEFINE_INT_FORMATTERS(TYPE) \
inline IntFormatSpec<TYPE, TypeSpec<'b'> > bin(TYPE value) { \
  return IntFormatSpec<TYPE, TypeSpec<'b'> >(value, TypeSpec<'b'>()); \
} \
 \
inline IntFormatSpec<TYPE, TypeSpec<'o'> > oct(TYPE value) { \
  return IntFormatSpec<TYPE, TypeSpec<'o'> >(value, TypeSpec<'o'>()); \
} \
 \
inline IntFormatSpec<TYPE, TypeSpec<'x'> > hex(TYPE value) { \
  return IntFormatSpec<TYPE, TypeSpec<'x'> >(value, TypeSpec<'x'>()); \
} \
 \
inline IntFormatSpec<TYPE, TypeSpec<'X'> > hexu(TYPE value) { \
  return IntFormatSpec<TYPE, TypeSpec<'X'> >(value, TypeSpec<'X'>()); \
} \
 \
template <char TYPE_CODE> \
inline IntFormatSpec<TYPE, AlignTypeSpec<TYPE_CODE> > pad( \
    IntFormatSpec<TYPE, TypeSpec<TYPE_CODE> > f, unsigned width) { \
  return IntFormatSpec<TYPE, AlignTypeSpec<TYPE_CODE> >( \
      f.value(), AlignTypeSpec<TYPE_CODE>(width, ' ')); \
} \
 \
/* For compatibility with older compilers we provide two overloads for pad, */ \
/* one that takes a fill character and one that doesn't. In the future this */ \
/* can be replaced with one overload making the template argument Char      */ \
/* default to char (C++11). */ \
template <char TYPE_CODE, typename Char> \
inline IntFormatSpec<TYPE, AlignTypeSpec<TYPE_CODE>, Char> pad( \
    IntFormatSpec<TYPE, TypeSpec<TYPE_CODE>, Char> f, \
    unsigned width, Char fill) { \
  return IntFormatSpec<TYPE, AlignTypeSpec<TYPE_CODE>, Char>( \
      f.value(), AlignTypeSpec<TYPE_CODE>(width, fill)); \
} \
 \
inline IntFormatSpec<TYPE, AlignTypeSpec<0> > pad( \
    TYPE value, unsigned width) { \
  return IntFormatSpec<TYPE, AlignTypeSpec<0> >( \
      value, AlignTypeSpec<0>(width, ' ')); \
} \
 \
template <typename Char> \
inline IntFormatSpec<TYPE, AlignTypeSpec<0>, Char> pad( \
   TYPE value, unsigned width, Char fill) { \
 return IntFormatSpec<TYPE, AlignTypeSpec<0>, Char>( \
     value, AlignTypeSpec<0>(width, fill)); \
}

FMT_DEFINE_INT_FORMATTERS(int)
FMT_DEFINE_INT_FORMATTERS(long)
FMT_DEFINE_INT_FORMATTERS(unsigned)
FMT_DEFINE_INT_FORMATTERS(unsigned long)
FMT_DEFINE_INT_FORMATTERS(LongLong)
FMT_DEFINE_INT_FORMATTERS(ULongLong)

/**
  \rst
  Returns a string formatter that pads the formatted argument with the fill
  character to the specified width using the default (left) string alignment.

  **Example**::

    std::string s = str(MemoryWriter() << pad("abc", 8));
    // s == "abc     "

  \endrst
 */
template <typename Char>
inline StrFormatSpec<Char> pad(
    const Char *str, unsigned width, Char fill = ' ') {
  return StrFormatSpec<Char>(str, width, fill);
}

inline StrFormatSpec<wchar_t> pad(
    const wchar_t *str, unsigned width, char fill = ' ') {
  return StrFormatSpec<wchar_t>(str, width, fill);
}

// Generates a comma-separated list with results of applying f to
// numbers 0..n-1.
# define FMT_GEN(n, f) FMT_GEN##n(f)
# define FMT_GEN1(f)  f(0)
# define FMT_GEN2(f)  FMT_GEN1(f),  f(1)
# define FMT_GEN3(f)  FMT_GEN2(f),  f(2)
# define FMT_GEN4(f)  FMT_GEN3(f),  f(3)
# define FMT_GEN5(f)  FMT_GEN4(f),  f(4)
# define FMT_GEN6(f)  FMT_GEN5(f),  f(5)
# define FMT_GEN7(f)  FMT_GEN6(f),  f(6)
# define FMT_GEN8(f)  FMT_GEN7(f),  f(7)
# define FMT_GEN9(f)  FMT_GEN8(f),  f(8)
# define FMT_GEN10(f) FMT_GEN9(f),  f(9)
# define FMT_GEN11(f) FMT_GEN10(f), f(10)
# define FMT_GEN12(f) FMT_GEN11(f), f(11)
# define FMT_GEN13(f) FMT_GEN12(f), f(12)
# define FMT_GEN14(f) FMT_GEN13(f), f(13)
# define FMT_GEN15(f) FMT_GEN14(f), f(14)

namespace internal {
inline uint64_t make_type() { return 0; }

template <typename T>
inline uint64_t make_type(const T &arg) { return MakeValue<char>::type(arg); }

#if FMT_USE_VARIADIC_TEMPLATES
template <typename Arg, typename... Args>
inline uint64_t make_type(const Arg &first, const Args & ... tail) {
  return make_type(first) | (make_type(tail...) << 4);
}
#else

struct ArgType {
  uint64_t type;

  ArgType() : type(0) {}

  template <typename T>
  ArgType(const T &arg) : type(make_type(arg)) {}
};

# define FMT_ARG_TYPE_DEFAULT(n) ArgType t##n = ArgType()

inline uint64_t make_type(FMT_GEN15(FMT_ARG_TYPE_DEFAULT)) {
  return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) |
      (t4.type << 16) | (t5.type << 20) | (t6.type << 24) | (t7.type << 28) |
      (t8.type << 32) | (t9.type << 36) | (t10.type << 40) | (t11.type << 44) |
      (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
#endif
}  // namespace internal

# define FMT_MAKE_TEMPLATE_ARG(n) typename T##n
# define FMT_MAKE_ARG_TYPE(n) T##n
# define FMT_MAKE_ARG(n) const T##n &v##n
# define FMT_MAKE_REF_char(n) fmt::internal::MakeValue<char>(v##n)
# define FMT_MAKE_REF_wchar_t(n) fmt::internal::MakeValue<wchar_t>(v##n)

#if FMT_USE_VARIADIC_TEMPLATES
// Defines a variadic function returning void.
# define FMT_VARIADIC_VOID(func, arg_type) \
  template <typename... Args> \
  void func(arg_type arg1, const Args & ... args) { \
    const fmt::internal::Arg array[ \
      fmt::internal::NonZero<sizeof...(Args)>::VALUE] = { \
      fmt::internal::MakeValue<Char>(args)... \
    }; \
    func(arg1, ArgList(fmt::internal::make_type(args...), array)); \
  }

// Defines a variadic constructor.
# define FMT_VARIADIC_CTOR(ctor, func, arg0_type, arg1_type) \
  template <typename... Args> \
  ctor(arg0_type arg0, arg1_type arg1, const Args & ... args) { \
    using fmt::internal::MakeValue; \
    const fmt::internal::Arg array[ \
        fmt::internal::NonZero<sizeof...(Args)>::VALUE] = { \
      MakeValue<Char>(args)... \
    }; \
    func(arg0, arg1, ArgList(fmt::internal::make_type(args...), array)); \
  }

#else

# define FMT_MAKE_REF(n) fmt::internal::MakeValue<Char>(v##n)
# define FMT_MAKE_REF2(n) v##n

// Defines a wrapper for a function taking one argument of type arg_type
// and n additional arguments of arbitrary types.
# define FMT_WRAP1(func, arg_type, n) \
  template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
  inline void func(arg_type arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
    const fmt::internal::Arg args[] = {FMT_GEN(n, FMT_MAKE_REF)}; \
    func(arg1, fmt::ArgList( \
      fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), args)); \
  }

// Emulates a variadic function returning void on a pre-C++11 compiler.
# define FMT_VARIADIC_VOID(func, arg_type) \
  inline void func(arg_type arg) { func(arg, fmt::ArgList()); } \
  FMT_WRAP1(func, arg_type, 1) FMT_WRAP1(func, arg_type, 2) \
  FMT_WRAP1(func, arg_type, 3) FMT_WRAP1(func, arg_type, 4) \
  FMT_WRAP1(func, arg_type, 5) FMT_WRAP1(func, arg_type, 6) \
  FMT_WRAP1(func, arg_type, 7) FMT_WRAP1(func, arg_type, 8) \
  FMT_WRAP1(func, arg_type, 9) FMT_WRAP1(func, arg_type, 10)

# define FMT_CTOR(ctor, func, arg0_type, arg1_type, n) \
  template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
  ctor(arg0_type arg0, arg1_type arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
    const fmt::internal::Arg args[] = {FMT_GEN(n, FMT_MAKE_REF)}; \
    func(arg0, arg1, fmt::ArgList( \
      fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), args)); \
  }

// Emulates a variadic constructor on a pre-C++11 compiler.
# define FMT_VARIADIC_CTOR(ctor, func, arg0_type, arg1_type) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 1) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 2) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 3) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 4) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 5) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 6) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 7) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 8) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 9) \
  FMT_CTOR(ctor, func, arg0_type, arg1_type, 10)
#endif

// Generates a comma-separated list with results of applying f to pairs
// (argument, index).
#define FMT_FOR_EACH1(f, x0) f(x0, 0)
#define FMT_FOR_EACH2(f, x0, x1) \
  FMT_FOR_EACH1(f, x0), f(x1, 1)
#define FMT_FOR_EACH3(f, x0, x1, x2) \
  FMT_FOR_EACH2(f, x0 ,x1), f(x2, 2)
#define FMT_FOR_EACH4(f, x0, x1, x2, x3) \
  FMT_FOR_EACH3(f, x0, x1, x2), f(x3, 3)
#define FMT_FOR_EACH5(f, x0, x1, x2, x3, x4) \
  FMT_FOR_EACH4(f, x0, x1, x2, x3), f(x4, 4)
#define FMT_FOR_EACH6(f, x0, x1, x2, x3, x4, x5) \
  FMT_FOR_EACH5(f, x0, x1, x2, x3, x4), f(x5, 5)
#define FMT_FOR_EACH7(f, x0, x1, x2, x3, x4, x5, x6) \
  FMT_FOR_EACH6(f, x0, x1, x2, x3, x4, x5), f(x6, 6)
#define FMT_FOR_EACH8(f, x0, x1, x2, x3, x4, x5, x6, x7) \
  FMT_FOR_EACH7(f, x0, x1, x2, x3, x4, x5, x6), f(x7, 7)
#define FMT_FOR_EACH9(f, x0, x1, x2, x3, x4, x5, x6, x7, x8) \
  FMT_FOR_EACH8(f, x0, x1, x2, x3, x4, x5, x6, x7), f(x8, 8)
#define FMT_FOR_EACH10(f, x0, x1, x2, x3, x4, x5, x6, x7, x8, x9) \
  FMT_FOR_EACH9(f, x0, x1, x2, x3, x4, x5, x6, x7, x8), f(x9, 9)

/**
 An error returned by an operating system or a language runtime,
 for example a file opening error.
*/
class SystemError : public internal::RuntimeError {
 private:
  void init(int err_code, StringRef format_str, ArgList args);

 protected:
  int error_code_;

  typedef char Char;  // For FMT_VARIADIC_CTOR.

  SystemError() {}

 public:
  /**
   \rst
   Constructs a :class:`fmt::SystemError` object with the description
   of the form

   .. parsed-literal::
     *<message>*: *<system-message>*

   where *<message>* is the formatted message and *<system-message>* is
   the system message corresponding to the error code.
   *error_code* is a system error code as given by ``errno``.
   If *error_code* is not a valid error code such as -1, the system message
   may look like "Unknown error -1" and is platform-dependent.
   
   **Example**::

     // This throws a SystemError with the description
     //   cannot open file 'madeup': No such file or directory
     // or similar (system message may vary).
     const char *filename = "madeup";
     std::FILE *file = std::fopen(filename, "r");
     if (!file)
       throw fmt::SystemError(errno, "cannot open file '{}'", filename);
   \endrst
  */
  SystemError(int error_code, StringRef message) {
    init(error_code, message, ArgList());
  }
  FMT_VARIADIC_CTOR(SystemError, init, int, StringRef)

  int error_code() const { return error_code_; }
};

/**
  \rst
  This template provides operations for formatting and writing data into
  a character stream. The output is stored in a buffer provided by a subclass
  such as :class:`fmt::BasicMemoryWriter`.

  You can use one of the following typedefs for common character types:

  +---------+----------------------+
  | Type    | Definition           |
  +=========+======================+
  | Writer  | BasicWriter<char>    |
  +---------+----------------------+
  | WWriter | BasicWriter<wchar_t> |
  +---------+----------------------+

  \endrst
 */
template <typename Char>
class BasicWriter {
 private:
  // Output buffer.
  Buffer<Char> &buffer_;

  FMT_DISALLOW_COPY_AND_ASSIGN(BasicWriter);

  typedef typename internal::CharTraits<Char>::CharPtr CharPtr;

#if _SECURE_SCL
  // Returns pointer value.
  static Char *get(CharPtr p) { return p.base(); }
#else
  static Char *get(Char *p) { return p; }
#endif

  // Fills the padding around the content and returns the pointer to the
  // content area.
  static CharPtr fill_padding(CharPtr buffer,
      unsigned total_size, std::size_t content_size, wchar_t fill);

  // Grows the buffer by n characters and returns a pointer to the newly
  // allocated area.
  CharPtr grow_buffer(std::size_t n) {
    std::size_t size = buffer_.size();
    buffer_.resize(size + n);
    return internal::make_ptr(&buffer_[size], n);
  }

  // Prepare a buffer for integer formatting.
  CharPtr prepare_int_buffer(unsigned num_digits,
      const EmptySpec &, const char *prefix, unsigned prefix_size) {
    unsigned size = prefix_size + num_digits;
    CharPtr p = grow_buffer(size);
    std::copy(prefix, prefix + prefix_size, p);
    return p + size - 1;
  }

  template <typename Spec>
  CharPtr prepare_int_buffer(unsigned num_digits,
    const Spec &spec, const char *prefix, unsigned prefix_size);

  // Formats an integer.
  template <typename T, typename Spec>
  void write_int(T value, Spec spec);

  // Formats a floating-point number (double or long double).
  template <typename T>
  void write_double(T value, const FormatSpec &spec);

  // Writes a formatted string.
  template <typename StrChar>
  CharPtr write_str(
      const StrChar *s, std::size_t size, const AlignSpec &spec);

  template <typename StrChar>
  void write_str(
      const internal::Arg::StringValue<StrChar> &str, const FormatSpec &spec);

  // This following methods are private to disallow writing wide characters
  // and strings to a char stream. If you want to print a wide string as a
  // pointer as std::ostream does, cast it to const void*.
  // Do not implement!
  void operator<<(typename internal::WCharHelper<wchar_t, Char>::Unsupported);
  void operator<<(
      typename internal::WCharHelper<const wchar_t *, Char>::Unsupported);

  // Appends floating-point length specifier to the format string.
  // The second argument is only used for overload resolution.
  void append_float_length(Char *&format_ptr, long double) {
    *format_ptr++ = 'L';
  }

  template<typename T>
  void append_float_length(Char *&, T) {}

  friend class internal::ArgFormatter<Char>;
  friend class internal::PrintfFormatter<Char>;

 protected:
  /**
    Constructs a ``BasicWriter`` object.
   */
  explicit BasicWriter(Buffer<Char> &b) : buffer_(b) {}

 public:
  /**
    Destroys a ``BasicWriter`` object.
   */
  virtual ~BasicWriter() {}

  /**
    Returns the total number of characters written.
   */
  std::size_t size() const { return buffer_.size(); }

  /**
    Returns a pointer to the output buffer content. No terminating null
    character is appended.
   */
  const Char *data() const FMT_NOEXCEPT { return &buffer_[0]; }

  /**
    Returns a pointer to the output buffer content with terminating null
    character appended.
   */
  const Char *c_str() const {
    std::size_t size = buffer_.size();
    buffer_.reserve(size + 1);
    buffer_[size] = '\0';
    return &buffer_[0];
  }

  /**
    Returns the content of the output buffer as an `std::string`.
   */
  std::basic_string<Char> str() const {
    return std::basic_string<Char>(&buffer_[0], buffer_.size());
  }

  /**
    \rst
    Writes formatted data.
    
    *args* is an argument list representing arbitrary arguments.

    **Example**::

       MemoryWriter out;
       out.write("Current point:\n");
       out.write("({:+f}, {:+f})", -3.14, 3.14);

    This will write the following output to the ``out`` object:

    .. code-block:: none

       Current point:
       (-3.140000, +3.140000)

    The output can be accessed using :func:`data()`, :func:`c_str` or
    :func:`str` methods.

    See also :ref:`syntax`.
    \endrst
   */
  void write(BasicStringRef<Char> format, ArgList args) {
    BasicFormatter<Char>(*this).format(format, args);
  }
  FMT_VARIADIC_VOID(write, BasicStringRef<Char>)

  BasicWriter &operator<<(int value) {
    return *this << IntFormatSpec<int>(value);
  }
  BasicWriter &operator<<(unsigned value) {
    return *this << IntFormatSpec<unsigned>(value);
  }
  BasicWriter &operator<<(long value) {
    return *this << IntFormatSpec<long>(value);
  }
  BasicWriter &operator<<(unsigned long value) {
    return *this << IntFormatSpec<unsigned long>(value);
  }
  BasicWriter &operator<<(LongLong value) {
    return *this << IntFormatSpec<LongLong>(value);
  }

  /**
    Formats *value* and writes it to the stream.
   */
  BasicWriter &operator<<(ULongLong value) {
    return *this << IntFormatSpec<ULongLong>(value);
  }

  BasicWriter &operator<<(double value) {
    write_double(value, FormatSpec());
    return *this;
  }

  /**
    Formats *value* using the general format for floating-point numbers
    (``'g'``) and writes it to the stream.
   */
  BasicWriter &operator<<(long double value) {
    write_double(value, FormatSpec());
    return *this;
  }

  /**
    Writes a character to the stream.
   */
  BasicWriter &operator<<(char value) {
    buffer_.push_back(value);
    return *this;
  }

  BasicWriter &operator<<(
      typename internal::WCharHelper<wchar_t, Char>::Supported value) {
    buffer_.push_back(value);
    return *this;
  }

  /**
    Writes *value* to the stream.
   */
  BasicWriter &operator<<(fmt::BasicStringRef<Char> value) {
    const Char *str = value.c_str();
    buffer_.append(str, str + value.size());
    return *this;
  }

  template <typename T, typename Spec, typename FillChar>
  BasicWriter &operator<<(IntFormatSpec<T, Spec, FillChar> spec) {
    internal::CharTraits<Char>::convert(FillChar());
    write_int(spec.value(), spec);
    return *this;
  }

  template <typename StrChar>
  BasicWriter &operator<<(const StrFormatSpec<StrChar> &spec) {
    const StrChar *s = spec.str();
    // TODO: error if fill is not convertible to Char
    write_str(s, std::char_traits<Char>::length(s), spec);
    return *this;
  }

  void clear() FMT_NOEXCEPT { buffer_.clear(); }
};

template <typename Char>
template <typename StrChar>
typename BasicWriter<Char>::CharPtr BasicWriter<Char>::write_str(
      const StrChar *s, std::size_t size, const AlignSpec &spec) {
  CharPtr out = CharPtr();
  if (spec.width() > size) {
    out = grow_buffer(spec.width());
    Char fill = static_cast<Char>(spec.fill());
    if (spec.align() == ALIGN_RIGHT) {
      std::fill_n(out, spec.width() - size, fill);
      out += spec.width() - size;
    } else if (spec.align() == ALIGN_CENTER) {
      out = fill_padding(out, spec.width(), size, fill);
    } else {
      std::fill_n(out + size, spec.width() - size, fill);
    }
  } else {
    out = grow_buffer(size);
  }
  std::copy(s, s + size, out);
  return out;
}

template <typename Char>
typename BasicWriter<Char>::CharPtr
  BasicWriter<Char>::fill_padding(
    CharPtr buffer, unsigned total_size,
    std::size_t content_size, wchar_t fill) {
  std::size_t padding = total_size - content_size;
  std::size_t left_padding = padding / 2;
  Char fill_char = static_cast<Char>(fill);
  std::fill_n(buffer, left_padding, fill_char);
  buffer += left_padding;
  CharPtr content = buffer;
  std::fill_n(buffer + content_size, padding - left_padding, fill_char);
  return content;
}

template <typename Char>
template <typename Spec>
typename BasicWriter<Char>::CharPtr
  BasicWriter<Char>::prepare_int_buffer(
    unsigned num_digits, const Spec &spec,
    const char *prefix, unsigned prefix_size) {
  unsigned width = spec.width();
  Alignment align = spec.align();
  Char fill = static_cast<Char>(spec.fill());
  if (spec.precision() > static_cast<int>(num_digits)) {
    // Octal prefix '0' is counted as a digit, so ignore it if precision
    // is specified.
    if (prefix_size > 0 && prefix[prefix_size - 1] == '0')
      --prefix_size;
    unsigned number_size = prefix_size + spec.precision();
    AlignSpec subspec(number_size, '0', ALIGN_NUMERIC);
    if (number_size >= width)
      return prepare_int_buffer(num_digits, subspec, prefix, prefix_size);
    buffer_.reserve(width);
    unsigned fill_size = width - number_size;
    if (align != ALIGN_LEFT) {
      CharPtr p = grow_buffer(fill_size);
      std::fill(p, p + fill_size, fill);
    }
    CharPtr result = prepare_int_buffer(
        num_digits, subspec, prefix, prefix_size);
    if (align == ALIGN_LEFT) {
      CharPtr p = grow_buffer(fill_size);
      std::fill(p, p + fill_size, fill);
    }
    return result;
  }
  unsigned size = prefix_size + num_digits;
  if (width <= size) {
    CharPtr p = grow_buffer(size);
    std::copy(prefix, prefix + prefix_size, p);
    return p + size - 1;
  }
  CharPtr p = grow_buffer(width);
  CharPtr end = p + width;
  if (align == ALIGN_LEFT) {
    std::copy(prefix, prefix + prefix_size, p);
    p += size;
    std::fill(p, end, fill);
  } else if (align == ALIGN_CENTER) {
    p = fill_padding(p, width, size, fill);
    std::copy(prefix, prefix + prefix_size, p);
    p += size;
  } else {
    if (align == ALIGN_NUMERIC) {
      if (prefix_size != 0) {
        p = std::copy(prefix, prefix + prefix_size, p);
        size -= prefix_size;
      }
    } else {
      std::copy(prefix, prefix + prefix_size, end - size);
    }
    std::fill(p, end - size, fill);
    p = end;
  }
  return p - 1;
}

template <typename Char>
template <typename T, typename Spec>
void BasicWriter<Char>::write_int(T value, Spec spec) {
  unsigned prefix_size = 0;
  typedef typename internal::IntTraits<T>::MainType UnsignedType;
  UnsignedType abs_value = value;
  char prefix[4] = "";
  if (internal::is_negative(value)) {
    prefix[0] = '-';
    ++prefix_size;
    abs_value = 0 - abs_value;
  } else if (spec.flag(SIGN_FLAG)) {
    prefix[0] = spec.flag(PLUS_FLAG) ? '+' : ' ';
    ++prefix_size;
  }
  switch (spec.type()) {
  case 0: case 'd': {
    unsigned num_digits = internal::count_digits(abs_value);
    CharPtr p = prepare_int_buffer(
      num_digits, spec, prefix, prefix_size) + 1 - num_digits;
    internal::format_decimal(get(p), abs_value, num_digits);
    break;
  }
  case 'x': case 'X': {
    UnsignedType n = abs_value;
    if (spec.flag(HASH_FLAG)) {
      prefix[prefix_size++] = '0';
      prefix[prefix_size++] = spec.type();
    }
    unsigned num_digits = 0;
    do {
      ++num_digits;
    } while ((n >>= 4) != 0);
    Char *p = get(prepare_int_buffer(
      num_digits, spec, prefix, prefix_size));
    n = abs_value;
    const char *digits = spec.type() == 'x' ?
        "0123456789abcdef" : "0123456789ABCDEF";
    do {
      *p-- = digits[n & 0xf];
    } while ((n >>= 4) != 0);
    break;
  }
  case 'b': case 'B': {
    UnsignedType n = abs_value;
    if (spec.flag(HASH_FLAG)) {
      prefix[prefix_size++] = '0';
      prefix[prefix_size++] = spec.type();
    }
    unsigned num_digits = 0;
    do {
      ++num_digits;
    } while ((n >>= 1) != 0);
    Char *p = get(prepare_int_buffer(num_digits, spec, prefix, prefix_size));
    n = abs_value;
    do {
      *p-- = '0' + (n & 1);
    } while ((n >>= 1) != 0);
    break;
  }
  case 'o': {
    UnsignedType n = abs_value;
    if (spec.flag(HASH_FLAG))
      prefix[prefix_size++] = '0';
    unsigned num_digits = 0;
    do {
      ++num_digits;
    } while ((n >>= 3) != 0);
    Char *p = get(prepare_int_buffer(num_digits, spec, prefix, prefix_size));
    n = abs_value;
    do {
      *p-- = '0' + (n & 7);
    } while ((n >>= 3) != 0);
    break;
  }
  default:
    internal::report_unknown_type(
      spec.type(), spec.flag(CHAR_FLAG) ? "char" : "integer");
    break;
  }
}

template <typename Char>
template <typename T>
void BasicWriter<Char>::write_double(
    T value, const FormatSpec &spec) {
  // Check type.
  char type = spec.type();
  bool upper = false;
  switch (type) {
  case 0:
    type = 'g';
    break;
  case 'e': case 'f': case 'g': case 'a':
    break;
  case 'F':
#ifdef _MSC_VER
    // MSVC's printf doesn't support 'F'.
    type = 'f';
#endif
    // Fall through.
  case 'E': case 'G': case 'A':
    upper = true;
    break;
  default:
    internal::report_unknown_type(type, "double");
    break;
  }

  char sign = 0;
  // Use getsign instead of value < 0 because the latter is always
  // false for NaN.
  if (internal::getsign(static_cast<double>(value))) {
    sign = '-';
    value = -value;
  } else if (spec.flag(SIGN_FLAG)) {
    sign = spec.flag(PLUS_FLAG) ? '+' : ' ';
  }

  if (value != value) {
    // Format NaN ourselves because sprintf's output is not consistent
    // across platforms.
    std::size_t nan_size = 4;
    const char *nan = upper ? " NAN" : " nan";
    if (!sign) {
      --nan_size;
      ++nan;
    }
    CharPtr out = write_str(nan, nan_size, spec);
    if (sign)
      *out = sign;
    return;
  }

  if (internal::isinfinity(value)) {
    // Format infinity ourselves because sprintf's output is not consistent
    // across platforms.
    std::size_t inf_size = 4;
    const char *inf = upper ? " INF" : " inf";
    if (!sign) {
      --inf_size;
      ++inf;
    }
    CharPtr out = write_str(inf, inf_size, spec);
    if (sign)
      *out = sign;
    return;
  }

  std::size_t offset = buffer_.size();
  unsigned width = spec.width();
  if (sign) {
    buffer_.reserve(buffer_.size() + (std::max)(width, 1u));
    if (width > 0)
      --width;
    ++offset;
  }

  // Build format string.
  enum { MAX_FORMAT_SIZE = 10}; // longest format: %#-*.*Lg
  Char format[MAX_FORMAT_SIZE];
  Char *format_ptr = format;
  *format_ptr++ = '%';
  unsigned width_for_sprintf = width;
  if (spec.flag(HASH_FLAG))
    *format_ptr++ = '#';
  if (spec.align() == ALIGN_CENTER) {
    width_for_sprintf = 0;
  } else {
    if (spec.align() == ALIGN_LEFT)
      *format_ptr++ = '-';
    if (width != 0)
      *format_ptr++ = '*';
  }
  if (spec.precision() >= 0) {
    *format_ptr++ = '.';
    *format_ptr++ = '*';
  }

  append_float_length(format_ptr, value);
  *format_ptr++ = type;
  *format_ptr = '\0';

  // Format using snprintf.
  Char fill = static_cast<Char>(spec.fill());
  for (;;) {
    std::size_t buffer_size = buffer_.capacity() - offset;
#if _MSC_VER
    // MSVC's vsnprintf_s doesn't work with zero size, so reserve
    // space for at least one extra character to make the size non-zero.
    // Note that the buffer's capacity will increase by more than 1.
    if (buffer_size == 0) {
      buffer_.reserve(offset + 1);
      buffer_size = buffer_.capacity() - offset;
    }
#endif
    Char *start = &buffer_[offset];
    int n = internal::CharTraits<Char>::format_float(
        start, buffer_size, format, width_for_sprintf, spec.precision(), value);
    if (n >= 0 && offset + n < buffer_.capacity()) {
      if (sign) {
        if ((spec.align() != ALIGN_RIGHT && spec.align() != ALIGN_DEFAULT) ||
            *start != ' ') {
          *(start - 1) = sign;
          sign = 0;
        } else {
          *(start - 1) = fill;
        }
        ++n;
      }
      if (spec.align() == ALIGN_CENTER &&
          spec.width() > static_cast<unsigned>(n)) {
        width = spec.width();
        CharPtr p = grow_buffer(width);
        std::copy(p, p + n, p + (width - n) / 2);
        fill_padding(p, spec.width(), n, fill);
        return;
      }
      if (spec.fill() != ' ' || sign) {
        while (*start == ' ')
          *start++ = fill;
        if (sign)
          *(start - 1) = sign;
      }
      grow_buffer(n);
      return;
    }
    // If n is negative we ask to increase the capacity by at least 1,
    // but as std::vector, the buffer grows exponentially.
    buffer_.reserve(n >= 0 ? offset + n + 1 : buffer_.capacity() + 1);
  }
}

/**
  \rst
  This class template provides operations for formatting and writing data
  into a character stream. The output is stored in a memory buffer that grows
  dynamically.

  You can use one of the following typedefs for common character types
  and the standard allocator:

  +---------------+-----------------------------------------------------+
  | Type          | Definition                                          |
  +===============+=====================================================+
  | MemoryWriter  | BasicMemoryWriter<char, std::allocator<char>>       |
  +---------------+-----------------------------------------------------+
  | WMemoryWriter | BasicMemoryWriter<wchar_t, std::allocator<wchar_t>> |
  +---------------+-----------------------------------------------------+

  **Example**::

     MemoryWriter out;
     out << "The answer is " << 42 << "\n";
     out.write("({:+f}, {:+f})", -3.14, 3.14);

  This will write the following output to the ``out`` object:

  .. code-block:: none

     The answer is 42
     (-3.140000, +3.140000)

  The output can be converted to an ``std::string`` with ``out.str()`` or
  accessed as a C string with ``out.c_str()``.
  \endrst
 */
template <typename Char, typename Allocator = std::allocator<Char> >
class BasicMemoryWriter : public BasicWriter<Char> {
 private:
  internal::MemoryBuffer<Char, internal::INLINE_BUFFER_SIZE, Allocator> buffer_;

 public:
  explicit BasicMemoryWriter(const Allocator& alloc = Allocator())
    : BasicWriter<Char>(buffer_), buffer_(alloc) {}

#if FMT_USE_RVALUE_REFERENCES
  /**
    \rst
    Constructs a :class:`fmt::BasicMemoryWriter` object moving the content
    of the other object to it.
    \endrst
   */
  BasicMemoryWriter(BasicMemoryWriter &&other)
    : BasicWriter<Char>(buffer_), buffer_(std::move(other.buffer_)) {
  }

  /**
    \rst
    Moves the content of the other ``BasicMemoryWriter`` object to this one.
    \endrst
   */
  BasicMemoryWriter &operator=(BasicMemoryWriter &&other) {
    buffer_ = std::move(other.buffer_);
    return *this;
  }
#endif
};

typedef BasicMemoryWriter<char> MemoryWriter;
typedef BasicMemoryWriter<wchar_t> WMemoryWriter;

/**
  \rst
  This class template provides operations for formatting and writing data
  into a fixed-size array. For writing into a dynamically growing buffer
  use :class:`fmt::BasicMemoryWriter`.
  
  Any write method will throw ``std::runtime_error`` if the output doesn't fit
  into the array.

  You can use one of the following typedefs for common character types:

  +--------------+---------------------------+
  | Type         | Definition                |
  +==============+===========================+
  | ArrayWriter  | BasicArrayWriter<char>    |
  +--------------+---------------------------+
  | WArrayWriter | BasicArrayWriter<wchar_t> |
  +--------------+---------------------------+
  \endrst
 */
template <typename Char>
class BasicArrayWriter : public BasicWriter<Char> {
 private:
  internal::FixedBuffer<Char> buffer_;

 public:
  /**
   \rst
   Constructs a :class:`fmt::BasicArrayWriter` object for *array* of the
   given size.
   \endrst
   */
  BasicArrayWriter(Char *array, std::size_t size)
    : BasicWriter<Char>(buffer_), buffer_(array, size) {}

  // FIXME: this is temporary undocumented due to a bug in Sphinx
  /*
   \rst
   Constructs a :class:`fmt::BasicArrayWriter` object for *array* of the
   size known at compile time.
   \endrst
   */
  template <std::size_t SIZE>
  explicit BasicArrayWriter(Char (&array)[SIZE])
    : BasicWriter<Char>(buffer_), buffer_(array, SIZE) {}
};

typedef BasicArrayWriter<char> ArrayWriter;
typedef BasicArrayWriter<wchar_t> WArrayWriter;

// Formats a value.
template <typename Char, typename T>
void format(BasicFormatter<Char> &f, const Char *&format_str, const T &value) {
  std::basic_ostringstream<Char> os;
  os << value;
  std::basic_string<Char> str = os.str();
  internal::Arg arg = internal::MakeValue<Char>(str);
  arg.type = static_cast<internal::Arg::Type>(
        internal::MakeValue<Char>::type(str));
  format_str = f.format(format_str, arg);
}

// Reports a system error without throwing an exception.
// Can be used to report errors from destructors.
void report_system_error(int error_code, StringRef message) FMT_NOEXCEPT;

#ifdef _WIN32

/** A Windows error. */
class WindowsError : public SystemError {
 private:
  void init(int error_code, StringRef format_str, ArgList args);

 public:
  /**
   \rst
   Constructs a :class:`fmt::WindowsError` object with the description
   of the form

   .. parsed-literal::
     *<message>*: *<system-message>*

   where *<message>* is the formatted message and *<system-message>* is the
   system message corresponding to the error code.
   *error_code* is a Windows error code as given by ``GetLastError``.
   If *error_code* is not a valid error code such as -1, the system message
   will look like "error -1".

   **Example**::

     // This throws a WindowsError with the description
     //   cannot open file 'madeup': The system cannot find the file specified.
     // or similar (system message may vary).
     const char *filename = "madeup";
     LPOFSTRUCT of = LPOFSTRUCT();
     HFILE file = OpenFile(filename, &of, OF_READ);
     if (file == HFILE_ERROR) {
       throw fmt::WindowsError(GetLastError(),
                               "cannot open file '{}'", filename);
     }
   \endrst
  */
  WindowsError(int error_code, StringRef message) {
    init(error_code, message, ArgList());
  }
  FMT_VARIADIC_CTOR(WindowsError, init, int, StringRef)
};

// Reports a Windows error without throwing an exception.
// Can be used to report errors from destructors.
void report_windows_error(int error_code, StringRef message) FMT_NOEXCEPT;

#endif

enum Color { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

/**
  Formats a string and prints it to stdout using ANSI escape sequences
  to specify color (experimental).
  Example:
    PrintColored(fmt::RED, "Elapsed time: {0:.2f} seconds") << 1.23;
 */
void print_colored(Color c, StringRef format, ArgList args);

/**
  \rst
  Formats arguments and returns the result as a string.

  **Example**::

    std::string message = format("The answer is {}", 42);
  \endrst
*/
inline std::string format(StringRef format_str, ArgList args) {
  MemoryWriter w;
  w.write(format_str, args);
  return w.str();
}

inline std::wstring format(WStringRef format_str, ArgList args) {
  WMemoryWriter w;
  w.write(format_str, args);
  return w.str();
}

/**
  \rst
  Prints formatted data to the file *f*.

  **Example**::

    print(stderr, "Don't {}!", "panic");
  \endrst
 */
void print(std::FILE *f, StringRef format_str, ArgList args);

/**
  \rst
  Prints formatted data to ``stdout``.

  **Example**::

    print("Elapsed time: {0:.2f} seconds", 1.23);
  \endrst
 */
void print(StringRef format_str, ArgList args);

/**
  \rst
  Prints formatted data to the stream *os*.

  **Example**::

    print(cerr, "Don't {}!", "panic");
  \endrst
 */
void print(std::ostream &os, StringRef format_str, ArgList args);

template <typename Char>
void printf(BasicWriter<Char> &w, BasicStringRef<Char> format, ArgList args) {
  internal::PrintfFormatter<Char>().format(w, format, args);
}

/**
  \rst
  Formats arguments and returns the result as a string.

  **Example**::

    std::string message = fmt::sprintf("The answer is %d", 42);
  \endrst
*/
inline std::string sprintf(StringRef format, ArgList args) {
  MemoryWriter w;
  printf(w, format, args);
  return w.str();
}

/**
  \rst
  Prints formatted data to the file *f*.

  **Example**::

    fmt::fprintf(stderr, "Don't %s!", "panic");
  \endrst
 */
int fprintf(std::FILE *f, StringRef format, ArgList args);

/**
  \rst
  Prints formatted data to ``stdout``.

  **Example**::

    fmt::printf("Elapsed time: %.2f seconds", 1.23);
  \endrst
 */
inline int printf(StringRef format, ArgList args) {
  return fprintf(stdout, format, args);
}

/**
  Fast integer formatter.
 */
class FormatInt {
 private:
  // Buffer should be large enough to hold all digits (digits10 + 1),
  // a sign and a null character.
  enum {BUFFER_SIZE = std::numeric_limits<ULongLong>::digits10 + 3};
  mutable char buffer_[BUFFER_SIZE];
  char *str_;

  // Formats value in reverse and returns the number of digits.
  char *format_decimal(ULongLong value) {
    char *buffer_end = buffer_ + BUFFER_SIZE - 1;
    while (value >= 100) {
      // Integer division is slow so do it for a group of two digits instead
      // of for every digit. The idea comes from the talk by Alexandrescu
      // "Three Optimization Tips for C++". See speed-test for a comparison.
      unsigned index = (value % 100) * 2;
      value /= 100;
      *--buffer_end = internal::Data::DIGITS[index + 1];
      *--buffer_end = internal::Data::DIGITS[index];
    }
    if (value < 10) {
      *--buffer_end = static_cast<char>('0' + value);
      return buffer_end;
    }
    unsigned index = static_cast<unsigned>(value * 2);
    *--buffer_end = internal::Data::DIGITS[index + 1];
    *--buffer_end = internal::Data::DIGITS[index];
    return buffer_end;
  }

  void FormatSigned(LongLong value) {
    ULongLong abs_value = static_cast<ULongLong>(value);
    bool negative = value < 0;
    if (negative)
      abs_value = 0 - abs_value;
    str_ = format_decimal(abs_value);
    if (negative)
      *--str_ = '-';
  }

 public:
  explicit FormatInt(int value) { FormatSigned(value); }
  explicit FormatInt(long value) { FormatSigned(value); }
  explicit FormatInt(LongLong value) { FormatSigned(value); }
  explicit FormatInt(unsigned value) : str_(format_decimal(value)) {}
  explicit FormatInt(unsigned long value) : str_(format_decimal(value)) {}
  explicit FormatInt(ULongLong value) : str_(format_decimal(value)) {}

  /**
    Returns the number of characters written to the output buffer.
   */
  std::size_t size() const { return buffer_ - str_ + BUFFER_SIZE - 1; }

  /**
    Returns a pointer to the output buffer content. No terminating null
    character is appended.
   */
  const char *data() const { return str_; }

  /**
    Returns a pointer to the output buffer content with terminating null
    character appended.
   */
  const char *c_str() const {
    buffer_[BUFFER_SIZE - 1] = '\0';
    return str_;
  }

  /**
    Returns the content of the output buffer as an `std::string`.
   */
  std::string str() const { return std::string(str_, size()); }
};

// Formats a decimal integer value writing into buffer and returns
// a pointer to the end of the formatted string. This function doesn't
// write a terminating null character.
template <typename T>
inline void format_decimal(char *&buffer, T value) {
  typename internal::IntTraits<T>::MainType abs_value = value;
  if (internal::is_negative(value)) {
    *buffer++ = '-';
    abs_value = 0 - abs_value;
  }
  if (abs_value < 100) {
    if (abs_value < 10) {
      *buffer++ = static_cast<char>('0' + abs_value);
      return;
    }
    unsigned index = static_cast<unsigned>(abs_value * 2);
    *buffer++ = internal::Data::DIGITS[index];
    *buffer++ = internal::Data::DIGITS[index + 1];
    return;
  }
  unsigned num_digits = internal::count_digits(abs_value);
  internal::format_decimal(buffer, abs_value, num_digits);
  buffer += num_digits;
}
}

#if FMT_GCC_VERSION
// Use the system_header pragma to suppress warnings about variadic macros
// because suppressing -Wvariadic-macros with the diagnostic pragma doesn't
// work. It is used at the end because we want to suppress as little warnings
// as possible.
# pragma GCC system_header
#endif

// This is used to work around VC++ bugs in handling variadic macros.
#define FMT_EXPAND(args) args

// Returns the number of arguments.
// Based on https://groups.google.com/forum/#!topic/comp.std.c/d-6Mj5Lko_s.
#define FMT_NARG(...) FMT_NARG_(__VA_ARGS__, FMT_RSEQ_N())
#define FMT_NARG_(...) FMT_EXPAND(FMT_ARG_N(__VA_ARGS__))
#define FMT_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define FMT_RSEQ_N() 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define FMT_CONCAT(a, b) a##b
#define FMT_FOR_EACH_(N, f, ...) \
  FMT_EXPAND(FMT_CONCAT(FMT_FOR_EACH, N)(f, __VA_ARGS__))
#define FMT_FOR_EACH(f, ...) \
  FMT_EXPAND(FMT_FOR_EACH_(FMT_NARG(__VA_ARGS__), f, __VA_ARGS__))

#define FMT_ADD_ARG_NAME(type, index) type arg##index
#define FMT_GET_ARG_NAME(type, index) arg##index

#if FMT_USE_VARIADIC_TEMPLATES

namespace fmt {
namespace internal {
inline void do_set_types(Arg *) {}

template <typename T, typename... Args>
inline void do_set_types(Arg *args, const T &arg, const Args & ... tail) {
  args->type = static_cast<Arg::Type>(MakeValue<T>::type(arg));
  do_set_types(args + 1, tail...);
}

template <typename... Args>
inline void set_types(Arg *array, const Args & ... args) {
  do_set_types(array, args...);
  array[sizeof...(Args)].type = Arg::NONE;
}

// Computes the argument array size by adding 1 to N, which is the number of
// arguments, if N is zero, because array of zero size is invalid, or if N
// is greater than ArgList::MAX_PACKED_ARGS to accommodate for an extra
// argument that marks the end of the list.
template <unsigned N>
struct ArgArraySize {
  enum { VALUE = N + (N == 0 || N > ArgList::MAX_PACKED_ARGS ? 1 : 0) };
};
}
}

# define FMT_VARIADIC_(Char, ReturnType, func, call, ...) \
  template <typename... Args> \
  ReturnType func(FMT_FOR_EACH(FMT_ADD_ARG_NAME, __VA_ARGS__), \
      const Args & ... args) { \
    using fmt::internal::Arg; \
    Arg array[fmt::internal::ArgArraySize<sizeof...(Args)>::VALUE] = { \
      fmt::internal::MakeValue<Char>(args)... \
    }; \
    if (fmt::internal::check((sizeof...(Args) > fmt::ArgList::MAX_PACKED_ARGS))) \
      set_types(array, args...); \
    call(FMT_FOR_EACH(FMT_GET_ARG_NAME, __VA_ARGS__), \
      fmt::ArgList(fmt::internal::make_type(args...), array)); \
  }
#else
// Defines a wrapper for a function taking __VA_ARGS__ arguments
// and n additional arguments of arbitrary types.
# define FMT_WRAP(Char, ReturnType, func, call, n, ...) \
  template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
  inline ReturnType func(FMT_FOR_EACH(FMT_ADD_ARG_NAME, __VA_ARGS__), \
      FMT_GEN(n, FMT_MAKE_ARG)) { \
    const fmt::internal::Arg args[] = {FMT_GEN(n, FMT_MAKE_REF_##Char)}; \
    call(FMT_FOR_EACH(FMT_GET_ARG_NAME, __VA_ARGS__), fmt::ArgList( \
      fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), args)); \
  }

# define FMT_VARIADIC_(Char, ReturnType, func, call, ...) \
  inline ReturnType func(FMT_FOR_EACH(FMT_ADD_ARG_NAME, __VA_ARGS__)) { \
    call(FMT_FOR_EACH(FMT_GET_ARG_NAME, __VA_ARGS__), fmt::ArgList()); \
  } \
  FMT_WRAP(Char, ReturnType, func, call, 1, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 2, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 3, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 4, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 5, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 6, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 7, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 8, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 9, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 10, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 11, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 12, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 13, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 14, __VA_ARGS__) \
  FMT_WRAP(Char, ReturnType, func, call, 15, __VA_ARGS__)
#endif  // FMT_USE_VARIADIC_TEMPLATES

/**
  \rst
  Defines a variadic function with the specified return type, function name
  and argument types passed as variable arguments to this macro.

  **Example**::

    void print_error(const char *file, int line, const char *format,
                     fmt::ArgList args) {
      fmt::print("{}: {}: ", file, line);
      fmt::print(format, args);
    }
    FMT_VARIADIC(void, print_error, const char *, int, const char *)

  ``FMT_VARIADIC`` is used for compatibility with legacy C++ compilers that
  don't implement variadic templates. You don't have to use this macro if
  you don't need legacy compiler support and can use variadic templates
  directly::

    template <typename... Args>
    void print_error(const char *file, int line, const char *format,
                     const Args & ... args) {
      fmt::print("{}: {}: ", file, line);
      fmt::print(format, args...);
    }
  \endrst
 */
#define FMT_VARIADIC(ReturnType, func, ...) \
  FMT_VARIADIC_(char, ReturnType, func, return func, __VA_ARGS__)

#define FMT_VARIADIC_W(ReturnType, func, ...) \
  FMT_VARIADIC_(wchar_t, ReturnType, func, return func, __VA_ARGS__)

namespace fmt {
FMT_VARIADIC(std::string, format, StringRef)
FMT_VARIADIC_W(std::wstring, format, WStringRef)
FMT_VARIADIC(void, print, StringRef)
FMT_VARIADIC(void, print, std::FILE *, StringRef)
FMT_VARIADIC(void, print, std::ostream &, StringRef)
FMT_VARIADIC(void, print_colored, Color, StringRef)
FMT_VARIADIC(std::string, sprintf, StringRef)
FMT_VARIADIC(int, printf, StringRef)
FMT_VARIADIC(int, fprintf, std::FILE *, StringRef)
}

// Restore warnings.
#if FMT_GCC_VERSION >= 406
# pragma GCC diagnostic pop
#endif

#ifdef __clang__
# pragma clang diagnostic pop
#endif

#ifdef FMT_HEADER_ONLY
# include "format.cc"
#endif

#endif  // FMT_FORMAT_H_
