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

#include "RSA.h"
#include "HMAC.h"
#include <openssl/pem.h>
#include <algorithm>
#include <memory>
#include <vector>
#include <cstring>

namespace
{
struct BIODeleter
{
    void operator()(BIO* bio)
    {
        BIO_free(bio);
    }
};

struct HMAC_SHA256_MD
{
    struct CTX_DATA
    {
        Trinity::Crypto::HMAC_SHA256* hmac;
    };

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#else
#pragma warning(push)
#pragma warning(disable: 4996)
#endif

    HMAC_SHA256_MD()
    {
        _md = EVP_MD_meth_new(NID_sha256, NID_sha256WithRSAEncryption);
        EVP_MD_meth_set_result_size(_md, Trinity::Crypto::Constants::SHA256_DIGEST_LENGTH_BYTES);
        EVP_MD_meth_set_flags(_md, EVP_MD_FLAG_DIGALGID_ABSENT);
        EVP_MD_meth_set_init(_md, &Init);
        EVP_MD_meth_set_update(_md, &UpdateData);
        EVP_MD_meth_set_final(_md, &Finalize);
        EVP_MD_meth_set_copy(_md, &Copy);
        EVP_MD_meth_set_cleanup(_md, &Cleanup);
        EVP_MD_meth_set_input_blocksize(_md, SHA256_CBLOCK);
        EVP_MD_meth_set_app_datasize(_md, sizeof(EVP_MD*) + sizeof(CTX_DATA*));
    }

    HMAC_SHA256_MD(HMAC_SHA256_MD const&) = delete;
    HMAC_SHA256_MD(HMAC_SHA256_MD&&) = delete;

    HMAC_SHA256_MD& operator=(HMAC_SHA256_MD const&) = delete;
    HMAC_SHA256_MD& operator=(HMAC_SHA256_MD&&) = delete;

    ~HMAC_SHA256_MD()
    {
        EVP_MD_meth_free(_md);
        _md = nullptr;
    }

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic pop
#else
#pragma warning(pop)
#endif

    operator EVP_MD const* () const
    {
        return _md;
    }

    static int Init(EVP_MD_CTX* ctx)
    {
        Cleanup(ctx);
        return 1;
    }

    static int UpdateData(EVP_MD_CTX* ctx, const void* data, size_t count)
    {
        CTX_DATA* ctxData = reinterpret_cast<CTX_DATA*>(EVP_MD_CTX_md_data(ctx));
        if (!ctxData->hmac)
            return 0;

        ctxData->hmac->UpdateData(reinterpret_cast<uint8 const*>(data), count);
        return 1;
    }

    static int Finalize(EVP_MD_CTX* ctx, unsigned char* md)
    {
        CTX_DATA* ctxData = reinterpret_cast<CTX_DATA*>(EVP_MD_CTX_md_data(ctx));
        if (!ctxData->hmac)
            return 0;

        ctxData->hmac->Finalize();
        memcpy(md, ctxData->hmac->GetDigest().data(), ctxData->hmac->GetDigest().size());
        return 1;
    }

    // post-processing after openssl memcpys from source to dest (no need to cleanup dest)
    static int Copy(EVP_MD_CTX* to, EVP_MD_CTX const* from)
    {
        CTX_DATA const* ctxDataFrom = reinterpret_cast<CTX_DATA const*>(EVP_MD_CTX_md_data(from));
        CTX_DATA* ctxDataTo = reinterpret_cast<CTX_DATA*>(EVP_MD_CTX_md_data(to));

        if (ctxDataFrom->hmac)
            ctxDataTo->hmac = new Trinity::Crypto::HMAC_SHA256(*ctxDataFrom->hmac);

        return 1;
    }

    static int Cleanup(EVP_MD_CTX* ctx)
    {
        CTX_DATA* data = reinterpret_cast<CTX_DATA*>(EVP_MD_CTX_md_data(ctx));
        if (data->hmac)
        {
            delete data->hmac;
            data->hmac = nullptr;
        }

        return 1;
    }

private:
    EVP_MD* _md;
} HmacSha256Md;
}

