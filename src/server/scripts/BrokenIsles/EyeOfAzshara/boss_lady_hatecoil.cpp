/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "eye_of_azshara.h"

enum Spells
{
    SPELL_STATIC_NOVA                   = 193597,
    SPELL_FOCUSED_LIGHTING              = 193611,
    
    SPELL_BECKON_STORM                  = 193682,
    SPELL_BECKON_STORM_SUMMON           = 193683,
    
    SPELL_CURSE_OF_THE_WITCH_DEBUFF     = 193698,
    SPELL_CURSE_OF_THE_WITCH_1_TARGET   = 193712,
    SPELL_CURSE_OF_THE_WITCH_3_TARGETS  = 193716,
    SPELL_CURSE_OF_THE_WITCH_KNOCK_BACK = 193700,
    SPELL_CURSE_OF_THE_WITCH_KILL       = 193720,

    SPELL_ARCANE_SHIELDING              = 197868,

    SPELL_SAND_DUNE_GOB                 = 193061,

    SPELL_CRACKLING_THUNDER_CHECK       = 197324,
    SPELL_CRACKLING_THUNDER_DAMAGE      = 197326,

    // Heroic & Mythic
    SPELL_MONSOON_DAMAGE                = 196610,
    SPELL_MONSOON_VISUAL                = 196609,
    SPELL_MONSOON_TARGET                = 196624,
    SPELL_MONSOON_MISSILE               = 196630 // Triggers the spawn of the Monsoon NPC
};

// 91784
struct boss_lady_hatecoil : public BossAI
{
    boss_lady_hatecoil(Creature* creature) : BossAI(creature, DATA_LADY_HATECOIL) { }

    void Reset() override
    {
        BossAI::Reset();

        if (!_arcanistsDead)
            DoCastSelf(SPELL_ARCANE_SHIELDING, true);

        me->GetInstanceScript()->SetData(DATA_RESPAWN_DUNES, 0);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        me->GetInstanceScript()->SetData(DATA_BOSS_DIED, 0);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_BECKON_STORM, 20s);
        events.ScheduleEvent(SPELL_CURSE_OF_THE_WITCH_DEBUFF, 40s);
        events.ScheduleEvent(SPELL_STATIC_NOVA, 14s);
        events.ScheduleEvent(SPELL_FOCUSED_LIGHTING, 29s);
        events.ScheduleEvent(SPELL_CRACKLING_THUNDER_CHECK, 1s);

        if (IsHeroic())
            events.ScheduleEvent(SPELL_MONSOON_TARGET, 15s);
    }

    void DoAction(int32 param) override
    {
        if (param == 1)
        {
            _arcanistsDead = true;
            me->RemoveAurasDueToSpell(SPELL_ARCANE_SHIELDING);
            me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_BECKON_STORM:
            {
                Talk(3);
                DoCastSelf(SPELL_BECKON_STORM, false);
                events.Repeat(45s);
                break;
            }
            case SPELL_CURSE_OF_THE_WITCH_DEBUFF:
            {
                uint32 spellId = urand(0, 1) ? SPELL_CURSE_OF_THE_WITCH_1_TARGET : SPELL_CURSE_OF_THE_WITCH_3_TARGETS;
                DoCastSelf(spellId, false);
                events.Repeat(40s);
                break;
            }
            case SPELL_STATIC_NOVA:
            {
                Talk(2);
                DoCastSelf(SPELL_STATIC_NOVA, false);
                events.Repeat(35s);
                break;
            }
            case SPELL_FOCUSED_LIGHTING:
            {
                DoCastSelf(SPELL_FOCUSED_LIGHTING, false);
                events.Repeat(35s);
                break;
            }
            case SPELL_CRACKLING_THUNDER_CHECK:
            {
                DoCastSelf(SPELL_CRACKLING_THUNDER_CHECK, true);
                events.Repeat(1s);
                break;
            }
            case SPELL_MONSOON_TARGET:
            {
                Talk(6);
                DoCastSelf(SPELL_MONSOON_TARGET, true);
                events.Repeat(25s, 35s);
                break;
            }
        }
    }

private:
    bool _arcanistsDead = false;
};

