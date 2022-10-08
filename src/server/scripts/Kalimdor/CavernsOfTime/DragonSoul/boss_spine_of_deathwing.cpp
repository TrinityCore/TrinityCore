/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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

#include "AchievementMgr.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "dragon_soul.h"
#include "SpellMgr.h"
#include "GameObject.h"
#include "SpellAuraEffects.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"

enum ScriptedTexts
{
    SAY_DEATHWING_LEFT_ROLL_PRE     = 0,
    SAY_DEATHWING_RIGHT_ROLL_PRE    = 1,
    SAY_DEATHWING_LEFT_ROLL         = 2,
    SAY_DEATHWING_RIGHT_ROLL        = 3,
    SAY_DEATHWING_PLATE             = 4,
    SAY_DEATHWING_TALK              = 5,
};

enum Spells
{
    // Deathwing
    SPELL_ROLL_CONTROL              = 105036, // check aura
    SPELL_ROLL_CONTROL_AOE_1        = 104621, // triggered by check aura
    SPELL_ROLL_CONTROL_FORCE        = 105740, //
    SPELL_ROLL_CONTROL_AOE_2        = 105777, // triggered by force spell
    SPELL_ROLL_CONTROL_AOE_3        = 105773, // ?
    SPELL_SUMMON_SLIME_AOE          = 105537, //
    SPELL_SUMMON_SLIME              = 104999, // cast on spawner

    // Corruption
    SPELL_FIERY_GRIP                = 105490,
    SPELL_SEARING_PLASMA_AOE        = 109379,
    SPELL_SEARING_PLASMA            = 105479,

    // Hideous Amalgamation
    SPELL_ZERO_REGEN                = 109121,
    SPELL_ABSORB_BLOOD_BAR          = 109329,
    SPELL_DEGRADATION               = 106005,
    SPELL_NUCLEAR_BLAST             = 105845,
    SPELL_NUCLEAR_BLAST_SCRIPT      = 105846,
    SPELL_SUPERHEATED_NUCLEUS       = 105834,
    SPELL_SUPERHEATED_NUCLEUS_DMG   = 106264,
    SPELL_ABSORB_BLOOD              = 105244,
    SPELL_ABSORB_BLOOD_DUMMY        = 105241, // target on 105223
    SPELL_ABSORBED_BLOOD            = 105248,

    // Spawner ?
    SPELL_GRASPING_TENDRILS         = 105510,
    SPELL_GRASPING_TENDRILS_10      = 105563,

    // Corrupted Blood
    SPELL_RESIDUE                   = 105223,
    SPELL_BURST                     = 105219,

    // Burning Tendons
    SPELL_SEAL_ARMOR_BREACH_1       = 105847,
    SPELL_SEAL_ARMOR_BREACH_2       = 105848,
    SPELL_BREACH_ARMOR_1            = 105363,
    SPELL_BREACH_ARMOR_2            = 105385,
    SPELL_PLATE_FLY_OFF_LEFT        = 105366,
    SPELL_PLATE_FLY_OFF_RIGHT       = 105384,
    SPELL_SLOW                      = 110907, // ?

    SPELL_BLOOD_CORRUPTION_DEATH    = 106199,
    SPELL_BLOOD_CORRUPTION_EARTH    = 106200,
    SPELL_BLOOD_OF_DEATHWING        = 106201,
    SPELL_BLOOD_OF_NELTHARION       = 106213,

    SPELL_PLAY_MOVIE                = 104574, // script, achievement spell
};

enum Adds
{
    NPC_HIDEOUS_AMALGAMATION    = 53890,
    NPC_CORRUPTION_1            = 53891,
    NPC_CORRUPTION_2            = 56161, // ?
    NPC_CORRUPTION_3            = 56162, // ?
    NPC_SPAWNER                 = 53888,
    NPC_CORRUPTED_BLOOD         = 53889,
    NPC_BURNING_TENDONS_1       = 56341, // left
    NPC_BURNING_TENDONS_2       = 56575, // right
};

enum Events
{
    EVENT_CHECK_PLAYERS                 = 1,
    EVENT_FIERY_GRIP                    = 2,
    EVENT_SEARING_PLASMA                = 3,
    EVENT_CHECK_ROLL                    = 4,
    EVENT_SUMMON_HIDEOUS_AMALGAMATION   = 5,
    EVENT_SUMMON_CORRUPTED_BLOOD        = 6,
    EVENT_CHECK_SPAWNER                 = 7,
    EVENT_MOVE_TO_SPAWNER               = 8,
    EVENT_TALK                          = 9,
    EVENT_END_ENCOUNTER                 = 10,
    EVENT_BLOOD_CORRUPTION              = 11,
    EVENT_SPAWN_LOOT                    = 12,
    EVENT_CHECK_CASTING                 = 13,
    EVENT_CHECK_AURA                    = 14,
};

enum Actions
{
    ACTION_START_BATTLE = 1,
    ACTION_ROLL_LEFT    = 2,
    ACTION_ROLL_RIGHT   = 3,
    ACTION_ROLL_NONE    = 4,
    ACTION_ABSORB_BLOOD = 5,
};

enum MiscData
{
    DATA_POS        = 1,
    POINT_SPAWNER   = 2,
    DATA_PLATES     = 3,
    DATA_BLAST_POS  = 4,
};

