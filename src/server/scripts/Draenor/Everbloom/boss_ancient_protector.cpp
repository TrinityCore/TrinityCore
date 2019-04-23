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
#include "Spell.h"
#include "SpellScript.h"
#include "the_everbloom.h"

static void StartAncientProtectors(InstanceScript* instance)
{
    if (!instance)
        return;

    if (Creature* l_Gola = instance->GetCreature(DATA_LIFE_WARDEN_GOLA))
        l_Gola->SetInCombatWithZone();

    if (Creature* l_Dulhu = instance->GetCreature(DATA_DULHU))
        l_Dulhu->SetInCombatWithZone();

   if (Creature* l_Telu = instance->GetCreature(DATA_EARTHSHAPER_TELU))
        l_Telu->SetInCombatWithZone();
}

enum LifeWardenGolaEnums
{
    SPELL_BOTANI_WATER_COSMETIC_CHANNEL = 173380,
    SPELL_WATER_BOLT                    = 168092,
    SPELL_REVITALIZING_WATERS           = 168082,
};

/// Life Warden Gola - 83892
class boss_life_warden : public CreatureScript
{
public:
    boss_life_warden() : CreatureScript("boss_life_warden") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_life_wardenAI(pCreature);
    }

    struct boss_life_wardenAI : public BossAI
    {
        boss_life_wardenAI(Creature* pCreature) : BossAI(pCreature, DATA_ANCIENT_PROTECTORS)
        {
            DoCast(me, SPELL_BOTANI_WATER_COSMETIC_CHANNEL);
        }

        void Reset() override
        {
            _Reset();
            WaterBoltTimer = 0;
            RevitalizingWatersTimer = 18000;
        }

        void EnterCombat(Unit * /*who*/) override
        {
            me->RemoveAurasDueToSpell(SPELL_BOTANI_WATER_COSMETIC_CHANNEL);
            _EnterCombat();
            StartAncientProtectors(instance);
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            summons.DespawnAll();
            
            if (Creature* l_Dulhu = instance->GetCreature(DATA_DULHU))
                if (Creature* l_Telu = instance->GetCreature(DATA_EARTHSHAPER_TELU))
                    if (l_Dulhu->isDead() && l_Telu->isDead())
                        instance->SetBossState(DATA_ANCIENT_PROTECTORS, DONE);
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            DoCast(me, SPELL_BOTANI_WATER_COSMETIC_CHANNEL);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, true))
                DoStartNoMovement(who);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (WaterBoltTimer <= diff)
            {
                WaterBoltTimer = 2000;
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_WATER_BOLT);
            }
            else
                WaterBoltTimer -= diff;

            if (RevitalizingWatersTimer <= diff)
            {
                RevitalizingWatersTimer = 70000;
                DoCast(me, SPELL_REVITALIZING_WATERS);
            }
            else
                RevitalizingWatersTimer -= diff;
        }

        private:

            uint32 WaterBoltTimer;
            uint32 RevitalizingWatersTimer;
    };
};

enum EarthshaperTeluEnums
{
    SPELL_BOTANI_NATURE_COSMETIC_CHANNEL    = 172325,
    SPELL_NATURE_WRATH                      = 168040,
    SPELL_BRIARSKIN                         = 168041,
    SPELL_BRAMBLE_PATCH_1                   = 177497,
    SPELL_BRAMBLE_PATCH_2                   = 167977,
};

/// Earthshaper Telu - 83893
class boss_earthshaper_telu : public CreatureScript
{
public:
    boss_earthshaper_telu() : CreatureScript("boss_earthshaper_telu") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_earthshaper_teluAI(pCreature);
    }

    struct boss_earthshaper_teluAI : public BossAI
    {
        boss_earthshaper_teluAI(Creature* pCreature) : BossAI(pCreature, DATA_ANCIENT_PROTECTORS)
        {
            DoCast(me, SPELL_BOTANI_NATURE_COSMETIC_CHANNEL);
        }

        void Reset() override
        {
            _Reset();
            NatureWrathTimer = 0;
            BriarskinTimer = 26000;
            BramblePatchTimer = 12000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->RemoveAurasDueToSpell(SPELL_BOTANI_NATURE_COSMETIC_CHANNEL);
            _EnterCombat();
            StartAncientProtectors(instance);
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            summons.DespawnAll();

            if (Creature* l_Gola = instance->GetCreature(DATA_LIFE_WARDEN_GOLA))
                if (Creature* l_Dulhu = instance->GetCreature(DATA_DULHU))
                    if (l_Gola->isDead() && l_Dulhu->isDead())
                        instance->SetBossState(DATA_ANCIENT_PROTECTORS, DONE);
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            DoCast(me, SPELL_BOTANI_NATURE_COSMETIC_CHANNEL);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, true))
                DoStartNoMovement(who);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (NatureWrathTimer <= diff)
            {
                NatureWrathTimer = 2000;
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_NATURE_WRATH);
            }
            else
                NatureWrathTimer -= diff;

            if (BriarskinTimer <= diff)
            {
                BriarskinTimer = urand(30000, 35000);
                DoCast(me, SPELL_BRIARSKIN);
            }
            else
                BriarskinTimer -= diff;

            if (BramblePatchTimer <= diff)
            {
                BramblePatchTimer = 21000;
                NatureWrathTimer = 5000;
                DoCast(me, SPELL_BRAMBLE_PATCH_1, true);
            }
            else
                BramblePatchTimer -= diff;
        }

        private:

        uint32 NatureWrathTimer;
        uint32 BriarskinTimer;
        uint32 BramblePatchTimer;
    };
};

enum BramblePatchEnums
{
    SPELL_BRAMBLE_PATCH_VISUAL = 167967,
};

