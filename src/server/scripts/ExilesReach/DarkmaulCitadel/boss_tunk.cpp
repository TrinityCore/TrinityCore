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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "darkmaul_citadel.h"

enum TunkSpells
{
    SPELL_INTERRUPTING_SHOUT    = 321240,
    SPELL_SEISMIC_SLAM_SELECTOR = 308454,
    SPELL_SEISMIC_SLAM_AT       = 308455,
    SPELL_SEISMIC_SLAM_DAMAGE   = 308463
};

enum TunkEvents
{
    EVENT_INTERRUPTING_SHOUT = 1,
    EVENT_SEISMIC_SLAM
};

enum TunkTexts
{
    SAY_WARNING_SEISMIC_SLAM = 0,
    SAY_WARNING_INTERRUPT    = 1
};

// 157300 - Tunk
struct boss_tunk : public BossAI
{
    boss_tunk(Creature* creature) : BossAI(creature, DATA_TUNK) { }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_INTERRUPTING_SHOUT, 7s);
        events.ScheduleEvent(EVENT_SEISMIC_SLAM, 14s);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (!target->IsPlayer())
            return;

        if (spellInfo->Id == SPELL_SEISMIC_SLAM_DAMAGE)
            Talk(SAY_WARNING_SEISMIC_SLAM, target);
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
                case EVENT_INTERRUPTING_SHOUT:
                {
                    DoCastSelf(SPELL_INTERRUPTING_SHOUT);
                    events.Repeat(20s);
                    break;
                }
                case EVENT_SEISMIC_SLAM:
                {
                    DoCast(SPELL_SEISMIC_SLAM_SELECTOR);
                    events.Repeat(30s);
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

// 308454 - Seismic Slam
class spell_tunk_seismic_slam_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SEISMIC_SLAM_AT });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), SPELL_SEISMIC_SLAM_AT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tunk_seismic_slam_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 308455 - Seismic Slam
struct at_tunk_seismic_slam : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(at->GetSpellId(), DIFFICULTY_NONE);
        if (!spellInfo)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position destPos = at->GetFirstCollisionPosition(spellInfo->GetMaxRange(false, caster), 0.0f);
        PathGenerator path(at);

        path.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), false);

        at->InitSplines(path.GetPath());
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_SEISMIC_SLAM_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// 321240 - Interrupting Shout
class spell_tunk_interrupting_shout : public SpellScript
{
    void HandleLaunchTarget(SpellEffIndex /*effIndex*/) const
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        Player* hitPlayer = GetHitUnit()->ToPlayer();
        if (!hitPlayer)
            return;

        if (hitPlayer->GetCurrentSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL) != nullptr)
            caster->AI()->Talk(SAY_WARNING_INTERRUPT, hitPlayer);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_tunk_interrupting_shout::HandleLaunchTarget, EFFECT_1, SPELL_EFFECT_INTERRUPT_CAST);
    }
};

void AddSC_boss_tunk()
{
    RegisterDarkmaulCitadelCreatureAI(boss_tunk);

    RegisterSpellScript(spell_tunk_seismic_slam_selector);
    RegisterSpellScript(spell_tunk_interrupting_shout);

    RegisterAreaTriggerAI(at_tunk_seismic_slam);
}