namespace Trinity::Crypto
{
EVP_MD const* RsaSignature::SHA256::GetGenerator() const
{
    return EVP_sha256();
}

void RsaSignature::SHA256::PostInitCustomizeContext(EVP_MD_CTX*)
{
}

EVP_MD const* RsaSignature::HMAC_SHA256::GetGenerator() const
{
    return HmacSha256Md;
}

void RsaSignature::HMAC_SHA256::PostInitCustomizeContext(EVP_MD_CTX* ctx)
{
    HMAC_SHA256_MD::CTX_DATA* ctxData = reinterpret_cast<HMAC_SHA256_MD::CTX_DATA*>(EVP_MD_CTX_md_data(ctx));

    delete ctxData->hmac;
    ctxData->hmac = new Crypto::HMAC_SHA256(_key, _keyLength);
}

RsaSignature::RsaSignature() : _ctx(Impl::GenericHashImpl::MakeCTX())
{
}

RsaSignature::RsaSignature(RsaSignature const& other) : _ctx(Impl::GenericHashImpl::MakeCTX())
{
    *this = other;
}

RsaSignature::RsaSignature(RsaSignature&& other) noexcept
{
    *this = std::move(other);
}

RsaSignature::~RsaSignature()
{
    EVP_MD_CTX_free(_ctx);
    EVP_PKEY_free(_key);
}

RsaSignature& RsaSignature::operator=(RsaSignature const& right)
{
    if (this == &right)
        return *this;

    EVP_MD_CTX_copy_ex(_ctx, right._ctx);   // Allowed to fail if not yet initialized
    _key = right._key;                      // EVP_PKEY uses reference counting internally, just copy the pointer
    EVP_PKEY_up_ref(_key);                  // Bump reference count for PKEY, as every instance of this class holds two references to PKEY and destructor decrements it twice
    return *this;
}

RsaSignature& RsaSignature::operator=(RsaSignature&& right) noexcept
{
    if (this == &right)
        return *this;

    _ctx = std::exchange(right._ctx, Impl::GenericHashImpl::MakeCTX());
    _key = std::exchange(right._key, EVP_PKEY_new());
    return *this;
}

bool RsaSignature::LoadKeyFromFile(std::string const& fileName)
{
    if (_key)
    {
        EVP_PKEY_free(_key);
        _key = nullptr;
    }

    std::unique_ptr<BIO, BIODeleter> keyBIO(BIO_new_file(fileName.c_str(), "r"));
    if (!keyBIO)
        return false;

    _key = EVP_PKEY_new();
    if (!PEM_read_bio_PrivateKey(keyBIO.get(), &_key, nullptr, nullptr))
        return false;

    return true;
}

bool RsaSignature::LoadKeyFromString(std::string const& keyPem)
{
    if (_key)
    {
        EVP_PKEY_free(_key);
        _key = nullptr;
    }

    std::unique_ptr<BIO, BIODeleter> keyBIO(BIO_new_mem_buf(
        const_cast<char*>(keyPem.c_str()) /*api hack - this function assumes memory is readonly but lacks const modifier*/,
        keyPem.length() + 1));
    if (!keyBIO)
        return false;

    _key = EVP_PKEY_new();
    if (!PEM_read_bio_PrivateKey(keyBIO.get(), &_key, nullptr, nullptr))
        return false;

    return true;
}

bool RsaSignature::Sign(uint8 const* message, std::size_t messageLength, DigestGenerator& generator, std::vector<uint8>& output)
{
    size_t signatureLength = 0;
    EVP_DigestSignInit(_ctx, nullptr, generator.GetGenerator(), nullptr, _key);
    generator.PostInitCustomizeContext(_ctx);
    EVP_DigestSignUpdate(_ctx, message, messageLength);
    int result = EVP_DigestSignFinal(_ctx, nullptr, &signatureLength);
    if (result == 0)
        return false;

    output.resize(signatureLength);
    result = EVP_DigestSignFinal(_ctx, output.data(), &signatureLength);
    std::reverse(output.begin(), output.end());
    return result != 0;
}
}
