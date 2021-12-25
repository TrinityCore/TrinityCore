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
#include "karazhan.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum TerestianSays
{
    SAY_SLAY                  = 0,
    SAY_DEATH                 = 1,
    SAY_AGGRO                 = 2,
    SAY_SACRIFICE             = 3,
    SAY_SUMMON_PORTAL         = 4
};

enum TerestianSpells
{
    SPELL_SHADOW_BOLT         = 30055,
    SPELL_SUMMON_IMP          = 30066,
    SPELL_FIENDISH_PORTAL_1   = 30171,
    SPELL_FIENDISH_PORTAL_2   = 30179,
    SPELL_BERSERK             = 32965,
    SPELL_SUMMON_FIENDISH_IMP = 30184,
    SPELL_BROKEN_PACT         = 30065,
    SPELL_AMPLIFY_FLAMES      = 30053,
    SPELL_FIREBOLT            = 30050,
    SPELL_SUMMON_DEMONCHAINS  = 30120,
    SPELL_DEMON_CHAINS        = 30206,
    SPELL_SACRIFICE           = 30115
};

enum TerestianMisc
{
    NPC_FIENDISH_PORTAL       = 17265,
    ACTION_DESPAWN_IMPS       = 1
};

enum TerestianEvents
{
    EVENT_SACRIFICE = 1,
    EVENT_SHADOWBOLT,
    EVENT_SUMMON_PORTAL_1,
    EVENT_SUMMON_PORTAL_2,
    EVENT_SUMMON_KILREK,
    EVENT_ENRAGE
};

class boss_terestian_illhoof : public CreatureScript
{
public:
    boss_terestian_illhoof() : CreatureScript("boss_terestian_illhoof") { }

    struct boss_terestianAI : public BossAI
    {
        boss_terestianAI(Creature* creature) : BossAI(creature, DATA_TERESTIAN) { }

        void Reset() override
        {
            EntryCheckPredicate pred(NPC_FIENDISH_PORTAL);
            summons.DoAction(ACTION_DESPAWN_IMPS, pred);
            _Reset();

            events.ScheduleEvent(EVENT_SHADOWBOLT, 1s);
            events.ScheduleEvent(EVENT_SUMMON_KILREK, 3s);
            events.ScheduleEvent(EVENT_SACRIFICE, 30s);
            events.ScheduleEvent(EVENT_SUMMON_PORTAL_1, Seconds(10));
            events.ScheduleEvent(EVENT_SUMMON_PORTAL_2, Seconds(11));
            events.ScheduleEvent(EVENT_ENRAGE, 10min);
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_BROKEN_PACT)
                events.ScheduleEvent(EVENT_SUMMON_KILREK, 32s);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            EntryCheckPredicate pred(NPC_FIENDISH_PORTAL);
            summons.DoAction(ACTION_DESPAWN_IMPS, pred);
            _JustDied();
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_SACRIFICE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        DoCast(target, SPELL_SACRIFICE, true);
                        target->CastSpell(target, SPELL_SUMMON_DEMONCHAINS, true);
                        Talk(SAY_SACRIFICE);
                    }
                    events.Repeat(Seconds(42));
                    break;
                case EVENT_SHADOWBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT, 0))
                        DoCast(target, SPELL_SHADOW_BOLT);
                    events.Repeat(Seconds(4), Seconds(10));
                    break;
                case EVENT_SUMMON_KILREK:
                    me->RemoveAurasDueToSpell(SPELL_BROKEN_PACT);
                    DoCastAOE(SPELL_SUMMON_IMP, true);
                    break;
                case EVENT_SUMMON_PORTAL_1:
                    Talk(SAY_SUMMON_PORTAL);
                    DoCastAOE(SPELL_FIENDISH_PORTAL_1);
                    break;
                case EVENT_SUMMON_PORTAL_2:
                    DoCastAOE(SPELL_FIENDISH_PORTAL_2, true);
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_BERSERK, true);
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<boss_terestianAI>(creature);
    }
};

class npc_kilrek : public CreatureScript
{
public:
    npc_kilrek() : CreatureScript("npc_kilrek") { }

    struct npc_kilrekAI : public ScriptedAI
    {
        npc_kilrekAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(8), [this](TaskContext amplify)
            {
                DoCastVictim(SPELL_AMPLIFY_FLAMES);
                amplify.Repeat(Seconds(9));
            });
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCastAOE(SPELL_BROKEN_PACT, true);
            me->DespawnOrUnsummon(Seconds(15));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _scheduler.Update(diff, [this]
            {
                DoMeleeAttackIfReady();
            });
        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<npc_kilrekAI>(creature);
    }
};

class npc_demon_chain : public CreatureScript
{
public:
    npc_demon_chain() : CreatureScript("npc_demon_chain") { }

    struct npc_demon_chainAI : public PassiveAI
    {
        npc_demon_chainAI(Creature* creature) : PassiveAI(creature) { }

        void IsSummonedBy(WorldObject* summoner) override
        {
            _sacrificeGUID = summoner->GetGUID();
            DoCastSelf(SPELL_DEMON_CHAINS, true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Unit* sacrifice = ObjectAccessor::GetUnit(*me, _sacrificeGUID))
                sacrifice->RemoveAurasDueToSpell(SPELL_SACRIFICE);
        }

    private:
        ObjectGuid _sacrificeGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<npc_demon_chainAI>(creature);
    }
};

class npc_fiendish_portal : public CreatureScript
{
public:
    npc_fiendish_portal() : CreatureScript("npc_fiendish_portal") { }

    struct npc_fiendish_portalAI : public PassiveAI
    {
        npc_fiendish_portalAI(Creature* creature) : PassiveAI(creature), _summons(me) { }

        void Reset() override
        {
            _scheduler.Schedule(Milliseconds(2400), Seconds(8), [this](TaskContext summonImp)
            {
                DoCastAOE(SPELL_SUMMON_FIENDISH_IMP, true);
                summonImp.Repeat();
            });
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_DESPAWN_IMPS)
                _summons.DespawnAll();
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);
            DoZoneInCombat(summon);
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        SummonList _summons;
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<npc_fiendish_portalAI>(creature);
    }
};

class npc_fiendish_imp : public CreatureScript
{
public:
    npc_fiendish_imp() : CreatureScript("npc_fiendish_imp") { }

    struct npc_fiendish_impAI : public ScriptedAI
    {
        npc_fiendish_impAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(2), [this](TaskContext firebolt)
            {
                DoCastVictim(SPELL_FIREBOLT);
                firebolt.Repeat(Milliseconds(2400));
            });

            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _scheduler.Update(diff, [this]
            {
                DoMeleeAttackIfReady();
            });
        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<npc_fiendish_impAI>(creature);
    }
};

void AddSC_boss_terestian_illhoof()
{
    new boss_terestian_illhoof();
    new npc_kilrek();
    new npc_demon_chain();
    new npc_fiendish_portal();
    new npc_fiendish_imp();
}
