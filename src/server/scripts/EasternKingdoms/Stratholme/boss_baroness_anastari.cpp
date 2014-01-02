/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Baroness_Anastari
SD%Complete: 90
SDComment: MC disabled
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_BANSHEEWAIL       = 16565,
    SPELL_BANSHEECURSE      = 16867,
    SPELL_SILENCE           = 18327
    //SPELL_POSSESS           = 17244
};

class boss_baroness_anastari : public CreatureScript
{
public:
    boss_baroness_anastari() : CreatureScript("boss_baroness_anastari") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_baroness_anastariAI>(creature);
    }

    struct boss_baroness_anastariAI : public ScriptedAI
    {
        boss_baroness_anastariAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 BansheeWail_Timer;
        uint32 BansheeCurse_Timer;
        uint32 Silence_Timer;
        //uint32 Possess_Timer;

        void Reset() OVERRIDE
        {
            BansheeWail_Timer = 1000;
            BansheeCurse_Timer = 11000;
            Silence_Timer = 13000;
            //Possess_Timer = 35000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            instance->SetData(TYPE_BARONESS, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            //BansheeWail
            if (BansheeWail_Timer <= diff)
            {
                if (rand()%100 < 95)
                    DoCastVictim(SPELL_BANSHEEWAIL);
                //4 seconds until we should cast this again
                BansheeWail_Timer = 4000;
            } else BansheeWail_Timer -= diff;

            //BansheeCurse
            if (BansheeCurse_Timer <= diff)
            {
                if (rand()%100 < 75)
                    DoCastVictim(SPELL_BANSHEECURSE);
                //18 seconds until we should cast this again
                BansheeCurse_Timer = 18000;
            } else BansheeCurse_Timer -= diff;

            //Silence
            if (Silence_Timer <= diff)
            {
                if (rand()%100 < 80)
                    DoCastVictim(SPELL_SILENCE);
                //13 seconds until we should cast this again
                Silence_Timer = 13000;
            } else Silence_Timer -= diff;

            //Possess
            /*            if (Possess_Timer <= diff)
            {
            //Cast
              if (rand()%100 < 65)
            {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (target)DoCast(target, SPELL_POSSESS);
            }
            //50 seconds until we should cast this again
            Possess_Timer = 50000;
            } else Possess_Timer -= diff;
            */

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_baroness_anastari()
{
    new boss_baroness_anastari();
}
