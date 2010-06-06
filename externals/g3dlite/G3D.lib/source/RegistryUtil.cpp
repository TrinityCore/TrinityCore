/**
 @file RegistryUtil.cpp

 @created 2006-04-06
 @edited  2006-04-24

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
*/

#include "G3D/platform.h"

// This file is only used on Windows
#ifdef G3D_WIN32

#include "G3D/RegistryUtil.h"
#include "G3D/System.h"

namespace G3D {

// static helpers
static HKEY getRootKeyFromString(const char* str, size_t length);


bool RegistryUtil::keyExists(const std::string& key) {
    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if (hkey == NULL) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_READ, &openKey);

    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        RegCloseKey(openKey);
        return true;
    } else {
        return false;
    }
}

bool RegistryUtil::valueExists(const std::string& key, const std::string& value) {
    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if ( hkey == NULL ) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_READ, &openKey);
    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        uint32 dataSize = 0;
        result = RegQueryValueExA(openKey, value.c_str(), NULL, NULL, NULL, reinterpret_cast<LPDWORD>(&dataSize));

        debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);
        RegCloseKey(openKey);
    }
    return (result == ERROR_SUCCESS);
}


bool RegistryUtil::readInt32(const std::string& key, const std::string& value, int32& data) {
    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if ( hkey == NULL ) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_READ, &openKey);
    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        uint32 dataSize = sizeof(int32);
        result = RegQueryValueExA(openKey, value.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(&data), reinterpret_cast<LPDWORD>(&dataSize));

        debugAssertM(result == ERROR_SUCCESS, "Could not read registry key value.");

        RegCloseKey(openKey);
    }
    return (result == ERROR_SUCCESS);
}

bool RegistryUtil::readBytes(const std::string& key, const std::string& value, uint8* data, uint32& dataSize) {
    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if (hkey == NULL) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_READ, &openKey);
    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        if (data == NULL) {
            result = RegQueryValueExA(openKey, value.c_str(), NULL, NULL, NULL, reinterpret_cast<LPDWORD>(&dataSize));
        } else {
            result = RegQueryValueExA(openKey, value.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(&data), reinterpret_cast<LPDWORD>(&dataSize));
        }

        debugAssertM(result == ERROR_SUCCESS, "Could not read registry key value.");

        RegCloseKey(openKey);
    }
    return (result == ERROR_SUCCESS);
}

bool RegistryUtil::readString(const std::string& key, const std::string& value, std::string& data) {
    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if (hkey == NULL) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_READ, &openKey);
    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        uint32 dataSize = 0;

        result = RegQueryValueExA(openKey, value.c_str(), NULL, NULL, NULL, reinterpret_cast<LPDWORD>(&dataSize));
        debugAssertM(result == ERROR_SUCCESS, "Could not read registry key value.");

        // increment datasize to allow for non null-terminated strings in registry
        dataSize += 1;

        if (result == ERROR_SUCCESS) {
            char* tmpStr = static_cast<char*>(System::malloc(dataSize));
            System::memset(tmpStr, 0, dataSize);

            result = RegQueryValueExA(openKey, value.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(tmpStr), reinterpret_cast<LPDWORD>(&dataSize));
            debugAssertM(result == ERROR_SUCCESS, "Could not read registry key value.");
                
            if (result == ERROR_SUCCESS) {
                data = tmpStr;
            }

            RegCloseKey(openKey);
            System::free(tmpStr);
        }
    }
    return (result == ERROR_SUCCESS);
}

bool RegistryUtil::writeInt32(const std::string& key, const std::string& value, int32 data) {
    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if (hkey == NULL) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_WRITE, &openKey);
    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        result = RegSetValueExA(openKey, value.c_str(), 0, REG_DWORD, reinterpret_cast<const BYTE*>(&data), sizeof(int32));

        debugAssertM(result == ERROR_SUCCESS, "Could not write registry key value.");

        RegCloseKey(openKey);
    }
    return (result == ERROR_SUCCESS);
}

bool RegistryUtil::writeBytes(const std::string& key, const std::string& value, const uint8* data, uint32 dataSize) {
    debugAssert(data);

    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if (hkey == NULL) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_WRITE, &openKey);
    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        if (data) {
            result = RegSetValueExA(openKey, value.c_str(), 0, REG_BINARY, reinterpret_cast<const BYTE*>(data), dataSize);
        }

        debugAssertM(result == ERROR_SUCCESS, "Could not write registry key value.");

        RegCloseKey(openKey);
    }
    return (result == ERROR_SUCCESS);
}

bool RegistryUtil::writeString(const std::string& key, const std::string& value, const std::string& data) {
    size_t pos = key.find('\\', 0);
    if (pos == std::string::npos) {
        return false;
    }

    HKEY hkey = getRootKeyFromString(key.c_str(), pos);

    if (hkey == NULL) {
        return false;
    }

    HKEY openKey;
    int32 result = RegOpenKeyExA(hkey, (key.c_str() + pos + 1), 0, KEY_WRITE, &openKey);
    debugAssert(result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);

    if (result == ERROR_SUCCESS) {
        result = RegSetValueExA(openKey, value.c_str(), 0, REG_SZ, reinterpret_cast<const BYTE*>(data.c_str()), (data.size() + 1));                
        debugAssertM(result == ERROR_SUCCESS, "Could not write registry key value.");

        RegCloseKey(openKey);
    }
    return (result == ERROR_SUCCESS);
}


// static helpers
static HKEY getRootKeyFromString(const char* str, uint32 length) {
    debugAssert(str);

    if (str) {
        if ( strncmp(str, "HKEY_CLASSES_ROOT", length) == 0 ) {
            return HKEY_CLASSES_ROOT;
        } else if  ( strncmp(str, "HKEY_CURRENT_CONFIG", length) == 0 ) {
            return HKEY_CURRENT_CONFIG;
        } else if  ( strncmp(str, "HKEY_CURRENT_USER", length) == 0 ) {
            return HKEY_CURRENT_USER;
        } else if  ( strncmp(str, "HKEY_LOCAL_MACHINE", length) == 0 ) {
            return HKEY_LOCAL_MACHINE;
        } else if  ( strncmp(str, "HKEY_PERFORMANCE_DATA", length) == 0 ) {
            return HKEY_PERFORMANCE_DATA;
        } else if  ( strncmp(str, "HKEY_PERFORMANCE_NLSTEXT", length) == 0 ) {
            return HKEY_PERFORMANCE_NLSTEXT;
        } else if  ( strncmp(str, "HKEY_PERFORMANCE_TEXT", length) == 0 ) {
            return HKEY_PERFORMANCE_TEXT;
        } else if  ( strncmp(str, "HKEY_CLASSES_ROOT", length) == 0 ) {
            return HKEY_CLASSES_ROOT;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

} // namespace G3D

#endif // G3D_WIN32
