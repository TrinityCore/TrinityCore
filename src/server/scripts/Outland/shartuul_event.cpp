/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "BattlegroundIC.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "EventMap.h"
#include "TemporarySummon.h"
#include "AreaBoundary.h"
#include "SpellMgr.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "Unit.h"

 /* ContentData: Legion Ring event (Shartuul's Transporter)
 new boss_doomguard_punisher;
 new boss_shivan_assassin;
 new boss_eye_of_shartuul;
 new boss_dreadmaw;
 new boss_shartuul;
 new npc_warp_gate_shield;
 new npc_felguard_degrader;
 new npc_overseer_shartuul;
 new npc_shield_zapper;
 new npc_fel_imp_defender;
 new npc_felhound_defender;
 new npc_ganarg_underling;
 new npc_moarg_tormenter;
 new npc_portable_fel_cannon;
 new npc_fel_eye_stalk;
 RegisterSpellScript(spell_shartuuls_transporter_possess_demon);
 RegisterSpellScript(spell_shartuuls_transporter_possession_transfer);
 RegisterSpellScript(spell_shartuuls_transporter_aspects);
 RegisterSpellScript(spell_shartuuls_transporter_summon_stun_trap);
 RegisterSpellScript(spell_shartuuls_transporter_consume_essence);
 RegisterSpellScript(spell_shartuuls_transporter_build_portable_fel_cannon);
 RegisterSpellScript(spell_shartuuls_transporter_super_jump);
 EndContentData */

enum STActions
{
    ACTION_START_DEMON_I_PHASE_I     = -1,  //battle with trash mobs (Felhound Defender and Fel Imp Defender)
    ACTION_START_DEMON_I_PHASE_II    = -2,  //battle with boss (Doomguard Punisher)
    ACTION_START_DEMON_II_PHASE_I    = -3,  //battle with trash mobs (Gan'arg Underlings and Mo'arg Tormenter)
    ACTION_START_DEMON_II_PHASE_II   = -4,  //battle with boss (Shivan Assassin)
    ACTION_START_DEMON_III_PHASE_I   = -5,  //battle with boss (Eye of Shartuul)
    ACTION_START_DEMON_III_PHASE_II  = -6,  //battle with boss (Dreadmaw)
    ACTION_START_DEMON_III_PHASE_III = -7,  //battle with boss (Shartuul)
    ACTION_EVENT_DONE_OR_FAIL        = -8,
};

enum STGameObjects
{
    GO_FORGE_CAMP_WARP_GATE   = 185902,
    GO_SHIELD_WRECKAGE        = 185925,
    GO_SHIELD_WRECKAGE_MEDIUM = 185926
};

enum STSpells
{
    SPELL_KNOCKBACK        = 40191,
    SPELL_POSSESS_DEMON    = 40309,
    SPELL_CHARM_NORTH_01   = 39985,
    SPELL_CHARM_NORTH_02   = 40382,
    SPELL_CHARM_NORTH_03   = 40523,
    SPELL_INVIS_AND_IMMUNE = 40357
};

enum Creatures
{
    //Bosses
    NPC_FELGUARD_DEGRADER            = 23055,
    NPC_DOOMGUARD_PUNISHER           = 23113,
    NPC_SHIVAN_ASSASSIN              = 23220,
    NPC_SHIVAN_ASSASSIN_RED          = 23474,
    NPC_SHIVAN_ASSASSIN_BLUE         = 23475,
    NPC_SHIVAN_ASSASSIN_BLACK        = 23476,
    NPC_EYE_OF_SHARTUUL              = 23228,
    NPC_DREADMAW                     = 23275,
    NPC_SHARTUUL                     = 23230,

    //Triggers
    NPC_OVERSEER_SHARTUUL            = 23063,
    NPC_TRIGGER_SHIELD_ZAPPER        = 23500,
    NPC_TRIGGER_WARP_GATE_SHIELD     = 23116,
    NPC_TRIGGER_EREDAR_BREATH_TARGET = 23328,
    NPC_TRIGGER_INVISMAN_LG          = 23260,
    NPC_TRIGGER_INVISMAN             = 23059,

    //Trash
    NPC_FEL_IMP_DEFENDER             = 23078,
    NPC_FELHOUND_DEFENDER            = 23173,
    NPC_GAN_ARG_UNDERLING            = 23199,
    NPC_MO_ARG_TORMENTER             = 23212,
    NPC_PORTABLE_FEL_CANNON          = 23278,
    NPC_FEL_EYE_STALK                = 23323
};

typedef std::set<uint32> TrashMobSet;

ParallelogramBoundary* const GreenMatterBoundary = new ParallelogramBoundary
{
    Position(2640.37f, 7089.21f, 0.0f),
    Position(2698.23f, 7184.25f, 0.0f),
    Position(2741.68f, 7046.69f, 0.0f),
};

CreatureBoundary* const FieldBoundary = new CreatureBoundary({ GreenMatterBoundary });

//Fire position after shield explosion
Position const ShieldWreckageCreatePos[8] =
{
    { 2691.03f, 7144.14f, 364.116f },               // Temp fire
    { 2697.72f, 7084.87f, 364.415f },               // Temp fire
    { 2707.42f, 7109.77f, 366.646f },
    { 2719.83f, 7102.84f, 366.647f },
    { 2728.27f, 7112.92f, 380.271f },
    { 2728.08f, 7125.20f, 379.987f },
    { 2720.65f, 7133.99f, 366.645f },
    { 2706.98f, 7118.91f, 373.900f }
};

static Position const EyeOfShartuulSpawnPos = { 2706.92f, 7154.45f, 365.25f, 0.37f };

static Position const DreadmawSpawnPos = { 2705.00f, 7093.24f, 364.91f, 2.19f };

static Position const WarpGateShieldSpawnPos = { 2720.31f, 7117.68f, 371.30f, 4.29094f };

static Position const ShartuulSpawnPos = { 2654.52f, 7150.42f, 364.54f, 5.90889f };

static Position const ShartuulPortalSpawnPos = { 2648.45f, 7152.92f, 364.86f, 5.76889f };

//Position where Shartuul approaches before the start of the battle
static Position const ShartuulCombatPos = { 2694.21f, 7131.45f, 365.15f, 5.733f };

static Position const ForgeCampPos = { 2720.31f, 7117.68f, 367.30f, 4.29094f };

static Position const EredarBreathTargetSpawnPos = { 2648.45f, 7152.92f, 377.35f, 5.76889f };

static Position const SpawnLightningNPCSpawnPos[6] =
{
    {2720.74f, 7118.42f, 393.85f, 0.00f},
    {2720.74f, 7118.42f, 395.85f, 0.00f},
    {2720.74f, 7118.42f, 391.85f, 0.00f},
    {2718.74f, 7118.42f, 393.85f, 0.00f},
    {2720.74f, 7120.42f, 393.85f, 0.00f},
    {2720.74f, 7120.42f, 396.85f, 0.00f}
};

static Position const ZapperPos[4] =
{
    {2640.37f, 7089.21f, 380.85f, 0.00f},
    {2698.23f, 7184.25f, 381.35f, 0.00f},
    {2798.41f, 7135.72f, 380.85f, 0.00f},
    {2741.68f, 7046.69f, 380.85f, 0.00f}
};

//Positions for NPCs that emit lightning before the start of the event
static Position const ZapperTargetPos[12] =
{
    {2740.54f, 7057.71f, 365.36f, 0.00f}, //first zapper target
    {2734.42f, 7055.62f, 365.36f, 0.00f},
    {2731.52f, 7064.95f, 364.46f, 0.00f},
    {2786.71f, 7143.98f, 365.48f, 0.00f}, //second
    {2777.67f, 7140.72f, 365.17f, 0.00f},
    {2789.03f, 7129.18f, 365.59f, 0.00f},
    {2704.49f, 7168.00f, 365.04f, 0.00f}, //third
    {2697.30f, 7174.82f, 366.51f, 0.00f},
    {2710.98f, 7166.74f, 364.57f, 0.00f},
    {2652.43f, 7079.41f, 364.67f, 0.00f}, //fourth
    {2651.76f, 7090.05f, 364.75f, 0.00f},
    {2656.43f, 7094.72f, 365.27f, 0.00f},
};

static Position const GreenMatterSpawnPos[4] =
{
    {2640.37f, 7089.21f, 371.32f, 0.00f},
    {2698.23f, 7184.25f, 371.32f, 0.00f},
    {2798.41f, 7135.72f, 371.32f, 0.00f},
    {2741.68f, 7046.69f, 371.32f, 0.00f}
};

static Position const EredarBeamSpawnPos[2] =
{
    {2713.88f, 7125.00f, 372.35f, 2.58024f},
    {2710.23f, 7120.10f, 372.35f, 2.81893f}
};

//Position added by Mo'arg the Tormentor and his minions
static Position const MoSpawnPos[3] =
{
    {2710.15f, 7155.41f, 365.10f, 0.00f},
    {2761.23f, 7129.37f, 366.81f, 0.00f},
    {2704.05f, 7089.95f, 364.77f, 4.08f}
};

