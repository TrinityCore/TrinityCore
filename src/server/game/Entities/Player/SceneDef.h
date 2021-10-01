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

#ifndef SceneDef_h__
#define SceneDef_h__

#include "Common.h"

enum class SceneFlag : uint32
{
    None                        = 0x00,
    PlayerNonInteractablePhased = 0x01, // Player Is Non-Interactable and Phased
    FadeToBlackscreenOnComplete = 0x02,
    NotCancelable               = 0x04,
    GiganticAOI                 = 0x08,
    InfiniteAOI                 = 0x10, // 16, most common value
    FadeToBlackscreenOnCancel   = 0x20,
    IgnoreTransport             = 0x40,
    PlayAsLoginCinematic        = 0x80,
};

DEFINE_ENUM_FLAG(SceneFlag);

struct SceneTemplate
{
    uint32 SceneId = 0;
    uint32 PlaybackFlags = 0;
    uint32 ScenePackageId = 0;
    bool Encrypted = false;
    uint32 ScriptId = 0;

    EnumFlag<SceneFlag> GetFlags() const { return static_cast<SceneFlag>(PlaybackFlags); }
};

#endif
