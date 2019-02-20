/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "SpellAuras.h"
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
    // Elder Nadox
    SPELL_BROOD_PLAGUE          = 56130,
    H_SPELL_BROOD_RAGE          = 59465,
    SPELL_ENRAGE                = 26662, // Enraged if too far away from home
    SPELL_SUMMON_SWARMERS       = 56119, // 2x 30178  -- 2x every 10secs
    SPELL_SUMMON_SWARM_GUARD    = 56120, // 1x 30176

    // Adds
    SPELL_SWARM_BUFF            = 56281,
    SPELL_SPRINT                = 56354
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

        struct boss_elder_nadoxAI : public BossAI
        {
            boss_elder_nadoxAI(Creature* creature) : BossAI(creature, DATA_ELDER_NADOX)
            {
                Initialize();
            }

            void Initialize()
            {
                GuardianSummoned = false;
                GuardianDied = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_PLAGUE, 13s);
                events.ScheduleEvent(EVENT_SUMMON_SWARMER, 10s);

                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_RAGE, 12s);
                    events.ScheduleEvent(EVENT_CHECK_ENRAGE, 5s);
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                if (summon->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                    GuardianDied = true;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_RESPECT_YOUR_ELDERS)
                    return !GuardianDied ? 1 : 0;

                return 0;
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
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
                        case EVENT_PLAGUE:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_BROOD_PLAGUE, true);
                            events.ScheduleEvent(EVENT_PLAGUE, 15s);
                            break;
                        case EVENT_RAGE:
                            DoCast(H_SPELL_BROOD_RAGE);
                            events.ScheduleEvent(EVENT_RAGE, 10s, 50s);
                            break;
                        case EVENT_SUMMON_SWARMER:
                            /// @todo: summoned by egg
                            DoCast(me, SPELL_SUMMON_SWARMERS);
                            if (urand(1, 3) == 3) // 33% chance of dialog
                                Talk(SAY_EGG_SAC);
                            events.ScheduleEvent(EVENT_SUMMON_SWARMER, 10s);
                            break;
                        case EVENT_CHECK_ENRAGE:
                            if (me->HasAura(SPELL_ENRAGE))
                                return;
                            if (me->GetPositionZ() < 24.0f)
                                DoCast(me, SPELL_ENRAGE, true);
                            events.ScheduleEvent(EVENT_CHECK_ENRAGE, 5s);
                            break;
                        default:
                            break;
                    }
                }

                if (!GuardianSummoned && me->HealthBelowPct(50))
                {
                    /// @todo: summoned by egg
                    Talk(EMOTE_HATCHES, me);
                    DoCast(me, SPELL_SUMMON_SWARM_GUARD);
                    GuardianSummoned = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool GuardianSummoned;
            bool GuardianDied;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAhnKahetAI<boss_elder_nadoxAI>(creature);
        }
};

class npc_ahnkahar_nerubian : public CreatureScript
{
    public:
        npc_ahnkahar_nerubian() : CreatureScript("npc_ahnkahar_nerubian") { }

        struct npc_ahnkahar_nerubianAI : public ScriptedAI
        {
            npc_ahnkahar_nerubianAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_SPRINT, 13s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPRINT:
                            DoCast(me, SPELL_SPRINT);
                            _events.ScheduleEvent(EVENT_SPRINT, 20s);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAhnKahetAI<npc_ahnkahar_nerubianAI>(creature);
        }
};

// 56159 - Swarm
class spell_ahn_kahet_swarm : public SpellScriptLoader
{
    public:
        spell_ahn_kahet_swarm() : SpellScriptLoader("spell_ahn_kahet_swarm") { }

        class spell_ahn_kahet_swarm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ahn_kahet_swarm_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SWARM_BUFF });
            }

            void CountTargets(std::list<WorldObject*>& targets)
            {
                _targetCount = targets.size();
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (_targetCount)
                {
                    if (Aura* aura = GetCaster()->GetAura(SPELL_SWARM_BUFF))
                    {
                        aura->SetStackAmount(_targetCount);
                        aura->RefreshDuration();
                    }
                    else
                    {
                        CastSpellExtraArgs args;
                        args.TriggerFlags = TRIGGERED_FULL_MASK;
                        args.AddSpellMod(SPELLVALUE_AURA_STACK, _targetCount);
                        GetCaster()->CastSpell(GetCaster(), SPELL_SWARM_BUFF, args);
                    }
                }
                else
                    GetCaster()->RemoveAurasDueToSpell(SPELL_SWARM_BUFF);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ahn_kahet_swarm_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                OnEffectHit += SpellEffectFn(spell_ahn_kahet_swarm_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

            uint32 _targetCount = 0;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ahn_kahet_swarm_SpellScript();
        }
};

class achievement_respect_your_elders : public AchievementCriteriaScript
{
    public:
        achievement_respect_your_elders() : AchievementCriteriaScript("achievement_respect_your_elders") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_RESPECT_YOUR_ELDERS);
        }
};

void AddSC_boss_elder_nadox()
{
    new boss_elder_nadox();
    new npc_ahnkahar_nerubian();
    new spell_ahn_kahet_swarm();
    new achievement_respect_your_elders();
}
