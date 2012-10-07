/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "ahnkahet.h"

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_SLAY        = 1,
    SAY_DEATH       = 2,
    SAY_EGG_SAC     = 3,
    EMOTE_HATCHES   = 4
};

enum Spells
{
    SPELL_BROOD_PLAGUE          = 56130,
    H_SPELL_BROOD_RAGE          = 59465,
    SPELL_ENRAGE                = 26662, // Enraged if too far away from home
    SPELL_SUMMON_SWARMERS       = 56119, // 2x 30178  -- 2x every 10secs
    SPELL_SUMMON_SWARM_GUARD    = 56120, // 1x 30176  -- every 25%
    // Spells Adds
    SPELL_SPRINT                = 56354,
    SPELL_GUARDIAN_AURA         = 56151
};

enum Creatures
{
    NPC_AHNKAHAR_SWARMER        = 30178,
    NPC_AHNKAHAR_GUARDIAN       = 30176
};

enum Events
{
    EVENT_PLAGUE = 1,
    EVENT_RAGE,
    EVENT_SUMMON_SWARMER,
    EVENT_CHECK_ENRAGE,
    EVENT_SPRINT,
    DATA_RESPECT_YOUR_ELDERS
};

class boss_elder_nadox : public CreatureScript
{
    public:
        boss_elder_nadox() : CreatureScript("boss_elder_nadox") { }

        struct boss_elder_nadoxAI : public ScriptedAI
        {
            boss_elder_nadoxAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            bool GuardianDied;
            uint8 AmountHealthModifier;
            InstanceScript* instance;
            SummonList summons;
            EventMap events;

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                AmountHealthModifier = 1;
                GuardianDied = false;

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, IN_PROGRESS);

                events.ScheduleEvent(EVENT_PLAGUE, 13*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_SWARMER, 10*IN_MILLISECONDS);

                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_RAGE, 12*IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_CHECK_ENRAGE, 5*IN_MILLISECONDS);
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                summon->AI()->DoZoneInCombat();
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                if (summon->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                    GuardianDied = true;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_RESPECT_YOUR_ELDERS)
                    return !GuardianDied ? 1 : 0;

                return 0;
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);

                summons.DespawnAll();

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, DONE);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PLAGUE:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM,0, 100, true),SPELL_BROOD_PLAGUE,true);
                            events.ScheduleEvent(EVENT_PLAGUE, 15*IN_MILLISECONDS);
                            break;
                        case EVENT_RAGE:
                            DoCast(H_SPELL_BROOD_RAGE);
                            events.ScheduleEvent(EVENT_RAGE, urand(10*IN_MILLISECONDS, 50*IN_MILLISECONDS));
                            break;
                        case EVENT_SUMMON_SWARMER:
                            DoCast(me, SPELL_SUMMON_SWARMERS);
                            if (urand(1, 3) == 3) // 33% chance of dialog
                                Talk(SAY_EGG_SAC);
                            events.ScheduleEvent(EVENT_SUMMON_SWARMER, 10*IN_MILLISECONDS);
                            break;
                        case EVENT_CHECK_ENRAGE:
                            if (me->HasAura(SPELL_ENRAGE))
                                return;
                            if (me->GetPositionZ() < 24.0f)
                                DoCast(me, SPELL_ENRAGE, true);
                            events.ScheduleEvent(EVENT_CHECK_ENRAGE, 5*IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }

                if (me->HealthBelowPct(100 - AmountHealthModifier * 25))
                {
                    Talk(EMOTE_HATCHES, me->GetGUID());
                    DoCast(me, SPELL_SUMMON_SWARM_GUARD);
                    ++AmountHealthModifier;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_elder_nadoxAI(creature);
        }
};

class mob_ahnkahar_nerubian : public CreatureScript
{
    public:
        mob_ahnkahar_nerubian() : CreatureScript("mob_ahnkahar_nerubian") { }

        struct mob_ahnkahar_nerubianAI : public ScriptedAI
        {
            mob_ahnkahar_nerubianAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                if (me->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                    DoCast(me, SPELL_GUARDIAN_AURA, true);

                events.ScheduleEvent(EVENT_SPRINT, 13*IN_MILLISECONDS);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (me->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                    me->RemoveAurasDueToSpell(SPELL_GUARDIAN_AURA);
            }

            void UpdateAI(const uint32 diff)
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
                    case EVENT_SPRINT:
                        DoCast(me, SPELL_SPRINT);
                        events.ScheduleEvent(EVENT_SPRINT, 20*IN_MILLISECONDS);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ahnkahar_nerubianAI(creature);
        }
};

//HACK: No, AI. Replace with proper db content?
class mob_nadox_eggs : public CreatureScript
{
public:
    mob_nadox_eggs() : CreatureScript("mob_nadox_eggs") { }

    struct mob_nadox_eggsAI : public Scripted_NoMovementAI
    {
        mob_nadox_eggsAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            creature->UpdateAllStats();
        }

        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*victim*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(const uint32 /*diff*/) {}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_nadox_eggsAI(creature);
    }
};

class GuardianCheck
{
public:
    bool operator()(const WorldObject* target) const
    {
        if (target->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
            return true;

        return false;
    }
};

class spell_elder_nadox_guardian : public SpellScriptLoader
{
public:
    spell_elder_nadox_guardian() : SpellScriptLoader("spell_elder_nadox_guardian") { }

    class spell_elder_nadox_guardian_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_elder_nadox_guardian_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(GuardianCheck());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elder_nadox_guardian_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elder_nadox_guardian_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_elder_nadox_guardian_SpellScript();
    }
};

class achievement_respect_your_elders : public AchievementCriteriaScript
{
public:
    achievement_respect_your_elders() : AchievementCriteriaScript("achievement_respect_your_elders") {}

    bool OnCheck(Player* /*player*/, Unit* target)
    {
        if (!target)
            return false;

        if (Creature* Nadox = target->ToCreature())
            if (Nadox->AI()->GetData(DATA_RESPECT_YOUR_ELDERS))
                return true;

        return false;
    }
};

void AddSC_boss_elder_nadox()
{
    new boss_elder_nadox();
    new mob_ahnkahar_nerubian();
    new mob_nadox_eggs();
    new spell_elder_nadox_guardian();
    new achievement_respect_your_elders();
}
