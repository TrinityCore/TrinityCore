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

enum eWitherbarkTalks
{
    WitherbarkAggro   = 4, ///< So... Thirsty(45108)
    WitherbarkKill01  = 5, ///< Return to the earth...(45110)
    WitherbarkKill02  = 6, ///< Feed my roots.(45111) 
    WitherbarkSpell01 = 7, ///< Refreshed.(45112)
    WitherbarkSpell02 = 8, ///< I Cannot Be Stopped.(45113)
    WitherbarkDeath   = 9 ///< Arghh...(45109)
};

Position PositionAqueousMobs[6] =
{
    { 376.2222f, 1636.727f, 86.56787f, 0.000000f },
    { 349.9809f, 1594.229f, 86.56787f, 0.000000f },
    { 362.7083f, 1599.984f, 86.56787f, 0.000000f },
    { 366.5365f, 1614.205f, 86.56787f, 0.000000f },
    { 434.3351f, 1661.589f, 86.56787f, 0.000000f },
    { 387.4913f, 1650.116f, 86.56787f, 0.000000f },
};

enum WitherbarkEnums
{
    SPELL_PETRIFIED_BARK            = 164713,
    SPELL_CANCEL_PETRIFIED_BARK     = 164719,
    SPELL_ENERGIZE                  = 164438,
    SPELL_AGITATED_WATER_1          = 177733,
    SPELL_PARCHED_GASP              = 164357,
    SPELL_BRITTLE_BARK              = 164275,
    SPELsummon_AQUEOUS_GLOBULE      = 164437,
    SPELL_NOXIOUS_VINES             = 164712,
};

/// Witherbark - 81522
class boss_witherbark : public CreatureScript
{
public:
    boss_witherbark() : CreatureScript("boss_witherbark") { }

    struct boss_witherbarkAI : public BossAI
    {
        boss_witherbarkAI(Creature* creature) : BossAI(creature, DATA_WITHERBARK)
        {
            DoCast(me, SPELL_PETRIFIED_BARK);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void Reset() override
        {
            intro = false;
            if (instance && instance->GetBossState(DATA_WITHERBARK) != NOT_STARTED && instance->GetBossState(DATA_WITHERBARK) != TO_BE_DECIDED)
                intro = true;

            _Reset();

            aqueousIntro = 0;
            aqueous = 0;
            AgitatedWaterTimer = 4000;
            ParchedGaspTimer = 7000;
            BrittleBarkTimer = 30000;
            BrittleBark2WaveTimer = 0;
            NoxiousVinesTimer = 5000;
        }

        void JustReachedHome() override
        {
            if (!intro)
            {
                DoCast(me, SPELL_PETRIFIED_BARK);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            }
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_ENERGIZE:
                    if (aqueousIntro < 3)
                        aqueousIntro++;

                    if (aqueous < 6)
                        aqueous++;

                    if (!intro && aqueousIntro >= 3)
                    {
                        DoCast(me, SPELL_CANCEL_PETRIFIED_BARK);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        intro = true;
                    }

                    if (intro && aqueous >= 6)
                        me->RemoveAurasDueToSpell(SPELL_BRITTLE_BARK);

                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim() || !intro)
                return;

            if (AgitatedWaterTimer <= diff)
            {
                AgitatedWaterTimer = urand (6000, 7000);
                DoCast(me, SPELL_AGITATED_WATER_1);
            }
            else
                AgitatedWaterTimer -= diff;

            if (ParchedGaspTimer <= diff)
            {
                ParchedGaspTimer = 12000;
                DoCast(me, SPELL_PARCHED_GASP);
            }
            else
                ParchedGaspTimer -= diff;

            if (BrittleBarkTimer <= diff)
            {
                aqueous = 0;
                BrittleBarkTimer = 90000;
                DoCast(me, SPELL_BRITTLE_BARK);

                for (uint8 i = 0; i < 3; i++)
                    me->CastSpell(PositionAqueousMobs[i].m_positionX, PositionAqueousMobs[i].m_positionY, PositionAqueousMobs[i].m_positionZ, SPELsummon_AQUEOUS_GLOBULE, true);

                BrittleBark2WaveTimer = 15000;
            }
            else
                BrittleBarkTimer -= diff;

            if (BrittleBark2WaveTimer)
            {
                if (BrittleBark2WaveTimer <= diff)
                {
                    for (uint8 i = 3; i < 6; i++)
                        me->CastSpell(PositionAqueousMobs[i].m_positionX, PositionAqueousMobs[i].m_positionY, PositionAqueousMobs[i].m_positionZ, SPELsummon_AQUEOUS_GLOBULE, true);

                    BrittleBark2WaveTimer = 0;
                }
                else
                    BrittleBark2WaveTimer -= diff;
            }

            if (NoxiousVinesTimer <= diff)
            {
                NoxiousVinesTimer = 11000;
                DoCast(me, SPELL_NOXIOUS_VINES);
            }
            else
                NoxiousVinesTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:

            uint8 aqueousIntro;
            uint8 aqueous;
            bool intro;
            uint32 AgitatedWaterTimer;
            uint32 ParchedGaspTimer;
            uint32 BrittleBarkTimer;
            uint32 BrittleBark2WaveTimer;
            uint32 NoxiousVinesTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_witherbarkAI(creature);
    }
};

enum EnchantedWaterEnums
{
    SPELL_AGITATED_WATER_2 = 177732,
};

/// Enchanted Waters - 88862
class mob_enchanted_water : public CreatureScript
{
public:
    mob_enchanted_water() : CreatureScript("mob_enchanted_water") {}

