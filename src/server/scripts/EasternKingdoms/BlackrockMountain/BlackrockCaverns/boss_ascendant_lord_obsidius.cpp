/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "blackrock_caverns.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum Text
{
    // Ascendant Lord Obsidius
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_TRANSFORMATION          = 2,
    SAY_DEATH                   = 3,
    SAY_ANNOUNCE_TRANSFORMATION = 4
};

enum Spells
{
    // Ascendant Lord Obsidius
    SPELL_STOP_HEART            = 82393,
    SPELL_STONE_BLOW            = 76185,
    SPELL_THUNDERCLAP           = 76186,
    SPELL_TRANSFORMATION        = 76196,

    // Shadow of Obsidius
    SPELL_SHADOWY_CORRUPTION    = 75054,
};

#define SPELL_TWILIGHT_CORRUPTION RAID_MODE<int32>(76188, 93613)

enum SpellVisualKits
{
    SPELL_VISUAL_SPOTTED = 14893
};

enum Events
{
    // Ascendant Lord Obsidius
    EVENT_FINISH_RAZ_INTRO = 1,
    EVENT_STONE_BLOW ,
    EVENT_TWILIGHT_CORRUPTION,
    EVENT_THUNDERCLAP,
};

enum Data
{
    DATA_DEAD_ELEMENTAL_WARDEN = 0,
    DATA_ASCENDANT_DESCENDING
};

Position const ShadowOfObsidiusPositions[] =
{
    { 331.6267f, 563.5573f, 66.08982f, 3.141593f },
    { 332.2361f, 544.75f,   66.08982f, 3.141593f },
    { 324.6545f, 554.1979f, 66.10867f, 3.141593f }
};

struct boss_ascendant_lord_obsidius : public BossAI
{
    boss_ascendant_lord_obsidius(Creature* creature) : BossAI(creature, DATA_ASCENDANT_LORD_OBSIDIUS) { }

    void Reset() override
    {
        _Reset();
        _transformationCount = 0;
        _deadElementalWardenCount = 0;
        _achievementEnligible = true;

        if (instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_OBSIDIUS)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_STUNNED);
            me->RemoveAurasDueToSpell(SPELL_SHADOWY_CORRUPTION);
        }

        for (uint8 i = 0; i < (IsHeroic() ? 3 : 2); i++)
        {
            if (Creature* shadow = DoSummon(NPC_SHADOW_OF_OBSIDIUS, ShadowOfObsidiusPositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
            {
                if (instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_OBSIDIUS)
                {
                    shadow->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                    shadow->RemoveAurasDueToSpell(SPELL_SHADOWY_CORRUPTION);
                }
            }
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_STONE_BLOW, 8s);
        events.ScheduleEvent(EVENT_TWILIGHT_CORRUPTION, 12s);

        if (IsHeroic())
            events.ScheduleEvent(EVENT_THUNDERCLAP, 15s + 600ms);

        for (ObjectGuid guid : summons)
            if (Creature* shadow = ObjectAccessor::GetCreature(*me, guid))
                shadow->AI()->DoZoneInCombat();
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_CORRUPTION);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_CORRUPTION);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if ((me->HealthBelowPctDamaged(69, damage) && _transformationCount == 0)
            || (me->HealthBelowPctDamaged(34, damage) && _transformationCount == 1))
        {
            Talk(SAY_TRANSFORMATION);
            Talk(SAY_ANNOUNCE_TRANSFORMATION);
            DoCastAOE(SPELL_TRANSFORMATION, true);
            _transformationCount++;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
            case DATA_DEAD_ELEMENTAL_WARDEN:
                _deadElementalWardenCount++;
                if (_deadElementalWardenCount == 7)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_STUNNED);
                    me->RemoveAurasDueToSpell(SPELL_SHADOWY_CORRUPTION);

                    for (ObjectGuid guid : summons)
                    {
                        if (Creature* shadow = ObjectAccessor::GetCreature(*me, guid))
                        {
                            shadow->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            shadow->RemoveAurasDueToSpell(SPELL_SHADOWY_CORRUPTION);
                        }
                    }
                    DoCastAOE(SPELL_STOP_HEART);
                }
                break;
            case DATA_ASCENDANT_DESCENDING:
                _achievementEnligible = false;
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_ASCENDANT_DESCENDING)
            return _achievementEnligible;

        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STONE_BLOW:
                    DoCastVictim(SPELL_STONE_BLOW);
                    events.Repeat(12s);
                    break;
                case EVENT_TWILIGHT_CORRUPTION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, -SPELL_TWILIGHT_CORRUPTION))
                        DoCast(target, SPELL_TWILIGHT_CORRUPTION);
                    events.Repeat(12s);
                    break;
                case EVENT_THUNDERCLAP:
                    DoCastAOE(SPELL_THUNDERCLAP);
                    events.Repeat(23s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    uint8 _transformationCount;
    uint8 _deadElementalWardenCount;
    bool _achievementEnligible;
};

