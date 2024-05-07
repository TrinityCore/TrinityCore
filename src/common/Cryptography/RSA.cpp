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
#include "Memory.h"
#include <openssl/pem.h>
#include <algorithm>
#include <memory>
#include <vector>
#include <cstring>

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
#include <openssl/core_names.h>
#include <openssl/params.h>
#include <openssl/provider.h>
#endif

namespace
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L

extern OSSL_DISPATCH const HMAC_SHA256_funcs[];
extern OSSL_ALGORITHM const HMAC_SHA256_algs[];
extern OSSL_DISPATCH const HMAC_SHA256_method[];

#endif

struct HMAC_SHA256_MD
{
    struct CTX_DATA
    {
        Trinity::Crypto::HMAC_SHA256* hmac;
    };

#if OPENSSL_VERSION_NUMBER < 0x30000000L

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

    EVP_MD* GetMd() const
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

#else

    HMAC_SHA256_MD()
    {
        _lib = OSSL_LIB_CTX_new();
        OSSL_PROVIDER_add_builtin(_lib, "trinity-rsa-hmac-sha256", &InitProvider);
        _handle = OSSL_PROVIDER_try_load(_lib, "trinity-rsa-hmac-sha256", 1);
    }

    ~HMAC_SHA256_MD()
    {
        if (_handle)
            OSSL_PROVIDER_unload(_handle);
        if (_lib)
            OSSL_LIB_CTX_free(_lib);
    }

    OSSL_LIB_CTX* GetLib() const
    {
        return _lib;
    }

    static int InitProvider(const OSSL_CORE_HANDLE* /*handle*/, const OSSL_DISPATCH* /*in*/, const OSSL_DISPATCH** out, void** /*provctx*/)
    {
        *out = HMAC_SHA256_method;
        return 1;
    }

    static OSSL_ALGORITHM const* QueryProvider(void* /*provctx*/, int operation_id, int* no_cache)
    {
        *no_cache = 0;
        if (operation_id == OSSL_OP_DIGEST)
            return HMAC_SHA256_algs;

        return nullptr;
    }

    static CTX_DATA* DigestNew()
    {
        CTX_DATA* data = new CTX_DATA();
        data->hmac = nullptr;
        return data;
    }

    static int DigestInit(void* dctx, OSSL_PARAM const* params)
    {
        CTX_DATA* ctxData = reinterpret_cast<CTX_DATA*>(dctx);

        delete ctxData->hmac;
        if (OSSL_PARAM const* keyParam = OSSL_PARAM_locate_const(params, "hmac-key"))
        {
            uint8 const* key = nullptr;
            size_t keyLength = 0;
            if (OSSL_PARAM_get_octet_ptr(keyParam, reinterpret_cast<void const**>(&key), &keyLength))
            {
                ctxData->hmac = new Trinity::Crypto::HMAC_SHA256(key, keyLength);
                return 1;
            }
        }

        return 0;
    }

    static int DigestUpdate(void* dctx, const unsigned char* in, size_t inl)
    {
        reinterpret_cast<CTX_DATA*>(dctx)->hmac->UpdateData(in, inl);
        return 1;
    }

    static int DigestFinal(void* dctx, unsigned char* out, size_t* outl, size_t outsz)
    {
        CTX_DATA* ctxData = reinterpret_cast<CTX_DATA*>(dctx);
        ctxData->hmac->Finalize();
        *outl = std::min(ctxData->hmac->GetDigest().size(), outsz);
        memcpy(out, ctxData->hmac->GetDigest().data(), *outl);
        return 1;
    }

    static void DigestFree(void* dctx)
    {
        CTX_DATA* data = reinterpret_cast<CTX_DATA*>(dctx);
        if (data->hmac)
        {
            delete data->hmac;
            data->hmac = nullptr;
        }
        delete data;
    }

    static void* DigestDup(void* dctx)
    {
        CTX_DATA const* ctxDataFrom = reinterpret_cast<CTX_DATA const*>(dctx);
        CTX_DATA* ctxDataTo = DigestNew();
        if (ctxDataFrom->hmac)
            ctxDataTo->hmac = new Trinity::Crypto::HMAC_SHA256(*ctxDataFrom->hmac);

        return ctxDataTo;
    }

