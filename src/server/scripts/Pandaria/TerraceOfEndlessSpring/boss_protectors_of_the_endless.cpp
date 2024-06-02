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

#include "Containers.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "terrace_of_endless_spring.h"

enum ProtectorsSpells
{
    // Protector Kaolan
    SPELL_TOUCH_OF_SHA_SELECTOR           = 117510,
    SPELL_TOUCH_OF_SHA                    = 117519,
    SPELL_DEFILED_GROUND                  = 117986,
    SPELL_EXPEL_CORRUPTION                = 117975,

    // Elder Regail
    SPELL_LIGHTNING_BOLT                  = 117187,
    SPELL_LIGHTNING_PRISON                = 122874,
    SPELL_LIGHTNING_PRISON_MARKER         = 111850,
    SPELL_LIGHTNING_STORM_CAST            = 118077,
    SPELL_LIGHTNING_STORM_10_YARDS        = 118064,
    SPELL_LIGHTNING_STORM_30_YARDS        = 118040,
    SPELL_LIGHTNING_STORM_50_YARDS        = 118053,
    SPELL_LIGHTNING_STORM_70_YARDS        = 118054,
    SPELL_LIGHTNING_STORM_90_YARDS        = 118055,
    SPELL_LIGHTNING_STORM_10_YARDS_DAMAGE = 118003,
    SPELL_LIGHTNING_STORM_30_YARDS_DAMAGE = 118004,
    SPELL_LIGHTNING_STORM_50_YARDS_DAMAGE = 118005,
    SPELL_LIGHTNING_STORM_70_YARDS_DAMAGE = 118007,
    SPELL_LIGHTNING_STORM_90_YARDS_DAMAGE = 118008,

    // Elder Asani
    SPELL_WATER_BOLT                      = 118312,
    SPELL_CLEANSING_WATERS                = 117309,
    SPELL_CLEANSING_WATERS_HEAL           = 117283,
    SPELL_CORRUPTED_WATERS                = 117227,

    SPELL_SHA_CORRUPTION                  = 117052,
    SPELL_OVERWHELMING_CORRUPTION         = 117351,
    SPELL_SHA_CORRUPTION_FOUNTAIN         = 125651,
    SPELL_RAID_WARNING_CLEANSING_WATERS   = 122851
};

enum ProtectorsEvents
{
    // Protector Kaolan
    EVENT_TOUCH_OF_SHA                    = 1,
    EVENT_DEFILED_GROUND                  = 2,
    EVENT_EXPEL_CORRUPTION                = 3,

    // Elder Regail
    EVENT_LIGHTNING_BOLT                  = 4,
    EVENT_LIGHTNING_PRISON                = 5,
    EVENT_LIGHTNING_STORM                 = 6,

    // Elder Asani
    EVENT_WATER_BOLT                      = 7,
    EVENT_CLEANSING_WATERS                = 8,
    EVENT_CORRUPTED_WATERS                = 9
};

enum ProtectorsTexts
{
    // Shared texts
    SAY_NEW_POWER                  = 1, // NYI
    SAY_WARNING_CLEANSING_WATERS   = 2,
    SAY_DISPEL_CLEANSING_WATERS    = 3,
    SAY_FULL_POWER                 = 4,
    SAY_SLAY                       = 5,
    SAY_DEAD                       = 6,

    // Protector Kaolan
    SAY_INTRO                      = 0,
    SAY_EXPEL_CORRUPTION           = 7,

    // Elder Asani
    // Elder Regail
    SAY_PULL                       = 0,

    // Elder Regail
    SAY_LIGHTNING_PRISON           = 7,
    SAY_LIGHTNING_STORM_CAST       = 8,
    SAY_LIGHTNING_STORM            = 9,

    // Elder Asani
    SAY_CORRUPTED_WATERS           = 7,
    SAY_CORRUPTED_ORB              = 8
};

enum ProtectorsMisc
{
    ANIMKIT_NONE              = 0,
    ANIMKIT_PROTECTORS_AWAKEN = 2636,
    NPC_CORRUPTED_ORB         = 60621
};

