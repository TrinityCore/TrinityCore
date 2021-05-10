#include "TSString.h"
#include "TSArray.h"

TSArray<TSString> TSString::split(TSString delim)
{
  TSArray<TSString> arr;
  auto start = 0U;
  auto end = _value.find(delim._value);
  while (end != std::string::npos)
  {
    if (end != start) {
      arr.push(_value.substr(start, end - start));
    }
    start = end + delim.get_length();
    end = _value.find(delim._value, start);
  }

  end = get_length();
  if (start != end) {
    arr.push(_value.substr(start, end - start));
  }

  return arr;
}