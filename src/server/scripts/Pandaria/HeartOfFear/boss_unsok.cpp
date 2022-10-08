/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "heart_of_fear.h"

enum eUnsokSpells
{
    // --- Un'sok ---
    SPELL_AMBER_SCALPEL         = 121994,
    SPELL_CONCENTRATED_MUTATION = 122556,
    SPELL_DRAW_POWER            = 122547,
    SPELL_PARASITIC_GROWTH      = 121949,
    SPELL_RESHAPED              = 122784,
    SPELL_AMBER_CARAPACE        = 122540,
    SPELL_VOLATILE_AMBER        = 123014,
    SPELL_GROW                  = 122555,
    SPELL_UNSOK_BERSERK         = 26662,

    // --- Adds ---
    SPELL_FIXATE                = 122477,
    SPELL_LIVING_AMBER_DEBUFF   = 64481,
    SPELL_PERMANENT_FEIGN_DEATH = 70628,    // Can't resurrect
    SPELL_TEMP_FEIGN_DEATH      = 126009,   // Can resurrect
    SPELL_RESURRECT             = 58854,
    SPELL_CLEAR_DEBUFF          = 34098,
    SPELL_BURNING_AMBER         = 122503,   // Create a burning amber area, triggers 122504 dealing damages

    // --- Mutated Construct ---
    SPELL_CONSUME_AMBER         = 123156,
    SPELL_AMBER_EXPLOSION       = 122398,
    SPELL_MUTATED_EXPLOSION     = 122402,
    SPELL_MUTATED_SLAM          = 122960,

    // --- Amber Monstruosity ---
    SPELL_MASSIVE_STOMP         = 122408,
    SPELL_MSTR_EXPLOSION        = 122402,
    SPELL_RIDE_MONSTRUOSITY     = 43671,
    SPELL_GRAB                  = 122415,
    SPELL_FLING                 = 122413,
    SPELL_FLING_FLYING          = 122420,
    SPELL_FLING_LANDING         = 122457,

    // --- Amber Pool Stallker ---
    SPELL_BUBBLING_AMBER        = 122977,
    SPELL_POOL_DRAW_POWER       = 122551,
    SPELL_BURNING_POOL          = 123020,
    SPELL_HEAL_MUTATED          = 123198,

    // --- Amber Globule ---
    SPELL_AMBER_GLOBULE         = 125498,
    SPELL_AMBER_BEACON          = 125502,
    SPELL_AMBERGEDDON           = 125508,

    SPELL_UNSOK_BONUS           = 132198
};

enum eUnsokEvents
{
    EVENT_UNSOK_BERSERK = 1,
    EVENT_AMBER_SCALPEL,
    EVENT_PARASITIC_GROWTH,
    EVENT_RESHAPE_LIFE,
    EVENT_RESHAPE_ACTIVE,
    EVENT_VOLATILE_AMBER,
    EVENT_AMBER_RESURRECT,
    EVENT_CHECK_MUTATED,
    EVENT_AMBER_EXPLOSION,
    EVENT_MASSIVE_STOMP,
    EVENT_GRAB,
    EVENT_FLING,
    EVENT_GROW,
    EVENT_DRAW_POWER,
    EVENT_AMBER_GLOBULE,
    EVENT_BERSERK,
    EVENT_SCALPEL_DESPAWN
};

enum eUnsokTalk
{
    TALK_INTRO      = 0,
    TALK_AGGRO      = 1,
    TALK_SCALPEL    = 2,
    TALK_RESHAPE    = 3,
    TALK_RESHAPE2   = 4,
    TALK_PHASE2     = 5,
    TALK_PHASE3     = 6,
    TALK_SLAY       = 7,
    TALK_DEATH      = 8
};

enum eUnsokActions
{
    ACTION_UNSOK_LAST_PHASE = 1,
    ACTION_AMBER_POOL,
    ACTION_END_POOL,
    ACTION_AMBER_CONSUMED,
    ACTION_LAUNCH_LAST_PHASE
};

enum eUnsokAdds
{
    NPC_AMBER_SCALPEL               = 62510,
    NPC_LIVING_AMBER                = 62691,
    NPC_MUTATED_CONSTRUCT           = 62701,
    NPC_AMBER_MONSTRUOSITY          = 62711,
    NPC_AMBER_POOL_STALKER          = 62762,
    NPC_AMBER_GLOBULE               = 64283
};

enum eUnsokTypes
{
    TYPE_GET_SCALPEL_TARGET         = 1
};

Position spawnAmberMonstruosity = {-2549.87f, 770.0f, 582.92f, 0.0f};
Position roomCenter =             {-2479.44f, 700.0f, 580.10f, 0.0f};

Position poolPositionsTab[4] =
{
    {-2409.33f, 630.0f, 582.92f, 0.0f},
    {-2549.87f, 770.0f, 582.92f, 0.0f},
    {-2409.33f, 770.0f, 582.92f, 0.0f},
    {-2549.87f, 630.0f, 582.92f, 0.0f}
};

