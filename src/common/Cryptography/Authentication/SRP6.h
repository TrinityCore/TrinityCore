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

#include "BigNumber.h"
#include "CryptoHash.h"
#include "Define.h"
#include "Optional.h"
#include <array>
#include <span>

namespace Trinity::Crypto
{
namespace SRP
{
    static constexpr size_t SALT_LENGTH = 32;
    using Salt = std::array<uint8, SALT_LENGTH>;

    using Verifier = std::vector<uint8>;

    class TC_COMMON_API SRP6
    {
    protected:
        struct ForRegistrationTag { };

    public:
        explicit SRP6(BigNumber const& i, Salt const& salt, Verifier const& verifier, BigNumber const& N, BigNumber const& g, BigNumber const& k);
        explicit SRP6(ForRegistrationTag);

        SRP6(SRP6 const&) = delete;
        SRP6(SRP6&&) = delete;
        SRP6& operator=(SRP6 const&) = delete;
        SRP6& operator=(SRP6&&) = delete;

        virtual ~SRP6() = default;

        virtual BigNumber const& GetN() const = 0;
        virtual BigNumber const& Getg() const = 0;

        Optional<BigNumber> VerifyClientEvidence(BigNumber const& A, BigNumber const& clientM1);

        virtual BigNumber CalculateServerEvidence(BigNumber const& A, BigNumber const& clientM1, BigNumber const& K) const = 0;

        template<typename Impl>
        static std::pair<Salt, Verifier> MakeRegistrationData(std::string const& username, std::string const& password)
        {
            Impl impl(ForRegistrationTag{});
            return { impl.s, impl.CalculateVerifier(username, password, impl.s) };
        }

        bool CheckCredentials(std::string const& username, std::string const& password) const;

        Salt const s; // s - the user's password salt, random, used to calculate v on registration

    protected:
        static BigNumber CalculatePrivateB(BigNumber const& N);

        BigNumber CalculatePublicB(BigNumber const& N, BigNumber const& g, BigNumber const& k) const;

        virtual BigNumber CalculateX(std::string const& username, std::string const& password, Salt const& salt) const = 0;

        Verifier CalculateVerifier(std::string const& username, std::string const& password, Salt const& salt) const;

        virtual Optional<BigNumber> DoVerifyClientEvidence(BigNumber const& A, BigNumber const& clientM1) = 0;

        BigNumber const I; // H(I) - the username, all uppercase
        BigNumber const b; // b - randomly chosen by the server, same length as N, never given out
        BigNumber const v; // v - the user's password verifier, derived from s + H(USERNAME || ":" || PASSWORD)

    public:
        BigNumber const B; // B = k*v + g^b

    private:
        bool _used = false; // a single instance can only be used to verify once
    };

    class TC_COMMON_API GruntSRP6 final : public SRP6
    {
    public:
        static constexpr size_t EPHEMERAL_KEY_LENGTH = 32;

        using EphemeralKey = std::array<uint8, EPHEMERAL_KEY_LENGTH>;

        using SessionKey = std::array<uint8, SHA1::DIGEST_LENGTH * 2>;

        static BigNumber const N; // the modulus, an algorithm parameter; all operations are mod this
        static BigNumber const g; // a [g]enerator for the ring of integers mod N, algorithm parameter

        explicit GruntSRP6(std::string const& username, Salt const& salt, Verifier const& verifier);
        explicit GruntSRP6(ForRegistrationTag t) : SRP6(t) { }

        BigNumber const& GetN() const override { return N; }
        BigNumber const& Getg() const override { return g; }

        BigNumber CalculateServerEvidence(BigNumber const& A, BigNumber const& clientM1, BigNumber const& K) const override;

    protected:
        BigNumber CalculateX(std::string const& username, std::string const& password, Salt const& salt) const override;

        Optional<BigNumber> DoVerifyClientEvidence(BigNumber const& A, BigNumber const& clientM1) override;

        static SessionKey SHA1Interleave(EphemeralKey const& S);
    };

    class TC_COMMON_API BnetSRP6Base : public SRP6
    {
    public:
        explicit BnetSRP6Base(BigNumber const& i, Salt const& salt, Verifier const& verifier, BigNumber const& N, BigNumber const& g, BigNumber const& k);
        explicit BnetSRP6Base(ForRegistrationTag t) : SRP6(t) { }

        BigNumber CalculateServerEvidence(BigNumber const& A, BigNumber const& clientM1, BigNumber const& K) const final;

