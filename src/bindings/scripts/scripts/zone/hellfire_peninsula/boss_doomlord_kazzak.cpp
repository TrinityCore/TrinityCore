/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Doomlord_Kazzak
SD%Complete: 70
SDComment: Using incorrect spell for Mark of Kazzak
SDCategory: Hellfire Peninsula
EndScriptData */

#include "precompiled.h"

#define SPELL_SHADOWVOLLEY              32963
#define SPELL_CLEAVE                    31779
#define SPELL_THUNDERCLAP               36706
#define SPELL_VOIDBOLT                  39329
#define SPELL_MARKOFKAZZAK              32960
#define SPELL_ENRAGE                    32964
#define SPELL_CAPTURESOUL               32966
#define SPELL_TWISTEDREFLECTION         21063

struct TRINITY_DLL_DECL boss_doomlordkazzakAI : public ScriptedAI
{
    boss_doomlordkazzakAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 ShadowVolley_Timer;
    uint32 Cleave_Timer;
    uint32 ThunderClap_Timer;
    uint32 VoidBolt_Timer;
    uint32 MarkOfKazzak_Timer;
    uint32 Enrage_Timer;
    uint32 Twisted_Reflection_Timer;

    void Reset()
    {
        ShadowVolley_Timer = 8000 + rand()%4000;
        Cleave_Timer = 7000;
        ThunderClap_Timer = 16000 + rand()%4000;
        VoidBolt_Timer = 30000;
        MarkOfKazzak_Timer = 25000;
        Enrage_Timer = 60000;
        Twisted_Reflection_Timer = 33000;                   // Timer may be incorrect
    }

    void Aggro(Unit *who) {}

    void KilledUnit(Unit* victim)
    {
        // When Kazzak kills a player (not pets/totems), he regens some health
        if(victim->GetTypeId() == TYPEID_PLAYER)
            DoCast(m_creature,SPELL_CAPTURESOUL);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //ShadowVolley_Timer
        if (ShadowVolley_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SHADOWVOLLEY);
            ShadowVolley_Timer = 4000 + rand()%2000;
        }else ShadowVolley_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 8000 + rand()%4000;
        }else Cleave_Timer -= diff;

        //ThunderClap_Timer
        if (ThunderClap_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_THUNDERCLAP);
            ThunderClap_Timer = 10000 + rand()%4000;
        }else ThunderClap_Timer -= diff;

        //VoidBolt_Timer
        if (VoidBolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_VOIDBOLT);
            VoidBolt_Timer = 15000 + rand()%3000;
        }else VoidBolt_Timer -= diff;

        //MarkOfKazzak_Timer
        if (MarkOfKazzak_Timer < diff)
        {
            Unit* victim = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if(victim->GetPower(POWER_MANA))
            {
                DoCast(victim, SPELL_MARKOFKAZZAK);
                MarkOfKazzak_Timer = 20000;
            }
        }else MarkOfKazzak_Timer -= diff;

        //Enrage_Timer
        if (Enrage_Timer < diff)
        {
            DoCast(m_creature,SPELL_ENRAGE);
            Enrage_Timer = 30000;
        }else Enrage_Timer -= diff;

        if(Twisted_Reflection_Timer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_TWISTEDREFLECTION);
            Twisted_Reflection_Timer = 15000;
        }else Twisted_Reflection_Timer -= diff;

        DoMeleeAttackIfReady();
    }

};
CreatureAI* GetAI_boss_doomlordkazzak(Creature *_Creature)
{
    return new boss_doomlordkazzakAI (_Creature);
}

void AddSC_boss_doomlordkazzak()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_doomlord_kazzak";
    newscript->GetAI = GetAI_boss_doomlordkazzak;
    m_scripts[nrscripts++] = newscript;
}
