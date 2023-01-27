/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: boss_postmaster_malown
SD%Complete: 50
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"

//Spell ID to summon this guy is 24627 "Summon Postmaster Malown"
//He should be spawned along with three other elites once the third postbox has been opened

#define SAY_AGGRO   -1900161
#define SAY_KILLED  -1900162

#define SPELL_WAILINGDEAD    7713
#define SPELL_BACKHAND    6253
#define SPELL_CURSEOFWEAKNESS    8552
#define SPELL_CURSEOFTONGUES    12889
#define SPELL_CALLOFTHEGRAVE    17831

struct boss_postmaster_malownAI : public ScriptedAI
{
    boss_postmaster_malownAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 WailingDead_Timer;
    uint32 Backhand_Timer;
    uint32 CurseOfWeakness_Timer;
    uint32 CurseOfTongues_Timer;
    uint32 CallOfTheGrave_Timer;
    bool HasYelled;

    void Reset() override
    {
        WailingDead_Timer = 19000; //lasts 6 sec
        Backhand_Timer = 8000; //2 sec stun
        CurseOfWeakness_Timer = 20000; //lasts 2 mins
        CurseOfTongues_Timer = 22000;
        CallOfTheGrave_Timer = 25000;
        HasYelled = false;
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
        ScriptedAI::Aggro(pWho);
    }

    void KilledUnit(Unit* pVictim) override
    {
        DoScriptText(SAY_KILLED, m_creature);
        ScriptedAI::KilledUnit(pVictim);
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //WailingDead
        if (WailingDead_Timer < diff)
        {
            //Cast
            if (rand() % 100 < 65) //65% chance to cast
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WAILINGDEAD);
            //19 seconds until we should cast this again
            WailingDead_Timer = 19000;
        }
        else WailingDead_Timer -= diff;

        //Backhand
        if (Backhand_Timer < diff)
        {
            //Cast
            if (rand() % 100 < 45) //45% chance to cast
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BACKHAND);
            //8 seconds until we should cast this again
            Backhand_Timer = 8000;
        }
        else Backhand_Timer -= diff;

        //CurseOfWeakness
        if (CurseOfWeakness_Timer < diff)
        {
            //Cast
            if (rand() % 100 < 3) //3% chance to cast
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSEOFWEAKNESS);
            //20 seconds until we should cast this again
            CurseOfWeakness_Timer = 20000;
        }
        else CurseOfWeakness_Timer -= diff;

        //CurseOfTongues
        if (CurseOfTongues_Timer < diff)
        {
            //Cast
            if (rand() % 100 < 3) //3% chance to cast
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSEOFTONGUES);
            //22 seconds until we should cast this again
            CurseOfTongues_Timer = 22000;
        }
        else CurseOfTongues_Timer -= diff;

        //CallOfTheGrave
        if (CallOfTheGrave_Timer < diff)
        {
            //Cast
            if (rand() % 100 < 5) //5% chance to cast
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CALLOFTHEGRAVE);
            //25 seconds until we should cast this again
            CallOfTheGrave_Timer = 25000;
        }
        else CallOfTheGrave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_postmaster_malown(Creature* pCreature)
{
    return new boss_postmaster_malownAI(pCreature);
}

void AddSC_boss_postmaster_malown()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_postmaster_malown";
    newscript->GetAI = &GetAI_boss_postmaster_malown;
    newscript->RegisterSelf();
}