        virtual uint8 GetVersion() const = 0;
        virtual uint32 GetXIterations() const = 0;

    protected:
        Optional<BigNumber> DoVerifyClientEvidence(BigNumber const& A, BigNumber const& clientM1) final;

        virtual BigNumber CalculateU(BigNumber const& A) const = 0;

        virtual BigNumber DoCalculateEvidence(std::span<BigNumber const*> bns) const = 0;

        template<typename CryptoHash>
        BigNumber DoCalculateEvidence(std::span<BigNumber const*> bns) const
        {
            CryptoHash hash;
            for (BigNumber const* bn : bns)
                hash.UpdateData(GetBrokenEvidenceVector(*bn));

            hash.Finalize();
            return BigNumber(hash.GetDigest(), false);
        }

        static std::vector<uint8> GetBrokenEvidenceVector(BigNumber const& bn);
    };

    class TC_COMMON_API BnetSRP6v1Base : public BnetSRP6Base
    {
    public:
        static BigNumber const N; // the modulus, an algorithm parameter; all operations are mod this
        static BigNumber const g; // a [g]enerator for the ring of integers mod N, algorithm parameter

        explicit BnetSRP6v1Base(std::string const& username, Salt const& salt, Verifier const& verifier, BigNumber const& k);
        explicit BnetSRP6v1Base(ForRegistrationTag t) : BnetSRP6Base(t) { }

        BigNumber const& GetN() const final { return N; }
        BigNumber const& Getg() const final { return g; }

        uint8 GetVersion() const final { return 1; }
        uint32 GetXIterations() const final { return 1; }

    protected:
        BigNumber CalculateX(std::string const& username, std::string const& password, Salt const& salt) const final;
    };

    class TC_COMMON_API BnetSRP6v2Base : public BnetSRP6Base
    {
    public:
        static BigNumber const N; // the modulus, an algorithm parameter; all operations are mod this
        static BigNumber const g; // a [g]enerator for the ring of integers mod N, algorithm parameter

        explicit BnetSRP6v2Base(std::string const& username, Salt const& salt, Verifier const& verifier, BigNumber const& k);
        explicit BnetSRP6v2Base(ForRegistrationTag t) : BnetSRP6Base(t) { }

        BigNumber const& GetN() const final { return N; }
        BigNumber const& Getg() const final { return g; }

        uint8 GetVersion() const final { return 2; }
        uint32 GetXIterations() const final { return 15000; }

    protected:
        BigNumber CalculateX(std::string const& username, std::string const& password, Salt const& salt) const final;
    };

    template<typename CryptoHash>
    class BnetSRP6v1 final : public BnetSRP6v1Base
    {
    public:
        BnetSRP6v1(std::string const& username, Salt const& salt, Verifier const& verifier)
            : BnetSRP6v1Base(username, salt, verifier, BigNumber(CryptoHash::GetDigestOf(N.ToByteArray<128>(false), g.ToByteArray<128>(false)), false))
        {
        }

        explicit BnetSRP6v1(ForRegistrationTag t) : BnetSRP6v1Base(t) { }

    protected:
        BigNumber CalculateU(BigNumber const& A) const override
        {
            return BigNumber(CryptoHash::GetDigestOf(A.ToByteArray<128>(false), B.ToByteArray<128>(false)), false);
        }

        BigNumber DoCalculateEvidence(std::span<BigNumber const*> bns) const override
        {
            return BnetSRP6Base::DoCalculateEvidence<CryptoHash>(bns);
        }
    };

    template<typename CryptoHash>
    class BnetSRP6v2 final : public BnetSRP6v2Base
    {
    public:
        BnetSRP6v2(std::string const& username, Salt const& salt, Verifier const& verifier)
            : BnetSRP6v2Base(username, salt, verifier, BigNumber(CryptoHash::GetDigestOf(N.ToByteArray<256>(false), g.ToByteArray<256>(false)), false))
        {
        }

        explicit BnetSRP6v2(ForRegistrationTag t) : BnetSRP6v2Base(t) { }

    protected:
        BigNumber CalculateU(BigNumber const& A) const override
        {
            return BigNumber(CryptoHash::GetDigestOf(A.ToByteArray<256>(false), B.ToByteArray<256>(false)), false);
        }

        BigNumber DoCalculateEvidence(std::span<BigNumber const*> bns) const override
        {
            return BnetSRP6Base::DoCalculateEvidence<CryptoHash>(bns);
        }
    };
}

using SRP::SRP6;
}

#endif
