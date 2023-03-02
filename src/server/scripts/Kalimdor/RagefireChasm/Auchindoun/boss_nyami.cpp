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
#include "GameObject.h"
#include "AreaTrigger.h"
#include "auchindoun.h"


enum eNyamiSpells
{
    SpellShadowWordPain = 154477,
    SpellSoulVesselDummy = 155327,
    SpellSoulBubbleVisual = 177549,
    SpellSoulBubbleBuff = 177550,
    SpellSoulVesselDmg = 154187,
    SpellSoulVesselAreatrigger = 153888,
    SpellTornSpritsDummy = 153994,
    SpellTornSpritsDummyTwo = 153991,
    SpellTournSpiritsJump = 153992,
    SpellArbitrerHammer = 154218,
    SpellRadiantFuryVisualStar = 157787,
    SpellRadiantFuryDummy = 154261,
    SpellRadiantFullyVisual = 154264,
    SpellRadiantDamage = 154301,
    SpellRadiantFuryJump = 154262,
    SpellCrusaderStrike = 176931,
    SpellArcaneBolt = 154235,
    SpellVoidChanneling = 160677,
    SpellStrangulateState = 78037,
    SpellSpiritVisual = 145945,
};

enum eNyamiEvents
{
    EventShadowWordPain = 1,
    EventMindSpikeNyami,
    EventSoulVessel,
    EventTornSpirit,
    EventTornSpiritNyamiEffect,
    EventTornSpiritsDummy,
    EventArbitrerHammer,
    EventRadiantFury,
    EventRadiantFurySummonTrigger,
    EventRadiantFuryStop,
    EventArcaneBolt,
    EventCrusaderStrike,
    EventArcaneBombNyami,
    EventOnDeath1,
    EventOnDeath2,
    EventOnDeath3,
};

enum eNyamiTalks
{
    NyamiSpell1 = 1,   ///< Your Oath Is Unfinished! (43647)
    NyamiSpell3 = 2,   ///< The Spirits Are Mine To Command! (43649)
    NyamiSpell2 = 3,   ///< Return To This World! (43648)
    NyamiSpell4 = 4,   ///< I Will Drown This World In Shadows!(43650)
    NyamiAggro = 5,   ///< I Will Coil Your Souls Into Darkness!(43636)
    NyamiSlay = 6,   ///< Shadows Envelop You! (43646)
    NyamiDeath = 7,   ///< Too Late...My Master...Comes...(43637) 
    Auchenaiwarden1 = 32,  ///< Champions! Nyami'S Agents - They Went This Way.
    Auchenaiwarden2 = 33,  ///< No...Oh...No...
    Auchenaiwarden3 = 34,  ///< The Barrier Protecting Auchindoun Is Asunder.
    Auchenaiwarden4 = 35,  ///< A Foul Force Has Penetrated These Sacerd Chambers.
    Auchenaiwarden5 = 36   ///< Scount Ahead While We Establish A Foothold.
};

enum eNyamiActions
{
    ActionSummonSpirits = 1,
    ActionBreakLoose,
    ActionReleaseAnimationPreSoulVessel
};

enum eNyamiCreatures
{
    CreatureSpitefulArbitrer = 76284,
    CreatureTwistedMagus = 76296,
    CreatureMaleficDefender = 76283,
    CreatureRadiantFury = 432626,
    CreatureSoulVesselHackBubbleEffect = 342652
};

enum eNyamiMovementInformed
{
    MovementInformedRadiantFury = 1,
    MovementWardenMoveOuttaGate
};

void AddSC_boss_nyami()
{
    
}
