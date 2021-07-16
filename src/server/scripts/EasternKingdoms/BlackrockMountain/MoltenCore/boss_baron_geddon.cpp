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

/* ScriptData
SDName: Boss_Baron_Geddon
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "ScriptMgr.h"
#include "molten_core.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "ObjectMgr.h"

enum Emotes
{
    EMOTE_SERVICE       = 0
};

enum Spells
{
    SPELL_INFERNO       = 19695,
    SPELL_INFERNO_DMG   = 19698,
    SPELL_IGNITE_MANA   = 19659,
    SPELL_LIVING_BOMB   = 20475,
    SPELL_ARMAGEDDON    = 20478,
};

enum Events
{
    EVENT_INFERNO       = 1,
    EVENT_IGNITE_MANA   = 2,
    EVENT_LIVING_BOMB   = 3,
};

struct boss_baron_geddon : public BossAI
{
    boss_baron_geddon(Creature* creature) : BossAI(creature, BOSS_BARON_GEDDON)
    {
    }

    void JustEngagedWith(Unit* victim) override
    {
        BossAI::JustEngagedWith(victim);
        events.ScheduleEvent(EVENT_INFERNO, 45s);
        events.ScheduleEvent(EVENT_IGNITE_MANA, 30s);
        events.ScheduleEvent(EVENT_LIVING_BOMB, 35s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        // If we are <2% hp cast Armageddon
        if (!HealthAbovePct(2))
        {
            me->InterruptNonMeleeSpells(true);
            DoCast(me, SPELL_ARMAGEDDON);
            Talk(EMOTE_SERVICE);
            return;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INFERNO:
                    DoCast(me, SPELL_INFERNO);
                    events.ScheduleEvent(EVENT_INFERNO, 45s);
                    break;
                case EVENT_IGNITE_MANA:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true, true, -SPELL_IGNITE_MANA))
                        DoCast(target, SPELL_IGNITE_MANA);
                    events.ScheduleEvent(EVENT_IGNITE_MANA, 30s);
                    break;
                case EVENT_LIVING_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_LIVING_BOMB);
                    events.ScheduleEvent(EVENT_LIVING_BOMB, 35s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

// 19695 - Inferno
class spell_baron_geddon_inferno : public AuraScript
{
    PrepareAuraScript(spell_baron_geddon_inferno);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        static const int32 damageForTick[8] = { 500, 500, 1000, 1000, 2000, 2000, 3000, 5000 };
        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_FULL_MASK;
        args.TriggeringAura = aurEff;
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, damageForTick[aurEff->GetTickNumber() - 1]);
        GetTarget()->CastSpell(nullptr, SPELL_INFERNO_DMG, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_baron_geddon_inferno::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_baron_geddon()
{
    RegisterMoltenCoreCreatureAI(boss_baron_geddon);
    RegisterSpellScript(spell_baron_geddon_inferno);
}
