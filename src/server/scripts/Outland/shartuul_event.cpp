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
#include "Unit.h"

 /* ContentData: Legion Ring event (Shartuul's Transporter)
 new boss_doomguard_punisher;
 new boss_shivan_assassin;
 new boss_eye_of_shartuul;
 new boss_dreadmaw;
 new boss_shartuul;
 new npc_warp_gate_shield;
 new npc_felguard_degradeb;
 new npc_overseer_shartuul;
 new npc_shield_zapper;
 new npc_fel_imp_defender;
 new npc_felhound_defender;
 new npc_ganarg_underling;
 new npc_moarg_tormenter;
 new npc_portable_fel_cannon;
 new npc_fel_eye_stalk;
 RegisterSpellScript(spell_shartuuls_transporter_possess_demon);
 RegisterSpellScript(spell_shartuuls_transporter_aspects);
 RegisterSpellScript(spell_shartuuls_transporter_summon_stun_trap);
 RegisterSpellScript(spell_shartuuls_transporter_consume_essence);
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
    SPELL_FEL_CANNON_BLAST = 40672,
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
    NPC_TRIGGER_GREEN_MATTER         = 23059,
    NPC_TRIGGER_EREDAR_BREATH_TARGET = 23328,
    NPC_TRIGGER_EREDAR_PRE_GATE_BEAM = 23260,

    //Trash
    NPC_FEL_IMP_DEFENDER             = 23078,
    NPC_FELHOUND_DEFENDER            = 23173,
    NPC_GAN_ARG_UNDERLING            = 23199,
    NPC_MO_ARG_TORMENTER             = 23212,
    NPC_PORTABLE_FEL_CANNON          = 23278,
    NPC_FEL_EYE_STALK                = 23323
};


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

static Position const ShartuulSpawnPos = { 2671.42f, 7144.42f, 365.42f, 5.76889f };

//Position where Shartuul approaches before the start of the battle
static Position const ShartuulCombatPos = { 2694.21f, 7131.45f, 365.15f, 5.84f };

static Position const ForgeCampPos = { 2720.31f, 7117.68f, 367.30f, 4.29094f };

static Position const EredarBreathTargetSpawnPos = { 2671.42f, 7144.42f, 377.35f, 5.76889f };

static Position const ZapperTargetPos[4] =
{
    {2640.37f, 7089.21f, 380.35f, 0.00f},
    {2698.23f, 7184.25f, 380.35f, 0.00f},
    {2798.41f, 7135.72f, 380.35f, 0.00f},
    {2741.68f, 7046.69f, 380.35f, 0.00f}
};

//Positions for NPCs that emit lightning before the start of the event
static Position const ZapperPos[12] =
{
    {2740.54f, 7057.71f, 365.36f, 0.00f}, //first zapper target
    {2734.42f, 7055.62f, 365.36f, 0.00f},
    {2731.52f, 7064.95f, 364.46f, 0.00f},
    {2786.71f, 7143.98f, 365.48f, 0.00f}, //second
    {2777.67f, 7140.72f, 365.17f, 0.00f},
    {2782.77f, 7133.71f, 365.47f, 0.00f},
    {2704.49f, 7168.00f, 365.04f, 0.00f}, //third
    {2689.65f, 7165.04f, 364.51f, 0.00f},
    {2710.98f, 7166.74f, 364.57f, 0.00f},
    {2661.43f, 7077.41f, 365.27f, 0.00f}, //fourth
    {2651.76f, 7090.05f, 364.75f, 0.00f},
    {2652.65f, 7103.53f, 365.67f, 0.00f}
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
    {2761.23f, 7129.37f, 365.81f, 0.00f},
    {2704.05f, 7089.95f, 364.77f, 4.08f}
};

//TODO code style
//TODO check all dist 225f?
//
//TODO FIND SHARTUUL PORTAL GAMEOBJECT
//TODO SPELL_BUILD_PORTABLE_FEL_CANNON = 40675, //todo should be building a portable fel cannon (Make a separate spell script) //mb effect_1(2)
//TODO SPELL_METEOR = 26558, //todo find real
//TODO SPELL_DISRUPTION_RAY = 41550 - dont work right (aims the beam under himself anyway, must at the enemy)
//TODO EYE STALK METEOR
//TODO FIND REAL ANITMATION FOR STUN FIELD
//TODO FIX 40493 NPC_DOOMGUARD_PUNISHER spell doesnt work (mb conditionsTypeOfReference 29)
//TODO FIX ACTION BAR NPC_DOOMGUARD_PUNISHER and NPC_SHIVAN AFTER POCCESS
//TODO FIX DOUBLE ZAP IN JustAppeared trash_defender
//TODO ADD FEL CANNON AFTER OK CAST SPELL BUILD

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
    EVENT_SPAWN_MOB_DEMON_I_WAVE_I      = 1,
    EVENT_SPAWN_MOB_DEMON_II_WAVE_I,
    EVENT_SPAWN_MOB_DEMON_II_WAVE_II,
    EVENT_SPAWN_MOB_DEMON_II_WAVE_III,
    EVENT_SPAWN_MOB_DEMON_II_WAVE_IV,
    EVENT_SPAWN_FEL_EYE_STALK,

    EVENT_SPAWN_EYE_OF_SHARTUUL,
    EVENT_SPAWN_DREADMAW,
    EVENT_SPAWN_SHIVAN_ASSASSIN,

    EVENT_SPAWN_MOB_WAVE,
    EVENT_CLOSE_SHARTUULS_GATE,

    SAY_THREAT                          = 0,
    SAY_EVENT_START,
    SAY_FIRST_HAMMER_THROWN,
    SAY_SHIVAN_IN_PROGRESS,
    SAY_SHIVAN_DONE,
    SAY_DREADMAW_DONE,
    SAY_SHARTUUL_DONE,

    SPELL_COSMETIC_GREEN_MATTER         = 40071,
    SPELL_COSMETIC_EREDAR_PRE_GATE_BEAM = 40605,
    SPELL_COSMETIC_SHIVAN_STASIS        = 40507,
    SPELL_COSMETIC_EREDAR_LIGHTNING     = 40646,
    SPELL_COSMETIC_METEOR               = 26558, //todo find real (Shartuul summons a meteor from his hand, not the sky)

    POINT_SHARTUUL_COMBAT               = 0
};

class npc_overseer_shartuul : public CreatureScript
{
public:
    npc_overseer_shartuul() : CreatureScript("npc_overseer_shartuul") { }

    struct npc_overseer_shartuulAI : public ScriptedAI
    {
        npc_overseer_shartuulAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            Initialaize();
        }

        void Initialaize()
        {
            currMoWave = 0;
            currDemonState = 0;
            _knockBackDist = 5.0f;
            _knockBackX = 0;
            _knockBackY = 0;
            _knockBackOrientation = 0;

            _eredarGateBeamGUIDs.clear();
            _wreckageGUIDs.clear();
            _felguardDegraderGUID.Clear();
            _doomPunisherGUID.Clear();
            _eredarBreathTargeGUID.Clear();
            currPossessDemonGUID.Clear();
        }

        void Reset() override
        {
            summons.DespawnAll();
            SummonStartEventNPC();
            SetGreenMatter(false);
            events.Reset();
            Initialaize();
        }

        void JustAppeared() override
        {
        }

        uint8 currMoWave;
        int8 currDemonState;
        EventMap events;
        SummonList summons;
        ObjectGuid currPossessDemonGUID;

        void JustSummoned(Creature* summoned) override
        {
            summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void DoAction(int32 action) override
        {
            currDemonState = action;
            currMoWave = 0;

            events.ScheduleEvent(EVENT_SPAWN_MOB_WAVE, 8s);
            switch (action)
            {
            case ACTION_START_DEMON_I_PHASE_I: //Trigger the event, activate the barrier
                Talk(SAY_EVENT_START);
                SummonShieldZappers(false);
                SetGreenMatter(true);
                SetBoundary(FieldBoundary);
                break;
            case ACTION_START_DEMON_I_PHASE_II: //Activate Doom Punisher, remove trash mobs
                if (Creature* doomPunisher = me->FindNearestCreature(NPC_DOOMGUARD_PUNISHER, 100.0f))
                {
                    summons.DespawnEntry(NPC_FELHOUND_DEFENDER);
                    summons.DespawnEntry(NPC_FEL_IMP_DEFENDER);
                    doomPunisher->AI()->DoAction(ACTION_START_DEMON_I_PHASE_II);
                }
                IgniteShieldWreckage(true);
                events.Reset();
                break;
            case ACTION_START_DEMON_II_PHASE_I: //Summon Shivan Assassin
                events.ScheduleEvent(EVENT_SPAWN_SHIVAN_ASSASSIN, 12s);
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
                OpenShartuulsGate(true);
                events.ScheduleEvent(EVENT_CLOSE_SHARTUULS_GATE, 10s);
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
                    shartuul->CastSpell(me, SPELL_COSMETIC_METEOR);
                    shartuul->GetMotionMaster()->MovePoint(POINT_SHARTUUL_COMBAT, ShartuulCombatPos);
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
            CheckEventFail();

            if (events.Empty())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    //!Wave handler
                case EVENT_SPAWN_MOB_WAVE:
                    Talk(SAY_THREAT);
                    switch (currDemonState)
                    {
                    case ACTION_START_DEMON_I_PHASE_I:
                        events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_I_WAVE_I, 1s, 4s);
                        events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_I_WAVE_I, 120s); //!x2 mobs after 120s
                        break;
                    case ACTION_START_DEMON_II_PHASE_I:
                        events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_I, 1s);
                        events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_II, 24s);
                        events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_III, 44s);
                        break;
                    default:
                        break;
                    }
                    break;
                    //!Bosses spawn events (INTRO PHASE)
                case EVENT_SPAWN_SHIVAN_ASSASSIN:
                    if (Creature* creature = me->SummonCreature(NPC_SHIVAN_ASSASSIN, ForgeCampPos))
                    {
                        DoCast(creature, SPELL_COSMETIC_SHIVAN_STASIS);
                        _shivanAssassinGUID = creature->GetGUID();
                    }
                    break;
                case EVENT_SPAWN_EYE_OF_SHARTUUL:
                    if (Creature* eyeOfShartuul = me->SummonCreature(NPC_EYE_OF_SHARTUUL, EyeOfShartuulSpawnPos))
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
                    if (Creature* dreadMaw = me->SummonCreature(NPC_DREADMAW, DreadmawSpawnPos))
                    {
                        if (_shartuulGUID)
                        {
                            Creature* shartuul = ObjectAccessor::GetCreature(*me, _shartuulGUID);
                            shartuul->SetFacingTo(shartuul->GetAbsoluteAngle(dreadMaw));
                            shartuul->CastSpell(dreadMaw, SPELL_COSMETIC_EREDAR_LIGHTNING);
                        }
                    }
                    break;
                    //!Mob Waves
                case EVENT_SPAWN_MOB_DEMON_I_WAVE_I:
                    me->SummonCreature(NPC_FEL_IMP_DEFENDER, me->GetRandomPoint(ForgeCampPos, 50.0f), TEMPSUMMON_DEAD_DESPAWN);
                    me->SummonCreature(NPC_FELHOUND_DEFENDER, me->GetRandomPoint(ForgeCampPos, 50.0f), TEMPSUMMON_DEAD_DESPAWN);
                    me->SummonCreature(NPC_FELHOUND_DEFENDER, me->GetRandomPoint(ForgeCampPos, 50.0f), TEMPSUMMON_DEAD_DESPAWN);
                    events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_I_WAVE_I, 7s, 14s);
                    break;
                case EVENT_SPAWN_MOB_DEMON_II_WAVE_I:
                case EVENT_SPAWN_MOB_DEMON_II_WAVE_II:
                    for (uint8 i = 0; i < 2; i++)
                        me->SummonCreature(NPC_GAN_ARG_UNDERLING, me->GetRandomPoint(ForgeCampPos, 50.0f), TEMPSUMMON_DEAD_DESPAWN);
                    break;
                case EVENT_SPAWN_MOB_DEMON_II_WAVE_III:
                    events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_I, 1s);
                    events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_II, 4s);
                    events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_IV, 35s);
                    break;
                case EVENT_SPAWN_MOB_DEMON_II_WAVE_IV: //Mo Wave
                {
                    if (currMoWave >= 3) //Checking the number of summoned Mo'arg the Tormentor
                    {
                        DoAction(ACTION_START_DEMON_II_PHASE_II);
                        break;
                    }
                    if (currMoWave == 2) //Summon the last two Gan'arg
                        events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_II, 60s);
                    me->SummonCreature(NPC_MO_ARG_TORMENTER, MoSpawnPos[currMoWave], TEMPSUMMON_DEAD_DESPAWN);
                    for (uint8 i = 0; i < 4; ++i) //!Summon Gan'arg near Mo'arg
                        FindPosAndSpawnMoUnderling(i, MoSpawnPos[currMoWave]);
                    for (uint8 i = 0; i < 3; ++i) //!Summon Gan'arg in a random location
                        me->SummonCreature(NPC_GAN_ARG_UNDERLING, me->GetRandomPoint(ForgeCampPos, 50.0f), TEMPSUMMON_DEAD_DESPAWN);
                    events.ScheduleEvent(EVENT_SPAWN_MOB_DEMON_II_WAVE_IV, 80s);
                    ++currMoWave;
                }
                break;
                case EVENT_CLOSE_SHARTUULS_GATE:
                    OpenShartuulsGate(false);
                    events.ScheduleEvent(EVENT_SPAWN_EYE_OF_SHARTUUL, 7s);  //Summon Eye of Shartuul
                    break;
                case EVENT_SPAWN_FEL_EYE_STALK:
                    SpawnEyeStalk();
                    break;
                default:
                    break;
                }
            }
        }

        void SummonStartEventNPC()
        {
            me->SummonCreature(NPC_TRIGGER_WARP_GATE_SHIELD, WarpGateShieldSpawnPos, TEMPSUMMON_DEAD_DESPAWN);
            me->SummonCreature(NPC_FELGUARD_DEGRADER, me->GetRandomPoint(ForgeCampPos, 30.0f), TEMPSUMMON_DEAD_DESPAWN);
            me->SummonCreature(NPC_DOOMGUARD_PUNISHER, ForgeCampPos, TEMPSUMMON_DEAD_DESPAWN);
            SummonShieldZappers(true);
        }

        void CheckEventFail()
        {
            if (Creature* creature = ObjectAccessor::GetCreature(*me, currPossessDemonGUID))
                // If the creature is not alive, trigger "event" failure
                if (!creature->IsAlive())
                    DoAction(ACTION_EVENT_DONE_OR_FAIL);
        };

        void CheckBoundary()
        {
            if (Creature* creature = ObjectAccessor::GetCreature(*me, currPossessDemonGUID))
                if (!IsInBoundary(creature))
                    // If the creature is not within the boundary, compute the knockback.
                    ComputeKnockback(creature);
        };

        // This function turns the barrier on or off.
        void SetGreenMatter(bool on)
        {
            std::vector<Creature*> temp;
            me->GetCreatureListWithEntryInGrid(temp, NPC_TRIGGER_GREEN_MATTER);

            // If the green matter is to be turned on, cast the spell on the creatures in a specific pattern.
            if (on)
            {
                //The way the npc's are connected was obtained by experience and can break if the npc's are swapped.
                if (temp.size() == 4)
                {
                    temp[0]->CastSpell(temp[2], SPELL_COSMETIC_GREEN_MATTER);
                    temp[1]->CastSpell(temp[0], SPELL_COSMETIC_GREEN_MATTER);
                    temp[2]->CastSpell(temp[3], SPELL_COSMETIC_GREEN_MATTER);
                    temp[3]->CastSpell(temp[1], SPELL_COSMETIC_GREEN_MATTER);
                }
            }
            //If the green matter is to be turned off, remove the green matter auras from all creatures.
            else
            {
                for (uint8 i = 0; i < temp.size(); ++i)
                    temp[i]->RemoveAurasDueToSpell(SPELL_COSMETIC_GREEN_MATTER);
            }
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
            if (currMoWave == 2)
            {
                //Calculate position by line
                static const std::vector<std::pair<int, int>> offsets = { {-20, 12}, {-10, 10}, {10, -10}, {20, -12} };
                if (i < offsets.size())
                {
                    moPos.m_positionX += offsets[i].first;
                    moPos.m_positionY += offsets[i].second;
                }
            }
            else
            {
                //Calculate position by square
                static const std::vector<std::pair<int, int>> offsets = { {-10, -10}, {10, -10}, {-10, 10}, {10, 10} };
                if (i < offsets.size())
                {
                    moPos.m_positionX += offsets[i].first;
                    moPos.m_positionY += offsets[i].second;
                }
            }
            me->SummonCreature(NPC_GAN_ARG_UNDERLING, moPos, TEMPSUMMON_DEAD_DESPAWN);
        }

        void OpenShartuulsGate(bool on)
        {
            // If the gate is to be opened, summon the necessary creatures and cast the pre gate beam
            if (on)
            {
                if (Creature* eredarBreathTarget = me->SummonCreature(NPC_TRIGGER_EREDAR_BREATH_TARGET, EredarBreathTargetSpawnPos, TEMPSUMMON_TIMED_DESPAWN, 30s))
                {
                    _eredarBreathTargeGUID = eredarBreathTarget->GetGUID();
                    for (uint8 i = 0; i < 2; ++i)
                        if (Creature* eredarBeam = me->SummonCreature(NPC_TRIGGER_EREDAR_PRE_GATE_BEAM, EredarBeamSpawnPos[i], TEMPSUMMON_TIMED_DESPAWN, 30s))
                        {
                            _eredarGateBeamGUIDs.push_back(eredarBeam->GetGUID());
                            eredarBeam->CastSpell(eredarBreathTarget, SPELL_COSMETIC_EREDAR_PRE_GATE_BEAM);
                        }
                }
            }
            // If the gate is to be closed, remove the pre gate beam from the eredarBreathTarge. Summon Shartuul
            else
            {
                if (Creature* eredarBreathTarge = ObjectAccessor::GetCreature(*me, _eredarBreathTargeGUID))
                    eredarBreathTarge->RemoveAurasDueToSpell(SPELL_COSMETIC_EREDAR_PRE_GATE_BEAM);
                _shartuulGUID = me->SummonCreature(NPC_SHARTUUL, ShartuulSpawnPos, TEMPSUMMON_DEAD_DESPAWN)->GetGUID();
            }
        }

        void SpawnEyeStalk()
        {
            for (uint8 i = 0; i < 16; ++i)
            {
                //Cast a spell to add a meteor effect, then summon the eye stalk
                me->SummonCreature(NPC_FEL_EYE_STALK, me->GetRandomPoint(ForgeCampPos, 50.0f));
                //if (Creature* creature = me->SummonCreature(NPC_FEL_EYE_STALK, me->GetRandomPoint(ForgeCampPos, 50.0f)))
                //{
                    //TODO SPELL_FEL_CANNON_BLAST or a spell with the same animation should be used here.
                    //TODO But SpellCastResult returns SPELL_FAILED_BAD_TARGETS.
                    //DoCast(creature, SPELL_FEL_CANNON_BLAST);
               // }
            }
        }

        void SummonShieldZappers(bool on)
        {
            if (on) //Summon shield zappers at the columns
            {
                for (uint8 i = 0; i < 4; ++i)
                    me->SummonCreature(NPC_TRIGGER_EREDAR_PRE_GATE_BEAM, ZapperTargetPos[i], TEMPSUMMON_MANUAL_DESPAWN);
                for (uint8 i = 0; i < 12; ++i)
                    me->SummonCreature(NPC_TRIGGER_SHIELD_ZAPPER, ZapperPos[i], TEMPSUMMON_MANUAL_DESPAWN);
            }
            else //Despawn all shield zappers at the columns
            {
                summons.DespawnEntry(NPC_TRIGGER_EREDAR_PRE_GATE_BEAM);
                summons.DespawnEntry(NPC_TRIGGER_SHIELD_ZAPPER);
            }
        }

    private:
        float _knockBackDist;
        float _knockBackX, _knockBackY;
        float _knockBackOrientation;
        GuidVector _eredarGateBeamGUIDs;
        GuidVector _wreckageGUIDs;
        ObjectGuid _felguardDegraderGUID;
        ObjectGuid _doomPunisherGUID;
        ObjectGuid _shivanAssassinGUID;
        ObjectGuid _shartuulGUID;
        ObjectGuid _eredarBreathTargeGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_overseer_shartuulAI(creature);
    }
};

/*#####
# npc_warp_gate_shield
# This NPC monitor hits to the shield and explosion of the shield
#####*/

