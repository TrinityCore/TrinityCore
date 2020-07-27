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

#include "SRP6.h"
#include "CryptoRandom.h"
#include "Util.h"
#include <algorithm>
#include <functional>

using SHA1 = Trinity::Crypto::SHA1;
using SRP6 = Trinity::Crypto::SRP6;

/*static*/ const std::array<uint8, 1> SRP6::g = { 7 };
/*static*/ const std::array<uint8, 32> SRP6::N = HexStrToByteArray<32>("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7", true);
/*static*/ const BigNumber SRP6::_g(SRP6::g);
/*static*/ const BigNumber SRP6::_N(N);

/*static*/ std::pair<SRP6::Seed, SRP6::Verifier> SRP6::MakeRegistrationData(std::string const& username, std::string const& password)
{
    std::pair<SRP6::Seed, SRP6::Verifier> res;
    Crypto::GetRandomBytes(res.first); // random seed
    res.second = CalculateVerifier(username, password, res.first);
    return res;
}

/*static*/ std::pair<SRP6::Seed, SRP6::Verifier> SRP6::MakeRegistrationDataFromHash_DEPRECATED_DONOTUSE(SHA1::Digest const& hash)
{
    std::pair<SRP6::Seed, SRP6::Verifier> res;
    Crypto::GetRandomBytes(res.first);
    res.second = CalculateVerifierFromHash(hash, res.first);
    return res;
}

/*static*/ SRP6::Verifier SRP6::CalculateVerifier(std::string const& username, std::string const& password, SRP6::Seed const& seed)
{
    return CalculateVerifierFromHash(SHA1::GetDigestOf(username, ":", password), seed);
}

// merge this into CalculateVerifier once the sha_pass hack finally gets nuked from orbit
/*static*/ SRP6::Verifier SRP6::CalculateVerifierFromHash(SHA1::Digest const& hash, SRP6::Seed const& seed)
{
    return _g.ModExp(SHA1::GetDigestOf(seed, hash), _N).ToByteArray<32>(false);
}

/*static*/ SessionKey SRP6::SHA1Interleave(SRP6::EphemeralKey const& S)
{
    // split S into two buffers
    std::array<uint8, EPHEMERAL_KEY_LENGTH/2> buf0, buf1;
    for (size_t i = 0; i < EPHEMERAL_KEY_LENGTH/2; ++i)
    {
        buf0[i] = S[2 * i + 0];
        buf1[i] = S[2 * i + 1];
    }

    // find position of first nonzero byte
    size_t p = 0;
    while (p < EPHEMERAL_KEY_LENGTH && !S[p]) ++p;
    if (p & 1) ++p; // skip one extra byte if p is odd
    p /= 2; // offset into buffers

    // hash each of the halves, starting at the first nonzero byte
    SHA1::Digest const hash0 = SHA1::GetDigestOf(buf0.data() + p, EPHEMERAL_KEY_LENGTH/2 - p);
    SHA1::Digest const hash1 = SHA1::GetDigestOf(buf1.data() + p, EPHEMERAL_KEY_LENGTH/2 - p);

    SessionKey K;
    for (size_t i = 0; i < SHA1::DIGEST_LENGTH; ++i)
    {
        K[2 * i + 0] = hash0[i];
        K[2 * i + 1] = hash1[i];
    }
    return K;
}

SRP6::SRP6(std::string const& username, Seed const& seed, Verifier const& verifier)
    : _I(SHA1::GetDigestOf(username)), _b(Crypto::GetRandomBytes<19>()), _v(verifier, false), s(seed), B(_B(_b, _v)) {}

std::optional<SessionKey> SRP6::VerifyChallengeResponse(EphemeralKey const& A, SHA1::Digest const& clientM)
{
    ASSERT(!_used, "A single SRP6 object must only ever be used to verify ONCE!");
    _used = true;
    BigNumber const _A(A);
    if ((_A % _N).IsZero())
        return std::nullopt;
    BigNumber const u(SHA1::GetDigestOf(A, B));
    EphemeralKey const S = (_A * (_v.ModExp(u, _N))).ModExp(_b, N).ToByteArray<32>();

    // derive K from S
    SessionKey K = SHA1Interleave(S);

    // NgHash = H(N) xor H(g)
    SHA1::Digest const NHash = SHA1::GetDigestOf(N);
    SHA1::Digest const gHash = SHA1::GetDigestOf(g);
    SHA1::Digest NgHash;
    std::transform(NHash.begin(), NHash.end(), gHash.begin(), NgHash.begin(), std::bit_xor<>());

    SHA1::Digest const ourM = SHA1::GetDigestOf(NgHash, _I, s, A, B, K);
    if (ourM == clientM)
        return K;
    else
        return std::nullopt;
}
