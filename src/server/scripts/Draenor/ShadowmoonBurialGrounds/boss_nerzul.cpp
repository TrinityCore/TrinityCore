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

#include "GameObject.h"
#include "shadowmoon_burial_grounds.h"
#include "SpellMgr.h"
#include "SpellAuras.h"

enum eNerzulSpells
{
    // Ritual of Bones: 76518   
    SpellMalevolance                    = 154442,
    SpellOmenOfDeathPeriodicSpell       = 175988,
    SpellOmenOfDeathSummon              = 154350,
    SpellOmenOfDeathVisualRune          = 154351,
    SpellOmenOfDeathLightningt          = 154352,
    SpellOmenOfDeathLightningDamageTick = 154353,
    SpellOmenOfDeathBreath              = 175988,
    SpellOmenOfDeathDummy               = 177691,
    SpellRitualOfBones                  = 154469,
    SpellRitualOfBonesDamage            = 154468,
    SpellRitualOfBonesDot               = 154469,
    SpellRitualOfBonesThirdVisual       = 154559,
    SpellRitualOfBonesPeriodic          = 156312,
    SpellRitualOfBonesWeirdVisualPoop   = 160445,
    SpellRitualOfBonesInvisibiltiy      = 160537,

    // RP
    SpellNerzulChannel                  = 160674,
};

enum eNerzulEvents
{
    // Ritual of Bones: 76518 
    EventMalevolance,
    EventRitualOfSouls,
    EventOmenOfDeath,
};

enum eNerzulTalks
{
    TalkAggro = 1, ///< The Shadowmoon cannot be defeated.. we walk in the realm of death itself!  [43682]
    TalkDeath,     ///< My power... will repel across eternity.. [43683]
    TalkIntro01,   ///< The darkness it flows within me.. it seeps from every vein. Come stranger gaze into the eye of the void! Tender your souls... to ME! *Nerz'ul laughs* [43684]
    TalkIntro02,   ///< Peer into the gateway.. I command! cross into the realm of the shadowland.. they should deliever you to your death! [43685]
    TalkKill01,    ///< You soul.. shall serve me... [43686]
    TalkKill02,    ///< You bend to my will...  [43687]
    TalkSpell01,   ///< I am the herald of the END! [43688]
    TalkSpell02,   ///< A kindeling of bones and shadows.. army of the dead.. ARISE! [43689]
    TalkSpell03,   ///< Into the ABYSS! [43690]
    TalkSpell04,   ///< Feel the void, cold embrace.. [43691]
}; 

enum eNerzulCreatures
{
    CreatureOmenOfDeath                  = 76462,
    CreatureRitualOfBones                = 76518,
    CreatureRitualOfBonesDarknessTrigger = 534556,
    CreatureVoidDoorSpawnCounter         = 645456,
};

enum eNerzulActions
{
    ActionNerzulPropIntroduction = 1,
};

Position l_NerzulTeleportPosition = {1723.754f, -799.859f, 73.735f, 4.222427f};

Position l_InitialPositionRight = { 1694.928f, -785.322f, 73.735f, 4.234663f };
Position l_InitialPositionLeft  = { 1677.648f, -825.009f, 73.306f, 0.882368f };

void AddSC_nerzul()
{
    
}
