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

#include "scholomance.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum VectusEmotes
{
    EMOTE_FRENZY                 = 0
};

enum VectusSpells
{
    SPELL_FLAMESTRIKE            = 18399,
    SPELL_BLAST_WAVE             = 16046,
    SPELL_FIRE_SHIELD            = 19626,
    SPELL_FRENZY                 = 8269  // 28371
};

enum VectusEvents
{
    EVENT_FIRE_SHIELD = 1,
    EVENT_BLAST_WAVE,
    EVENT_FRENZY
};

enum VectusTalks
{
    TALK_IDLE   = 1,
    TALK_IDLE2  = 2,
    TALK_IDLE3  = 3
};

enum VectusPaths
{
    PATH_VECTUS_IDLE = 3904400
};

class boss_vectus : public CreatureScript
{
public:
    boss_vectus() : CreatureScript("boss_vectus") { }

    struct boss_vectusAI : public BossAI
    {
        boss_vectusAI(Creature* creature) : BossAI(creature, DATA_VECTUS) { }

        void JustEngagedWith(Unit* who) override
        {
            _JustEngagedWith(who);
            events.ScheduleEvent(EVENT_FIRE_SHIELD, 2s);
            events.ScheduleEvent(EVENT_BLAST_WAVE, 14s);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (me->HealthBelowPctDamaged(25, damage))
            {
                DoCast(me, SPELL_FRENZY);
                Talk(EMOTE_FRENZY);
                events.ScheduleEvent(EVENT_FRENZY, 24s);
            }
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
                    case EVENT_FIRE_SHIELD:
                        DoCast(me, SPELL_FIRE_SHIELD);
                        events.ScheduleEvent(EVENT_FIRE_SHIELD, 90s);
                        break;
                    case EVENT_BLAST_WAVE:
                        DoCast(me, SPELL_BLAST_WAVE);
                        events.ScheduleEvent(EVENT_BLAST_WAVE, 12s);
                        break;
                    case EVENT_FRENZY:
                        DoCast(me, SPELL_FRENZY);
                        Talk(EMOTE_FRENZY);
                        events.ScheduleEvent(EVENT_FRENZY, 24s);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
        }

        void WaypointReached(uint32 waypointId, uint32 pathId) override
        {
            if (pathId != PATH_VECTUS_IDLE)
                return;

            if (waypointId == 2)
                Talk(TALK_IDLE);
            else if (waypointId == 3)
                Talk(TALK_IDLE2);
            else if (waypointId == 4)
                Talk(TALK_IDLE3);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScholomanceAI<boss_vectusAI>(creature);
    }
};

void AddSC_boss_vectus()
{
    new boss_vectus();
}
