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
SDName: Boss_Hakkar
SD%Complete: 95
SDComment: Blood siphon spell buggy cause of Core Issue.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptPCH.h"
#include "zulgurub.h"

#define SAY_AGGRO                   -1309020
#define SAY_FLEEING                 -1309021
#define SAY_MINION_DESTROY          -1309022                //where does it belong?
#define SAY_PROTECT_ALTAR           -1309023                //where does it belong?

#define SPELL_BLOODSIPHON            24322
#define SPELL_CORRUPTEDBLOOD         24328
#define SPELL_CAUSEINSANITY          24327                  //Not working disabled.
#define SPELL_WILLOFHAKKAR           24178
#define SPELL_ENRAGE                 24318

// The Aspects of all High Priests
#define SPELL_ASPECT_OF_JEKLIK       24687
#define SPELL_ASPECT_OF_VENOXIS      24688
#define SPELL_ASPECT_OF_MARLI        24686
#define SPELL_ASPECT_OF_THEKAL       24689
#define SPELL_ASPECT_OF_ARLOKK       24690

struct boss_hakkarAI : public ScriptedAI
{
    boss_hakkarAI(Creature *c) : ScriptedAI(c)
    {
        m_pInstance = c->GetInstanceData();
    }

    ScriptedInstance *m_pInstance;

    uint32 BloodSiphon_Timer;
    uint32 CorruptedBlood_Timer;
    uint32 CauseInsanity_Timer;
    uint32 WillOfHakkar_Timer;
    uint32 Enrage_Timer;

    uint32 CheckJeklik_Timer;
    uint32 CheckVenoxis_Timer;
    uint32 CheckMarli_Timer;
    uint32 CheckThekal_Timer;
    uint32 CheckArlokk_Timer;

    uint32 AspectOfJeklik_Timer;
    uint32 AspectOfVenoxis_Timer;
    uint32 AspectOfMarli_Timer;
    uint32 AspectOfThekal_Timer;
    uint32 AspectOfArlokk_Timer;

    bool Enraged;

    void Reset()
    {
        BloodSiphon_Timer = 90000;
        CorruptedBlood_Timer = 25000;
        CauseInsanity_Timer = 17000;
        WillOfHakkar_Timer = 17000;
        Enrage_Timer = 600000;

        CheckJeklik_Timer = 1000;
        CheckVenoxis_Timer = 2000;
        CheckMarli_Timer = 3000;
        CheckThekal_Timer = 4000;
        CheckArlokk_Timer = 5000;

        AspectOfJeklik_Timer = 4000;
        AspectOfVenoxis_Timer = 7000;
        AspectOfMarli_Timer = 12000;
        AspectOfThekal_Timer = 8000;
        AspectOfArlokk_Timer = 18000;

        Enraged = false;
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //BloodSiphon_Timer
        if (BloodSiphon_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_BLOODSIPHON);
            BloodSiphon_Timer = 90000;
        } else BloodSiphon_Timer -= diff;

        //CorruptedBlood_Timer
        if (CorruptedBlood_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_CORRUPTEDBLOOD);
            CorruptedBlood_Timer = 30000 + rand()%15000;
        } else CorruptedBlood_Timer -= diff;

        //CauseInsanity_Timer
        /*if (CauseInsanity_Timer <= diff)
        {
        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
        DoCast(pTarget, SPELL_CAUSEINSANITY);

        CauseInsanity_Timer = 35000 + rand()%8000;
        } else CauseInsanity_Timer -= diff;*/

        //WillOfHakkar_Timer
        if (WillOfHakkar_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(pTarget, SPELL_WILLOFHAKKAR);

            WillOfHakkar_Timer = 25000 + rand()%10000;
        } else WillOfHakkar_Timer -= diff;

        if (!Enraged && Enrage_Timer <= diff)
        {
            DoCast(me, SPELL_ENRAGE);
            Enraged = true;
        } else Enrage_Timer -= diff;

        //Checking if Jeklik is dead. If not we cast her Aspect
        if (CheckJeklik_Timer <= diff)
        {
            if (m_pInstance)
            {
                if (m_pInstance->GetData(TYPE_JEKLIK) != DONE)
                {
                    if (AspectOfJeklik_Timer <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_ASPECT_OF_JEKLIK);
                        AspectOfJeklik_Timer = 10000 + rand()%4000;
                    } else AspectOfJeklik_Timer -= diff;
                }
            }
            CheckJeklik_Timer = 1000;
        } else CheckJeklik_Timer -= diff;

        //Checking if Venoxis is dead. If not we cast his Aspect
        if (CheckVenoxis_Timer <= diff)
        {
            if (m_pInstance)
            {
                if (m_pInstance->GetData(TYPE_VENOXIS) != DONE)
                {
                    if (AspectOfVenoxis_Timer <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_ASPECT_OF_VENOXIS);
                        AspectOfVenoxis_Timer = 8000;
                    } else AspectOfVenoxis_Timer -= diff;
                }
            }
            CheckVenoxis_Timer = 1000;
        } else CheckVenoxis_Timer -= diff;

        //Checking if Marli is dead. If not we cast her Aspect
        if (CheckMarli_Timer <= diff)
        {
            if (m_pInstance)
            {
                if (m_pInstance->GetData(TYPE_MARLI) != DONE)
                {
                    if (AspectOfMarli_Timer <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_ASPECT_OF_MARLI);
                        AspectOfMarli_Timer = 10000;
                    } else AspectOfMarli_Timer -= diff;

                }
            }
            CheckMarli_Timer = 1000;
        } else CheckMarli_Timer -= diff;

        //Checking if Thekal is dead. If not we cast his Aspect
        if (CheckThekal_Timer <= diff)
        {
            if (m_pInstance)
            {
                if (m_pInstance->GetData(TYPE_THEKAL) != DONE)
                {
                    if (AspectOfThekal_Timer <= diff)
                    {
                        DoCast(me, SPELL_ASPECT_OF_THEKAL);
                        AspectOfThekal_Timer = 15000;
                    } else AspectOfThekal_Timer -= diff;
                }
            }
            CheckThekal_Timer = 1000;
        } else CheckThekal_Timer -= diff;

        //Checking if Arlokk is dead. If yes we cast her Aspect
        if (CheckArlokk_Timer <= diff)
        {
            if (m_pInstance)
            {
                if (m_pInstance->GetData(TYPE_ARLOKK) != DONE)
                {
                    if (AspectOfArlokk_Timer <= diff)
                    {
                        DoCast(me, SPELL_ASPECT_OF_ARLOKK);
                        DoResetThreat();

                        AspectOfArlokk_Timer = 10000 + rand()%5000;
                    } else AspectOfArlokk_Timer -= diff;
                }
            }
            CheckArlokk_Timer = 1000;
        } else CheckArlokk_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_hakkar(Creature* pCreature)
{
    return new boss_hakkarAI (pCreature);
}

void AddSC_boss_hakkar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_hakkar";
    newscript->GetAI = &GetAI_boss_hakkar;
    newscript->RegisterSelf();
}