enum WarpGateShield
{
    EVENT_DEFENSE_BEAM              = 0,

    SPELL_COSMETIC_SHIELD_LIGHTNING = 40158,
    SPELL_COSMETIC_SHIELD_EXPLODE   = 41918,
    SPELL_SHIELD_DEFENSE_BEAM       = 40380,
    SPELL_SMASH_SHIELD              = 40222,
};

class npc_warp_gate_shield : public CreatureScript
{
public:
    npc_warp_gate_shield() : CreatureScript("npc_warp_gate_shield") { }

    struct npc_warp_gate_shieldAI : public ScriptedAI
    {
        npc_warp_gate_shieldAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _shiledHit = 0;
            _events.Reset();
            DoCastSelf(SPELL_COSMETIC_SHIELD_LIGHTNING);
        }

        void JustAppeared() override
        {
            if (Creature* overseerShartuul = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 250.0f))
                _overseerShartuulGUID = overseerShartuul->GetGUID();
            _events.ScheduleEvent(EVENT_DEFENSE_BEAM, 1min);
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
                    _events.Reset();
                    ShieldExplode();
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
                default:
                    break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
        }

        void ShieldExplode()
        {
            me->RemoveAura(SPELL_COSMETIC_SHIELD_LIGHTNING);

            //Inform Overseer that the shield has exploded.
            if (Creature* overseerShartuul = ObjectAccessor::GetCreature(*me, _overseerShartuulGUID))
                overseerShartuul->AI()->DoAction(ACTION_START_DEMON_I_PHASE_II);
            if (Creature* creature = me->SummonCreature(NPC_TRIGGER_GREEN_MATTER, ForgeCampPos, TEMPSUMMON_TIMED_DESPAWN, 5s))
                creature->AI()->DoCastSelf(SPELL_COSMETIC_SHIELD_EXPLODE);
        }

    private:
        EventMap _events;
        uint8 _shiledHit;
        ObjectGuid _overseerShartuulGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_warp_gate_shieldAI(creature);
    }
};

