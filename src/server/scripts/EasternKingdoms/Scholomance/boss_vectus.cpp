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

enum VectusTexts
{
    EMOTE_FRENZY                 = 0,
    TALK_IDLE                    = 1,
    TALK_IDLE2                   = 2,
    TALK_IDLE3                   = 3
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

enum VectusPaths
{
    PATH_VECTUS_IDLE = 3904400
};

// 10432 - Vectus
struct boss_vectus : public BossAI
{
    boss_vectus(Creature* creature) : BossAI(creature, DATA_VECTUS) { }

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_FIRE_SHIELD, 2s);
        events.ScheduleEvent(EVENT_BLAST_WAVE, 14s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!me->HasAura(SPELL_FRENZY) && me->HealthBelowPctDamaged(25, damage))
            events.ScheduleEvent(EVENT_FRENZY, 0s);
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
                    DoCastSelf(SPELL_FIRE_SHIELD);
                    events.Repeat(90s);
                    break;
                case EVENT_BLAST_WAVE:
                    DoCastSelf(SPELL_BLAST_WAVE);
                    events.Repeat(12s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    Talk(EMOTE_FRENZY);
                    events.Repeat(24s);
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

void AddSC_boss_vectus()
{
    RegisterScholomanceCreatureAI(boss_vectus);
}