static TrashMobSet const TrashMobs =
{
    NPC_FEL_IMP_DEFENDER,
    NPC_FELHOUND_DEFENDER,
    NPC_GAN_ARG_UNDERLING,
    NPC_MO_ARG_TORMENTER
};

//TODO code style
//TODO check all dist 225f?
//
//TODO SPELL_DISRUPTION_RAY = 41550 - dont work right (aims the beam under himself anyway, must at the enemy)
//TODO JUMP

//////////////////
///NPC TRIGGERS///
//////////////////

/*#####
# npc_overseer_shartuul - Event handler
# This NPC controls the entire event.
# - Spawns thrash mobs, trigger npcs, bosses
# - Spawns Felguard Degrader, Doom Punisher, Shivan Assassin
# - Controls the action. (event stages)
# - Monitors the failure of the event
# - Monitors border crossings
# Appears immediately after the event starts
#####*/

enum OverseerShartuul
{
    EVENT_SPAWN_TRASH_WAVE              = 1,

    EVENT_SPAWN_EYE_OF_SHARTUUL,
    EVENT_SPAWN_DREADMAW,
    EVENT_SPAWN_SHIVAN_ASSASSIN,
    EVENT_SPAWN_SHARTUUL,

    EVENT_SPAWN_MOB_WAVE,
    EVENT_OPEN_SHARTUUL_PORTAL,
    EVENT_CAST_ARCANE_EXPLOSION,
    EVENT_CLOSE_SHARTUULS_PORTAL,
    EVENT_SHARTUUL_MOVE_TO_BATTLE,
    EVENT_SWAP_DEMONS,

    SAY_THREAT                          = 0,
    SAY_EVENT_START,
    SAY_FIRST_HAMMER_THROWN,
    SAY_SHIVAN_IN_PROGRESS,
    SAY_SHIVAN_DONE,
    SAY_DREADMAW_DONE,
    SAY_SHARTUUL_DONE,

    SPELL_COSMETIC_GREEN_MATTER         = 40071,
    SPELL_COSMETIC_EREDAR_PRE_GATE_BEAM = 40605,
    SPELL_COSMETIC_ARCANE_EXPLOSION     = 34808,
    SPELL_COSMETIC_SHARTUUL_PORTAL      = 40280,
    SPELL_COSMETIC_SHIVAN_STASIS        = 40507,
    SPELL_COSMETIC_EREDAR_LIGHTNING     = 40646,
    SPELL_COSMETIC_SHIELD_LIGHTNING     = 41916,
    SPELL_SHADOWFORM                    = 37816,
    SPELL_MADNESS_RIFT                  = 40824,
    SPELL_TOUCH_OF_MADNESS              = 40821,
    SPELL_SPAWN_LIGHTNING               = 39979,

    POINT_SHARTUUL_COMBAT               = 0
};

struct TrashWave
{
    uint8 currWave;
    std::vector<uint32> creatureEntrys;
    std::vector<Seconds> delays; // in seconds
};

// Define waves
std::vector<TrashWave> trashWaves =
{
    {
        0,
        {NPC_FEL_IMP_DEFENDER, NPC_FELHOUND_DEFENDER, NPC_FELHOUND_DEFENDER},
        {14s, 120s}
    },
    {
        0,
        {NPC_GAN_ARG_UNDERLING, NPC_GAN_ARG_UNDERLING},
        {8s, 36s, 64s, 67s}
    },
    {
        0,
        {NPC_MO_ARG_TORMENTER, NPC_GAN_ARG_UNDERLING, NPC_GAN_ARG_UNDERLING, NPC_GAN_ARG_UNDERLING},
        {20s, 100s, 180s}
    },
    {
        0,
        {NPC_GAN_ARG_UNDERLING, NPC_GAN_ARG_UNDERLING},
        {16s}
    }
};

struct npc_overseer_shartuul : public ScriptedAI
{
    npc_overseer_shartuul(Creature* creature) : ScriptedAI(creature), summons(me) { }

    void Initialaize()
    {
        currDemonState = 0;
        _knockBackDist = 5.0f;
        _knockBackX = 0;
        _knockBackY = 0;
        _knockBackOrientation = 0;
        _spawnEyesFirtTime = true;

        _eredarGateBeamGUIDs.clear();
        _wreckageGUIDs.clear();
        _spawnLightningNPCGUIDs.clear();
        _felguardDegraderGUID.Clear();
        _doomPunisherGUID.Clear();
        _eredarBreathTargeGUID.Clear();
        currPossessDemonGUID.Clear();
        _shivanAssassinGUID.Clear();
        _shartuulGUID.Clear();

        SummonStartEventNPC();
    }

    void Reset() override
    {
        summons.DespawnAll();
        events.Reset();
        Initialaize();
    }

    int8 currDemonState;
    EventMap events;
    SummonList summons;
    ObjectGuid currPossessDemonGUID;

    void JustSummoned(Creature* summoned) override
    {
        summons.Summon(summoned);
        //The effect of being struck by green lightning, before a npc appears
        if (TrashMobs.find(summoned->GetEntry()) != TrashMobs.end())
            if (Creature* spawnLightningNPC = FindFreeSpawnLightningNPC())
                spawnLightningNPC->CastSpell(summoned, SPELL_SPAWN_LIGHTNING, false);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        summons.Despawn(summon);
    }

