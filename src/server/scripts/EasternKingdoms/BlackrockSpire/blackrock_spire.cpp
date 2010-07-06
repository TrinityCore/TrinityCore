/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "blackrock_spire.h"

enum Creatures
{
    NPC_ROOKERY_WHELP                             = 10161
};

struct npc_rookey_whelpAI : public ScriptedAI
{
    npc_rookey_whelpAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    void JustDied(Unit * /*who*/)
    {
        if (pInstance)
            pInstance->SetData(WHELP_DEATH_COUNT, pInstance->GetData(WHELP_DEATH_COUNT)+1);
    }

    void UpdateAI(const uint32 /*diff*/)
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_rookey_whelp(Creature* pCreature)
{
    return new npc_rookey_whelpAI(pCreature);
}

bool GOHello_rookey_egg(Player *pPlayer, GameObject * /*pGO*/)
{
    Position pos;
    pPlayer->GetPosition(&pos);
    pPlayer->SummonCreature(NPC_ROOKERY_WHELP, pos, TEMPSUMMON_TIMED_DESPAWN, 15*IN_MILISECONDS);
    //destroy gobject need to be implemented

    return true;
};

void AddSC_blackrock_spire()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_rookey_whelp";
    newscript->GetAI = &GetAI_rookey_whelp;
    newscript->RegisterSelf();
    newscript = new Script;

    newscript->Name = "go_rookey_egg";
    newscript->pGOHello = &GOHello_rookey_egg;
    newscript->RegisterSelf();
}
