/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "gundrak.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

/// @todo: implement mojo frenzy

enum Spells
{
    SPELL_DETERMINED_GORE       = 55102,
    SPELL_DETERMINED_STAB       = 55104,
    SPELL_GROUND_TREMOR         = 55142,
    SPELL_NUMBING_SHOUT         = 55106,
    SPELL_QUAKE                 = 55101,
    SPELL_NUMBING_ROAR          = 55100,
    SPELL_MOJO_FRENZY           = 55163,
    SPELL_TRANSFORMATION        = 55098, // Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.
};

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2,
    SAY_TRANSFORM               = 3,
    SAY_QUAKE                   = 4,
    EMOTE_BEGIN_TRANSFORM       = 5,
    EMOTE_TRANSFORMED           = 6,
    EMOTE_ACTIVATE_ALTAR        = 7
};

enum Events
{
    EVENT_GROUND_TREMOR         = 1,
    EVENT_NUMBLING_SHOUT,
    EVENT_DETERMINED_STAB,
    EVENT_TRANFORMATION
};

enum Misc
{
    DATA_LESS_RABI              = 1
};

class boss_moorabi : public CreatureScript
{
    public:
        boss_moorabi() : CreatureScript("boss_moorabi") { }

        struct boss_moorabiAI : public BossAI
        {
            boss_moorabiAI(Creature* creature) : BossAI(creature, DATA_MOORABI)
            {
                Initialize();
            }

            void Initialize()
            {
                _transformed = false;
            }

            void Reset() override
            {
                Initialize();
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_MOJO_FRENZY, true);

                events.ScheduleEvent(EVENT_GROUND_TREMOR, 18 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_NUMBLING_SHOUT, 10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_DETERMINED_STAB, 20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_TRANFORMATION, 12 * IN_MILLISECONDS);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_LESS_RABI)
                    return _transformed ? 0 : 1;
                return 0;
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                Talk(EMOTE_ACTIVATE_ALTAR);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_TRANSFORMATION)
                {
                    _transformed = true;
                    Talk(EMOTE_TRANSFORMED);
                    events.CancelEvent(EVENT_TRANFORMATION);
                    me->RemoveAurasDueToSpell(SPELL_MOJO_FRENZY);
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_GROUND_TREMOR:
                        Talk(SAY_QUAKE);
                        if (_transformed)
                            DoCastAOE(SPELL_QUAKE);
                        else
                            DoCastAOE(SPELL_GROUND_TREMOR);
                        events.ScheduleEvent(eventId, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_NUMBLING_SHOUT:
                        if (_transformed)
                            DoCastAOE(SPELL_NUMBING_ROAR);
                        else
                            DoCastAOE(SPELL_NUMBING_SHOUT);
                        events.ScheduleEvent(eventId, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_DETERMINED_STAB:
                        if (_transformed)
                            DoCastVictim(SPELL_DETERMINED_GORE);
                        else
                            DoCastVictim(SPELL_DETERMINED_STAB);
                        events.ScheduleEvent(eventId, 8 * IN_MILLISECONDS);
                        break;
                    case EVENT_TRANFORMATION:
                        Talk(EMOTE_BEGIN_TRANSFORM);
                        Talk(SAY_TRANSFORM);
                        DoCast(me, SPELL_TRANSFORMATION);
                        events.ScheduleEvent(eventId, 10 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

        private:
            bool _transformed;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGundrakAI<boss_moorabiAI>(creature);
        }
};

class achievement_less_rabi : public AchievementCriteriaScript
{
    public:
        achievement_less_rabi() : AchievementCriteriaScript("achievement_less_rabi") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Moorabi = target->ToCreature())
                if (Moorabi->AI()->GetData(DATA_LESS_RABI))
                    return true;

            return false;
        }
};

void AddSC_boss_moorabi()
{
    new boss_moorabi();
    new achievement_less_rabi();
}