// 62511 - Amber-Shaper Un'sok
class boss_unsok : public CreatureScript
{
    public:
        boss_unsok() : CreatureScript("boss_unsok") { }

        struct boss_unsokAI : public BossAI
        {
            boss_unsokAI(Creature* creature) : BossAI(creature, DATA_UNSOK)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            uint8 phase;
            uint8 growth;
            ObjectGuid reshapedGuid;
            uint32 scalpelTargetGuid;
            bool fightInProgress;
            bool checkMutated;
            bool introDone;

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();
                phase = 0;
                growth = 0;
                reshapedGuid = ObjectGuid::Empty;
                scalpelTargetGuid = 0;
                fightInProgress = false;
                checkMutated = false;
                introDone = false;

                me->SetVirtualItem(0, EQUIP_UNSOK);
                me->SetReactState(REACT_PASSIVE);
            }

            bool CheckTrash()
            {
                if (GetClosestCreatureWithEntry(me, NPC_COAGULATED_AMBER,   200.0f, true) ||
                    GetClosestCreatureWithEntry(me, NPC_COAGULATED_AMBER2,  200.0f, true) ||
                    GetClosestCreatureWithEntry(me, NPC_LIVING_AMBER,       200.0f, true) ||
                    GetClosestCreatureWithEntry(me, NPC_SRATHIK_POOLTENDER, 200.0f, true))
                    return false;
                return true;
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
                summons.DespawnAll();
                phase = 0;
                growth = 0;
                reshapedGuid = ObjectGuid::Empty;
                scalpelTargetGuid = 0;
                fightInProgress = false;
                checkMutated = false;
                introDone = false;
                me->RemoveAllAuras();
                Talk(TALK_DEATH);
                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RESHAPE_LIFE);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARASITIC_GROWTH);
                    pInstance->SetData(DATA_UNSOK, DONE);
                }

                // Stopping amber pools
                std::list<Creature*> poolList;
                GetCreatureListWithEntryInGrid(poolList, me, NPC_AMBER_POOL_STALKER, 200.0f);

                for (Creature* pool : poolList)
                    pool->AI()->DoAction(ACTION_END_POOL);

                // Opening doors
                if (GameObject* entranceDoor = pInstance->GetGameObject(GOB_SANCTUM_DOOR_ENTRANCE))
                    entranceDoor->SetGoState(GO_STATE_ACTIVE);
                if (GameObject* exitDoor = pInstance->GetGameObject(GOB_HEARTOFFEAR_DOOR_ENTRANCE))
                    exitDoor->SetGoState(GO_STATE_ACTIVE);

                _JustDied();

                Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                {
                    if (Player* l_Player = l_Itr->GetSource())
                        me->CastSpell(l_Player, SPELL_UNSOK_BONUS, true);
                }

                /*if (me->GetMap()->IsLFR())
                {
                    me->ResetLootRecipients();
                    Player* l_Player = me->GetMap()->GetPlayers().begin()->GetSource();
                    if (l_Player && l_Player->GetGroup())
                        sLFGMgr->AutomaticLootAssignation(me, l_Player->GetGroup());
                }*/
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (!CheckTrash() || (!instance->CheckRequiredBosses(DATA_UNSOK) && !IsLFR()))
                {
                    me->SetFullHealth();
                    me->SetReactState(REACT_PASSIVE);
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    if (fightInProgress)
                        fightInProgress = false;
                    return;
                }

                fightInProgress = true;
                phase = 1;
                me->SetReactState(REACT_AGGRESSIVE);
                Talk(TALK_AGGRO);

                events.ScheduleEvent(EVENT_BERSERK, 540000); // 9 minutes timer
                events.ScheduleEvent(EVENT_AMBER_SCALPEL, 15000);
                events.ScheduleEvent(EVENT_PARASITIC_GROWTH, 10000);
                events.ScheduleEvent(EVENT_RESHAPE_LIFE, 40000);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                events.Reset();
                summons.DespawnAll();
                phase = 0;
                reshapedGuid = ObjectGuid::Empty;
                scalpelTargetGuid = 0;
                growth = 0;
                fightInProgress = false;
                checkMutated = false;
                introDone = false;
                me->SetFullHealth();
                me->RemoveAllAuras();
                me->GetMotionMaster()->MoveTargetedHome();
                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RESHAPE_LIFE);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARASITIC_GROWTH);
                    pInstance->SetData(DATA_UNSOK, TO_BE_DECIDED);
                }

                // Stopping amber pools
                std::list<Creature*> poolList;
                GetCreatureListWithEntryInGrid(poolList, me, NPC_AMBER_POOL_STALKER, 200.0f);

                for (Creature* pool : poolList)
                    pool->AI()->DoAction(ACTION_END_POOL);
            }

            void JustReachedHome() override
            {
                if (pInstance)
                    if (pInstance->GetData(DATA_UNSOK) == TO_BE_DECIDED)
                        pInstance->SetData(DATA_UNSOK, FAIL);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->IsPlayer())
                    Talk(TALK_SLAY);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (who->GetTypeId() != TYPEID_PLAYER || fightInProgress)
                    return;

                if (me->GetDistance(who) < 40.0f && !introDone)
                {
                    Talk(TALK_INTRO);
                    introDone = true;
                }

                if (!fightInProgress)
                    if (me->GetDistance(who) < 15.0f)
                        EnterCombat(who);
            }

            void DamageTaken(Unit* attacker, uint32 &damage) override
            {
                if (!fightInProgress)
                    EnterCombat(attacker);

                // Damage taken from mutated construct leads to a 40 loss of power for the mutated construct
                if (attacker->HasAura(SPELL_RESHAPE_LIFE) && attacker->IsPlayer())
                    attacker->ModifyPower(POWER_ALTERNATE_POWER, -40);

                if (phase == 1 && me->HealthBelowPctDamaged(70, damage))
                {
                    phase = 2;
                    Talk(TALK_PHASE2);
                    DoCast(SPELL_AMBER_CARAPACE);
                    me->SummonCreature(NPC_AMBER_MONSTRUOSITY, spawnAmberMonstruosity);
                }
            }

            void DoAction(const int32 action) override
            {
                // Amber monstruosity just died: it's a transition between phase 2 and 3 where Un'sok comes to the room's center
                if (action == ACTION_UNSOK_LAST_PHASE && phase == 2)
                {
                    phase = 3;
                    Talk(TALK_PHASE3);
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_AMBER_SCALPEL);

                    std::list<Creature*> poolList;
                    GetCreatureListWithEntryInGrid(poolList, me, NPC_AMBER_POOL_STALKER, 200.0f);

                    for (Creature* pool : poolList)
                        pool->AI()->DoAction(ACTION_AMBER_POOL);

                    me->GetMotionMaster()->MovePoint(1, roomCenter);
                }
                // Un'sok has cast Draw power; third phase really begins here
                else if (action == ACTION_LAUNCH_LAST_PHASE)
                {
                    me->RemoveAura(SPELL_AMBER_CARAPACE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->AddAura(SPELL_CONCENTRATED_MUTATION, me);
                    me->TextEmote("The nearby pools of Amber begin to bubble violently", 0, true);
                    events.RescheduleEvent(EVENT_RESHAPE_LIFE, 15000);
                    events.ScheduleEvent(EVENT_GROW, 250);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_AMBER_GLOBULE, 15000);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    DoCast(SPELL_DRAW_POWER);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == TYPE_GET_SCALPEL_TARGET)
                    return scalpelTargetGuid;
                return 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (!fightInProgress)
                    return;

                if (pInstance)
                {
                    if (pInstance->IsWipe())
                    {
                        EnterEvadeMode(EVADE_REASON_OTHER);
                        return;
                    }
                }

                if (!reshapedGuid && (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING)))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_AMBER_SCALPEL:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                            {
                                scalpelTargetGuid = target->GetGUID().GetCounter();
                                me->SummonCreature(NPC_AMBER_SCALPEL, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                            }

                            events.ScheduleEvent(EVENT_AMBER_SCALPEL, phase == 3 ? 15000 : 50000);
                            break;
                        }
                        case EVENT_PARASITIC_GROWTH:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                                me->CastSpell(target, SPELL_PARASITIC_GROWTH, true);
                            events.ScheduleEvent(EVENT_PARASITIC_GROWTH, 50000);
                            break;
                        }
                        case EVENT_RESHAPE_LIFE:
                        {
                            // Picking a target to turn into mutated construct
                            Unit* target = 0;

                            std::list<Player*> playerList;
                            GetPlayerListInGrid(playerList, me, 5000.0f);

                            bool canCast = true;

                            // We can't cast if there's no player
                            if (playerList.empty())
                                canCast = false;
                            else
                            {
                                // We can't cast if all players have already been turned into mutated construct,
                                // so we must find at least one non-transformed player to be able to cast Reshape Life
                                std::list<Player*>::iterator itr = playerList.begin();
                                canCast = false;
                                while (itr != playerList.end() && !canCast)
                                {
                                    if (!(*itr)->HasAura(SPELL_RESHAPE_LIFE))
                                        // In phase 1, can only be casted on tank
                                        if (phase > 1 || (*itr)->GetRoleForGroup() == Roles::ROLE_TANK)
                                            canCast = true;

                                    ++itr;
                                }
                            }

                            if (canCast)
                            {
                                uint8 l_Count = 0;
                                do
                                {
                                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5000.0f, true);
                                    if (target != nullptr)
                                        reshapedGuid = target->GetGUID();
                                    l_Count++;
                                } while ((!target || target->HasAura(SPELL_RESHAPE_LIFE)) && l_Count < 10);
                                Talk(TALK_RESHAPE);

                                if (target)
                                    me->CastSpell(target, SPELL_RESHAPED, false);
                                events.ScheduleEvent(EVENT_RESHAPE_ACTIVE, 1800);
                            }

                            if (phase < 3)
                                events.ScheduleEvent(EVENT_RESHAPE_LIFE, 50000);
                            break;
                        }
                        case EVENT_RESHAPE_ACTIVE:
                        {
                            // Turn target player into mutated construct
                            if (Unit* target = ObjectAccessor::FindPlayer(reshapedGuid))
                            {
                                Talk(TALK_RESHAPE2);
                                me->CastSpell(target, SPELL_RESHAPE_LIFE, true);
                                target->SetMaxPower(POWER_ALTERNATE_POWER, 100);
                                target->SetPower(POWER_ALTERNATE_POWER, target->GetMaxPower(POWER_ALTERNATE_POWER));
                            }
                            if (!checkMutated)
                            {
                                events.ScheduleEvent(EVENT_CHECK_MUTATED, 1000);
                                checkMutated = true;
                            }
                            reshapedGuid = ObjectGuid::Empty;
                            break;
                        }
                        case EVENT_CHECK_MUTATED:
                        {
                            // Every second, each mutated player loses 2 will points
                            std::list<Player*> playerList;
                            GetPlayerListInGrid(playerList, me, 5000.0f);

                            for (Player* player : playerList)
                            {
                                if (player->HasAura(SPELL_RESHAPE_LIFE))
                                {
                                    player->ModifyPower(POWER_ALTERNATE_POWER, -2);
                                    // If no will remains, player dies and mutated construct remains uncontrollable
                                    if (player->GetPower(POWER_ALTERNATE_POWER) <= 0)
                                    {
                                        me->Kill(player);
                                        me->SummonCreature(NPC_MUTATED_CONSTRUCT, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
                                    }
                                }
                            }

                            events.ScheduleEvent(EVENT_CHECK_MUTATED, 1000);
                            break;
                        }
                        case EVENT_AMBER_EXPLOSION:
                        {
                            // Retreiving players
                            std::list<Player*> mutatedList;
                            GetPlayerListInGrid(mutatedList, me, 200.0f);
                            std::list<Player*>::iterator itr = mutatedList.begin();
                            
                            bool search = true;
                            uint8 countMutated = 0;

                            // Picking a random mutated construct to cast amber explosion
                            while (search)
                            {
                                if ((*itr)->HasAura(SPELL_RESHAPE_LIFE))
                                {
                                    ++countMutated;
                                    if (urand(0, 1))
                                    {
                                        (*itr)->CastSpell(*itr, SPELL_AMBER_EXPLOSION, true);
                                        (*itr)->TextEmote("Against your will, you begin to unleash an |cffBA0022|Hspell:122398|h[Amber Explosion]|h|r", 0, true);
                                        search = false;
                                    }
                                }

                                ++itr;

                                if (itr == mutatedList.end())
                                {
                                    if (countMutated)
                                        itr = mutatedList.begin();
                                    // breaking the loop if none of the players is a mutated construct
                                    else
                                        search = false;
                                }
                            }

                            events.ScheduleEvent(EVENT_AMBER_EXPLOSION, urand(5000, 15000));
                            break;
                        }
                        case EVENT_GROW:
                        {
                            DoCast(me, SPELL_GROW);
                            if (++growth < 16)
                                events.ScheduleEvent(EVENT_GROW, 250);
                            break;
                        }
                        case EVENT_AMBER_GLOBULE:
                        {
                            uint8 globFirst  = urand(0, 3);
                            uint8 globSecond = urand(0, 3);

                            while (globFirst == globSecond)
                                globSecond = urand(0, 3);

                            me->SummonCreature(NPC_AMBER_GLOBULE, poolPositionsTab[globFirst]);
                            me->SummonCreature(NPC_AMBER_GLOBULE, poolPositionsTab[globSecond]);

                            events.ScheduleEvent(EVENT_AMBER_GLOBULE, urand(30000, 450000));
                            break;
                        }
                        case EVENT_UNSOK_BERSERK:
                        {
                            DoCast(me, SPELL_UNSOK_BERSERK);
                            break;
                        }
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_unsokAI(creature);
        }
};

