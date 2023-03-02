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
#include "shadowmoon_burial_grounds.h"
#include "GameObject.h"
#include "PhasingHandler.h"
#include "SpellAuras.h"
#include "SpellMgr.h"

enum eNhalishSpells
{
    SpellPlanarShift                         = 153623,
    SpellTeleportSelf                        = 153621,
    SpellVoidVortexDamage                    = 152800,
    SpellVoidVortexAreaTrigger               = 152801,
    SpellVoidBlastSpellAuraDummy             = 152792,
    SpellVoidBlastDot                        = 153501,
    SpellVoidDevastationPeriodicTriggerSpell = 153067,
    SpellVoidDevstationProjectile            = 153068,
    SpellVoidDevestationDebuff               = 153070l,
    SpellVoidDevstationAreaTrigger           = 153072,
    SpellSoulStealForceCast                  = 152962,
    SpellSoulStealPeriodicDummy              = 156755,
    SpellSoulless                            = 154947,
    SpellRegainYourSoul                      = 153007,
    SpellSoulShred                           = 152979,
    SpellShadowChannel                       = 46757,
    SpellLootSparkles                        = 92376,
    SpellCloneMe                             = 45204
};

enum eNhalishEvents
{
    EventPlanarShift = 1,
    EventVoidVortex,
    EventVoidBlast,
    EventVoidDevastation,
    EventSoulSteal,
    EventRandomMovement,
    EventExhumeCrypt
};

enum eNhalishCreatures
{
   CreatureDistrubedSouls     = 76400,
   CreatureSoul               = 75899,
   CreatureNhalishProp        = 432561,
   CreatureDevestationTrigger = 543531 /// Hardcoded
};

enum eNhalishGameObjects
{
    GameObjectNhalishDoor     = 227851
};

enum eNhallishTalks
{
    TalkAggro = 1, ///< Yes... come closer, your souls are strong and proud! I will feast on your terror.. [43197]
    TalkDeath,     ///< You are just maggots.. sworm into a corpse of a dying god! [43198]
    TalkIntro01,   ///< Cower before me! [43199]
    TalkIntro02,   ///< Your undying souls will fuel my ascention from the Darkness! [43200]
    TalkIntro03,   ///< Your blisper afterlife is over! [43201]
    TalkKill01,    ///< Your mortal body are so fragile! [43202]
    TalkKill02,    ///< Another soul to DEVOUR! [43203]
    TalkSpell01,   ///< None escape the void! [43204]
    TalkSpell02,   ///< You cannot flee! [43205]
    TalkSpell03,   ///< *Nhallish laughs* [43206]
    TalkSpell04,   ///< Flee... flee from your your formal masters! [43207]
};

enum eNhalishActions
{
    ActionActivateVortex = 1,
    ActionDeactivateVortex
};

void AddSC_nhalish()
{
    
}
