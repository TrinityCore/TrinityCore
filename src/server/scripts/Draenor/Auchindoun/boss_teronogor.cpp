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


enum eTerongorSpells
{
    SpellAgony = 156925,
    SpellChaosBolt = 156975,
    SpellChaosWaveDummy = 157001,
    SpellChaosWaveDmg = 157002,
    SpellConflagrate = 154083,
    SpellCorruptionDmg = 156842,
    SpellCurseOfExhaustionDebuff = 164841,
    SpellDemonicLeapDummy = 157039,
    SpellDemonicLeapAreatriger = 157040,
    SpellDoomBuff = 156965,
    SpellDrainLife = 156854,
    SpellImmolate = 156964,
    SpellIncinrate = 156963,
    SpellRainOfFire = 156974,
    SpellSeedOfMalevolenceApplyAura = 156921,
    SpellSeedOfMalevolenceBuff = 166451,
    SpellSeedOfMalevolenceDmg = 156924,
    SpellSeedOfMalevolenceVisualTriger = 166462,
    SpellShadowBolt = 156829,
    SpellTouchOfChaosDummy = 169028,
    SpellTouchOfChaosDmg = 156968,
    SpellUnstableAffliction = 156954,
    SpellWrathCleave = 159035,
    SpellWrathStorm = 159033,
    SpellTranscend = 164009,
    SpellAfflictionTransform = 156863,
    SpellDestructionTransform = 156866,
    SpellDemonologyTransform = 156919,
    SpellSummonAbyssalMeteor = 164508,
    SpellSummonAbyssalGroundEffect = 159681,
    SpellSummonAbyssalDummy = 157214,
    SpellSummonAbyssalSummonSpell = 157216,
    SpellDemonicCircleVisual = 149133,
    SpellTeronogorShield = 157017,
    SpellBrokenSouls = 72398,
    SpellSoulBarrage = 72305,
    SpellGuldenSoulVisual = 166453
};

enum eTerongorEvents
{
    EventAgony = 1,
    EventChaosBolt,
    EventChaosWave,
    EventConflagrate,
    EventCorruption,
    EventCurseOfExhaustion,
    EventDemonicLeap,
    EventDoom,
    EventDrainLife,
    EventImmolate,
    EventIncinrate,
    EventRainOfFire,
    EventSeedOfMalevolence,
    EventTouchOfChaos,
    EventUnstableAffliction,
    EventShadowBolt,
    EventWrathcleave,
    EventWrathstorm,
    EventBloomOfMalevolence,
    EventDepassive,
    EventTransform,
    EventTransformRemovePassive,
    TransformationPreChannel1,
    TransformationPreChannel2,
    TransformationPreChannel3,
    TransformationPreChannel4,
    TransformationPreChannel5,
    TransformationPreChannel6,
};

enum eTerongorTalks
{
    TERONGOR_INTRO_01 = 83255, ///< p_Who know the draenei held such...delicious treasure in their temple?  (44423)
    TERONGOR_INTRO_02 = 43, ///< Do you dare challenge me,defenders of Auchindoun?!(44424)
    TERONGOR_INTRO_03 = 44, ///< Such decadence...it will all burn. (44425)
    TERONGOR_INTRO_05 = 45, ///< Gul'dan, such foolshness. This gift...so much more you could ever know...(44427)
    TERONGOR_INTRO_06 = 46, ///< Long have i waited...(44428)
    TERONGOR_INTRO_07 = 47, ///< ...hungered... to be more... (44429)
    TERONGOR_INTRO_08 = 48, ///<  And now, all shall bow before me!(44430)
    TERONGOR_KILL_01 = 49, ///< All will fall before me!(44431)
    TERONGOR_AGGRO_01 = 0, ///< This power. you will be the first to know it.(44418)
    TERONGOR_SPELL_01 = 52, ///< Destruction!(44433)
    TERONGOR_SPELL_02 = 2, ///< Wither.. away! (44434)
    TERONGOR_SPELL_03 = 53, ///< I become something greater!(44435)
    TERONGOR_SPELL_04 = 54, ///< Die! (44436)
    TERONGOR_SPELL_05 = 55, ///< Your demise awaits! (44437)
    TERONGOR_SPELL_06 = 3, ///< Quickly now. (44438)
    TERONGOR_SPELL_07 = 57, ///< More! I...need...more!(44439)
    TERONGOR_EVENT_01 = 60, ///< Jorrun.. p_Who battle demons in life, in death.. your power will feed them! (44420)
    TERONGOR_EVENT_02 = 61, ///< Joraa, paragon of order - i shall twist your soul to power Destruction!(44421)
    TERONGOR_EVENT_03 = 1, ///< Elum, life time of healing... now, you shall fuel Deziz and Decay!(44422)
    TERONGOR_DEATH = 4 ///< (44419)
};

enum eTeronogorActions
{
    ActionTransport = 1,
    ActionChoosePower
};

enum eTeronogorCreatures
{
    TriggerSummonAbyssal = 213593
};

enum eTeronogorTransformations
{
    TransformationAffliction = 0,
    TransformationDestruction = 1,
    TransformationDemonology = 2,
    TransformationPreChannel = 3,
    TransformationOccur = 4,
    TransformationOccured = 5
};

enum eTeronogorMovements
{
    MovementBossDeathSceneStart = 1,
    MovementBossDeathSceneStage01,
    MovementBossDeathSceneEnd
};

Position const g_EndBossCinematicTeleport = { 1904.59f, 2982.96f, 16.844f };
Position const g_EndBossCinematicTeleportPreDespawn = { 1930.304f, 3056.913f, 33.249f };
Position const g_EndBossCinematicTeleportDespawn = { 1925.326f, 3043.384f, -53.435f };

void AddSC_boss_teronogor()
{
    
}