enum RollStage
{
    ROLL_NONE           = 0,
    ROLL_PRE_LEFT_1     = 1,
    ROLL_PRE_RIGHT_1    = 2,
    ROLL_PRE_LEFT_2     = 3,
    ROLL_PRE_RIGHT_2    = 4,
    ROLLING_LEFT        = 5,
    ROLLING_RIGHT       = 6,
};

enum Achievement
{
    ACHI_HEROIC_SPINE_OF_DEATHWING = 6115,
};

const Position corruptionPos[8] =
{
    {-13868.6f, -13667.3f, 262.836f, 0.0698132f}, // left 1
    {-13841.1f, -13666.9f, 262.795f, 3.01942f}, // right 1
    {-13868.5f, -13654.1f, 262.946f, 0.0174533f}, // left 2
    {-13842.8f, -13654.1f, 263.965f, 5.84685f}, // right 2
    {-13867.1f, -13638.5f, 264.783f, 2.33874f}, // left 3
    {-13841.2f, -13635.2f, 265.261f, 0.785398f}, // right 3
    {-13870.5f, -13614.4f, 266.88f, 1.95477f}, // left 4
    {-13839.3f, -13614.8f, 266.32f, 6.23082f} // right 4
};

const Position tendonsPos[6] =
{
    {-13862.8f, -13645.f, 265.752f, 1.5708f}, // left 1
    {-13846.8f, -13644.7f, 265.789f, 1.5708f}, // right 1
    {-13862.6f, -13626.3f, 266.59f, 1.5708f}, // left 2
    {-13846.6f, -13626.f, 266.638f, 1.5708f}, // right 2
    {-13862.6f, -13604.9f, 269.227f, 1.5708f}, // left 3
    {-13846.6f, -13604.7f, 269.174f, 1.5708f} // right 3
};

