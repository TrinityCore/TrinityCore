#include "ScriptMgr.h"
#include "Unit.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "ScriptedCreature.h"
#include "CustomAI.h"

enum Spells
{
    SPELL_FIREBALL              = 100003,
    SPELL_FIREBLAST             = 100004,
    SPELL_PYROBLAST             = 100005,
    SPELL_LIVING_BOMB           = 100080,
    SPELL_IGNITE                = 100092,

    SPELL_FROSTBOLT             = 100006,
    SPELL_ICE_LANCE             = 100007,
    SPELL_ICE_BLOCK             = 100008,
    SPELL_HYPOTHERMIA           = 41425,
    SPELL_BLINK                 = 57869,
    SPELL_FROT_NOVA             = 71320,
    SPELL_ICE_BARRIER           = 100068,
    SPELL_FROSTBITE             = 12494,

    SPELL_ARCANE_BARRAGE        = 100009,
    SPELL_ARCANE_BARRAGES       = 100078,
    SPELL_ARCANE_BLAST          = 100010,
    AURA_ARCANE_BLAST           = 36032,
    SPELL_ARCANE_PROJECTILE     = 100012,
    SPELL_ARCANE_EXPLOSION      = 100011,
    SPELL_EVOCATION             = 100014,
    SPELL_PRISMATIC_BARRIER     = 100069,
    SPELL_ARCANE_POWER          = 100081,

    SPELL_COUNTERSPELL          = 15122
};

enum Misc
{
    NPC_RHONIN                  = 100005
};

class npc_archmage_fire : public CreatureScript
{
    public:
    npc_archmage_fire() : CreatureScript("npc_archmage_fire") {}

    struct npc_archmage_fireAI : public CustomAI
    {
        npc_archmage_fireAI(Creature* creature) : CustomAI(creature)
        {
            SetCombatMovement(false);
        }

        void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_FIREBALL || spellInfo->Id == SPELL_FIREBLAST || spellInfo->Id == SPELL_PYROBLAST)
            {
                Unit* victim = target->ToUnit();
                if (victim && roll_chance_i(40))
                    DoCast(victim, SPELL_IGNITE, true);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler
                .Schedule(5ms, [this](TaskContext fireball)
                {
                    DoCastVictim(SPELL_FIREBALL);
                    fireball.Repeat(2s);
                })
                .Schedule(5ms, [this](TaskContext counterspell)
                {
                    if (Unit* target = DoSelectCastingUnit(SPELL_COUNTERSPELL, 35.f))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_COUNTERSPELL);
                        counterspell.Repeat(25s, 40s);
                    }
                    else
                    {
                        counterspell.Repeat(1s);
                    }
                })
                .Schedule(5s, [this](TaskContext living_bomb)
                {
                    DoCastVictim(SPELL_LIVING_BOMB);
                    living_bomb.Repeat(20s, 28s);
                })
                .Schedule(8s, [this](TaskContext fireblast)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FIREBLAST);
                    fireblast.Repeat(14s, 22s);
                })
                .Schedule(12s, [this](TaskContext pyroblast)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::MaxDistance, 0))
                        DoCast(target, SPELL_PYROBLAST);
                    pyroblast.Repeat(22s, 35s);
                });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            // Que pour la bataille de Theramore
            if (me->GetMapId() == 726)
            {
                if (damage >= me->GetMaxHealth())
                    damage = 0;

                if (HealthBelowPct(20))
                    damage = 0;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_fireAI(creature);
    }
};

class npc_archmage_arcanes : public CreatureScript
{
    public:
    npc_archmage_arcanes() : CreatureScript("npc_archmage_arcanes") {}

    struct npc_archmage_arcanesAI : public CustomAI
    {
        npc_archmage_arcanesAI(Creature* creature) : CustomAI(creature)
        {
            SetCombatMovement(false);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (me->GetEntry() != NPC_RHONIN)
            {
                DoCast(SPELL_PRISMATIC_BARRIER);

                scheduler
                    .Schedule(30s, [this](TaskContext prismatic_barrier)
                    {
                        if (!me->HasAura(SPELL_PRISMATIC_BARRIER))
                        {
                            DoCast(SPELL_PRISMATIC_BARRIER);
                            prismatic_barrier.Repeat(30s);
                        }
                        else
                        {
                            prismatic_barrier.Repeat(1s);
                        }
                    })
                    .Schedule(15s, [this](TaskContext arcane_projectile)
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCastVictim(SPELL_ARCANE_PROJECTILE);
                        arcane_projectile.Repeat(28s, 40s);
                    });
            }
            else
            {
                DoCast(SPELL_ARCANE_POWER);
            }