// 62701 - Mutated Construct
class mob_mutated_construct : public CreatureScript
{
    public:
        mob_mutated_construct() : CreatureScript("mob_mutated_construct") { }

        struct mob_mutated_constructAI : public ScriptedAI
        {
            mob_mutated_constructAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_AMBER_EXPLOSION, 30000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_AMBER_EXPLOSION)
                {
                    me->TextEmote("The Amber Monstruosity readies an |cffBA0022|Hspell:122398|h[Amber Explosion]|h|r", 0, true);
                    DoCast(SPELL_MUTATED_EXPLOSION);
                    events.ScheduleEvent(EVENT_AMBER_EXPLOSION, 30000);
                }
                else
                    if (UpdateVictim())
                        me->CastSpell(me->GetVictim(), SPELL_MUTATED_SLAM, true);
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mutated_constructAI(creature);
        }
};

// 62711 - Amber Monstruosity
class mob_amber_monstruosity : public CreatureScript
{
    public:
        mob_amber_monstruosity() : CreatureScript("mob_amber_monstruosity") { }

        struct mob_amber_monstruosityAI : public ScriptedAI
        {
            mob_amber_monstruosityAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            ObjectGuid grabTargetGuid;

            void Reset() override
            {
                events.Reset();
                grabTargetGuid = ObjectGuid::Empty;
                events.ScheduleEvent(EVENT_MASSIVE_STOMP,   5000);
                events.ScheduleEvent(EVENT_GRAB,            10000);
                events.ScheduleEvent(EVENT_AMBER_EXPLOSION, 20000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* Unsok = pInstance->GetCreature(NPC_UNSOK))
                    Unsok->AI()->DoAction(ACTION_UNSOK_LAST_PHASE);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MASSIVE_STOMP:
                        {
                            DoCast(SPELL_MASSIVE_STOMP);
                            events.ScheduleEvent(EVENT_MASSIVE_STOMP, 20000);
                            break;
                        }
                        case EVENT_AMBER_EXPLOSION:
                        {
                            DoCast(SPELL_MSTR_EXPLOSION);
                            events.ScheduleEvent(EVENT_MASSIVE_STOMP, 50000);
                            break;
                        }
                        case EVENT_GRAB:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            {
                                me->CastSpell(target, SPELL_GRAB, true);
                                grabTargetGuid = target->GetGUID();
                            }
                            events.ScheduleEvent(EVENT_FLING, 4000);
                            events.ScheduleEvent(EVENT_GRAB, 40000);
                            break;
                        }
                        case EVENT_FLING:
                        {
                            if (Unit* target = ObjectAccessor::GetUnit(*me, grabTargetGuid))
                                me->CastSpell(target, SPELL_FLING, true);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_amber_monstruosityAI(creature);
        }
};

// 62691 - Living Amber
class mob_living_amber : public CreatureScript
{
public:
    mob_living_amber() : CreatureScript("mob_living_amber") { }