class npc_spine_of_deathwing_deathwing : public CreatureScript
{
    public:
        npc_spine_of_deathwing_deathwing() : CreatureScript("npc_spine_of_deathwing_deathwing") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_spine_of_deathwing_deathwingAI(pCreature);
        }

        struct npc_spine_of_deathwing_deathwingAI : public Scripted_NoMovementAI
        {
            npc_spine_of_deathwing_deathwingAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->setActive(true);
                pInstance = me->GetInstanceScript();
                rollStage = ROLL_NONE;
                destroyedPlates = 0;
                achieve = 0;
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_START_BATTLE:
                        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 10000);
                        ResetBattle(false, false);
                        StartBattle();
                        break;
                    case ACTION_ROLL_LEFT:
                        if (rollStage == ROLL_NONE)
                            rollStage = ROLL_PRE_LEFT_1;
                        break;
                    case ACTION_ROLL_RIGHT:
                        if (rollStage == ROLL_NONE)
                            rollStage = ROLL_PRE_RIGHT_1;
                        break;
                    case ACTION_ROLL_NONE:
                        rollStage = ROLL_NONE;
                        break;
                }
            }

            bool AllowAchieve()
            {
                return (achieve == 4);
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_PLATES)
                {
                    destroyedPlates = (uint8)data;
                    if (pInstance)
                    {
                        if (destroyedPlates == 1)
                        {
                            Talk(SAY_DEATHWING_PLATE);
                            pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_1), true);
                            for (uint8 i = 4; i < 6; ++i)
                                if (Creature* pCorruption = me->SummonCreature(NPC_CORRUPTION_1, corruptionPos[i]))
                                {
                                    pCorruption->AI()->SetData(DATA_POS, i);
                                    DoZoneInCombat(pCorruption);
                                }
                        }
                        else if (destroyedPlates == 2)
                        {
                            Talk(SAY_DEATHWING_PLATE);
                            pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_2), true);
                            for (uint8 i = 6; i < 8; ++i)
                                if (Creature* pCorruption = me->SummonCreature(NPC_CORRUPTION_1, corruptionPos[i]))
                                {
                                    pCorruption->AI()->SetData(DATA_POS, i);
                                    DoZoneInCombat(pCorruption);
                                }
                        }
                        else if (destroyedPlates == 3)
                        {
                            Talk(SAY_DEATHWING_PLATE);
                            pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_3), true);
                            events.ScheduleEvent(EVENT_END_ENCOUNTER, 1000);
                        }
                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_PLATES)
                    return (uint32)destroyedPlates;
                return 0;
            }

            void DamageTaken(Unit* /*who*/, uint32 &damage) override
            {
                if (me->GetHealth() <= damage)
                    damage = 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_END_ENCOUNTER:
                            events.Reset();
                            ResetBattle(true);
                            if (pInstance)
                            {
                                //75 Justices Points for players level 85
                                pInstance->DoModifyPlayerCurrencies(395, 7500);
                                if (!IsHeroic())
                                {
                                    pInstance->DoModifyPlayerCurrencies(614, 1);
                                    pInstance->DoModifyPlayerCurrencies(615, 1);
                                }
                                else
                                {
                                    pInstance->DoModifyPlayerCurrencies(614, 2);
                                    pInstance->DoModifyPlayerCurrencies(615, 2);
                                    pInstance->DoCompleteAchievement(ACHI_HEROIC_SPINE_OF_DEATHWING);
                                }
                                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SEARING_PLASMA);
                                pInstance->DoStartMovie(75);
                                events.ScheduleEvent(EVENT_SPAWN_LOOT, 3000);
                                pInstance->DoNearTeleportPlayers(madnessdeathwingPos);
                            }
                            break;
                        case EVENT_SPAWN_LOOT:
                            if (Creature* trall = pInstance->GetCreature(DATA_TRALL_MAELSTROM))
                                trall->SummonGameObject(RAID_MODE(GO_GREATER_CACHE_OF_THE_ASPECTS_10N, GO_GREATER_CACHE_OF_THE_ASPECTS_25N, GO_GREATER_CACHE_OF_THE_ASPECTS_10H, GO_GREATER_CACHE_OF_THE_ASPECTS_25H), -12075.2f, 12168.2f, -2.56926f, 3.57793f, QuaternionData(), 7 * DAY);
                            break;
                        case EVENT_SUMMON_CORRUPTED_BLOOD:
                        {
                            std::list<Creature*> targets;
                            me->GetCreatureListWithEntryInGrid(targets, NPC_SPAWNER, 200.0f);
                            if (!targets.empty())
                            {
                                Unit* pSpawner = Trinity::Containers::SelectRandomContainerElement(targets);
                                if (Creature* pBlood = me->SummonCreature(NPC_CORRUPTED_BLOOD, *pSpawner))
                                    DoZoneInCombat(pBlood);
                            }
                            events.ScheduleEvent(EVENT_SUMMON_CORRUPTED_BLOOD, 12000);
                            break;
                        }
                        case EVENT_TALK:
                            Talk(SAY_DEATHWING_TALK);
                            events.ScheduleEvent(EVENT_TALK, urand(35000, 45000));
                            break;
                        case EVENT_CHECK_PLAYERS:
                            if (pInstance)
                            {
                                if ((pInstance->GetBossState(DATA_SPINE) != IN_PROGRESS) || !CheckPlayers())
                                {
                                    ResetBattle(false, true);
                                }
                                else
                                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                            }
                            break;
                        case EVENT_CHECK_ROLL:
                            switch (rollStage)
                            {
                                case ROLL_PRE_LEFT_1:
                                    Talk(SAY_DEATHWING_LEFT_ROLL_PRE);
                                    rollStage = ROLL_PRE_LEFT_2;
                                    events.ScheduleEvent(EVENT_CHECK_ROLL, 5000);
                                    break;
                                case ROLL_PRE_LEFT_2:
                                    Talk(SAY_DEATHWING_LEFT_ROLL);
                                    rollStage = ROLLING_LEFT;
                                    events.ScheduleEvent(EVENT_CHECK_ROLL, 1000);
                                    break;
                                case ROLLING_LEFT:
                                    DoRoll(1);
                                    events.ScheduleEvent(EVENT_CHECK_ROLL, 10000);
                                    rollStage = ROLL_NONE;
                                    break;
                                case ROLL_PRE_RIGHT_1:
                                    Talk(SAY_DEATHWING_RIGHT_ROLL_PRE);
                                    rollStage = ROLL_PRE_RIGHT_2;
                                    events.ScheduleEvent(EVENT_CHECK_ROLL, 5000);
                                    break;
                                case ROLL_PRE_RIGHT_2:
                                    Talk(SAY_DEATHWING_RIGHT_ROLL);
                                    rollStage = ROLLING_RIGHT;
                                    events.ScheduleEvent(EVENT_CHECK_ROLL, 1000);
                                    break;
                                case ROLLING_RIGHT:
                                    DoRoll(2);
                                    events.ScheduleEvent(EVENT_CHECK_ROLL, 10000);
                                    rollStage = ROLL_NONE;
                                    break;
                                default:
                                    events.ScheduleEvent(EVENT_CHECK_ROLL, 2000);
                                    break;
                            }
                            break;
                    }
                }
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
            RollStage rollStage;
            uint8 destroyedPlates;
            int8 achieve;

            void DoRoll(uint8 side /* 1 - left, 2 - right*/)
            {
                std::list<Player*> players;
                AnyLivePlayerNoGmCheck check(me, 200.0f, true);
                Trinity::PlayerListSearcher<AnyLivePlayerNoGmCheck> searcher(me, players, check);
                Cell::VisitWorldObjects(me, searcher, 200.0f);
                if (!players.empty())
                    for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++ itr)
                        if (Player* pPlayer = (*itr))
                            pPlayer->CastSpell(pPlayer->GetPositionX() + ((side == 2) ? 50 : - 50), pPlayer->GetPositionY() - 100.0f, pPlayer->GetPositionZ() + 30.0f, SPELL_ROLL_CONTROL_AOE_2, true);


                DespawnCreatures(NPC_HIDEOUS_AMALGAMATION);

                if (achieve != -1 && achieve < 4)
                {
                    if ((achieve % 2) == (side - 1))
                        achieve++;
                    else
                        achieve = -1;
                }
            }

            void ResetBattle(bool done = false, bool despawn = true)
            {
                if (pInstance)
                {
                    pInstance->SetBossState(DATA_SPINE, (done ? DONE : NOT_STARTED));
                    if (!done)
                    {
                        pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_1),  false);
                        pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_2),  false);
                        pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_3),  false);
                    }
                }

                if (despawn)
                {
                    DespawnCreatures(NPC_HIDEOUS_AMALGAMATION);
                    DespawnCreatures(NPC_CORRUPTION_1);
                    DespawnCreatures(NPC_CORRUPTION_2);
                    DespawnCreatures(NPC_CORRUPTION_3);
                    DespawnCreatures(NPC_SPAWNER);
                    DespawnCreatures(NPC_CORRUPTED_BLOOD);
                    DespawnCreatures(NPC_BURNING_TENDONS_1);
                    DespawnCreatures(NPC_BURNING_TENDONS_2);
                    me->DespawnOrUnsummon(8000);
                }
            }

            void StartBattle()
            {
                for (uint8 i = 0; i < 4; ++i)
                    if (Creature* pCorruption = me->SummonCreature(NPC_CORRUPTION_1, corruptionPos[i]))
                    {
                        pCorruption->AI()->SetData(DATA_POS, i);
                        DoZoneInCombat(pCorruption);
                    }

                for (uint8 i = 0; i < 6; ++i)
                    if (Creature* pTendons = me->SummonCreature((((i % 2) == 1) ? NPC_BURNING_TENDONS_2 : NPC_BURNING_TENDONS_1), tendonsPos[i]))
                    {
                        pTendons->AI()->SetData(DATA_POS, i);
                        DoZoneInCombat(pTendons);
                    }

                pInstance->SetBossState(DATA_SPINE, IN_PROGRESS);
                rollStage = ROLL_NONE;
                events.ScheduleEvent(EVENT_CHECK_ROLL, 3000);
                events.ScheduleEvent(EVENT_TALK, urand(3000, 5000));
                events.ScheduleEvent(EVENT_SUMMON_CORRUPTED_BLOOD, 10000);
                DoCast(me, SPELL_ROLL_CONTROL, true);
            }

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon();
            }

            bool CheckPlayers()
            {
                Player* player = NULL;
                AnyLivePlayerNoGmCheck check(me, 200.0f);
                Trinity::PlayerSearcher<AnyLivePlayerNoGmCheck> searcher(me, player, check);
                Cell::VisitWorldObjects(me, searcher, 200.0f);
                return (player ? true : false);
            }

            class AnyLivePlayerNoGmCheck
            {
                public:
                    AnyLivePlayerNoGmCheck(WorldObject const* obj, float range, bool withAura = false) : _obj(obj), _range(range), _withAura(withAura) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (!_obj->IsWithinDistInMap(u, _range))
                            return false;

                        /*if (u->IsGameMaster())
                            return false;*/

                        if (_withAura)
                        {
                            uint32 spellId1 = SPELL_GRASPING_TENDRILS_10;
                            uint32 spellId2 = SPELL_FIERY_GRIP;
                            if (u->HasAura(spellId1) || u->HasAura(spellId2))
                                return false;
                        }

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
                    bool _withAura;
            };
        };
};

