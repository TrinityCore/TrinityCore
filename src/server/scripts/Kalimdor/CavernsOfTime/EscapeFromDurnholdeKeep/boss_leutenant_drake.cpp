/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Luetenant_Drake
SD%Complete: 70
SDComment: Missing proper code for patrolling area after being spawned. Script for GO (barrels) quest 10283
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "old_hillsbrad.h"
#include "ScriptedEscortAI.h"

/*######
## go_barrel_old_hillsbrad
######*/

class go_barrel_old_hillsbrad : public GameObjectScript
{
public:
    go_barrel_old_hillsbrad() : GameObjectScript("go_barrel_old_hillsbrad") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (InstanceScript* instance = go->GetInstanceScript())
        {
            if (instance->GetData(TYPE_BARREL_DIVERSION) == DONE)
                return false;

            instance->SetData(TYPE_BARREL_DIVERSION, IN_PROGRESS);
        }

        return false;
    }

};

/*######
## boss_lieutenant_drake
######*/

enum LieutenantDrake
{
    SAY_ENTER               = 0,
    SAY_AGGRO               = 1,
    SAY_SLAY                = 2,
    SAY_MORTAL              = 3,
    SAY_SHOUT               = 4,
    SAY_DEATH               = 5,

    SPELL_WHIRLWIND         = 31909,
    SPELL_HAMSTRING         = 9080,
    SPELL_MORTAL_STRIKE     = 31911,
    SPELL_FRIGHTENING_SHOUT = 33789
};

struct Location
{
    uint32 wpId;
    float x;
    float y;
    float z;
};

static Location DrakeWP[]=
{
    {0, 2125.84f, 88.2535f, 54.8830f},
    {1, 2111.01f, 93.8022f, 52.6356f},
    {2, 2106.70f, 114.753f, 53.1965f},
    {3, 2107.76f, 138.746f, 52.5109f},
    {4, 2114.83f, 160.142f, 52.4738f},
    {5, 2125.24f, 178.909f, 52.7283f},
    {6, 2151.02f, 208.901f, 53.1551f},
    {7, 2177.00f, 233.069f, 52.4409f},
    {8, 2190.71f, 227.831f, 53.2742f},
    {9, 2178.14f, 214.219f, 53.0779f},
    {10, 2154.99f, 202.795f, 52.6446f},
    {11, 2132.00f, 191.834f, 52.5709f},
    {12, 2117.59f, 166.708f, 52.7686f},
    {13, 2093.61f, 139.441f, 52.7616f},
    {14, 2086.29f, 104.950f, 52.9246f},
    {15, 2094.23f, 81.2788f, 52.6946f},
    {16, 2108.70f, 85.3075f, 53.3294f},
    {17, 2125.50f, 88.9481f, 54.7953f},
    {18, 2128.20f, 70.9763f, 64.4221f}
};

class boss_lieutenant_drake : public CreatureScript
{
public:
    boss_lieutenant_drake() : CreatureScript("boss_lieutenant_drake") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lieutenant_drakeAI (creature);
    }

    struct boss_lieutenant_drakeAI : public ScriptedAI
    {
        boss_lieutenant_drakeAI(Creature* creature) : ScriptedAI(creature) {}

        bool CanPatrol;
        uint32 wpId;

        uint32 Whirlwind_Timer;
        uint32 Fear_Timer;
        uint32 MortalStrike_Timer;
        uint32 ExplodingShout_Timer;

        void Reset()
        {
            CanPatrol = true;
            wpId = 0;

            Whirlwind_Timer = 20000;
            Fear_Timer = 30000;
            MortalStrike_Timer = 45000;
            ExplodingShout_Timer = 25000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
        }

        void UpdateAI(const uint32 diff)
        {
            //TODO: make this work
            if (CanPatrol && wpId == 0)
            {
                me->GetMotionMaster()->MovePoint(DrakeWP[0].wpId, DrakeWP[0].x, DrakeWP[0].y, DrakeWP[0].z);
                ++wpId;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Whirlwind
            if (Whirlwind_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND);
                Whirlwind_Timer = 20000+rand()%5000;
            } else Whirlwind_Timer -= diff;

            //Fear
            if (Fear_Timer <= diff)
            {
                Talk(SAY_SHOUT);
                DoCast(me->getVictim(), SPELL_FRIGHTENING_SHOUT);
                Fear_Timer = 25000+rand()%10000;
            } else Fear_Timer -= diff;

            //Mortal Strike
            if (MortalStrike_Timer <= diff)
            {
                Talk(SAY_MORTAL);
                DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
                MortalStrike_Timer = 20000+rand()%10000;
            } else MortalStrike_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_lieutenant_drake()
{
    new go_barrel_old_hillsbrad();
    new boss_lieutenant_drake();
}