class spell_obsidius_twitchy : public AuraScript
{
    PrepareAuraScript(spell_obsidius_twitchy);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        if (DamageInfo* damage = eventInfo.GetDamageInfo())
        {
            if (Unit* attacker = damage->GetAttacker())
            {
                target->SendPlaySpellVisualKit(SPELL_VISUAL_SPOTTED, 0, 0);
                target->getThreatManager().resetAllAggro();
                target->AddThreat(attacker, 100000000.0f);
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_obsidius_twitchy::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_obsidius_transformation : public SpellScript
{
    PrepareSpellScript(spell_obsidius_transformation);

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(GetSpellInfo()->Effects[i].BasePoints))
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), spell->Id, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_obsidius_transformation::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_obsidius_transformation_not_selectable : public AuraScript
{
    PrepareAuraScript(spell_obsidius_transformation_not_selectable);

    void AfterRemmove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetTarget();
        if (caster == target)
            return;

        Position pos1 = target->GetPosition();
        Position pos2 = caster->GetPosition();
        caster->NearTeleportTo(pos1);
        target->NearTeleportTo(pos2);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_obsidius_transformation_not_selectable::AfterRemmove, EFFECT_0, SPELL_AURA_MOD_UNATTACKABLE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_obsidius_transformation_scale : public AuraScript
{
    PrepareAuraScript(spell_obsidius_transformation_scale);

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(GetSpellInfo()->Effects[aurEff->GetEffIndex()].BasePoints))
            GetTarget()->CastSpell(GetTarget(), spell->Id, true);

        Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_obsidius_transformation_scale::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_obsidius_crepuscular_veil : public SpellScript
{
    PrepareSpellScript(spell_obsidius_crepuscular_veil);

    void HandleAchievement()
    {
        Unit* target = GetHitUnit();
        if (!target)
            return;

        Aura* aura = target->GetAura(GetSpellInfo()->Id);
        if (!aura)
            return;

        if (aura->GetStackAmount() == GetSpellInfo()->StackAmount)
        {
            InstanceScript* instance = target->GetInstanceScript();
            if (!instance)
                return;

            if (Creature* obsidius = instance->GetCreature(DATA_ASCENDANT_LORD_OBSIDIUS))
                obsidius->AI()->SetData(DATA_ASCENDANT_DESCENDING, FAIL);
        }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_obsidius_crepuscular_veil::HandleAchievement);
    }
};

class spell_obsidius_shadow_of_obsidius : public AuraScript
{
    PrepareAuraScript(spell_obsidius_shadow_of_obsidius);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        absorbAmount = dmgInfo.GetDamage();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_obsidius_shadow_of_obsidius::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_obsidius_shadow_of_obsidius::Absorb, EFFECT_0);
    }
};

class achievement_ascendant_descending : public AchievementCriteriaScript
{
    public:
        achievement_ascendant_descending() : AchievementCriteriaScript("achievement_ascendant_descending") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_ASCENDANT_DESCENDING);

            return false;
        }
};

void AddSC_boss_ascendant_lord_obsidius()
{
    RegisterBlackrockCavernsCreatureAI(boss_ascendant_lord_obsidius);
    RegisterAuraScript(spell_obsidius_twitchy);
    RegisterSpellScript(spell_obsidius_transformation);
    RegisterAuraScript(spell_obsidius_transformation_not_selectable);
    RegisterAuraScript(spell_obsidius_transformation_scale);
    RegisterSpellScript(spell_obsidius_crepuscular_veil);
    RegisterAuraScript(spell_obsidius_shadow_of_obsidius);
    new achievement_ascendant_descending();
}