class npc_spine_of_deathwing_corruption : public CreatureScript
{
    public:
        npc_spine_of_deathwing_corruption() : CreatureScript("npc_spine_of_deathwing_corruption") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_spine_of_deathwing_corruptionAI(pCreature);
        }

        struct npc_spine_of_deathwing_corruptionAI : public Scripted_NoMovementAI
        {
            npc_spine_of_deathwing_corruptionAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->SetReactState(REACT_PASSIVE);
                damageCounter = 0;
                isGrip = false;
            }

            void IsSummonedBy(Unit* /*who*/) override
            {
                if (Creature* pSpawner = me->FindNearestCreature(NPC_SPAWNER, 5.0f, true))
                    pSpawner->DespawnOrUnsummon();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SEARING_PLASMA, urand(1000, 8000));
                events.ScheduleEvent(EVENT_FIERY_GRIP, urand(31000, 33000));
            }

            void DamageTaken(Unit* /*who*/, uint32 &damage) override
            {
                if (!isGrip)
                    return;

                if (damageCounter <= damage)
                {
                    damageCounter = 0;
                    isGrip = false;
                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                }
                else
                    damageCounter -= damage;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_POS)
                    pos = (uint8)data;
            }

            void JustDied(Unit* /*who*/) override
            {
                events.Reset();
                if (!me->FindNearestCreature(NPC_CORRUPTION_1, 200.0f, true))
                {
                    uint8 i = (((pos % 2) == 1) ? pos - 1 : pos + 1);
                    if (Creature* pCorruption = me->SummonCreature(NPC_CORRUPTION_1, corruptionPos[i]))
                    {
                        pCorruption->AI()->SetData(DATA_POS, i);
                        DoZoneInCombat(pCorruption);
                    }
                }
                me->SummonCreature(NPC_HIDEOUS_AMALGAMATION, *me);
                me->SummonCreature(NPC_SPAWNER, *me);

                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIERY_GRIP:
                        {
                            Unit* pTarget = NULL;
                            pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true, -SPELL_FIERY_GRIP);
                            if (!pTarget)
                                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true);
                            if (pTarget)
                            {
                                isGrip = true;
                                damageCounter = me->CountPctFromMaxHealth(20);
                                me->CastCustomSpell(SPELL_FIERY_GRIP, SPELLVALUE_MAX_TARGETS, RAID_MODE(1, 3), pTarget, false);
                            }
                            events.ScheduleEvent(EVENT_FIERY_GRIP, urand(31000, 33000));
                            break;
                        }
                        case EVENT_SEARING_PLASMA:
                        {
                             DoCastAOE(SPELL_SEARING_PLASMA_AOE);
                             events.ScheduleEvent(EVENT_SEARING_PLASMA, urand(15000, 20000));
                             break;
                        }
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
            uint32 damageCounter;
            bool isGrip;
            uint8 pos;
        };
};