/*#####
# npc_shield_zapper
# This npc controls lightning at the columns and at the portal
#####*/

enum ShieldZapper
{
    EVENT_CAST_GREEN_LIGHTNING     = 1,
    SPELL_COSMETIC_GREEN_LIGHTNING = 40146
};

class npc_shield_zapper : public CreatureScript
{
public:
    npc_shield_zapper() : CreatureScript("npc_shield_zapper") { }

    struct npc_shield_zapperAI : public ScriptedAI
    {
        npc_shield_zapperAI(Creature* creature) : ScriptedAI(creature)
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
                    _events.ScheduleEvent(EVENT_CAST_GREEN_LIGHTNING, 5s, 7s);
                    //Strikes bosses or Zapp Target
                    if (Creature* gateShield = me->FindNearestCreature(NPC_DOOMGUARD_PUNISHER, 14.0f))
                    {
                        DoCast(gateShield, SPELL_COSMETIC_GREEN_LIGHTNING);
                        return;
                    }
                    if (Creature* shivanAssassin = me->FindNearestCreature(NPC_SHIVAN_ASSASSIN, 14.0f))
                    {
                        DoCast(shivanAssassin, SPELL_COSMETIC_GREEN_LIGHTNING);
                        return;
                    }
                    if (Creature* target = me->FindNearestCreature(NPC_TRIGGER_EREDAR_PRE_GATE_BEAM, 35.0f))
                        DoCast(target, SPELL_COSMETIC_GREEN_LIGHTNING);
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shield_zapperAI(creature);
    }
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
    EVENT_FINISHED_CAST_POSSESSION_TRANSFER,

