/*
 * Copyright 2023 AzgathCore
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "Conversation.h"
#include "atal_dazar.h"

enum Spells {
    SPELL_TAIL                        = 255372, //Cast if player is behind
    SPELL_SERRATHED_TEETH             = 255434,
    SPELL_DEVOUR                      = 255421,
    SPELL_TERRIFYING_VISAGE           = 255371,
    SPELL_PURSUIT                     = 257407,
    SPELL_RIDE_VEHICLE                = 46598,
    SPELL_PILE_OF_BONES_AREATRIGGER   = 256608, //AT 11959
    SPELL_PILE_OF_BONES_SPAWN_NORMAL  = 256634,
    SPELL_PILE_OF_BONES_SPAWN_HEROIC  = 256720,
    SPELL_PILE_OF_BONES_SLOW          = 257483,
};

Position AreatriggerPositions[]{
    { -814.344f, 2241.63f, 641.538f },
    { -868.391f, 2245.54f, 642.03f  },
    { -887.726f, 2242.22f, 642.04f  },
    { -846.66f,  2247.46f, 641.774f },
    { -902.443f, 2238.86f, 642.331f },
    { -829.602f, 2247.23f, 641.842f },
    { -793.8f,   2239.09f, 641.832f },
    { -859.222f, 2256.25f, 643.136f },
    { -871.375f, 2258.77f, 643.438f },
    { -804.901f, 2254.52f, 641.964f },
    { -884.057f, 2257.15f, 642.643f },
    { -818.212f, 2259.57f, 642.465f },
    { -830.214f, 2265.17f, 642.486f },
    { -897.104f, 2259.22f, 641.901f },
    { -874.649f, 2273.9f,  642.642f },
    { -809.342f, 2272.22f, 641.905f },
    { -821.203f, 2279.28f, 642.488f },
    { -893.123f, 2276.57f, 642.583f },
    { -848.333f, 2288.46f, 642.486f },
    { -797.328f, 2282.58f, 641.182f },
    { -900.995f, 2285.5f,  641.773f },
    { -804.385f, 2293.2f,  641.488f },
    { -895.255f, 2298.0f,  642.486f },
    { -880.141f, 2301.81f, 642.501f },
    { -826.514f, 2306.46f, 642.699f },
    { -871.58f,  2311.03f, 642.487f },
    { -803.264f, 2310.29f, 641.707f },
    { -817.41f,  2313.88f, 641.638f },
    { -889.821f, 2315.4f,  642.486f },
    { -834.929f, 2321.18f, 643.028f },
    { -861.599f, 2322.33f, 642.5f   },
    { -872.771f, 2324.00f, 642.77f  },
    { -825.752f, 2329.17f, 642.247f },
    { -810.163f, 2327.19f, 641.401f },
    { -884.835f, 2331.72f, 642.487f },
    { -843.49f,  2335.39f, 642.765f },
    { -895.611f, 2334.97f, 642.425f },
    { -874.451f, 2340.77f, 643.405f },
    { -817.785f, 2342.43f, 641.914f },
    { -861.078f, 2344.69f, 642.685f },
    { -838.155f, 2345.16f, 642.733f },
    { -869.793f, 2352.61f,  642.515f},
};

enum Actions {
    ACTION_AREATRIGGER_ACTIVATED = 1,
};

enum Talks {
    TALK_BONE_PILE = 0,
    TALK_DEVOUR,
    TALK_PURSUIT,
};
enum Npcs {
    NPC_REANIMATED_RAPTOR = 129517,


};
enum Events {
    EVENT_TAIL = 1,
    EVENT_SERRATHED_TEETH,
    EVENT_DEVOUR,
    EVENT_TERRIFYING_VISAGE,
    EVENT_PURSUIT,
    EVENT_PURSUIT_TARGET,
    EVENT_PURSUIT_STOP,
    EVENT_DISMOUNT,
};

enum
{
  CONVERSATION_REZAN_DEATH = 6322,
};

void AddSC_boss_rezan()
{
    
}
