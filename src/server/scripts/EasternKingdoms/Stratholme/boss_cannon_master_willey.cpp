/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: boss_cannon_master_willey
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptPCH.h"

//front, left
#define ADD_1X 3553.851807f
#define ADD_1Y -2945.885986f
#define ADD_1Z 125.001015f
#define ADD_1O 0.592007f
//front, right
#define ADD_2X 3559.206299f
#define ADD_2Y -2952.929932f
#define ADD_2Z 125.001015f
#define ADD_2O 0.592007f
//mid, left
#define ADD_3X 3552.417480f
#define ADD_3Y -2948.667236f
#define ADD_3Z 125.001015f
#define ADD_3O 0.592007f
//mid, right
#define ADD_4X 3555.651855f
#define ADD_4Y -2953.519043f
#define ADD_4Z 125.001015f
#define ADD_4O 0.592007f
//back, left
#define ADD_5X 3547.927246f
#define ADD_5Y -2950.977295f
#define ADD_5Z 125.001015f
#define ADD_5O 0.592007f
//back, mid
#define ADD_6X 3553.094697f
#define ADD_6Y -2952.123291f
#define ADD_6Z 125.001015f
#define ADD_6O 0.592007f
//back, right
#define ADD_7X 3552.727539f
#define ADD_7Y -2957.776123f
#define ADD_7Z 125.001015f
#define ADD_7O 0.592007f
//behind, left
#define ADD_8X 3547.156250f
#define ADD_8Y -2953.162354f
#define ADD_8Z 125.001015f
#define ADD_8O 0.592007f
//behind, right
#define ADD_9X 3550.202148f
#define ADD_9Y -2957.437744f
#define ADD_9Z 125.001015f
#define ADD_9O 0.592007f

#define SPELL_KNOCKAWAY    10101
#define SPELL_PUMMEL    15615
#define SPELL_SHOOT    16496
//#define SPELL_SUMMONCRIMSONRIFLEMAN    17279

class boss_cannon_master_willey : public CreatureScript
{
public:
    boss_cannon_master_willey() : CreatureScript("boss_cannon_master_willey") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_cannon_master_willeyAI (pCreature);
    }

    struct boss_cannon_master_willeyAI : public ScriptedAI
    {
        boss_cannon_master_willeyAI(Creature *c) : ScriptedAI(c) {}

        uint32 KnockAway_Timer;
        uint32 Pummel_Timer;
        uint32 Shoot_Timer;
        uint32 SummonRifleman_Timer;

        void Reset()
        {
            Shoot_Timer = 1000;
            Pummel_Timer = 7000;
            KnockAway_Timer = 11000;
            SummonRifleman_Timer = 15000;
        }

        void JustDied(Unit* /*Victim*/)
        {
            me->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
            me->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
            me->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
            me->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
            me->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
            me->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
            me->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Pummel
            if (Pummel_Timer <= diff)
            {
                //Cast
                if (rand()%100 < 90) //90% chance to cast
                {
                    DoCast(me->getVictim(), SPELL_PUMMEL);
                }
                //12 seconds until we should cast this again
                Pummel_Timer = 12000;
            } else Pummel_Timer -= diff;

            //KnockAway
            if (KnockAway_Timer <= diff)
            {
                //Cast
                if (rand()%100 < 80) //80% chance to cast
                {
                    DoCast(me->getVictim(), SPELL_KNOCKAWAY);
                }
                //14 seconds until we should cast this again
                KnockAway_Timer = 14000;
            } else KnockAway_Timer -= diff;

            //Shoot
            if (Shoot_Timer <= diff)
            {
                //Cast
                DoCast(me->getVictim(), SPELL_SHOOT);
                //1 seconds until we should cast this again
                Shoot_Timer = 1000;
            } else Shoot_Timer -= diff;

            //SummonRifleman
            if (SummonRifleman_Timer <= diff)
            {
                //Cast
                switch (rand()%9)
                {
                case 0:
                    me->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 1:
                    me->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 2:
                    me->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_6X,ADD_6Y,ADD_6Z,ADD_6O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 3:
                    me->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 4:
                    me->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_6X,ADD_6Y,ADD_6Z,ADD_6O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_8X,ADD_8Y,ADD_8Z,ADD_8O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 5:
                    me->SummonCreature(11054,ADD_6X,ADD_6Y,ADD_6Z,ADD_6O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 6:
                    me->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_8X,ADD_8Y,ADD_8Z,ADD_8O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 7:
                    me->SummonCreature(11054,ADD_8X,ADD_8Y,ADD_8Z,ADD_8O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                case 8:
                    me->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    me->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
                    break;
                }
                //30 seconds until we should cast this again
                SummonRifleman_Timer = 30000;
            } else SummonRifleman_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_cannon_master_willey()
{
    new boss_cannon_master_willey();
}