    void JustAppeared() override { }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_TOUCH_OF_MADNESS)
        {
            SpawnEyeStalk();
            DoCast(SPELL_MADNESS_RIFT);
        }
    }

    void DoAction(int32 action) override
    {
        currDemonState = action;

        switch (action)
        {
        case ACTION_START_DEMON_I_PHASE_I: //Trigger the event, activate the barrier
            Talk(SAY_EVENT_START);
            SummonShieldZappers(false);
            SetGreenMatter();
            SetBoundary(FieldBoundary);
            if (_shieldGateGUID)
            {
                Creature* shield = ObjectAccessor::GetCreature(*me, _shieldGateGUID);
                shield->AI()->DoAction(ACTION_START_DEMON_I_PHASE_I);
            }
            events.ScheduleEvent(EVENT_SPAWN_MOB_WAVE, 8s);
            break;
        case ACTION_START_DEMON_I_PHASE_II: //Activate Doom Punisher, remove trash mobs
            if (_doomPunisherGUID)
            {
                Creature* doomPunisher = ObjectAccessor::GetCreature(*me, _doomPunisherGUID);
                summons.DespawnEntry(NPC_FELHOUND_DEFENDER);
                summons.DespawnEntry(NPC_FEL_IMP_DEFENDER);
                doomPunisher->AI()->DoAction(ACTION_START_DEMON_I_PHASE_II);
            }
            IgniteShieldWreckage(true);
            events.Reset();
            break;
        case ACTION_START_DEMON_II_PHASE_I: //Summon Shivan Assassin
            ++waveIndex;
            events.ScheduleEvent(EVENT_SPAWN_MOB_WAVE, 8s);
            events.ScheduleEvent(EVENT_SPAWN_SHIVAN_ASSASSIN, 60s);
            break;
        case ACTION_START_DEMON_II_PHASE_II: //Activate Shivan Assassin
            if (_shivanAssassinGUID)
            {
                Creature* shivanAssassin = ObjectAccessor::GetCreature(*me, _shivanAssassinGUID);
                shivanAssassin->RemoveAurasDueToSpell(SPELL_COSMETIC_SHIVAN_STASIS);
                shivanAssassin->AI()->DoAction(ACTION_START_DEMON_II_PHASE_II);
            }
            Talk(SAY_SHIVAN_IN_PROGRESS);
            break;
        case ACTION_START_DEMON_III_PHASE_I: //Open the portal, and eventually close it
            Talk(SAY_SHIVAN_DONE);
            ActivatePortalBeam();
            events.ScheduleEvent(EVENT_CAST_ARCANE_EXPLOSION, 1s);
            events.ScheduleEvent(EVENT_OPEN_SHARTUUL_PORTAL, 10s);
            events.ScheduleEvent(EVENT_SPAWN_SHARTUUL, 18s);
            events.ScheduleEvent(EVENT_CLOSE_SHARTUULS_PORTAL, 23s);
            break;
        case ACTION_START_DEMON_III_PHASE_II: //Summon DreadMaw
            if (_shartuulGUID)
            {
                Creature* shartuul = ObjectAccessor::GetCreature(*me, _shartuulGUID);
                shartuul->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
            }
            events.ScheduleEvent(EVENT_SPAWN_DREADMAW, 10s);
            break;
        case ACTION_START_DEMON_III_PHASE_III:
            if (_shartuulGUID)
            {
                Creature* shartuul = ObjectAccessor::GetCreature(*me, _shartuulGUID);
                shartuul->CastSpell(me, SPELL_TOUCH_OF_MADNESS);
                events.ScheduleEvent(EVENT_SHARTUUL_MOVE_TO_BATTLE, 8s);
            }
            break;
        case ACTION_EVENT_DONE_OR_FAIL: //Reset event
            IgniteShieldWreckage(false);
            Reset();
            break;
        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!currDemonState)
            return;

        CheckBoundary();

        if (events.Empty())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                //!Wave handler
            case EVENT_SPAWN_MOB_WAVE:
            {
                if (waveIndex >= trashWaves.size()) // If all waves are cleared, the following action begins
                {
                    DoAction(ACTION_START_DEMON_II_PHASE_II);
                    break;
                }
                for (uint8 i = 0; i < trashWaves[waveIndex].delays.size(); ++i)
                    events.ScheduleEvent(EVENT_SPAWN_TRASH_WAVE, trashWaves[waveIndex].delays[i]);
                Talk(SAY_THREAT);
            }
            break;
            //!Bosses spawn events (INTRO PHASE)
            case EVENT_SPAWN_SHIVAN_ASSASSIN:
                if (Creature* creature = DoSummon(NPC_SHIVAN_ASSASSIN, ForgeCampPos, 0s, TEMPSUMMON_MANUAL_DESPAWN))
                {
                    DoCast(creature, SPELL_COSMETIC_SHIVAN_STASIS);
                    _shivanAssassinGUID = creature->GetGUID();
                }
                break;
            case EVENT_SPAWN_EYE_OF_SHARTUUL:
                if (Creature* eyeOfShartuul = DoSummon(NPC_EYE_OF_SHARTUUL, EyeOfShartuulSpawnPos, 0s, TEMPSUMMON_MANUAL_DESPAWN))
                {
                    if (_shartuulGUID)
                    {
                        Creature* shartuul = ObjectAccessor::GetCreature(*me, _shartuulGUID);
                        shartuul->SetFacingTo(shartuul->GetAbsoluteAngle(eyeOfShartuul));
                        shartuul->CastSpell(eyeOfShartuul, SPELL_COSMETIC_EREDAR_LIGHTNING);
                    }
                }
                break;
            case EVENT_SPAWN_DREADMAW:
                if (Creature* dreadMaw = DoSummon(NPC_DREADMAW, DreadmawSpawnPos, 0s, TEMPSUMMON_MANUAL_DESPAWN))
                {
                    if (_shartuulGUID)
                    {
                        Creature* shartuul = ObjectAccessor::GetCreature(*me, _shartuulGUID);
                        shartuul->SetFacingTo(shartuul->GetAbsoluteAngle(dreadMaw));
                        shartuul->CastSpell(dreadMaw, SPELL_COSMETIC_EREDAR_LIGHTNING);
                    }
                }
                break;
            case EVENT_SPAWN_SHARTUUL:
                if (Creature* creature = DoSummon(NPC_SHARTUUL, ShartuulSpawnPos, 0s, TEMPSUMMON_DEAD_DESPAWN))
                    _shartuulGUID = creature->GetGUID();
                break;
            case EVENT_SPAWN_TRASH_WAVE:
                SummonTrashWave(me, trashWaves[waveIndex]);
                if (!waveIndex) //The first wave of mobs shouldn't end until the boss shows up
                    events.ScheduleEvent(EVENT_SPAWN_TRASH_WAVE, 7s, 14s);
                else
                    if (++trashWaves[waveIndex].currWave == trashWaves[waveIndex].delays.size())
                    {
                        ++waveIndex;
                        events.ScheduleEvent(EVENT_SPAWN_MOB_WAVE, 20s);
                    }
                break;
            case EVENT_OPEN_SHARTUUL_PORTAL:
                events.CancelEvent(EVENT_CAST_ARCANE_EXPLOSION);
                if (Creature* creature = DoSummon(NPC_TRIGGER_EREDAR_BREATH_TARGET, ShartuulPortalSpawnPos, 20s, TEMPSUMMON_TIMED_DESPAWN))
                    creature->AI()->DoCastSelf(SPELL_COSMETIC_SHARTUUL_PORTAL);
                break;
            case EVENT_CAST_ARCANE_EXPLOSION:
                if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_EREDAR_BREATH_TARGET, 100.0f))
                    creature->AI()->DoCastSelf(SPELL_COSMETIC_ARCANE_EXPLOSION);
                events.ScheduleEvent(EVENT_CAST_ARCANE_EXPLOSION, 3s);
                break;
            case EVENT_CLOSE_SHARTUULS_PORTAL:
                if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_EREDAR_BREATH_TARGET, 100.0f))
                    creature->RemoveAurasDueToSpell(SPELL_COSMETIC_SHARTUUL_PORTAL);
                events.ScheduleEvent(EVENT_SPAWN_EYE_OF_SHARTUUL, 7s);  //Summon Eye of Shartuul
                break;
            case EVENT_SHARTUUL_MOVE_TO_BATTLE:
                if (_shartuulGUID)
                {
                    Creature* shartuul = ObjectAccessor::GetCreature(*me, _shartuulGUID);
                    shartuul->GetMotionMaster()->MovePoint(POINT_SHARTUUL_COMBAT, ShartuulCombatPos);
                }
                break;
            default:
                break;
            }
        }
    }

    void SummonTrashWave(Creature* me, const TrashWave& wave)
    {
        for (uint32 creatureId : wave.creatureEntrys)
        {
            if (waveIndex == 2 && creatureId == NPC_MO_ARG_TORMENTER)
            {
                DoSummon(NPC_MO_ARG_TORMENTER, MoSpawnPos[wave.currWave], 0s, TEMPSUMMON_DEAD_DESPAWN);
                for (uint8 i = 0; i < 4; ++i)
                    FindPosAndSpawnMoUnderling(i, MoSpawnPos[wave.currWave]); //Summon Gan'arg near Mo'arg
            }
            else
                DoSummon(creatureId, me->GetRandomPoint(ForgeCampPos, 50.0f), 0s, TEMPSUMMON_DEAD_DESPAWN);
        }
    }

    void SummonStartEventNPC()
    {
        DoSummon(NPC_FELGUARD_DEGRADER, me->GetRandomPoint(ForgeCampPos, 30.0f), 0s, TEMPSUMMON_DEAD_DESPAWN);
        if (Creature* creature = DoSummon(NPC_TRIGGER_WARP_GATE_SHIELD, WarpGateShieldSpawnPos, 0s, TEMPSUMMON_DEAD_DESPAWN))
            _shieldGateGUID = creature->GetGUID();
        if (Creature* creature = DoSummon(NPC_DOOMGUARD_PUNISHER, ForgeCampPos, 0s, TEMPSUMMON_DEAD_DESPAWN))
            _doomPunisherGUID = creature->GetGUID();
        for (uint8 i = 0; i < 6; i++)
            if (Creature* creature = DoSummon(NPC_TRIGGER_INVISMAN, SpawnLightningNPCSpawnPos[i], 0s, TEMPSUMMON_MANUAL_DESPAWN))
                _spawnLightningNPCGUIDs.emplace_back(creature->GetGUID());
        SummonShieldZappers(true);
    }

    Creature* FindFreeSpawnLightningNPC()
    {
        for (const auto& el : _spawnLightningNPCGUIDs)
            if (el)
            {
                Creature* creature = ObjectAccessor::GetCreature(*me, el);
                if (creature->GetSpellHistory()->IsReady(sSpellMgr->GetSpellInfo(SPELL_SPAWN_LIGHTNING)) &&
                    !creature->HasUnitState(UNIT_STATE_CASTING))
                    return creature;
            }
        return nullptr;
    }

    void CheckBoundary()
    {
        if (currPossessDemonGUID)
        {
            Creature* creature = ObjectAccessor::GetCreature(*me, currPossessDemonGUID);
            if (!IsInBoundary(creature))
                // If the creature is not within the boundary, compute the knockback.
                ComputeKnockback(creature);
        }
    };

    // This function turns the barrier on
    void SetGreenMatter()
    {
        std::vector<Creature*> temp;

        // To activate Green Matter, summon creatures and cast a spell on them in a specific order
        for (uint8 i = 0; i < 4; ++i)
            if (Creature* creature = DoSummon(NPC_TRIGGER_INVISMAN, GreenMatterSpawnPos[i], 0s, TEMPSUMMON_MANUAL_DESPAWN))
                temp.emplace_back(creature);
        if (temp.size() == 4)
            for (uint8 i = 0; i < 4; ++i)
                temp[i]->CastSpell(temp[(i + 1) % temp.size()], SPELL_COSMETIC_GREEN_MATTER);
    }

    void ComputeKnockback(Creature* creature)
    {
        _knockBackOrientation = creature->GetAbsoluteAngle(ForgeCampPos) + static_cast<float>(M_PI);
        creature->GetNearPoint2D(nullptr, _knockBackX, _knockBackY, _knockBackDist, _knockBackOrientation);
        creature->KnockbackFrom(_knockBackX, _knockBackY, 16, 12);
    }

    void IgniteShieldWreckage(bool on)
    {
        if (on)
        {
            for (uint8 i = 0; i < 8; ++i)
            {
                // Summon game objects for the shield wreckage.
                const bool isTemporary = i < 2;
                QuaternionData rotation = QuaternionData::fromEulerAnglesZYX(ShieldWreckageCreatePos[i].GetPositionZ(), 0.f, 0.f);
                _wreckageGUIDs.push_back(me->SummonGameObject(GO_SHIELD_WRECKAGE_MEDIUM, ShieldWreckageCreatePos[i], rotation,
                    isTemporary ? 25s : 0s, GOSummonType(GO_SUMMON_TIMED_OR_CORPSE_DESPAWN))->GetGUID());
            }
        }
        else
        {
            if (!_wreckageGUIDs.empty())
                for (uint8 i = 2; i < 8; ++i)
                {
                    // Despawn shield wreckage.
                    if (_wreckageGUIDs[i])
                    {
                        GameObject* go = ObjectAccessor::GetGameObject(*me, _wreckageGUIDs[i]);
                        go->DespawnOrUnsummon();
                    }
                }
        }
    }

    void FindPosAndSpawnMoUnderling(uint8 i, Position moPos)
    {
        if (trashWaves[2].currWave == 2)
        {
            //Calculate position by line
            static const std::vector<std::pair<int8, int8>> offsets = { {-20, 12}, {-10, 10}, {10, -10}, {20, -12} };
            if (i < offsets.size())
            {
                moPos.m_positionX += offsets[i].first;
                moPos.m_positionY += offsets[i].second;
            }
        }
        else
        {
            //Calculate position by square
            static const std::vector<std::pair<int8, int8>> offsets = { {-10, -10}, {10, -10}, {-10, 10}, {10, 10} };
            if (i < offsets.size())
            {
                moPos.m_positionX += offsets[i].first;
                moPos.m_positionY += offsets[i].second;
            }
        }
        DoSummon(NPC_GAN_ARG_UNDERLING, moPos, 0s, TEMPSUMMON_DEAD_DESPAWN);
    }

    void ActivatePortalBeam()
    {
        // If the gate is to be opened, summon the necessary creatures and cast the pre gate beam
        if (Creature* eredarBreathTarget = DoSummon(NPC_TRIGGER_EREDAR_BREATH_TARGET, EredarBreathTargetSpawnPos, 15s, TEMPSUMMON_TIMED_DESPAWN))
        {
            _eredarBreathTargeGUID = eredarBreathTarget->GetGUID();
            for (uint8 i = 0; i < 2; ++i)
                if (Creature* eredarBeam = DoSummon(NPC_TRIGGER_INVISMAN_LG, EredarBeamSpawnPos[i], 15s, TEMPSUMMON_TIMED_DESPAWN))
                {
                    _eredarGateBeamGUIDs.push_back(eredarBeam->GetGUID());
                    eredarBeam->CastSpell(eredarBreathTarget, SPELL_COSMETIC_EREDAR_PRE_GATE_BEAM);
                }
        }
    }

    void SpawnEyeStalk()
    {
        if (_spawnEyesFirtTime)
        {
            //Eyes appears all over the arena
            for (uint8 i = 0; i < 16; ++i)
                DoSummon(NPC_FEL_EYE_STALK, me->GetRandomPoint(ForgeCampPos, 50.0f), 0s, TEMPSUMMON_MANUAL_DESPAWN);
        }
        else
        {
            //Eyes spawns near the player
            for (uint8 i = 0; i < 6; ++i)
            {
                if (!_shivanAssassinGUID)
                    break;
                Position pos = me->GetRandomPoint(ObjectAccessor::GetCreature(*me, _shivanAssassinGUID)->GetPosition(), 15.0f);
                DoSummon(NPC_FEL_EYE_STALK, pos, 0s, TEMPSUMMON_MANUAL_DESPAWN);
            }
        }
        _spawnEyesFirtTime = false;
    }

    void SummonShieldZappers(bool on)
    {
        if (on) //Summon shield zappers at the columns
        {
            for (uint8 i = 0; i < 12; ++i)
                DoSummon(NPC_TRIGGER_INVISMAN_LG, ZapperTargetPos[i], 0s, TEMPSUMMON_MANUAL_DESPAWN); //target
            for (uint8 i = 0; i < 4; ++i)
                DoSummon(NPC_TRIGGER_SHIELD_ZAPPER, ZapperPos[i], 0s, TEMPSUMMON_MANUAL_DESPAWN);
        }
        else //Despawn all shield zappers at the columns
        {
            summons.DespawnEntry(NPC_TRIGGER_INVISMAN_LG); //target
            summons.DespawnEntry(NPC_TRIGGER_SHIELD_ZAPPER);
        }
    }

