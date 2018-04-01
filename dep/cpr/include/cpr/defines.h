#ifndef CPR_DEFINES_H
#define CPR_DEFINES_H

#include <utility>

#define CPR_FWD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

#endif