class npc_spine_of_deathwing_hideous_amalgamation : public CreatureScript
{
    public:
        npc_spine_of_deathwing_hideous_amalgamation() : CreatureScript("npc_spine_of_deathwing_hideous_amalgamation") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_spine_of_deathwing_hideous_amalgamationAI(pCreature);
        }

        struct npc_spine_of_deathwing_hideous_amalgamationAI : public ScriptedAI
        {
            npc_spine_of_deathwing_hideous_amalgamationAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);

                degradationDebuff = false;
                isExplode = false;
            }

            void Reset() override
            {
                events.Reset();
                absorve = 0;
                me->SetMaxPower(POWER_ALTERNATE_POWER, 9);
                me->SetPower(POWER_ALTERNATE_POWER, 0);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 200.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    AttackStart(target);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_ABSORB_BLOOD)
                {
                    DoCast(me, SPELL_ABSORBED_BLOOD, true);
                    absorve++;
                }
            }

            void JustDied(Unit* /*who*/) override
            {
                if (IsHeroic() && !degradationDebuff)
                {
                    if (InstanceScript* pInstance = me->GetInstanceScript())
                    {
                        Map::PlayerList const& plrList = pInstance->instance->GetPlayers();
                        if (!plrList.isEmpty())
                            for (Map::PlayerList::const_iterator itr = plrList.begin(); itr != plrList.end(); ++itr)
                                if (Player* pPlayer = itr->GetSource())
                                if (pPlayer->GetDistance(me) <= 200.0f)
                                {
                                    degradationDebuff = true;
                                    pPlayer->AddAura(SPELL_DEGRADATION, pPlayer);
                                }

                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_BLAST_POS)
                {
                    if (me->GetPositionX() > -13870.0f && me->GetPositionX() <= -13854.787109f &&
                        me->GetPositionY() > -13660.0f && me->GetPositionY() < -13640.0f)
                        return 1;
                    if (me->GetPositionX() >= -13854.787109f && me->GetPositionX() <= -13830.0f &&
                        me->GetPositionY() > -13660.0f && me->GetPositionY() < -13640.0f)
                        return 2;
                    if (me->GetPositionX() > -13870.0f && me->GetPositionX() <= -13854.787109f &&
                        me->GetPositionY() > -13640.0f && me->GetPositionY() < -13620.0f)
                        return 3;
                    if (me->GetPositionX() >= -13854.787109f && me->GetPositionX() <= -13830.0f &&
                        me->GetPositionY() > -13640.0f && me->GetPositionY() < -13620.0f)
                        return 4;
                    if (me->GetPositionX() > -13870.0f && me->GetPositionX() <= -13854.787109f &&
                        me->GetPositionY() > -13620.0f && me->GetPositionY() < -13600.0f)
                        return 5;
                    if (me->GetPositionX() >= -13854.787109f && me->GetPositionX() <= -13830.0f &&
                        me->GetPositionY() > -13620.0f && me->GetPositionY() < -13600.0f)
                        return 6;
                }
                return 0;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_BLOOD_CORRUPTION, urand(6000, 11000));
                events.ScheduleEvent(EVENT_CHECK_AURA, 500);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (me->GetHealth() <= damage)
                {
                    if (Aura* aur = me->GetAura(SPELL_ABSORBED_BLOOD))
                        if (aur->GetStackAmount() >= 9)
                        {
                            damage = 0;
                            if (!isExplode)
                            {
                                isExplode = true;
                                DoCastAOE(SPELL_NUCLEAR_BLAST);
                            }
                        }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_BLOOD_CORRUPTION)
                    {
                        DoCastAOE(SPELL_BLOOD_CORRUPTION_DEATH);
                    }
                    if (eventId == EVENT_CHECK_AURA)
                    {
                        if (me->GetPower(POWER_ALTERNATE_POWER) < 9)
                            me->SetPower(POWER_ALTERNATE_POWER, absorve);
                        if (Aura* aur = me->GetAura(SPELL_ABSORBED_BLOOD))
                        if ((aur->GetStackAmount() >= 9 || me->GetPower(POWER_ALTERNATE_POWER) >= 9) && !me->HasAura(SPELL_SUPERHEATED_NUCLEUS))
                            me->AddAura(SPELL_SUPERHEATED_NUCLEUS, me);
                        events.ScheduleEvent(EVENT_CHECK_AURA, 500);
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool isExplode;
            bool degradationDebuff;
            EventMap events;
            uint8 absorve;
        };
};

class npc_spine_of_deathwing_spawner : public CreatureScript
{
    public:
        npc_spine_of_deathwing_spawner() : CreatureScript("npc_spine_of_deathwing_spawner") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_spine_of_deathwing_spawnerAI(pCreature);
        }

        struct npc_spine_of_deathwing_spawnerAI : public Scripted_NoMovementAI
        {
            npc_spine_of_deathwing_spawnerAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                DoCast(me, SPELL_GRASPING_TENDRILS, true);
            }

            void KilledUnit(Unit* who) override
            {
                if (who && who->GetTypeId() == TYPEID_PLAYER)
                {
                    who->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 94644, 0, 0, me, who->ToPlayer());
                    who->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET2, 94655, 0, 0, me, who->ToPlayer());
                }
            }
        };
};

