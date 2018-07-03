/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONNECTION_PATCHER_PATCHES_COMMON_HPP
#define CONNECTION_PATCHER_PATCHES_COMMON_HPP

#include <vector>

namespace Connection_Patcher
{
    namespace Patches
    {
        struct Common
        {
            static std::vector<unsigned char> Portal() { return { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; }
            static std::vector<unsigned char> Modulus()
            {
                return
                {
                    0x5F, 0xD6, 0x80, 0x0B, 0xA7, 0xFF, 0x01, 0x40, 0xC7, 0xBC, 0x8E, 0xF5, 0x6B, 0x27, 0xB0, 0xBF,
                    0xF0, 0x1D, 0x1B, 0xFE, 0xDD, 0x0B, 0x1F, 0x3D, 0xB6, 0x6F, 0x1A, 0x48, 0x0D, 0xFB, 0x51, 0x08,
                    0x65, 0x58, 0x4F, 0xDB, 0x5C, 0x6E, 0xCF, 0x64, 0xCB, 0xC1, 0x6B, 0x2E, 0xB8, 0x0F, 0x5D, 0x08,
                    0x5D, 0x89, 0x06, 0xA9, 0x77, 0x8B, 0x9E, 0xAA, 0x04, 0xB0, 0x83, 0x10, 0xE2, 0x15, 0x4D, 0x08,
                    0x77, 0xD4, 0x7A, 0x0E, 0x5A, 0xB0, 0xBB, 0x00, 0x61, 0xD7, 0xA6, 0x75, 0xDF, 0x06, 0x64, 0x88,
                    0xBB, 0xB9, 0xCA, 0xB0, 0x18, 0x8B, 0x54, 0x13, 0xE2, 0xCB, 0x33, 0xDF, 0x17, 0xD8, 0xDA, 0xA9,
                    0xA5, 0x60, 0xA3, 0x1F, 0x4E, 0x27, 0x05, 0x98, 0x6F, 0xAA, 0xEE, 0x14, 0x3B, 0xF3, 0x97, 0xA8,
                    0x12, 0x02, 0x94, 0x0D, 0x84, 0xDC, 0x0E, 0xF1, 0x76, 0x23, 0x95, 0x36, 0x13, 0xF9, 0xA9, 0xC5,
                    0x48, 0xDB, 0xDA, 0x86, 0xBE, 0x29, 0x22, 0x54, 0x44, 0x9D, 0x9F, 0x80, 0x7B, 0x07, 0x80, 0x30,
                    0xEA, 0xD2, 0x83, 0xCC, 0xCE, 0x37, 0xD1, 0xD1, 0xCF, 0x85, 0xBE, 0x91, 0x25, 0xCE, 0xC0, 0xCC,
                    0x55, 0xC8, 0xC0, 0xFB, 0x38, 0xC5, 0x49, 0x03, 0x6A, 0x02, 0xA9, 0x9F, 0x9F, 0x86, 0xFB, 0xC7,
                    0xCB, 0xC6, 0xA5, 0x82, 0xA2, 0x30, 0xC2, 0xAC, 0xE6, 0x98, 0xDA, 0x83, 0x64, 0x43, 0x7F, 0x0D,
                    0x13, 0x18, 0xEB, 0x90, 0x53, 0x5B, 0x37, 0x6B, 0xE6, 0x0D, 0x80, 0x1E, 0xEF, 0xED, 0xC7, 0xB8,
                    0x68, 0x9B, 0x4C, 0x09, 0x7B, 0x60, 0xB2, 0x57, 0xD8, 0x59, 0x8D, 0x7F, 0xEA, 0xCD, 0xEB, 0xC4,
                    0x60, 0x9F, 0x45, 0x7A, 0xA9, 0x26, 0x8A, 0x2F, 0x85, 0x0C, 0xF2, 0x19, 0xC6, 0x53, 0x92, 0xF7,
                    0xF0, 0xB8, 0x32, 0xCB, 0x5B, 0x66, 0xCE, 0x51, 0x54, 0xB4, 0xC3, 0xD3, 0xD4, 0xDC, 0xB3, 0xEE
                };
            }
            static std::string VersionsFile() { return "trinity6.github.io/%s/%s/build/versi"; };
            static std::vector<unsigned char> CertBundleUrl() { return { 'h', 't', 't', 'p', 's', ':', '/', '/', 't', 'r', 'i', 'n', 'i', 't', 'y', '6', '.', 'g', 'i', 't', 'h', 'u', 'b', '.', 'i', 'o', '/', 'B', 'n', 'e', 't', '/', 'z', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', '/', 'c', 'l', 'i', 'e', 'n', 't', '/', 'b', 'g', 's', '-', 'k', 'e', 'y', '-', 'f', 'i', 'n', 'g', 'e', 'r', 'p', 'r', 'i', 'n', 't' }; }
            static std::string CertificateBundle()
            {
                return
R"({
    "Created": 1455065214,
    "Certificates": [
        { "Uri": "*.*", "ShaHashPublicKeyInfo": "B1241D831999D4A67B0C6F9A687331C87FBA9B2CDC4CAC3694ADAD622F01952B" }
    ],
    "PublicKeys": [
        { "Uri": "*.*", "ShaHashPublicKeyInfo": "B1241D831999D4A67B0C6F9A687331C87FBA9B2CDC4CAC3694ADAD622F01952B" }
    ],
    "SigningCertificates": [
        { "RawData": "-----BEGIN CERTIFICATE-----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-----END CERTIFICATE-----" }
    ]
})";
            }
            static std::string CertificatePrivateKey()
            {
                return
R"(-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAwN3EYmKhDGawGrh62wAgjh3wr4CcV6lp61Ev39jzTkgetXDB
F2SWC9s/pzS/h10HQwL9P0cYlqbZHj/darOphcqplK05WsJC876lUASSeVWVPiHs
mfpSzjx65qV2PfmcNE1SUEizOOfpaoxvLfVqh5y4MkuSxXxOXCXS9CnQBwQo8f/4
uV6czHZgigi7CSID75VK3VhqvlTaLYFoEiOpjWNAQ7x/18sv+VoSVuX+alYez2PD
wU+hl0CpzEIqtaavntce9sQ3uEd3eXYGAJp6X+bOVItRmUhb3WXoIXmHMaLe5oSc
cINa17ZL7H2ISOqr/1Pfq84Ck/VStbzEfJdTZwIDAQABAoIBAHcu1DQERQd30a3B
gNIi4vtPzzN1I6gcXgL3+cC3vasLcEapdflxxDNxeoVmWFFbEKi9iSf4VF6MnrFN
wBM3ETRHh8IDxeSrFVqw3lFzcdyfIYnyxtZkVZVy1HQBne8wd/HuMkbAllg9IAYi
4HWjKgDBvSX/g6Sca4QQL6uIxy/9s3Z4K2vU8KbvUpwo+ON4HMt61fgrIrbEUVCl
TMCVEf8UphwHctmQJb/Pr0+BCTdiv04ga1dkt+ZyR2o0VN6T/zKDqk4m1sSl0GZz
8sn63GbuTlwHcm9GgkaxoeeZJK1/sdOSIZN8W3PpnyHrAZJlNOY7G684F1mBaWV1
PGCcVtkCgYEA8jCDTGub7ZyMk48x+8L3Devja3TQz7YNIGkVEbQBpNw4gDV8j1m6
EgqFdzowkY+gbA76ylNfm6Aa66RDR/LbTbXlsNd8YkXcbU3xDQ96F6cS51VBkled
hq+iAuGJB9VYN5yP1P/Oswg/AFMjOnsfBL/1zFo26364z9x8zazw0wsCgYEAy907
mpkk59AQ4YIDSR9wK2YpXv6HoBPFld6m7PAnBWFO0uNtQ0YppbYbrhmDqrxUoFud
ZiEHIa0gLlp9lHr+UdUAMPDlJ6gbMnJW3U5qiVuuZA13tiZFlv11qUeU1tQUzTUv
ZoIISN15Im0PQzUFbTxSFbS+vTYjsedv1C9UOpUCgYEAkTaTUzvmV3cZNtSSFLFW
ros0Zda56QDwJ/G5x06V+cJtQjpPwCf9kBms4ssKGgzzFDd7GdsZpVc/LPDlwnsU
ESkyWnEpzEa1HvivwrP38bykcf5Ffbh45CvkyTNvlTnPVjDScNUcm24jUE+I/OSb
uZ5bg7bH3TWzHDbIwg2iq/cCgYB+DPqvqoVhOAtYBBWX/vJSQ0bNT7/4QIFpG1RH
KG5YK0SbrLeAYz+ZELKowWniBbSluj/mSAGq1usQ/i6rwijB3FvT5v8puA2o8X24
NKY27BM2FgWxAJUCuREpa/Mhqdx6zanTTg9lTlt558kKGxyR4Dw445sUTwdfFuTU
Y7dGyQKBgAG0vyOdfku9TlPX2a3LasM5jkbxljeTlCJUlahW7LSoQEmLoEhOM4Ja
6CA5PADhA16pOUweKjOtSkNEcVEorFNjlH34PpnsysF+NsDBP5HEy0eYyHSYwg1Y
7BGwQxUOoBaUKMu7jVQcffrKiWOGEXzBDSEZ3A30t7+JIS7qy1d1
-----END RSA PRIVATE KEY-----
)";
            }
        };
    }
}

#endif
