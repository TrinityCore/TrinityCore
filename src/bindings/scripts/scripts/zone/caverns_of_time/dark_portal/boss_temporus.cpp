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
SDName: Boss_Temporus
SD%Complete: 75
SDComment: More abilities need to be implemented
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "precompiled.h"
#include "def_dark_portal.h"

enum
{
    SAY_ENTER               = -1269000,
    SAY_AGGRO               = -1269001,
    SAY_BANISH              = -1269002,
    SAY_SLAY1               = -1269003,
    SAY_SLAY2               = -1269004,
    SAY_DEATH               = -1269005,

    SPELL_HASTE             = 31458,
    SPELL_MORTAL_WOUND      = 31464,
    SPELL_WING_BUFFET       = 31475,
    H_SPELL_WING_BUFFET     = 38593,
    SPELL_REFLECT           = 38592                       //Not Implemented (Heroic mod)
};

struct TRINITY_DLL_DECL boss_temporusAI : public ScriptedAI
{
    boss_temporusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = c->GetMap()->IsHeroic();
    }

    ScriptedInstance *pInstance;
    bool HeroicMode;

    uint32 Haste_Timer;
    uint32 SpellReflection_Timer;
    uint32 MortalWound_Timer;
    uint32 WingBuffet_Timer;

    void Reset()
    {
        Haste_Timer = 15000+rand()%8000;
        SpellReflection_Timer = 30000;
        MortalWound_Timer = 8000;
        WingBuffet_Timer = 25000+rand()%10000;
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(TYPE_RIFT,SPECIAL);
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

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Attack Haste
        if (Haste_Timer < diff)
        {
            DoCast(m_creature, SPELL_HASTE);
            Haste_Timer = 20000+rand()%5000;
        }else Haste_Timer -= diff;

        //MortalWound_Timer
        if (MortalWound_Timer < diff)
        {
            DoCast(m_creature, SPELL_MORTAL_WOUND);
            MortalWound_Timer = 10000+rand()%10000;
        }else MortalWound_Timer -= diff;

        //Wing ruffet
        if (WingBuffet_Timer < diff)
        {
            DoCast(m_creature,HeroicMode ? H_SPELL_WING_BUFFET : SPELL_WING_BUFFET);
            WingBuffet_Timer = 20000+rand()%10000;
        }else WingBuffet_Timer -= diff;

        if (HeroicMode)
        {
            if (SpellReflection_Timer < diff)
            {
                DoCast(m_creature,SPELL_REFLECT);
                SpellReflection_Timer = 25000+rand()%10000;
            }else SpellReflection_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_temporus(Creature* pCreature)
{
    return new boss_temporusAI (pCreature);
}

void AddSC_boss_temporus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_temporus";
    newscript->GetAI = &GetAI_boss_temporus;
    newscript->RegisterSelf();
}

