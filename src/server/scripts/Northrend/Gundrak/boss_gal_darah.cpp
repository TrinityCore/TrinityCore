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
#include "gundrak.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_IMPALING_CHARGE                   = 54956,
    SPELL_IMPALING_CHARGE_CONTROL_VEHICLE   = 54958,
    SPELL_STOMP                             = 55292,
    SPELL_PUNCTURE                          = 55276,
    SPELL_STAMPEDE                          = 55218,
    SPELL_WHIRLING_SLASH                    = 55250,
    SPELL_ENRAGE                            = 55285,
    SPELL_HEARTH_BEAM_VISUAL                = 54988,
    SPELL_TRANSFORM_RHINO                   = 55297,
    SPELL_TRANSFORM_BACK                    = 55299,

    // Rhino Spirit
    SPELL_STAMPEDE_SPIRIT                   = 55221,
    SPELL_STAMPEDE_SPIRIT_2                 = 55219,
    SPELL_STAMPEDE_SPIRIT_CHARGE            = 59823

};

enum Yells
{
    SAY_AGGRO                               = 0,
    SAY_SLAY                                = 1,
    SAY_DEATH                               = 2,
    SAY_SUMMON_RHINO                        = 3,
    SAY_TRANSFORM_1                         = 4,
    SAY_TRANSFORM_2                         = 5,
    EMOTE_IMPALE                            = 6
};

enum CombatPhase
{
    PHASE_TROLL                             = 1,
    PHASE_RHINO                             = 2
};

enum Events
{
    EVENT_IMPALING_CHARGE                   = 1,
    EVENT_STOMP,
    EVENT_PUNCTURE,
    EVENT_STAMPEDE,
    EVENT_WHIRLING_SLASH,
    EVENT_ENRAGE,
    EVENT_TRANSFORM,

    EVENT_GROUP_TROLL                       = PHASE_TROLL,
    EVENT_GROUP_RHINO                       = PHASE_RHINO
};

enum Misc
{
    DATA_SHARE_THE_LOVE                     = 1
};

class boss_gal_darah : public CreatureScript
{
    public:
        boss_gal_darah() : CreatureScript("boss_gal_darah") { }

        struct boss_gal_darahAI : public BossAI
        {
            boss_gal_darahAI(Creature* creature) : BossAI(creature, DATA_GAL_DARAH), _phaseCounter(0) { }

            void Reset() override
            {
                _Reset();
                _impaledPlayers.clear();
                _phaseCounter = 0;
                DoCastAOE(SPELL_HEARTH_BEAM_VISUAL, true);
            }

            void JustSummoned(Creature* summon) override
            {
                BossAI::JustSummoned(summon);
                if (summon->GetEntry() == NPC_RHINO_SPIRIT)
                {
                    summon->CastSpell(summon, SPELL_STAMPEDE_SPIRIT, true);
                    summon->CastSpell(summon, SPELL_STAMPEDE_SPIRIT_2, true);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        summon->CastSpell(target, SPELL_STAMPEDE_SPIRIT_CHARGE);
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);
                me->InterruptNonMeleeSpells(false);
                SetPhase(PHASE_TROLL);
            }

            void SetPhase(CombatPhase phase)
            {
                events.SetPhase(phase);
                switch (phase)
                {
                    case PHASE_TROLL:
                        events.ScheduleEvent(EVENT_STAMPEDE, Seconds(10), 0, PHASE_TROLL);
                        events.ScheduleEvent(EVENT_WHIRLING_SLASH, Seconds(21), 0, PHASE_TROLL);
                        break;
                    case PHASE_RHINO:
                        events.ScheduleEvent(EVENT_STOMP, Seconds(25), 0, PHASE_RHINO);
                        events.ScheduleEvent(EVENT_IMPALING_CHARGE, Seconds(21), 0, PHASE_RHINO);
                        events.ScheduleEvent(EVENT_ENRAGE, Seconds(15), 0, PHASE_RHINO);
                        events.ScheduleEvent(EVENT_PUNCTURE, Seconds(10), 0, PHASE_RHINO);
                        break;
                }
            }

