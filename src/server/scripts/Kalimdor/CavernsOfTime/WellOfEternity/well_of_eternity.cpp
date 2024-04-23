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

#include "Creature.h"
#include "InstanceScript.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "well_of_eternity.h"

enum Texts
{
    // Nozdormu (intro)
    SAY_INTRO_1         = 0,
    SAY_INTRO_2         = 1,
    SAY_INTRO_3         = 2,
    SAY_INTRO_4         = 3
};

enum Actions
{
    // Intro
    ACTION_NOZDORMU_INTRO       = 1
};

enum Spells
{
    // Intro
    SPELL_SUMMON_FIRE_WALL                   = 105243,
    SPELL_SUMMON_FEL_FIREWALL_COSMETIC       = 105247,
    SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE = 105250,

    // Legion Demon
    SPELL_STRIKE_FEAR                        = 103913
};

enum MovementMisc
{
    // Legion Demon
    WAYPOINT_INTRO             = 3
};

enum Events
{
    // Legion Demon
    EVENT_STRIKE_FEAR = 1
};

constexpr Position FirewallPos[7] =
{
    { 3204.6145f, -4935.3647f, 194.41118f },
    { 3182.0986f, -4933.1196f, 194.41118f },
    { 3201.0647f, -4937.5664f, 194.41118f },
    { 3185.1438f, -4935.9785f, 194.41118f },
    { 3197.0664f, -4938.774f,  194.41118f },
    { 3188.825f,  -4937.952f,  194.41118f },
    { 3192.8916f, -4938.9053f, 194.41118f }
};

// Areatrigger - 7387
struct at_woe_nozdormu_intro : OnlyOnceAreaTriggerScript
{
public:
    at_woe_nozdormu_intro() : OnlyOnceAreaTriggerScript("at_woe_nozdormu_intro") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* nozdormu = instance->GetCreature(DATA_NOZDORMU))
                nozdormu->AI()->DoAction(ACTION_NOZDORMU_INTRO);
        }
        return true;
    }
};

// Areatrigger - 7029
struct at_woe_perotharn_intro : OnlyOnceAreaTriggerScript
{
public:
    at_woe_perotharn_intro() : OnlyOnceAreaTriggerScript("at_woe_perotharn_intro") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* perotharn = instance->GetCreature(BOSS_PEROTHARN))
                perotharn->AI()->DoAction(ACTION_PEROTHARN_INTRO);
        }
        return true;
    }
};

// 55624 - Nozdormu
struct npc_woe_nozdormu : public ScriptedAI
{
    npc_woe_nozdormu(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_NOZDORMU_INTRO)
        {
            Talk(SAY_INTRO_1);

            scheduler.Schedule(12s + 970ms, [this](TaskContext context)
            {
                Talk(SAY_INTRO_2);
                context.Schedule(5s + 950ms, [this](TaskContext context)
                {
                    Talk(SAY_INTRO_3);
                    context.Schedule(12s + 230ms, [this](TaskContext /*context*/)
                    {
                        Talk(SAY_INTRO_4);
                    });
                });
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

// 55503 - Legion Demon
struct npc_woe_legion_demon : public ScriptedAI
{
    npc_woe_legion_demon(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_STRIKE_FEAR, 7s);
    }

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        if (!me->HasStringId("legion_demon_woe_intro"))
            return;

        if (waypointId == WAYPOINT_INTRO)
        {
            if (Creature* stalker = me->FindNearestCreature(NPC_FIRE_WALL_STALKER, 25.0f))
                stalker->CastSpell(stalker, SPELL_SUMMON_FEL_FIREWALL_COSMETIC, TRIGGERED_FULL_MASK);

            DoCast(SPELL_SUMMON_FIRE_WALL);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (GameObject* go = me->FindNearestGameObject(GO_LARGE_FIRE_WALL_DOOR, 75.0f))
            go->SetGoState(GO_STATE_DESTROYED);

        if (GameObject* go = me->FindNearestGameObject(GO_COURTYARD_DOOR, 75.0f))
            go->SetGoState(GO_STATE_DESTROYED);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
            case EVENT_STRIKE_FEAR:
                DoCast(SPELL_STRIKE_FEAR);
                events.ScheduleEvent(EVENT_STRIKE_FEAR, 7s);
                break;
            default:
                break;
        }
    }
private:
    EventMap events;
};

// 105247 - Summon Fel Firewall Cosmetic PH
class spell_woe_summon_fel_firewall_cosmetic_ph : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        switch (aurEff->GetTickNumber())
        {
            case 1:
            {
                GetTarget()->CastSpell(FirewallPos[0], SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE, TRIGGERED_FULL_MASK);
                GetTarget()->CastSpell(FirewallPos[1], SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE, TRIGGERED_FULL_MASK);
                break;
            }
            case 2:
            {
                GetTarget()->CastSpell(FirewallPos[2], SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE, TRIGGERED_FULL_MASK);
                GetTarget()->CastSpell(FirewallPos[3], SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE, TRIGGERED_FULL_MASK);
                break;
            }
            case 3:
            {
                GetTarget()->CastSpell(FirewallPos[4], SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE, TRIGGERED_FULL_MASK);
                GetTarget()->CastSpell(FirewallPos[5], SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE, TRIGGERED_FULL_MASK);
                break;
            }
            case 4:
            {
                GetTarget()->CastSpell(FirewallPos[6], SPELL_SUMMON_FEL_FIREWALL_COSMETIC_PULSE, TRIGGERED_FULL_MASK);
                break;
            }
            default:
                break;
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GameObject* go = GetTarget()->FindNearestGameObject(GO_LARGE_FIRE_WALL_DOOR, 15.0f))
            go->SetGoState(GO_STATE_READY);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_woe_summon_fel_firewall_cosmetic_ph::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_woe_summon_fel_firewall_cosmetic_ph::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 105243 - Summon Fire Wall
class spell_woe_summon_fire_wall : public SpellScript
{
    void HandleAfterCast()
    {
        GetCaster()->ToCreature()->SetImmuneToPC(false);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_woe_summon_fire_wall::HandleAfterCast);
    }
};

void AddSC_well_of_eternity()
{
    RegisterWellOfEternityCreatureAI(npc_woe_nozdormu);
    RegisterWellOfEternityCreatureAI(npc_woe_legion_demon);
    RegisterSpellScript(spell_woe_summon_fel_firewall_cosmetic_ph);
    RegisterSpellScript(spell_woe_summon_fire_wall);

    new at_woe_nozdormu_intro();
    new at_woe_perotharn_intro();
}
