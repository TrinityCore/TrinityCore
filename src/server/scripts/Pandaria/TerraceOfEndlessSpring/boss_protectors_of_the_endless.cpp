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

#include "CellImpl.h"
#include "GameObject.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "terrace_of_endless_spring.h"

enum ProtectorsSpells
{
    // Protector Kaolan
    SPELL_TOUCH_OF_SHA                    = 117519,
    SPELL_DEFILED_GROUND                  = 117986,
    SPELL_EXPEL_CORRUPTION                = 117975,

    // Elder Regail
    SPELL_LIGHTNING_BOLT                  = 117187,
    SPELL_LIGHTNING_PRISON                = 122874,
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

    // Cleansing Waters
    SPELL_CLEANSING_WATERS_AURA           = 117250,
    SPELL_CLEANSING_WATERS_SPHERE         = 117268,
    SPELL_CLEANSING_WATERS_HEAL           = 117283,

    SPELL_SHA_CORRUPTION                  = 117052,
    SPELL_OVERWHELMING_CORRUPTION         = 117351,
    SPELL_SHA_CORRUPTION_FOUNTAIN         = 125651
};

enum ProtectorsEvents
{
    // Protector Kaolan
    EVENT_TOUCH_OF_SHA                    = 1,
    EVENT_DEFILED_GROUND                  = 2,
    EVENT_EXPEL_CORRUPTION                = 3,

    // Elder Regail
    EVENT_LIGHTNING_BOLT                  = 4,
    EVENT_LIGHTNING_STORM                 = 5,

    // Elder Asani
    EVENT_WATER_BOLT                      = 6,
    EVENT_CLEANSING_WATERS                = 7,

    // Cleansing Waters
    EVENT_CLEANSING_WATERS_HEAL           = 8
};

enum ProtectorsTexts
{
    // Protector Kaolan
    SAY_INTRO   = 0,
    SAY_INTRO2   = 1,
    SAY_INTRO1   = 2,
    SAY_INTRO3   = 3,
    SAY_INTRO4   = 4,
    SAY_INTRO5   = 5,

    // Elder Regail

    // Cleansing Waters
};

enum ProtectorsActions
{};

enum ProtectorsMisc
{
    ANIMKIT_NONE              = 0,
    ANIMKIT_PROTECTORS_AWAKEN = 2636
};

namespace
{
void ProtectorsOfTheEndlessData(InstanceScript* instance, std::function<void(Creature* protector)> func)
{
    for (uint32 data = DATA_PROTECTOR_KAOLAN; data <= DATA_ELDER_ASANI; data++)
    {
        if (Creature* protector = instance->GetCreature(data))
            func(protector);
    }
}

void DespawnProtectors(InstanceScript* instance, EvadeReason why)
{
    if (instance->GetBossState(DATA_PROTECTORS_OF_THE_ENDLESS) == FAIL)
        return;

    instance->SetBossState(DATA_PROTECTORS_OF_THE_ENDLESS, FAIL);

    ProtectorsOfTheEndlessData(instance, [instance, why](Creature* protector)
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, protector);
        protector->AI()->EnterEvadeMode(why);
    });
}
}