class npc_spine_of_deathwing_corrupted_blood : public CreatureScript
{
    public:
        npc_spine_of_deathwing_corrupted_blood() : CreatureScript("npc_spine_of_deathwing_corrupted_blood") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_spine_of_deathwing_corrupted_bloodAI(pCreature);
        }

        struct npc_spine_of_deathwing_corrupted_bloodAI : public ScriptedAI
        {
            npc_spine_of_deathwing_corrupted_bloodAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                isDead = false;
            }

            void Reset() override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                events.Reset();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE)
                    if (id == POINT_SPAWNER)
                    {
                        isDead = false;
                        me->SetSpeed(MOVE_RUN, 1.0f);
                        me->SetSpeed(MOVE_SWIM, 1.0f);
                        me->SetSpeed(MOVE_WALK, 1.0f);
                        me->SetSpeed(MOVE_FLIGHT, 1.0f);
                        DoResetThreat();
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveAura(SPELL_RESIDUE);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                    }
            }

            void DamageTaken(Unit* /*who*/, uint32 & damage) override
            {
                if (me->GetHealth() < damage)
                {
                    damage = 0;
                    if (!isDead)
                    {
                        isDead = true;
                        DoResetThreat();
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                        DoCastAOE(SPELL_BURST, true);
                        DoCast(me, SPELL_RESIDUE, true);
                        me->SetSpeed(MOVE_RUN, 0.05f);
                        me->SetSpeed(MOVE_SWIM, 0.05f);
                        me->SetSpeed(MOVE_WALK, 0.05f);
                        me->SetSpeed(MOVE_FLIGHT, 0.05f);
                        events.ScheduleEvent(EVENT_MOVE_TO_SPAWNER, 5000);
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_MOVE_TO_SPAWNER)
                    {
                        if (Creature* pSpawner = me->FindNearestCreature(NPC_SPAWNER, 200.0f, true))
                            me->GetMotionMaster()->MovePoint(POINT_SPAWNER, *pSpawner);
                    }
                }

                DoMeleeAttackIfReady();
             }

        private:
            EventMap events;
            bool isDead;
        };
};

class npc_spine_of_deathwing_burning_tendons : public CreatureScript
{
    public:
        npc_spine_of_deathwing_burning_tendons() : CreatureScript("npc_spine_of_deathwing_burning_tendons") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_spine_of_deathwing_burning_tendonsAI(pCreature);
        }

        struct npc_spine_of_deathwing_burning_tendonsAI : public Scripted_NoMovementAI
        {
            npc_spine_of_deathwing_burning_tendonsAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                isOpened = false;
                pInstance = me->GetInstanceScript();
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                if (spellInfo->Id == SPELL_NUCLEAR_BLAST_SCRIPT && !isOpened)
                {
                    Creature* pDeathwing = NULL;
                    pDeathwing = me->FindNearestCreature(NPC_SPINE_OF_DEATHWING, 300.0f);
                    if (!pDeathwing)
                        return;

                    switch (pos)
                    {
                        case 0:
                        case 1:
                            if (pDeathwing->AI()->GetData(DATA_PLATES) != 0)
                                return;
                            break;
                        case 2:
                        case 3:
                            if (pDeathwing->AI()->GetData(DATA_PLATES) != 1)
                                return;
                            break;
                        case 4:
                        case 5:
                            if (pDeathwing->AI()->GetData(DATA_PLATES) != 2)
                                return;
                            break;
                        default:
                            return;
                    }

                    isOpened = true;
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    DoCast(me, ((pos % 2) == 1) ? SPELL_BREACH_ARMOR_2 : SPELL_BREACH_ARMOR_1, true);
                    DoCast(me, ((pos % 2) == 1) ? SPELL_SEAL_ARMOR_BREACH_2 : SPELL_SEAL_ARMOR_BREACH_1);
                    events.ScheduleEvent(EVENT_CHECK_CASTING, 1000);
                }
                else if ((spellInfo->Id == SPELL_SEAL_ARMOR_BREACH_2 || spellInfo->Id == SPELL_SEAL_ARMOR_BREACH_1) && isOpened)
                {
                    isOpened = false;
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    if (Creature* pDeathwing = me->FindNearestCreature(NPC_SPINE_OF_DEATHWING, 200.0f, true))
                    {
                        uint8 cur_plate = pDeathwing->AI()->GetData(DATA_PLATES);
                        if (cur_plate == 0)
                            pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_1), false);
                        if (cur_plate == 1)
                            pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_2), false);
                        if (cur_plate == 2)
                            pInstance->HandleGameObject(pInstance->GetGuidData(DATA_BACK_PLATE_3), false);
                    }
                    events.Reset();
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (!isOpened)
                    damage = 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_POS)
                    pos = (uint8)data;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_POS)
                    return pos;
                return 0;
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                return;
            }

            void JustDied(Unit* /*who*/) override
            {
                DoCast(me, ((pos % 2) == 1) ? SPELL_PLATE_FLY_OFF_RIGHT : SPELL_PLATE_FLY_OFF_LEFT, true);
                if (Creature* pDeathwing = me->FindNearestCreature(NPC_SPINE_OF_DEATHWING, 300.0f))
                {
                    pDeathwing->AI()->SetData(DATA_PLATES, pDeathwing->AI()->GetData(DATA_PLATES) + 1);
                }
                me->DespawnOrUnsummon(1000);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_CHECK_CASTING:
                    {
                        if (isOpened)
                        {
                            if (!me->HasUnitState(UNIT_STATE_CASTING))
                            {
                                isOpened = false;
                                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            }
                            events.ScheduleEvent(EVENT_CHECK_CASTING, 1000);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

        private:
            uint8 pos;
            bool isOpened;
            EventMap events;
            InstanceScript* pInstance;
        };
};

class spell_spine_of_deathwing_roll_control_check : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_roll_control_check() : SpellScriptLoader("spell_spine_of_deathwing_roll_control_check") { }

        class spell_spine_of_deathwing_roll_control_check_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spine_of_deathwing_roll_control_check_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                uint8 min_diff = (targets.size() > 3) ? 2 : 1;
                uint8 playersLeft = 0;
                uint8 playersRight = 0;

                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    if ((*itr)->GetPositionX() >= -13850.3)
                        playersRight++;
                    else if ((*itr)->GetPositionX() <= -13860)
                        playersLeft++;
                }

                if (Creature* pDeathwing = GetCaster()->ToCreature())
                {
                    if (playersLeft >= playersRight && playersLeft >= min_diff)
                        pDeathwing->AI()->DoAction(ACTION_ROLL_LEFT);
                    else if (playersRight >= playersLeft && playersRight >= min_diff)
                        pDeathwing->AI()->DoAction(ACTION_ROLL_RIGHT);
                    else
                        pDeathwing->AI()->DoAction(ACTION_ROLL_NONE);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spine_of_deathwing_roll_control_check_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spine_of_deathwing_roll_control_check_SpellScript();
        }
};

