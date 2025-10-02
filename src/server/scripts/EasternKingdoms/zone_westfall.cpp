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

#include "CombatAI.h"
#include "Containers.h"
#include "CreatureAIImpl.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

namespace Scripts::EasternKingdoms::Westfall
{
namespace Creatures
{
    static constexpr uint32 EnergizedHarvestReaper = 42342;
    static constexpr uint32 OverloadedHarvestGolem = 42601;
}

namespace Events
{
    namespace ItsAlive
    {
        static constexpr uint32 CheckArea = 1;
        static constexpr uint32 DespawnHarvester = 2;
    }
}

namespace Text
{
    namespace HarvestGolem
    {
        static constexpr uint32 AnnounceOutOfArea = 0;
    }
}

namespace Area
{
    static constexpr uint32 TheMoestFarm = 918;
}

// 79084 - Unbound Energy
class spell_westfall_unbound_energy : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject const* target) -> bool
        {
            return caster->ToWorldObject() == target;
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_westfall_unbound_energy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 42601 - Overloaded Harvest Golem
struct npc_westfall_overloaded_harvest_golem : public ScriptedAI
{
    npc_westfall_overloaded_harvest_golem(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        _events.ScheduleEvent(Events::ItsAlive::CheckArea, 1s);
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::ItsAlive::CheckArea:
                    if (me->GetAreaId() != Area::TheMoestFarm)
                    {
                        if (Unit* owner = me->GetCharmerOrOwner())
                            Talk(Text::HarvestGolem::AnnounceOutOfArea, owner);
                        _events.ScheduleEvent(Events::ItsAlive::DespawnHarvester, 8s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                case Events::ItsAlive::DespawnHarvester:
                    if (me->GetAreaId() != Area::TheMoestFarm)
                        me->DespawnOrUnsummon();
                    else
                        _events.ScheduleEvent(Events::ItsAlive::CheckArea, 1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 79425 - Reaping Blows
class spell_westfall_reaping_blows : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } }) && ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_1).TriggerSpell) });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        // HACK
        // periodic ticks are forcing to cast the spell onto himself instead of target
        // ref AuraEffect::HandlePeriodicTriggerSpellAuraTick
        PreventDefaultAction();
        if (Creature* reaper = GetTarget()->FindNearestCreature(Creatures::EnergizedHarvestReaper, 5.f, true))
            GetTarget()->CastSpell(reaper, GetSpellInfo()->GetEffect(EFFECT_1).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_westfall_reaping_blows::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 79436 - Wake Harvest Golem
class spell_westfall_wake_harvest_golem : public SpellScript
{
    SpellCastResult CheckTarget()
    {
        Unit* target = GetExplTargetUnit();
        if (!target || !target->IsCreature())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        if (Creature* target = GetHitCreature())
        {
            caster->ToPlayer()->KilledMonsterCredit(Creatures::OverloadedHarvestGolem);
            target->DespawnOrUnsummon(100ms);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_westfall_wake_harvest_golem::CheckTarget);
        OnEffectHitTarget += SpellEffectFn(spell_westfall_wake_harvest_golem::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};
}

void AddSC_westfall()
{
    using namespace Scripts::EasternKingdoms::Westfall;

    // Creature
    RegisterCreatureAI(npc_westfall_overloaded_harvest_golem);

    // Spells
    RegisterSpellScript(spell_westfall_unbound_energy);
    RegisterSpellScript(spell_westfall_reaping_blows);
    RegisterSpellScript(spell_westfall_wake_harvest_golem);
}