    SPELL_DOOMPUNISHER_POSSESSION_TRANSFER  = 40503,
    SPELL_SHIVAN_POSSESSION_TRANSFER        = 41962
};

struct possess_demonAI : public WorldBossAI
{
    possess_demonAI(Creature* creature) : WorldBossAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        //DoCastSelf(/*shadow spell*/);
        SetActive(false);
    }

    void Reset() override
    {
        _Reset();
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

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;
            me->CastStop();
            events.Reset();
            _lastDemon = attacker->GetGUID();

            //Possess the demon
            if (me->GetEntry() == NPC_SHIVAN_ASSASSIN)
                DoCastVictim(SPELL_SHIVAN_POSSESSION_TRANSFER);
            else
                DoCastVictim(SPELL_DOOMPUNISHER_POSSESSION_TRANSFER);
        }
    }

    void OnSpellCast(const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_SHIVAN_POSSESSION_TRANSFER || spell->Id == SPELL_DOOMPUNISHER_POSSESSION_TRANSFER)
            events.ScheduleEvent(EVENT_FINISHED_CAST_POSSESSION_TRANSFER, 5s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            //todo I wanted to convert this into a spell script, but I can't possess the demon after the end of the cast.
            //todo AfterCast is called immediately
        case EVENT_FINISHED_CAST_POSSESSION_TRANSFER:
            if (Creature* creature = ObjectAccessor::GetCreature(*me, _lastDemon))
            {
                if (Player* player = creature->GetCharmer()->ToPlayer())
                {
                    if (Creature* overseerShartuul = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 200.0f))
                    {
                        //This is to check if the current demon the player is controlling is still alive
                        ENSURE_AI(npc_overseer_shartuul::npc_overseer_shartuulAI, overseerShartuul->AI())->currPossessDemonGUID = me->GetGUID();
                        if (me->GetEntry() == NPC_SHIVAN_ASSASSIN)
                            overseerShartuul->AI()->DoAction(ACTION_START_DEMON_III_PHASE_I);
                        else
                            overseerShartuul->AI()->DoAction(ACTION_START_DEMON_II_PHASE_I);
                        //Replacing the demon
                        creature->KillSelf();
                        player->CastSpell(me, 530);
                        me->SetFaction(FACTION_ENEMY);
                    }
                }
            }
            break;
        default:
            break;
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
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
        else
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
    }

