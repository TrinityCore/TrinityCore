/**
 @file RegistryUtil.h

 @created 2006-04-06
 @edited  2006-04-06

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
*/

#ifndef G3D_REGISTRYUTIL_H
#define G3D_REGISTRYUTIL_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"

// This file is only used on Windows
#ifdef G3D_WINDOWS

#include <string>

namespace G3D {

/** 
    Provides generalized Windows registry querying.

    All key names are one string in the format:
        "[base key]\[sub-keys]"

    A value must now be provided for every query.
    An empty value string will use the (Default) value.

    [base key] can be any of the following:
        HKEY_CLASSES_ROOT
        HKEY_CURRENT_CONFIG
        HKEY_CURRENT_USER
        HKEY_LOCAL_MACHINE
        HKEY_PERFORMANCE_DATA
        HKEY_PERFORMANCE_NLSTEXT
        HKEY_PERFORMANCE_TEXT
        HKEY_USERS

    valueExists() should be used to validate a key+value before reading or writing
    to ensure that a debug assert or false return is for a different error during 
    reads and writes.

    All read and write calls will assert when a key will not open for reasons other
    that it does not exist. All read and write calls will assert when the value cannot
    be read or written for any reason.
*/
class RegistryUtil {

public:
    /** returns true if the key exists and the current user has permission to read */
    static bool keyExists(const std::string& key);

    /** returns true if the key exists and the current user has permission to read */
    static bool valueExists(const std::string& key, const std::string& value);

    /** returns false if the key could not be read for any reason. */
    static bool readInt32(const std::string& key, const std::string& value, int32& data);

    /** 
      Reads an arbitrary amount of data from a binary registry key.
      returns false if the key could not be read for any reason.
    
      @beta
      @param data pointer to the output buffer of sufficient size. Pass NULL as data in order to have available data size returned in dataSize.
      @param dataSize size of the output buffer.  When NULL is passed for data, contains the size of available data on successful return.
    */
    static bool readBytes(const std::string& key, const std::string& value, uint8* data, uint32& dataSize);

    /** returns false if the key could not be read for any reason. */
    static bool readString(const std::string& key, const std::string& value, std::string& data);

    /** returns false if the key could not be written for any reason. */
    static bool writeInt32(const std::string& key, const std::string& value, int32 data);

    /** 
      Writes an arbitrary amount of data to a binary registry key.
      returns false if the key could not be written for any reason.
    
      @param data pointer to the input buffer
      @param dataSize size of the input buffer that should be written
    */
    static bool writeBytes(const std::string& key, const std::string& value, const uint8* data, uint32 dataSize);

    /** returns false if the key could not be written for any reason. */
    static bool writeString(const std::string& key, const std::string& value, const std::string& data);

};

} // namespace G3D

#endif // G3D_WINDOWS

#endif // G3D_REGISTRYTUIL_H
