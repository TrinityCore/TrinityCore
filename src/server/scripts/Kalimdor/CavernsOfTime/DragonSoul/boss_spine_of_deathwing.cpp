/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
*
* Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

/* ScriptData
SDName: boss_spine_of_deathwing
Author: Bennu
SD%Complete: 80%
SDComment: Backplates does not works
SDCategory: Boss Spine of Deathwing
EndScriptData
*/

#include "ScriptMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "GameObjectAI.h"
#include "Vehicle.h"
#include "dragon_soul.h"
#include "GameObject.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum Events
{
    // Deathwing
    EVENT_CHECK_CORRUPTION = 1,
    EVENT_PLATE,
    EVENT_SIDE_CHECK,
    EVENT_BARREL_ROLL,
    EVENT_ROLL_LEFT,
    EVENT_ROLL_RIGHT,
    EVENT_BLOOD_SPEED,
    EVENT_TALK,

    // Corruption
    EVENT_FIERY_GRIP,
    EVENT_SEARING_PLASMA,
    EVENT_INTRO,

    // Burning Tendons
    EVENT_SEAL_ARMOR,
    EVENT_PLATE_CHECK,

    // Corrupted Blood
    EVENT_CHECK_AMALGAMATION,
    EVENT_FIND_HOLE,

    // Spawner
    EVENT_SPAWN_BLOOD,

    // Hideous Amalgamation
    EVENT_BLOOD_CORRUPTION,
};

enum Actions
{
    ACTION_MOVE = 0,
};

enum Spells
{
    // Corruption
    SPELL_FIERY_GRIP             = 105490,
    SPELL_FIERY_GRIP_AURA        = 109457,
    SPELL_SEARING_PLASMA_DUMMY   = 109379,
    SPELL_SEARING_PLASMA         = 105479,

    // Corrupted Blood
    SPELL_BURST                  = 105219,
    SPELL_ABSORBED_BLOOD         = 105248,
    SPELL_ABSORB_BLOOD_PERIODIC  = 105244,
    SPELL_ABSORB_BLOOD_DUMMY     = 105241,
    SPELL_RESIDUE                = 105223,

    // Hideous Amalgamation
    SPELL_SUPERHEATED_NUCLEUS    = 105834,
    SPELL_NUCLEAR_BLAST          = 105845,
    SPELL_NUCLEAR_BLAST_TENDON   = 105846,
    SPELL_DEGRADATION            = 106005,

    // Burning Tendon
    SPELL_SEAL_ARMOR_BREACH      = 105847,
    SPELL_PLATE_FLY_OFF_LEFT     = 105366,
    SPELL_PLATE_FLY_OFF_RIGHT    = 105384,

    // Misc
    SPELL_ABSORB_BLOOD_BAR       = 109329,
    SPELL_GRASPING_TENDRILS      = 105510,
    SPELL_GRASPING_TENDRILS_AURA = 105563,
    SPELL_BLOOD_OF_DEATHWING     = 106201,
    SPELL_BLOOD_CORRUPTION_DEATH = 106199,
    SPELL_BLOOD_CORRUPTION_EARTH = 106200,
    SPELL_BLOOD_OF_NELTHARION    = 106213,
};

enum ScriptedTexts
{
    // Deathwing
    SAY_TEXT        = 0,
    SAY_BACKPLATE   = 1,
    SAY_FEEL_LEFT   = 2,
    SAY_ROLL_LEFT   = 3,
    SAY_FEEL_RIGHT  = 4,
    SAY_ROLL_RIGHT  = 5,

    // Captain Swayze
    SAY_SWAYZE_INTRO_SPINE = 2,
    SAY_SWAYZE_INTRO_SPINE_1 = 3,
};

Position const rollPos = { -13857.34f, -13759.77f, 286.14f, 1.49f };

