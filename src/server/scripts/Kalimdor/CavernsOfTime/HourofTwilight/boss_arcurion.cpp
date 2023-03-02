/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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

#include"ScriptMgr.h"
#include"hour_of_twilight.h"

enum Spells
{
    SPELL_HAND_OF_FROST         = 102593,
    SPELL_CHAINS_OF_FROST       = 102582,
    SPELL_ICY_TOMB              = 103252,
    SPELL_ICY_TOMB_STUN         = 103251,
    SPELL_TORRENT_OF_FROST      = 104050,
    SPELL_BLOODLUST             = 103834,

    // NPC spells
    SPELL_ICY_BOULDER = 102480

};

enum Events
{
    EVENT_HAND_OF_FROST = 1,
    EVENT_CHAINS_OF_FROST,
    EVENT_ICY_TOMB,
    EVENT_SUMMON_FROZEN_SERVITOR,
    EVENT_ICY_BOULDER,
    EVENT_CHECK_PLAYER
};


class boss_arcurion : public CreatureScript
{
public:
    boss_arcurion() : CreatureScript("boss_arcurion") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_arcurionAI (creature);
    }

    struct boss_arcurionAI : public BossAI
    {
        boss_arcurionAI(Creature* creature) : BossAI(creature, DATA_ARCURION_EVENT)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript *instance;
        EventMap events;

        bool casting;
        uint8 count;
        bool cooldownVictim;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            me->SetVisible(false);
        }

        void Reset() override
        {
            _Reset();
            events.Reset();
            casting = false;
            cooldownVictim = false;

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
            {
                thrall->RemoveAura(SPELL_ICY_TOMB_STUN);
                thrall->AI()->Reset();
            }

            if (instance)
                instance->SetData(DATA_ARCURION_EVENT, NOT_STARTED);

            if (Creature* icyTomb = me->FindNearestCreature(NPC_ICY_TOMB, 50.0f, true))
            {
                icyTomb->DespawnOrUnsummon();
            }

        }

        void JustDied(Unit* /*Kill*/) override
        {

            _JustDied();

            if (instance)
                instance->SetData(DATA_ARCURION_EVENT, DONE);

            if (Creature* icyTomb = me->FindNearestCreature(NPC_ICY_TOMB, 50.0f, true))
            {
                icyTomb->DespawnOrUnsummon();
            }
        }

        void EnterCombat(Unit* /*Ent*/) override
        {
            _EnterCombat();
            DoZoneInCombat();

            count = 0;

            if (instance)
                instance->SetData(DATA_ARCURION_EVENT, IN_PROGRESS);

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
            {
                thrall->SetReactState(REACT_AGGRESSIVE);
                thrall->AI()->DoAction(ACTION_START_ARCURION);
                events.ScheduleEvent(EVENT_HAND_OF_FROST, 3000);
                events.ScheduleEvent(EVENT_ICY_TOMB, 30000);
                events.ScheduleEvent(EVENT_CHAINS_OF_FROST, 45000);
                events.ScheduleEvent(EVENT_SUMMON_FROZEN_SERVITOR, 0);
                events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32&damage) override
        {
            if(damage > 0)
            {
                if(me->HealthBelowPct(30) && casting == false)
                {
                    events.CancelEvent(EVENT_SUMMON_FROZEN_SERVITOR);
                    events.CancelEvent(EVENT_HAND_OF_FROST);
                    events.CancelEvent(EVENT_CHAINS_OF_FROST);
                    events.CancelEvent(EVENT_ICY_TOMB);

                    me->CastSpell(me, SPELL_TORRENT_OF_FROST, false);
                    casting = true;

                    if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
                    {
                        thrall->CastSpell(thrall, SPELL_BLOODLUST, false);
                        thrall->AI()->DoAction(ACTION_LAVA_BURST_ARCURION);
                    }
                    std::list<Creature*> unitList;
                    me->GetCreatureListWithEntryInGrid(unitList, NPC_FS_ARCURION, 100.0f);
                    for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                    {
                        (*itr)->DespawnOrUnsummon();
                    }

                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            //if (me->HasUnitState(UNIT_STATE_CASTING))
                //return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HAND_OF_FROST:
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_HAND_OF_FROST, false);
                        }
                        events.ScheduleEvent(EVENT_HAND_OF_FROST, 2000);
                        break;
                    case EVENT_ICY_TOMB:
                        events.RescheduleEvent(EVENT_SUMMON_FROZEN_SERVITOR, 12000);
                        events.CancelEvent(EVENT_HAND_OF_FROST);
                        if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
                        {
                            me->CastSpell(thrall, SPELL_ICY_TOMB, false);
                        }
                        events.ScheduleEvent(EVENT_HAND_OF_FROST, 2000);
                        break;
                    case EVENT_CHAINS_OF_FROST:
                        events.CancelEvent(EVENT_HAND_OF_FROST);
                        me->CastSpell(me, SPELL_CHAINS_OF_FROST, false);
                        events.ScheduleEvent(EVENT_HAND_OF_FROST, 2000);
                        events.ScheduleEvent(EVENT_CHAINS_OF_FROST, 45000);
                        break;
                    case EVENT_SUMMON_FROZEN_SERVITOR:
                    {
                        std::list<Creature*> unitList;
                        me->GetCreatureListWithEntryInGrid(unitList, NPC_FS_ARCURION, 100.0f);
                        if (unitList.size() < 6)
                        {
                            if (count > 5)
                                count = 0;
                            me->SummonCreature(NPC_FS_ARCURION, SpawnFrozenServitor[count], TEMPSUMMON_DEAD_DESPAWN, 0);
                            count++;
                        }
                        events.ScheduleEvent(EVENT_SUMMON_FROZEN_SERVITOR, 4000);
                        break;
                    }
                    case EVENT_CHECK_PLAYER:
                    {
                        std::list<Player*> targets;
                        me->GetPlayerListInGrid(targets, 100.0f);

                        if (targets.size() == 0)
                        {
                            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
                            {
                                me->SetReactState(REACT_PASSIVE);
                                thrall->SetReactState(REACT_PASSIVE);
                                thrall->AI()->Reset();
                                if (instance)
                                {
                                    instance->SetData(DATA_ARCURION_EVENT, NOT_STARTED);
                                    instance->SetBossState(DATA_ARCURION, NOT_STARTED);
                                }
                                EnterEvadeMode();

                                Reset();
                                me->SetReactState(REACT_AGGRESSIVE);
                            }
                        }
                        cooldownVictim = false;
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_frozen_servitor_arcurion : public CreatureScript
{
public:
    npc_frozen_servitor_arcurion() : CreatureScript("npc_frozen_servitor_arcurion") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_frozen_servitor_arcurionAI(creature);
    }

    struct npc_frozen_servitor_arcurionAI: public ScriptedAI
    {
        npc_frozen_servitor_arcurionAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_ICY_BOULDER, urand(3000, 7000));
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            events.ScheduleEvent(EVENT_ICY_BOULDER, 1000);
        }

        void DamageTaken(Unit* attacker, uint32& /*damage*/) override
        {
            if (Unit* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
            {
                if(attacker == thrall)
                {
                    me->DespawnOrUnsummon();
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ICY_BOULDER:
                    {
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_ICY_BOULDER, false);
                        }
                        events.ScheduleEvent(EVENT_ICY_BOULDER, 1000);
                        break;
                    }

                }
            }
        }
    };

};

class DistanceCheck
{
    public:
        explicit DistanceCheck(Unit* _caster) : caster(_caster) { }

        bool operator() (WorldObject* unit) const
        {
            if (!unit->ToPlayer())
                return true;
            return false;
        }

        Unit* caster;
};

class spell_icy_boulder : public SpellScriptLoader
{
    public:
        spell_icy_boulder() : SpellScriptLoader("spell_icy_boulder") { }

        class spell_icy_boulder_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icy_boulder_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(DistanceCheck(GetCaster()));

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_icy_boulder_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_icy_boulder_SpellScript();
        }
};

class npc_icy_tomb : public CreatureScript
{
public:
    npc_icy_tomb() : CreatureScript("npc_icy_tomb") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_icy_tombAI(creature);
    }

    struct npc_icy_tombAI: public ScriptedAI
    {
        npc_icy_tombAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 50.0f, true))
            {
                thrall->RemoveAurasDueToSpell(SPELL_ICY_TOMB_STUN);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            /*if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                }
            }*/
        }
    };

};

void AddSC_boss_arcurion()
{
    new boss_arcurion();
    new npc_frozen_servitor_arcurion();
    new spell_icy_boulder();
    new npc_icy_tomb();
}


