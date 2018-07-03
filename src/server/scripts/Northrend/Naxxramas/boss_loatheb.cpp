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
#include "InstanceScript.h"
#include "naxxramas.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_NECROTIC_AURA                     = 55593,
    SPELL_SUMMON_SPORE                      = 29234,
    SPELL_DEATHBLOOM                        = 29865,
    SPELL_INEVITABLE_DOOM                   = 29204,
    SPELL_FUNGAL_CREEP                      = 29232,

    SPELL_DEATHBLOOM_FINAL_DAMAGE           = 55594,
};

enum Texts
{
    SAY_NECROTIC_AURA_APPLIED       = 0,
    SAY_NECROTIC_AURA_REMOVED       = 1,
    SAY_NECROTIC_AURA_FADING        = 2,
};

enum Events
{
    EVENT_NECROTIC_AURA = 1,
    EVENT_DEATHBLOOM,
    EVENT_INEVITABLE_DOOM,
    EVENT_SPORE,
    EVENT_NECROTIC_AURA_FADING,
    EVENT_NECROTIC_AURA_FADED
};

enum Achievement
{
    DATA_ACHIEVEMENT_SPORE_LOSER    = 21822183,
};

class boss_loatheb : public CreatureScript
{
    public:
        boss_loatheb() : CreatureScript("boss_loatheb") { }

        struct boss_loathebAI : public BossAI
        {
            boss_loathebAI(Creature* creature) : BossAI(creature, BOSS_LOATHEB), _doomCounter(0), _sporeLoser(true) { }

            void Reset() override
            {
                _Reset();
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FUNGAL_CREEP);
                _doomCounter = 0;
                _sporeLoser = true;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_NECROTIC_AURA, Seconds(17));
                events.ScheduleEvent(EVENT_DEATHBLOOM, Seconds(5));
                events.ScheduleEvent(EVENT_SPORE, Seconds(18));
                events.ScheduleEvent(EVENT_INEVITABLE_DOOM, Minutes(2));
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                _sporeLoser = false;
                summon->CastSpell(summon, SPELL_FUNGAL_CREEP, true);
            }

            uint32 GetData(uint32 id) const override
            {
                return (_sporeLoser && id == DATA_ACHIEVEMENT_SPORE_LOSER) ? 1u : 0u;
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
                        case EVENT_NECROTIC_AURA:
                            DoCastAOE(SPELL_NECROTIC_AURA);
                            Talk(SAY_NECROTIC_AURA_APPLIED);
                            events.ScheduleEvent(EVENT_NECROTIC_AURA_FADING, Seconds(14));
                            events.ScheduleEvent(EVENT_NECROTIC_AURA_FADED, Seconds(17));
                            events.Repeat(Seconds(20));
                            break;
                        case EVENT_DEATHBLOOM:
                            DoCastAOE(SPELL_DEATHBLOOM);
                            events.Repeat(Seconds(30));
                            break;
                        case EVENT_INEVITABLE_DOOM:
                            ++_doomCounter;
                            DoCastAOE(SPELL_INEVITABLE_DOOM);
                            if (_doomCounter > 6)
                                events.Repeat((_doomCounter & 1) ? Seconds(14) : Seconds(17));
                            else
                                events.Repeat(Seconds(30));
                            break;
                        case EVENT_SPORE:
                            DoCast(me, SPELL_SUMMON_SPORE, false);
                            events.Repeat(RAID_MODE(Seconds(36), Seconds(15)));
                            break;
                        case EVENT_NECROTIC_AURA_FADING:
                            Talk(SAY_NECROTIC_AURA_FADING);
                            break;
                        case EVENT_NECROTIC_AURA_FADED:
                            Talk(SAY_NECROTIC_AURA_REMOVED);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _doomCounter;
            bool _sporeLoser;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNaxxramasAI<boss_loathebAI>(creature);
        }
};

class achievement_spore_loser : public AchievementCriteriaScript
{
    public:
        achievement_spore_loser() : AchievementCriteriaScript("achievement_spore_loser") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_ACHIEVEMENT_SPORE_LOSER);
        }
};

class spell_loatheb_deathbloom : public SpellScriptLoader
{
    public:
        spell_loatheb_deathbloom() : SpellScriptLoader("spell_loatheb_deathbloom") { }

        class spell_loatheb_deathbloom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_loatheb_deathbloom_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_DEATHBLOOM_FINAL_DAMAGE });
            }

            void AfterRemove(AuraEffect const* eff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                GetTarget()->CastSpell(nullptr, SPELL_DEATHBLOOM_FINAL_DAMAGE, true, nullptr, eff, GetCasterGUID());
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_loatheb_deathbloom_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_loatheb_deathbloom_AuraScript();
        }
};

void AddSC_boss_loatheb()
{
    new boss_loatheb();
    new achievement_spore_loser();
    new spell_loatheb_deathbloom();
}