Position const corrPos[] =
{
    { -13841.6f, -13667.0f, 262.0f, 3.10f },
    { -13868.5f, -13667.3f, 261.9f, 0.03f },
    { -13868.6f, -13654.1f, 262.8f, 0.01f },
    { -13842.8f, -13654.5f, 263.1f, 3.14f },
    { -13841.4f, -13635.0f, 265.2f, 3.05f },
    { -13866.9f, -13638.3f, 264.8f, 6.24f },
    { -13839.6f, -13614.5f, 266.3f, 3.05f },
    { -13870.5f, -13614.3f, 266.8f, 6.23f },
};
Position const tendonsPos[] =
{
    { -13862.6f, -13604.9f, 269.227f, 0.0f},
    { -13862.8f, -13645.0f, 265.752f, 0.0f},
    { -13862.6f, -13626.3f, 266.590f, 0.0f},
    { -13846.8f, -13644.7f, 265.789f, 0.0f},
    { -13846.6f, -13626.0f, 266.638f, 0.0f},
    { -13846.6f, -13604.7f, 269.174f, 0.0f},
};

class boss_spine_of_deathwing : public CreatureScript
{
public:
    boss_spine_of_deathwing() : CreatureScript("boss_spine_of_deathwing") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_spine_of_deathwingAI(creature);
    }

    struct boss_spine_of_deathwingAI : public BossAI
    {
        boss_spine_of_deathwingAI(Creature* creature) : BossAI(creature, DATA_SPINE), summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        uint32 step;
        float speed;
        bool platestep1;
        bool platestep2;
        bool leftSide;
        bool rightSide;

        void Reset() override
        {
            summons.DespawnAll();
            events.Reset();
            DespawnCreatures(NPC_SPAWNER, 500.0f);
            DespawnCreatures(NPC_CORRUPTED_BLOOD, 500.0f);
            DespawnCreatures(NPC_HIDEOUS_AMALGAMATION, 500.0f);

            if (GameObject* plate1 = me->FindNearestGameObject(GO_DEATHWING_BACK_PLATE_1, 500.0f))
                plate1->SetGoState(GO_STATE_READY);

            if (GameObject* plate2 = me->FindNearestGameObject(GO_DEATHWING_BACK_PLATE_2, 500.0f))
                plate2->SetGoState(GO_STATE_READY);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEGRADATION);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOOD_OF_NELTHARION);
            instance->SetBossState(DATA_SPINE, NOT_STARTED);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void DespawnCreatures(uint32 entry, float distance)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);

            platestep1 = false;
            platestep2 = false;
            leftSide = false;
            rightSide = false;

            for (uint32 x = 0; x <= 3; x++)
                me->SummonCreature(NPC_CORRUPTION, corrPos[x], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

            for (uint32 x = 0; x <= 2; x++)
                me->SummonCreature(NPC_BURNING_TENDONS_2, tendonsPos[x], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);

            for (uint32 x = 3; x <= 5; x++)
                me->SummonCreature(NPC_BURNING_TENDONS, tendonsPos[x], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);

            events.ScheduleEvent(EVENT_CHECK_CORRUPTION, 1000);
            events.ScheduleEvent(EVENT_PLATE, 1000);
            events.ScheduleEvent(EVENT_SIDE_CHECK, 15000);
            events.ScheduleEvent(EVENT_BLOOD_SPEED, 1000);
            events.ScheduleEvent(EVENT_TALK, 30000);
            events.ScheduleEvent(EVENT_SPAWN_BLOOD, 11000);
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_CORRUPTION:
                {
                    if (me->FindNearestCreature(NPC_CORRUPTION, 500.0f, true))
                    {
                        speed = 0.2f;
                        events.ScheduleEvent(EVENT_CHECK_CORRUPTION, 1000);
                    }
                    else
                    {
                        if (GameObject* plate1 = me->FindNearestGameObject(GO_DEATHWING_BACK_PLATE_1, 500.0f))
                        {
                            if (plate1->GetGoState() == GO_STATE_ACTIVE)
                            {
                                step = 3;
                                speed = 0.2f;
                            }

                            if (GameObject* plate2 = me->FindNearestGameObject(GO_DEATHWING_BACK_PLATE_2, 500.0f))
                            {
                                if (plate1->GetGoState() == GO_STATE_ACTIVE)
                                {
                                    if (plate2->GetGoState() == GO_STATE_READY)
                                    {
                                        step = 5;
                                        speed = 0.3f;
                                    }
                                    else
                                    {
                                        step = 7;
                                        speed = 0.4f;
                                    }
                                }
                            }
                        }

                        uint32 pos = urand(0, step);
                        me->SummonCreature(NPC_CORRUPTION, corrPos[pos], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

                        events.ScheduleEvent(EVENT_CHECK_CORRUPTION, 1000);
                    }
                }
                break;

                case EVENT_BLOOD_SPEED:
                {
                    std::list<Creature*> Blood;
                    me->GetCreatureListWithEntryInGrid(Blood, NPC_CORRUPTED_BLOOD, 300.0f);
                    for (std::list<Creature*>::iterator itr = Blood.begin(); itr != Blood.end(); ++itr)
                    {
                        if ((*itr)->HasAura(SPELL_RESIDUE))
                        {
                            (*itr)->SetSpeed(MOVE_WALK, speed);
                            (*itr)->SetSpeed(MOVE_RUN, speed);
                        }
                        else
                        {
                            (*itr)->SetSpeed(MOVE_WALK, 1.0f);
                            (*itr)->SetSpeed(MOVE_RUN, 1.0f);
                        }
                    }

                    events.ScheduleEvent(EVENT_BLOOD_SPEED, 500);
                }
                    break;

                case EVENT_PLATE:
                {
                    if (GameObject* plate2 = me->FindNearestGameObject(GO_DEATHWING_BACK_PLATE_2, 500.0f))
                    {
                        if (plate2->GetGoState() == GO_STATE_READY)
                        {
                            if (GameObject* plate1 = me->FindNearestGameObject(GO_DEATHWING_BACK_PLATE_1, 500.0f))
                            {
                                if (plate1->GetGoState() == GO_STATE_ACTIVE)
                                {
                                    if (platestep1 == false)
                                    {
                                        platestep1 = true;
                                        for (uint32 x = 4; x <= 5; x++)
                                            me->SummonCreature(NPC_CORRUPTION, corrPos[x], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (platestep2 == false)
                            {
                                platestep2 = true;
                                for (uint32 x = 6; x <= 7; x++)
                                    me->SummonCreature(NPC_CORRUPTION, corrPos[x], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_PLATE, 1000);
                }
                    break;

                case EVENT_SPAWN_BLOOD:
                {
                    std::list<Creature*> Spawner;
                    me->GetCreatureListWithEntryInGrid(Spawner, NPC_SPAWNER, 100.0f);
                    Trinity::Containers::RandomResize(Spawner, 1);
                    for (std::list<Creature*>::iterator itr = Spawner.begin(); itr != Spawner.end(); ++itr)
                    {
                        (*itr)->SummonCreature(NPC_CORRUPTED_BLOOD, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    }

                    events.ScheduleEvent(EVENT_SPAWN_BLOOD, 11000);
                }
                    break;

                case EVENT_SIDE_CHECK:
                {
                    float rightPos = -13850.0f;
                    float leftPos = -13860.0f;

                    std::list<Player*> players;
                    std::list<Player*> left;
                    std::list<Player*> right;
                    me->GetPlayerListInGrid(players, 500.0f);

                    for (std::list<Player*>::const_iterator iter = players.begin(); iter != players.end(); ++iter)
                    {
                        if ((*iter)->ToPlayer())
                        {
                            if ((*iter)->GetPositionX() <= leftPos)
                                left.push_back((*iter));
                            else if ((*iter)->GetPositionX() >= rightPos)
                                right.push_back((*iter));
                        }
                    }

                    if (left.size() == players.size())
                    {
                        if (leftSide != true)
                            events.RescheduleEvent(EVENT_ROLL_LEFT, 1000);
                    }
                    else if (right.size() == players.size())
                    {
                        if (rightSide != true)
                            events.RescheduleEvent(EVENT_ROLL_RIGHT, 1000);
                    }
                    else
                    {
                        events.CancelEvent(EVENT_BARREL_ROLL);
                        leftSide = false;
                        rightSide = false;
                    }

                    events.ScheduleEvent(EVENT_SIDE_CHECK, 1100);
                }
                    break;

                case EVENT_ROLL_LEFT:
                    leftSide = true;
                    rightSide = false;
                    Talk(SAY_FEEL_LEFT);

                    events.RescheduleEvent(EVENT_BARREL_ROLL, 5000);
                        break;

                case EVENT_ROLL_RIGHT:
                    rightSide = true;
                    leftSide = false;
                    Talk(SAY_FEEL_RIGHT);

                    events.RescheduleEvent(EVENT_BARREL_ROLL, 5000);
                    break;

                case EVENT_BARREL_ROLL:
                {
                    if (leftSide == true)
                        Talk(SAY_ROLL_LEFT);
                    else if (rightSide == true)
                        Talk(SAY_ROLL_RIGHT);

                    leftSide = false;
                    rightSide = false;

                    std::list<Creature*> Amalgamations;
                    me->GetCreatureListWithEntryInGrid(Amalgamations, NPC_HIDEOUS_AMALGAMATION, 300.0f);
                    for (std::list<Creature*>::iterator itr = Amalgamations.begin(); itr != Amalgamations.end(); ++itr)
                    {
                        (*itr)->SetReactState(REACT_PASSIVE);
                        (*itr)->SetSpeed(MOVE_WALK, 8.0f);
                        (*itr)->SetSpeed(MOVE_RUN, 8.0f);
                        (*itr)->GetMotionMaster()->MovePoint(0, rollPos);
                        (*itr)->DespawnOrUnsummon(2000);
                    }

                    std::list<Player*> targets;
                    me->GetPlayerListInGrid(targets, 500.0f);

                    for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        if ((*itr)->GetAura(SPELL_GRASPING_TENDRILS_AURA) ||
                            (*itr)->GetAura(109454) ||
                            (*itr)->GetAura(109455) ||
                            (*itr)->GetAura(109456) ||
                            (*itr)->GetAura(SPELL_FIERY_GRIP) ||
                            (*itr)->GetAura(109457) ||
                            (*itr)->GetAura(109458) ||
                            (*itr)->GetAura(109459))
                            return;

                        (*itr)->GetMotionMaster()->MovePoint(0, rollPos);
                        (*itr)->SetSpeed(MOVE_WALK, 8.0f);
                        (*itr)->SetSpeed(MOVE_RUN, 8.0f);
                    }
                }
                    break;

                case EVENT_TALK:
                    Talk(SAY_TEXT);

                    events.ScheduleEvent(EVENT_TALK, 30000);
                    break;
                default:
                    break;
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetBossState(DATA_SPINE, DONE);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEGRADATION);
            DoCast(SPELL_PLAY_MOVIE_DEATHWING_3);
            summons.DespawnAll();
            DespawnCreatures(NPC_CORRUPTED_BLOOD, 500.0f);
            DespawnCreatures(NPC_HIDEOUS_AMALGAMATION, 500.0f);

            Map::PlayerList const& PlayerList = instance->instance->GetPlayers();
            for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
            {
                if (Player* player = itr->GetSource())
                {
                    player->TeleportTo(967, -12081.390625f, 12160.050781f, 30.60f, 6.03f);
                }
            }

            _JustDied();
        }
    };
};

class npc_spawner : public CreatureScript
{
public:
    npc_spawner() : CreatureScript("npc_spawner") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spawnerAI(creature);
    }

    struct npc_spawnerAI : public ScriptedAI
    {
        npc_spawnerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            DoZoneInCombat(me);
            me->AddAura(SPELL_GRASPING_TENDRILS, me);
            me->SetReactState(REACT_PASSIVE);

            events.ScheduleEvent(EVENT_SPAWN_BLOOD, urand(20000, 36000));
        }
    };
};

class npc_corrupted_blood : public CreatureScript
{
public:
    npc_corrupted_blood() : CreatureScript("npc_corrupted_blood") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corrupted_bloodAI(creature);
    }

    struct npc_corrupted_bloodAI : public ScriptedAI
    {
        npc_corrupted_bloodAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Position pos;

        void InitializeAI() override
        {
            DoZoneInCombat(me);
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_ABSORBED_BLOOD)
            {
                me->DespawnOrUnsummon();
            }
        }

        void DamageTaken(Unit* /*who*/, uint32&damage) override
        {
            if (!me || !me->IsAlive() || me->HasAura(SPELL_RESIDUE))
                return;

            if ((me->GetHealth()) < (me->GetHealth() - damage))
            {
                damage = 0;
                DoCast(me, SPELL_RESIDUE);
                DoCast(me, SPELL_BURST);
                DoCast(me, SPELL_ABSORB_BLOOD_PERIODIC);

                me->SetReactState(REACT_PASSIVE);
                me->CombatStop();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);

                events.ScheduleEvent(EVENT_FIND_HOLE, 500);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FIND_HOLE:
                    if (Creature* spawner = me->FindNearestCreature(NPC_SPAWNER, 100.0f, true))
                    {
                        pos = spawner->GetPosition();
                        me->GetMotionMaster()->MovePoint(0, pos);

                        if (me->GetDistance(spawner) >= 0.2f)
                            events.ScheduleEvent(EVENT_FIND_HOLE, 1000);
                        else
                        {
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoZoneInCombat(me);
                            me->RemoveAllAuras();
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                            events.CancelEvent(EVENT_FIND_HOLE);
                        }
                    }
                    else
                        events.ScheduleEvent(EVENT_FIND_HOLE, 1000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_hideous_amalgamation : public CreatureScript
{
public:
    npc_hideous_amalgamation() : CreatureScript("npc_hideous_amalgamation") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hideous_amalgamationAI(creature);
    }

    struct npc_hideous_amalgamationAI : public ScriptedAI
    {
        npc_hideous_amalgamationAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint32 stacks;

        void InitializeAI() override
        {
            DoZoneInCombat(me);

            if (IsHeroic())
                events.ScheduleEvent(EVENT_BLOOD_CORRUPTION, 8000);
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_NUCLEAR_BLAST_TENDON)
            {
                if (Creature* tendon1 = me->FindNearestCreature(NPC_BURNING_TENDONS, 8.0f, true))
                    tendon1->AI()->DoAction(ACTION_MOVE);
                else if (Creature* tendon2 = me->FindNearestCreature(NPC_BURNING_TENDONS_2, 8.0f, true))
                    tendon2->AI()->DoAction(ACTION_MOVE);
                me->Kill(me);
            }
        }

        void SpellHit(Unit* /*unit*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_ABSORBED_BLOOD)
            {
                if (Aura * absorbed = me->GetAura(SPELL_ABSORBED_BLOOD))
                {
                    stacks = absorbed->GetStackAmount();

                    if (stacks == 9)
                        me->CastSpell(me, SPELL_SUPERHEATED_NUCLEUS);
                }
            }
        }

        void DamageTaken(Unit* /*who*/, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
            {
                damage = 0;
                return;
            }

            if ((me->GetHealth()) < (me->GetHealth() - damage))
            {
                if (stacks == 9)
                {
                    damage = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->CastSpell(me, SPELL_NUCLEAR_BLAST);
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BLOOD_CORRUPTION:
                {
                    DoCast(me, SPELL_BLOOD_CORRUPTION_DEATH);
                }
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Aura * absorbed = me->GetAura(SPELL_ABSORBED_BLOOD))
            {
                stacks = absorbed->GetStackAmount();

                if (stacks == 9)
                    DoCast(SPELL_NUCLEAR_BLAST_TENDON);
            }

            if (IsHeroic())
                DoCast(me, SPELL_DEGRADATION);
        }
    };
};

class npc_tendon : public CreatureScript
{
public:
    npc_tendon() : CreatureScript("npc_tendon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tendonAI(creature);
    }

    struct npc_tendonAI : public BossAI
    {
        npc_tendonAI(Creature* creature) : BossAI(creature, DATA_SPINE)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset() override
        {
            _Reset();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
        }

        void InitializeAI() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
            me->SetReactState(REACT_PASSIVE);

            events.ScheduleEvent(EVENT_PLATE_CHECK, 500);
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_SEAL_ARMOR_BREACH)
            {
                me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ() + 0.5f, me->GetHomePosition().GetOrientation());
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);

                events.ScheduleEvent(EVENT_PLATE_CHECK, 500);
            }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_MOVE:
                float ori = 4.74f;
                DoZoneInCombat(me);
                me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + 8 * cos(ori), me->GetPositionY() + 8 * sin(ori), me->GetPositionZ(), me->GetOrientation());

                events.CancelEvent(EVENT_PLATE_CHECK);
                events.ScheduleEvent(EVENT_SEAL_ARMOR, 5000);
                break;
            }
        }

        void UpdateAI(uint32 diff) override

        {

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SEAL_ARMOR:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                    DoCast(me, SPELL_SEAL_ARMOR_BREACH);
                    break;

                case EVENT_PLATE_CHECK:
                    if (GameObject* plate = me->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_DOOR, 50.0f))
                        if (plate->GetGoState() == GO_STATE_ACTIVE)
                            me->DespawnOrUnsummon();
                    events.ScheduleEvent(EVENT_PLATE_CHECK, 500);
                    break;
                default:
                    break;
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ() + 0.5f, me->GetHomePosition().GetOrientation());

            if (GameObject* plate = me->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_DOOR, 50.0f))
                plate->SetGoState(GO_STATE_ACTIVE);

            if (Creature* dwing = me->FindNearestCreature(NPC_SPINE_OF_DEATHWING, 500.0f, true))
            {
                dwing->AI()->Talk(SAY_BACKPLATE);
                me->DealDamage(dwing, dwing->GetMaxHealth() * 0.35);
            }
            _JustDied();
        }
    };
};