    struct mob_living_amberAI : ScriptedAI
    {
        mob_living_amberAI(Creature* creature) : ScriptedAI(creature) { }

        ObjectGuid targetGuid;
        EventMap events;

        void Reset() override
        {
            events.Reset();
            targetGuid = ObjectGuid::Empty;
            DoCast(SPELL_CORROSIVE_AURA);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
            {
                targetGuid = target->GetGUID();
                DoCast(target, SPELL_FIXATE);
                DoCast(target, SPELL_LIVING_AMBER_DEBUFF);
            }
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_AMBER_CONSUMED)
            {
                me->RemoveAura(SPELL_BURNING_AMBER);
                events.CancelEvent(EVENT_AMBER_RESURRECT);
            }
        }

        void DamageTaken(Unit* /*p_Attacker*/, uint32 &p_Damage) override
        {
            if (me->HasAura(SPELL_TEMP_FEIGN_DEATH) || me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
            {
                p_Damage = 0;
                return;
            }

            if (p_Damage > me->GetHealth())
            {
                // False death
                p_Damage = me->GetHealth() - 1;
                me->SetReactState(REACT_PASSIVE);
                me->RemoveAurasDueToSpell(SPELL_CORROSIVE_AURA);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->CombatStop(true);
                DoCast(IsHeroic() ? SPELL_TEMP_FEIGN_DEATH : SPELL_PERMANENT_FEIGN_DEATH);
                // Removing debuff on initial target
                if (Player* target = ObjectAccessor::FindPlayer(targetGuid))
                    DoCast(target, SPELL_CLEAR_DEBUFF);

                // Explode
                DoCast(SPELL_BURST);

                // Burning amber area
                DoCast(SPELL_BURNING_AMBER);

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_AMBER_RESURRECT, 30000);
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);
            if (events.ExecuteEvent() == EVENT_AMBER_RESURRECT)
            {
                DoCast(me, SPELL_RESURRECT);
                me->RemoveAura(SPELL_BURNING_AMBER);
                me->SetReactState(REACT_AGGRESSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                Reset();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_living_amberAI(creature);
    }
};

// 62762 - Amber Pool Stalker
class mob_amber_pool_stalker : public CreatureScript
{
    public:
        mob_amber_pool_stalker() : CreatureScript("mob_amber_pool_stalker") { }

        struct mob_amber_pool_stalkerAI : public ScriptedAI
        {
            mob_amber_pool_stalkerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_AMBER_POOL)
                {
                    DoCast(SPELL_BUBBLING_AMBER);
                    DoCast(SPELL_POOL_DRAW_POWER);

                    events.ScheduleEvent(EVENT_DRAW_POWER, 2000);
                    events.ScheduleEvent(EVENT_VOLATILE_AMBER, 8000);
                }
                else if (action == ACTION_END_POOL)
                {
                    me->RemoveAllAuras();
                    events.Reset();
                    if (pInstance)
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VOLATILE_AMBER);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING) || !me->HasAura(SPELL_BUBBLING_AMBER))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_VOLATILE_AMBER:
                        {
                            std::list<Player*> playerList;
                            GetPlayerListInGrid(playerList, me, 200.0f);

                            // No player found
                            if (playerList.empty())
                            {
                                events.ScheduleEvent(EVENT_VOLATILE_AMBER, 3000);
                                break;
                            }
                    
                            Player* target = 0;

                            // More than 1 player found
                            if (playerList.size() > 1)
                            {
                                std::list<Player*>::iterator itr = playerList.begin();
                                while (!target)
                                {
                                    if (urand(0, 1))
                                        target = *itr;

                                    ++itr;

                                    if (itr == playerList.end())
                                        itr = playerList.begin();
                                }
                            }
                            // Only 1 target
                            else
                                target = playerList.front();

                            // So here, we have a target
                            DoCast(target, SPELL_VOLATILE_AMBER);
                            DoCast(SPELL_BURNING_POOL);

                            events.ScheduleEvent(EVENT_VOLATILE_AMBER, 3000);
                        }
                        case EVENT_DRAW_POWER:
                        {
                            if (Creature* Unsok = pInstance->GetCreature(NPC_UNSOK))
                                me->AddAura(SPELL_POOL_DRAW_POWER, Unsok);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_amber_pool_stalkerAI(creature);
        }
};

// 64283 - Amber Globule
class mob_amber_globule : public CreatureScript
{
    public:
        mob_amber_globule() : CreatureScript("mob_amber_globule") { }

