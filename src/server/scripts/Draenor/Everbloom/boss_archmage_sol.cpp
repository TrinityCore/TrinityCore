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
#include "the_everbloom.h"

enum eArchmageTalks
{
    KirinTorMageIntro     = 30,     ///< No...you Cant...its...i Cant Fight It!(45481)
    KirinTorMageAggro     = 31,     ///< Yes, Flee! Fire The Vines! They Control Us All!(45479)
    KirinTorMageSpell01   = 32,     ///< Yes, Fire! Fire Will Burn Away The Contagion.(45484)
    KirinTorMageSpell02   = 33,     ///< Surely The Cold Make Them Wither?(45485)
    KirinTorMageSpell03   = 34,     ///< Get Away..get Away!(45486)
    KirinTorMageKill01    = 35,     ///< No! They Will Take You Too!(45482)
    KirinTorMageKill02    = 36,     ///< You Musnt Give Them Anoter Host!(45483)
    KirinTorMageDeath     = 37,     ///< Burn My Body. Its  The Only Way To Stop Them.(45480)
};

enum ArchmageEnums
{
    SPELL_BARRIER               = 170150,
    SPELL_LIVING_ORGANISM       = 166719,
    SPELL_DESPAWN_AREA_TRIGGERS = 138175,
    SPELL_THOUGHT_CHRYSALIS     = 166474,
    SPELL_FIREBALL              = 166464,
    SPELL_FROSTBOLT             = 166465,
    SPELL_ARCANE_BURST          = 166466,
    SPELL_FIREBLOOM             = 166572,
    SPELL_FIREBLOOM_TARGET      = 166562,
    SPELL_FROZEN_RAIN           = 166913,
    SPELL_PARASITIC_GROWTH      = 168885,
    SPELL_PARASITIC_INJECTION   = 166891,
    SPELL_PRIMAL_FIRE           = 166475,
    SPELL_PRIMAL_FROST          = 166476,
    SPELL_PRIMAL_ARCANE         = 166477,
    SPELL_FIRE_SPORES           = 168905,
    SPELL_FROST_SPORES          = 168906,

    NPC_FROZEN_RAIN             = 82846,
    NPC_SPORE_FIRE              = 84386,
    NPC_SPORE_FROST             = 84387,
};

void AddSC_boss_sol()
{
    
}
