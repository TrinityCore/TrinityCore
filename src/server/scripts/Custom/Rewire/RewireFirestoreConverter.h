/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#ifndef TRINITYCORE_REWIRE_FIRESTORE_CONVERTER_H
#define TRINITYCORE_REWIRE_FIRESTORE_CONVERTER_H

#include "RewireConfig.h"

#include <string>
#include <string_view>

namespace Trinity::Rewire
{
class FirestoreConverter final
{
public:
    static bool Convert(std::string_view sourceEvent, RewireConfig const& config, std::string& output, std::string& error);
};
}

#endif // TRINITYCORE_REWIRE_FIRESTORE_CONVERTER_H