class spell_spine_of_deathwing_searing_plasma_aoe : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_searing_plasma_aoe() : SpellScriptLoader("spell_spine_of_deathwing_searing_plasma_aoe") { }

        class spell_spine_of_deathwing_searing_plasma_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spine_of_deathwing_searing_plasma_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Aura* aur = GetHitUnit()->GetAura(SPELL_SEARING_PLASMA))
                    aur->ModStackAmount(1);
                else
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_SEARING_PLASMA, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spine_of_deathwing_searing_plasma_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_spine_of_deathwing_searing_plasma_aoe_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spine_of_deathwing_searing_plasma_aoe_SpellScript();
        }
};

class spell_spine_of_deathwing_nuclear_blast : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_nuclear_blast() : SpellScriptLoader("spell_spine_of_deathwing_nuclear_blast") { }

        class spell_spine_of_deathwing_nuclear_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spine_of_deathwing_nuclear_blast_SpellScript);

            void HandleAfterCast()
            {
                if (!GetCaster())
                    return;

                GetCaster()->CastSpell(GetCaster(), SPELL_NUCLEAR_BLAST_SCRIPT, true);
                GetCaster()->Kill(GetCaster());
                if (Creature* pAmalgamation = GetCaster()->ToCreature())
                    pAmalgamation->AI()->JustDied(pAmalgamation);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_spine_of_deathwing_nuclear_blast_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spine_of_deathwing_nuclear_blast_SpellScript();
        }
};

class spell_spine_of_deathwing_absorb_blood : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_absorb_blood() : SpellScriptLoader("spell_spine_of_deathwing_absorb_blood") { }

        class spell_spine_of_deathwing_absorb_blood_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spine_of_deathwing_absorb_blood_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (Creature* pAmalgamation = GetCaster()->ToCreature())
                {
                    Aura* aur = NULL;
                    aur = pAmalgamation->GetAura(SPELL_ABSORBED_BLOOD);
                    if (!aur || aur->GetStackAmount() < 9)
                        if (Creature* pBlood = GetHitUnit()->ToCreature())
                        {
                            pBlood->RemoveAura(SPELL_RESIDUE);
                            pBlood->DespawnOrUnsummon(1000);
                            pAmalgamation->AI()->DoAction(ACTION_ABSORB_BLOOD);
                        }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_spine_of_deathwing_absorb_blood_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spine_of_deathwing_absorb_blood_SpellScript();
        }
};

class spell_spine_of_deathwing_nuclear_blast_script : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_nuclear_blast_script() : SpellScriptLoader("spell_spine_of_deathwing_nuclear_blast_script") { }

        class spell_spine_of_deathwing_nuclear_blast_script_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spine_of_deathwing_nuclear_blast_script_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                if (GetCaster()->IsPlayer())
                {
                    if (targets.size() > 1)
                    {
                        targets.sort(DistancePred(GetCaster()));
                        targets.resize(1);
                    }
                    return;
                }

                targets.clear();

                if (Creature* pDeathwing = GetCaster()->FindNearestCreature(NPC_SPINE_OF_DEATHWING, 200.0f, true))
                {
                    uint8 cur_plate = pDeathwing->AI()->GetData(DATA_PLATES);
                    uint8 pos = GetCaster()->ToCreature()->AI()->GetData(DATA_BLAST_POS);
                    if ((cur_plate == 0 && pos != 1 && pos != 2) ||
                        (cur_plate == 1 && pos != 3 && pos != 4) ||
                        (cur_plate == 2 && pos != 5 && pos != 6) ||
                        (cur_plate >= 3))
                        return;

                    Creature* pTendons = GetCaster()->FindNearestCreature((((pos % 2) == 0) ? NPC_BURNING_TENDONS_2 : NPC_BURNING_TENDONS_1), 20.0f, true);
                    if (!pTendons)
                        return;

                    uint8 tendons_pos = pTendons->AI()->GetData(DATA_POS);

                    if ((pos - 1) != tendons_pos)
                        return;

                    targets.push_back(pTendons);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spine_of_deathwing_nuclear_blast_script_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }

        private:
            class DistancePred
            {
                public:
                    DistancePred(Unit* searcher) :  _searcher(searcher) { }
                    bool operator() (WorldObject* a, WorldObject* b) const
                    {
                        float rA = _searcher->GetDistance(a);
                        float rB = _searcher->GetDistance(b);
                        return rA < rB;
                    }
                private:
                    Unit const* _searcher;
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spine_of_deathwing_nuclear_blast_script_SpellScript();
        }
};

