/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

void AddSC_elwynn_forest()
{
    new npc_stormwind_infantry();
    new npc_blackrock_battle_worg();
    new npc_injured_stormwind_infantry_dummy();
}
