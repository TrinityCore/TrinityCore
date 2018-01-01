/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "MoveSplineInit.h"
#include "SpellScript.h"
#include "CombatAI.h"
#include "Player.h"

enum Northshire
{
    NPC_BLACKROCK_BATTLE_WORG               = 49871,
    NPC_STORWIND_INFANTRY                   = 49869,
    NPC_BROTHER_PAXTON                      = 951,
    NPC_INJURED_NORTHSHIRE_INFANTRY_DUMMY   = 50378,

    EVENT_ASK_FOR_HELP                      = 1,
    EVENT_SELECT_INFANTRY,
    EVENT_HEAL_INFANTRY,
    EVENT_GIVE_RIGHT_CLICK_INSTRUCTIONS,

    SAY_ASK_FOR_HELP                        = 0,
    SAY_HEAL_INFANTRY                       = 0,
    SAY_RIGHT_CLICK                         = 0,

    SPELL_PRAYER_OF_HEALING                 = 93091,
    SPELL_RENEW                             = 93094,
    SPELL_FLASH_HEAL                        = 17843,

    SPELL_GIVEN_RIGHT_CLICK_INSTRUCTION     = 93450,
};

uint32 const FearNoEvilQuests[] =
{
    28806,
    28807,
    28808,
    28809,
    28810,
    28811,
    28812,
    28813,
    29082,
};

class npc_stormwind_infantry : public CreatureScript
{
public:
    npc_stormwind_infantry() : CreatureScript("npc_stormwind_infantry") { }

