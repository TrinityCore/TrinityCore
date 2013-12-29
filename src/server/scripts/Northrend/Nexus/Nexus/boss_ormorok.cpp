/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "nexus.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_SPELL_REFLECTION                      = 47981,
    SPELL_TRAMPLE                               = 48016,
    SPELL_FRENZY                                = 48017,
    SPELL_SUMMON_CRYSTALLINE_TANGLER            = 61564,
    SPELL_CRYSTAL_SPIKES                        = 47958,
};
enum Yells
{
    SAY_AGGRO                                   = 1,
    SAY_DEATH                                   = 2,
    SAY_REFLECT                                 = 3,
    SAY_CRYSTAL_SPIKES                          = 4,
    SAY_KILL                                    = 5,
    SAY_FRENZY                                  = 6
};

enum Events
{
    EVENT_CRYSTAL_SPIKES                        = 1,
    EVENT_TRAMPLE                               = 2,
    EVENT_SPELL_REFLECTION                      = 3,
    EVENT_CRYSTALLINE_TANGLER                   = 4,
};

class OrmorokTanglerPredicate
{
   public:
      OrmorokTanglerPredicate(Unit* unit) : me(unit) { }

    bool operator() (WorldObject* object) const
    {
        return object->GetDistance2d(me) >= 5.0f;
    }

    private:
        Unit* me;
};

class boss_ormorok : public CreatureScript
{
public:
    boss_ormorok() : CreatureScript("boss_ormorok") { }

    struct boss_ormorokAI : public BossAI
    {
        boss_ormorokAI(Creature* creature) : BossAI(creature, DATA_ORMOROK_EVENT) { }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();

            events.ScheduleEvent(EVENT_CRYSTAL_SPIKES, 12000);
            events.ScheduleEvent(EVENT_TRAMPLE, 10000);
            events.ScheduleEvent(EVENT_SPELL_REFLECTION, 30000);
            if (IsHeroic())
                events.ScheduleEvent(EVENT_CRYSTALLINE_TANGLER, 17000);

            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(DATA_ORMOROK_EVENT, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) OVERRIDE
        {
            if (!frenzy && HealthBelowPct(25))
            {
                Talk(SAY_FRENZY);
                DoCast(me, SPELL_FRENZY);
                frenzy = true;
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();

            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_ORMOROK_EVENT, DONE);
        }

        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TRAMPLE:
                    DoCast(me, SPELL_TRAMPLE);
                    events.ScheduleEvent(EVENT_TRAMPLE, 10000);
                    break;
                case EVENT_SPELL_REFLECTION:
                    Talk(SAY_REFLECT);
                    DoCast(me, SPELL_SPELL_REFLECTION);
                    events.ScheduleEvent(EVENT_SPELL_REFLECTION, 30000);
                    break;
                case EVENT_CRYSTAL_SPIKES:
                    Talk(SAY_CRYSTAL_SPIKES);
                    DoCast(SPELL_CRYSTAL_SPIKES);
                    events.ScheduleEvent(EVENT_CRYSTAL_SPIKES, 12000);
                    break;
                case EVENT_CRYSTALLINE_TANGLER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, OrmorokTanglerPredicate(me)))
                        DoCast(target, SPELL_SUMMON_CRYSTALLINE_TANGLER);
                    events.ScheduleEvent(EVENT_CRYSTALLINE_TANGLER, 17000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool frenzy;

    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_ormorokAI>(creature);
    }
};

enum CrystalSpikes
{
    NPC_CRYSTAL_SPIKE_INITIAL        = 27101,
    NPC_CRYSTAL_SPIKE_TRIGGER        = 27079,

    DATA_COUNT                       = 1,
    MAX_COUNT                        = 5,

    SPELL_CRYSTAL_SPIKE_DAMAGE       = 47944,

    GO_CRYSTAL_SPIKE_TRAP            = 188537,
};

uint32 const crystalSpikeSummon[3] =
{
        47936,
        47942,
        47943
};

class npc_crystal_spike_trigger : public CreatureScript
{
public:
    npc_crystal_spike_trigger() : CreatureScript("npc_crystal_spike_trigger") { }

    struct npc_crystal_spike_triggerAI : public ScriptedAI
    {
        npc_crystal_spike_triggerAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* owner) OVERRIDE
        {
            switch (me->GetEntry())
            {
                case NPC_CRYSTAL_SPIKE_INITIAL:
                     _count = 0;
                     me->SetFacingToObject(owner);
                     break;
                case NPC_CRYSTAL_SPIKE_TRIGGER:
                    if (Creature* trigger = owner->ToCreature())
                        _count = trigger->AI()->GetData(DATA_COUNT) + 1;
                    break;
                default:
                    _count = MAX_COUNT;
                    break;
            }

            if (me->GetEntry() == NPC_CRYSTAL_SPIKE_TRIGGER)
                if (GameObject* trap = me->FindNearestGameObject(GO_CRYSTAL_SPIKE_TRAP, 1.0f))
                    trap->Use(me);

            _despawntimer = 2000;
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            return type == DATA_COUNT ? _count : 0;
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (_despawntimer <= diff)
            {
                if (me->GetEntry() == NPC_CRYSTAL_SPIKE_TRIGGER)
                    if (GameObject* trap = me->FindNearestGameObject(GO_CRYSTAL_SPIKE_TRAP, 1.0f))
                        trap->Delete();

                me->DespawnOrUnsummon();
            }
            else
                _despawntimer -= diff;
        }

    private:
        uint32 _count;
        uint32 _despawntimer;

    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_crystal_spike_triggerAI(creature);
    }
};

class spell_crystal_spike : public SpellScriptLoader
{
    public:
        spell_crystal_spike() : SpellScriptLoader("spell_crystal_spike") { }

        class spell_crystal_spike_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_crystal_spike_AuraScript);

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();
                if (target->GetEntry() == NPC_CRYSTAL_SPIKE_INITIAL || target->GetEntry() == NPC_CRYSTAL_SPIKE_TRIGGER)
                    if (Creature* trigger = target->ToCreature())
                    {
                        uint32 spell = target->GetEntry() == NPC_CRYSTAL_SPIKE_INITIAL ? crystalSpikeSummon[0] : crystalSpikeSummon[urand(0, 2)];
                        if (trigger->AI()->GetData(DATA_COUNT) < MAX_COUNT)
                            trigger->CastSpell(trigger, spell, true);
                    }
            }

            void Register() OVERRIDE
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_crystal_spike_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_crystal_spike_AuraScript();
        }
};

void AddSC_boss_ormorok()
{
    new boss_ormorok();
    new npc_crystal_spike_trigger();
    new spell_crystal_spike();
}