private:
    ObjectGuid _lastDemon;
};

/*#####
# npc_felguard_degradeb - first possessed demon
#####*/

class npc_felguard_degradeb : public CreatureScript
{
public:
    npc_felguard_degradeb() : CreatureScript("npc_felguard_degradeb") { }

    struct npc_felguard_degradebAI : public ScriptedAI
    {
        npc_felguard_degradebAI(Creature* creature) : ScriptedAI(creature) { }

        void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
        {
            Player* playerCaster = caster->ToPlayer();
            if (!playerCaster)
                return;

            if (spellInfo->Id == SPELL_POSSESS_DEMON)
            {
                if (Creature* overseerShartuul = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 250.0f))
                {
                    ENSURE_AI(npc_overseer_shartuul::npc_overseer_shartuulAI, overseerShartuul->AI())->currPossessDemonGUID = me->GetGUID();
                    overseerShartuul->AI()->DoAction(ACTION_START_DEMON_I_PHASE_I);
                    me->SetFaction(FACTION_ENEMY);
                }
            }
            if (spellInfo->Id == SPELL_DOOMPUNISHER_POSSESSION_TRANSFER)
                me->CastStop();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_felguard_degradebAI(creature);
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

class boss_doomguard_punisher : public CreatureScript
{
public:
    boss_doomguard_punisher() : CreatureScript("boss_doomguard_punisher") { }

