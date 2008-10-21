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
SDName: Boss_Doomrel
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_SHADOWBOLTVOLLEY               17228
#define SPELL_IMMOLATE                       15505
#define SPELL_CURSEOFWEAKNESS                17227
#define SPELL_DEMONARMOR                     11735

struct TRINITY_DLL_DECL boss_doomrelAI : public ScriptedAI
{
    boss_doomrelAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 ShadowVolley_Timer;
    uint32 Immolate_Timer;
    uint32 CurseOfWeakness_Timer;
    uint32 DemonArmor_Timer;
    bool Voidwalkers;
    int Rand;
    int RandX;
    int RandY;
    Creature* Summoned;

    void Reset()
    {
        ShadowVolley_Timer = 10000;
        Immolate_Timer = 18000;
        CurseOfWeakness_Timer = 5000;
        DemonArmor_Timer = 16000;
        Voidwalkers = false;
    }

    void Aggro(Unit *who)
    {
    }

    void SummonVoidwalkers(Unit* victim)
    {
        Rand = rand()%5;
        switch (rand()%2)
        {
            case 0: RandX = 0 - Rand; break;
            case 1: RandX = 0 + Rand; break;
        }
        Rand = 0;
        Rand = rand()%5;
        switch (rand()%2)
        {
            case 0: RandY = 0 - Rand; break;
            case 1: RandY = 0 + Rand; break;
        }
        Rand = 0;
        Summoned = DoSpawnCreature(16119, RandX, RandY, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000);
        if(Summoned)
            ((CreatureAI*)Summoned->AI())->AttackStart(victim);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //ShadowVolley_Timer
        if (ShadowVolley_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHADOWBOLTVOLLEY);
            ShadowVolley_Timer = 12000;
        }else ShadowVolley_Timer -= diff;

        //Immolate_Timer
        if (Immolate_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target)DoCast(target,SPELL_IMMOLATE);
            Immolate_Timer = 25000;
        }else Immolate_Timer -= diff;

        //CurseOfWeakness_Timer
        if (CurseOfWeakness_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CURSEOFWEAKNESS);
            CurseOfWeakness_Timer = 45000;
        }else CurseOfWeakness_Timer -= diff;

        //DemonArmor_Timer
        if (DemonArmor_Timer < diff)
        {
            DoCast(m_creature,SPELL_DEMONARMOR);
            DemonArmor_Timer = 300000;
        }else DemonArmor_Timer -= diff;

        //Summon Voidwalkers
        if (!Voidwalkers && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 51 )
        {
            SummonVoidwalkers(m_creature->getVictim());
            SummonVoidwalkers(m_creature->getVictim());
            SummonVoidwalkers(m_creature->getVictim());
            Voidwalkers = true;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_doomrel(Creature *_Creature)
{
    return new boss_doomrelAI (_Creature);
}

void AddSC_boss_doomrel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_doomrel";
    newscript->GetAI = GetAI_boss_doomrel;
    m_scripts[nrscripts++] = newscript;
}
