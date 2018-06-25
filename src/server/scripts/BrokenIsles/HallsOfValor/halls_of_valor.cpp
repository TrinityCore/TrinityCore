/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "halls_of_valor.h"

enum hallsOfValorSpells
{
    SPELL_SEVER             = 199652,
    SPELL_UNRULY_YELL       = 199726,
    SPELL_CALL_ANCESTOR     = 200969,
    SPELL_WICKED_DAGGER     = 199674,
};

enum hallsOfValorEvents
{
    EVENT_SEVER,
    EVENT_UNRULY_YELL,
    EVENT_CALL_ANCESTOR,
    EVENT_WICKED_DAGGER,
};

enum hallsOfValorTalk
{
    SAY_ENTER_COMBAT = 0,
    SAY_JUST_DIED = 1,
};

// 97083 - King Ranulf
struct boss_king_ranulf : public BossAI
{
    boss_king_ranulf(Creature* creature) : BossAI(creature, DATA_KING_RANULF) { }

    ObjectGuid targetGuid;

    void sGossipHello(Player* /*player*/) override
    {
        me->setFaction(14);
        me->SetReactState(REACT_DEFENSIVE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (InstanceScript* instance = me->GetInstanceScript())
            instance->SetBossState(DATA_GODKING_SKOVALD, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_SEVER, 3000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
                case EVENT_UNRULY_YELL:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_UNRULY_YELL, true);

                    events.ScheduleEvent(EVENT_UNRULY_YELL, 16000);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 95843 - King Haldor
struct boss_king_haldor : public BossAI
{
    boss_king_haldor(Creature* creature) : BossAI(creature, DATA_KING_HALDOR)  { }

    ObjectGuid targetGuid;

    void sGossipHello(Player* /*player*/) override
    {
        me->setFaction(14);
        me->SetReactState(REACT_DEFENSIVE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (InstanceScript* instance = me->GetInstanceScript())
            instance->SetBossState(DATA_KING_HALDOR, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(EVENT_SEVER, 3000);

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
                case EVENT_SEVER:
                {
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_SEVER, true);

                    events.ScheduleEvent(EVENT_SEVER, 16000);
                    break;
                }
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 97081 - King Bjorn
struct boss_king_bjorn : public BossAI
{
    boss_king_bjorn(Creature* creature) : BossAI(creature, DATA_KING_BJORN) { }

    ObjectGuid targetGuid;

    void sGossipHello(Player* /*player*/) override
    {
        me->setFaction(14);
        me->SetReactState(REACT_DEFENSIVE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (InstanceScript* instance = me->GetInstanceScript())
            instance->SetBossState(DATA_KING_BJORN, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(EVENT_WICKED_DAGGER, 3000);

        if (instance)
            instance->SetBossState(DATA_KING_BJORN, IN_PROGRESS);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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

                case EVENT_WICKED_DAGGER:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_WICKED_DAGGER, true);

                    events.ScheduleEvent(EVENT_WICKED_DAGGER, 16000);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 97084 - King Tor
struct boss_king_tor : public BossAI
{
    boss_king_tor(Creature* creature) : BossAI(creature, DATA_KING_TOR) { }

    void sGossipHello(Player* /*player*/) override
    {
        me->setFaction(14);
        me->SetReactState(REACT_DEFENSIVE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (InstanceScript* instance = me->GetInstanceScript())
            instance->SetBossState(DATA_KING_TOR, NOT_STARTED);
    }

    ObjectGuid targetGuid;

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(EVENT_CALL_ANCESTOR, 1000);

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (Creature* creature = me->FindNearestCreature(101326, 50.0f))
        {
            if (me->IsWithinMeleeRange(creature))
            {
                me->CastSpell(me, 199747, true);
                creature->DespawnOrUnsummon(0);
            }
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CALL_ANCESTOR:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        me->CastSpell(target, SPELL_CALL_ANCESTOR, true);

                    if (Creature* creature = me->FindNearestCreature(101326, 50.0f))
                    {
                        creature->SetLevel(110);
                        creature->setFaction(14);
                        creature->GetMotionMaster()->MovePoint(0, me->GetPosition(), true);
                    }
                    events.ScheduleEvent(EVENT_CALL_ANCESTOR, 16000);
                    break;
                }
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 101697 - Field of Eternal Hunt
class npc_field_of_eternal_hunt : public CreatureScript
{
public:
    npc_field_of_eternal_hunt() : CreatureScript("npc_field_of_eternal_hunt") { }

    bool OnGossipHello(Player* player, Creature* /*creature*/) override
    {
        player->TeleportTo(1477, 3199.07f, 2899.65f, 640.58f, 2.13f);
        return true;
    }
};

// 101712 - Halls of Valor
class npc_halls_of_valor : public CreatureScript
{
public:
    npc_halls_of_valor() : CreatureScript("npc_halls_of_valor") { }

    bool OnGossipHello(Player* player, Creature* /*creature*/) override
    {
        player->TeleportTo(1477, 3238.64f, 648.56f, 634.31f, 5.5f);
        return true;
    }
};

void AddSC_halls_of_valor()
{
    RegisterCreatureAI(boss_king_ranulf);
    RegisterCreatureAI(boss_king_haldor);
    RegisterCreatureAI(boss_king_bjorn);
    RegisterCreatureAI(boss_king_tor);
    new npc_field_of_eternal_hunt();
    new npc_halls_of_valor();
}