    static int DigestGetParams(OSSL_PARAM params[])
    {
        OSSL_PARAM* p = nullptr;

        p = OSSL_PARAM_locate(params, OSSL_DIGEST_PARAM_BLOCK_SIZE);
        if (p != nullptr && !OSSL_PARAM_set_size_t(p, SHA256_CBLOCK))
            return 0;

        p = OSSL_PARAM_locate(params, OSSL_DIGEST_PARAM_SIZE);
        if (p != nullptr && !OSSL_PARAM_set_size_t(p, Trinity::Crypto::Constants::SHA256_DIGEST_LENGTH_BYTES))
            return 0;

        p = OSSL_PARAM_locate(params, OSSL_DIGEST_PARAM_XOF);
        if (p != nullptr && !OSSL_PARAM_set_int(p, 0))
            return 0;

        p = OSSL_PARAM_locate(params, OSSL_DIGEST_PARAM_ALGID_ABSENT);
        if (p != nullptr && !OSSL_PARAM_set_int(p, 1))
            return 0;

        return 1;
    }

    static OSSL_PARAM const* DigestGettableParams()
    {
        static constexpr OSSL_PARAM Params[] =
        {
            OSSL_PARAM_size_t(OSSL_DIGEST_PARAM_BLOCK_SIZE, NULL),
            OSSL_PARAM_size_t(OSSL_DIGEST_PARAM_SIZE, NULL),
            OSSL_PARAM_int(OSSL_DIGEST_PARAM_XOF, NULL),
            OSSL_PARAM_int(OSSL_DIGEST_PARAM_ALGID_ABSENT, NULL),
            OSSL_PARAM_END
        };

        return Params;
    }

private:
    OSSL_LIB_CTX* _lib;
    OSSL_PROVIDER* _handle;
#endif
} const HmacSha256Md;

#if OPENSSL_VERSION_NUMBER >= 0x30000000L

OSSL_DISPATCH const HMAC_SHA256_funcs[] =
{
    { OSSL_FUNC_DIGEST_NEWCTX, (void (*)())HMAC_SHA256_MD::DigestNew },
    { OSSL_FUNC_DIGEST_INIT, (void (*)())HMAC_SHA256_MD::DigestInit },
    { OSSL_FUNC_DIGEST_UPDATE, (void (*)())HMAC_SHA256_MD::DigestUpdate },
    { OSSL_FUNC_DIGEST_FINAL, (void (*)())HMAC_SHA256_MD::DigestFinal },
    { OSSL_FUNC_DIGEST_FREECTX, (void (*)())HMAC_SHA256_MD::DigestFree },
    { OSSL_FUNC_DIGEST_DUPCTX, (void (*)())HMAC_SHA256_MD::DigestDup },
    { OSSL_FUNC_DIGEST_GET_PARAMS, (void (*)())HMAC_SHA256_MD::DigestGetParams },
    { OSSL_FUNC_DIGEST_GETTABLE_PARAMS, (void (*)())HMAC_SHA256_MD::DigestGettableParams },
    { 0, nullptr}
};

OSSL_ALGORITHM const HMAC_SHA256_algs[] =
{
    // pretend this custom HMAC_SHA256 is a regular SHA256 - openssl has a whitelist of allowed digests for RSA and HMAC_SHA256 is not on it
    { OSSL_DIGEST_NAME_SHA2_256, "provider=trinity-rsa-hmac-sha256", HMAC_SHA256_funcs, "HMAC SHA265 \"digest\" for RSA" },
    { nullptr, nullptr, nullptr, nullptr}
};

OSSL_DISPATCH const HMAC_SHA256_method[] =
{
    { OSSL_FUNC_PROVIDER_QUERY_OPERATION, (void(*)())HMAC_SHA256_MD::QueryProvider },
    { 0, nullptr },
};
#endif

}

namespace Trinity::Crypto
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L

void RsaSignature::DigestGenerator::EVP_MD_Deleter::operator()(EVP_MD* md) const
{
    EVP_MD_free(md);
}

std::unique_ptr<EVP_MD, RsaSignature::DigestGenerator::EVP_MD_Deleter> RsaSignature::SHA256::GetGenerator() const
{
    return std::unique_ptr<EVP_MD, EVP_MD_Deleter>(EVP_MD_fetch(nullptr, OSSL_DIGEST_NAME_SHA2_256, "provider=default"));
}

OSSL_LIB_CTX* RsaSignature::SHA256::GetLib() const
{
    return nullptr;
}

std::unique_ptr<OSSL_PARAM[]> RsaSignature::SHA256::GetParams() const
{
    return nullptr;
}

