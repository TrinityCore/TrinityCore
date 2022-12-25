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

#include "shadowmoon_burial_grounds.h"
#include "GameObject.h"

enum eBoneMawSpells
{
    // Carrion Worm: 88769
    SpellNecroticPitchTriggerMissile    = 153689,
    SpellNecroticPitchAreatrigger       = 153690,
    SpellNecroticPitchDummy             = 153691,
    SpellNecroticPitchDebuff            = 153692,
    SpellCorpseBreathPeriodic           = 165578,
    SpellCorpseBreathDamage             = 165579,
    SpellFetidSpitDamage                = 153681,

    SpellBodySlam                       = 154175,
    SpellInhaleVisual                   = 153721,
    SpellInhalePeriodicChannel          = 153804,
    SpellInhaleDamage                   = 153908,
    SpellInhaleAreaTrigger              = 153961,
    SpellInhaleSleep                    = 154010,
    SpellnhaleScreenEffect              = 154008,

    SpellVisualSubmerge                 = 177694
};

enum eBoneMawEvents
{
    // Carrion Worm: 88769
    EventNecroticPitch = 1,
    EventCorpseBreath,
    EventFetidSpit,
    EventBodySlam,
    EventInhale,
    EventCarrionWorm,
    EventCancelBodySlamFlags,
    EventCancelSubmerge,

    // Cosmetic - Submerge for Bonemaw
    EventSubmerge,
};

enum eBoneMawCreatures
{
    CreatureCarrionWorm             = 88769,
    CreatureInhaleTrigger           = 76250,
    CreatureNecroticPitchTrigger    = 76191,
};

enum eBoneMawGameObjects
{
    GameObjectBonemawDoors      = 233988,
    GameObjectBonemawDoors01    = 233989
};

enum eBoneMawActions
{
    ActionInhaleDeactivate = 1,
};

Position const positionBoneMaw = { 1851.256f, -558.721f, 199.027f, 1.991077f };
Position const positionAdds[2] =
{
    { 1801.369f, -521.248f, 196.795f, 0.030723f },
    { 1860.075f, -497.532f, 196.796f, 4.054334f },
};

#define FriendlyFaction 35
#define HostileFaction 16
#define InvisibleDisplay 11686

void AddSC_bonemaw()
{
    
}
