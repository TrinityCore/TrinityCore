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
SDName: Boss_Golemagg
SD%Complete: 90
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "precompiled.h"
#include "def_molten_core.h"

#define EMOTE_AEGIS                     -1409002

#define SPELL_MAGMASPLASH               13879
#define SPELL_PYROBLAST                 20228
#define SPELL_EARTHQUAKE                19798
#define SPELL_ENRAGE                    19953
#define SPELL_BUFF                      20553

//-- CoreRager Spells --
#define SPELL_MANGLE                    19820
#define SPELL_AEGIS                     20620               //This is self casted whenever we are below 50%

struct TRINITY_DLL_DECL boss_golemaggAI : public ScriptedAI
{
    boss_golemaggAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    ScriptedInstance *pInstance;

    uint32 Pyroblast_Timer;
    uint32 EarthQuake_Timer;
    uint32 Enrage_Timer;
    uint32 Buff_Timer;

    void Reset()
    {
        Pyroblast_Timer = 7000;                             //These times are probably wrong
        EarthQuake_Timer = 3000;
        Buff_Timer = 2500;
        Enrage_Timer = 0;

        m_creature->CastSpell(m_creature,SPELL_MAGMASPLASH,true);
    }

    void EnterCombat(Unit *who)
    {
    }

    void JustDied(Unit* Killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_GOLEMAGG_DEATH, 0);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Pyroblast_Timer
        if (Pyroblast_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target,SPELL_PYROBLAST);

            Pyroblast_Timer = 7000;
        }else Pyroblast_Timer -= diff;

        //Enrage_Timer
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 11)
        {
            if (Enrage_Timer < diff)
            {
                DoCast(m_creature,SPELL_ENRAGE);
                Enrage_Timer = 62000;
            }else Enrage_Timer -= diff;
        }

        //EarthQuake_Timer
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 11)
        {
            if (EarthQuake_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_EARTHQUAKE);
                EarthQuake_Timer = 3000;
            }else EarthQuake_Timer -= diff;
        }

        //Casting Buff for Coreragers. Spell is not working right. Players get the buff...
        //        if (Buff_Timer < diff)
        //        {
        //            DoCast(m_creature, SPELL_BUFF);
        //            Buff_Timer = 2500;
        //        }else Buff_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_core_ragerAI : public ScriptedAI
{
    mob_core_ragerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 Mangle_Timer;
    uint32 Check_Timer;
    ScriptedInstance *pInstance;

    void Reset()
    {
        Mangle_Timer = 7000;                                //These times are probably wrong
        Check_Timer = 1000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Mangle_Timer
        if (Mangle_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MANGLE);
            Mangle_Timer = 10000;
        }else Mangle_Timer -= diff;

        //Cast AEGIS
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 50)
        {
            DoCast(m_creature,SPELL_AEGIS);
            DoScriptText(EMOTE_AEGIS, m_creature);
        }

        //Check_Timer
        if (Check_Timer < diff)
        {
            if (pInstance)
            {
                Unit *pGolemagg = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_GOLEMAGG));
                if (!pGolemagg || !pGolemagg->isAlive())
                {
                    m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, true);
                }
            }

            Check_Timer = 1000;
        }else Check_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_golemagg(Creature *_Creature)
{
    return new boss_golemaggAI (_Creature);
}

CreatureAI* GetAI_mob_core_rager(Creature *_Creature)
{
    return new mob_core_ragerAI (_Creature);
}

void AddSC_boss_golemagg()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_golemagg";
    newscript->GetAI = &GetAI_boss_golemagg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_core_rager";
    newscript->GetAI = &GetAI_mob_core_rager;
    newscript->RegisterSelf();
}