    struct boss_doomguard_punisherAI : public possess_demonAI
    {
        boss_doomguard_punisherAI(Creature* creature) : possess_demonAI(creature) { }

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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_doomguard_punisherAI(creature);
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

class boss_shivan_assassin : public CreatureScript
{
public:
    boss_shivan_assassin() : CreatureScript("boss_shivan_assassin") { }
    struct boss_shivan_assassinAI : public possess_demonAI
    {
        boss_shivan_assassinAI(Creature* creature) : possess_demonAI(creature) { }

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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_shivan_assassinAI(creature);
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
    EVENT_CAST_DARK_GLARE      = 0,
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

class boss_eye_of_shartuul : public CreatureScript
{
public:
    boss_eye_of_shartuul() : CreatureScript("boss_eye_of_shartuul") { }

    struct boss_eye_of_shartuulAI : public WorldBossAI
    {
        boss_eye_of_shartuulAI(Creature* creature) : WorldBossAI(creature) { }

        void JustAppeared() override
        {
            events.ScheduleEvent(EVENT_CAST_TRANSFORM, 5s);
            me->SetDisplayId(MODEL_IMAGE_OF_EMPTY);
        }

        void JustEngagedWith(Unit* who) override
        {
            AttackStart(who);
            events.ScheduleEvent(EVENT_CAST_DARK_GLARE, 25s);
            events.ScheduleEvent(EVENT_CAST_DISRUPTION_RAY, 2s);
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
                    me->SetFaction(FACTION_MONSTER_2);
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

    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_eye_of_shartuulAI(creature);
    }
};

/*#####
# boss_dreadmaw
#####*/

enum Dreadmaw
{
    EVENT_CAST_GROWTH            = 2,
    EVENT_CAST_LACERATING_BITE,
    EVENT_CAST_RAMPAGING_CHARGE,
    EVENT_CAST_WAR_STOMP,
    SPELL_GROWTH                 = 41953,
    SPELL_LACERATING_BITE        = 41940,
    SPELL_RAMPAGING_CHARGE       = 41939,
    SPELL_WAR_STOMP              = 35238,
    SPELL_WRATH_HOUND_TRANSFORM  = 40648,
};

class boss_dreadmaw : public CreatureScript
{
public:
    boss_dreadmaw() : CreatureScript("boss_dreadmaw") { }

    struct boss_dreadmawAI : public WorldBossAI
    {
        boss_dreadmawAI(Creature* creature) : WorldBossAI(creature) { }

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
                    me->SetFaction(FACTION_MONSTER_2);
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

    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_dreadmawAI(creature);
    }
};
/*#####
# boss_shartuul
#####*/

enum Shartuul
{
    SAY_AGRO                        = 0,
    SAY_INCINERATE,
    EVENT_LIGHTNING_EYE_OF_SHARTUUL = NPC_EYE_OF_SHARTUUL,
    EVENT_LIGHTNING_DREADMAW        = NPC_DREADMAW,
    EVENT_CAST_IMMOLATE             = 10,
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

class boss_shartuul : public CreatureScript
{
public:
    boss_shartuul() : CreatureScript("boss_shartuul") { }

    struct boss_shartuulAI : public WorldBossAI
    {
        boss_shartuulAI(Creature* creature) : WorldBossAI(creature) { }

