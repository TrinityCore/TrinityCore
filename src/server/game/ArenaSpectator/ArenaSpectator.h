/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef AZEROTHCORE_ARENASPECTATOR_H
#define AZEROTHCORE_ARENASPECTATOR_H

#include "Chat.h"
#include "Common.h"
#include "ObjectDefines.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "StringFormat.h"

class Aura;
class Player;
class Map;
class WorldPacket;

#define SPECTATOR_ADDON_VERSION 27
#define SPECTATOR_BUFFER_LEN 150
#define SPECTATOR_ADDON_PREFIX "ASSUN\x09"
#define SPECTATOR_COOLDOWN_MIN 20
#define SPECTATOR_COOLDOWN_MAX 900
#define SPECTATOR_SPELL_BINDSIGHT 6277
#define SPECTATOR_SPELL_SPEED 1557

namespace ArenaSpectator
{
    template<class T>
    TC_GAME_API void SendPacketTo(const T* object, std::string&& message);

    template<class T, typename Format, typename... Args>
    inline void SendCommand(T* o, Format&& fmt, Args&& ... args)
    {
        SendPacketTo(o, Trinity::StringFormatAC(std::forward<Format>(fmt), std::forward<Args>(args)...));
    }

    template<class T>
    inline void SendCommand_String(T* o, ObjectGuid targetGUID, const char* prefix, const char* c)
    {
        if (!targetGUID.IsPlayer())
            return;

        SendCommand(o, "%s0x%016llX;%s=%s;", SPECTATOR_ADDON_PREFIX, targetGUID.GetRawValue(), prefix, c);
    }

    template<class T>
    inline void SendCommand_UInt32Value(T* o, ObjectGuid targetGUID, const char* prefix, uint32 t)
    {
        if (!targetGUID.IsPlayer())
            return;

        SendCommand(o, "%s0x%016llX;%s=%u;", SPECTATOR_ADDON_PREFIX, targetGUID.GetRawValue(), prefix, t);
    }

    template<class T>
    inline void SendCommand_GUID(T* o, ObjectGuid targetGUID, const char* prefix, ObjectGuid t)
    {
        if (!targetGUID.IsPlayer())
            return;

        SendCommand(o, "%s0x%016llX;%s=0x%016llX;", SPECTATOR_ADDON_PREFIX, targetGUID.GetRawValue(), prefix, t.GetRawValue());
    }

    template<class T>
    inline void SendCommand_Spell(T* o, ObjectGuid targetGUID, const char* prefix, uint32 id, int32 casttime)
    {
        if (!targetGUID.IsPlayer())
            return;

        SendCommand(o, "%s0x%016llX;%s=%u,%i;", SPECTATOR_ADDON_PREFIX, targetGUID.GetRawValue(), prefix, id, casttime);
    }

    template<class T>
    inline void SendCommand_Cooldown(T* o, ObjectGuid targetGUID, const char* prefix, uint32 id, uint32 dur, uint32 maxdur)
    {
        if (!targetGUID.IsPlayer())
            return;

        if (SpellInfo const* si = sSpellMgr->GetSpellInfo(id))
            if (si->SpellIconID == 1)
                return;

        SendCommand(o, "%s0x%016llX;%s=%u,%u,%u;", SPECTATOR_ADDON_PREFIX, targetGUID.GetRawValue(), prefix, id, dur, maxdur);
    }

    template<class T>
    inline void SendCommand_Aura(T* o, ObjectGuid targetGUID, const char* prefix, ObjectGuid caster, uint32 id, bool isDebuff, uint32 dispel, int32 dur, int32 maxdur, uint32 stack, bool remove)
    {
        if (!targetGUID.IsPlayer())
            return;

        SendCommand(o, "%s0x%016llX;%s=%u,%u,%i,%i,%u,%u,%u,0x%016llX;", SPECTATOR_ADDON_PREFIX, targetGUID.GetRawValue(), prefix, remove ? 1 : 0, stack, dur, maxdur, id, dispel, isDebuff ? 1 : 0, caster.GetRawValue());
    }

    TC_GAME_API bool HandleSpectatorSpectateCommand(ChatHandler* handler, std::string const& name);
    TC_GAME_API bool HandleSpectatorWatchCommand(ChatHandler* handler, std::string const& name);
    TC_GAME_API void CreatePacket(WorldPacket& data, std::string const& message);
    TC_GAME_API void HandleResetCommand(Player* player);
    TC_GAME_API bool ShouldSendAura(Aura* aura, uint8 effMask, ObjectGuid targetGUID, bool remove);
}

#endif
