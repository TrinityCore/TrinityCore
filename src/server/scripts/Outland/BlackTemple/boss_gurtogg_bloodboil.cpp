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
#include "GridNotifiers.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

#include "black_temple.h"

enum Says
{
    SAY_AGGRO     = 0,
    SAY_SLAY      = 1,
    SAY_SPECIAL   = 2,
    SAY_ENRAGE    = 3
};

enum Spells
{
    //Gurtogg
    SPELL_BLOODBOIL             = 42005,
    SPELL_ARCING_SMASH          = 40457,
    SPELL_FEL_ACID_BREATH       = 40508,
    SPELL_EJECT                 = 40486,
    SPELL_BEWILDERING_STRIKE    = 40491,
    SPELL_FEL_RAGE_SELF         = 40594,
    SPELL_INSIGNIFIGANCE        = 40618,
    SPELL_FEL_RAGE_TARGET       = 40604,
    SPELL_FEL_RAGE_2            = 40616,
    SPELL_FEL_RAGE_3            = 41625,
    SPELL_FEL_RAGE_TARGET_2     = 46787,
    SPELL_FEL_GEYSER            = 40569,
    SPELL_CHARGE                = 40602,
    SPELL_EJECT_2               = 40597,
    SPELL_FEL_ACID_BREATH_2     = 40595,
    SPELL_ARCING_SMASH_2        = 40599,
    SPELL_BERSERK               = 45078,
    //Player
    SPELL_TAUNT_GURTOGG         = 40603,
    SPELL_FEL_RAGE_P            = 40617,
    //Fel Geyser
    SPELL_FEL_GEYSER_2          = 40593,
    SPELL_BIRTH                 = 40031
};

enum Phases
{
    PHASE_1       = 1,
    PHASE_2       = 2,
    GROUP_PHASE_1 = 1,
    GROUP_PHASE_2 = 2
};

enum Sounds
{
    SOUND_ID_DEATH  = 11439,
    SOUND_ID_ENRAGE = 11437
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_BLOODBOIL,
    EVENT_ARCING_SMASH,
    EVENT_FEL_ACID_BREATH,
    EVENT_EJECT,
    EVENT_BEWILDERING_STRIKE,
    EVENT_CHANGE_PHASE,
    EVENT_START_PHASE_2,
    EVENT_EJECT_2,
    EVENT_FEL_ACID_BREATH_2,
    EVENT_ARCING_SMASH_2,
    EVENT_CHARGE_PLAYER
};

class boss_gurtogg_bloodboil : public CreatureScript
{
public:
    boss_gurtogg_bloodboil() : CreatureScript("boss_gurtogg_bloodboil") { }

    struct boss_gurtogg_bloodboilAI : public BossAI
    {
        boss_gurtogg_bloodboilAI(Creature* creature) : BossAI(creature, DATA_GURTOGG_BLOODBOIL)
        {
            Initialize();
        }

        void Reset() override
        {
            _Reset();
            Initialize();
            events.SetPhase(PHASE_1);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
        }

        void Initialize()
        {
            _oldThreat = 0.0f;
            _oldTargetGUID.Clear();
            _targetGUID.Clear();
        }

        bool CanAIAttack(Unit const* who) const override
        {
            return BossAI::CanAIAttack(who) && !who->HasAura(SPELL_BEWILDERING_STRIKE);
        }

        void AttackStart(Unit* who) override
        {
            if (!CanAIAttack(who))
                return;

            BossAI::AttackStart(who);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            events.ScheduleEvent(EVENT_BERSERK, Minutes(10));
            events.ScheduleEvent(EVENT_CHANGE_PHASE, Seconds(60));
            ScheduleEvents();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _DespawnAtEvade();
        }

