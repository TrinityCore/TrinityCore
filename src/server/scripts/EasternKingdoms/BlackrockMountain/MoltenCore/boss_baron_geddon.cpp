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

#include "ScriptMgr.h"
#include "molten_core.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum GeddonTexts
{
    EMOTE_SERVICE       = 0
};

enum GeddonSpells
{
    SPELL_INFERNO       = 19695,
    SPELL_IGNITE_MANA   = 19659,
    SPELL_LIVING_BOMB   = 20475,
    SPELL_ARMAGEDDON    = 20478,

    SPELL_INFERNO_DMG   = 19698
};

enum GeddonEvents
{
    EVENT_INFERNO       = 1,
    EVENT_IGNITE_MANA,
    EVENT_LIVING_BOMB,
    EVENT_ARMAGEDDON
};

// 12056 - Baron Geddon
struct boss_baron_geddon : public BossAI
{
    boss_baron_geddon(Creature* creature) : BossAI(creature, BOSS_BARON_GEDDON), _performedArmageddon(false) { }

    void Reset() override
    {
        _Reset();
        _performedArmageddon = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_INFERNO, 15s, 20s);
        events.ScheduleEvent(EVENT_IGNITE_MANA, 5s, 20s);
        events.ScheduleEvent(EVENT_LIVING_BOMB, 15s, 35s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_performedArmageddon && me->HealthBelowPctDamaged(2, damage))
        {
            _performedArmageddon = true;
            events.ScheduleEvent(EVENT_ARMAGEDDON, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ARMAGEDDON)
            Talk(EMOTE_SERVICE);
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
                case EVENT_INFERNO:
                    DoCastSelf(SPELL_INFERNO);
                    events.Repeat(20s, 35s);
                    break;
                case EVENT_IGNITE_MANA:
                    DoCastSelf(SPELL_IGNITE_MANA);
                    events.Repeat(25s, 40s);
                    break;
                case EVENT_LIVING_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_LIVING_BOMB);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_ARMAGEDDON:
                    DoCastSelf(SPELL_ARMAGEDDON);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _performedArmageddon;
};

// 19695 - Inferno
class spell_baron_geddon_inferno : public AuraScript
{
    PrepareAuraScript(spell_baron_geddon_inferno);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INFERNO_DMG });
    }

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
