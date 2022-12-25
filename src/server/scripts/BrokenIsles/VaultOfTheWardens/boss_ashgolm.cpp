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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "vault_of_the_wardens.h"
#include "GameObject.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_LAVA_WREATH = 1,
    SAY_FREEZE = 2,
    SAY_FREEZE_EMOTE = 3,
    SAY_BRITTLE = 4,
    // SAY_AGGRO        = 5   I don`t know where "Fire has a life of its own."
    SAY_DEATH = 6,
    SAY_SYSTEM = 7,
};

enum Spells
{
    SPELL_FROZEN = 200354,
    SPELL_HEAT_UP = 200981,
    SPELL_SMOLDERING = 193209,
    SPELL_VOLCANO = 192622,
    SPELL_LAVA_WREATH = 192631,
    SPELL_LAVA_WREATH_VIS = 193354,
    SPELL_LAVA_WREATH_TRIG = 193353,
    SPELL_LAVA_WREATH_AT = 192571,
    SPELL_FISSURE = 192522,
    SPELL_FISSURE_TRIG = 193355,
    SPELL_SUM_EMBER = 195170,

    //Ember
    SPELL_EMBER_SMOLDERING = 195188,
    SPELL_SEAR = 195332,
    SPELL_FIRED_UP = 202169,
    SPELL_DETONATE = 195187,

    //System security
    SPELL_ACTIVATE_SYSTEM_VIS = 195189,
    SPELL_ACTIVATE_SYSTEM = 195213,
    SPELL_FREEZE_ROOM = 195227,

    SPELL_ACHIEVE = 215478,
};

enum eEvents
{
    EVENT_VOLCANO = 1,
    EVENT_LAVA_WREATH = 2,
    EVENT_FISSURE = 3,
    EVENT_SUM_EMBER = 4,
    EVENT_SYSTEM_SECURITY = 5,

    EVENT_1,
    EVENT_2,
};

Position const centrPos = { 4239.14f, -451.332f, 105.947f };

void AddSC_boss_ashgolm()
{
   
}