    struct mob_enchanted_waterAI : public Scripted_NoMovementAI
    {
        mob_enchanted_waterAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        void UpdateAI(const uint32 /*diff*/) override
        {
            if (!me->IsInCombat())
            {
                if (instance && instance->GetBossState(DATA_WITHERBARK) == IN_PROGRESS)
                    DoZoneInCombat();
            }
        }

        private:

            InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_enchanted_waterAI(creature);
    }
};

class spell_agitated_water_trig : public SpellScriptLoader
{
public:
    spell_agitated_water_trig() : SpellScriptLoader("spell_agitated_water_trig") { }

    class spell_agitated_water_trig_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_agitated_water_trig_SpellScript);

        void HandleForceCast(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            if (GetHitUnit())
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_AGITATED_WATER_2, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_agitated_water_trig_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_agitated_water_trig_SpellScript;
    }
};

class spell_agitated_water : public SpellScriptLoader
{
public:
    spell_agitated_water() : SpellScriptLoader("spell_agitated_water") { }

    class spell_agitated_water_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_agitated_water_SpellScript);

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            targets.clear();

            if (Unit* target = GetCaster()->ToCreature()->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 50000.0f, true))
                targets.push_back(target);
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), GetSpellValue()->EffectBasePoints[effIndex]);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_agitated_water_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_agitated_water_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_agitated_water_SpellScript;
    }
};

/// Aqueous Globue  - 81638
class npc_aqueous_globule_witherbark : public CreatureScript
{
public:
    npc_aqueous_globule_witherbark() : CreatureScript("npc_aqueous_globule_witherbark") {}

    struct npc_aqueous_globule_witherbarkAI : public ScriptedAI
    {
        npc_aqueous_globule_witherbarkAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, 164988);
        }

        void Reset() override
        {
            visualSpell = 1000;
        }

        void AttackStart(Unit* /*who*/) override { }

        void UpdateAI(const uint32 diff) override
        {
            if (visualSpell)
            {
                if (visualSpell <= diff)
                {
                    visualSpell = 0;
                    DoCast(me, 164391);
                    if (Creature* witherbark = me->FindNearestCreature(81522, 1000.0f))
                        me->GetMotionMaster()->MovePoint(0, witherbark->GetPositionX(), witherbark->GetPositionY(), witherbark->GetPositionZ());
                }
                else
                    visualSpell -= diff;
            }
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (point)
            {
                case 0:
                    DoCast(me, 164538);
                    DoCast(me, SPELL_ENERGIZE);
                    me->DespawnOrUnsummon(2000);
                    break;
            }
        }

        private:
            uint32 visualSpell;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aqueous_globule_witherbarkAI(creature);
    }
};