        struct mob_amber_globuleAI : public ScriptedAI
        {
            mob_amber_globuleAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;
            ObjectGuid targetGuid;
            bool canExplode;

            void Reset() override
            {
                events.Reset();
                canExplode = true;
                me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_RUN, 1.0f);
                me->AddAura(SPELL_AMBER_GLOBULE, me);
                GetTarget();
            }

            // Sending to a target, or despawn if no player to target
            void GetTarget()
            {
                // Resetting target and movement
                targetGuid = ObjectGuid::Empty;
                me->GetMotionMaster()->Clear();
                
                Player* target = 0;

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 200.0f);

                // No player found: it's a wipe, so we despawn
                if (playerList.empty())
                {
                    me->DespawnOrUnsummon();
                    return;
                }
                // Else, we go through the list
                else
                {
                    std::list<Player*>::iterator itr, next;
                    itr = playerList.begin();
                    while (!targetGuid)
                    {
                        // Preparing next iteration
                        next = itr;
                        ++next;

                        if (next == playerList.end())
                            next = playerList.begin();

                        // If player is already marked
                        if ((*itr)->HasAura(SPELL_AMBER_BEACON))
                        {
                            // if other players remain, we remove him from the list to pick another player who possibly won't be marked
                            if (playerList.size() > 1)
                                playerList.remove(*itr);
                            // If only one player remains, we pick him as target
                            else if (playerList.size() == 1)
                            {
                                target = *itr;
                                targetGuid = target->GetGUID();
                            }
                            // No player remain in list (crash prevention, should not happen)
                            else
                            {
                                me->DespawnOrUnsummon();
                                return;
                            }
                        }
                        // Else: the player isn't marked, so we have a random chance to pick him as a target
                        else if (urand(0, 1))
                        {
                            target = *itr;
                            targetGuid = target->GetGUID();
                        }

                        itr = next;
                    }

                    DoCast(target, SPELL_AMBER_BEACON);
                    me->GetMotionMaster()->MoveChase(target);
                }
            }