uint32 const ProtectorsData[3] =
{
    DATA_PROTECTOR_KAOLAN,
    DATA_ELDER_ASANI,
    DATA_ELDER_REGAIL
};

namespace
{
void DespawnProtectors(InstanceScript* instance, EvadeReason why)
{
    if (instance->GetBossState(DATA_PROTECTORS_OF_THE_ENDLESS) == FAIL)
        return;

    instance->SetBossState(DATA_PROTECTORS_OF_THE_ENDLESS, FAIL);

    for (uint32 bossesData : ProtectorsData)
    {
        if (Creature* protectors = instance->GetCreature(bossesData))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, protectors);
            protectors->AI()->EnterEvadeMode(why);
        }
    }
}

void ProtectorsEncounterDone(InstanceScript* instance)
{
    if (instance->GetBossState(DATA_PROTECTORS_OF_THE_ENDLESS) == DONE)
        return;

    for (uint32 bossesData : ProtectorsData)
    {
        if (Creature* protectors = instance->GetCreature(bossesData))
        {
            if (protectors->IsAlive())
                return;
        }
    }

    instance->SetBossState(DATA_PROTECTORS_OF_THE_ENDLESS, DONE);
}
}

struct ProtectorsSharedAI : public BossAI
{
    ProtectorsSharedAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _newPower(false), _fullPower(false)
    {
        SetBoundary(instance->GetBossBoundary(DATA_PROTECTORS_OF_THE_ENDLESS));
    }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
        _newPower = false;
        _fullPower = false;
    }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_PROTECTORS_INTRO_STATE) == DONE)
        {
            me->SetUninteractible(false);
            me->SetImmuneToPC(false);
            me->SetAIAnimKitId(ANIMKIT_NONE);
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnProtectors(instance, why);

        events.Reset();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        for (uint32 bossesData : ProtectorsData)
        {
            if (Creature* protectors = instance->GetCreature(bossesData))
                protectors->AI()->DoZoneInCombat();
        }

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        summons.DespawnAll();

        DoCast(SPELL_SHA_CORRUPTION);

        Talk(SAY_DEAD);

        ProtectorsEncounterDone(instance);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_CLEANSING_WATERS_HEAL)
            Talk(SAY_DISPEL_CLEANSING_WATERS);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

protected:
    bool _newPower;
    bool _fullPower;
};