    struct npc_stormwind_infantryAI : public ScriptedAI
    {
        npc_stormwind_infantryAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset() override
        {
            SetCombatMovement(false);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ASK_FOR_HELP, Seconds(RAND(1, 10) * 10));
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            events.Reset();
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (me->GetHealthPct() <= 85 && attacker->GetEntry() == NPC_BLACKROCK_BATTLE_WORG)
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ASK_FOR_HELP:
                        Talk(SAY_ASK_FOR_HELP);
                        events.ScheduleEvent(EVENT_ASK_FOR_HELP, Seconds(RAND(3, 10) * 10));
                        events.ScheduleEvent(EVENT_HEAL_INFANTRY, Seconds(2));
                        break;
                    case EVENT_HEAL_INFANTRY:
                        if (Creature* paxton = me->FindNearestCreature(NPC_BROTHER_PAXTON, 30.0f, true))
                        {
                            if (!paxton->HasUnitState(UNIT_STATE_CASTING))
                            {
                                paxton->AI()->Talk(SAY_HEAL_INFANTRY, me);
                                if (me->GetHealthPct() <= 85)
                                {
                                    paxton->StopMoving();
                                    switch (RAND(0, 2))
                                    {
                                        case 0: // Prayer of Healing
                                            paxton->CastSpell(paxton, SPELL_PRAYER_OF_HEALING);
                                            break;
                                        case 1: // Renew
                                            paxton->SetFacingToObject(me);
                                            paxton->CastSpell(me, SPELL_RENEW);
                                            break;
                                        case 2: // Flash Heal
                                            paxton->SetFacingToObject(me);
                                            paxton->CastSpell(me, SPELL_FLASH_HEAL);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_stormwind_infantryAI(creature);
    }
};

class npc_blackrock_battle_worg : public CreatureScript
{
public:
    npc_blackrock_battle_worg() : CreatureScript("npc_blackrock_battle_worg") { }

    struct npc_blackrock_battle_worgAI : public ScriptedAI
    {
        npc_blackrock_battle_worgAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void EnterCombat(Unit* who) override
        {
            if (who->GetEntry() != NPC_STORWIND_INFANTRY)
                isInfantry = false;
            events.CancelEvent(EVENT_SELECT_INFANTRY);
        }

        void Reset() override
        {
            isInfantry = true;
            events.ScheduleEvent(EVENT_SELECT_INFANTRY, Milliseconds(1));
        }

        void SelectInfantry()
        {
            if (Creature* victim = me->FindNearestCreature(NPC_STORWIND_INFANTRY, 5.0f, true))
            {
                isInfantry = true;
                victim->getThreatManager().getThreatList().empty();
                me->AI()->AttackStart(victim);
                victim->AI()->AttackStart(me);
            }
            else
                events.ScheduleEvent(EVENT_SELECT_INFANTRY, Seconds(1));
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (me->GetHealthPct() <= 85 && attacker->GetEntry() == NPC_STORWIND_INFANTRY)
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!isInfantry && !UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SELECT_INFANTRY:
                        SelectInfantry();
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        bool isInfantry;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_blackrock_battle_worgAI(creature);
    }
};

class npc_injured_stormwind_infantry_dummy : public CreatureScript
{
public:
    npc_injured_stormwind_infantry_dummy() : CreatureScript("npc_injured_stormwind_infantry_dummy") { }

    struct npc_injured_stormwind_infantry_dummyAI : public ScriptedAI
    {
        npc_injured_stormwind_infantry_dummyAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset() override
        {
            events.ScheduleEvent(EVENT_GIVE_RIGHT_CLICK_INSTRUCTIONS, Milliseconds(1));
        }


        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GIVE_RIGHT_CLICK_INSTRUCTIONS:
                    {
                        std::list<Player*> players;
                        Trinity::AnyPlayerInObjectRangeCheck checker(me, 50.0f);
                        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
                        Cell::VisitWorldObjects(me, searcher, 50.0f);
                        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            for (uint8 i = 0; i < 9; i++)
                            {
                                if ((*itr)->GetQuestStatus(FearNoEvilQuests[i]) == QUEST_STATUS_INCOMPLETE)
                                {
                                    if (!(*itr)->HasAura(SPELL_GIVEN_RIGHT_CLICK_INSTRUCTION))
                                    {
                                        me->CastSpell((*itr), SPELL_GIVEN_RIGHT_CLICK_INSTRUCTION, true);
                                        Talk(SAY_RIGHT_CLICK, (*itr));
                                    }
                                }
                            }
                        }
                        events.Repeat(Seconds(10));
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_injured_stormwind_infantry_dummyAI(creature);
    }
};

enum WantedHogger
{
    // Hogger
    SPELL_VICIOUS_SLICE     = 87337,
    SPELL_SUMMON_MINIONS    = 87366,
    SPELL_EATING            = 87351,
    SPELL_UPSET_STOMACH     = 87352,
    SPELL_TELEPORT_VISUAL   = 64446,

    SAY_HELP_HOGGER         = 0,
    SAY_ANNOUNCE_HEAL       = 1,
    SAY_ANNOUNCE_STUN       = 2,
    SAY_SURRENDER           = 3,
    SAY_OUTRO_1             = 4,
    SAY_OUTRO_2             = 5,

    EVENT_VICIOUS_SLICE     = 1,
    EVENT_MOVE_TO_MEAT      = 2,
    EVENT_EAT_MEAT          = 3,
    EVENT_MAKE_AGGRESSIVE   = 4,
    EVENT_SUMMON_GENERAL    = 5,
    EVENT_FACE_TO_GENERAL   = 6,
    EVENT_SAY_OUTRO_2       = 7,
    EVENT_CAST_TELEPORT     = 8,
    EVENT_DESPAWN           = 9,

    POINT_EAT_MEAT          = 1,
    POINT_SURRENDER         = 2,
};

Position const HoggerMeatPos = { -10145.12f, 667.582f, 37.53608f };
Position const HoggerEndPos = { -10136.9f, 670.009f, 36.03682f };

class npc_hogger : public CreatureScript
{
public:
    npc_hogger() : CreatureScript("npc_hogger") { }

    struct npc_hoggerAI : public ScriptedAI
    {
        npc_hoggerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset() override
        {
            me->GetMotionMaster()->MoveRandom(7.0f);
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            _calledForHelp = false;
            _defeated = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_VICIOUS_SLICE, Seconds(5));
            me->GetMotionMaster()->Clear(MOTION_SLOT_IDLE);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
                damage = me->GetHealth() - 1;

            if (me->GetHealthPct() <= 50 && !_calledForHelp)
            {
                Talk(SAY_HELP_HOGGER);
                DoCast(SPELL_SUMMON_MINIONS);
                events.ScheduleEvent(EVENT_MOVE_TO_MEAT, Seconds(4));
                _calledForHelp = true;
            }

            if (me->GetHealth() == 1 && !_defeated)
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                me->RemoveAllAuras();
                me->KillSelf();
                me->setDeathState(ALIVE);
                me->setRegeneratingHealth(false);
                me->SetHealth(1);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                Talk(SAY_SURRENDER);
                me->GetMotionMaster()->MovePoint(POINT_SURRENDER, HoggerEndPos, true);
                _defeated = true;
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (pointId)
            {
                case POINT_EAT_MEAT:
                    events.ScheduleEvent(EVENT_EAT_MEAT, 1);
                    break;
                case POINT_SURRENDER:
                    events.ScheduleEvent(EVENT_SUMMON_GENERAL, 1);
                    break;
                default:
                    break;
            }
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_UPSET_STOMACH)
            {
                events.CancelEvent(EVENT_MAKE_AGGRESSIVE);
                me->SetReactState(REACT_AGGRESSIVE);
                Talk(SAY_ANNOUNCE_STUN);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !_defeated)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_VICIOUS_SLICE:
                        DoCastVictim(SPELL_VICIOUS_SLICE);
                        events.Repeat(Seconds(11), Seconds(12));
                        break;
                    case EVENT_MOVE_TO_MEAT:
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        Talk(SAY_ANNOUNCE_HEAL);
                        me->GetMotionMaster()->MovePoint(POINT_EAT_MEAT, HoggerMeatPos, true);
                        break;
                    case EVENT_EAT_MEAT:
                        DoCast(me, SPELL_EATING);
                        events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, Seconds(12));
                        break;
                    case EVENT_MAKE_AGGRESSIVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case EVENT_SUMMON_GENERAL:
                        me->SummonCreatureGroup(0);
                        events.ScheduleEvent(EVENT_FACE_TO_GENERAL, Seconds(12));
                        break;
                    case EVENT_FACE_TO_GENERAL:
                        Talk(SAY_OUTRO_1);
                        me->SetFacingTo(5.339049f);
                        events.ScheduleEvent(EVENT_SAY_OUTRO_2, Seconds(15));
                        break;
                    case EVENT_SAY_OUTRO_2:
                        Talk(SAY_OUTRO_2);
                        events.ScheduleEvent(EVENT_CAST_TELEPORT, Seconds(7));
                        break;
                    case EVENT_CAST_TELEPORT:
                        DoCast(me, SPELL_TELEPORT_VISUAL, true);
                        events.ScheduleEvent(EVENT_DESPAWN, Seconds(2));
                        break;
                    case EVENT_DESPAWN:
                        me->setRegeneratingHealth(true);
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool _calledForHelp;
        bool _defeated;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hoggerAI(creature);
    }
};

void AddSC_elwynn_forest()
{
    new npc_stormwind_infantry();
    new npc_blackrock_battle_worg();
    new npc_injured_stormwind_infantry_dummy();
    new npc_hogger();
}
