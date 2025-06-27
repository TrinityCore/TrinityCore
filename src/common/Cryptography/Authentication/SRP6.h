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

#ifndef TRINITY_SRP6_H
#define TRINITY_SRP6_H

#include "AuthDefines.h"
#include "BigNumber.h"
#include "Define.h"
#include "Common.h"
#include "CryptoHash.h"
#include <array>
#include <optional>

namespace Trinity::Crypto
{
    class TC_COMMON_API SRP6
    {
        public:
            static constexpr size_t SALT_LENGTH = 32;
            using Salt = std::array<uint8, SALT_LENGTH>;
            static constexpr size_t VERIFIER_LENGTH = 32;
            using Verifier = std::array<uint8, VERIFIER_LENGTH>;
            static constexpr size_t EPHEMERAL_KEY_LENGTH = 32;
            using EphemeralKey = std::array<uint8, EPHEMERAL_KEY_LENGTH>;

            static std::array<uint8, 1> const g;
            static std::array<uint8, 32> const N;

            // username + password must be passed through Utf8ToUpperOnlyLatin FIRST!
            static std::pair<Salt, Verifier> MakeRegistrationData(std::string const& username, std::string const& password);
            // username + password must be passed through Utf8ToUpperOnlyLatin FIRST!
            static bool CheckLogin(std::string const& username, std::string const& password, Salt const& salt, Verifier const& verifier)
            {
                return (verifier == CalculateVerifier(username, password, salt));
            }

            static SHA1::Digest GetSessionVerifier(EphemeralKey const& A, SHA1::Digest const& clientM, SessionKey const& K)
            {
                return SHA1::GetDigestOf(A, clientM, K);
            }

            SRP6(std::string const& username, Salt const& salt, Verifier const& verifier);
            std::optional<SessionKey> VerifyChallengeResponse(EphemeralKey const& A, SHA1::Digest const& clientM);

        private:
            bool _used = false; // a single instance can only be used to verify once

            static Verifier CalculateVerifier(std::string const& username, std::string const& password, Salt const& salt);
            static SessionKey SHA1Interleave(EphemeralKey const& S);

            /* global algorithm parameters */
            static BigNumber const _g; // a [g]enerator for the ring of integers mod N, algorithm parameter
            static BigNumber const _N; // the modulus, an algorithm parameter; all operations are mod this

            static EphemeralKey _B(BigNumber const& b, BigNumber const& v) { return ((_g.ModExp(b,_N) + (v * 3)) % N).ToByteArray<EPHEMERAL_KEY_LENGTH>(); }

            /* per-instantiation parameters, set on construction */
            SHA1::Digest const _I; // H(I) - the username, all uppercase
            BigNumber const _b; // b - randomly chosen by the server, 19 bytes, never given out
            BigNumber const _v; // v - the user's password verifier, derived from s + H(USERNAME || ":" || PASSWORD)

        public:
            Salt const s; // s - the user's password salt, random, used to calculate v on registration
            EphemeralKey const B; // B = 3v + g^b
    };
}

#endif