class npc_corruption : public CreatureScript
{
public:
    npc_corruption() : CreatureScript("npc_corruption") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corruptionAI(creature);
    }

    struct npc_corruptionAI : public ScriptedAI
    {
        npc_corruptionAI(Creature* creature) : ScriptedAI(creature), summons(me), vehicle(creature->GetVehicleKit())
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        Vehicle* vehicle;
        Position pos;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            DoZoneInCombat(me);

            if (Creature* spawner = me->FindNearestCreature(NPC_SPAWNER, 2.0f, true))
                spawner->DespawnOrUnsummon();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_SKY_CAPTAIN_SWAYZE)
                summon->AI()->Talk(SAY_SWAYZE_INTRO_SPINE);
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            vehicle = me->GetVehicleKit();

            if (me->GetPositionX() == corrPos[0].GetPositionX())
            {
                vehicle->InstallAccessory(NPC_SKY_CAPTAIN_SWAYZE, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 15000);
                events.ScheduleEvent(EVENT_INTRO, 8000);
            }

            if (me->GetPositionX() == corrPos[1].GetPositionX())
                vehicle->InstallAccessory(NPC_KAANU_REEVS, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 15000);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_FIERY_GRIP, urand(7000, 22000));
            events.ScheduleEvent(EVENT_SEARING_PLASMA, 18000);
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INTRO:
                        if (Creature* pass = me->FindNearestCreature(NPC_SKY_CAPTAIN_SWAYZE, 5.0f, true))
                        {
                            pass->ExitVehicle();
                            pass->SetSpeed(MOVE_WALK, 8.0f);
                            pass->SetSpeed(MOVE_RUN, 8.0f);
                            pass->GetMotionMaster()->MovePoint(0, rollPos);
                            pass->AI()->Talk(SAY_SWAYZE_INTRO_SPINE_1);
                        }
                    break;

                case EVENT_FIERY_GRIP:
                    DoCast(me, SPELL_FIERY_GRIP);

                    events.ScheduleEvent(EVENT_FIERY_GRIP, urand(10000, 22000));
                    break;

                case EVENT_SEARING_PLASMA:
                    DoCast(me, SPELL_SEARING_PLASMA_DUMMY);

                    events.ScheduleEvent(EVENT_SEARING_PLASMA, 15000);
                    break;
                default:
                    break;
                }
            }
        }

        void DamageTaken(Unit* /*who*/, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;

            if (damage >= (me->GetHealth() * 0.2f))
            {
                me->CastStop(SPELL_SEARING_PLASMA_DUMMY);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->SummonCreature(NPC_HIDEOUS_AMALGAMATION, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            me->SummonCreature(NPC_SPAWNER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
        }
    };
};

class spell_fiery_grip : public SpellScriptLoader
{

public:
    spell_fiery_grip() : SpellScriptLoader("spell_fiery_grip") { }

    class spell_fiery_grip_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_fiery_grip_SpellScript);

        void FilterStun(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
            DamageTarget = targets;
        }

        void FilterDamage(std::list<WorldObject*>& targets)
        {
            targets = DamageTarget;
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fiery_grip_SpellScript::FilterStun, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fiery_grip_SpellScript::FilterDamage, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
        std::list<WorldObject*> DamageTarget;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_fiery_grip_SpellScript();
    }
};

