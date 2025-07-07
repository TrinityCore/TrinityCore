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

#include "MovementDefines.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum DoomwalkerSpells
{
    SPELL_SUMMON_OVERRUN_TARGET       = 32632, // Serverside
    SPELL_OVERRUN_TARGET_SPAWN        = 32634, // Serverside
    SPELL_OVERRUN_TARGET_SPAWN_EFFECT = 32635, // Serverside
    SPELL_OVERRUN                     = 32636,
    SPELL_OVERRUN_DAMAGE              = 32637,
    SPELL_LIGHTNING_WRATH             = 33665,
    SPELL_FRENZY                      = 33653,
    SPELL_CRUSH_ARMOR                 = 33661,
    SPELL_EARTHQUAKE                  = 326405,
    SPELL_KNOCKDOWN                   = 13360
};

enum DoomwalkerTexts
{
    SAY_AGGRO       = 0,
    SAY_EARTHQUAKE  = 1,
    SAY_OVERRUN     = 2,
    SAY_KILL        = 3,
    SAY_FRENZY      = 4,
    SAY_DEATH       = 5
};

enum DoomwalkerEvents
{
    EVENT_OVERRUN         = 1,
    EVENT_CRUSH_ARMOR,
    EVENT_LIGHTNING_WRATH,
    EVENT_EARTHQUAKE
};

enum DoomwalkerMisc
{
    POINT_OVERRUN         = 0,
    NPC_OVERRUN_TARGET    = 18665
};

// 167749 - Doomwalker
struct boss_doomwalker_anniversary : public WorldBossAI
{
    using WorldBossAI::WorldBossAI;

    void JustDied(Unit* killer) override
    {
        WorldBossAI::JustDied(killer);
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void JustEngagedWith(Unit* who) override
    {
        WorldBossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_OVERRUN, 15s, 40s);
        events.ScheduleEvent(EVENT_EARTHQUAKE, 30s, 55s);
        events.ScheduleEvent(EVENT_LIGHTNING_WRATH, 7s, 27s);
        events.ScheduleEvent(EVENT_CRUSH_ARMOR, 10s, 25s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
    {
        if (me->HealthBelowPctDamaged(20, damage))
        {
            Talk(SAY_FRENZY);
            DoCastSelf(SPELL_FRENZY);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_OVERRUN)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveAurasDueToSpell(SPELL_OVERRUN);

            if (Creature* overrunTarget = me->FindNearestCreature(NPC_OVERRUN_TARGET, 50.0f))
                overrunTarget->DespawnOrUnsummon();
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
                case EVENT_OVERRUN:
                {
                    DoCastSelf(SPELL_SUMMON_OVERRUN_TARGET);
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_OVERRUN);
                    DoCastSelf(SPELL_OVERRUN);
                    events.ScheduleEvent(EVENT_OVERRUN, 25s, 40s);
                    break;
                }
                case EVENT_EARTHQUAKE:
                {
                    Talk(SAY_EARTHQUAKE);
                    DoCastSelf(SPELL_EARTHQUAKE);
                    events.ScheduleEvent(EVENT_EARTHQUAKE, 30s, 55s);
                    break;
                }
                case EVENT_LIGHTNING_WRATH:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_LIGHTNING_WRATH);
                    events.ScheduleEvent(EVENT_LIGHTNING_WRATH, 7s, 27s);
                    break;
                }
                case EVENT_CRUSH_ARMOR:
                {
                    DoCastVictim(SPELL_CRUSH_ARMOR);
                    events.ScheduleEvent(EVENT_CRUSH_ARMOR, 10s, 25s);
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

void AddSC_boss_doomwalker_anniversary()
{
    RegisterCreatureAI(boss_doomwalker_anniversary);
}
