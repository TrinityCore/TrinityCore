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

#include "SslContext.h"
#include "Config.h"
#include "Log.h"
#include "Memory.h"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <openssl/store.h>
#include <openssl/ui.h>

bool Battlenet::SslContext::_usesDevWildcardCertificate = false;

namespace
{
auto CreatePasswordUiMethodFromPemCallback(::pem_password_cb* callback)
{
    return Trinity::make_unique_ptr_with_deleter(UI_UTIL_wrap_read_pem_callback(callback, 0), ::UI_destroy_method);
}

auto OpenOpenSSLStore(boost::filesystem::path const& storePath, UI_METHOD const* passwordCallback, void* passwordCallbackData)
{
    std::string uri;
    uri.reserve(6 + storePath.size());

    uri += "file:";
    std::string genericPath = storePath.generic_string();
    if (!genericPath.empty() && !genericPath.starts_with('/'))
        uri += '/'; // ensure the path starts with / (windows special case, unix absolute paths already do)

    uri += genericPath;

    return Trinity::make_unique_ptr_with_deleter(OSSL_STORE_open(uri.c_str(), passwordCallback, passwordCallbackData, nullptr, nullptr), ::OSSL_STORE_close);
}

boost::system::error_code GetLastOpenSSLError()
{
    auto ossl_error = ::ERR_get_error();
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    if (ERR_SYSTEM_ERROR(ossl_error))
        return boost::system::error_code(static_cast<int>(::ERR_GET_REASON(ossl_error)), boost::asio::error::get_system_category());
#endif

    return boost::system::error_code(static_cast<int>(ossl_error), boost::asio::error::get_ssl_category());
}
}

bool Battlenet::SslContext::Initialize()
{
    boost::system::error_code err;
#define LOAD_CHECK(fn) do { fn; \
    if (err) \
    { \
        TC_LOG_ERROR("server.ssl", #fn " failed: {}", err.message()); \
        return false; \
    } } while (0)

    std::string certificateChainFile = sConfigMgr->GetStringDefault("CertificatesFile", "./bnetserver.cert.pem");

    auto passwordCallback = [](std::size_t /*max_length*/, boost::asio::ssl::context::password_purpose /*purpose*/) -> std::string
    {
        return sConfigMgr->GetStringDefault("PrivateKeyPassword", "");
    };

    LOAD_CHECK(instance().set_password_callback(passwordCallback, err));

    SSL_CTX* nativeContext = instance().native_handle();
    auto password_ui_method = CreatePasswordUiMethodFromPemCallback(SSL_CTX_get_default_passwd_cb(nativeContext));

    auto store = OpenOpenSSLStore(boost::filesystem::absolute(certificateChainFile),
        password_ui_method.get(), SSL_CTX_get_default_passwd_cb_userdata(nativeContext));

    if (!store)
    {
        err = GetLastOpenSSLError();
        TC_LOG_ERROR("server.ssl", "OSSL_STORE_open failed: {}", err.message());
        return false;
    }

    EVP_PKEY* key = nullptr;
    STACK_OF(X509)* certs = sk_X509_new_null();
    while (!OSSL_STORE_eof(store.get()))
    {
        OSSL_STORE_INFO* info = OSSL_STORE_load(store.get());
        if (!info)
            continue;

        switch (OSSL_STORE_INFO_get_type(info))
        {
            case OSSL_STORE_INFO_PKEY:
                key = OSSL_STORE_INFO_get1_PKEY(info);
                break;
            case OSSL_STORE_INFO_CERT:
                sk_X509_push(certs, OSSL_STORE_INFO_get1_CERT(info));
                break;
            default:
                break;
        }
    }

    if (sk_X509_num(certs) > 0)
    {
        X509* cert = sk_X509_shift(certs);

        _usesDevWildcardCertificate = [&]
        {
            X509_NAME* nm = X509_get_subject_name(cert);
            int32 lastpos = -1;
            while (true)
            {
                lastpos = X509_NAME_get_index_by_NID(nm, NID_commonName, lastpos);
                if (lastpos == -1)
                    break;

                X509_NAME_ENTRY* e = X509_NAME_get_entry(nm, lastpos);
                if (!e)
                    continue;

                ASN1_STRING* text = X509_NAME_ENTRY_get_data(e);
                if (!text)
                    continue;

                unsigned char* utf8TextRaw = nullptr;
                if (int utf8Length = ASN1_STRING_to_UTF8(&utf8TextRaw, text); utf8Length >= 0)
                {
                    auto utf8Text = Trinity::make_unique_ptr_with_deleter(utf8TextRaw, [](unsigned char* ptr) { ::OPENSSL_free(ptr); });
                    if (std::string_view(reinterpret_cast<char const*>(utf8Text.get()), utf8Length) == "*.*")
                        return true;
                }
            }

            return false;
        }();

        SSL_CTX_use_cert_and_key(nativeContext, cert, key, certs, 1);
    }

    sk_X509_free(certs);

    if (!key)
    {
        std::string privateKeyFile = sConfigMgr->GetStringDefault("PrivateKeyFile", "./bnetserver.key.pem");
        LOAD_CHECK(instance().use_private_key_file(privateKeyFile, boost::asio::ssl::context::pem, err));
    }

#undef LOAD_CHECK

    return true;
}

boost::asio::ssl::context& Battlenet::SslContext::instance()
{
    static boost::asio::ssl::context context(boost::asio::ssl::context::tls);
    return context;
}
