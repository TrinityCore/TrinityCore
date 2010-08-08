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
SDName: Boss_Rajaxx
SD%Complete: 0
SDComment: Place Holder
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "ScriptPCH.h"
#include "ruins_of_ahnqiraj.h"

enum Yells
{
    SAY_ANDOROV_INTRO         = -1509003,
    SAY_ANDOROV_ATTACK        = -1509004,
    SAY_WAVE3                 = -1509005,
    SAY_WAVE4                 = -1509006,
    SAY_WAVE5                 = -1509007,
    SAY_WAVE6                 = -1509008,
    SAY_WAVE7                 = -1509009,
    SAY_INTRO                 = -1509010,
    SAY_UNK1                  = -1509011,
    SAY_UNK2                  = -1509012,
    SAY_UNK3                  = -1509013,
    SAY_UNK4                  = -1509014,
    SAY_DEAGGRO               = -1509015,
    SAY_KILLS_ANDOROV         = -1509016,
    SAY_COMPLETE_QUEST        = -1509017                        //Yell when realm complete quest 8743 for world event
};

class boss_rajaxx : public CreatureScript
{
public:
    boss_rajaxx() : CreatureScript("boss_rajaxx") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_rajaxxAI (pCreature);
    }

    struct boss_rajaxxAI : public ScriptedAI
    {
        boss_rajaxxAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        void Reset()
        {
            if (pInstance)
                pInstance->SetData(DATA_RAJAXX_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_RAJAXX_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit * /*killer*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_RAJAXX_EVENT, DONE);
        }
    };

};

void AddSC_boss_rajaxx()
{
    new boss_rajaxx();
}