class spell_searing_plasma : public SpellScriptLoader
{

public:
    spell_searing_plasma() : SpellScriptLoader("spell_searing_plasma") { }

    class spell_searing_plasma_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_searing_plasma_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if ((GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_10_N) ||
                (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_10_HC))
                Trinity::Containers::RandomResize(targets, 1);
            else if ((GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_N) ||
                     (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC))
                Trinity::Containers::RandomResize(targets, 3);
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_SEARING_PLASMA);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_searing_plasma_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_searing_plasma_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_searing_plasma_SpellScript();
    }
};

class spell_absorb_blood : public SpellScriptLoader
{

public:
    spell_absorb_blood() : SpellScriptLoader("spell_absorb_blood") { }

    class spell_absorb_blood_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_absorb_blood_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_ABSORB_BLOOD_DUMMY))
                return false;
            return true;
        }


        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* amalga = GetUnitOwner()->FindNearestCreature(NPC_HIDEOUS_AMALGAMATION, 2.0f, true))
                GetUnitOwner()->CastSpell(amalga, SPELL_ABSORBED_BLOOD);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_absorb_blood_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_absorb_blood_AuraScript();
    }
};

class spell_nuclear_blast : public SpellScriptLoader
{
public:
    spell_nuclear_blast() : SpellScriptLoader("spell_nuclear_blast") { }

