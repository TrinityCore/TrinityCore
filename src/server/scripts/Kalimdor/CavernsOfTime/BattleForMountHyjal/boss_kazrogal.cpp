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

/*
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "hyjal.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum KazrogalTexts
{
    SAY_INTRO                   = 0,
    SAY_MARK                    = 1,
    SAY_SLAY                    = 2
};

enum KazrogalSpells
{
    SPELL_MALEVOLENT_CLEAVE     = 31436,
    SPELL_WAR_STOMP             = 31480,
    SPELL_CRIPPLE               = 31477,
    SPELL_MARK_OF_KAZROGAL      = 31447,

    SPELL_MARK_OF_KAZROGAL_DMG  = 31463
};

enum KazrogalEvents
{
    EVENT_MALEVOLENT_CLEAVE     = 1,
    EVENT_WAR_STOMP,
    EVENT_CRIPPLE,
    EVENT_MARK_OF_KAZROGAL
};

enum KazrogalMisc
{
    SOUND_DEATH                 = 11018
};

// 17888 - Kaz'rogal
struct boss_kazrogal : public BossAI
{
    boss_kazrogal(Creature* creature) : BossAI(creature, DATA_KAZROGAL), _markCount(0), _markTimer(0) { }

    void JustAppeared() override
    {
        Talk(SAY_INTRO);
        me->GetMotionMaster()->MovePath(PATH_HORDE_BOSS, false);
    }

    void Reset() override
    {
        _Reset();
        _markCount = 0;
        _markTimer = 45s;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_MALEVOLENT_CLEAVE, 6s, 12s);
        events.ScheduleEvent(EVENT_WAR_STOMP, 20s, 30s);
        events.ScheduleEvent(EVENT_CRIPPLE, 15s, 20s);
        events.ScheduleEvent(EVENT_MARK_OF_KAZROGAL, 45s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_MARK_OF_KAZROGAL)
            Talk(SAY_MARK);
    }

    // Do not reset SetActive, we want boss to be active all the time
    void JustReachedHome() override { }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoPlaySoundToSet(me, SOUND_DEATH);
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
                case EVENT_MALEVOLENT_CLEAVE:
                    DoCastVictim(SPELL_MALEVOLENT_CLEAVE);
                    events.Repeat(6s, 12s);
                    break;
                case EVENT_WAR_STOMP:
                    DoCastSelf(SPELL_WAR_STOMP);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_CRIPPLE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 20.0f))
                        DoCast(target, SPELL_CRIPPLE);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_MARK_OF_KAZROGAL:
                    DoCastSelf(SPELL_MARK_OF_KAZROGAL);
                    ++_markCount;
                    if (_markCount <= 7)
                        _markTimer -= 5s;
                    events.Repeat(_markTimer);
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
    uint8 _markCount;
    Milliseconds _markTimer;
};

class MarkTargetFilter
{
    public:
        bool operator()(WorldObject* target) const
        {
            if (Unit* unit = target->ToUnit())
                return unit->GetPowerType() != POWER_MANA;
            return true;
        }
};

// 31447 - Mark of Kaz'rogal
class spell_mark_of_kazrogal : public SpellScript
{
    PrepareSpellScript(spell_mark_of_kazrogal);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(MarkTargetFilter());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mark_of_kazrogal::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_mark_of_kazrogal_aura : public AuraScript
{
    PrepareAuraScript(spell_mark_of_kazrogal_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_KAZROGAL_DMG });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (target->GetPower(POWER_MANA) < uint32(aurEff->GetAmount()))
        {
            target->CastSpell(target, SPELL_MARK_OF_KAZROGAL_DMG, aurEff);
            Remove();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mark_of_kazrogal_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
    }
};

void AddSC_boss_kazrogal()
{
    RegisterHyjalCreatureAI(boss_kazrogal);
    RegisterSpellAndAuraScriptPair(spell_mark_of_kazrogal, spell_mark_of_kazrogal_aura);
}
