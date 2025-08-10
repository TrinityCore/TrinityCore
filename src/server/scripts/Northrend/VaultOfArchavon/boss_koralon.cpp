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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "vault_of_archavon.h"

enum KoralonSpells
{
    SPELL_BURNING_BREATH                        = 66665,
    SPELL_BURNING_FURY                          = 66721,
    SPELL_FLAME_CINDER_A                        = 66684,
    SPELL_FLAME_CINDER_B                        = 66681, // don't know the real relation to SPELL_FLAME_CINDER_A atm.
    SPELL_METEOR_FISTS                          = 66725,
    SPELL_METEOR_FISTS_DAMAGE                   = 66765,

    // Flame Warder
    SPELL_FW_METEOR_FISTS_DAMAGE                = 66809
};

enum KoralonEvents
{
    EVENT_BURNING_BREATH = 1,
    EVENT_BURNING_FURY,
    EVENT_FLAME_CINDER,
    EVENT_METEOR_FISTS
};

struct boss_koralon : public BossAI
{
    boss_koralon(Creature* creature) : BossAI(creature, DATA_KORALON) { }

    void JustEngagedWith(Unit* who) override
    {
        DoCast(me, SPELL_BURNING_FURY);

        events.ScheduleEvent(EVENT_BURNING_FURY, 20s);    /// @todo check timer
        events.ScheduleEvent(EVENT_BURNING_BREATH, 15s);  // 1st after 15sec, then every 45sec
        events.ScheduleEvent(EVENT_METEOR_FISTS, 75s);    // 1st after 75sec, then every 45sec
        events.ScheduleEvent(EVENT_FLAME_CINDER, 30s);    /// @todo check timer

        BossAI::JustEngagedWith(who);
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
                case EVENT_BURNING_FURY:
                    DoCast(me, SPELL_BURNING_FURY);
                    events.ScheduleEvent(EVENT_BURNING_FURY, 20s);
                    break;
                case EVENT_BURNING_BREATH:
                    DoCast(me, SPELL_BURNING_BREATH);
                    events.ScheduleEvent(EVENT_BURNING_BREATH, 45s);
                    break;
                case EVENT_METEOR_FISTS:
                    DoCast(me, SPELL_METEOR_FISTS);
                    events.ScheduleEvent(EVENT_METEOR_FISTS, 45s);
                    break;
                case EVENT_FLAME_CINDER:
                    DoCast(me, SPELL_FLAME_CINDER_A);
                    events.ScheduleEvent(EVENT_FLAME_CINDER, 30s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 66725, 68161 - Meteor Fists
class spell_koralon_meteor_fists : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_METEOR_FISTS_DAMAGE });
    }

    void TriggerFists(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_METEOR_FISTS_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_koralon_meteor_fists::TriggerFists, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 66765, 67333 - Meteor Fists
// 66809, 67331 - Meteor Fists
class spell_koralon_meteor_fists_damage : public SpellScript
{
public:
    spell_koralon_meteor_fists_damage()
    {
        _chainTargets = 0;
    }

private:
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        _chainTargets = uint8(targets.size());
    }

    void CalculateSplitDamage()
    {
        if (_chainTargets)
            SetHitDamage(GetHitDamage() / (_chainTargets + 1));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_koralon_meteor_fists_damage::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ENEMY);
        OnHit += SpellHitFn(spell_koralon_meteor_fists_damage::CalculateSplitDamage);
    }

private:
    uint8 _chainTargets;
};

// 66808, 68160 - Meteor Fists
class spell_flame_warder_meteor_fists : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FW_METEOR_FISTS_DAMAGE });
    }

    void TriggerFists(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_FW_METEOR_FISTS_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_flame_warder_meteor_fists::TriggerFists, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

void AddSC_boss_koralon()
{
    RegisterVaultOfArchavonCreatureAI(boss_koralon);
    RegisterSpellScript(spell_koralon_meteor_fists);
    RegisterSpellScript(spell_koralon_meteor_fists_damage);
    RegisterSpellScript(spell_flame_warder_meteor_fists);
}