private:
    bool _spawnEyesFirtTime;
    float _knockBackDist;
    float _knockBackX, _knockBackY;
    float _knockBackOrientation;
    GuidVector _eredarGateBeamGUIDs;
    GuidVector _wreckageGUIDs;
    GuidVector _spawnLightningNPCGUIDs;
    ObjectGuid _shieldGateGUID;
    ObjectGuid _felguardDegraderGUID;
    ObjectGuid _doomPunisherGUID;
    ObjectGuid _shivanAssassinGUID;
    ObjectGuid _shartuulGUID;
    ObjectGuid _eredarBreathTargeGUID;

    uint8 waveIndex = 0;
};

/*#####
# npc_warp_gate_shield
# This NPC monitor hits to the shield and explosion of the shield
#####*/

enum WarpGateShield
{
    EVENT_DEFENSE_BEAM              = 1,
    EVENT_CAST_GREEN_LIGHTNING,

    SPELL_COSMETIC_SHELL_SHIELD     = 40158,
    SPELL_COSMETIC_SHIELD_EXPLODE   = 41918,
    SPELL_SHIELD_DEFENSE_BEAM       = 40380,
    SPELL_SMASH_SHIELD              = 40222,
    SPELL_COSMETIC_GREEN_LIGHTNING  = 40146
};

struct npc_warp_gate_shield : public ScriptedAI
{
    npc_warp_gate_shield(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _shiledHit = 0;
        _events.Reset();
        DoCastSelf(SPELL_COSMETIC_SHELL_SHIELD);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_START_DEMON_I_PHASE_I:
            _events.ScheduleEvent(EVENT_DEFENSE_BEAM, 1min);
            break;
        default:
            break;
        }
    }

    void JustAppeared() override
    {
        if (Creature* overseerShartuul = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 250.0f))
            _overseerShartuulGUID = overseerShartuul->GetGUID();
        _events.ScheduleEvent(EVENT_CAST_GREEN_LIGHTNING, 1s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SMASH_SHIELD)
        {
            ++_shiledHit;
            _events.CancelEvent(EVENT_DEFENSE_BEAM);
            if (_shiledHit == 1)
                if (_overseerShartuulGUID)
                {
                    Creature* overseerShartuul = ObjectAccessor::GetCreature(*me, _overseerShartuulGUID);
                    overseerShartuul->AI()->Talk(SAY_FIRST_HAMMER_THROWN);
                }
            if (_shiledHit == 8) //After eight hits, the shield explodes
            {
                ShieldExplode();
                _events.Reset();
                return;
            }
            _events.ScheduleEvent(EVENT_DEFENSE_BEAM, 1min);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (_events.Empty())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                //If the shield does not get hit within a minute, the demon dies and the event will fail.
            case EVENT_DEFENSE_BEAM:
                if (Creature* creature = me->FindNearestCreature(NPC_FELGUARD_DEGRADER, 200.0f))
                    creature->AI()->DoCastSelf(SPELL_SHIELD_DEFENSE_BEAM);
                break;
            case EVENT_CAST_GREEN_LIGHTNING:
                _events.ScheduleEvent(EVENT_CAST_GREEN_LIGHTNING, 9s);
                if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_INVISMAN_LG, 35.0f))
                    me->CastSpell(creature, SPELL_COSMETIC_SHIELD_LIGHTNING);
                break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    void ShieldExplode()
    {
        me->RemoveAura(SPELL_COSMETIC_SHELL_SHIELD);
        Position pos = me->GetPosition();
        pos.m_positionZ -= 5;
        me->NearTeleportTo(pos, true);
        DoCastSelf(SPELL_COSMETIC_SHIELD_EXPLODE);

        //Inform Overseer that the shield has exploded.
        if (_overseerShartuulGUID)
        {
            Creature* overseerShartuul = ObjectAccessor::GetCreature(*me, _overseerShartuulGUID);
            overseerShartuul->AI()->DoAction(ACTION_START_DEMON_I_PHASE_II);
        }
    }

private:
    EventMap _events;
    uint8 _shiledHit;
    ObjectGuid _overseerShartuulGUID;
};

/*#####
# npc_shield_zapper
# This npc controls lightning at the columns and at the portal
#####*/

