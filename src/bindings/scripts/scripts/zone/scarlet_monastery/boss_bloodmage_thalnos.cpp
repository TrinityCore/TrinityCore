/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Boss_Bloodmage_Thalnos
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO                       -1189016
#define SAY_HEALTH                      -1189017
#define SAY_KILL                        -1189018

#define SPELL_FROSTNOVA2                865
#define SPELL_FLAMESHOCK3               8053
#define SPELL_SHADOWBOLT5               1106
#define SPELL_FLAMESPIKE                8814
#define SPELL_FIRENOVA                  16079

struct TRINITY_DLL_DECL boss_bloodmage_thalnosAI : public ScriptedAI
{
    boss_bloodmage_thalnosAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool HpYell;
    uint32 FrostNova2_Timer;
    uint32 FlameShock3_Timer;
    uint32 ShadowBolt5_Timer;
    uint32 FlameSpike_Timer;
    uint32 FireNova_Timer;

    void Reset()
    {
        FrostNova2_Timer = 10000;
        FlameShock3_Timer = 15000;
        ShadowBolt5_Timer = 20000;
        FlameSpike_Timer = 20000;
        FireNova_Timer = 10000;
    }

    void Aggro(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void KilledUnit(Unit* Victim)
    {
        DoScriptText(SAY_KILL, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are <35% hp
        if (!HpYell && ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() <= 35))
        {
            DoScriptText(SAY_HEALTH, m_creature);
            HpYell = true;
        }

        //FrostNova2_Timer
        if (FrostNova2_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FROSTNOVA2);
            FrostNova2_Timer = 10000;
        }else FrostNova2_Timer -= diff;

        //FlameShock3_Timer
        if (FlameShock3_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FLAMESHOCK3);
            FlameShock3_Timer = 15000;
        }else FlameShock3_Timer -= diff;

        //ShadowBolt5_Timer
        if (ShadowBolt5_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHADOWBOLT5);
            ShadowBolt5_Timer = 20000;
        }else ShadowBolt5_Timer -= diff;

        //FlameSpike_Timer
        if (FlameSpike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FLAMESPIKE);
            FlameSpike_Timer = 30000;
        }else FlameSpike_Timer -= diff;

        //FireNova_Timer
        if (FireNova_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FIRENOVA);
            FireNova_Timer = 20000;
        }else FireNova_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_bloodmage_thalnos(Creature *_Creature)
{
    return new boss_bloodmage_thalnosAI (_Creature);
}

void AddSC_boss_bloodmage_thalnos()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_bloodmage_thalnos";
    newscript->GetAI = &GetAI_boss_bloodmage_thalnos;
    newscript->RegisterSelf();
}

