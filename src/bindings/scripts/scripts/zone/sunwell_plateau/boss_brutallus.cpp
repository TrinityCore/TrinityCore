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
SDName: Boss_Brutallus
SD%Complete: 50
SDComment: Intro not made. Script for Madrigosa to be added here.
EndScriptData */

#include "precompiled.h"
#include "def_sunwell_plateau.h"

#define YELL_INTRO                      -1580017
#define YELL_INTRO_BREAK_ICE            -1580018
#define YELL_INTRO_CHARGE               -1580019
#define YELL_INTRO_KILL_MADRIGOSA       -1580020
#define YELL_INTRO_TAUNT                -1580021

#define YELL_MADR_ICE_BARRIER           -1580031
#define YELL_MADR_INTRO                 -1580032
#define YELL_MADR_ICE_BLOCK             -1580033
#define YELL_MADR_TRAP                  -1580034
#define YELL_MADR_DEATH                 -1580035

#define YELL_AGGRO                      -1580022
#define YELL_KILL1                      -1580023
#define YELL_KILL2                      -1580024
#define YELL_KILL3                      -1580025
#define YELL_LOVE1                      -1580026
#define YELL_LOVE2                      -1580027
#define YELL_LOVE3                      -1580028
#define YELL_BERSERK                    -1580029
#define YELL_DEATH                      -1580030

#define SPELL_METEOR_SLASH              45150
#define SPELL_BURN                      45141
#define SPELL_STOMP                     45185
#define SPELL_BERSERK                   26662
#define SPELL_DUAL_WIELD                42459

#define FREEZING 45203
#define FROST_BOLT 44843
#define ENCAPSULATE 45665
#define ENCAPSULATE_CHANELLING 45661

struct TRINITY_DLL_DECL boss_brutallusAI : public ScriptedAI
{
    boss_brutallusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance* pInstance;

    uint32 SlashTimer;
    uint32 BurnTimer;
    uint32 StompTimer;
    uint32 BerserkTimer;

    uint32 ConversationTimer;
    bool Intro;

    void Reset()
    {
        SlashTimer = 11000;
        StompTimer = 30000;
        BurnTimer = 60000;
        BerserkTimer = 360000;
        m_creature->CastSpell(m_creature, SPELL_DUAL_WIELD, true);

        if(pInstance)
            pInstance->SetData(DATA_BRUTALLUS, NOT_STARTED);
    }

    void Aggro(Unit *who)
    {
        DoScriptText(YELL_AGGRO, m_creature);

        if(pInstance)
            pInstance->SetData(DATA_BRUTALLUS, IN_PROGRESS);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%3)
        {
        case 0: DoScriptText(YELL_KILL1, m_creature); break;
        case 1: DoScriptText(YELL_KILL2, m_creature); break;
        case 2: DoScriptText(YELL_KILL3, m_creature); break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(YELL_DEATH, m_creature);

        if(pInstance)
            pInstance->SetData(DATA_BRUTALLUS, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() )
            return;

        if(SlashTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_METEOR_SLASH);
            SlashTimer = 11000;
        }else SlashTimer -= diff;

        if(StompTimer < diff)
        {
            switch(rand()%3)
            {
            case 0: DoScriptText(YELL_LOVE1, m_creature); break;
            case 1: DoScriptText(YELL_LOVE2, m_creature); break;
            case 2: DoScriptText(YELL_LOVE3, m_creature); break;
            }

            Unit *Target = m_creature->getVictim();
            DoCast(Target,SPELL_STOMP);
            if(Target->HasAura(45151)) Target->RemoveAura(45151);
            StompTimer = 30000;
        }else StompTimer -= diff;

        if(BurnTimer < diff)
        {
            if(Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                target->CastSpell(target,SPELL_BURN,true);
            BurnTimer = 60000;
        }
        else BurnTimer -= diff;

        if(BerserkTimer < diff)
        {
            DoScriptText(YELL_BERSERK, m_creature);
            DoCast(m_creature,SPELL_BERSERK);
            BerserkTimer = 20000;
        }
        else BerserkTimer -= diff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_brutallus(Creature *_Creature)
{
    return new boss_brutallusAI (_Creature);
}

void AddSC_boss_brutallus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_brutallus";
    newscript->GetAI = &GetAI_boss_brutallus;
    newscript->RegisterSelf();
}

