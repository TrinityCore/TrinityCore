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
#include "SpellInfo.h"
#include "the_botanica.h"

enum ThorngrinTexts
{
    SAY_AGGRO                   = 0,
    SAY_20_PERCENT_HP           = 1,
    SAY_SLAY                    = 2,
    SAY_CAST_SACRIFICE          = 3,
    SAY_50_PERCENT_HP           = 4,
    SAY_CAST_HELLFIRE           = 5,
    SAY_DEATH                   = 6,
    EMOTE_ENRAGE                = 7,
    SAY_INTRO                   = 8
};

enum ThorngrinSpells
{
    SPELL_SACRIFICE             = 34661,
    SPELL_HELLFIRE              = 34659,
    SPELL_HELLFIRE_H            = 39131,
    SPELL_ENRAGE                = 34670
};

enum ThorngrinEvents
{
    EVENT_SACRIFICE             = 1,
    EVENT_HELLFIRE,
    EVENT_ENRAGE
};

enum ThorngrinPhases : uint8
{
    PHASE_NONE                  = 0,
    PHASE_HEALTH_50,
    PHASE_HEALTH_20
};

// 17978 - Thorngrin the Tender
struct boss_thorngrin_the_tender : public BossAI
{
    boss_thorngrin_the_tender(Creature* creature) : BossAI(creature, DATA_THORNGRIN_THE_TENDER), _phase(PHASE_NONE), _introDone(false) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
        _introDone = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!_introDone && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 75.0f))
        {
            _introDone = true;
            Talk(SAY_INTRO);
        }

        BossAI::MoveInLineOfSight(who);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_SACRIFICE, 30s, 40s);
        events.ScheduleEvent(EVENT_HELLFIRE, 5s, 15s);
        events.ScheduleEvent(EVENT_ENRAGE, 30s, 40s);
    }

    void OnSpellStart(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SACRIFICE)
            Talk(SAY_CAST_SACRIFICE);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_HELLFIRE:
            case SPELL_HELLFIRE_H:
                Talk(SAY_CAST_HELLFIRE);
                break;
            case SPELL_ENRAGE:
                Talk(EMOTE_ENRAGE);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_50 && me->HealthBelowPctDamaged(50, damage))
        {
            _phase++;
            Talk(SAY_50_PERCENT_HP);
        }
        if (_phase < PHASE_HEALTH_20 && me->HealthBelowPctDamaged(20, damage))
        {
            _phase++;
            Talk(SAY_20_PERCENT_HP);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                case EVENT_SACRIFICE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                        DoCast(target, SPELL_SACRIFICE);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_HELLFIRE:
                    DoCastSelf(SPELL_HELLFIRE);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE);
                    events.Repeat(30s, 40s);
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
    uint8 _phase;
    bool _introDone;
};

void AddSC_boss_thorngrin_the_tender()
{
    RegisterBotanicaCreatureAI(boss_thorngrin_the_tender);
}