            scheduler
                .Schedule(5ms, [this](TaskContext arcane_blast)
                {
                    if (Aura* aura = me->GetAura(AURA_ARCANE_BLAST))
                    {
                        if (aura->GetStackAmount() <= 3)
                            DoCastVictim(SPELL_ARCANE_BLAST);
                    }
                    else
                    {
                        DoCastVictim(SPELL_ARCANE_BLAST);
                    }

                    arcane_blast.Repeat(500ms);
                })
                .Schedule(5ms, [this](TaskContext evocation)
                {
                    float manaPct = me->GetPower(POWER_MANA) * 100 / me->GetMaxPower(POWER_MANA);
                    if (manaPct <= 20)
                    {
                        me->InterruptNonMeleeSpells(true);
                        if (me->GetEntry() == NPC_RHONIN)
                        {
                            CastSpellExtraArgs args;
                            const SpellInfo* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_EVOCATION);
                            args.AddSpellBP0(spellInfo->Effects[EFFECT_0].BasePoints * 10);
                            DoCastSelf(SPELL_EVOCATION, args);
                        }
                        else
                        {
                            DoCastSelf(SPELL_EVOCATION);
                        }

                        evocation.Repeat(2min);
                    }
                    else
                    {
                        evocation.Repeat(5s);
                    }
                })
                .Schedule(5ms, [this](TaskContext counterspell)
                {
                    if (Unit* target = DoSelectCastingUnit(SPELL_COUNTERSPELL, 35.f))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_COUNTERSPELL);
                        counterspell.Repeat(25s, 40s);
                    }
                    else
                    {
                        counterspell.Repeat(1s);
                    }
                })
                .Schedule(3s, [this](TaskContext arcane_barrage)
                {
                    if (Aura* aura = me->GetAura(AURA_ARCANE_BLAST))
                    {
                        if (aura->GetStackAmount() >= 4)
                        {
                            me->InterruptNonMeleeSpells(true);
                            me->RemoveAura(aura);
                            DoCastVictim(SPELL_ARCANE_BARRAGE);
                        }
                    }

                    arcane_barrage.Repeat(500ms);
                })
                .Schedule(1min, [this](TaskContext arcane_explosion)
                {
                    DoCastAOE(SPELL_ARCANE_EXPLOSION);
                    arcane_explosion.Repeat(1min, 2min);
                });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            // Que pour la bataille de Theramore
            if (me->GetMapId() == 726)
            {
                if (damage >= me->GetMaxHealth())
                    damage = 0;

                if (HealthBelowPct(20))
                    damage = 0;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_arcanesAI(creature);
    }
};

class npc_archmage_frost : public CreatureScript
{
    public:
    npc_archmage_frost() : CreatureScript("npc_archmage_frost") {}

    struct npc_archmage_frostAI : public CustomAI
    {
        npc_archmage_frostAI(Creature* creature) : CustomAI(creature)
        {
            SetCombatMovement(false);
        }

        void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_FROSTBOLT || spellInfo->Id == SPELL_ICE_LANCE)
            {
                Unit* victim = target->ToUnit();
                if (victim && roll_chance_i(60))
                    DoCast(victim, SPELL_FROSTBITE, true);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoCast(SPELL_ICE_BARRIER);

            scheduler
                .Schedule(5ms, [this](TaskContext frostbotl)
                {
                    DoCastVictim(SPELL_FROSTBOLT);
                    frostbotl.Repeat(2s);
                })
                .Schedule(5ms, [this](TaskContext counterspell)
                {
                    if (Unit* target = DoSelectCastingUnit(SPELL_COUNTERSPELL, 35.f))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_COUNTERSPELL);
                        counterspell.Repeat(20s, 45s);
                    }
                    else
                    {
                        counterspell.Repeat(1s);
                    }
                })
                .Schedule(3s, [this](TaskContext ice_lance)
                {
                    me->InterruptNonMeleeSpells(false);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_ICE_LANCE);
                    ice_lance.Repeat(8s, 14s);
                })
                .Schedule(30s, [this](TaskContext ice_barrier)
                {
                    if (!me->HasAura(SPELL_ICE_BARRIER))
                    {
                        DoCast(SPELL_ICE_BARRIER);
                        ice_barrier.Repeat(30s);
                    }
                    else
                    {
                        ice_barrier.Repeat(1s);
                    }
                });
        }

        void Reset() override
        {
            CustomAI::Reset();

            me->RemoveAurasDueToSpell(SPELL_HYPOTHERMIA);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            // Que pour la bataille de Theramore
            if (me->GetMapId() == 726)
            {
                if (damage >= me->GetMaxHealth())
                    damage = 0;

                if (HealthBelowPct(20))
                    damage = 0;
            }

            if (!me->HasAura(SPELL_HYPOTHERMIA) && HealthBelowPct(30))
            {
                damage = 0;

                me->InterruptNonMeleeSpells(false);

                DoCastSelf(SPELL_HYPOTHERMIA);
                DoCastSelf(SPELL_ICE_BLOCK);

                scheduler
                    .Schedule(6s, [this](TaskContext /*context*/)
                    {
                        DoCast(SPELL_FROT_NOVA);
                    })
                    .Schedule(7s, [this](TaskContext /*context*/)
                    {
                        DoCast(SPELL_BLINK);
                    });
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_frostAI(creature);
    }
};

void AddSC_npc_archmages()
{
    new npc_archmage_fire();
    new npc_archmage_arcanes();
    new npc_archmage_frost();
}
