#include "new_karazhan.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

/* enum Says
{
    SAY_AGGRO           = ,
    SAY_DEATH           = ,
}; */

enum Spells
{
    SPELL_MANA_DEVOURER_ENERGIZE = 227451,
    SPELL_ENERGIZE = 232066,
    SPELL_ARCANE_BOMB = 227618,
    SPELL_ENERGY_VOID = 227523,
    SPELL_ENERGY_VOID_MANA_DRAIN = 227528,
    SPELL_UNSTABLE_MANA = 227502,
    SPELL_ENGULFING_POWER = 228577,
    SPELL_ENERGY_DISCHARGE = 227457,
    SPELL_COALESCE_POWER = 227297,
    SPELL_LOOSE_MANA = 228066,
    SPELL_DECIMATING_ESSENCE = 227507,

    SPELL_PLR_TELEPORT = 231500, //231499
};

enum eEvents
{
    EVENT_ARCANE_BOMB = 1,
    EVENT_ENERGY_VOID = 2,
    EVENT_ENERGY_DISCHARGE = 3,
    EVENT_COALESCE_POWER = 4,
};

//114252
class boss_mana_devourer : public CreatureScript
{
public:
    boss_mana_devourer() : CreatureScript("boss_mana_devourer") {}

    struct boss_mana_devourerAI : public BossAI
    {
        boss_mana_devourerAI(Creature* creature) : BossAI(creature, DATA_MANA_DEVOURER)
        {
            me->SetMaxPower(POWER_MANA, 100000);
        }

        void Reset() override
        {
            _Reset();
            me->SetPower(POWER_MANA, 0);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNSTABLE_MANA);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            DoCast(me, SPELL_MANA_DEVOURER_ENERGIZE, true);

            events.RescheduleEvent(EVENT_ARCANE_BOMB, 8000);
            events.RescheduleEvent(EVENT_ENERGY_VOID, 15000);
            events.RescheduleEvent(EVENT_ENERGY_DISCHARGE, 22000);
            events.RescheduleEvent(EVENT_COALESCE_POWER, 30000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNSTABLE_MANA);
            DoCast(me, SPELL_PLR_TELEPORT, true);

           // if (GetDifficultyID() != DIFFICULTY_MYTHIC && GetDifficultyID() != DIFFICULTY_MYTHIC_KEYSTONE)
             //   me->SummonGameObject(GO_DEVOURER_CACHE, 4144.98f, -2028.57f, 730.59f, 4.73f, 0.0f, 0.0f, 0.0f, 0.0f, 0);
        }


        void OnSpellFinished(SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_DECIMATING_ESSENCE)
                me->SetPower(POWER_MANA, 0);
        }


        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ARCANE_BOMB:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                        DoCast(target, SPELL_ARCANE_BOMB);
                    events.RescheduleEvent(EVENT_ARCANE_BOMB, 14000);
                    break;
                case EVENT_ENERGY_VOID:
                {
                    Position pos;
                    me->GetNearPosition(38.0f, frand(0.0f, 6.28f));
                    me->CastSpell(pos, SPELL_ENERGY_VOID, false);
                    events.RescheduleEvent(EVENT_ENERGY_VOID, 22000);
                    break;
                }
                case EVENT_ENERGY_DISCHARGE:
                    for (uint8 i = 0; i < 30; i++)
                        DoCast(me, SPELL_ENGULFING_POWER, true);
                    DoCast(me, SPELL_ENERGY_DISCHARGE, true);
                    events.RescheduleEvent(EVENT_ENERGY_DISCHARGE, 27000);
                    break;
                case EVENT_COALESCE_POWER:
                    DoCast(me, SPELL_COALESCE_POWER, true);
                    events.RescheduleEvent(EVENT_COALESCE_POWER, 30000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_mana_devourerAI(creature);
    }
};

//227451
class spell_mana_devourer_energize : public SpellScriptLoader
{
public:
    spell_mana_devourer_energize() : SpellScriptLoader("spell_mana_devourer_energize") {}

    class spell_mana_devourer_energize_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mana_devourer_energize_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            Creature* caster = GetCaster()->ToCreature();
            if (!caster || !caster->IsInCombat())
                return;

            if (caster->GetPowerPct(POWER_MANA) < 100.0f)
            {
                if (!caster->HasAura(SPELL_COALESCE_POWER))
                    caster->CastSpell(caster, SPELL_ENERGIZE, true);
            }
            else if (!caster->HasUnitState(UNIT_STATE_CASTING))
            {
                caster->CastSpell(caster, SPELL_DECIMATING_ESSENCE, false);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mana_devourer_energize_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mana_devourer_energize_AuraScript();
    }
};

//227524
class spell_mana_energy_void : public SpellScriptLoader
{
public:
    spell_mana_energy_void() : SpellScriptLoader("spell_mana_energy_void") {}

    class spell_mana_energy_void_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mana_energy_void_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            if (GetTarget())
            {
                if (!GetTarget()->HasAura(SPELL_UNSTABLE_MANA))
                    GetTarget()->CastSpell(GetTarget(), SPELL_ENERGY_VOID_MANA_DRAIN, true);
                else
                {
                    if (Aura* aura = GetTarget()->GetAura(SPELL_UNSTABLE_MANA))
                        aura->ModStackAmount(-1);
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mana_energy_void_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mana_energy_void_AuraScript();
    }
};

//227297
class spell_mana_coalesce_power : public SpellScriptLoader
{
public:
    spell_mana_coalesce_power() : SpellScriptLoader("spell_mana_coalesce_power") {}

    class spell_mana_coalesce_power_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mana_coalesce_power_AuraScript);

        uint32 mana = 0;

        void OnTick(AuraEffect const* aurEff)
        {
            if (auto caster = GetCaster())
            {
                if (caster->GetPowerPct(POWER_MANA) >= 5.0f)
                {
                    mana = caster->GetPower(POWER_MANA) - caster->CountPctFromMaxPower(POWER_MANA, 5);
                    caster->SetPower(POWER_MANA, mana);
                    caster->CastSpell(caster, SPELL_LOOSE_MANA, true);
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mana_coalesce_power_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mana_coalesce_power_AuraScript();
    }
};

//231499
class spell_rtk_mana_teleport : public SpellScriptLoader
{
public:
    spell_rtk_mana_teleport() : SpellScriptLoader("spell_rtk_mana_teleport") {}

    class spell_rtk_mana_teleport_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rtk_mana_teleport_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Player* player = GetTarget()->ToPlayer())
                player->TeleportTo(1651, 4147.74f, -2031.47f, 730.55f, player->GetOrientation());
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_rtk_mana_teleport_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rtk_mana_teleport_AuraScript();
    }
};

void AddSC_boss_mana_devourer()
{
    new boss_mana_devourer();
    new spell_mana_devourer_energize();
    new spell_mana_energy_void();
    new spell_mana_coalesce_power();
    new spell_rtk_mana_teleport();
}