// 60583 - Protector Kaolan
struct boss_protector_kaolan : public ProtectorsSharedAI
{
    boss_protector_kaolan(Creature* creature) : ProtectorsSharedAI(creature, DATA_PROTECTOR_KAOLAN) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_TOUCH_OF_SHA, 35200ms);
    }

    void CleanupPlayerAuras()
    {
        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        for (auto i = players.begin(); i != players.end(); ++i)
        {
            if (Player* player = i->GetSource())
                player->RemoveAurasDueToSpell(SPELL_TOUCH_OF_SHA);
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ProtectorsSharedAI::EnterEvadeMode(why);

        CleanupPlayerAuras();
    }

    void JustDied(Unit* killer) override
    {
        ProtectorsSharedAI::JustDied(killer);

        CleanupPlayerAuras();
    }

    void DoAction(int32 actionId) override
    {
        if (actionId != ACTION_PROTECTORS_INTRO)
            return;

        if (Creature* corruptionDummy = me->FindNearestCreature(NPC_CORRUPTION_DUMMY, 30.0f))
        {
            corruptionDummy->RemoveAllAuras();
            corruptionDummy->DespawnOrUnsummon(12s);
            corruptionDummy->AI()->DoCastSelf(SPELL_SHA_CORRUPTION_FOUNTAIN);
        }

        scheduler.Schedule(10s, [this](TaskContext context)
        {
            for (uint32 bossesData : ProtectorsData)
            {
                if (Creature* protectors = instance->GetCreature(bossesData))
                    protectors->SetAIAnimKitId(ANIMKIT_NONE);
            }

            context.Schedule(2s + 500ms, [this](TaskContext context)
            {
                Talk(SAY_INTRO);

                for (uint32 bossesData : ProtectorsData)
                {
                    if (Creature* protectors = instance->GetCreature(bossesData))
                        protectors->PlayOneShotAnimKitId(ANIMKIT_PROTECTORS_AWAKEN);
                }

                context.Schedule(2s + 440ms, [this](TaskContext /*context*/)
                {
                    for (uint32 bossesData : ProtectorsData)
                    {
                        if (Creature* protectors = instance->GetCreature(bossesData))
                        {
                            protectors->SetFacingTo(4.694935f);
                            protectors->SetOrientation(protectors->GetOrientation());
                            protectors->SetUninteractible(false);
                            protectors->SetImmuneToPC(false);
                            protectors->SetHomePosition(protectors->GetPosition());
                        }
                    }

                    instance->SetData(DATA_PROTECTORS_INTRO_STATE, DONE);
                });
            });
        });
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_TOUCH_OF_SHA:
            {
                DoCast(SPELL_TOUCH_OF_SHA_SELECTOR);
                events.Repeat(35200ms);
                break;
            }
            case EVENT_DEFILED_GROUND:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_DEFILED_GROUND);
                events.Repeat(15800ms);
                break;
            }
            case EVENT_EXPEL_CORRUPTION:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                {
                    DoCast(target, SPELL_EXPEL_CORRUPTION);
                    Talk(SAY_EXPEL_CORRUPTION);
                }
                events.Repeat(38900ms, 41300ms);
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (Aura* shaCorruption = me->GetAura(SPELL_SHA_CORRUPTION))
        {
            if (shaCorruption->GetStackAmount() >= 1 && !_newPower)
            {
                events.ScheduleEvent(EVENT_DEFILED_GROUND, 5100ms);
                _newPower = true;
            }
            else if (shaCorruption->GetStackAmount() == 2 && !_fullPower)
            {
                Talk(SAY_FULL_POWER);
                events.ScheduleEvent(EVENT_EXPEL_CORRUPTION, 6100ms);
                _fullPower = true;
            }
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    TaskScheduler scheduler;
};