    class spell_nuclear_blast_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_nuclear_blast_SpellScript);

        void HandleOnCast()
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_NUCLEAR_BLAST_TENDON);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_nuclear_blast_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_nuclear_blast_SpellScript();
    }
};

class spell_plate : public SpellScriptLoader
{
public:
    spell_plate() : SpellScriptLoader("spell_plate") { }

    class spell_plate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_plate_SpellScript);

        void HandleActivate(SpellEffIndex index)
        {
            if ( GetCaster())
            {
                if (GetHitGObj())
                {
                    PreventHitDefaultEffect(index);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_plate_SpellScript::HandleActivate, EFFECT_0, SPELL_EFFECT_ACTIVATE_OBJECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_plate_SpellScript();
    }
};

class spell_blood_corruption_death : public SpellScriptLoader
{
public:
    spell_blood_corruption_death() : SpellScriptLoader("spell_blood_corruption_death") { }

    class spell_blood_corruption_death_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_blood_corruption_death_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                float centerPos = -13855.0f;

                std::list<Player*> players;
                std::list<WorldObject*> left;
                std::list<WorldObject*> right;
                caster->GetPlayerListInGrid(players, 500.0f);

                for (std::list<Player*>::const_iterator iter = players.begin(); iter != players.end(); ++iter)
                {
                    if ((*iter)->GetPositionX() <= centerPos)
                    {
                        left.push_back((*iter));
                        if ((*iter)->GetAura(SPELL_BLOOD_CORRUPTION_DEATH) || (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_EARTH))
                            targets = right;
                    }
                    else if ((*iter)->GetPositionX() >= centerPos)
                    {
                        right.push_back((*iter));
                        if ((*iter)->GetAura(SPELL_BLOOD_CORRUPTION_DEATH) || (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_EARTH))
                            targets = left;
                    }
                }

                if (left.empty())
                    targets = right;
                else if (right.empty())
                    targets = left;

                Trinity::Containers::RandomResize(targets, 1);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blood_corruption_death_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_blood_corruption_death_SpellScript();
    }

    class spell_blood_corruption_death_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_blood_corruption_death_AuraScript);

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            //aurEff->GetBase()->SetDuration(GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue());
        }

        void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
                if (Unit* owner = GetUnitOwner())
                {
                    if (Creature* dwing = owner->FindNearestCreature(NPC_SPINE_OF_DEATHWING, 500.0f, true))
                    {

                        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                        {
                            _duration = aurEff->GetBase()->GetDuration();

                            uint32 spell_id = roll_chance_i(35) ? SPELL_BLOOD_CORRUPTION_EARTH : SPELL_BLOOD_CORRUPTION_DEATH;

                            dwing->CastSpell(dwing, spell_id);

                            std::list<Player*> targets;
                            dwing->GetPlayerListInGrid(targets, 500.0f);

                            for (std::list<Player*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                            {
                                if (Aura* death = (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_DEATH))
                                    death->SetDuration(_duration);
                                else if (Aura* earth = (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_EARTH))
                                    earth->SetDuration(_duration);
                            }
                        }
                        else if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                            owner->CastSpell(owner, SPELL_BLOOD_OF_DEATHWING);
                    }
                }
        }
    private:
        uint32 _duration;

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_blood_corruption_death_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_blood_corruption_death_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_blood_corruption_death_AuraScript();
    }
};

