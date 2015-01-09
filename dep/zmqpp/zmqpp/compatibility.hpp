/**
 * \file
 *
 * \date   10 Sep 2011
 * \author ron
 * \author Ben Gray (\@benjamg)
 *
 * A fair number of C++0x (or more accurately C++11) features are used in this
 * library and as this project is used where I work on older compilers this
 * file was created to help.
 *
 * C++ features and their workaround where not supported:
 * \li lambda functions - disabled, these are only used in the test anyway.
 * \li typesafe enums   - replaced with enum where comparisons needed.
 * \li nullptr          - defined to null.
 *
 * As of the port to version 3.1 (libzmqpp version 1.1.0) this file will also
 * be used to maintain compatablity with multiple versions of 0mq
 */

#ifndef ZMQPP_COMPATIBILITY_HPP_
#define ZMQPP_COMPATIBILITY_HPP_

#include <zmq.h>
#include <cstdint>

// Currently we require at least 0mq version 2.2.x
#define ZMQPP_REQUIRED_ZMQ_MAJOR 2
#define ZMQPP_REQUIRED_ZMQ_MINOR 2

#if (ZMQ_VERSION_MAJOR < ZMQPP_REQUIRED_ZMQ_MAJOR) || ((ZMQ_VERSION_MAJOR == ZMQPP_REQUIRED_ZMQ_MAJOR) && (ZMQ_VERSION_MINOR < ZMQPP_REQUIRED_ZMQ_MINOR))
#error zmqpp requires a later version of 0mq
#endif

// Experimental feature support
#if (ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR == 0)
#define ZMQ_EXPERIMENTAL_LABELS
#endif

// Deal with older versions of gcc
#if defined(__GNUC__) && !defined(__clang__)
#if __GNUC__ == 4

// Deal with older gcc not supporting C++0x typesafe enum class name {} comparison
#if __GNUC_MINOR__ < 4
#define ZMQPP_COMPARABLE_ENUM enum
#endif

#if __GNUC_MINOR__ == 4
#if __GNUC_PATCHLEVEL__ < 1
#undef ZMQPP_COMPARABLE_ENUM
#define ZMQPP_COMPARABLE_ENUM enum
#endif // if __GNUC_PATCHLEVEL__ < 1
#endif // if __GNUC_MINOR__ == 4

// Deal with older gcc not supporting C++0x lambda function
#if __GNUC_MINOR__ < 5
#define ZMQPP_IGNORE_LAMBDA_FUNCTION_TESTS
#define ZMQPP_EXPLICITLY_DELETED
#endif // if __GNUC_MINOR__ < 5

// Deal with older gcc not supporting C++0x nullptr
#if __GNUC_MINOR__ < 6
#define nullptr NULL
#define NOEXCEPT
#endif // if __GNUC_MINOR__ < 6

#endif // if __GNUC_ == 4
#endif // if defined(__GNUC__) && !defined(__clang__)

#if defined(_MSC_VER)
#define NOEXCEPT throw()
#if _MSC_VER < 1800
#define ZMQPP_EXPLICITLY_DELETED
#endif // if _MSC_VER < 1800
#if _MSC_VER < 1600
#define nullptr NULL
#define ZMQPP_IGNORE_LAMBDA_FUNCTION_TESTS
#define ZMQPP_COMPARABLE_ENUM enum
#endif // if _MSC_VER < 1600
#endif // if defined(_MSC_VER)

// Generic state, assume a modern compiler
#ifndef ZMQPP_COMPARABLE_ENUM
#define ZMQPP_COMPARABLE_ENUM enum class
#endif

#ifndef ZMQPP_EXPLICITLY_DELETED
#define ZMQPP_EXPLICITLY_DELETED = delete
#endif

#ifndef NOEXCEPT
#define NOEXCEPT noexcept
#endif

#endif /* ZMQPP_COMPATIBILITY_HPP_ */

