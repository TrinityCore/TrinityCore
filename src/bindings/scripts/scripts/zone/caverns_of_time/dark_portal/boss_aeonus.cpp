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
SDName: Boss_Aeonus
SD%Complete: 80
SDComment: Some spells not implemented
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "precompiled.h"
#include "def_dark_portal.h"

enum
{
    SAY_ENTER           = -1269012,
    SAY_AGGRO           = -1269013,
    SAY_BANISH          = -1269014,
    SAY_SLAY1           = -1269015,
    SAY_SLAY2           = -1269016,
    SAY_DEATH           = -1269017,
    EMOTE_FRENZY        = -1269018,

    SPELL_CLEAVE        = 40504,
    SPELL_TIME_STOP     = 31422,
    SPELL_ENRAGE        = 37605,
    SPELL_SAND_BREATH   = 31473,
    H_SPELL_SAND_BREATH = 39049
};

struct TRINITY_DLL_DECL boss_aeonusAI : public ScriptedAI
{
    boss_aeonusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    ScriptedInstance *pInstance;
    bool HeroicMode;

    uint32 SandBreath_Timer;
    uint32 TimeStop_Timer;
    uint32 Frenzy_Timer;

    void Reset()
    {
        SandBreath_Timer = 15000+rand()%15000;
        TimeStop_Timer = 10000+rand()%5000;
        Frenzy_Timer = 30000+rand()%15000;
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void MoveInLineOfSight(Unit *who)
    {
        //Despawn Time Keeper
        if (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == C_TIME_KEEPER)
        {
            if (m_creature->IsWithinDistInMap(who,20.0f))
            {
                DoScriptText(SAY_BANISH, m_creature);
                m_creature->DealDamage(who, who->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
        }

        ScriptedAI::MoveInLineOfSight(who);
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

         if (pInstance)
         {
             pInstance->SetData(TYPE_RIFT,DONE);
             pInstance->SetData(TYPE_MEDIVH,DONE);//FIXME: later should be removed
         }
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Sand Breath
        if (SandBreath_Timer < diff)
        {
            DoCast(m_creature->getVictim(), HeroicMode ? H_SPELL_SAND_BREATH : SPELL_SAND_BREATH);
            SandBreath_Timer = 15000+rand()%10000;
        }else SandBreath_Timer -= diff;

        //Time Stop
        if (TimeStop_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_TIME_STOP);
            TimeStop_Timer = 20000+rand()%15000;
        }else TimeStop_Timer -= diff;

        //Frenzy
        if (Frenzy_Timer < diff)
        {
            DoScriptText(EMOTE_FRENZY, m_creature);
            DoCast(m_creature, SPELL_ENRAGE);
            Frenzy_Timer = 20000+rand()%15000;
        }else Frenzy_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_aeonus(Creature* pCreature)
{
    return new boss_aeonusAI (pCreature);
}

void AddSC_boss_aeonus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_aeonus";
    newscript->GetAI = &GetAI_boss_aeonus;
    newscript->RegisterSelf();
}