        void JustAppeared() override
        {
            //DoCastSelf(/*shadow spell*/);
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
                    SummonList& summons = ENSURE_AI(npc_overseer_shartuul::npc_overseer_shartuulAI, creature->AI())->summons;
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
                    if (Creature* creature = me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 200.0f))
                        DoCast(creature, SPELL_COSMETIC_METEOR);
                    SpawnEyeStalk();
                    events.ScheduleEvent(EVENT_CAST_METEOR, 8s, 12s);
                    break;
                case EVENT_CAST_TRANSFORM:
                    SetActive(true);
                    Talk(SAY_AGRO);
                    //me->RemoveAurasDueToSpell(/*shadow spell*/);
                    me->SetFaction(FACTION_MONSTER_2);
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

        //todo Should be the same mechanics as Overseer, only Eye Stalk should be summoned near the player
        void SpawnEyeStalk()
        {
            for (uint8 i = 0; i < 6; ++i)
            {
                Position pos = me->GetRandomPoint(me->GetVictim()->GetPosition(), 10.0f);

                //Checking to make sure Eye Stalk is not summoned behind a barrier
                if (!pos.IsWithinBox(ForgeCampPos, 20.0f, 20.0f, 110.0f))
                    continue;
                if (Creature* creature = me->SummonCreature(NPC_FEL_EYE_STALK, pos))
                {
                    //me->CastSpell(creature, /*mini meteor*/);  SPELL_FEL_CANNON_BLAST = 40672,
                }
            }
        }

        void SetActive(bool on)
        {
            if (on)
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
            else
                me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_shartuulAI(creature);
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
    EVENT_CASTED_BUILD_PORTABLE_FEL_CANNON,

    //Mo'arg Tormenter
    EVENT_CAST_ACID_GEYSER,

    //Portable Fel Cannon
    EVENT_CAST_FEL_CANNON_BLAST,

    //Fel Eye Stalk
    EVENT_IGNITE,
    EVENT_CAST_MIND_FLAY,

    SPELL_COSMETIC_GREEN_LIGHTNING_THICK    = 40057,
    SPELL_COSMETIC_FEL_IMPACT               = 40108,
};

struct trash_defenderAI : public ScriptedAI
{
    trash_defenderAI(Creature* creature) : ScriptedAI(creature)
    {
        //SetActive(false);
        //me->SetInstantCast(true);
    }

