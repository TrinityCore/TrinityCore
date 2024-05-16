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

#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ragefire_chasm.h"

enum KoranthalSpells
{
    SPELL_SHADOW_VORTEX     = 119928,
    SPELL_TWISTED_ELEMENTS  = 119300,
    SPELL_SHADOW_STORM      = 119971
};

enum KoranthalTexts
{
    SAY_AGGRO               = 0,
    SAY_SHADOW_STORM        = 1,
    SAY_DEATH               = 2
};

enum KoranthalEvents
{
    EVENT_TWISTED_ELEMENTS  = 1,
    EVENT_SHADOW_STORM      = 2
};

// 61412 - Dark Shaman Koranthal
struct boss_dark_shaman_koranthal : public BossAI
{
    boss_dark_shaman_koranthal(Creature* creature) : BossAI(creature, BOSS_DARK_SHAMAN_KORANTHAL) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SHADOW_VORTEX);
    }

    void Reset() override
    {
        _Reset();
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

        Talk(SAY_AGGRO);
        me->RemoveAurasDueToSpell(SPELL_SHADOW_VORTEX);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_TWISTED_ELEMENTS, 6s);
        events.ScheduleEvent(EVENT_SHADOW_STORM, 20500ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
                case EVENT_TWISTED_ELEMENTS:
                {
                    DoCastVictim(SPELL_TWISTED_ELEMENTS);
                    events.Repeat(7300ms);
                    break;
                }
                case EVENT_SHADOW_STORM:
                {
                    Talk(SAY_SHADOW_STORM);
                    DoCast(SPELL_SHADOW_STORM);
                    events.RescheduleEvent(EVENT_TWISTED_ELEMENTS, 15s + 700ms);
                    events.Repeat(47200ms);
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

// 119973 - Shadow Storm
class spell_dark_shaman_koranthal_shadow_storm : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dark_shaman_koranthal_shadow_storm::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_dark_shaman_koranthal()
{
    RegisterRagefireChasmCreatureAI(boss_dark_shaman_koranthal);
    RegisterSpellScript(spell_dark_shaman_koranthal_shadow_storm);
}
