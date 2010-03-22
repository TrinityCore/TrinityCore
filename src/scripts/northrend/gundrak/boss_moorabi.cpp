/*
* Copyright (C) 2009-2010 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "ScriptedPch.h"
#include "gundrak.h"

enum eSpells
{
    SPELL_DETERMINED_STAB                         = 55104,
    SPELL_GROUND_TREMOR                           = 55142,
    SPELL_NUMBING_SHOUT                           = 55106,
    SPELL_DETERMINED_GORE                         = 55102,
    SPELL_DETERMINED_GORE_1                       = 59444,
    SPELL_QUAKE                                   = 55101,
    SPELL_NUMBING_ROAR                            = 55100,
    SPELL_MOJO_FRENZY                             = 55163,
    SPELL_TRANSFORMATION                          = 55098, //Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.
};

enum eArchivements
{
    ACHIEVEMENT_LESS_RABI       =   2040
};

enum eSays
{
    SAY_AGGRO                   =   -1604010,
    //SAY_SLAY_1                =   -1604011, // not in db
    SAY_SLAY_2                  =   -1604012,
    SAY_SLAY_3                  =   -1604013,
    SAY_DEATH                   =   -1604014,
    SAY_TRANSFORM               =   -1604015,
    SAY_QUAKE                   =   -1604016,
    EMOTE_TRANSFORM             =   -1604017
};

struct boss_moorabiAI : public ScriptedAI
{
    boss_moorabiAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool bPhase;

    uint32 uiNumblingShoutTimer;
    uint32 uiGroundTremorTimer;
    uint32 uiDeterminedStabTimer;
    uint32 uiTransformationTImer;

    void Reset()
    {
        uiGroundTremorTimer = 18000;
        uiNumblingShoutTimer =  10000;
        uiDeterminedStabTimer = 20000;
        uiTransformationTImer = 12000;
        bPhase = false;

        if (pInstance)
            pInstance->SetData(DATA_MOORABI_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoCast(m_creature, SPELL_MOJO_FRENZY, true);

        if (pInstance)
            pInstance->SetData(DATA_MOORABI_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
         if (!UpdateVictim())
             return;

        if(!bPhase && m_creature->HasAura(SPELL_TRANSFORMATION))
        {
            bPhase = true;
            m_creature->RemoveAura(SPELL_MOJO_FRENZY);
        }

        if (uiGroundTremorTimer <= uiDiff)
        {
            DoScriptText(SAY_QUAKE, m_creature);
            if (bPhase)
                DoCast(m_creature->getVictim(), SPELL_QUAKE, true);
            else
                DoCast(m_creature->getVictim(), SPELL_GROUND_TREMOR, true);
            uiGroundTremorTimer = 10000;
        } else uiGroundTremorTimer -= uiDiff;

        if (uiNumblingShoutTimer <= uiDiff)
        {
            if (bPhase)
                DoCast(m_creature->getVictim(), SPELL_NUMBING_ROAR, true);
            else
                DoCast(m_creature->getVictim(), SPELL_NUMBING_SHOUT, true);
            uiNumblingShoutTimer = 10000;
        } else uiNumblingShoutTimer -=uiDiff;

        if (uiDeterminedStabTimer <= uiDiff)
        {
            if (bPhase)
                DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_DETERMINED_GORE, SPELL_DETERMINED_GORE_1));
            else
                DoCast(m_creature->getVictim(), SPELL_DETERMINED_STAB, true);
            uiDeterminedStabTimer = 8000;
        } else uiDeterminedStabTimer -=uiDiff;

        if (!bPhase && uiTransformationTImer <= uiDiff)
        {
            DoScriptText(EMOTE_TRANSFORM, m_creature);
            DoScriptText(SAY_TRANSFORM, m_creature);
            DoCast(m_creature, SPELL_TRANSFORMATION, false);
            uiTransformationTImer = 10000;
        } else uiTransformationTImer -= uiDiff;

        DoMeleeAttackIfReady();
     }

     void JustDied(Unit* pKiller)
     {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
        {
            pInstance->SetData(DATA_MOORABI_EVENT, DONE);

            if (IsHeroic() && !bPhase)
                pInstance->DoCompleteAchievement(ACHIEVEMENT_LESS_RABI);
        }
    }

    void KilledUnit(Unit* pVictim)
    {
        if (pVictim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_moorabi(Creature *pCreature)
{
    return new boss_moorabiAI(pCreature);
}

void AddSC_boss_moorabi()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_moorabi";
    newscript->GetAI = &GetAI_boss_moorabi;
    newscript->RegisterSelf();
}