    void JustAppeared() override
    {
        me->SetFaction(FACTION_ENEMY);
        const uint32 entry = me->GetEntry();
        if (entry != NPC_PORTABLE_FEL_CANNON && entry != NPC_FEL_EYE_STALK)
        {
            //The effect of being struck by green lightning, before a npc appears
            DoCastSelf(SPELL_COSMETIC_FEL_IMPACT);
            me->CastSpell(me->FindNearestCreature(NPC_OVERSEER_SHARTUUL, 60.0f), SPELL_COSMETIC_GREEN_LIGHTNING_THICK);
        }
        me->SetDisplayId(MODEL_IMAGE_OF_EMPTY);
        Events.ScheduleEvent(EVENT_TRANSFORM, 4s);
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

class npc_fel_imp_defender : public CreatureScript
{
public:
    npc_fel_imp_defender() : CreatureScript("npc_fel_imp_defender") { }

    struct npc_fel_imp_defenderAI : public trash_defenderAI
    {
        npc_fel_imp_defenderAI(Creature* creature) : trash_defenderAI(creature) { }

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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fel_imp_defenderAI(creature);
    }
};

/*#####
# npc_felhound_defender
#####*/

enum FelHoundDefender
{
    SPELL_FELHOUND_TRANSFORM = 40462,
};

class npc_felhound_defender : public CreatureScript
{
public:
    npc_felhound_defender() : CreatureScript("npc_felhound_defender") { }

    struct npc_felhound_defenderAI : public trash_defenderAI
    {
        npc_felhound_defenderAI(Creature* creature) : trash_defenderAI(creature) { }

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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_felhound_defenderAI(creature);
    }
};

/*#####
# npc_ganarg_underling
#####*/

enum GanargUnderling
{
    //todo I can't create a portable fel cannon exactly after a completed cast. AfterCast, AfterHit are called immediately.
    SPELL_BUILD_PORTABLE_FEL_CANNON = 40675,

    SPELL_HEALTH_FUNNEL             = 40671, //todo This spell can only be used on MoargTormenter
    SPELL_GAN_ARG_TRANSFORM         = 40069,

    SAY_ASSIST                      = 0,
    SAY_BUILD_FEL_CANNON            = 1
};

class npc_ganarg_underling : public CreatureScript
{
public:
    npc_ganarg_underling() : CreatureScript("npc_ganarg_underling") { }

    struct npc_ganarg_underlingAI : public trash_defenderAI
    {
        npc_ganarg_underlingAI(Creature* creature) : trash_defenderAI(creature) { }

        void JustEngagedWith(Unit* who) override
        {
            trash_defenderAI::JustEngagedWith(who);
            Events.ScheduleEvent(EVENT_CAST_BUILD_PORTABLE_FEL_CANNON, 15s);
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
                Events.ScheduleEvent(EVENT_CASTED_BUILD_PORTABLE_FEL_CANNON, 4s);
                DoCastVictim(SPELL_BUILD_PORTABLE_FEL_CANNON);
                break;
            case EVENT_CASTED_BUILD_PORTABLE_FEL_CANNON:  //todo replace with spell script (SPELL_BUILD_PORTABLE_FEL_CANNON)
            {
                Talk(SAY_BUILD_FEL_CANNON);
                Position pos = me->GetRandomPoint(me->GetPosition(), 5.0f);
                if (pos.IsWithinBox(ForgeCampPos, 20.0f, 20.0f, 110.0f))
                    me->SummonCreature(NPC_PORTABLE_FEL_CANNON, me->GetRandomPoint(me->GetPosition(), 5.0f), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5min);
            }
            break;
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ganarg_underlingAI(creature);
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

class npc_moarg_tormenter : public CreatureScript
{
public:
    npc_moarg_tormenter() : CreatureScript("npc_moarg_tormenter") { }

    struct npc_moarg_tormenterAI : public trash_defenderAI
    {
        npc_moarg_tormenterAI(Creature* creature) : trash_defenderAI(creature) { }

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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_moarg_tormenterAI(creature);
    }
};

/*#####
# npc_portable_fel_cannon
#####*/

enum PortableFelCannon
{
    SPELL_PORTABLE_FEL_CANNON_TRANSFORM = 40673,
};

class npc_portable_fel_cannon : public CreatureScript
{
public:
    npc_portable_fel_cannon() : CreatureScript("npc_portable_fel_cannon") { }

    struct npc_portable_fel_cannonAI : public trash_defenderAI
    {
        npc_portable_fel_cannonAI(Creature* creature) : trash_defenderAI(creature) { }

        void JustEngagedWith(Unit* who) override
        {
            trash_defenderAI::JustEngagedWith(who);
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
                DoCast(me->FindNearestCreature(NPC_DOOMGUARD_PUNISHER, 50.0f), SPELL_FEL_CANNON_BLAST);
                Events.ScheduleEvent(EVENT_CAST_FEL_CANNON_BLAST, 5s);
                break;
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_portable_fel_cannonAI(creature);
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

class npc_fel_eye_stalk : public CreatureScript
{
public:
    npc_fel_eye_stalk() : CreatureScript("npc_fel_eye_stalk") { }

    struct npc_fel_eye_stalkAI : public trash_defenderAI
    {
        npc_fel_eye_stalkAI(Creature* creature) : trash_defenderAI(creature) { }

        void JustAppeared() override
        {
            trash_defenderAI::JustAppeared();
            Events.ScheduleEvent(SPELL_MIND_FLAY, 2s);
        }

        void JustEngagedWith(Unit* who) override
        {
            trash_defenderAI::JustEngagedWith(who);
            Events.ScheduleEvent(SPELL_MIND_FLAY, 2s);
        }
        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
            case EVENT_IGNITE:
            {
                // Summon a game object for the fire effect
                QuaternionData rotation = QuaternionData::fromEulerAnglesZYX(me->GetPositionZ(), 0.f, 0.f);
                me->SummonGameObject(GO_SHIELD_WRECKAGE, me->GetPosition(), rotation, 6s, GOSummonType(GO_SUMMON_TIMED_DESPAWN));
                break;
            }
            case EVENT_TRANSFORM:
                SetActive(true);
                DoCastSelf(SPELL_EYE_STALK_TRANSFORM);
                break;
            case EVENT_CAST_MIND_FLAY:
                me->CastSpell(me->FindNearestCreature(NPC_SHIVAN_ASSASSIN, 25.0f), SPELL_MIND_FLAY);
                Events.ScheduleEvent(EVENT_CAST_MIND_FLAY, 13s);
                break;
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fel_eye_stalkAI(creature);
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
            //todo I haven't found anything better than using "Charm (Possess)" (530)
            if (target->IsAlive())
                caster->CastSpell(target, 530);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shartuuls_transporter_possess_demon::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
    MODEL_STUN_FIELD                  = 11686,
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

                std::vector<Creature*> temp;
                middleStunField->GetCreatureListWithEntryInGrid(temp, NPC_TRIGGER_STUN_ROPE_DUMMY, 20.0f);
                for (uint8 i = 0; i < temp.size(); ++i)
                    if (!temp[i]->HasAura(SPELL_STUN_ZONE))
                        //Apply effect on summoned creatures
                        temp[i]->AI()->DoCastSelf(SPELL_STUN_ZONE);
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

    //todo I think it can be converted to conditions in DB, but I don't know how.
    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (Unit* target = ObjectAccessor::GetCreature(*caster, caster->GetTarget()))
            if (target->GetEntry() != NPC_GAN_ARG_UNDERLING)
                return SPELL_FAILED_BAD_TARGETS;
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_shartuuls_transporter_consume_essence::CheckCast);
    }
};

void AddSC_shartuul_event()
{
    new boss_doomguard_punisher;
    new boss_shivan_assassin;
    new boss_eye_of_shartuul;
    new boss_dreadmaw;
    new boss_shartuul;
    new npc_warp_gate_shield;
    new npc_felguard_degradeb;
    new npc_overseer_shartuul;
    new npc_shield_zapper;
    new npc_fel_imp_defender;
    new npc_felhound_defender;
    new npc_ganarg_underling;
    new npc_moarg_tormenter;
    new npc_portable_fel_cannon;
    new npc_fel_eye_stalk;
    RegisterSpellScript(spell_shartuuls_transporter_possess_demon);
    RegisterSpellScript(spell_shartuuls_transporter_aspects);
    RegisterSpellScript(spell_shartuuls_transporter_summon_stun_trap);
    RegisterSpellScript(spell_shartuuls_transporter_consume_essence);
}
