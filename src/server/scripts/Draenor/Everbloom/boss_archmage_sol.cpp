/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "the_everbloom.h"

enum eArchmageTalks
{
    KirinTorMageIntro     = 30,     ///< No...you Cant...its...i Cant Fight It!(45481)
    KirinTorMageAggro     = 31,     ///< Yes, Flee! Fire The Vines! They Control Us All!(45479)
    KirinTorMageSpell01   = 32,     ///< Yes, Fire! Fire Will Burn Away The Contagion.(45484)
    KirinTorMageSpell02   = 33,     ///< Surely The Cold Make Them Wither?(45485)
    KirinTorMageSpell03   = 34,     ///< Get Away..get Away!(45486)
    KirinTorMageKill01    = 35,     ///< No! They Will Take You Too!(45482)
    KirinTorMageKill02    = 36,     ///< You Musnt Give Them Anoter Host!(45483)
    KirinTorMageDeath     = 37,     ///< Burn My Body. Its  The Only Way To Stop Them.(45480)
};

enum ArchmageEnums
{
    SPELL_BARRIER               = 170150,
    SPELL_LIVING_ORGANISM       = 166719,
    SPELL_DESPAWN_AREA_TRIGGERS = 138175,
    SPELL_THOUGHT_CHRYSALIS     = 166474,
    SPELL_FIREBALL              = 166464,
    SPELL_FROSTBOLT             = 166465,
    SPELL_ARCANE_BURST          = 166466,
    SPELL_FIREBLOOM             = 166572,
    SPELL_FIREBLOOM_TARGET      = 166562,
    SPELL_FROZEN_RAIN           = 166913,
    SPELL_PARASITIC_GROWTH      = 168885,
    SPELL_PARASITIC_INJECTION   = 166891,
    SPELL_PRIMAL_FIRE           = 166475,
    SPELL_PRIMAL_FROST          = 166476,
    SPELL_PRIMAL_ARCANE         = 166477,
    SPELL_FIRE_SPORES           = 168905,
    SPELL_FROST_SPORES          = 168906,

    NPC_FROZEN_RAIN             = 82846,
    NPC_SPORE_FIRE              = 84386,
    NPC_SPORE_FROST             = 84387,
};

/// Archmage Sol - 82682
class boss_archmage_sol : public CreatureScript
{
public:
    boss_archmage_sol() : CreatureScript("boss_archmage_sol") { }

