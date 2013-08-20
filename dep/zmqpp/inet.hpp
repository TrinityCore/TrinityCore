/**
 * \file
 *
 * \date   10 Aug 2011
 * \author Ben Gray (\@benjamg)
 */

#ifndef ZMQPP_INET_HPP_
#define ZMQPP_INET_HPP_

/** \todo cross-platform version of including headers for htons and htonl. */
// We get htons and htonl from here
#include <netinet/in.h>

#include "compatibility.hpp"

namespace zmqpp
{

/*!
 * \brief Possible byte order types.
 *
 * An enumeration of all the known order types, all two of them.
 * There is also an entry for unknown which is just used as a default.
 */
ZMQPP_COMPARABLE_ENUM order {
	unknown,      /*!< used as a default prior to detection of the the byte order */
	big_endian,   /*!< brief byte order is big endian */
	little_endian /*!< \brief byte order is little endian */
};

/*!
 * Common code for the 64bit versions of htons/htons and ntohs/ntohl
 *
 * As htons and ntohs (or htonl and ntohs) always just do the same thing, ie
 * swap bytes if the host order differs from network order or otherwise don't
 * do anything, it seemed silly to type the code twice.
 *
 * \note This code assumes network order is always big endian. Which it is.
 * \note The host endian is only checked once and afterwards assumed to remain
 *       the same.
 *
 * \param value_to_check unsigned 64 bit integer to swap
 * \return swapped (or not) unsigned 64 bit integer
 */
inline uint64_t swap_if_needed(uint64_t const& value_to_check)
{
	static order host_order = order::unknown;

	union {
		uint64_t integer;
		uint8_t bytes[8];
	} value;

	if (order::unknown == host_order)
	{
		value.integer = 1;
		host_order = (1 == value.bytes[0]) ? order::little_endian : order::big_endian;
	}

	if (order::big_endian == host_order)
	{
		return value_to_check;
	}

	value.integer = value_to_check;

	std::swap(value.bytes[0], value.bytes[7]);
	std::swap(value.bytes[1], value.bytes[6]);
	std::swap(value.bytes[2], value.bytes[5]);
	std::swap(value.bytes[3], value.bytes[4]);

	return value.integer;
}

}

/*!
 * 64 bit version of the htons/htonl
 *
 * I've used the name htonll to try and keep with the htonl naming scheme.
 *
 * \param hostlonglong unsigned 64 bit host order integer
 * \return unsigned 64 bit network order integer
 */
inline uint64_t htonll(uint64_t const& hostlonglong)
{
	return zmqpp::swap_if_needed(hostlonglong);
}

/*!
 * 64 bit version of the ntohs/ntohl
 *
 * I've used the name htonll to try and keep with the htonl naming scheme.
 *
 * \param networklonglong unsigned 64 bit network order integer
 * \return unsigned 64 bit host order integer
 */
inline uint64_t ntohll(uint64_t const& networklonglong)
{
	return zmqpp::swap_if_needed(networklonglong);
}

#endif /* INET_HPP_ */