        void ScheduleEvents()
        {
            if (events.IsInPhase(PHASE_1))
            {
                events.ScheduleEvent(EVENT_BLOODBOIL, Seconds(10), GROUP_PHASE_1, PHASE_1);
                events.ScheduleEvent(EVENT_ARCING_SMASH, Seconds(10), GROUP_PHASE_1, PHASE_1);
                events.ScheduleEvent(EVENT_FEL_ACID_BREATH, Seconds(25), GROUP_PHASE_1, PHASE_1);
                events.ScheduleEvent(EVENT_EJECT, Seconds(35), GROUP_PHASE_1, PHASE_1);
                events.ScheduleEvent(EVENT_BEWILDERING_STRIKE, Seconds(47), GROUP_PHASE_1, PHASE_1);
            }
            else if (events.IsInPhase(PHASE_2))
            {
                events.ScheduleEvent(EVENT_START_PHASE_2, Milliseconds(100), GROUP_PHASE_2, PHASE_2);
                events.ScheduleEvent(EVENT_EJECT_2, Seconds(14), GROUP_PHASE_2, PHASE_2);
                events.ScheduleEvent(EVENT_FEL_ACID_BREATH_2, Seconds(16), GROUP_PHASE_2, PHASE_2);
                events.ScheduleEvent(EVENT_ARCING_SMASH_2, Seconds(8), GROUP_PHASE_2, PHASE_2);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            DoPlaySoundToSet(me, SOUND_ID_DEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                 return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BLOODBOIL:
                        DoCast(SPELL_BLOODBOIL);
                        events.Repeat(Seconds(10));
                        break;
                    case EVENT_ARCING_SMASH:
                        DoCastVictim(SPELL_ARCING_SMASH);
                        events.Repeat(Seconds(10));
                        break;
                    case EVENT_FEL_ACID_BREATH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, me->GetCombatReach()))
                            DoCast(target, SPELL_FEL_ACID_BREATH);
                        events.Repeat(Seconds(25), Seconds(30));
                        break;
                    case EVENT_EJECT:
                        Talk(SAY_SPECIAL);
                        DoCastVictim(SPELL_EJECT);
                        break;
                    case EVENT_BEWILDERING_STRIKE:
                        DoCastVictim(SPELL_BEWILDERING_STRIKE);
                        break;
                    case EVENT_CHANGE_PHASE:
                        ChangePhase();
                        break;
                    case EVENT_START_PHASE_2:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        {
                            if (Unit* oldTarget = me->GetVictim())
                            {
                                _oldTargetGUID = oldTarget->GetGUID();
                                _oldThreat = DoGetThreat(oldTarget);
                            }
                            _targetGUID = target->GetGUID();
                            DoCastSelf(SPELL_FEL_RAGE_SELF, true);
                            DoCast(target, SPELL_FEL_RAGE_TARGET, true);
                            DoCast(target, SPELL_FEL_RAGE_2, true);
                            DoCast(target, SPELL_FEL_RAGE_3, true);
                            DoCast(target, SPELL_FEL_GEYSER, true);
                            DoCast(target, SPELL_FEL_RAGE_TARGET_2, true);
                            target->CastSpell(target, SPELL_FEL_RAGE_P, true);
                            target->CastSpell(target, SPELL_TAUNT_GURTOGG, true);
                            DoCastAOE(SPELL_INSIGNIFIGANCE, true);

                            events.ScheduleEvent(EVENT_CHARGE_PLAYER, Seconds(2), GROUP_PHASE_2, PHASE_2);

                            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                        }
                        else // If no other targets are found, reset phase 1
                        {
                            events.SetPhase(PHASE_1);
                            events.CancelEventGroup(GROUP_PHASE_2);
                            ScheduleEvents();
                            events.RescheduleEvent(EVENT_CHANGE_PHASE, Seconds(60));
                        }
                        break;
                    case EVENT_CHARGE_PLAYER:
                        if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                            DoCast(target, SPELL_CHARGE);
                        break;
                    case EVENT_EJECT_2:
                        DoCastVictim(SPELL_EJECT_2);
                        break;
                    case EVENT_FEL_ACID_BREATH_2:
                        DoCastVictim(SPELL_FEL_ACID_BREATH_2);
                        break;
                    case EVENT_ARCING_SMASH_2:
                        DoCastVictim(SPELL_ARCING_SMASH_2);
                        events.Repeat(Seconds(13));
                        break;
                    case EVENT_BERSERK:
                        DoCast(SPELL_BERSERK);
                        roll_chance_i(50) ? Talk(SAY_ENRAGE) : DoPlaySoundToSet(me, SOUND_ID_ENRAGE);
                        break;
                    default:
                        break;
                }
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