// 60585 - Elder Regail
struct boss_elder_regail : public ProtectorsSharedAI
{
    boss_elder_regail(Creature* creature) : ProtectorsSharedAI(creature, DATA_ELDER_REGAIL) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 800ms);
        events.ScheduleEvent(EVENT_LIGHTNING_PRISON, 15500ms);
    }

    void JustEngagedWith(Unit* who) override
    {
        ProtectorsSharedAI::JustEngagedWith(who);

        Creature* protector = nullptr;

        if (roll_chance_i(50))
            protector = me;
        else
            protector = me->GetInstanceScript()->GetCreature(DATA_ELDER_ASANI);

        protector->AI()->Talk(SAY_PULL);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_LIGHTNING_BOLT:
            {
                DoCastVictim(SPELL_LIGHTNING_BOLT);
                events.Repeat(2400ms);
                break;
            }
            case EVENT_LIGHTNING_PRISON:
            {
                DoCast(SPELL_LIGHTNING_PRISON);
                Talk(SAY_LIGHTNING_PRISON);
                events.Repeat(25400ms);
                break;
            }
            case EVENT_LIGHTNING_STORM:
            {
                DoCast(SPELL_LIGHTNING_STORM_CAST);
                Talk(SAY_LIGHTNING_STORM);
                Talk(SAY_LIGHTNING_STORM_CAST);
                events.RescheduleEvent(EVENT_LIGHTNING_BOLT, 16s);
                events.Repeat(42200ms);
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (Aura* shaCorruption = me->GetAura(SPELL_SHA_CORRUPTION))
        {
            if (shaCorruption->GetStackAmount() >= 1 && !_newPower)
            {
                events.ScheduleEvent(EVENT_LIGHTNING_STORM, 21200ms);
                _newPower = true;
            }
            else if (shaCorruption->GetStackAmount() == 2 && !_fullPower)
            {
                Talk(SAY_FULL_POWER);
                DoCastSelf(SPELL_OVERWHELMING_CORRUPTION);
                _fullPower = true;
            }
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 60586 - Elder Asani
struct boss_elder_asani : public ProtectorsSharedAI
{
    boss_elder_asani(Creature* creature) : ProtectorsSharedAI(creature, DATA_ELDER_ASANI) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_WATER_BOLT, 800ms);
        events.ScheduleEvent(EVENT_CLEANSING_WATERS, 10600ms);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_WATER_BOLT:
            {
                DoCastVictim(SPELL_WATER_BOLT);
                events.Repeat(2400ms);
                break;
            }
            case EVENT_CLEANSING_WATERS:
            {
                Unit* target = nullptr;
                switch (urand(0, 2))
                {
                    case 0:
                        target = me->GetInstanceScript()->GetCreature(DATA_ELDER_REGAIL);
                        break;
                    case 1:
                        target = me->GetInstanceScript()->GetCreature(DATA_PROTECTOR_KAOLAN);
                        break;
                    case 2:
                        target = me;
                        break;

                    if (!target->IsAlive())
                        return;
                }

                if (target)
                {
                    DoCast(target, SPELL_CLEANSING_WATERS);
                    target->GetAI()->DoCastVictim(SPELL_RAID_WARNING_CLEANSING_WATERS);
                }

                events.Repeat(31500ms, 36400ms);
                break;
            }
            case EVENT_CORRUPTED_WATERS:
            {
                DoCast(SPELL_CORRUPTED_WATERS);
                Talk(SAY_CORRUPTED_WATERS);
                events.Repeat(42500ms, 43800ms);
                break;
            }
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_CORRUPTED_ORB)
            Talk(SAY_CORRUPTED_ORB);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (Aura* shaCorruption = me->GetAura(SPELL_SHA_CORRUPTION))
        {
            if (shaCorruption->GetStackAmount() >= 1 && !_newPower)
            {
                events.ScheduleEvent(EVENT_CORRUPTED_WATERS, 5100ms);
                _newPower = true;
            }
            else if (shaCorruption->GetStackAmount() == 2 && !_fullPower)
            {
                Talk(SAY_FULL_POWER);
                DoCastSelf(SPELL_OVERWHELMING_CORRUPTION);
                _fullPower = true;
            }
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 122851 - Raid Warning: I'm Standing In Cleansing Waters
class spell_protectors_of_the_endless_warning_cleansing_waters : public SpellScript
{
    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Creature* protector = GetCaster()->ToCreature())
            if (protector->GetEntry() == BOSS_PROTECTOR_KAOLAN || protector->GetEntry() == BOSS_ELDER_ASANI || protector->GetEntry() == BOSS_ELDER_REGAIL)
                protector->AI()->Talk(SAY_WARNING_CLEANSING_WATERS, GetHitUnit()->ToPlayer());
    }

    void Register() override
    {
       OnEffectHitTarget += SpellEffectFn(spell_protectors_of_the_endless_warning_cleansing_waters::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 117510 - Touch of Sha
class spell_protectors_of_the_endless_touch_of_sha_selector : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_TOUCH_OF_SHA));

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_TOUCH_OF_SHA, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_protectors_of_the_endless_touch_of_sha_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_protectors_of_the_endless_touch_of_sha_selector::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 111850 - Lightning Prison Marker
class spell_protectors_of_the_endless_lightning_prison_marker : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 3 : 2);
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_protectors_of_the_endless_lightning_prison_marker::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 122874 - Lightning Prison Cast
class spell_protectors_of_the_endless_lightning_prison_cast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LIGHTNING_PRISON_MARKER });
    }

    void HandleCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_LIGHTNING_PRISON_MARKER, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_protectors_of_the_endless_lightning_prison_cast::HandleCast);
    }
};

// 117052 - Sha Corruption
class spell_protectors_of_the_endless_sha_corruption : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->SetFullHealth();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_protectors_of_the_endless_sha_corruption::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 118077 - Lightning Storm
class spell_protectors_of_the_endless_lightning_storm_cast : public SpellScript
{
    void HandleCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_LIGHTNING_STORM_10_YARDS, CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS));
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_protectors_of_the_endless_lightning_storm_cast::HandleCast);
    }
};

