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

#include "culling_of_stratholme.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_CURSE_OF_TWISTED_FLESH = 58845,
    SPELL_EXPLODE_GHOUL = 52480,
    SPELL_SHADOW_BOLT = 57725,
    SPELL_STEAL_FLESH = 52708,
    SPELL_STEAL_FLESH_DEBUFF = 52711,
    SPELL_STEAL_FLESH_BUFF = 52712,
    SPELL_SUMMON_GHOULS = 52451
};

enum Yells
{
    SAY_AGGRO = 0,
    SAY_SPAWN = 1,
    SAY_SLAY = 2,
    SAY_DEATH = 3,
    SAY_EXPLODE_GHOUL = 4,
    SAY_STEAL_FLESH = 5,
    SAY_SUMMON_GHOULS = 6
};

enum Events
{
    EVENT_CURSE_FLESH = 1,
    EVENT_EXPLODE_GHOUL1,
    EVENT_EXPLODE_GHOUL2,
    EVENT_SHADOW_BOLT,
    EVENT_STEAL_FLESH,
    EVENT_SUMMON_GHOULS
};

class boss_salramm : public CreatureScript
{
    public:
        boss_salramm() : CreatureScript("boss_salramm") { }

        struct boss_salrammAI : public BossAI
        {
            boss_salrammAI(Creature* creature) : BossAI(creature, DATA_SALRAMM) { }

            void InitializeAI() override
            {
                Talk(SAY_SPAWN);
                if (instance->GetBossState(DATA_SALRAMM) == DONE)
                    me->RemoveLootMode(LOOT_MODE_DEFAULT);
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);
                BossAI::JustEngagedWith(who);

                events.ScheduleEvent(EVENT_SUMMON_GHOULS, randtime(Seconds(19),Seconds(24)));
                events.ScheduleEvent(EVENT_SHADOW_BOLT, Seconds(2));
                events.ScheduleEvent(EVENT_STEAL_FLESH, Seconds(25), Seconds(35));
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_CURSE_FLESH, Seconds(40));
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CURSE_FLESH:
                        DoCastVictim(SPELL_CURSE_OF_TWISTED_FLESH);
                        events.Repeat(Seconds(37));
                        break;
                    case EVENT_SUMMON_GHOULS:
                        Talk(SAY_SUMMON_GHOULS);
                        DoCastAOE(SPELL_SUMMON_GHOULS);
                        events.ScheduleEvent(EVENT_EXPLODE_GHOUL1, Seconds(20), Seconds(24));
                        events.ScheduleEvent(EVENT_EXPLODE_GHOUL2, Seconds(25), Seconds(29));
                        break;
                    case EVENT_SHADOW_BOLT:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                            DoCast(target, SPELL_SHADOW_BOLT);
                        events.Repeat(Seconds(3));
                        break;
                    case EVENT_STEAL_FLESH:
                        Talk(SAY_STEAL_FLESH);
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 50.0f, true))
                            DoCast(target, SPELL_STEAL_FLESH);
                        events.Repeat(Seconds(15), Seconds(20));
                        break;
                    case EVENT_EXPLODE_GHOUL2:
                        events.ScheduleEvent(EVENT_SUMMON_GHOULS, Seconds(4));
                        [[fallthrough]];
                    case EVENT_EXPLODE_GHOUL1:
                        Talk(SAY_EXPLODE_GHOUL);
                        DoCastAOE(SPELL_EXPLODE_GHOUL, true);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
                instance->SetData(DATA_NOTIFY_DEATH, 1);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetCullingOfStratholmeAI<boss_salrammAI>(creature);
        }
};

// 52708 - Steal Flesh
class spell_salramm_steal_flesh : public AuraScript
{
    PrepareAuraScript(spell_salramm_steal_flesh);

    void HandlePeriodic(AuraEffect const* /*eff*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_STEAL_FLESH_BUFF, true);
        GetCaster()->CastSpell(GetTarget(), SPELL_STEAL_FLESH_DEBUFF, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_salramm_steal_flesh::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_boss_salramm()
{
    new boss_salramm();
    RegisterSpellScript(spell_salramm_steal_flesh);
}
