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

#include "scarlet_monastery.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum BloodmageThalnosYells
{
    SAY_AGGRO = 0,
    SAY_HEALTH = 1,
    SAY_KILL = 2
};

enum BloodmageThalnosSpells
{
    SPELL_FLAMESHOCK = 8053,
    SPELL_SHADOWBOLT = 1106,
    SPELL_FLAMESPIKE = 8814,
    SPELL_FIRENOVA = 16079
};

enum BloodmageThalnosEvents
{
    EVENT_FLAME_SHOCK = 1,
    EVENT_SHADOW_BOLT,
    EVENT_FLAME_SPIKE,
    EVENT_FIRE_NOVA
};

struct boss_bloodmage_thalnos : public BossAI
{
    boss_bloodmage_thalnos(Creature* creature) : BossAI(creature, DATA_BLOODMAGE_THALNOS)
    {
        _hpYell = false;
    }

    void Reset() override
    {
        _hpYell = false;
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_FLAME_SHOCK, 10s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 2s);
        events.ScheduleEvent(EVENT_FLAME_SPIKE, 8s);
        events.ScheduleEvent(EVENT_FIRE_NOVA, 40s);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!_hpYell && me->HealthBelowPctDamaged(35, damage))
        {
            Talk(SAY_HEALTH);
            _hpYell = true;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_FLAME_SHOCK:
                DoCastVictim(SPELL_FLAMESHOCK);
                events.Repeat(10s, 15s);
                break;
            case EVENT_SHADOW_BOLT:
                DoCastVictim(SPELL_SHADOWBOLT);
                events.Repeat(2s);
                break;
            case EVENT_FLAME_SPIKE:
                DoCastVictim(SPELL_FLAMESPIKE);
                events.Repeat(30s);
                break;
            case EVENT_FIRE_NOVA:
                DoCastVictim(SPELL_FIRENOVA);
                events.Repeat(40s);
                break;
            default:
                break;
        }
    }

private:
    bool _hpYell;
};

void AddSC_boss_bloodmage_thalnos()
{
    RegisterScarletMonasteryCreatureAI(boss_bloodmage_thalnos);
}