            void UpdateAI(const uint32 /*p_Diff*/) override
            {
                // Checking if another Amber Globule is in contact - we need a list not to detect only itself
                std::list<Creature*> globuleList;
                GetCreatureListWithEntryInGrid(globuleList, me, NPC_AMBER_GLOBULE, 1.5f);

                if (!globuleList.empty())
                {
                    for (Creature* globule : globuleList)
                    {
                        if (globule != me)
                        {
                            me->GetMotionMaster()->Clear();
                            me->DespawnOrUnsummon();

                            globule->GetMotionMaster()->Clear();
                            me->RemoveAura(SPELL_AMBER_GLOBULE);
                            globule->DespawnOrUnsummon(3000);
                        }
                    }
                }

                // Checking if has reached target
                if (canExplode)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGuid))
                    {
                        if (target->IsPlayer() && target->IsWithinDist2d(me, 1.5f))
                        {
                            me->GetMotionMaster()->Clear();
                            DoCast(SPELL_AMBERGEDDON);
                            // prevent globule to explode several times
                            canExplode = false;
                            me->RemoveAura(SPELL_AMBER_GLOBULE);
                            me->DespawnOrUnsummon(3000);
                        }
                    }
                    else
                        GetTarget();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_amber_globuleAI(creature);
        }
};