    struct boss_archmage_sol_AI : public BossAI
    {
        boss_archmage_sol_AI(Creature* creature) : BossAI(creature, DATA_ARCHMAGE_SOL)
        {
            casters.clear();
            introDone = false;

            DoCast(me, SPELL_BARRIER);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void Reset() override
        {
            _Reset();

            frozenRain = NULL;

            CheckIntroTimer = 500;
            thoughtChrysalisTimer = 500;
            fireballTimer = 1000;
            frostboltTimer = 1000;
            arcaneBurstTimer = 1000;
            firebloomTimer = 12000;
            frozenRainTimer = 16000;
            frozenRainTriggerTimer = 0;
            changeSchoolTimer = 33000;

            school = 0;
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            _EnterCombat();
            Talk(eArchmageTalks::KirinTorMageAggro);
            DoCast(me, SPELL_LIVING_ORGANISM);
        }

        void KilledUnit(Unit* attacker) override
        {
            if (attacker->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (roll_chance_i(50))
                    Talk(eArchmageTalks::KirinTorMageKill01);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(eArchmageTalks::KirinTorMageDeath);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsPlayer() && me->IsWithinDistInMap(who, 30.0f) && introDone)
            {
                if (me->GetVictim())
                    return;

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveAurasDueToSpell(SPELL_BARRIER);
                DoCast(me, SPELL_DESPAWN_AREA_TRIGGERS);

                if (me->CanStartAttack(who, false))
                    AttackStart(who);

                Talk(eArchmageTalks::KirinTorMageIntro);
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
                case 170193:
                case 170194:
                case 170195:
                    casters.push_back(caster);
                    break;
                default:
                    break;
            }
        }

        void SpellInterrupted(uint32 spellId, uint32 /*unTimeMs*/) override
        {
            if (spellId == SPELL_PARASITIC_GROWTH)
            {
                me->RemoveAurasDueToSpell(SPELL_PARASITIC_GROWTH);

                Position pos;
                school++;
                switch (school)
                {
                    case 1: // Frost
                        me->RemoveAurasDueToSpell(SPELL_PRIMAL_FIRE);
                        DoCast(me, SPELL_PRIMAL_FROST);
                        DoCast(me, SPELL_FIRE_SPORES);
                        pos = me->GetRandomNearPosition(30.0f);
                        me->SummonCreature(NPC_SPORE_FIRE, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
                        break;
                    case 2: // Arcane
                        me->RemoveAurasDueToSpell(SPELL_PRIMAL_FROST);
                        DoCast(me, SPELL_PRIMAL_ARCANE);
                        DoCast(me, SPELL_FROST_SPORES);
                        pos = me->GetRandomNearPosition(30.0f);
                        me->SummonCreature(NPC_SPORE_FROST, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
                        break;
                }

                DoCast(me, SPELL_PARASITIC_INJECTION);
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!me->IsInCombat() && !introDone)
            {
                if (CheckIntroTimer <= diff)
                {
                    CheckIntroTimer = 500;
                    for (std::list<Unit*>::iterator itr = casters.begin(); itr != casters.end(); ++itr)
                    {
                        if ((*itr)->IsAlive())
                            break;
                        else
                            introDone = true;
                    }
                }
                else
                    CheckIntroTimer -= diff;
            }

            if (!introDone)
                return;

            // Boss AI
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (thoughtChrysalisTimer <= diff)
            {
                thoughtChrysalisTimer = urand(34000, 38000);
                DoCast(me, SPELL_THOUGHT_CHRYSALIS);
            }
            else
                thoughtChrysalisTimer -= diff;

            switch (school)
            {
                case 0:
                    if (fireballTimer <= diff)
                    {
                        fireballTimer = 4000;
                        DoCast(me->GetVictim(), SPELL_FIREBALL);
                    }
                    else
                        fireballTimer -= diff;

                    if (firebloomTimer <= diff)
                    {
                        firebloomTimer = 12000;
                        DoCast(me, SPELL_FIREBLOOM);
                    }
                    else
                        firebloomTimer -= diff;
                    break;
                case 1:
                    if (frostboltTimer <= diff)
                    {
                        frostboltTimer = 4000;
                        DoCast(me->GetVictim(), SPELL_FROSTBOLT);
                    }
                    else
                        frostboltTimer -= diff;

                    if (frozenRainTimer <= diff)
                    {
                        frozenRainTimer = 11000;
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                        {
                            frozenRainTriggerTimer = 1500;
                            frozenRain = me->SummonCreature(NPC_FROZEN_RAIN, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 300 * IN_MILLISECONDS);
                        }
                    }
                    else
                        frozenRainTimer -= diff;

                    break;
                case 2:
                    if (arcaneBurstTimer <= diff)
                    {
                        arcaneBurstTimer = 4000;
                        DoCast(me, SPELL_ARCANE_BURST);
                    }
                    else
                        arcaneBurstTimer -= diff;
                    break;
                default:
                    break;
            }

            if (frozenRainTriggerTimer > 0)
            {
                if (frozenRainTriggerTimer <= diff)
                {
                    frozenRainTriggerTimer = 0;
                    if (frozenRain)
                        DoCast(frozenRain, ArchmageEnums::SPELL_FROZEN_RAIN);

                    frozenRain = NULL;
                }
                else
                    frozenRainTriggerTimer -= diff;
            }

            DoMeleeAttackIfReady();

            if (school >= 2)
                return;

            if (changeSchoolTimer <= diff)
            {
                changeSchoolTimer = 33000;
                DoCast(me, SPELL_PARASITIC_GROWTH);
            }
            else
                changeSchoolTimer -= diff;
        }

        private:

            bool introDone;

            uint8 school;

            uint32 CheckIntroTimer;
            uint32 thoughtChrysalisTimer;
            uint32 fireballTimer;
            uint32 frostboltTimer;
            uint32 arcaneBurstTimer;
            uint32 firebloomTimer;
            uint32 frozenRainTimer;
            uint32 frozenRainTriggerTimer;
            uint32 changeSchoolTimer;

            std::list<Unit*> casters;

            Creature* frozenRain;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_archmage_sol_AI(creature);
    }
};

enum FrozenRainEnums
{
    SPELL_FROZEN_RAIN_NPC = 166723,
};

/// Frozen Rain - 82846
class npc_frozen_rain : public CreatureScript
{
public:
    npc_frozen_rain() : CreatureScript("npc_frozen_rain") { }

    struct npc_frozen_rainAI : public Scripted_NoMovementAI
    {
        npc_frozen_rainAI(Creature* creature) : Scripted_NoMovementAI(creature) { }

        void Reset() override
        {
            DoCast(me, FrozenRainEnums::SPELL_FROZEN_RAIN_NPC);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_frozen_rainAI(creature);
    }
};

class spell_firebloom_target : public SpellScriptLoader
{
public:
    spell_firebloom_target() : SpellScriptLoader("spell_firebloom_target") { }

    class spell_firebloom_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_firebloom_target_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                GetCaster()->CastSpell(target->GetPosition(), SPELL_FIREBLOOM_TARGET, false);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_firebloom_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_firebloom_target_SpellScript();
    }
};

Position ArchmagePositionBarrier[5] =
{
    { 609.4202f, 1550.811f, 118.6338f, 0.000000f },
    { 603.8663f, 1564.918f, 117.6480f, 0.000000f },
    { 616.7986f, 1573.880f, 119.0866f, 0.000000f },
    { 630.5243f, 1566.682f, 119.2359f, 0.000000f },
    { 627.4792f, 1552.241f, 121.7746f, 0.000000f },
};

class aura_archmage_barrier : public SpellScriptLoader
{
public:
    aura_archmage_barrier() : SpellScriptLoader("aura_archmage_barrier") { }

    class aura_archmage_barrier_AuraScript : public AuraScript
    {
        PrepareAuraScript(aura_archmage_barrier_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            for (uint8 i = 0; i < 5; i++)
                GetCaster()->CastSpell(ArchmagePositionBarrier[i].m_positionX, ArchmagePositionBarrier[i].m_positionY, ArchmagePositionBarrier[i].m_positionZ, 170146, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(aura_archmage_barrier_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new aura_archmage_barrier_AuraScript();
    }
};

/*######
## at_frozen_rain
######*/

enum FrozenATEnums
{
    SPELL_FROZEN_RAIN_DAMAGE            = 166726,
};

class at_frozen_rain : public AreaTriggerAI
{
public:
    at_frozen_rain(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Creature* archmage = GetClosestCreatureWithEntry(unit, NPC_ARCHMAGE_SOL, 100.0f))
            if (unit->IsPlayer() && !unit->HasAura(SPELL_FROZEN_RAIN_DAMAGE))
                archmage->CastSpell(unit, SPELL_FROZEN_RAIN_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_FROZEN_RAIN_DAMAGE);
    }
};

void AddSC_boss_sol()
{
    new boss_archmage_sol();
    new npc_frozen_rain();
    new spell_firebloom_target();
    new aura_archmage_barrier();
    RegisterAreaTriggerAI(at_frozen_rain);
}
