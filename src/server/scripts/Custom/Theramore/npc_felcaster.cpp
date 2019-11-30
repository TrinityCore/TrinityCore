#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Custom/AI/CustomAI.h"

enum Spells
{
    SPELL_SHADOW_BOLT           = 100028,
    SPELL_FEL_FIREBALL          = 100027,
    SPELL_SUMMON_PET            = 100070,
    SPELL_CORRUPTION            = 100074,
    SPELL_HAUNT                 = 100075,
    SPELL_HAUNT_HEAL            = 100076,
    SPELL_CURSE_OF_AGONY        = 100077,
    SPELL_DRAIN_OF_LIFE         = 69066
};

enum Pets
{
    NPC_PET                     = 100070,

    DISPLAYID_IMP               = 4449,
    DISPLAYID_VOID_WALKER       = 1132,
    DISPLAYID_FELHUNTER         = 850,
    DISPLAYID_SUCCUBUS          = 4162
};

class npc_felcaster : public CreatureScript
{
    public:
    npc_felcaster() : CreatureScript("npc_felcaster") {}

    struct npc_felcasterAI : public CustomAI
    {
        npc_felcasterAI(Creature* creature) : CustomAI(creature), healOnCooldown(false)
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!healOnCooldown && HealthBelowPct(50))
            {
                me->InterruptNonMeleeSpells(true);

                DoCastVictim(SPELL_DRAIN_OF_LIFE);

                healOnCooldown = true;

                scheduler.Schedule(Minutes(1), [this](TaskContext /*context*/)
                {
                    healOnCooldown = false;
                });
            }
        }

        void JustEngagedWith(Unit* who) override
        {
            if (Creature* pet = DoSummon(NPC_PET, me, 10.0f, 8000, TEMPSUMMON_CORPSE_TIMED_DESPAWN))
            {
                DoCast(SPELL_SUMMON_PET);

                pet->Attack(who, true);
                pet->GetMotionMaster()->MoveChase(who, PET_FOLLOW_DIST);
            }

            scheduler
                .Schedule(Seconds(12), [this](TaskContext shadow_bolt)
                {
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    shadow_bolt.Repeat(Seconds(3));
                })
                .Schedule(Seconds(8), [this](TaskContext fel_fireball)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_FEL_FIREBALL);
                    fel_fireball.Repeat(Seconds(8), Seconds(13));
                })
                .Schedule(Seconds(2), [this](TaskContext curse_of_agony)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (!target->HasAura(SPELL_CURSE_OF_AGONY))
                        {
                            DoCast(target, SPELL_CURSE_OF_AGONY);
                            curse_of_agony.Repeat(Seconds(15), Seconds(28));
                        }
                        else
                        {
                            curse_of_agony.Repeat(Seconds(5));
                        }
                    }
                })
                .Schedule(Seconds(3), [this](TaskContext corruption)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CORRUPTION);
                    corruption.Repeat(Seconds(18), Seconds(24));
                })
                .Schedule(Seconds(5), [this](TaskContext haunt)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_HAUNT);
                    haunt.Repeat(Seconds(20), Seconds(30));
                });

            DoStartNoMovement(who);
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            scheduler.Update(diff, [this]
            {
                if (me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoMeleeAttackIfReady();
                }
            });
        }

        private:
        bool healOnCooldown;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_felcasterAI(creature);
    }
};

// Haunt
class spell_felcaster_haunt : public SpellScriptLoader
{
    public:
    spell_felcaster_haunt() : SpellScriptLoader("spell_felcaster_haunt")
    {
    }

    class spell_felcaster_haunt_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_felcaster_haunt_SpellScript);

        void HandleAfterHit()
        {
            if (Aura* aura = GetHitAura())
                if (AuraEffect* aurEff = aura->GetEffect(EFFECT_1))
                    aurEff->SetAmount(CalculatePct(GetHitDamage(), aurEff->GetAmount()));
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_felcaster_haunt_SpellScript::HandleAfterHit);
        }
    };

    class spell_felcaster_haunt_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_felcaster_haunt_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_HAUNT_HEAL });
        }

        void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                CastSpellExtraArgs args(aurEff);
                args.OriginalCaster = GetCasterGUID();
                args.AddSpellBP0(aurEff->GetAmount());
                GetTarget()->CastSpell(caster, SPELL_HAUNT_HEAL, args);
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectApplyFn(spell_felcaster_haunt_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_felcaster_haunt_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_felcaster_haunt_AuraScript();
    }
};

void AddSC_npc_felcaster()
{
    new npc_felcaster();
    new spell_felcaster_haunt();
}