// 118003, 118004, 118005, 118007 - Lightning Storm (damage)
class spell_protectors_of_the_endless_lightning_storm : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_LIGHTNING_STORM_30_YARDS,
            SPELL_LIGHTNING_STORM_50_YARDS,
            SPELL_LIGHTNING_STORM_70_YARDS,
            SPELL_LIGHTNING_STORM_90_YARDS,
            SPELL_LIGHTNING_STORM_10_YARDS_DAMAGE,
            SPELL_LIGHTNING_STORM_30_YARDS_DAMAGE,
            SPELL_LIGHTNING_STORM_50_YARDS_DAMAGE,
            SPELL_LIGHTNING_STORM_70_YARDS_DAMAGE
        });
    }

    void HandleHit()
    {
        uint32 spellId;

        switch (GetSpellInfo()->Id)
        {
            case SPELL_LIGHTNING_STORM_10_YARDS_DAMAGE:
                spellId = SPELL_LIGHTNING_STORM_30_YARDS;
                break;
            case SPELL_LIGHTNING_STORM_30_YARDS_DAMAGE:
                spellId = SPELL_LIGHTNING_STORM_50_YARDS;
                break;
            case SPELL_LIGHTNING_STORM_50_YARDS_DAMAGE:
                spellId = SPELL_LIGHTNING_STORM_70_YARDS;
                break;
            case SPELL_LIGHTNING_STORM_70_YARDS_DAMAGE:
                spellId = SPELL_LIGHTNING_STORM_90_YARDS;
                break;
            default:
                return;
        }

        GetCaster()->CastSpell(GetCaster(), spellId, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_protectors_of_the_endless_lightning_storm::HandleHit);
    }
};

// 118040, 118053, 118054, 118055, 118064 - Lightning Storm
class spell_protectors_of_the_endless_lightning_storm_damage : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_LIGHTNING_STORM_10_YARDS,
            SPELL_LIGHTNING_STORM_30_YARDS,
            SPELL_LIGHTNING_STORM_50_YARDS,
            SPELL_LIGHTNING_STORM_70_YARDS,
            SPELL_LIGHTNING_STORM_90_YARDS,
            SPELL_LIGHTNING_STORM_10_YARDS_DAMAGE,
            SPELL_LIGHTNING_STORM_30_YARDS_DAMAGE,
            SPELL_LIGHTNING_STORM_50_YARDS_DAMAGE,
            SPELL_LIGHTNING_STORM_70_YARDS_DAMAGE,
            SPELL_LIGHTNING_STORM_90_YARDS_DAMAGE
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        uint32 spellId;

        switch (GetSpellInfo()->Id)
        {
            case SPELL_LIGHTNING_STORM_10_YARDS:
                spellId = SPELL_LIGHTNING_STORM_10_YARDS_DAMAGE;
                break;
            case SPELL_LIGHTNING_STORM_30_YARDS:
                spellId = SPELL_LIGHTNING_STORM_30_YARDS_DAMAGE;
                break;
            case SPELL_LIGHTNING_STORM_50_YARDS:
                spellId = SPELL_LIGHTNING_STORM_50_YARDS_DAMAGE;
                break;
            case SPELL_LIGHTNING_STORM_70_YARDS:
                spellId = SPELL_LIGHTNING_STORM_70_YARDS_DAMAGE;
                break;
            case SPELL_LIGHTNING_STORM_90_YARDS:
                spellId = SPELL_LIGHTNING_STORM_90_YARDS_DAMAGE;
                break;
            default:
                return;
        }

        GetCaster()->CastSpell(GetCaster(), spellId, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_protectors_of_the_endless_lightning_storm_damage::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_protectors_of_the_endless()
{
    RegisterTerraceOfEndlessSpringCreatureAI(boss_protector_kaolan);
    RegisterTerraceOfEndlessSpringCreatureAI(boss_elder_regail);
    RegisterTerraceOfEndlessSpringCreatureAI(boss_elder_asani);

    RegisterSpellScript(spell_protectors_of_the_endless_warning_cleansing_waters);
    RegisterSpellScript(spell_protectors_of_the_endless_touch_of_sha_selector);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_prison_marker);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_prison_cast);
    RegisterSpellScript(spell_protectors_of_the_endless_sha_corruption);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_storm_cast);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_storm);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_storm_damage);
}