/// Unchecked Growth  - 81564
class npc_unchecked_growth : public CreatureScript
{
public:
    npc_unchecked_growth() : CreatureScript("npc_unchecked_growth") {}

    struct npc_unchecked_growthAI : public ScriptedAI
    {
        npc_unchecked_growthAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, 164296);
        }

        void Reset() override
        {
            timer = 1000;
        }

        void AttackStart(Unit* /*who*/) override { }

        void UpdateAI(const uint32 diff) override
        {
            if (timer)
            {
                if (timer <= diff)
                {
                    timer = 0;
                    if (Creature* witherbark = me->FindNearestCreature(81522, 1000.0f))
                    {
                        if (Unit* target = witherbark->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 50000.0f, true))
                            me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                    }
                }
                else
                    timer -= diff;
            }
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (point)
            {
                case 0:
                    DoCast(me, 164290);
                    DoCast(me, 164375);
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    break;
            }
        }

        private:
            uint32 timer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_unchecked_growthAI(creature);
    }
};

class spell_unchecked_growth : public SpellScriptLoader
{
public:
    spell_unchecked_growth() : SpellScriptLoader("spell_unchecked_growth") { }

    class spell_unchecked_growth_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_unchecked_growth_SpellScript);

        void OnHit(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit())
                GetCaster()->GetMotionMaster()->MovePoint(0, GetHitUnit()->GetPositionX(), GetHitUnit()->GetPositionY(), GetHitUnit()->GetPositionZ());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_unchecked_growth_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_unchecked_growth_SpellScript;
    }
};

class at_unchecked_growth : public AreaTriggerAI
{
    public:
        at_unchecked_growth(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        /*void OnCreate() override
        {
            at->SetCustomRadius(5.0f);
        }*/

        void OnUnitEnter(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
                if (caster->IsHostileTo(unit) && !unit->HasAura(164294))
                    caster->CastSpell(unit, 164294);
        }

        void OnUnitExit(Unit* unit) override
        {
            unit->RemoveAurasDueToSpell(164294);
        }
};

enum AqueousGlobuleEnums
{
    SPELL_AQUEOUS_BURST = 164990,
};

/// Aqueous Globue  - 81821
class npc_aqueous_globule : public CreatureScript
{
public:
    npc_aqueous_globule() : CreatureScript("npc_aqueous_globule") {}

    struct npc_aqueous_globuleAI : public ScriptedAI
    {
        npc_aqueous_globuleAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            checkMob = 300;
            checkBoss = 200;
        }

        void AttackStart(Unit* /*who*/) override { }

        void UpdateAI(const uint32 diff) override
        {
            if (checkMob)
            {
                if (checkMob <= diff)
                {
                    checkMob = 300;
                    if (me->FindNearestCreature(81819, 10.0f))
                        return;

                    if (me->FindNearestCreature(81820, 10.0f))
                        return;

                    if (Unit* boss = me->FindNearestCreature(81522, 100.0f))
                    {
                        me->RemoveAurasDueToSpell(164715);
                        me->GetMotionMaster()->MovePoint(0, boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ());
                        checkMob = 0;
                    }
                }
                else
                    checkMob -= diff;
            }

            if (checkBoss)
            {
                if (checkBoss <= diff)
                {
                    checkBoss = 200;
                    if (me->FindNearestCreature(81522, 0.5f))
                    {
                        DoCast(me, SPELL_AQUEOUS_BURST);
                        DoCast(me, SPELL_ENERGIZE);
                        me->DespawnOrUnsummon(2000);
                        checkBoss = 0;
                    }
                }
                else
                    checkBoss -= diff;
            }
        }

        private:

        uint32 checkMob;
        uint32 checkBoss;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aqueous_globuleAI(creature);
    }
};

void AddSC_boss_witherbark()
{
    new boss_witherbark();
    new mob_enchanted_water();
    new spell_agitated_water_trig();
    new spell_agitated_water();
    new npc_aqueous_globule_witherbark();
    new npc_unchecked_growth();
    new spell_unchecked_growth();
    RegisterAreaTriggerAI(at_unchecked_growth);
    new npc_aqueous_globule();
}
