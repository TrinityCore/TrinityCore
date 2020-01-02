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

/* ScriptData
SDName: Boss_Luetenant_Drake
SD%Complete: 70
SDComment: Missing proper code for patrolling area after being spawned. Script for GO (barrels) quest 10283
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "old_hillsbrad.h"
#include "ScriptedEscortAI.h"

/*######
## go_barrel_old_hillsbrad
######*/

class go_barrel_old_hillsbrad : public GameObjectScript
{
public:
    go_barrel_old_hillsbrad() : GameObjectScript("go_barrel_old_hillsbrad") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go) override
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

class boss_lieutenant_drake : public CreatureScript
{
public:
    boss_lieutenant_drake() : CreatureScript("boss_lieutenant_drake") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetOldHillsbradAI<boss_lieutenant_drakeAI>(creature);
    }

    struct boss_lieutenant_drakeAI : public ScriptedAI
    {
        boss_lieutenant_drakeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            CanPatrol = true;
            wpId = 0;

            Whirlwind_Timer = 20000;
            Fear_Timer = 30000;
            MortalStrike_Timer = 45000;
            ExplodingShout_Timer = 25000;
        }

        bool CanPatrol;
        uint32 wpId;

        uint32 Whirlwind_Timer;
        uint32 Fear_Timer;
        uint32 MortalStrike_Timer;
        uint32 ExplodingShout_Timer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
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

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Whirlwind
            if (Whirlwind_Timer <= diff)
            {
                DoCastVictim(SPELL_WHIRLWIND);
                Whirlwind_Timer = 20000 + rand32() % 5000;
            } else Whirlwind_Timer -= diff;

            //Fear
            if (Fear_Timer <= diff)
            {
                Talk(SAY_SHOUT);
                DoCastVictim(SPELL_FRIGHTENING_SHOUT);
                Fear_Timer = 25000 + rand32() % 10000;
            } else Fear_Timer -= diff;

            //Mortal Strike
            if (MortalStrike_Timer <= diff)
            {
                Talk(SAY_MORTAL);
                DoCastVictim(SPELL_MORTAL_STRIKE);
                MortalStrike_Timer = 20000 + rand32() % 10000;
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