struct ProtectorsSharedAI : public BossAI
{
    ProtectorsSharedAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId) { }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
    }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_PROTECTORS_INTRO_STATE) == DONE)
        {
            ProtectorsOfTheEndlessData(instance, [](Creature* protector)
            {
                protector->SetUninteractible(false);
                protector->SetImmuneToPC(false);
            });
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnProtectors(instance, why);
 
        events.Reset();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void OnHealthDepleted(Unit* /*attacker*/, bool /*isKill*/) override
    {
        DoCast(SPELL_SHA_CORRUPTION);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ProtectorsOfTheEndlessData(instance, [](Creature* protector)
        {
            DoZoneInCombat(protector);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (Aura* shaCorruption = me->GetAura(SPELL_SHA_CORRUPTION))
        {
            if (shaCorruption->GetStackAmount() >= 1)
            {
                if (GetProtectorKaolan())
                    events.ScheduleEvent(EVENT_DEFILED_GROUND, 5100ms);
                else if (GetElderRegail())
                    events.ScheduleEvent(EVENT_LIGHTNING_STORM, 21200ms);
                //else if (Creature* asani = GetElderAsani())
            }
            else if (shaCorruption->GetStackAmount() == 2)
            {
                if (GetProtectorKaolan())
                    events.ScheduleEvent(EVENT_EXPEL_CORRUPTION, 6100ms);
                else if (GetElderRegail() || GetElderAsani())
                    DoCastSelf(SPELL_OVERWHELMING_CORRUPTION);
            }
        }
    }

protected:
    Creature* GetProtectorKaolan()
    {
        return instance->GetCreature(me->GetEntry() == BOSS_PROTECTOR_KAOLAN);
    }

    Creature* GetElderRegail()
    {
        return instance->GetCreature(me->GetEntry() == BOSS_ELDER_REGAIL);
    }

    Creature* GetElderAsani()
    {
        return instance->GetCreature(me->GetEntry() == BOSS_ELDER_ASANI);
    }
};

// 60583 - Protector Kaolan
struct boss_protector_kaolan : public ProtectorsSharedAI
{
    boss_protector_kaolan(Creature* creature) : ProtectorsSharedAI(creature, DATA_PROTECTOR_KAOLAN) { }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnProtectors(instance, why);
 
        events.Reset();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        ProtectorsSharedAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_TOUCH_OF_SHA, 35200ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        DoCastSelf(SPELL_SHA_CORRUPTION);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();

        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        for (auto i = players.begin(); i != players.end(); ++i)
        {
            Player* player = i->GetSource();
            player->RemoveAurasDueToSpell(SPELL_TOUCH_OF_SHA);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        ProtectorsSharedAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;
        
        events.Update(diff);
        
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TOUCH_OF_SHA:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_TOUCH_OF_SHA);
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
                        DoCast(target, SPELL_EXPEL_CORRUPTION);
                    events.Repeat(38900ms, 41300ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 60585 - Elder Regail
struct boss_elder_regail : public ProtectorsSharedAI
{
    boss_elder_regail(Creature* creature) : ProtectorsSharedAI(creature, DATA_ELDER_REGAIL) { }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        DoCastSelf(SPELL_SHA_CORRUPTION);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnProtectors(instance, why);
 
        events.Reset();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        ProtectorsSharedAI::JustEngagedWith(who);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 800ms);
    }

    void UpdateAI(uint32 diff) override
    {
        ProtectorsSharedAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LIGHTNING_BOLT:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_LIGHTNING_BOLT);
                    events.Repeat(2400ms);
                    break;
                }
                case EVENT_LIGHTNING_STORM:
                {
                    DoCastSelf(SPELL_LIGHTNING_STORM_CAST);
                    events.Repeat(42200ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 60586 - Elder Asani
struct boss_elder_asani : public ProtectorsSharedAI
{
    boss_elder_asani(Creature* creature) : ProtectorsSharedAI(creature, DATA_ELDER_ASANI) { }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        DoCastSelf(SPELL_SHA_CORRUPTION);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnProtectors(instance, why);
 
        events.Reset();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        ProtectorsSharedAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_WATER_BOLT, 800ms);
        events.ScheduleEvent(EVENT_CLEANSING_WATERS, 10600ms);
    }

    void UpdateAI(uint32 diff) override
    {
        ProtectorsSharedAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (events.ExecuteEvent())
            {
                case EVENT_WATER_BOLT:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_WATER_BOLT);
                    events.Repeat(2400ms);
                    break;
                }
                case EVENT_CLEANSING_WATERS:
                {
                    //DoCastSelf(GetNextTeleportSpell());
                    events.Repeat(31500ms, 36400ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 63420 - Protector's controller
struct npc_protectors_controller : public ScriptedAI
{
    npc_protectors_controller(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_PROTECTORS_INTRO:
            {
                me->RemoveAllAuras();
                me->DespawnOrUnsummon(15s);
                DoCast(SPELL_SHA_CORRUPTION_FOUNTAIN);

                _scheduler.Schedule(10s, [this](TaskContext context)
                {
                    ProtectorsOfTheEndlessData(_instance, [](Creature* protector)
                    {
                        protector->SetAIAnimKitId(ANIMKIT_NONE);
                    });

                    context.Schedule(2s + 500ms, [this](TaskContext context)
                    {
                        if (Creature* kaolan = _instance->GetCreature(DATA_PROTECTOR_KAOLAN))
                            kaolan->AI()->Talk(SAY_INTRO);

                        ProtectorsOfTheEndlessData(_instance, [](Creature* protector)
                        {
                            protector->PlayOneShotAnimKitId(ANIMKIT_PROTECTORS_AWAKEN);
                        });

                        context.Schedule(2s + 440ms, [this](TaskContext context)
                        {
                            if (Creature* kaolan = _instance->GetCreature(DATA_PROTECTOR_KAOLAN))
                                kaolan->SetUnitFlag3(UNIT_FLAG3_UNK23);

                            ProtectorsOfTheEndlessData(_instance, [](Creature* protector)
                            {
                                protector->SetFacingTo(4.694935f);
                                protector->SetUninteractible(false);
                                protector->SetImmuneToPC(false);
                                protector->SetHomePosition(protector->GetPosition());
                            });
                        });
                    });
                });
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// sai
struct npc_cleansing_waters : public ScriptedAI
{
    npc_cleansing_waters(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_CLEANSING_WATERS_AURA);
        DoCastSelf(SPELL_CLEANSING_WATERS_SPHERE);
        _events.ScheduleEvent(EVENT_CLEANSING_WATERS_HEAL, 6900ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLEANSING_WATERS_HEAL:
                    DoCastSelf(SPELL_CLEANSING_WATERS_HEAL);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
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
        GetCaster()->CastSpell(GetCaster(), SPELL_LIGHTNING_STORM_10_YARDS, true);
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
            case SPELL_LIGHTNING_STORM_10_YARDS_DAMAGE: spellId = SPELL_LIGHTNING_STORM_30_YARDS; break;
            case SPELL_LIGHTNING_STORM_30_YARDS_DAMAGE: spellId = SPELL_LIGHTNING_STORM_50_YARDS; break;
            case SPELL_LIGHTNING_STORM_50_YARDS_DAMAGE: spellId = SPELL_LIGHTNING_STORM_70_YARDS; break;
            case SPELL_LIGHTNING_STORM_70_YARDS_DAMAGE: spellId = SPELL_LIGHTNING_STORM_90_YARDS; break;
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
            case SPELL_LIGHTNING_STORM_10_YARDS: spellId = SPELL_LIGHTNING_STORM_10_YARDS_DAMAGE; break;
            case SPELL_LIGHTNING_STORM_30_YARDS: spellId = SPELL_LIGHTNING_STORM_30_YARDS_DAMAGE; break;
            case SPELL_LIGHTNING_STORM_50_YARDS: spellId = SPELL_LIGHTNING_STORM_50_YARDS_DAMAGE; break;
            case SPELL_LIGHTNING_STORM_70_YARDS: spellId = SPELL_LIGHTNING_STORM_70_YARDS_DAMAGE; break;
            case SPELL_LIGHTNING_STORM_90_YARDS: spellId = SPELL_LIGHTNING_STORM_90_YARDS_DAMAGE; break;
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
    RegisterTerraceOfEndlessSpringCreatureAI(npc_protectors_controller);

    RegisterSpellScript(spell_protectors_of_the_endless_sha_corruption);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_storm_cast);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_storm);
    RegisterSpellScript(spell_protectors_of_the_endless_lightning_storm_damage);
}
