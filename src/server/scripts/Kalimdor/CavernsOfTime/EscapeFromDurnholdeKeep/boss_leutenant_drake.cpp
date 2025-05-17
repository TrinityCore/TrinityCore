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

/* Missing proper code for patrolling area after being spawned */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "old_hillsbrad.h"
#include "ScriptedEscortAI.h"

enum DrakeTexts
{
    SAY_ENTER               = 0,
    SAY_AGGRO               = 1,
    SAY_SLAY                = 2,
    SAY_MORTAL              = 3,
    SAY_SHOUT               = 4,
    SAY_DEATH               = 5,
};

enum DrakeSpells
{
    SPELL_WHIRLWIND         = 31909,
    SPELL_HAMSTRING         = 9080,
    SPELL_MORTAL_STRIKE     = 31911,
    SPELL_FRIGHTENING_SHOUT = 33789
};

enum DrakeEvents
{
    EVENT_WHIRLWIND           = 1,
    EVENT_HAMSTRING,
    EVENT_MORTAL_STRIKE,
    EVENT_FRIGHTENING_SHOUT
};

Position const DrakeWP[]=
{
    { 2125.84f, 88.2535f, 54.8830f },
    { 2111.01f, 93.8022f, 52.6356f },
    { 2106.70f, 114.753f, 53.1965f },
    { 2107.76f, 138.746f, 52.5109f },
    { 2114.83f, 160.142f, 52.4738f },
    { 2125.24f, 178.909f, 52.7283f },
    { 2151.02f, 208.901f, 53.1551f },
    { 2177.00f, 233.069f, 52.4409f },
    { 2190.71f, 227.831f, 53.2742f },
    { 2178.14f, 214.219f, 53.0779f },
    { 2154.99f, 202.795f, 52.6446f },
    { 2132.00f, 191.834f, 52.5709f },
    { 2117.59f, 166.708f, 52.7686f },
    { 2093.61f, 139.441f, 52.7616f },
    { 2086.29f, 104.950f, 52.9246f },
    { 2094.23f, 81.2788f, 52.6946f },
    { 2108.70f, 85.3075f, 53.3294f },
    { 2125.50f, 88.9481f, 54.7953f },
    { 2128.20f, 70.9763f, 64.4221f }
};

// 17848 - Lieutenant Drake
struct boss_lieutenant_drake : public BossAI
{
    boss_lieutenant_drake(Creature* creature) : BossAI(creature, DATA_LIEUTENANT_DRAKE)
    {
        Initialize();
    }

    void Initialize()
    {
        CanPatrol = true;
        wpId = 0;
    }

    bool CanPatrol;
    uint32 wpId;

    void Reset() override
    {
        BossAI::Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_WHIRLWIND, 20s);
        events.ScheduleEvent(EVENT_HAMSTRING, 30s);
        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 45s);
        events.ScheduleEvent(EVENT_FRIGHTENING_SHOUT, 25s);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        /// @todo make this work
        if (CanPatrol && wpId == 0)
        {
            me->GetMotionMaster()->MovePoint(wpId, DrakeWP[wpId]);
            ++wpId;
        }

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    events.Repeat(20s, 25s);
                    break;
                case EVENT_HAMSTRING:
                    DoCastVictim(SPELL_HAMSTRING);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_MORTAL_STRIKE:
                    Talk(SAY_MORTAL);
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_FRIGHTENING_SHOUT:
                    Talk(SAY_SHOUT);
                    DoCastVictim(SPELL_FRIGHTENING_SHOUT);
                    events.Repeat(25s, 35s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct go_barrel_old_hillsbrad : public GameObjectAI
{
    go_barrel_old_hillsbrad(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

    InstanceScript* instance;

    bool OnGossipHello(Player* /*player*/) override
    {
        if (instance->GetData(TYPE_BARREL_DIVERSION) == DONE)
            return false;

        instance->SetData(TYPE_BARREL_DIVERSION, IN_PROGRESS);
        return false;
    }
};

void AddSC_boss_lieutenant_drake()
{
    RegisterOldHillsbradCreatureAI(boss_lieutenant_drake);
    RegisterOldHillsbradGameObjectAI(go_barrel_old_hillsbrad);
}
