/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef _UPDATEFIELDFLAGS_H
#define _UPDATEFIELDFLAGS_H

#include "UpdateFields.h"
#include "Define.h"

enum UpdatefieldFlags
{
    UF_FLAG_NONE                = 0x000,
    UF_FLAG_PUBLIC              = 0x001,
    UF_FLAG_PRIVATE             = 0x002,
    UF_FLAG_OWNER               = 0x004,
    UF_FLAG_ITEM_OWNER          = 0x008,
    UF_FLAG_SPECIAL_INFO        = 0x010,
    UF_FLAG_PARTY_MEMBER        = 0x020,
    UF_FLAG_UNIT_ALL            = 0x040,
    UF_FLAG_DYNAMIC             = 0x080,
    UF_FLAG_0x100               = 0x100,
    UF_FLAG_URGENT              = 0x200,
    UF_FLAG_URGENT_SELF_ONLY    = 0x400
};

TC_GAME_API extern uint32 ContainerUpdateFieldFlags[CONTAINER_END];
TC_GAME_API extern uint32 AzeriteEmpoweredItemUpdateFieldFlags[AZERITE_EMPOWERED_ITEM_END];
TC_GAME_API extern uint32 AzeriteItemUpdateFieldFlags[AZERITE_ITEM_END];
TC_GAME_API extern uint32 ItemDynamicUpdateFieldFlags[CONTAINER_DYNAMIC_END];
TC_GAME_API extern uint32 UnitUpdateFieldFlags[ACTIVE_PLAYER_END];
TC_GAME_API extern uint32 UnitDynamicUpdateFieldFlags[ACTIVE_PLAYER_DYNAMIC_END];
TC_GAME_API extern uint32 GameObjectUpdateFieldFlags[GAMEOBJECT_END];
TC_GAME_API extern uint32 GameObjectDynamicUpdateFieldFlags[GAMEOBJECT_DYNAMIC_END];
TC_GAME_API extern uint32 DynamicObjectUpdateFieldFlags[DYNAMICOBJECT_END];
TC_GAME_API extern uint32 CorpseUpdateFieldFlags[CORPSE_END];
TC_GAME_API extern uint32 AreaTriggerUpdateFieldFlags[AREATRIGGER_END];
TC_GAME_API extern uint32 SceneObjectUpdateFieldFlags[SCENEOBJECT_END];
TC_GAME_API extern uint32 ConversationUpdateFieldFlags[CONVERSATION_END];
TC_GAME_API extern uint32 ConversationDynamicUpdateFieldFlags[CONVERSATION_DYNAMIC_END];

#endif // _UPDATEFIELDFLAGS_H
