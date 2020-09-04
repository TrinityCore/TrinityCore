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
#include "black_temple.h"
#include "Containers.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"

enum Texts
{
    SAY_TAUNT     = 0,
    SAY_AGGRO     = 1,
    SAY_SPELL     = 2,
    SAY_SLAY      = 3,
    SAY_ENRAGE    = 4,
    SAY_DEATH     = 5,
    EMOTE_ENRAGE  = 6,
    EMOTE_BERSERK = 7
};

enum Spells
{
    SPELL_FATAL_ATTRACTION_DAMAGE   = 40871,
    SPELL_SILENCING_SHRIEK          = 40823,
    SPELL_SABER_LASH_IMMUNITY       = 43690,
    SPELL_FATAL_ATTACTION_TELEPORT  = 40869,
    SPELL_BERSERK                   = 45078,
    SPELL_FATAL_ATTRACTION          = 41001,
    SPELL_SINISTER_PERIODIC         = 40863,
    SPELL_VILE_PERIODIC             = 40865,
    SPELL_RANDOM_PERIODIC           = 40867,
    SPELL_WICKED_PERIODIC           = 40866,
    SPELL_SINFUL_PERIODIC           = 40862,
    SPELL_PRISMATIC_AURA_SHADOW     = 40880,
    SPELL_PRISMATIC_AURA_FIRE       = 40882,
    SPELL_PRISMATIC_AURA_NATURE     = 40883,
    SPELL_PRISMATIC_AURA_ARCANE     = 40891,
    SPELL_PRISMATIC_AURA_FROST      = 40896,
    SPELL_PRISMATIC_AURA_HOLY       = 40897,
    SPELL_BEAM_SINISTER             = 40859,
    SPELL_BEAM_VILE                 = 40860,
    SPELL_BEAM_WICKED               = 40861,
    SPELL_BEAM_SINFUL               = 40827
};

enum Events
{
    EVENT_RANDOM_BEAM  = 1,
    EVENT_PRISMATIC_SHIELD,
    EVENT_FATAL_ATTRACTION,
    EVENT_SILENCING_SHRIEK,
    EVENT_TAUNT,
    EVENT_BERSERK
};

uint32 const BeamTriggers[4] =
{
    SPELL_SINISTER_PERIODIC,
    SPELL_VILE_PERIODIC,
    SPELL_WICKED_PERIODIC,
    SPELL_SINFUL_PERIODIC
};

uint32 const RandomBeam[4] =
{
    SPELL_BEAM_SINISTER,
    SPELL_BEAM_VILE,
    SPELL_BEAM_WICKED,
    SPELL_BEAM_SINFUL
};

uint32 const PrismaticAuras[6]=
{
    SPELL_PRISMATIC_AURA_SHADOW,
    SPELL_PRISMATIC_AURA_FIRE,
    SPELL_PRISMATIC_AURA_NATURE,
    SPELL_PRISMATIC_AURA_ARCANE,
    SPELL_PRISMATIC_AURA_FROST,
    SPELL_PRISMATIC_AURA_HOLY
};

Position const TeleportPoint[7]=
{
    { 959.996f, 212.576f, 193.843f },
    { 932.537f, 231.813f, 193.838f },
    { 958.675f, 254.767f, 193.822f },
    { 946.955f, 201.316f, 192.535f },
    { 944.294f, 149.676f, 197.551f },
    { 930.548f, 284.888f, 193.367f },
    { 965.997f, 278.398f, 195.777f }
};

class boss_mother_shahraz : public CreatureScript
{
public:
    boss_mother_shahraz() : CreatureScript("boss_mother_shahraz") { }

    struct boss_shahrazAI : public BossAI
    {
        boss_shahrazAI(Creature* creature) : BossAI(creature, DATA_MOTHER_SHAHRAZ), _enraged(false) { }

        void Reset() override
        {
            _Reset();
            _enraged = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_SILENCING_SHRIEK, Seconds(22));
            events.ScheduleEvent(EVENT_PRISMATIC_SHIELD, Seconds(15));
            events.ScheduleEvent(EVENT_FATAL_ATTRACTION, Seconds(35));
            events.ScheduleEvent(EVENT_RANDOM_BEAM, Seconds(6));
            events.ScheduleEvent(EVENT_BERSERK, Minutes(10));
            events.ScheduleEvent(EVENT_TAUNT, Seconds(35));
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _DespawnAtEvade();
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (!_enraged && me->HealthBelowPctDamaged(10, damage))
            {
                _enraged = true;
                DoCastSelf(SPELL_RANDOM_PERIODIC, true);
                Talk(EMOTE_ENRAGE, me);
                Talk(SAY_ENRAGE);
            }
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_RANDOM_BEAM:
                    DoCastSelf(BeamTriggers[urand(0, 3)]);
                    events.Repeat(Seconds(30));
                    break;
                case EVENT_PRISMATIC_SHIELD:
                    DoCastSelf(PrismaticAuras[urand(0, 5)]);
                    events.Repeat(Seconds(15));
                    break;
                case EVENT_FATAL_ATTRACTION:
                    Talk(SAY_SPELL);
                    me->CastCustomSpell(SPELL_FATAL_ATTACTION_TELEPORT, SPELLVALUE_MAX_TARGETS, 3, me);
                    events.Repeat(Seconds(30));
                    break;
                case EVENT_SILENCING_SHRIEK:
                    DoCastVictim(SPELL_SILENCING_SHRIEK);
                    events.Repeat(Seconds(18), Seconds(30));
                    break;
                case EVENT_TAUNT:
                    Talk(SAY_TAUNT);
                    events.Repeat(Seconds(30), Seconds(40));
                    break;
                case EVENT_BERSERK:
                    Talk(EMOTE_BERSERK, me);
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }
        }

    private:
        bool _enraged;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_shahrazAI>(creature);
    }
};

