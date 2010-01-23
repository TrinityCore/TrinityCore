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
SDName: Boss_Kormok
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptedPch.h"

#define SPELL_SHADOWBOLTVOLLEY      20741
#define SPELL_BONESHIELD            27688

struct TRINITY_DLL_DECL boss_kormokAI : public ScriptedAI
{
    boss_kormokAI(Creature *c) : ScriptedAI(c) {}

    uint32 ShadowVolley_Timer;
    uint32 BoneShield_Timer;
    uint32 Minion_Timer;
    uint32 Mage_Timer;
    bool Mages;

    void Reset()
    {
        ShadowVolley_Timer = 10000;
        BoneShield_Timer = 2000;
        Minion_Timer = 15000;
        Mage_Timer = 0;
        Mages = false;
    }

    void EnterCombat(Unit *who)
    {
    }

    void SummonMinions(Unit* victim)
    {
        if (Creature *SummonedMinion = DoSpawnCreature(16119, irand(-7,7), irand(-7,7), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
            SummonedMinion->AI()->AttackStart(victim);
    }

    void SummonMages(Unit* victim)
    {
        if (Creature *SummonedMage = DoSpawnCreature(16120, irand(-9,9), irand(-9,9), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
            SummonedMage->AI()->AttackStart(victim);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //ShadowVolley_Timer
        if (ShadowVolley_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SHADOWBOLTVOLLEY);
            ShadowVolley_Timer = 15000;
        } else ShadowVolley_Timer -= diff;

        //BoneShield_Timer
        if (BoneShield_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_BONESHIELD);
            BoneShield_Timer = 45000;
        } else BoneShield_Timer -= diff;

        //Minion_Timer
        if (Minion_Timer <= diff)
        {
            //Cast
            SummonMinions(m_creature->getVictim());
            SummonMinions(m_creature->getVictim());
            SummonMinions(m_creature->getVictim());
            SummonMinions(m_creature->getVictim());

            Minion_Timer = 12000;
        } else Minion_Timer -= diff;

        //Summon 2 Bone Mages
        if (!Mages && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 26)
        {
            //Cast
            SummonMages(m_creature->getVictim());
            SummonMages(m_creature->getVictim());
            Mages = true;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_kormok(Creature* pCreature)
{
    return new boss_kormokAI (pCreature);
}

void AddSC_boss_kormok()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_kormok";
    newscript->GetAI = &GetAI_boss_kormok;
    newscript->RegisterSelf();
}

