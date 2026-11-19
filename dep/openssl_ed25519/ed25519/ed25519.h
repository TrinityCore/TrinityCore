/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CUSTOM_OPENSSL_ED25519_H
#define CUSTOM_OPENSSL_ED25519_H

#include <stddef.h>
#include <stdint.h>

#if defined _MSC_VER
#  define OPENSSL_ED25519_API_EXPORT __declspec(dllexport)
#  define OPENSSL_ED25519_API_IMPORT __declspec(dllimport)
#elif defined __GNUC__
#  define OPENSSL_ED25519_API_EXPORT __attribute__((visibility("default")))
#  define OPENSSL_ED25519_API_IMPORT
#else
#  error compiler not supported!
#endif

#ifdef OPENSSL_ED25519_EXPORT
#  define OPENSSL_ED25519_API OPENSSL_ED25519_API_EXPORT
#else
#  define OPENSSL_ED25519_API OPENSSL_ED25519_API_IMPORT
#endif

#ifdef __cplusplus
extern "C"
{
#endif

OPENSSL_ED25519_API int ED25519_sign(uint8_t* out_sig, const uint8_t* message, size_t message_len,
    const uint8_t public_key[32], const uint8_t private_key[32]);
OPENSSL_ED25519_API int ED25519_sign_ctx(uint8_t* out_sig, const uint8_t* message, size_t message_len,
    const uint8_t public_key[32], const uint8_t private_key[32], const uint8_t* context, uint8_t context_len);
OPENSSL_ED25519_API int ED25519_sign_ph(uint8_t* out_sig, const uint8_t* message, size_t message_len,
    const uint8_t public_key[32], const uint8_t private_key[32], const uint8_t* hash, uint8_t hash_len);

OPENSSL_ED25519_API int ED25519_verify(const uint8_t* message, size_t message_len,
    const uint8_t signature[64], const uint8_t public_key[32]);
OPENSSL_ED25519_API int ED25519_verify_ctx(const uint8_t* message, size_t message_len,
    const uint8_t signature[64], const uint8_t public_key[32], const uint8_t* context, uint8_t context_len);
OPENSSL_ED25519_API int ED25519_verify_ph(const uint8_t* message, size_t message_len,
    const uint8_t signature[64], const uint8_t public_key[32], const uint8_t* hash, uint8_t hash_len);

OPENSSL_ED25519_API void ED25519_public_from_private(uint8_t out_public_key[32],
    const uint8_t private_key[32]);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // CUSTOM_OPENSSL_ED25519_H