std::unique_ptr<EVP_MD, RsaSignature::DigestGenerator::EVP_MD_Deleter> RsaSignature::HMAC_SHA256::GetGenerator() const
{
    return std::unique_ptr<EVP_MD, EVP_MD_Deleter>(EVP_MD_fetch(HmacSha256Md.GetLib(), OSSL_DIGEST_NAME_SHA2_256, "provider=trinity-rsa-hmac-sha256"));
}

OSSL_LIB_CTX* RsaSignature::HMAC_SHA256::GetLib() const
{
    return HmacSha256Md.GetLib();
}

std::unique_ptr<OSSL_PARAM[]> RsaSignature::HMAC_SHA256::GetParams() const
{
    return std::unique_ptr<OSSL_PARAM[]>(new OSSL_PARAM[2]
    {
        OSSL_PARAM_octet_ptr("hmac-key", const_cast<void**>(reinterpret_cast<void const* const*>(&_key)), _keyLength),
        OSSL_PARAM_END
    });
}

#else

void RsaSignature::DigestGenerator::EVP_MD_Deleter::operator()(EVP_MD* /*md*/) const
{
}

std::unique_ptr<EVP_MD, RsaSignature::DigestGenerator::EVP_MD_Deleter> RsaSignature::SHA256::GetGenerator() const
{
    return std::unique_ptr<EVP_MD, EVP_MD_Deleter>(const_cast<EVP_MD*>(EVP_sha256()));
}

void RsaSignature::SHA256::PostInitCustomizeContext(EVP_MD_CTX*)
{
}

std::unique_ptr<EVP_MD, RsaSignature::DigestGenerator::EVP_MD_Deleter> RsaSignature::HMAC_SHA256::GetGenerator() const
{
    return std::unique_ptr<EVP_MD, EVP_MD_Deleter>(HmacSha256Md.GetMd());
}

void RsaSignature::HMAC_SHA256::PostInitCustomizeContext(EVP_MD_CTX* ctx)
{
    HMAC_SHA256_MD::CTX_DATA* ctxData = reinterpret_cast<HMAC_SHA256_MD::CTX_DATA*>(EVP_MD_CTX_md_data(ctx));

    delete ctxData->hmac;
    ctxData->hmac = new Crypto::HMAC_SHA256(_key, _keyLength);
}

#endif

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

    auto keyBIO = make_unique_ptr_with_deleter(BIO_new_file(fileName.c_str(), "r"), &BIO_free);
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

    auto keyBIO = make_unique_ptr_with_deleter(BIO_new_mem_buf(
        const_cast<char*>(keyPem.c_str()) /*api hack - this function assumes memory is readonly but lacks const modifier*/,
        keyPem.length() + 1), &BIO_free);
    if (!keyBIO)
        return false;

    _key = EVP_PKEY_new();
    if (!PEM_read_bio_PrivateKey(keyBIO.get(), &_key, nullptr, nullptr))
        return false;

    return true;
}

bool RsaSignature::Sign(uint8 const* message, std::size_t messageLength, DigestGenerator& generator, std::vector<uint8>& output)
{
    std::unique_ptr<EVP_MD, DigestGenerator::EVP_MD_Deleter> digestGenerator = generator.GetGenerator();

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    auto keyCtx = make_unique_ptr_with_deleter(EVP_PKEY_CTX_new_from_pkey(generator.GetLib(), _key, nullptr), &EVP_PKEY_CTX_free);
    EVP_MD_CTX_set_pkey_ctx(_ctx, keyCtx.get());

    std::unique_ptr<OSSL_PARAM[]> params = generator.GetParams();
    int result = EVP_DigestSignInit_ex(_ctx, nullptr, EVP_MD_get0_name(digestGenerator.get()), generator.GetLib(),  nullptr, _key, params.get());
#else
    int result = EVP_DigestSignInit(_ctx, nullptr, digestGenerator.get(), nullptr, _key);
    generator.PostInitCustomizeContext(_ctx);
#endif
    if (result == 0)
        return false;

    result = EVP_DigestSignUpdate(_ctx, message, messageLength);
    if (result == 0)
        return false;

    size_t signatureLength = 0;
    result = EVP_DigestSignFinal(_ctx, nullptr, &signatureLength);
    if (result == 0)
        return false;

    output.resize(signatureLength);
    result = EVP_DigestSignFinal(_ctx, output.data(), &signatureLength);
    std::reverse(output.begin(), output.end());
    return result != 0;
}
}
