/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Ossirian
SD%Complete: 0
SDComment: Place holder
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "ScriptPCH.h"
#include "ruins_of_ahnqiraj.h"

enum Yells
{
    SAY_SURPREME2   = -1509019,
    SAY_SURPREME3   = -1509020,
    SAY_RAND_INTRO1 = -1509021,
    SAY_RAND_INTRO2 = -1509022,
    SAY_RAND_INTRO3 = -1509023,
    SAY_RAND_INTRO4 = -1509024,                            //possibly old?
    SAY_AGGRO       = -1509025,
    SAY_SLAY        = -1509026,
    SAY_DEATH       = -1509027
};

class boss_ossirian : public CreatureScript
{
public:
    boss_ossirian() : CreatureScript("boss_ossirian") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ossirianAI (pCreature);
    }

    struct boss_ossirianAI : public ScriptedAI
    {
        boss_ossirianAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        void Reset()
        {
            if (pInstance)
                pInstance->SetData(DATA_OSSIRIAN_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_OSSIRIAN_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_OSSIRIAN_EVENT, DONE);
        }
    };

};

void AddSC_boss_ossirian()
{
    new boss_ossirian();
}