class spell_blood_corruption_earth : public SpellScriptLoader
{
public:
    spell_blood_corruption_earth() : SpellScriptLoader("spell_blood_corruption_earth") { }

    class spell_blood_corruption_earth_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_blood_corruption_earth_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                float centerPos = -13855.0f;

                std::list<Player*> players;
                std::list<WorldObject*> left;
                std::list<WorldObject*> right;
                caster->GetPlayerListInGrid(players, 500.0f);

                for (std::list<Player*>::const_iterator iter = players.begin(); iter != players.end(); ++iter)
                {
                    if ((*iter)->GetPositionX() <= centerPos)
                    {
                        left.push_back((*iter));
                        if ((*iter)->GetAura(SPELL_BLOOD_CORRUPTION_DEATH) || (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_EARTH))
                            targets = right;
                    }
                    else if ((*iter)->GetPositionX() >= centerPos)
                    {
                        right.push_back((*iter));
                        if ((*iter)->GetAura(SPELL_BLOOD_CORRUPTION_DEATH) || (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_EARTH))
                            targets = left;
                    }
                }

                if (left.empty())
                    targets = right;
                else if (right.empty())
                    targets = left;

                Trinity::Containers::RandomResize(targets, 1);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blood_corruption_earth_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_blood_corruption_earth_SpellScript();
    }

    class spell_blood_corruption_earth_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_blood_corruption_earth_AuraScript);

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            //aurEff->GetBase()->SetDuration(GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue());
        }

        void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
                if (Unit* owner = GetUnitOwner())
                {
                    if (Creature* dwing = owner->FindNearestCreature(NPC_SPINE_OF_DEATHWING, 500.0f, true))
                    {

                        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                        {
                            _duration = aurEff->GetBase()->GetDuration();

                            uint32 spell_id = roll_chance_i(35) ? SPELL_BLOOD_CORRUPTION_EARTH : SPELL_BLOOD_CORRUPTION_DEATH;

                            dwing->CastSpell(dwing, spell_id);

                            std::list<Player*> targets;
                            dwing->GetPlayerListInGrid(targets, 500.0f);

                            for (std::list<Player*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                            {
                                if (Aura* death = (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_DEATH))
                                    death->SetDuration(_duration);
                                else if (Aura* earth = (*iter)->GetAura(SPELL_BLOOD_CORRUPTION_EARTH))
                                    earth->SetDuration(_duration);
                            }
                        }
                        else if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                            owner->CastSpell(owner, SPELL_BLOOD_OF_NELTHARION);
                    }
                }
        }
    private:
        uint32 _duration;

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_blood_corruption_earth_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_blood_corruption_earth_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_blood_corruption_earth_AuraScript();
    }
};

void AddSC_boss_spine_of_deathwing()
{
    new boss_spine_of_deathwing();
    new npc_spawner();
    new npc_corrupted_blood();
    new npc_hideous_amalgamation();
    new npc_tendon();
    new npc_corruption();
    new spell_fiery_grip();
    new spell_searing_plasma();
    new spell_absorb_blood();
    new spell_nuclear_blast();
    new spell_plate();
    new spell_blood_corruption_death();
    new spell_blood_corruption_earth();
}