struct npc_shield_zapper : public ScriptedAI
{
    npc_shield_zapper(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _events.ScheduleEvent(EVENT_CAST_GREEN_LIGHTNING, 1s, 4s);
    }

    void Reset() override
    {
        _events.Reset();
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (_events.Empty())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CAST_GREEN_LIGHTNING:
                _events.ScheduleEvent(EVENT_CAST_GREEN_LIGHTNING, 9s);
                if (Creature* creature = me->FindNearestCreature(NPC_TRIGGER_INVISMAN_LG, 35.0f))
                    me->CastSpell(creature, SPELL_COSMETIC_SHIELD_LIGHTNING);
                break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
};

//////////////////////
///POSSESSED DEMONS///
//////////////////////

/*#####
# possess_demonAI - Base AI-structure used for the possessed Demons
#####*/

enum PossessDemon
{
    EVENT_CAST_TRANSFORM                    = 20,

    SPELL_DOOMPUNISHER_POSSESSION_TRANSFER  = 40503,
    SPELL_SHIVAN_POSSESSION_TRANSFER        = 41962
};

struct possess_demonAI : public WorldBossAI
{
    possess_demonAI(Creature* creature) : WorldBossAI(creature)
    {
        if (me->GetEntry() != NPC_FELGUARD_DEGRADER)
            Initialize();
    }

    void Initialize()
    {
        SetActive(false);
    }
        
    void OnCharmed(bool isNew) override
    {
        if (!me->IsAlive() && !me->isPossessedByPlayer())
        {
            // If the creature is not alive, trigger "event" failure
            if (TempSummon* tempSummon = me->ToTempSummon())
                if (Unit* creature = tempSummon->GetSummonerUnit())
                    creature->GetAI()->DoAction(ACTION_EVENT_DONE_OR_FAIL);
        }
    }

    void DoAction(int32 action) override
    {
        SetActive(true);
        switch (action)
        {
        case ACTION_START_DEMON_I_PHASE_II:
            AttackStart(me->FindNearestCreature(NPC_FELGUARD_DEGRADER, 225.0f));
            break;
        case ACTION_START_DEMON_II_PHASE_II:
            AttackStart(me->FindNearestCreature(NPC_DOOMGUARD_PUNISHER, 225.0f));
            break;
        default:
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && !me->isPossessedByPlayer())
        {
            damage = me->GetHealth() - 1;
            me->CastStop();
            events.Reset();

            //Possess the demon
            if (me->GetEntry() == NPC_SHIVAN_ASSASSIN)
                DoCastVictim(SPELL_SHIVAN_POSSESSION_TRANSFER);
            else
                DoCastVictim(SPELL_DOOMPUNISHER_POSSESSION_TRANSFER);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && events.Empty())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }

    void SetActive(bool on)
    {
        if (on)
        {
            me->RemoveAurasDueToSpell(SPELL_SHADOWFORM);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
            me->SetFaction(FACTION_ENEMY);
        }
        else
        {
            DoCastSelf(SPELL_SHADOWFORM);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
        }
    }
};

/*#####
# npc_felguard_degrader - first possessed demon
#####*/

struct npc_felguard_degrader : public possess_demonAI
{
    npc_felguard_degrader(Creature* creature) : possess_demonAI(creature) { }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override {}

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (Player* player = caster->ToPlayer())
            player->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC); //todo replace
        
        if (spellInfo->Id == SPELL_POSSESS_DEMON)
        {
            if (TempSummon* tempSummon = me->ToTempSummon())
                if (Unit* unit = tempSummon->GetSummonerUnit())
                    if (Creature* overseerShartuul = unit->ToCreature())
                    {
                        ENSURE_AI(npc_overseer_shartuul, overseerShartuul->AI())->currPossessDemonGUID = me->GetGUID();
                        overseerShartuul->AI()->DoAction(ACTION_START_DEMON_I_PHASE_I);
                        me->SetFaction(FACTION_ENEMY);
                    }
        }

        if (spellInfo->Id == SPELL_DOOMPUNISHER_POSSESSION_TRANSFER)
            me->CastStop();
    }
};

/*#####
# boss_doomguard_punisher - second possessed demon
#####*/

enum DoomguardPunisher
{
    EVENT_CAST_FEL_FLAMES = 1,
    SPELL_FEL_FLAMES      = 40561,
};

struct boss_doomguard_punisher : public possess_demonAI
{
    boss_doomguard_punisher(Creature* creature) : possess_demonAI(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        WorldBossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CAST_FEL_FLAMES, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_CAST_FEL_FLAMES:
            DoCastVictim(SPELL_FEL_FLAMES);
            events.ScheduleEvent(EVENT_CAST_FEL_FLAMES, 45s);
            break;
        default:
            possess_demonAI::ExecuteEvent(eventId);
            break;
        }
    }
};
/*#####
# boss_shivan_assassin - third possessed demon
#####*/

enum ShivanAssassin
{
    EVENT_CAST_DEATH_BLAST          = 10,
    EVENT_CAST_PYROBLAST,
    EVENT_CAST_ICEBLAST,
    EVENT_CAST_ASPECT_OF_THE_FLAME,
    EVENT_CAST_ASPECT_OF_THE_ICE,
    EVENT_CAST_ASPECT_OF_THE_SHADOW,

    SPELL_DEATH_BLAST               = 40736,
    SPELL_PYROBLAST                 = 41578,
    SPELL_ICEBLAST                  = 41579,
    SPELL_ASPECT_OF_THE_FLAME       = 41593,
    SPELL_ASPECT_OF_THE_ICE         = 41594,
    SPELL_ASPECT_OF_THE_SHADOW      = 41595,
};

struct boss_shivan_assassin : public possess_demonAI
{
    boss_shivan_assassin(Creature* creature) : possess_demonAI(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        WorldBossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CAST_PYROBLAST, 15s);
        events.ScheduleEvent(EVENT_CAST_ICEBLAST, 30s);
        events.ScheduleEvent(EVENT_CAST_DEATH_BLAST, 5s);
        events.ScheduleEvent(EVENT_CAST_ASPECT_OF_THE_FLAME, 10s);
        events.ScheduleEvent(EVENT_CAST_ASPECT_OF_THE_ICE, 25s);
        events.ScheduleEvent(EVENT_CAST_ASPECT_OF_THE_SHADOW, 50s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_CAST_PYROBLAST:
            if (me->HasAura(SPELL_ASPECT_OF_THE_FLAME))
                DoCastVictim(SPELL_PYROBLAST);
            events.ScheduleEvent(EVENT_CAST_PYROBLAST, 15s);
            break;
        case EVENT_CAST_ICEBLAST:
            if (me->HasAura(SPELL_ASPECT_OF_THE_ICE))
                DoCastVictim(SPELL_ICEBLAST);
            events.ScheduleEvent(EVENT_CAST_ICEBLAST, 15s);
            break;
        case EVENT_CAST_DEATH_BLAST:
            if (me->HasAura(SPELL_ASPECT_OF_THE_SHADOW))
                DoCastVictim(SPELL_DEATH_BLAST);
            events.ScheduleEvent(EVENT_CAST_DEATH_BLAST, 15s);
            break;
        case EVENT_CAST_ASPECT_OF_THE_FLAME:
            DoCastVictim(SPELL_ASPECT_OF_THE_FLAME);
            events.ScheduleEvent(EVENT_CAST_ASPECT_OF_THE_FLAME, 35s);
            break;
        case EVENT_CAST_ASPECT_OF_THE_ICE:
            DoCastVictim(SPELL_ASPECT_OF_THE_ICE);
            events.ScheduleEvent(EVENT_CAST_ASPECT_OF_THE_ICE, 35s);
            break;
        case EVENT_CAST_ASPECT_OF_THE_SHADOW:
            DoCastVictim(SPELL_ASPECT_OF_THE_SHADOW);
            events.ScheduleEvent(EVENT_CAST_ASPECT_OF_THE_SHADOW, 35s);
            break;
        default:
            possess_demonAI::ExecuteEvent(eventId);
            break;
        }
    }
};

///////////////////
///COMMON BOSSES///
///////////////////

/*#####
# boss_eye_of_shartuul
#####*/

enum EyeOfShartuul
{
    SAY_EMOTE                  = 0,
    EVENT_CAST_DARK_GLARE      = 1,
    EVENT_CAST_DISRUPTION_RAY,
    EVENT_CAST_FEL_FIREBALL,
    EVENT_CAST_TONGUE_LASH,
    SPELL_DARK_GLARE           = 41936,
    SPELL_DISRUPTION_RAY       = 41550, //TODO doesn't work right (aims the beam under himself anyway, must at the enemy)
    SPELL_FEL_FIREBALL         = 40633,
    SPELL_TONGUE_LASH          = 42002,
    SPELL_BEHOLDER_TRANSFORM   = 40534,
    MODEL_IMAGE_OF_EMPTY       = 19595,
};