// 62510 - Amber Scalpel
class mob_amber_scalpel : public CreatureScript
{
    public:
        mob_amber_scalpel() : CreatureScript("mob_amber_scalpel") { }

        struct mob_amber_scalpelAI : public ScriptedAI
        {
            mob_amber_scalpelAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            uint32 targetGuid;

            void Reset() override
            {
                events.Reset();
                targetGuid = 0;
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(43164);
                me->SetFaction(2577);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                events.ScheduleEvent(EVENT_SCALPEL_DESPAWN, 11000);

                if (Creature* unsok = pInstance->GetCreature(NPC_UNSOK))
                {
                    targetGuid = unsok->AI()->GetData(TYPE_GET_SCALPEL_TARGET);
                    me->GetMotionMaster()->Clear();
                    if (Player* target = ObjectAccessor::FindPlayer(ObjectGuid::Create<HighGuid::Player>(targetGuid)))
                        me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);

                    unsok->AI()->Talk(TALK_SCALPEL);
                    unsok->CastSpell(me, SPELL_AMBER_SCALPEL, true);
                }
            }

            void UpdateAI(uint32 const diff) override
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_SCALPEL_DESPAWN)
                {
                    if (Creature* unsok = pInstance->GetCreature(NPC_UNSOK))
                    {
                        CAST_AI(boss_unsok::boss_unsokAI, unsok->GetAI())->scalpelTargetGuid = 0;
                        me->DespawnOrUnsummon();
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_amber_scalpelAI(creature);
        }
};

// 121995 - Amber Scalpel - Summoning Living Amber
class spell_amber_scalpel : public SpellScriptLoader
{
    public:
        spell_amber_scalpel() : SpellScriptLoader("spell_amber_scalpel")  { }

        class spell_amber_scalpel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_amber_scalpel_SpellScript);

            void Summon()
            {
                if (Creature* l_Caster = GetCaster()->ToCreature())
                {
                    if (Creature* l_Scalpel = GetClosestCreatureWithEntry(l_Caster, NPC_AMBER_SCALPEL, 200.0f))
                    {
                        std::list<Creature*> amberList;
                        GetCreatureListWithEntryInGrid(amberList, l_Caster, NPC_LIVING_AMBER, 200.0f);
                        if (amberList.size() < 7)
                            if (urand(0, 1))
                                l_Caster->SummonCreature(NPC_LIVING_AMBER, l_Scalpel->GetPositionX(), l_Scalpel->GetPositionY(), l_Scalpel->GetPositionZ());
                    }
                }
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_amber_scalpel_SpellScript::Summon);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_amber_scalpel_SpellScript();
        }
};

// 122395 - Struggle for Control
class spell_struggle_for_control : public SpellScriptLoader
{
    public:
        spell_struggle_for_control() : SpellScriptLoader("spell_struggle_for_control") { }

        class spell_struggle_for_control_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_struggle_for_control_SpellScript);

            void WillConsumption()
            {
                if (Unit* caster = GetCaster())
                    if (caster->HasAura(SPELL_RESHAPE_LIFE))
                        caster->ModifyPower(POWER_ALTERNATE_POWER, -8);
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_struggle_for_control_SpellScript::WillConsumption);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_struggle_for_control_SpellScript();
        }
};

// 123156 - Consume Amber
class spell_consume_amber : public SpellScriptLoader
{
    public:
        spell_consume_amber() : SpellScriptLoader("spell_consume_amber") { }

        class spell_consume_amber_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_consume_amber_SpellScript);

            SpellCastResult CanConsume()
            {
                if (Unit* caster = GetCaster())
                    if (Unit* amber = GetClosestCreatureWithEntry(caster, NPC_LIVING_AMBER, 3.0f))
                        if (amber->HasAura(SPELL_BURNING_AMBER))
                            return SPELL_CAST_OK;
                
                return SPELL_FAILED_INCORRECT_AREA;
            }

            void Consume()
            {
                if (Unit* caster = GetCaster())
                    if (Unit* amber = GetClosestCreatureWithEntry(caster, NPC_LIVING_AMBER, 3.0f))
                        if (amber->HasAura(SPELL_BURNING_AMBER))
                            amber->GetAI()->DoAction(ACTION_AMBER_CONSUMED);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_consume_amber_SpellScript::CanConsume);
                AfterCast   += SpellCastFn(spell_consume_amber_SpellScript::Consume);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_consume_amber_SpellScript();
        }
};