// 193597
class spell_lady_hatecoil_static_nova : public SpellScript
{
    PrepareSpellScript(spell_lady_hatecoil_static_nova);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                if (target->FindNearestCreature(NPC_SAND_DUNE, 5.0f, true))
                    return true;

            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lady_hatecoil_static_nova::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lady_hatecoil_static_nova::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 193611
class spell_lady_hatecoil_focused_lightning : public SpellScript
{
    PrepareSpellScript(spell_lady_hatecoil_focused_lightning);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (target && target->ToPlayer())
        {
            if (Creature* sandDune = target->FindNearestCreature(NPC_SAND_DUNE, 5.0f, true))
            {
                if (GameObject* dune = target->FindNearestGameObject(GOB_SAND_DUNE, 5.0f))
                {
                    sandDune->RemoveGameObject(dune, true);
                    sandDune->DisappearAndDie();
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lady_hatecoil_focused_lightning::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 193682
class spell_lady_hatecoil_beckon_storm : public SpellScript
{
    PrepareSpellScript(spell_lady_hatecoil_beckon_storm);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_BECKON_STORM_SUMMON, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lady_hatecoil_beckon_storm::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 193712 && 193716
class spell_lady_hatecoil_curse_of_the_witch : public SpellScript
{
    PrepareSpellScript(spell_lady_hatecoil_curse_of_the_witch);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (Unit* caster = GetCaster())
            caster->CastSpell(target, SPELL_CURSE_OF_THE_WITCH_DEBUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lady_hatecoil_curse_of_the_witch::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 193698
class aura_lady_hatecoil_curse_of_the_witch : public AuraScript
{
    PrepareAuraScript(aura_lady_hatecoil_curse_of_the_witch);

    void OnRemove(AuraEffect const* /*auraEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_CURSE_OF_THE_WITCH_KNOCK_BACK, true);
        target->CastSpell(target, SPELL_CURSE_OF_THE_WITCH_KILL, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_lady_hatecoil_curse_of_the_witch::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 197324
class spell_lady_hatecoil_crackling_thunder : public SpellScript
{
    PrepareSpellScript(spell_lady_hatecoil_crackling_thunder);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        if (caster && target && target->GetDistance(Position(-3434.230469f, 4592.095703f, -0.437837f)) > 42.0f)
            caster->CastSpell(target, SPELL_CRACKLING_THUNDER_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lady_hatecoil_crackling_thunder::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 196624
class spell_lady_hatecoil_monsoon_target : public SpellScript
{
    PrepareSpellScript(spell_lady_hatecoil_monsoon_target);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        if (caster && target)
            caster->CastSpell(target, SPELL_MONSOON_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lady_hatecoil_monsoon_target::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 99852
struct npc_lady_hatecoil_monsoon : public ScriptedAI
{
    npc_lady_hatecoil_monsoon(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoCastSelf(SPELL_MONSOON_VISUAL, true);
        me->setFaction(16); // Same faction as Lady Hatecoil

        me->SetSpeed(MOVE_RUN, 2.0f);
        if (Unit* victim = me->SelectNearestPlayer(100.0f))
            me->GetMotionMaster()->MoveFollow(victim, 0.0f, 0.0f);
    }
};

// Spell: 196610
// AT: 100101 (custom)
struct at_lady_hatecoil_monsoon : AreaTriggerAI
{
    at_lady_hatecoil_monsoon(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();

        if (caster)
        {
            if (Player* player = unit->ToPlayer())
                caster->CastSpell(player, SPELL_MONSOON_DAMAGE, true);
            else if (Creature* creature = unit->ToCreature())
            {
                if (creature->GetEntry() == NPC_SAND_DUNE)
                {
                    if (GameObject* dune = creature->FindNearestGameObject(GOB_SAND_DUNE, 5.0f))
                    {
                        creature->RemoveGameObject(dune, true);
                        creature->DisappearAndDie();
                        at->Remove();
                        if (Creature* casterCre = caster->ToCreature())
                            casterCre->DisappearAndDie();
                    }
                }
            }
        }
    }
};

// Criteria ID: 29404
class achievement_stay_salty : public AchievementCriteriaScript
{
   public:
       achievement_stay_salty() : AchievementCriteriaScript("achievement_stay_salty") { }

       bool OnCheck(Player* /*player*/, Unit* /*target*/) override
       {
           // TODO
           return false;
       }
};

void AddSC_boss_lady_hatecoil()
{
    RegisterCreatureAI(boss_lady_hatecoil);
    RegisterCreatureAI(npc_lady_hatecoil_monsoon);

    RegisterSpellScript(spell_lady_hatecoil_static_nova);
    RegisterSpellScript(spell_lady_hatecoil_focused_lightning);
    RegisterSpellScript(spell_lady_hatecoil_beckon_storm);
    RegisterSpellScript(spell_lady_hatecoil_curse_of_the_witch);
    RegisterSpellScript(spell_lady_hatecoil_crackling_thunder);
    RegisterSpellScript(spell_lady_hatecoil_monsoon_target);

    RegisterAuraScript(aura_lady_hatecoil_curse_of_the_witch);

    RegisterAreaTriggerAI(at_lady_hatecoil_monsoon);

    new achievement_stay_salty();
}