            void SetGUID(ObjectGuid const& guid, int32 id) override
            {
                if (id == DATA_SHARE_THE_LOVE)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, guid))
                        Talk(EMOTE_IMPALE, target);
                    _impaledPlayers.insert(guid);
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_SHARE_THE_LOVE)
                    return _impaledPlayers.size();

                return 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_TRANSFORM_BACK)
                    me->RemoveAurasDueToSpell(SPELL_TRANSFORM_RHINO);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_IMPALING_CHARGE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                            DoCast(target, SPELL_IMPALING_CHARGE);
                        if (++_phaseCounter >= 2)
                            events.ScheduleEvent(EVENT_TRANSFORM, 5s);
                        events.Repeat(Seconds(31));
                        break;
                    case EVENT_STOMP:
                        DoCastAOE(SPELL_STOMP);
                        events.Repeat(Seconds(20));
                        break;
                    case EVENT_PUNCTURE:
                        DoCastVictim(SPELL_PUNCTURE);
                        events.Repeat(Seconds(8));
                        break;
                    case EVENT_STAMPEDE:
                        Talk(SAY_SUMMON_RHINO);
                        DoCastAOE(SPELL_STAMPEDE);
                        events.Repeat(Seconds(15));
                        break;
                    case EVENT_WHIRLING_SLASH:
                        DoCastVictim(SPELL_WHIRLING_SLASH);
                        if (++_phaseCounter >= 2)
                            events.ScheduleEvent(EVENT_TRANSFORM, 5s);
                        events.Repeat(Seconds(21));
                        break;
                    case EVENT_ENRAGE:
                        DoCastSelf(SPELL_ENRAGE);
                        events.Repeat(Seconds(20));
                        break;
                    case EVENT_TRANSFORM:
                        if (events.IsInPhase(PHASE_TROLL))
                        {
                            Talk(SAY_TRANSFORM_1);
                            DoCast(me, SPELL_TRANSFORM_RHINO);
                            SetPhase(PHASE_RHINO);
                        }
                        else if (events.IsInPhase(PHASE_RHINO))
                        {
                            Talk(SAY_TRANSFORM_2);
                            DoCast(me, SPELL_TRANSFORM_BACK);
                            SetPhase(PHASE_TROLL);
                        }
                        _phaseCounter = 0;
                        break;
                    default:
                        break;
                }
            }

        private:
            GuidSet _impaledPlayers;
            uint8 _phaseCounter;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGundrakAI<boss_gal_darahAI>(creature);
        }
};

// 54956, 59827 - Impaling Charge
class spell_gal_darah_impaling_charge : public SpellScriptLoader
{
    public:
        spell_gal_darah_impaling_charge() : SpellScriptLoader("spell_gal_darah_impaling_charge") { }

        class spell_gal_darah_impaling_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gal_darah_impaling_charge_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_IMPALING_CHARGE_CONTROL_VEHICLE });
            }

            bool Load() override
            {
                return GetCaster()->GetVehicleKit() && GetCaster()->GetEntry() == NPC_GAL_DARAH;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    Unit* caster = GetCaster();
                    target->CastSpell(caster, SPELL_IMPALING_CHARGE_CONTROL_VEHICLE, true);
                    caster->ToCreature()->AI()->SetGUID(target->GetGUID(), DATA_SHARE_THE_LOVE);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_gal_darah_impaling_charge_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_CHARGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gal_darah_impaling_charge_SpellScript();
        }
};

// 59823 - Stampede (Rhino Spirit Charge)
class spell_gal_darah_stampede_charge : public SpellScriptLoader
{
public:
    spell_gal_darah_stampede_charge() : SpellScriptLoader("spell_gal_darah_stampede_charge") { }

    class spell_gal_darah_stampede_charge_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gal_darah_stampede_charge_SpellScript);

        void OnHit(SpellEffIndex /*effIndex*/)
        {
            if (Creature* caster = GetCaster()->ToCreature())
                caster->DespawnOrUnsummon(Seconds(1));
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_gal_darah_stampede_charge_SpellScript::OnHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gal_darah_stampede_charge_SpellScript();
    }
};

class achievement_share_the_love : public AchievementCriteriaScript
{
    public:
        achievement_share_the_love() : AchievementCriteriaScript("achievement_share_the_love") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* GalDarah = target->ToCreature())
                if (GalDarah->AI()->GetData(DATA_SHARE_THE_LOVE) >= 5)
                    return true;

            return false;
        }
};

void AddSC_boss_gal_darah()
{
    new boss_gal_darah();
    new spell_gal_darah_impaling_charge();
    new spell_gal_darah_stampede_charge();
    new achievement_share_the_love();
}
