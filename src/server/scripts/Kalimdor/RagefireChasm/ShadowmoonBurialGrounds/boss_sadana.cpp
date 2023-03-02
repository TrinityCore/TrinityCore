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
#include "GameObject.h"
#include "GridNotifiers.h"
#include "shadowmoon_burial_grounds.h"

enum eSadanaSpells
{
    SpellDaggerFallDummy = 153240,
    SpellDaggerFallSummon = 153200,
    SpellDaggerAlttitudeVisual = 153225,
    SpellDaggerAura = 153236,
    SpellDaggerAuraFunctioning = 153216,
    SpellDaggerExplosion = 153373,
    SpellDaggerFallTriggerMissile = 153370,
    SpellDaggerFallGroundMarker = 173073,
    SpellDaggerFallDamage = 153224,

    SpellDarkCommunion = 153153,
    SpellDarkCommunionBuff = 153164,

    SpellDeathSpikeProcTriggerSpell = 153079,
    SpellDeathSpikeDamage = 153089,
    SpellDeathSpikeFull = 162696,

    SpellWhispersOfTheDarkStarDamage = 153093,
    SpellWhisperOfTheDarkStarTriggerSpell = 153094,

    SpellDarkEclipsePeriodicDummy = 164685,
    SpellDarkEclipseDamage = 164686,
    SpellDarkEclipseAreatrirger = 164704,
    SpellDarkEclipseDummy = 164705,
    SpellDarkEclipseDummy02 = 164706,
    SpellDarkEclipsePeriodicTrigger = 164710,
    SpellDarkElcipseUnknownPeriodicDummy = 164974,
    SpellLunaryPurtiyBuff = 162652,
    //SpellLunarPurityAreaTrigger           = 162620,

    SpellLunarPurityAreaTrigger = 164974,
    SpellLunarPurityDamageModification = 162652,

    SpellShadowRitual = 152158,
    SpellLunarRitual = 164693,
    SpellShadowRuneVisual = 152684,
    SpellShadowRuneVisual01 = 152691,
    SpellShadowRuneVisual02 = 152695,

    SpellLunarRuneVisual = 164693,
    SpellLunarRuneVisual01 = 164695,
    SpellLunarRuneVisual02 = 164696,

    SpellTenebreuxViolet = 152311,

    SpellCosmeticStrangulateState = 78037
};

enum eSadanaEvents
{
    EventDaggerFall = 1,
    EventDaggerFallMovement,
    EventDaggerFallActivation,
    EventDarkCommunion,
    EventDeathSpike,
    EventWhisperOfTheDarkStar,
    EventDarkEclipse,
    EventDarkEclipseFinish,
    EventLunarPurity,
    EventDefiledSpirtMovement
};

enum eSadanaTalks
{
    TalkAggro = 1, ///< Anscestors of the Shadowmoon.. shine in the darkness! Lend me your strength! [43539]
    TalkDeath,     ///< The dead shall rise again.. [43540]
    TalkIntro,     ///< Rivers of the damned.. rise! RISE in the name of Darkness... RISE in the name of NERZ'UL!.. the Shadowmoon beckons [43541]
    TalkKill01,    ///< Another spirit for the army! [43542]
    TalkKill02,    ///< Embrace the eternal darkness! [43543]
    TalkSpell01,   ///< For Nerz'ul! [43544]
    TalkSpell02,   ///< Mmm.. mmm.. YES! the perfect Sacrifice! [43545]
    TalkSpell03,   ///< Your souls will belong to me! [43546]
    TalkSpell04,   ///< Restless spirits.. heed my command! [43547]
};

enum eSadanaActions
{
    ActionActivateDefiledSpirit = 1,
    ActionMoveDefiledSpirits,
    ActionActivateLunarTriggersActivate,
    ActionActivateLunarTriggersDeactivate
};

enum eSadanaCreatures
{
    CreatureDaggerFall = 75981,
    CreatureEclipseTrigger = 76052,
    CreatureDefiledSpiritSadanaEncounter = 75966,
    CreatureShadowRune = 75778
};

enum eSadanaMovements
{
    MovementDaggerFallReachedAlttitude = 1
};

#define DaggerFallAltitude 268.028f
#define DaggerGroundAltitude 261.308f
#define HostileFaction 16
#define FriendlyFaction 35

Position const g_PositionCircles[8] =
{
    {1805.502f, -16.298f, 261.308f, 4.011894f},
    {1809.695f, -26.531f, 261.308f, 3.086692f},
    {1805.346f, -37.156f, 261.308f, 2.155996f},
    {1795.560f, -40.853f, 261.308f, 1.508042f},
    {1785.818f, -37.061f, 261.308f, 0.640176f},
    {1781.712f, -26.524f, 261.308f, 6.263623f},
    {1786.218f, -16.460f, 261.308f, 5.482167f},
    {1795.574f, -12.252f, 261.308f, 4.767466f}
};

Position const g_PositionDefiledSpiritsMovement[8] =
{
    {1817.100f, -26.563f, 276.406f, 4.329479f},
    {1817.556f, -49.306f, 300.783f, 2.829369f},
    {1794.627f, -57.390f, 289.405f, 2.762329f},
    {1773.798f, -52.632f, 278.439f, 1.855194f},
    {1787.415f, -34.515f, 289.940f, 0.099829f},
    {1819.107f, -6.276f, 273.476f,  4.141892f},
    {1789.199f, -9.896f, 270.591f,  3.336035f},
    {1797.886f, -20.040f, 281.501f, 5.166008f}
};

void AddSC_sadana()
{
    
}