class spell_spine_of_deathwing_blood_corruption : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_blood_corruption() : SpellScriptLoader("spell_spine_of_deathwing_blood_corruption") { }

        class spell_spine_of_deathwing_blood_corruption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spine_of_deathwing_blood_corruption_AuraScript);

            void HandleDispel(DispelInfo* /*dispelInfo*/)
            {
                uint32 cur_duration = GetDuration();
                if (Unit* owner = GetUnitOwner())
                {
                    Unit* target = NULL;
                    std::list<Player*> players;
                    PlayersCheck check(owner);
                    Trinity::PlayerListSearcher<PlayersCheck> searcher(owner, players, check);
                    Cell::VisitWorldObjects(owner, searcher, 200.0f);
                    if (!players.empty())
                        target = Trinity::Containers::SelectRandomContainerElement(players);
                    else
                        target = owner;

                    if (target)
                        if (Aura* aur = owner->AddAura(((GetAura()->GetId() == SPELL_BLOOD_CORRUPTION_DEATH) ? (roll_chance_i(40) ? SPELL_BLOOD_CORRUPTION_EARTH : SPELL_BLOOD_CORRUPTION_DEATH) : SPELL_BLOOD_CORRUPTION_EARTH), target))
                            aur->SetDuration(cur_duration);
                }
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                    if (removeMode == AURA_REMOVE_BY_EXPIRE || removeMode == AURA_REMOVE_BY_DEATH)
                        owner->CastSpell(owner, (GetId() == SPELL_BLOOD_CORRUPTION_EARTH) ? SPELL_BLOOD_OF_NELTHARION : SPELL_BLOOD_OF_DEATHWING, true);
                }
            }

            void Register() override
            {
                AfterDispel += AuraDispelFn(spell_spine_of_deathwing_blood_corruption_AuraScript::HandleDispel);
                AfterEffectRemove += AuraEffectRemoveFn(spell_spine_of_deathwing_blood_corruption_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

        private:
            class PlayersCheck
            {
                public:
                    PlayersCheck(WorldObject const* obj) : _obj(obj) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (u->IsGameMaster())
                            return false;

                        if (!_obj->IsWithinDistInMap(u, 200.0f))
                            return false;

                        if (u->HasAura(SPELL_BLOOD_CORRUPTION_DEATH) ||
                            u->HasAura(SPELL_BLOOD_CORRUPTION_EARTH))
                            return false;

                        if (_obj->GetGUID() == u->GetGUID())
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
            };
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_spine_of_deathwing_blood_corruption_AuraScript();
        }
};

class spell_spine_of_deathwing_roll_control : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_roll_control() : SpellScriptLoader("spell_spine_of_deathwing_roll_control") { }

        class spell_spine_of_deathwing_roll_control_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spine_of_deathwing_roll_control_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetUnitOwner())
                    owner->Kill(owner);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_spine_of_deathwing_roll_control_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_spine_of_deathwing_roll_control_AuraScript();
        }
};

class spell_spine_of_deathwing_blood_corruption_death : public SpellScriptLoader
{
    public:
        spell_spine_of_deathwing_blood_corruption_death() : SpellScriptLoader("spell_spine_of_deathwing_blood_corruption_death") { }

        class spell_spine_of_deathwing_blood_corruption_death_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_spine_of_deathwing_blood_corruption_death_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_spine_of_deathwing_blood_corruption_death_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_spine_of_deathwing_blood_corruption_death_SpellScript();
        }
};

typedef npc_spine_of_deathwing_deathwing::npc_spine_of_deathwing_deathwingAI SpineAI;

class achievement_maybe_he_ll_get_dizzy : public AchievementCriteriaScript
{
    public:
        achievement_maybe_he_ll_get_dizzy() : AchievementCriteriaScript("achievement_maybe_he_ll_get_dizzy") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (SpineAI* spineAI = CAST_AI(SpineAI, target->GetAI()))
                return spineAI->AllowAchieve();

            return false;
        }
};

void AddSC_spine_of_deathwing()
{
    new npc_spine_of_deathwing_deathwing();
    new npc_spine_of_deathwing_corruption();
    new npc_spine_of_deathwing_hideous_amalgamation();
    new npc_spine_of_deathwing_spawner();
    new npc_spine_of_deathwing_corrupted_blood();
    new npc_spine_of_deathwing_burning_tendons();
    new spell_spine_of_deathwing_roll_control_check();
    new spell_spine_of_deathwing_searing_plasma_aoe();
    new spell_spine_of_deathwing_nuclear_blast();
    new spell_spine_of_deathwing_absorb_blood();
    new spell_spine_of_deathwing_nuclear_blast_script();
    new spell_spine_of_deathwing_blood_corruption();
    new spell_spine_of_deathwing_roll_control();
    new spell_spine_of_deathwing_blood_corruption_death();
    new achievement_maybe_he_ll_get_dizzy();
}
