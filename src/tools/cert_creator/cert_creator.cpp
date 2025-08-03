/* The MIT License (MIT)
 *
 * Copyright (c) 2022 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or *sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
*/

#include "Banner.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

#include <openssl/x509v3.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#ifdef _WIN32
#include <openssl/applink.c>
#endif

std::string domain;

/* Generates a 4096-bit RSA key. */
EVP_PKEY* generate_key()
{
    EVP_PKEY_CTX* ctx = nullptr;
    EVP_PKEY* pkey = nullptr;

    // Create the context for key generation
    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    if (!ctx)
    {
        ERR_print_errors_fp(stderr);
        return nullptr;
    }

    // Initialize the key generation
    if (EVP_PKEY_keygen_init(ctx) <= 0)
    {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    // Set the RSA key length to 4096 bits
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 4096) <= 0)
    {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    // Generate the key
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0)
    {
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    // Free the context after use
    EVP_PKEY_CTX_free(ctx);

    return pkey;
}

void add_subject_alt_name(X509* cert, const char* dns_name)
{
    // Erstellen einer neuen subjectAltName-Erweiterung
    X509_EXTENSION* ext = NULL;
    X509V3_CTX ctx;
    STACK_OF(GENERAL_NAME)* san_names = NULL;

    // Initialisierung des V3-Kontextes
    X509V3_set_ctx_nodb(&ctx);
    X509V3_set_ctx(&ctx, cert, cert, NULL, NULL, 0);

    // Allgemeine Namen (subjectAltName) erstellen
    san_names = sk_GENERAL_NAME_new_null();

    // DNS-Namen hinzufügen
    GENERAL_NAME* san = GENERAL_NAME_new();
    GENERAL_NAME_set0_value(san, GEN_DNS, ASN1_IA5STRING_new());
    ASN1_STRING_set((ASN1_STRING*)san->d.ia5, dns_name, strlen(dns_name));
    sk_GENERAL_NAME_push(san_names, san);

    // subjectAltName-Erweiterung erstellen
    ext = X509V3_EXT_i2d(NID_subject_alt_name, 0, san_names);

    // Erweiterung zum Zertifikat hinzufügen
    X509_add_ext(cert, ext, -1);

    // Bereinigen
    sk_GENERAL_NAME_pop_free(san_names, GENERAL_NAME_free);
    X509_EXTENSION_free(ext);
}

/* Generates a self-signed x509 certificate. */
X509 * generate_x509(EVP_PKEY * pkey)
{
    /* Allocate memory for the X509 structure. */
    X509 * x509 = X509_new();
    if(!x509)
    {
        std::cerr << "Unable to create X509 structure." << std::endl;
        return NULL;
    }

    /* Set the serial number. */
    ASN1_INTEGER_set(X509_get_serialNumber(x509), 1);

    /* This certificate is valid from now until exactly 10 years from now. */
    X509_gmtime_adj(X509_get_notBefore(x509), 0);
    X509_gmtime_adj(X509_get_notAfter(x509), 31536000*10L);

    /* Set the public key for our certificate. */
    X509_set_pubkey(x509, pkey);

    /* We want to copy the subject name to the issuer name. */
    X509_NAME * name = X509_get_subject_name(x509);

    /* Set the country code and common name. */
    X509_NAME_add_entry_by_txt(name, "C",  MBSTRING_ASC, (unsigned char *)domain.c_str(), -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "O",  MBSTRING_ASC, (unsigned char *)domain.c_str(), -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC, (unsigned char *)domain.c_str(), -1, -1, 0);

    add_subject_alt_name(x509, domain.c_str());

    /* Now set the issuer name. */
    X509_set_issuer_name(x509, name);

    /* Actually sign the certificate with our key. */
    if(!X509_sign(x509, pkey, EVP_sha1()))
    {
        std::cerr << "Error signing certificate." << std::endl;
        X509_free(x509);
        return NULL;
    }

    return x509;
}

bool write_to_disk(EVP_PKEY * pkey, X509 * x509)
{
    /* Open the PEM file for writing the key to disk. */
    FILE * pkey_file = fopen("bnetserver.key", "wb");
    if(!pkey_file)
    {
        std::cerr << "Unable to open \"bnetserver.key\" for writing." << std::endl;
        return false;
    }

    /* Write the key to disk. */
    bool ret = PEM_write_PrivateKey(pkey_file, pkey, NULL, NULL, 0, NULL, NULL);
    fclose(pkey_file);

    if(!ret)
    {
        std::cerr << "Unable to write private key to disk." << std::endl;
        return false;
    }

    /* Open the PEM file for writing the certificate to disk. */
    FILE * x509_file = fopen("bnetserver.crt", "wb");
    if(!x509_file)
    {
        std::cerr << "Unable to open \"bnetserver.crt\" for writing." << std::endl;
        return false;
    }

    /* Write the certificate to disk. */
    ret = PEM_write_X509(x509_file, x509);
    fclose(x509_file);

    if(!ret)
    {
        std::cerr << "Unable to write certificate to disk." << std::endl;
        return false;
    }

    return true;
}

int main(/*int argc, char ** argv*/)
{
    Trinity::Banner::Show("cert_creator", [](char const* text) { std::cout << text << std::endl; }, nullptr);

    std::cout << "Enter your domain name: ";
    std::cin >> domain;

    /* Generate the key. */
    std::cout << "Generating RSA key..." << std::endl;

    EVP_PKEY * pkey = generate_key();
    if(!pkey)
        return 1;

    /* Generate the certificate. */
    std::cout << "Generating x509 certificate..." << std::endl;

    X509 * x509 = generate_x509(pkey);
    if(!x509)
    {
        EVP_PKEY_free(pkey);
        return 1;
    }

    /* Write the private key and certificate out to disk. */
    std::cout << "Writing key and certificate to disk..." << std::endl;

    bool ret = write_to_disk(pkey, x509);
    EVP_PKEY_free(pkey);
    X509_free(x509);

    if(ret)
    {
        std::cout << "Success!" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "ERROR!" << std::endl;
        return 1;
    }
}