class npc_bramble_patch : public CreatureScript
{
public:
    npc_bramble_patch() : CreatureScript("npc_bramble_patch") { }

    struct npc_bramble_patchAI : public ScriptedAI
    {
        npc_bramble_patchAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, SPELL_BRAMBLE_PATCH_VISUAL);
        }

        void AttackStart(Unit* /*who*/) override { }
        void UpdateAI(uint32 /*uiDiff*/) override { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bramble_patchAI(creature);
    }
};

class spell_bramble_patch : public SpellScriptLoader
{
public:
    spell_bramble_patch() : SpellScriptLoader("spell_bramble_patch") { }

    class spell_bramble_patch_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_bramble_patch_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex]);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_bramble_patch_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_bramble_patch_SpellScript;
    }
};

class at_bramble_patch : public AreaTriggerAI
{
public:
    at_bramble_patch(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        //at->SetCustomRadius(4.5f);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (caster->IsHostileTo(unit) && !unit->HasAura(SPELL_BRAMBLE_PATCH_2))
                caster->CastSpell(unit, SPELL_BRAMBLE_PATCH_2);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_BRAMBLE_PATCH_2);
    }
};


enum DulhuEnums
{
    SPELL_READY_UNARMED     = 173366,
    SPELL_RENDING_CHARGE_1  = 168186,
    SPELL_RENDING_CHARGE_2  = 168187,
    SPELL_NOXIOUS_ERUPTION  = 175997,
    SPELL_GRASPING_VINE_1   = 168375,
    SPELL_GRASPING_VINE_2   = 168376,
    SPELL_GRASPING_VINE_3   = 168377,
    SPELL_GRASPING_VINE_4   = 168378,
    SPELL_SLASH             = 168383,
};

/// Dulhu - 83894
class boss_dulhu : public CreatureScript
{
public:
    boss_dulhu() : CreatureScript("boss_dulhu") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_dulhuAI(pCreature);
    }

    struct boss_dulhuAI : public BossAI
    {
        boss_dulhuAI(Creature* pCreature) : BossAI(pCreature, DATA_ANCIENT_PROTECTORS)
        {
            DoCast(me, SPELL_READY_UNARMED);
        }

        void Reset() override
        {
            _Reset();
            
            RendingChargeTimer = 7000;
            chargeVictim = NULL;
            NoxiousEruptionTimer = 10000;
            GraspingVineTimer = 22000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            StartAncientProtectors(instance);
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            DoCast(me, SPELL_READY_UNARMED);     
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            if (Creature* l_Gola = instance->GetCreature(DATA_LIFE_WARDEN_GOLA))
                if (Creature* l_Telu = instance->GetCreature(DATA_EARTHSHAPER_TELU))
                    if (l_Gola->isDead() && l_Telu->isDead())
                        instance->SetBossState(DATA_ANCIENT_PROTECTORS, DONE);
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (point)
            {
                case 1005:
                case 1003:
                    if (chargeVictim)
                    {
                        DoCast(chargeVictim, SPELL_RENDING_CHARGE_2);
                        chargeVictim = NULL;
                    }
                    break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (RendingChargeTimer <= diff)
            {
                RendingChargeTimer = urand(20000, 22000);
                chargeVictim = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (chargeVictim)
                    DoCast(chargeVictim, SPELL_RENDING_CHARGE_1);
            }
            else
                RendingChargeTimer -= diff;

            if (NoxiousEruptionTimer <= diff)
            {
                NoxiousEruptionTimer = urand(16000, 17000);
                DoCast(me, SPELL_NOXIOUS_ERUPTION);
            }
            else
                NoxiousEruptionTimer -= diff;

            if (GraspingVineTimer <= diff)
            {
                GraspingVineTimer = urand(30000, 32000);
                DoCast(me, SPELL_GRASPING_VINE_1, true);
            }
            else
                GraspingVineTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:

            uint32 RendingChargeTimer;
            Unit* chargeVictim;
            uint32 NoxiousEruptionTimer;
            uint32 GraspingVineTimer;
    };
};

class spell_grasping_vine : public SpellScriptLoader
{
public:
    spell_grasping_vine() : SpellScriptLoader("spell_grasping_vine") { }

    class spell_grasping_vine_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_grasping_vine_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex]);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_grasping_vine_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_grasping_vine_SpellScript;
    }
};

class aura_grasping_vine : public SpellScriptLoader
{
public:
    aura_grasping_vine() : SpellScriptLoader("aura_grasping_vine") { }

    class aura_grasping_vine_AuraScript : public AuraScript
    {
        PrepareAuraScript(aura_grasping_vine_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                GetCaster()->CastSpell(target, SPELL_GRASPING_VINE_3);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(aura_grasping_vine_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new aura_grasping_vine_AuraScript();
    }
};

class spell_grasping_vine_jump : public SpellScriptLoader
{
public:
    spell_grasping_vine_jump() : SpellScriptLoader("spell_grasping_vine_jump") { }

    class spell_grasping_vine_jump_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_grasping_vine_jump_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            if (Unit* target = GetHitUnit())
                target->CastSpell(GetCaster(), GetSpellValue()->EffectBasePoints[effIndex]);

            GetCaster()->CastSpell(GetCaster(), SPELL_SLASH);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_grasping_vine_jump_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_grasping_vine_jump_SpellScript;
    }
};

void AddSC_boss_ancient_protectors()
{
    new boss_life_warden();
    new boss_earthshaper_telu();
    new npc_bramble_patch();
    new spell_bramble_patch();
    RegisterAreaTriggerAI(at_bramble_patch);
    new boss_dulhu();
    new spell_grasping_vine();
    new aura_grasping_vine();
    new spell_grasping_vine_jump();
}