// 40869 - Fatal Attraction
class spell_mother_shahraz_fatal_attraction : public SpellScriptLoader
{
    public:
        spell_mother_shahraz_fatal_attraction() : SpellScriptLoader("spell_mother_shahraz_fatal_attraction") { }

        class spell_mother_shahraz_fatal_attraction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mother_shahraz_fatal_attraction_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_SABER_LASH_IMMUNITY,
                    SPELL_FATAL_ATTRACTION
                });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SABER_LASH_IMMUNITY));
            }

            void SetDest(SpellDestination& dest)
            {
                dest.Relocate(TeleportPoint[urand(0, 6)]);
            }

            void HandleTeleport(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_FATAL_ATTRACTION, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mother_shahraz_fatal_attraction_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_mother_shahraz_fatal_attraction_SpellScript::SetDest, EFFECT_1, TARGET_DEST_CASTER_RANDOM);
                OnEffectHitTarget += SpellEffectFn(spell_mother_shahraz_fatal_attraction_SpellScript::HandleTeleport, EFFECT_1, SPELL_EFFECT_TELEPORT_UNITS);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mother_shahraz_fatal_attraction_SpellScript();
        }
};

// 40870 - Fatal Attraction Dummy Visual
class spell_mother_shahraz_fatal_attraction_link : public SpellScriptLoader
{
    public:
        spell_mother_shahraz_fatal_attraction_link() : SpellScriptLoader("spell_mother_shahraz_fatal_attraction_link") { }

        class spell_mother_shahraz_fatal_attraction_link_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mother_shahraz_fatal_attraction_link_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_FATAL_ATTRACTION_DAMAGE });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_FATAL_ATTRACTION_DAMAGE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mother_shahraz_fatal_attraction_link_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mother_shahraz_fatal_attraction_link_SpellScript();
        }
};

// 40816 - Saber Lash
class spell_mother_shahraz_saber_lash : public SpellScriptLoader
{
    public:
        spell_mother_shahraz_saber_lash() : SpellScriptLoader("spell_mother_shahraz_saber_lash") { }

        class spell_mother_shahraz_saber_lash_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mother_shahraz_saber_lash_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_1)->TriggerSpell });
            }

            void OnTrigger(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                uint32 triggerSpell = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell;
                if (Unit* target = GetUnitOwner()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0))
                    GetUnitOwner()->CastSpell(target, triggerSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mother_shahraz_saber_lash_AuraScript::OnTrigger, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mother_shahraz_saber_lash_AuraScript();
        }
};

/* 40863 - Sinister Periodic
   40865 - Vile Periodic
   40866 - Wicked Periodic
   40862 - Sinful Periodic */
class spell_mother_shahraz_generic_periodic : public SpellScriptLoader
{
    public:
        spell_mother_shahraz_generic_periodic() : SpellScriptLoader("spell_mother_shahraz_generic_periodic") { }

        class spell_mother_shahraz_generic_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mother_shahraz_generic_periodic_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0)->TriggerSpell });
            }

            void OnTrigger(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                uint32 triggerSpell = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell;
                if (Unit* target = GetUnitOwner()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0))
                    GetUnitOwner()->CastSpell(target, triggerSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mother_shahraz_generic_periodic_AuraScript::OnTrigger, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mother_shahraz_generic_periodic_AuraScript();
        }
};

// 40867 - Random Periodic
class spell_mother_shahraz_random_periodic : public SpellScriptLoader
{
    public:
        spell_mother_shahraz_random_periodic() : SpellScriptLoader("spell_mother_shahraz_random_periodic") { }

        class spell_mother_shahraz_random_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mother_shahraz_random_periodic_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(RandomBeam);
            }

            void OnPeriodic(AuraEffect const* /*aurEffect*/)
            {
                PreventDefaultAction();
                GetUnitOwner()->CastSpell(GetUnitOwner(), RandomBeam[urand(0, 3)], true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mother_shahraz_random_periodic_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mother_shahraz_random_periodic_AuraScript();
        }
};

void AddSC_boss_mother_shahraz()
{
    new boss_mother_shahraz();
    new spell_mother_shahraz_fatal_attraction();
    new spell_mother_shahraz_fatal_attraction_link();
    new spell_mother_shahraz_saber_lash();
    new spell_mother_shahraz_generic_periodic();
    new spell_mother_shahraz_random_periodic();
}
