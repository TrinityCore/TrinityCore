/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Huhuran
SD%Complete: 100
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "precompiled.h"

#define EMOTE_GENERIC_FRENZY_KILL   -1000001
#define EMOTE_GENERIC_BERSERK       -1000004

#define SPELL_FRENZY 26051
#define SPELL_BERSERK 26068
#define SPELL_POISONBOLT 26052
#define SPELL_NOXIOUSPOISON 26053
#define SPELL_WYVERNSTING 26180
#define SPELL_ACIDSPIT 26050

struct TRINITY_DLL_DECL boss_huhuranAI : public ScriptedAI
{
    boss_huhuranAI(Creature *c) : ScriptedAI(c) {}

    uint32 Frenzy_Timer;
    uint32 Wyvern_Timer;
    uint32 Spit_Timer;
    uint32 PoisonBolt_Timer;
    uint32 NoxiousPoison_Timer;
    uint32 FrenzyBack_Timer;

    bool Frenzy;
    bool Berserk;

    void Reset()
    {
        Frenzy_Timer = 25000 + rand()%10000;
        Wyvern_Timer = 18000 + rand()%10000;
        Spit_Timer = 8000;
        PoisonBolt_Timer = 4000;
        NoxiousPoison_Timer = 10000 + rand()%10000;
        FrenzyBack_Timer = 15000;

        Frenzy = false;
        Berserk = false;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Frenzy_Timer
        if (!Frenzy && Frenzy_Timer < diff)
        {
            DoCast(m_creature, SPELL_FRENZY);
			DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
            Frenzy = true;
            PoisonBolt_Timer = 3000;
            Frenzy_Timer = 25000 + rand()%10000;
        }else Frenzy_Timer -= diff;

        // Wyvern Timer
        if (Wyvern_Timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_WYVERNSTING);
            Wyvern_Timer = 15000 + rand()%17000;
        }else Wyvern_Timer -= diff;

        //Spit Timer
        if (Spit_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ACIDSPIT);
            Spit_Timer = 5000 + rand()%5000;
        }else Spit_Timer -= diff;

        //NoxiousPoison_Timer
        if (NoxiousPoison_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_NOXIOUSPOISON);
            NoxiousPoison_Timer = 12000 + rand()%12000;
        }else NoxiousPoison_Timer -= diff;

        //PoisonBolt only if frenzy or berserk
        if (Frenzy || Berserk)
        {
            if (PoisonBolt_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_POISONBOLT);
                PoisonBolt_Timer = 3000;
            }else PoisonBolt_Timer -= diff;
        }

        //FrenzyBack_Timer
        if (Frenzy && FrenzyBack_Timer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            Frenzy = false;
            FrenzyBack_Timer = 15000;
        }else FrenzyBack_Timer -= diff;

        if ( !Berserk && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 31 )
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoScriptText(EMOTE_GENERIC_BERSERK, m_creature);
            DoCast(m_creature, SPELL_BERSERK);
            Berserk = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_huhuran(Creature *_Creature)
{
    return new boss_huhuranAI (_Creature);
}

void AddSC_boss_huhuran()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_huhuran";
    newscript->GetAI = &GetAI_boss_huhuran;
    newscript->RegisterSelf();
}