struct boss_eye_of_shartuul : public WorldBossAI
{
    boss_eye_of_shartuul(Creature* creature) : WorldBossAI(creature) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_CAST_TRANSFORM, 5s);
        me->SetDisplayId(MODEL_IMAGE_OF_EMPTY);
    }

    void JustEngagedWith(Unit* who) override
    {
        AttackStart(who);
        events.ScheduleEvent(EVENT_CAST_DARK_GLARE, 25s);
        events.ScheduleEvent(EVENT_CAST_DISRUPTION_RAY, 21s);
        events.ScheduleEvent(EVENT_CAST_FEL_FIREBALL, 13s);
        events.ScheduleEvent(EVENT_CAST_TONGUE_LASH, 6s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* creature = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 200.0f))
            creature->AI()->DoAction(ACTION_START_DEMON_III_PHASE_II);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && events.Empty())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CAST_DARK_GLARE:
                Talk(SAY_EMOTE);
                DoCastVictim(SPELL_DARK_GLARE);
                events.ScheduleEvent(EVENT_CAST_DARK_GLARE, 27s, 31s);
                break;
            case EVENT_CAST_DISRUPTION_RAY:
                DoCastVictim(SPELL_DISRUPTION_RAY);
                events.ScheduleEvent(EVENT_CAST_DISRUPTION_RAY, 20s, 22s);
                break;
            case EVENT_CAST_FEL_FIREBALL:
                DoCastVictim(SPELL_FEL_FIREBALL);
                events.ScheduleEvent(EVENT_CAST_FEL_FIREBALL, 20s, 26s);
                break;
            case EVENT_CAST_TONGUE_LASH:
                DoCastVictim(SPELL_TONGUE_LASH);
                events.ScheduleEvent(EVENT_CAST_TONGUE_LASH, 6s, 11s);
                break;
            case EVENT_CAST_TRANSFORM:
                DoCastSelf(SPELL_BEHOLDER_TRANSFORM);
                me->SetFaction(FACTION_ENEMY);
                AttackStart(me->FindNearestCreature(NPC_SHIVAN_ASSASSIN, 100.0f));
                break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }
};

/*#####
# boss_dreadmaw
#####*/

enum Dreadmaw
{
    EVENT_CAST_GROWTH            = 1,
    EVENT_CAST_LACERATING_BITE,
    EVENT_CAST_RAMPAGING_CHARGE,
    EVENT_CAST_WAR_STOMP,
    SPELL_GROWTH                 = 41953,
    SPELL_LACERATING_BITE        = 41940,
    SPELL_RAMPAGING_CHARGE       = 41939,
    SPELL_WAR_STOMP              = 35238,
    SPELL_WRATH_HOUND_TRANSFORM  = 40648,
};

struct boss_dreadmaw : public WorldBossAI
{
    boss_dreadmaw(Creature* creature) : WorldBossAI(creature) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_CAST_TRANSFORM, 2s);
        me->SetDisplayId(MODEL_IMAGE_OF_EMPTY);
    }

    void JustEngagedWith(Unit* who) override
    {
        AttackStart(who);
        events.ScheduleEvent(EVENT_CAST_GROWTH, 4s);
        events.ScheduleEvent(EVENT_CAST_LACERATING_BITE, 5s);
        events.ScheduleEvent(EVENT_CAST_RAMPAGING_CHARGE, 13s);
        events.ScheduleEvent(EVENT_CAST_WAR_STOMP, 6s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* creature = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 200.0f))
        {
            creature->AI()->Talk(SAY_DREADMAW_DONE);
            creature->AI()->DoAction(ACTION_START_DEMON_III_PHASE_III);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && events.Empty())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CAST_GROWTH:
                DoCastSelf(SPELL_GROWTH);
                events.ScheduleEvent(EVENT_CAST_GROWTH, 45s);
                break;
            case EVENT_CAST_LACERATING_BITE:
                DoCastVictim(SPELL_LACERATING_BITE);
                events.ScheduleEvent(EVENT_CAST_LACERATING_BITE, 45s, 55s);
                break;
            case EVENT_CAST_RAMPAGING_CHARGE:
                Talk(SAY_EMOTE); // Talk(SAY_EMOTE, me->GetVictim());
                DoCastVictim(SPELL_RAMPAGING_CHARGE);
                events.ScheduleEvent(EVENT_CAST_RAMPAGING_CHARGE, 13s, 18s);
                break;
            case EVENT_CAST_WAR_STOMP:
                DoCastVictim(SPELL_WAR_STOMP);
                events.ScheduleEvent(EVENT_CAST_WAR_STOMP, 8s, 12s);
                break;
            case EVENT_CAST_TRANSFORM:
                DoCastSelf(SPELL_WRATH_HOUND_TRANSFORM);
                me->SetFaction(FACTION_ENEMY);
                JustEngagedWith(me->FindNearestCreature(NPC_SHIVAN_ASSASSIN, 100.0f));
                break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }
};

/*#####
# boss_shartuul
#####*/

enum Shartuul
{
    SAY_AGRO                        = 0,
    SAY_INCINERATE,
    EVENT_CAST_IMMOLATE             = 1,
    EVENT_CAST_INCINERATE,
    EVENT_CAST_MAGNETIC_PUL,
    EVENT_CAST_SHADOW_BOLT,
    EVENT_CAST_SHADOW_RESONANCE,
    EVENT_CAST_METEOR,
    SPELL_IMMOLATE                  = 41958,
    SPELL_INCINERATE                = 41960,
    SPELL_MAGNETIC_PULL             = 41959,
    SPELL_SHADOW_BOLT               = 41957,
    SPELL_SHADOW_RESONANCE          = 41961,
};

struct boss_shartuul : public WorldBossAI
{
    boss_shartuul(Creature* creature) : WorldBossAI(creature) { }

    void JustAppeared() override
    {
        SetActive(false);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            switch (pointId)
            {
            case POINT_SHARTUUL_COMBAT:
                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                events.ScheduleEvent(EVENT_CAST_TRANSFORM, 4s);
                break;
            default:
                break;
            }
        }
    }

    void OnSpellCast(const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_MAGNETIC_PULL)
            me->NearTeleportTo(me->GetRandomPoint(ForgeCampPos, 40.0f), true);
    }

    void JustEngagedWith(Unit* who) override
    {
        WorldBossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CAST_IMMOLATE, 4s);
        events.ScheduleEvent(EVENT_CAST_INCINERATE, 5s);
        events.ScheduleEvent(EVENT_CAST_MAGNETIC_PUL, 2s);
        events.ScheduleEvent(EVENT_CAST_SHADOW_BOLT, 100ms);
        events.ScheduleEvent(EVENT_CAST_SHADOW_RESONANCE, 7s);
        events.ScheduleEvent(EVENT_CAST_METEOR, 60s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (Creature* creature = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 200.0f))
            {
                //This is to keep Shartuul's corpse from disappearing after the event resets
                SummonList& summons = ENSURE_AI(npc_overseer_shartuul, creature->AI())->summons;
                for (auto itr = summons.begin(); itr != summons.end(); ++itr)
                {
                    if (itr->GetEntry() == me->GetEntry())
                    {
                        summons.erase(itr);
                        break;
                    }
                }
                creature->AI()->Talk(SAY_SHARTUUL_DONE);
                creature->AI()->DoAction(ACTION_EVENT_DONE_OR_FAIL);
            }
            me->KillSelf();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && events.Empty())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CAST_IMMOLATE:
                DoCastSelf(SPELL_IMMOLATE);
                events.ScheduleEvent(EVENT_CAST_IMMOLATE, 45s);
                break;
            case EVENT_CAST_INCINERATE:
                Talk(SAY_INCINERATE);
                DoCastVictim(SPELL_INCINERATE);
                me->RemoveAurasDueToSpell(SPELL_IMMOLATE);
                events.ScheduleEvent(EVENT_CAST_INCINERATE, 46s, 55s);
                break;
            case EVENT_CAST_MAGNETIC_PUL:
                DoCastVictim(SPELL_MAGNETIC_PULL);
                events.ScheduleEvent(EVENT_CAST_MAGNETIC_PUL, 5s, 5s);
                break;
            case EVENT_CAST_SHADOW_BOLT:
                DoCastVictim(SPELL_SHADOW_BOLT);
                events.ScheduleEvent(EVENT_CAST_SHADOW_BOLT, 8s, 12s);
                break;
            case EVENT_CAST_SHADOW_RESONANCE:
                DoCastVictim(SPELL_SHADOW_RESONANCE);
                events.ScheduleEvent(EVENT_CAST_SHADOW_RESONANCE, 8s, 12s);
                break;
            case EVENT_CAST_METEOR:
                DoCast(SPELL_TOUCH_OF_MADNESS);
                events.ScheduleEvent(EVENT_CAST_METEOR, 50s);
                break;
            case EVENT_CAST_TRANSFORM:
                SetActive(true);
                Talk(SAY_AGRO);
                me->SetFaction(FACTION_ENEMY);
                JustEngagedWith(me->FindNearestCreature(NPC_SHIVAN_ASSASSIN, 100.0f));
                break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }

    void SetActive(bool on)
    {
        if (on)
        {
            me->RemoveAurasDueToSpell(SPELL_SHADOWFORM);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
        }
        else
        {
            DoCastSelf(SPELL_SHADOWFORM);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
        }
    }
};