// 123060 - Break Free
class spell_break_free : SpellScriptLoader
{
    public:
        spell_break_free() : SpellScriptLoader("spell_break_free") { }
        
        class spell_break_free_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_break_free_SpellScript);

            void FreePlayer(SpellEffIndex /*effIndex*/)
            {
                if (Unit* player = GetCaster())
                    player->RemoveAura(SPELL_RESHAPE_LIFE);
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_break_free_SpellScript::FreePlayer, EFFECT_0, SPELL_EFFECT_INTERRUPT_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_break_free_SpellScript();
        }
};

// 122415 - Grab
class spell_grab : public SpellScriptLoader
{
    public:
        spell_grab() : SpellScriptLoader("spell_grab") { }

        class spell_grab_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_grab_SpellScript);

            void Handle(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetExplTargetUnit())
                        target->CastSpell(caster, GetSpellInfo()->GetEffect(effIndex)->BasePoints, true);
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_grab_SpellScript::Handle, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_grab_SpellScript();
        }
};

// 122413 - Fling
class spell_fling : public SpellScriptLoader
{
    public:
        spell_fling() : SpellScriptLoader("spell_fling") { }

        class spell_fling_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_fling_SpellScript);

            void Handle(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    caster->RemoveAura(SPELL_RIDE_MONSTRUOSITY);

                    ObjectGuid targetGuid = CAST_AI(mob_amber_monstruosity::mob_amber_monstruosityAI, caster->GetAI())->grabTargetGuid;
                    if (Unit* target = ObjectAccessor::GetUnit(*caster, targetGuid))
                    {
                        target->RemoveAura(SPELL_RIDE_MONSTRUOSITY);

                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, caster, 200.0f);

                        // playerList should be at least 2 as one of the list is the player thrown, and we can't choose him as target
                        if (playerList.size() > 1)
                        {
                            Player* dest = 0;
                            std::list<Player*>::iterator itr = playerList.begin();

                            while (!dest)
                            {
                                if ((*itr) != caster)
                                    if (urand(0, 1))
                                        dest = *itr;

                                if (itr == playerList.end())
                                    itr = playerList.begin();
                            }
                           target->CastSpell(dest, SPELL_FLING_FLYING, false);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_fling_SpellScript::Handle, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_fling_SpellScript();
        }
};

// 122420 - Fling, victim thrown
class spell_fling_thrown : public SpellScriptLoader
{
    public:
        spell_fling_thrown() : SpellScriptLoader("spell_fling_thrown") { }

        class spell_fling_thrown_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_fling_thrown_SpellScript);

            void Land(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, SPELL_FLING_LANDING, false);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_fling_thrown_SpellScript::Land, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_fling_thrown_SpellScript();
        }
};

// 122547 - Draw Power
class spell_unsok_draw_power : public SpellScriptLoader
{
public:
    spell_unsok_draw_power() : SpellScriptLoader("spell_unsok_draw_power") { }

    class spell_unsok_draw_power_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_unsok_draw_power_SpellScript);

        void ChangePhase()
        {
            if (Unit* caster = GetCaster())
                caster->GetAI()->DoAction(ACTION_LAUNCH_LAST_PHASE);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_unsok_draw_power_SpellScript::ChangePhase);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_unsok_draw_power_SpellScript();
    }
};

// 123014 - Volatile amber
class spell_volatile_amber : public SpellScriptLoader
{
public:
    spell_volatile_amber() : SpellScriptLoader("spell_volatile_amber") { }

    class spell_volatile_amber_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_volatile_amber_SpellScript);

        void CancelDmg(SpellEffIndex /*effIndex*/)
        {
            if (Player* target = GetHitPlayer())
                if (target->HasAura(SPELL_RESHAPE_LIFE))
                    SetHitDamage(0);
        }

        void HealMutated(SpellEffIndex /*effIndex*/)
        {
            if (Player* target = GetHitPlayer())
                if (target->HasAura(SPELL_RESHAPE_LIFE))
                    target->CastSpell(target, SPELL_HEAL_MUTATED, false);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_volatile_amber_SpellScript::CancelDmg, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_volatile_amber_SpellScript();
    }
};

void AddSC_boss_unsok()
{
    new boss_unsok();                   // 62511
    new mob_mutated_construct();        // 62701
    new mob_amber_monstruosity();       // 62711
    new mob_living_amber();             // 62691
    new mob_amber_pool_stalker();       // 62762
    new mob_amber_globule();            // 64283
    new mob_amber_scalpel();            // 62510
    new spell_amber_scalpel();          // 121995
    new spell_struggle_for_control();   // 122395
    new spell_consume_amber();          // 123156
    new spell_break_free();             // 123060
    new spell_grab();                   // 122415
    new spell_fling();                  // 122413
    new spell_fling_thrown();           // 122420
    new spell_unsok_draw_power();       // 122547
    new spell_volatile_amber();         // 123014
}
