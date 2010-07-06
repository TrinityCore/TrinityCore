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
SDName: boss_maleki_the_pallid
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptPCH.h"
#include "stratholme.h"

#define SPELL_FROSTBOLT    17503
#define SPELL_DRAINLIFE    20743
#define SPELL_DRAIN_MANA    17243
#define SPELL_ICETOMB    16869

struct boss_maleki_the_pallidAI : public ScriptedAI
{
    boss_maleki_the_pallidAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = me->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 Frostbolt_Timer;
    uint32 IceTomb_Timer;
    uint32 DrainLife_Timer;

    void Reset()
    {
        Frostbolt_Timer = 1000;
        IceTomb_Timer = 16000;
        DrainLife_Timer = 31000;
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void JustDied(Unit* /*Killer*/)
    {
        if (pInstance)
            pInstance->SetData(TYPE_PALLID,IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Frostbolt
        if (Frostbolt_Timer <= diff)
        {
             if (rand()%100 < 90)
                DoCast(me->getVictim(), SPELL_FROSTBOLT);
            Frostbolt_Timer = 3500;
        } else Frostbolt_Timer -= diff;

        //IceTomb
        if (IceTomb_Timer <= diff)
        {
            if (rand()%100 < 65)
                DoCast(me->getVictim(), SPELL_ICETOMB);
            IceTomb_Timer = 28000;
        } else IceTomb_Timer -= diff;

        //DrainLife
        if (DrainLife_Timer <= diff)
        {
              if (rand()%100 < 55)
                DoCast(me->getVictim(), SPELL_DRAINLIFE);
            DrainLife_Timer = 31000;
        } else DrainLife_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_maleki_the_pallid(Creature* pCreature)
{
    return new boss_maleki_the_pallidAI (pCreature);
}

void AddSC_boss_maleki_the_pallid()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_maleki_the_pallid";
    newscript->GetAI = &GetAI_boss_maleki_the_pallid;
    newscript->RegisterSelf();
}