////////////////
///TRASH MOBS///
////////////////

/*#####
# trash_defenderAI - Base AI-structure used for all the trash mobs
# - Fel Imp Defender
# - Gan'arg Underling
# - Mo'arg Tormenter
# - Portable Fel Cannon
# - Fel Eye Stalk
#####*/

enum TrashDefender
{
    EVENT_TRANSFORM                         = 1,

    //Fel Imp Defender
    EVENT_CAST_FIREBALL,

    //Gan'arg Underling
    EVENT_CAST_HEALTH_FUNNEL,
    EVENT_CAST_BUILD_PORTABLE_FEL_CANNON,

    //Mo'arg Tormenter
    EVENT_CAST_ACID_GEYSER,

    //Portable Fel Cannon
    EVENT_CAST_FEL_CANNON_BLAST,

    //Fel Eye Stalk
    EVENT_CAST_MIND_FLAY,

    SPELL_COSMETIC_GREEN_LIGHTNING_THICK    = 40057,
    SPELL_COSMETIC_FEL_IMPACT               = 40108,
};

struct trash_defenderAI : public ScriptedAI
{
    trash_defenderAI(Creature* creature) : ScriptedAI(creature)
    {
        SetActive(false);
    }

    void JustAppeared() override
    {
        me->SetFaction(FACTION_ENEMY);
        me->SetDisplayId(MODEL_IMAGE_OF_EMPTY);
        Events.ScheduleEvent(EVENT_TRANSFORM, 2s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override {};

    void JustExitedCombat() override
    {
        me->GetMotionMaster()->MoveTargetedHome();
    }

    virtual void ExecuteEvent(uint32 /*eventId*/) { }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && Events.Empty())
            return;

        Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = Events.ExecuteEvent())
        {
            ExecuteEvent(eventId);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }

    void SetActive(bool on)
    {
        if (on)
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
        else
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
    }

protected:
    EventMap Events;
    ObjectGuid CurrDemonGUID;
};

/*#####
# npc_fel_imp_defender
#####*/

enum FelImpDefender
{
    SPELL_FIREBALL          = 40554,
    SPELL_FEL_IMP_TRANSFORM = 40143,
};

struct npc_fel_imp_defender : public trash_defenderAI
{
    npc_fel_imp_defender(Creature* creature) : trash_defenderAI(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        trash_defenderAI::JustEngagedWith(who);
        Events.ScheduleEvent(EVENT_CAST_FIREBALL, 3s, 4s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TRANSFORM:
            SetActive(true);
            DoCastSelf(SPELL_FEL_IMP_TRANSFORM);
            AttackStart(me->FindNearestCreature(NPC_FELGUARD_DEGRADER, 200.0f));
            break;
        case EVENT_CAST_FIREBALL:
            if (me->GetEntry() == NPC_FEL_IMP_DEFENDER)
                DoCastVictim(SPELL_FIREBALL);
            Events.ScheduleEvent(EVENT_CAST_FIREBALL, 6s, 9s);
            break;
        default:
            break;
        }
    }
};

/*#####
# npc_felhound_defender
#####*/

enum FelHoundDefender
{
    SPELL_FELHOUND_TRANSFORM = 40462,
};

struct npc_felhound_defender : public trash_defenderAI
{
    npc_felhound_defender(Creature* creature) : trash_defenderAI(creature) { }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TRANSFORM:
            SetActive(true);
            DoCastSelf(SPELL_FELHOUND_TRANSFORM);
            AttackStart(me->FindNearestCreature(NPC_FELGUARD_DEGRADER, 200.0f));
            break;
        default:
            break;
        }
    }
};

/*#####
# npc_ganarg_underling
#####*/

enum GanargUnderling
{
    SPELL_BUILD_PORTABLE_FEL_CANNON = 40675,
    SPELL_HEALTH_FUNNEL             = 40671,
    SPELL_GAN_ARG_TRANSFORM         = 40069,
    SAY_ASSIST                      = 0,
    SAY_BUILD_FEL_CANNON            = 1
};

struct npc_ganarg_underling : public trash_defenderAI
{
    npc_ganarg_underling(Creature* creature) : trash_defenderAI(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        trash_defenderAI::JustEngagedWith(who);
        Events.ScheduleEvent(EVENT_CAST_BUILD_PORTABLE_FEL_CANNON, 12s, 18s);
        Events.ScheduleEvent(EVENT_CAST_HEALTH_FUNNEL, 25s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TRANSFORM:
            SetActive(true);
            DoCastSelf(SPELL_GAN_ARG_TRANSFORM);
            AttackStart(me->FindNearestCreature(NPC_DOOMGUARD_PUNISHER, 200.0f));
            break;
        case EVENT_CAST_HEALTH_FUNNEL:
            if (Creature* creature = me->FindNearestCreature(NPC_MO_ARG_TORMENTER, 200.0f))
            {
                Talk(SAY_ASSIST);
                DoCast(creature, SPELL_HEALTH_FUNNEL);
            }
            Events.ScheduleEvent(EVENT_CAST_HEALTH_FUNNEL, 20s);
            break;
        case EVENT_CAST_BUILD_PORTABLE_FEL_CANNON:
            DoCastSelf(SPELL_BUILD_PORTABLE_FEL_CANNON);
            break;
        default:
            break;
        }
    }
};

/*#####
# npc_moarg_tormenter
#####*/

enum MoargTormenter
{
    SPELL_ACID_GEYSER                = 40630,
    SPELL_MO_ARG_TORMENTER_TRANSFORM = 40479,
};

struct npc_moarg_tormenter : public trash_defenderAI
{
    npc_moarg_tormenter(Creature* creature) : trash_defenderAI(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        trash_defenderAI::JustEngagedWith(who);
        Events.ScheduleEvent(EVENT_CAST_ACID_GEYSER, 25s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TRANSFORM:
            SetActive(true);
            DoCastSelf(SPELL_MO_ARG_TORMENTER_TRANSFORM);
            AttackStart(me->FindNearestCreature(NPC_DOOMGUARD_PUNISHER, 200.0f));
            break;
        case EVENT_CAST_ACID_GEYSER:
            DoCastVictim(SPELL_ACID_GEYSER);
            Events.ScheduleEvent(EVENT_CAST_ACID_GEYSER, 20s);
            break;
        default:
            break;
        }
    }
};

/*#####
# npc_portable_fel_cannon
#####*/

enum PortableFelCannon
{
    SPELL_FEL_CANNON_BLAST              = 40672,
    SPELL_PORTABLE_FEL_CANNON_TRANSFORM = 40673,
};

struct npc_portable_fel_cannon : public trash_defenderAI
{
    npc_portable_fel_cannon(Creature* creature) : trash_defenderAI(creature) { }

    void JustAppeared() override
    {
        trash_defenderAI::JustAppeared();
        Events.ScheduleEvent(EVENT_CAST_FEL_CANNON_BLAST, 2s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TRANSFORM:
            SetActive(true);
            DoCastSelf(SPELL_PORTABLE_FEL_CANNON_TRANSFORM);
            break;
        case EVENT_CAST_FEL_CANNON_BLAST:
            DoCast(me->GetVictim(), SPELL_FEL_CANNON_BLAST);
            Events.ScheduleEvent(EVENT_CAST_FEL_CANNON_BLAST, 5s);
            break;
        default:
            break;
        }
    }
};

/*#####
# npc_fel_eye_stalk
#####*/

enum FelEyeStalk
{
    SPELL_MIND_FLAY           = 40842,
    SPELL_EYE_STALK_TRANSFORM = 40826,
};

struct npc_fel_eye_stalk : public trash_defenderAI
{
    npc_fel_eye_stalk(Creature* creature) : trash_defenderAI(creature) { }

    void JustAppeared() override
    {
        trash_defenderAI::JustAppeared();
        Events.ScheduleEvent(EVENT_CAST_MIND_FLAY, 2s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TRANSFORM:
            SetActive(true);
            DoCastSelf(SPELL_EYE_STALK_TRANSFORM);
            me->SetEntry(16236);
            break;
        case EVENT_CAST_MIND_FLAY:
            DoCast(me->GetVictim(), SPELL_MIND_FLAY);
            Events.ScheduleEvent(EVENT_CAST_MIND_FLAY, 13s);
            break;
        default:
            break;
        }
    }
};

