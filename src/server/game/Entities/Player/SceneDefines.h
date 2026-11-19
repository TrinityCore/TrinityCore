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

#ifndef SceneDefines_h__
#define SceneDefines_h__

#include "Define.h"
#include "EnumFlag.h"

enum class SceneFlag : uint32
{
    None                        = 0x00,
    PlayerNonInteractablePhased = 0x01, // Sets UNIT_FLAG_IMMUNE_TO_PC + UNIT_FLAG_IMMUNE_TO_NPC + UNIT_FLAG_PACIFIED
    FadeToBlackscreenOnComplete = 0x02,
    NotCancelable               = 0x04,
    FadeToBlackscreenOnCancel   = 0x08,

    IgnoreTransport             = 0x20
};

DEFINE_ENUM_FLAG(SceneFlag);

#endif // SceneDefines_h__
