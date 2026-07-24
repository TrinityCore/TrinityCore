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
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum RajaxxTexts
{
    // Intro
    SAY_WAVE_3                = 0,
    SAY_WAVE_4                = 1,
    SAY_WAVE_5                = 2,
    SAY_WAVE_6                = 3,
    SAY_WAVE_7                = 4,
    SAY_INTRO                 = 5,

    // Combat
    SAY_SLAY                  = 6,
    SAY_DEATH                 = 7,
    EMOTE_FRENZY              = 8
};

enum RajaxxSpells
{
    SPELL_DISARM              = 6713,
    SPELL_THUNDERCRASH        = 25599,
    SPELL_FRENZY              = 8269
};

enum RajaxxEvents
{
    EVENT_DISARM              = 1,
    EVENT_THUNDERCRASH,
    EVENT_FRENZY
};

// 15341 - General Rajaxx
struct boss_rajaxx : public BossAI
{
    boss_rajaxx(Creature* creature) : BossAI(creature, DATA_RAJAXX), _frenzied(false) { }

    void Reset() override
    {
        _Reset();
        _frenzied = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_DISARM, 10s, 20s);
        events.ScheduleEvent(EVENT_THUNDERCRASH, 10s, 15s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_frenzied && me->HealthBelowPctDamaged(30, damage))
        {
            _frenzied = true;
            events.ScheduleEvent(EVENT_FRENZY, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_FRENZY)
            Talk(EMOTE_FRENZY);
    }

    void DoAction(int32 action) override
    {
        if (!me->IsAlive())
            return;

        switch (action)
        {
            case ACTION_WAVE_STARTS_3:
                Talk(SAY_WAVE_3);
                break;
            case ACTION_WAVE_STARTS_4:
                Talk(SAY_WAVE_4);
                break;
            case ACTION_WAVE_STARTS_5:
                Talk(SAY_WAVE_5);
                break;
            case ACTION_WAVE_STARTS_6:
                Talk(SAY_WAVE_6);
                break;
            case ACTION_WAVE_STARTS_7:
                Talk(SAY_WAVE_7);
                break;
            case ACTION_RAJAXX_ENTER:
                Talk(SAY_INTRO);
                DoZoneInCombat();
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
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
                case EVENT_DISARM:
                    DoCastVictim(SPELL_DISARM);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_THUNDERCRASH:
                    DoCastSelf(SPELL_THUNDERCRASH);
                    events.Repeat(20s, 35s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
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
    bool _frenzied;
};

// 25599 - Thundercrash
class spell_rajaxx_thundercrash : public SpellScript
{
    PrepareSpellScript(spell_rajaxx_thundercrash);

    void HandleDamageCalc(SpellEffIndex /*effIndex*/)
    {
        int32 damage = GetHitUnit()->GetHealth() / 2;
        if (damage < 200)
            damage = 200;

        SetEffectValue(damage);
    }

    void HandleAfterCast()
    {
        if (GetCaster()->CanHaveThreatList())
            GetCaster()->GetThreatManager().ResetAllThreat();
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_rajaxx_thundercrash::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        AfterCast += SpellCastFn(spell_rajaxx_thundercrash::HandleAfterCast);
    }
};

void AddSC_boss_rajaxx()
{
    RegisterAQ20CreatureAI(boss_rajaxx);
    RegisterSpellScript(spell_rajaxx_thundercrash);
}