// 40309 - Possess Demon
class spell_shartuuls_transporter_possess_demon : public SpellScript
{
    PrepareSpellScript(spell_shartuuls_transporter_possess_demon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POSSESS_DEMON });
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        if (Unit* target = GetHitUnit())
        {
            PreventHitDefaultEffect(effIndex);
            if (target->IsAlive())
                caster->CastSpell(target, SPELL_CHARM_NORTH_01);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shartuuls_transporter_possess_demon::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 40503 - Possession Transfer (Doom Punisher)
// 41962 - Possession Transfer (Shivan)
class spell_shartuuls_transporter_possession_transfer : public AuraScript
{
    PrepareAuraScript(spell_shartuuls_transporter_possession_transfer);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;
        Unit* caster = GetCaster();
        if (!caster)
            return;
        Creature* overseerShartuul = caster->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 200.0f);
        if (!overseerShartuul)
            return;
        Unit* target = caster->GetVictim(); //GetTargetApplication()->GetTarget();
        if (!target)
            return;
        Unit* charmer = target->GetCharmer();
        if (!charmer)
            return;
        uint32 prevCharm;
        uint32 currCharm;

        //Save the new demon controlled by the player
        ENSURE_AI(npc_overseer_shartuul, overseerShartuul->AI())->currPossessDemonGUID = caster->GetGUID();
        if (GetId() == SPELL_DOOMPUNISHER_POSSESSION_TRANSFER)
        {
            prevCharm = SPELL_CHARM_NORTH_01;
            currCharm = SPELL_CHARM_NORTH_02;
            overseerShartuul->AI()->DoAction(ACTION_START_DEMON_II_PHASE_I);
        }
        else //SPELL_SHIVAN_POSSESSION_TRANSFER
        {
            prevCharm = SPELL_CHARM_NORTH_02;
            currCharm = SPELL_CHARM_NORTH_03;
            overseerShartuul->AI()->DoAction(ACTION_START_DEMON_III_PHASE_I);
        }

        caster->ToCreature()->SetHomePosition(caster->GetPosition());

        //Swaping the demon
        charmer->RemoveAurasDueToSpell(prevCharm);
        target->RemoveAurasDueToSpell(prevCharm);
        if (target->IsCreature())
            target->KillSelf();
        charmer->CastSpell(caster, currCharm);
        caster->CombatStop();
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_shartuuls_transporter_possession_transfer::AfterRemove, EFFECT_2, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(spell_shartuuls_transporter_possession_transfer::OnApply, EFFECT_2, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 41593 - Aspect of the Flame
// 41594 - Aspect of the Ice
// 41595 - Aspect of the Shadow
enum Aspects
{
    MODEL_IMAGE_OF_SHIVAN_ASSASSIN       = 24787,  // Shivan Assassin
    MODEL_IMAGE_OF_SHIVAN_ASSASSIN_RED   = 24788,  // Shivan Assassin (Red)
    MODEL_IMAGE_OF_SHIVAN_ASSASSIN_BLUE  = 24799,  // Shivan Assassin (Blue)
    MODEL_IMAGE_OF_SHIVAN_ASSASSIN_BLACK = 24799,  // Shivan Assassin (Black)
};

//todo The Aspects themselves only change Shivan's appearance. Logic needs to be added that will change her skills as well
class spell_shartuuls_transporter_aspects : public SpellScript
{
    PrepareSpellScript(spell_shartuuls_transporter_aspects);

    void Transform()
    {
        Creature* caster = GetCaster()->ToCreature();

        caster->RemoveAurasDueToSpell(SPELL_ASPECT_OF_THE_FLAME);
        caster->RemoveAurasDueToSpell(SPELL_ASPECT_OF_THE_ICE);
        caster->RemoveAurasDueToSpell(SPELL_ASPECT_OF_THE_SHADOW);

        switch (GetSpellInfo()->Id)
        {
        case SPELL_ASPECT_OF_THE_FLAME:
            break;
        case SPELL_ASPECT_OF_THE_ICE:
            break;
        case SPELL_ASPECT_OF_THE_SHADOW:
            break;
        default:
            break;
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_shartuuls_transporter_aspects::Transform);
    }
};

enum DisruptionRay
{
    SPELL_SUMMON_STUN_ZONE_GRAPHIC_EW = 40776,
    SPELL_SUMMON_STUN_ZONE_GRAPHIC_NS = 40783,
    SPELL_STUN_ZONE                   = 40775,
    SPELL_STUN_ROPE                   = 40778,
    NPC_TRIGGER_STUN_FIELD            = 23312,
    NPC_TRIGGER_STUN_ROPE_DUMMY       = 23313,
};

// 40784 - Summon Stun Trap
class spell_shartuuls_transporter_summon_stun_trap : public SpellScript
{
    PrepareSpellScript(spell_shartuuls_transporter_summon_stun_trap);
    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitEffect(effIndex);
        if (Unit* target = GetCaster()->GetVictim())
        {
            if (Creature* middleStunField = target->SummonCreature(NPC_TRIGGER_STUN_FIELD, target->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 45s))
            {
                //Summons creatures that describe the boundary of a stun trap (East-West, North-South)
                middleStunField->CastSpell(middleStunField, SPELL_SUMMON_STUN_ZONE_GRAPHIC_EW);
                middleStunField->CastSpell(middleStunField, SPELL_SUMMON_STUN_ZONE_GRAPHIC_NS);
                if (!middleStunField->HasAura(SPELL_STUN_ZONE))
                    //Apply stun effect on summoned creatures
                    middleStunField->AI()->DoCastSelf(SPELL_STUN_ZONE);

                std::vector<Creature*> temp;
                middleStunField->GetCreatureListWithEntryInGrid(temp, NPC_TRIGGER_STUN_ROPE_DUMMY, 20.0f);
                for (uint8 i = 0; i < temp.size(); i += 2)
                {
                    if (!temp[i]->HasAura(SPELL_STUN_ROPE))
                        //Apply cosmetic effect on summoned creatures
                        temp[i]->AI()->DoCast(temp[i + 1], SPELL_STUN_ROPE);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_shartuuls_transporter_summon_stun_trap::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// 40565 - Consume Essence
class spell_shartuuls_transporter_consume_essence : public SpellScript
{
    PrepareSpellScript(spell_shartuuls_transporter_consume_essence);

    SpellCastResult CheckCast()
    {
        if (Unit* target = GetExplTargetUnit())
            if (target->GetEntry() == NPC_GAN_ARG_UNDERLING)
                return SPELL_CAST_OK;

        return SPELL_FAILED_BAD_TARGETS;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_shartuuls_transporter_consume_essence::CheckCast);
    }
};

//todo check without conditions
// 40675 - Build Portable Fel Cannon
class spell_shartuuls_transporter_build_portable_fel_cannon : public AuraScript
{
    PrepareAuraScript(spell_shartuuls_transporter_build_portable_fel_cannon);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;
        if (Creature* caster = GetCaster()->ToCreature())
        {
            caster->AI()->Talk(SAY_BUILD_FEL_CANNON);
            Position pos = caster->GetRandomPoint(caster->GetPosition(), 5.0f);
            caster->SummonCreature(NPC_PORTABLE_FEL_CANNON, pos, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5min);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_shartuuls_transporter_build_portable_fel_cannon::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//TODO FIX
// 40493 - Super Jump
class spell_shartuuls_transporter_super_jump : public SpellScript
{
    PrepareSpellScript(spell_shartuuls_transporter_super_jump);

    void HandleLeap(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Unit* caster = GetCaster();
        if (Unit* target = GetExplTargetUnit())
        {
            Position pos = target->GetPosition();
            caster->GetMotionMaster()->MoveJump(pos, 21, 16);
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_shartuuls_transporter_super_jump::HandleLeap, EFFECT_0, SPELL_EFFECT_LEAP_BACK);
    }
};

void AddSC_shartuul_event()
{
    RegisterCreatureAI(npc_overseer_shartuul);
    RegisterCreatureAI(npc_warp_gate_shield);
    RegisterCreatureAI(npc_shield_zapper);
    RegisterCreatureAI(npc_felguard_degrader);
    RegisterCreatureAI(boss_doomguard_punisher);
    RegisterCreatureAI(boss_shivan_assassin);
    RegisterCreatureAI(boss_eye_of_shartuul);
    RegisterCreatureAI(boss_dreadmaw);
    RegisterCreatureAI(boss_shartuul);
    RegisterCreatureAI(npc_fel_imp_defender);
    RegisterCreatureAI(npc_felhound_defender);
    RegisterCreatureAI(npc_ganarg_underling);
    RegisterCreatureAI(npc_moarg_tormenter);
    RegisterCreatureAI(npc_portable_fel_cannon);
    RegisterCreatureAI(npc_fel_eye_stalk);
    RegisterSpellScript(spell_shartuuls_transporter_possess_demon);
    RegisterSpellScript(spell_shartuuls_transporter_possession_transfer);
    RegisterSpellScript(spell_shartuuls_transporter_aspects);
    RegisterSpellScript(spell_shartuuls_transporter_summon_stun_trap);
    RegisterSpellScript(spell_shartuuls_transporter_consume_essence);
    RegisterSpellScript(spell_shartuuls_transporter_build_portable_fel_cannon);
    RegisterSpellScript(spell_shartuuls_transporter_super_jump);
}