        void ChangePhase()
        {
            if (events.IsInPhase(PHASE_1))
            {
                events.SetPhase(PHASE_2);
                events.CancelEventGroup(GROUP_PHASE_1);
                events.ScheduleEvent(EVENT_CHANGE_PHASE, Seconds(30));
                ScheduleEvents();
            }
            else if (events.IsInPhase(PHASE_2))
            {
                events.SetPhase(PHASE_1);
                events.CancelEventGroup(GROUP_PHASE_2);
                events.ScheduleEvent(EVENT_CHANGE_PHASE, Seconds(60));
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                ScheduleEvents();

                // Attack the stored target
                if (Unit* oldTarget = ObjectAccessor::GetUnit(*me, _oldTargetGUID))
                    if (Unit* currentTarget = ObjectAccessor::GetUnit(*me, _targetGUID))
                    {
                        DoModifyThreatPercent(currentTarget, -100);
                        AttackStart(oldTarget);
                        me->AddThreat(oldTarget, _oldThreat);
                        Initialize();
                    }
            }
        }

    private:
        ObjectGuid _targetGUID;
        ObjectGuid _oldTargetGUID;
        float _oldThreat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_gurtogg_bloodboilAI>(creature);
    }
};

class npc_fel_geyser : public CreatureScript
{
public:
    npc_fel_geyser() : CreatureScript("npc_fel_geyser") { }

    struct npc_fel_geyserAI : public PassiveAI
    {
        npc_fel_geyserAI(Creature* creature) : PassiveAI(creature) { }

        void Reset() override
        {
            DoCastSelf(SPELL_FEL_GEYSER_2, true);
            DoCastSelf(SPELL_BIRTH, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_fel_geyserAI>(creature);
    }
};

// 42005 - Bloodboil
class spell_gurtogg_bloodboil_bloodboil : public SpellScriptLoader
{
    public:
        spell_gurtogg_bloodboil_bloodboil() : SpellScriptLoader("spell_gurtogg_bloodboil_bloodboil") { }

        class spell_gurtogg_bloodboil_bloodboil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gurtogg_bloodboil_bloodboil_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() <= 5)
                    return;

                // Sort the list of players
                targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), false));
                // Resize so we only get top 5
                targets.resize(5);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gurtogg_bloodboil_bloodboil_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gurtogg_bloodboil_bloodboil_SpellScript();
        }
};

// 40618 - Insignificance
class spell_gurtogg_bloodboil_insignificance : public SpellScriptLoader
{
public:
    spell_gurtogg_bloodboil_insignificance() : SpellScriptLoader("spell_gurtogg_bloodboil_insignificance") { }

    class spell_gurtogg_bloodboil_insignificance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gurtogg_bloodboil_insignificance_SpellScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_FEL_RAGE_TARGET });
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_FEL_RAGE_TARGET));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gurtogg_bloodboil_insignificance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gurtogg_bloodboil_insignificance_SpellScript();
    }
};

void AddSC_boss_gurtogg_bloodboil()
{
    new boss_gurtogg_bloodboil();
    new npc_fel_geyser();
    new spell_gurtogg_bloodboil_bloodboil();
    new spell_gurtogg_bloodboil_insignificance();
}
